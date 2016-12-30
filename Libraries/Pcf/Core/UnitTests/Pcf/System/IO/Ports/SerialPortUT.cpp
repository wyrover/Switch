#include <Rs232/rs232.h>
#include <Pcf/System/IO/IOException.h>
#include <Pcf/System/Threading/Thread.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

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
      throw System::IO::IOException(pcf_current_information);
    
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
      throw System::IO::IOException(pcf_current_information);
    
    string str = "The quick brown fox jumped over the lazy grey dog.";

    while (!Quit) {
      if (RS232_SendBuf(TransmitterPort, (unsigned char*)str.Data(), str.Length()) != str.Length())
        throw System::IO::IOException(pcf_current_information);
      
      Console::WriteLine("{0} sent: {1}", ++nbSend, str);
      
      Threading::Thread::Sleep(0);
    }
    
    RS232_CloseComport(TransmitterPort);
    Console::WriteLine("Stop Transmitter...");
  }

  TEST(SerialPort, Test) {
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