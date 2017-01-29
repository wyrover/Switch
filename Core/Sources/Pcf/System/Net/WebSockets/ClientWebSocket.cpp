#include <easywsclient/easywsclient.hpp>
#include "../../../../../Includes/Pcf/System/Net/WebSockets/ClientWebSocket.h"
#include "../../../../../Includes/Pcf/System/Threading/Thread.h"

using namespace System;
using namespace System::Net::WebSockets;

ClientWebSocket::ClientWebSocket() {
}

ClientWebSocket::~ClientWebSocket() {
  this->Close(WebSocketCloseStatus::NormalClosure, "Close instance");
  if (this->socket == null)
    delete this->socket;
}

void ClientWebSocket::Connect(const string& uri) {
  this->socket = easywsclient::WebSocket::from_url(uri.Data());
  if (this->socket == null)
    throw InvalidOperationException(pcf_current_information);
  
  this->thread = System::Threading::Thread(System::Threading::ThreadStart(pcf_delegate {
    while (this->State == WebSocketState::Connecting)
      System::Threading::Thread::Sleep(10);
    while (this->State == WebSocketState::Open) {
      //this->startReceive.WaitOne();
      this->socket->poll();
      this->socket->dispatch(pcf_delegate(const std::string& message) {
        this->items.Enqueue(message.c_str());
        this->itemsReceive.Release();
      });
    }
  }));
  this->thread.Start();
}

void ClientWebSocket::Close(WebSocketCloseStatus closeStatus, const string& statusDescription) {
  if (this->socket == null)
    return;

  this->closeStatus = closeStatus;
  this->thread.Join();
  this->socket->close();
}

ArraySegment<byte> ClientWebSocket::Receive() {
  if (this->socket == null)
    throw InvalidOperationException(pcf_current_information);
  
  string buffer;
  if (this->items.TryDequeue(buffer) == false) {
    this->startReceive.Release();
    while (this->itemsReceive.WaitOne() == false || this->items.TryDequeue(buffer) == false);
  }
  return ArraySegment<byte>(reinterpret_cast<const byte*>(buffer.Data()), buffer.Length);
}

void ClientWebSocket::Send(const ArraySegment<byte>& buffer, WebSocketMessageType messageType, bool endOfMessage) {
  if (this->socket == null)
    throw InvalidOperationException(pcf_current_information);
  
  switch (messageType) {
    case WebSocketMessageType::Text: this->socket->send(std::string(reinterpret_cast<const char*>(buffer.Data()), buffer.Length)); break;
    case WebSocketMessageType::Binary: this->socket->sendBinary(std::vector<byte>(buffer.Data(), buffer.Data() + buffer.Length)); break;
    default: throw InvalidOperationException(pcf_current_information);
  }
}

WebSocketState ClientWebSocket::GetState() const {
  if (this->socket == null)
    return WebSocketState::None;
  
  switch (this->socket->getReadyState()) {
    case easywsclient::WebSocket::CLOSING: return WebSocketState::CloseSent;
    case easywsclient::WebSocket::CLOSED: return WebSocketState::Closed;
    case easywsclient::WebSocket::CONNECTING: return WebSocketState::Connecting;
    case easywsclient::WebSocket::OPEN: return WebSocketState::Open;
  }
  return WebSocketState::None;
}
