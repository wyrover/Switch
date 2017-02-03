#include <Pcf/System/Threading/WaitHandle.h>
#include <Pcf/System/Threading/AutoResetEvent.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace TUnit;

namespace {

	class WaitHandleTests : public testing::Test {

	};

	TEST_F(WaitHandleTests, WaitingForAnyEventTimesOutIfEventNotSignalled) {
		// GIVEN an Event that is not signalled
		sp<System::Threading::AutoResetEvent> triggerStop = new System::Threading::AutoResetEvent(false);

		// WHEN waiting for the event with a timeout of 500 ms
		System::Collections::Generic::List<sp<System::Threading::WaitHandle>> events;
		events.Add(triggerStop.ChangeType<System::Threading::WaitHandle>());

		DateTime time = DateTime::Now;

		const int64 DurationMilliseconds = 500;
		int32 trigger = System::Threading::WaitHandle::WaitAny(events, DurationMilliseconds);

		// THEN the timeout expires
		EXPECT_EQ(System::Threading::WaitHandle::WaitTimeOut(), trigger);

		// AND the elapsed time is in [90%...150%[ of 500 ms
		// A timeout should never return before the requested time is elapsed
		// A timeout may return later than the requested time if higher priority processes take up processor time

		int64 elapsed = DateTime::Now().Subtract(time).Ticks();
		int64 expected = DurationMilliseconds * TimeSpan::TicksPerMillisecond;

		EXPECT_GE(elapsed, expected * 9 / 10 );
		EXPECT_LT(elapsed, expected * 15 / 10);
	}

	TEST_F(WaitHandleTests, WaitingForAllEventsTimesOutIfEventNotSignalled) {
		// GIVEN an Event that is not signalled
		sp<System::Threading::AutoResetEvent> triggerStop = new System::Threading::AutoResetEvent(false);

		// WHEN waiting for the event with a timeout of 500 ms
		System::Collections::Generic::List<sp<System::Threading::WaitHandle>> events;
		events.Add(triggerStop.ChangeType<System::Threading::WaitHandle>());

		DateTime time = DateTime::Now;

		const int64 DurationMilliseconds = 500;
		bool eventTriggered = System::Threading::WaitHandle::WaitAll(events, DurationMilliseconds);

		// THEN the timeout expires
		EXPECT_FALSE(eventTriggered);

		// AND the elapsed time is in [90%...150%[ of 500 ms
		// A timeout should never return before the requested time is elapsed
		// A timeout may return later than the requested time if higher priority processes take up processor time

		int64 elapsed = DateTime::Now().Subtract(time).Ticks();
		int64 expected = DurationMilliseconds * TimeSpan::TicksPerMillisecond;

		EXPECT_GE(elapsed, expected * 9 / 10);
		EXPECT_LT(elapsed, expected * 15 / 10);
	}
}
