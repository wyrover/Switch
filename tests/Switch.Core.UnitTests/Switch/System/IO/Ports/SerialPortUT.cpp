#include <Switch/System/IO/IOException.hpp>
#include <Switch/System/Threading/Thread.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  /*
   bool Quit = false;
  int32 ReceiverPort = 0;
  int32 TransmitterPort = 1;
  int32 BaudRate = 9600;
  const char* Mode = "8N1";

  void ReceiveChars() {
    Console::WriteLine("Start Receiver...");
    if (RS232_OpenComport(ReceiverPort, BaudRate, Mode) != 0)
      throw System::IO::IOException(_caller);

    while (!Quit) {
      byte buf[4096] = {0};
      int32 nbCharRead = RS232_PollComport(ReceiverPort, (byte*)buf, 4095);

      if (nbCharRead > 0) {
        buf[nbCharRead] = 0;   // always put a "null" at the end of a string!

        for (int32 i= 0; i < nbCharRead; i++) {
          if (buf[i] < 32) {  // replace unreadable control-codes by dots
            buf[i] = '.';
          }
        }
        string str = (char*)buf;

        Console::WriteLine("received {0} bytes: {1}", nbCharRead, (char*)buf);
      }

      Threading::Thread::Sleep(0);
    }

    RS232_CloseComport(ReceiverPort);
    Console::WriteLine("Stop Receiver...");
  }

  void TransmitChars() {
    int nbSend = 0;
    Console::WriteLine("Start Transmitter...");

    if (RS232_OpenComport(TransmitterPort, BaudRate, Mode) != 0)
      throw System::IO::IOException(_caller);

    string str = "The quick brown fox jumped over the lazy grey dog.";

    while (!Quit) {
      if (RS232_SendBuf(TransmitterPort, (unsigned char*)str.Data(), str.Length()) != str.Length())
        throw System::IO::IOException(_caller);

      Console::WriteLine("{0} sent: {1}", ++nbSend, str);

      Threading::Thread::Sleep(0);
    }

    RS232_CloseComport(TransmitterPort);
    Console::WriteLine("Stop Transmitter...");
  }

  TEST(SerialPortTest, Test) {
    Console::WriteLine("Start Test...");
    ReceiverPort = 0;
    TransmitterPort = 2;
    System::Threading::Thread receiver((Threading::ThreadStart)&ReceiveChars);
    System::Threading::Thread transmitter((Threading::ThreadStart)&TransmitChars);

    receiver.Start();
    transmitter.Start();

    Threading::Thread::Sleep(3000);
    Quit = true;

    receiver.Join();
    transmitter.Join();
    Console::WriteLine("Stop Test...");
  }
   */
}
