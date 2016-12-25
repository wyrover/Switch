#include <Pcf/System/Diagnostics/Stopwatch.h>
#include <Pcf/System/Threading/Thread.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace {
  TEST(Stopwatch, Scenario) {
    System::Diagnostics::Stopwatch stopwatch;

    Threading::Thread::Sleep(10);
    EXPECT_EQ(0, stopwatch.ElapsedTicks());
    EXPECT_FALSE(stopwatch.IsRunning());
    
    stopwatch.Start();
    Threading::Thread::Sleep(10);
    stopwatch.Stop();
    EXPECT_GE(stopwatch.ElapsedTicks(), 9900000);
    EXPECT_LE(stopwatch.ElapsedTicks(), 12000000);
    EXPECT_FALSE(stopwatch.IsRunning());

    System::Threading::Thread::Sleep(10);
    EXPECT_GE(stopwatch.ElapsedTicks(), 9900000);
    EXPECT_LE(stopwatch.ElapsedTicks(), 12000000);
    EXPECT_FALSE(stopwatch.IsRunning());
    
    stopwatch.Start();
    System::Threading::Thread::Sleep(10);
    EXPECT_GE(stopwatch.ElapsedTicks(), 19800000);
    EXPECT_LE(stopwatch.ElapsedTicks(), 24000000);
    EXPECT_TRUE(stopwatch.IsRunning());
    
    System::Threading::Thread::Sleep(10);
    EXPECT_GE(stopwatch.ElapsedTicks(), 29700000);
    EXPECT_LE(stopwatch.ElapsedTicks(), 36000000);
    EXPECT_TRUE(stopwatch.IsRunning());
    stopwatch.Stop();
    EXPECT_GE(stopwatch.ElapsedTicks(), 29700000);
    EXPECT_LE(stopwatch.ElapsedTicks(), 36000000);
    EXPECT_FALSE(stopwatch.IsRunning());
    
    stopwatch.Reset();
    EXPECT_EQ(0, stopwatch.ElapsedTicks());
    EXPECT_FALSE(stopwatch.IsRunning());
    
    stopwatch.Start();
    System::Threading::Thread::Sleep(10);
    stopwatch.Restart();
    System::Threading::Thread::Sleep(10);
    EXPECT_GE(stopwatch.ElapsedTicks(), 9900000);
    EXPECT_LE(stopwatch.ElapsedTicks(), 12000000);
    EXPECT_TRUE(stopwatch.IsRunning());
  }
}
