#include <Switch/System/Tuple.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  class TupleTest : public TestFixture {
  protected:
    void Tuple1() {
      Tuple<string> t("Value"_s);
      Assert::AreEqual("Value", t.Item1);
    }
    
    void Tuple2() {
      Tuple<string, int> t("Value", 42);
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
    }
    
    void Tuple3() {
      Tuple<string, int, bool> t("Value", 42, true);
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
    }
    
    void Tuple4() {
      Tuple<string, int, bool, DayOfWeek> t("Value", 42, true, DayOfWeek::Wednesday);
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
    }
    
    void Tuple5() {
      Tuple<string, int, bool, DayOfWeek, double> t("Value", 42, true, DayOfWeek::Wednesday, .42);
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
    }
    
    void Tuple6() {
      Tuple<string, int, bool, DayOfWeek, double, char32> t("Value", 42, true, DayOfWeek::Wednesday, .42, U'a');
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
    }
    
    void Tuple7() {
      Tuple<string, int, bool, DayOfWeek, double, char32, byte> t("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', 21);
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
      Assert::AreEqual((byte)21, t.Item7);
    }
    
    void TupleRest() {
      Tuple<string, int, bool, DayOfWeek, double, char32, byte, TimeSpan> t("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', 21, 12_h + 23_min + 2_s);
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
      Assert::AreEqual((byte)21, t.Item7);
      Assert::AreEqual(12_h + 23_min + 2_s, t.Rest);
    }
    
    void TupleRestWithTuple() {
      Tuple<string, int, bool, DayOfWeek, double, char32, byte, Tuple<TimeSpan, Version>> t("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', 21, {12_h + 23_min + 2_s, {1, 2, 3}});
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
      Assert::AreEqual((byte)21, t.Item7);
      Assert::AreEqual(12_h + 23_min + 2_s, t.Rest().Item1);
      Assert::AreEqual(Version(1, 2, 3), t.Rest().Item2);
    }
    
    void Tuple1ToString() {
      Tuple<string> t("Value"_s);
      Assert::AreEqual("(Value)", t.ToString());
    }
    
    void Tuple2ToString() {
      Tuple<string, int> t("Value", 42);
      Assert::AreEqual("(Value, 42)", t.ToString());
    }
    
    void Tuple3ToString() {
      Tuple<string, int, bool> t("Value", 42, true);
      Assert::AreEqual("(Value, 42, True)", t.ToString());
    }
    
    void Tuple4ToString() {
      Tuple<string, int, bool, DayOfWeek> t("Value", 42, true, DayOfWeek::Wednesday);
      Assert::AreEqual("(Value, 42, True, Wednesday)", t.ToString());
    }
    
    void Tuple5ToString() {
      Tuple<string, int, bool, DayOfWeek, double> t("Value", 42, true, DayOfWeek::Wednesday, .42);
      Assert::AreEqual("(Value, 42, True, Wednesday, 0.42)", t.ToString());
    }
    
    void Tuple6ToString() {
      Tuple<string, int, bool, DayOfWeek, double, char32> t("Value", 42, true, DayOfWeek::Wednesday, .42, U'a');
      Assert::AreEqual("(Value, 42, True, Wednesday, 0.42, a)", t.ToString());
    }
    
    void Tuple7ToString() {
      Tuple<string, int, bool, DayOfWeek, double, char32, byte> t("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', 21);
      Assert::AreEqual("(Value, 42, True, Wednesday, 0.42, a, 21)", t.ToString());
    }
    
    void TupleRestToString() {
      Tuple<string, int, bool, DayOfWeek, double, char32, byte, TimeSpan> t("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', 21, 12_h + 23_min + 2_s);
      Assert::AreEqual("(Value, 42, True, Wednesday, 0.42, a, 21, 12:23:02)", t.ToString());
    }
    
    void TupleRestWithTupleToString() {
      Tuple<string, int, bool, DayOfWeek, double, char32, byte, Tuple<TimeSpan, Version>> t("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', 21, {12_h + 23_min + 2_s, {1, 2, 3}});
      Assert::AreEqual("(Value, 42, True, Wednesday, 0.42, a, 21, 12:23:02, 1.2.3)", t.ToString());
    }

    void CreateTuple1() {
      auto t = Tuple<>::Create("Value");
      Assert::AreEqual("Value", t.Item1);
    }
    
    void CreateTuple2() {
      auto t = Tuple<>::Create("Value", 42);
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
    }
    
    void CreateTuple3() {
      auto t = Tuple<>::Create("Value", 42, true);
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
    }
    
    void CreateTuple4() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday);
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
    }
    
    void CreateTuple5() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42);
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
    }
    
    void CreateTuple6() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a');
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
    }
    
    void CreateTuple7() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
      Assert::AreEqual((byte)21, t.Item7);
    }
    
    void CreateTupleRest() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
      Assert::AreEqual((byte)21, t.Item7);
      Assert::AreEqual(12_h + 23_min + 2_s, t.Rest);
    }
    
    void CreateTupleRestWithTuple() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, Tuple<>::Create(12_h + 23_min + 2_s, Version(1, 2, 3)));
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
      Assert::AreEqual((byte)21, t.Item7);
      Assert::AreEqual(12_h + 23_min + 2_s, t.Rest().Item1);
      Assert::AreEqual(Version(1, 2, 3), t.Rest().Item2);
    }
    
    void CreateTuple1AndSetItem1() {
      auto t = Tuple<>::Create("Value");
      t.Item1 = "Other";
      Assert::AreEqual("Other", t.Item1);
    }
    
    void CreateTuple2AndSetItem1() {
      auto t = Tuple<>::Create("Value", 42);
      t.Item1 = "Other";
      Assert::AreEqual("Other", t.Item1);
      Assert::AreEqual(42, t.Item2);
    }
    
    void CreateTuple2AndSetItem2() {
      auto t = Tuple<>::Create("Value", 42);
      t.Item2 = 84;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(84, t.Item2);
    }
    
    void CreateTuple3AndSetItem1() {
      auto t = Tuple<>::Create("Value", 42, true);
      t.Item1 = "Other";
      Assert::AreEqual("Other", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
    }
    
    void CreateTuple3AndSetItem2() {
      auto t = Tuple<>::Create("Value", 42, true);
      t.Item2 = 84;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(84, t.Item2);
      Assert::AreEqual(true, t.Item3);
    }
    
    void CreateTuple3AndSetItem3() {
      auto t = Tuple<>::Create("Value", 42, true);
      t.Item3 = false;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(false, t.Item3);
    }
    
    void CreateTuple4AndSetItem1() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday);
      t.Item1 = "Other";
      Assert::AreEqual("Other", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
    }
    
    void CreateTuple4AndSetItem2() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday);
      t.Item2 = 84;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(84, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
    }
    
    void CreateTuple4AndSetItem3() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday);
      t.Item3 = false;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(false, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
    }
    
    void CreateTuple4AndSetItem4() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday);
      t.Item4 = DayOfWeek::Sunday;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Sunday, t.Item4);
    }
    
    void CreateTuple5AndSetItem1() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42);
      t.Item1 = "Other";
      Assert::AreEqual("Other", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
    }
    
    void CreateTuple5AndSetItem2() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42);
      t.Item2 = 84;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(84, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
    }
    
    void CreateTuple5AndSetItem3() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42);
      t.Item3 = false;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(false, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
    }
    
    void CreateTuple5AndSetItem4() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42);
      t.Item4 = DayOfWeek::Sunday;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Sunday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
    }
    
    void CreateTuple5AndSetItem5() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42);
      t.Item5 = .21;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.21, t.Item5);
    }
    
    void CreateTuple6AndSetItem1() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a');
      t.Item1 = "Other";
      Assert::AreEqual("Other", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
    }
    
    void CreateTuple6AndSetItem2() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a');
      t.Item2 = 84;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(84, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
    }
    
    void CreateTuple6AndSetItem3() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a');
      t.Item3 = false;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(false, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
    }
    
    void CreateTuple6AndSetItem4() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a');
      t.Item4 = DayOfWeek::Sunday;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Sunday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
    }
    
    void CreateTuple6AndSetItem5() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a');
      t.Item5 = .21;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.21, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
    }
    
    void CreateTuple6AndSetItem6() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a');
      t.Item6 = U'b';
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'b', t.Item6);
    }
    
    void CreateTuple7AndSetItem1() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      t.Item1 = "Other";
      Assert::AreEqual("Other", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
      Assert::AreEqual((byte)21, t.Item7);
    }
    
    void CreateTuple7AndSetItem2() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      t.Item2 = 84;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(84, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
      Assert::AreEqual((byte)21, t.Item7);
    }
    
    void CreateTuple7AndSetItem3() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      t.Item3 = false;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(false, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
      Assert::AreEqual((byte)21, t.Item7);
    }
    
    void CreateTuple7AndSetItem4() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      t.Item4 = DayOfWeek::Sunday;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Sunday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
      Assert::AreEqual((byte)21, t.Item7);
    }
    
    void CreateTuple7AndSetItem5() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      t.Item5 = .21;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.21, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
      Assert::AreEqual((byte)21, t.Item7);
    }
    
    void CreateTuple7AndSetItem6() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      t.Item6 = U'b';
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'b', t.Item6);
      Assert::AreEqual((byte)21, t.Item7);
    }
    
    void CreateTuple7AndSetItem7() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      t.Item7 = 42;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
      Assert::AreEqual((byte)42, t.Item7);
    }
    
    void CreateTupleRestAndSetItem1() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      t.Item1 = "Other";
      Assert::AreEqual("Other", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
      Assert::AreEqual((byte)21, t.Item7);
      Assert::AreEqual(12_h + 23_min + 2_s, t.Rest);
    }
    
    void CreateTupleRestAndSetItem2() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      t.Item2 = 84;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(84, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
      Assert::AreEqual((byte)21, t.Item7);
      Assert::AreEqual(12_h + 23_min + 2_s, t.Rest);
    }
    
    void CreateTupleRestAndSetItem3() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      t.Item3 = false;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(false, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
      Assert::AreEqual((byte)21, t.Item7);
      Assert::AreEqual(12_h + 23_min + 2_s, t.Rest);
    }
    
    void CreateTupleRestAndSetItem4() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      t.Item4 = DayOfWeek::Sunday;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Sunday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
      Assert::AreEqual((byte)21, t.Item7);
      Assert::AreEqual(12_h + 23_min + 2_s, t.Rest);
    }
    
    void CreateTupleRestAndSetItem5() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      t.Item5 = .21;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.21, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
      Assert::AreEqual((byte)21, t.Item7);
      Assert::AreEqual(12_h + 23_min + 2_s, t.Rest);
    }
    
    void CreateTupleRestAndSetItem6() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      t.Item6 = U'b';
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'b', t.Item6);
      Assert::AreEqual((byte)21, t.Item7);
      Assert::AreEqual(12_h + 23_min + 2_s, t.Rest);
    }
    
    void CreateTupleRestAndSetItem7() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      t.Item7 = 42;
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
      Assert::AreEqual((byte)42, t.Item7);
      Assert::AreEqual(12_h + 23_min + 2_s, t.Rest);
    }
    
    void CreateTupleRestAndSetRest() {
      auto t = Tuple<>::Create("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      t.Rest = TimeSpan(5, 28, 19);
      Assert::AreEqual("Value", t.Item1);
      Assert::AreEqual(42, t.Item2);
      Assert::AreEqual(true, t.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t.Item4);
      Assert::AreEqual(.42, t.Item5);
      Assert::AreEqual(U'a', t.Item6);
      Assert::AreEqual((byte)21, t.Item7);
      Assert::AreEqual(5_h + 28_min + 19_s, t.Rest);
    }
    
    void CreateTuple1AndCopyItToOther() {
      auto t1 = Tuple<>::Create("Value"_s);
      Tuple<string> t2;
      t2 = t1;
      Assert::AreEqual("Value", t2.Item1);
      
    }
    
    void CreateTuple2AndCopyItToOther() {
      auto t1 = Tuple<>::Create("Value"_s, 42);
      Tuple<string, int32> t2;
      t2 = t1;
      Assert::AreEqual("Value", t2.Item1);
      Assert::AreEqual(42, t2.Item2);
    }
    
    void CreateTuple3AndCopyItToOther() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true);
      Tuple<string, int32, bool> t2;
      t2 = t1;
      Assert::AreEqual("Value", t2.Item1);
      Assert::AreEqual(42, t2.Item2);
      Assert::AreEqual(true, t2.Item3);
    }
    
    void CreateTuple4AndCopyItToOther() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday);
      Tuple<string, int32, bool, DayOfWeek> t2;
      t2 = t1;
      Assert::AreEqual("Value", t2.Item1);
      Assert::AreEqual(42, t2.Item2);
      Assert::AreEqual(true, t2.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t2.Item4);
    }
    
    void CreateTuple5AndCopyItToOther() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
      Tuple<string, int32, bool, DayOfWeek, double> t2;
      t2 = t1;
      Assert::AreEqual("Value", t2.Item1);
      Assert::AreEqual(42, t2.Item2);
      Assert::AreEqual(true, t2.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t2.Item4);
      Assert::AreEqual(.42, t2.Item5);
    }
    
    void CreateTuple6AndCopyItToOther() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
      Tuple<string, int32, bool, DayOfWeek, double, char32> t2;
      t2 = t1;
      Assert::AreEqual("Value", t2.Item1);
      Assert::AreEqual(42, t2.Item2);
      Assert::AreEqual(true, t2.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t2.Item4);
      Assert::AreEqual(.42, t2.Item5);
      Assert::AreEqual(U'a', t2.Item6);
    }
    
    void CreateTuple7AndCopyItToOther() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      Tuple<string, int32, bool, DayOfWeek, double, char32, byte> t2;
      t2 = t1;
      Assert::AreEqual("Value", t2.Item1);
      Assert::AreEqual(42, t2.Item2);
      Assert::AreEqual(true, t2.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t2.Item4);
      Assert::AreEqual(.42, t2.Item5);
      Assert::AreEqual(U'a', t2.Item6);
      Assert::AreEqual((byte)21, t2.Item7);
    }
    
    void CreateTupleRestAndCopyItToOther() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      Tuple<string, int32, bool, DayOfWeek, double, char32, byte, TimeSpan> t2;
      t2 = t1;
      Assert::AreEqual("Value", t2.Item1);
      Assert::AreEqual(42, t2.Item2);
      Assert::AreEqual(true, t2.Item3);
      Assert::AreEqual(DayOfWeek::Wednesday, t2.Item4);
      Assert::AreEqual(.42, t2.Item5);
      Assert::AreEqual(U'a', t2.Item6);
      Assert::AreEqual((byte)21, t2.Item7);
      Assert::AreEqual(TimeSpan(12, 23, 2), t2.Rest);
    }
    
    void Create2SameTuple1AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s);
      auto t2 = Tuple<>::Create("Value"_s);
      Assert::IsTrue(t1.Equals(t2));
    }
    
    void Create2SameTuple2AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42);
      auto t2 = Tuple<>::Create("Value"_s, 42);
      Assert::IsTrue(t1.Equals(t2));
    }
    
    void Create2SameTuple3AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true);
      auto t2 = Tuple<>::Create("Value"_s, 42, true);
      Assert::IsTrue(t1.Equals(t2));
    }
    
    void Create2SameTuple4AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday);
      auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday);
      Assert::IsTrue(t1.Equals(t2));
    }
    
    void Create2SameTuple5AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
      auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
      Assert::IsTrue(t1.Equals(t2));
    }
    
    void Create2SameTuple6AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
      auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
      Assert::IsTrue(t1.Equals(t2));
    }
    
    void Create2SameTuple7AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      Assert::IsTrue(t1.Equals(t2));
    }
    
    void Create2SameTupleRestAndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      Assert::IsTrue(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple1ByItem1AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s);
      auto t2 = Tuple<>::Create("Other"_s);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple2ByItem1AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42);
      auto t2 = Tuple<>::Create("Other"_s, 42);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple2ByItem2AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42);
      auto t2 = Tuple<>::Create("Value"_s, 84);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple3ByItem1AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true);
      auto t2 = Tuple<>::Create("Other"_s, 42, true);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple3ByItem2AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true);
      auto t2 = Tuple<>::Create("Value"_s, 84, true);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple3ByItem3AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true);
      auto t2 = Tuple<>::Create("Value"_s, 42, false);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple4ByItem1AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday);
      auto t2 = Tuple<>::Create("Other"_s, 42, true, DayOfWeek::Wednesday);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple4ByItem2AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday);
      auto t2 = Tuple<>::Create("Value"_s, 84, true, DayOfWeek::Wednesday);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple4ByItem3AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday);
      auto t2 = Tuple<>::Create("Value"_s, 42, false, DayOfWeek::Wednesday);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple4ByItem4AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday);
      auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Sunday);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple5ByItem1AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
      auto t2 = Tuple<>::Create("Other"_s, 42, true, DayOfWeek::Wednesday, .42);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple5ByItem2AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
      auto t2 = Tuple<>::Create("Value"_s, 84, true, DayOfWeek::Wednesday, .42);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple5ByItem3AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
      auto t2 = Tuple<>::Create("Value"_s, 42, false, DayOfWeek::Wednesday, .42);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple5ByItem4AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
      auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Sunday, .42);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple5ByItem5AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
      auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .21);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple6ByItem1AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
      auto t2 = Tuple<>::Create("Other"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple6ByItem2AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
      auto t2 = Tuple<>::Create("Value"_s, 84, true, DayOfWeek::Wednesday, .42, U'a');
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple6ByItem3AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
      auto t2 = Tuple<>::Create("Value"_s, 42, false, DayOfWeek::Wednesday, .42, U'a');
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple6ByItem4AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
      auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Sunday, .42, U'a');
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple6ByItem5AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
      auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .21, U'a');
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple6ByItem6AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
      auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'b');
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple7ByItem1AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      auto t2 = Tuple<>::Create("Other"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple7ByItem2AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      auto t2 = Tuple<>::Create("Value"_s, 84, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple7ByItem3AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      auto t2 = Tuple<>::Create("Value"_s, 42, false, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple7ByItem4AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Sunday, .42, U'a', (byte)21);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple7ByItem5AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .21, U'a', (byte)21);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple7ByItem6AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'b', (byte)21);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTuple7ByItem7AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
      auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)42);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTupleRestByItem1AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      auto t2 = Tuple<>::Create("Other"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTupleRestByItem2AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      auto t2 = Tuple<>::Create("Value"_s, 84, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTupleRestByItem3AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      auto t2 = Tuple<>::Create("Value"_s, 42, false, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTupleRestByItem4AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Sunday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTupleRestByItem5AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .21, U'a', (byte)21, 12_h + 23_min + 2_s);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTupleRestByItem6AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .21, U'b', (byte)21, 12_h + 23_min + 2_s);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTupleRestByItem7AndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, 42, U'a', (byte)42, 12_h + 23_min + 2_s);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void Create2DifferentsTupleRestByRestAndCheckEquals() {
      auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
      auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, 42, U'a', (byte)21, 5_h + 28_min + 19_s);
      Assert::IsFalse(t1.Equals(t2));
    }
    
    void MyTuple() {
      using MyTuple = Tuple<Int32, string>;
      MyTuple tuple1(Int32(2), string("Cats"));
      Assert::AreEqual(2, tuple1.Item1);
      Assert::AreEqual("Cats", tuple1.Item2);
      Assert::AreEqual("(2, Cats)", tuple1.ToString());
    }
    
    void CreateArrayOfTuples() {
      Array<Tuple<string, int32>> tuples {Tuple<string, int32>("Value 1", 42), Tuple<string, int32>("Value 2", 21)};
      
      Assert::AreEqual("Value 1", tuples[0].Item1);
      Assert::AreEqual(42, tuples[0].Item2);
      Assert::AreEqual("Value 2", tuples[1].Item1);
      Assert::AreEqual(21, tuples[1].Item2);
    }
    
    void CreateListOfTuples() {
      System::Collections::Generic::List<Tuple<string, int32>> tuples {Tuple<string, int32>("Value 1", 42), Tuple<string, int32>("Value 2", 21)};
      Assert::AreEqual("Value 1", tuples[0].Item1);
      Assert::AreEqual(42, tuples[0].Item2);
      Assert::AreEqual("Value 2", tuples[1].Item1);
      Assert::AreEqual(21, tuples[1].Item2);
    }
    
    void CreateDictionaryOfTuples() {
      System::Collections::Generic::Dictionary<Tuple<string, int32>, int32> tuples {{Tuple<string, int32>("Value 1", 1), -1}, {Tuple<string, int32>("Value 2", 2), -2}};
      Assert::AreEqual(-1, tuples[{"Value 1"_s, 1}]);
      Assert::AreEqual(-2, tuples[{"Value 2"_s, 2}]);
      Assert::AreEqual(0, tuples[{"Value 3"_s, 3}]);
    }
  };
  
  _add_test(TupleTest, Tuple1)
  _add_test(TupleTest, Tuple2)
  _add_test(TupleTest, Tuple3)
  _add_test(TupleTest, Tuple4)
  _add_test(TupleTest, Tuple5)
  _add_test(TupleTest, Tuple6)
  _add_test(TupleTest, Tuple7)
  _add_test(TupleTest, TupleRest)
  _add_test(TupleTest, TupleRestWithTuple)
  _add_test(TupleTest, Tuple1ToString)
  _add_test(TupleTest, Tuple2ToString)
  _add_test(TupleTest, Tuple3ToString)
  _add_test(TupleTest, Tuple4ToString)
  _add_test(TupleTest, Tuple5ToString)
  _add_test(TupleTest, Tuple6ToString)
  _add_test(TupleTest, Tuple7ToString)
  _add_test(TupleTest, TupleRestToString)
  _add_test(TupleTest, TupleRestWithTupleToString)
  _add_test(TupleTest, CreateTuple1)
  _add_test(TupleTest, CreateTuple2)
  _add_test(TupleTest, CreateTuple3)
  _add_test(TupleTest, CreateTuple4)
  _add_test(TupleTest, CreateTuple5)
  _add_test(TupleTest, CreateTuple6)
  _add_test(TupleTest, CreateTuple7)
  _add_test(TupleTest, CreateTupleRest)
  _add_test(TupleTest, CreateTupleRestWithTuple)
  _add_test(TupleTest, CreateTuple1AndSetItem1)
  _add_test(TupleTest, CreateTuple2AndSetItem1)
  _add_test(TupleTest, CreateTuple2AndSetItem2)
  _add_test(TupleTest, CreateTuple3AndSetItem1)
  _add_test(TupleTest, CreateTuple3AndSetItem2)
  _add_test(TupleTest, CreateTuple3AndSetItem3)
  _add_test(TupleTest, CreateTuple4AndSetItem1)
  _add_test(TupleTest, CreateTuple4AndSetItem2)
  _add_test(TupleTest, CreateTuple4AndSetItem3)
  _add_test(TupleTest, CreateTuple4AndSetItem4)
  _add_test(TupleTest, CreateTuple5AndSetItem1)
  _add_test(TupleTest, CreateTuple5AndSetItem2)
  _add_test(TupleTest, CreateTuple5AndSetItem3)
  _add_test(TupleTest, CreateTuple5AndSetItem4)
  _add_test(TupleTest, CreateTuple5AndSetItem5)
  _add_test(TupleTest, CreateTuple6AndSetItem1)
  _add_test(TupleTest, CreateTuple6AndSetItem2)
  _add_test(TupleTest, CreateTuple6AndSetItem3)
  _add_test(TupleTest, CreateTuple6AndSetItem4)
  _add_test(TupleTest, CreateTuple6AndSetItem5)
  _add_test(TupleTest, CreateTuple6AndSetItem6)
  _add_test(TupleTest, CreateTuple7AndSetItem1)
  _add_test(TupleTest, CreateTuple7AndSetItem2)
  _add_test(TupleTest, CreateTuple7AndSetItem3)
  _add_test(TupleTest, CreateTuple7AndSetItem4)
  _add_test(TupleTest, CreateTuple7AndSetItem5)
  _add_test(TupleTest, CreateTuple7AndSetItem6)
  _add_test(TupleTest, CreateTuple7AndSetItem7)
  _add_test(TupleTest, CreateTupleRestAndSetItem1)
  _add_test(TupleTest, CreateTupleRestAndSetItem2)
  _add_test(TupleTest, CreateTupleRestAndSetItem3)
  _add_test(TupleTest, CreateTupleRestAndSetItem4)
  _add_test(TupleTest, CreateTupleRestAndSetItem5)
  _add_test(TupleTest, CreateTupleRestAndSetItem6)
  _add_test(TupleTest, CreateTupleRestAndSetItem7)
  _add_test(TupleTest, CreateTupleRestAndSetRest)
  _add_test(TupleTest, CreateTuple1AndCopyItToOther)
  _add_test(TupleTest, CreateTuple2AndCopyItToOther)
  _add_test(TupleTest, CreateTuple3AndCopyItToOther)
  _add_test(TupleTest, CreateTuple4AndCopyItToOther)
  _add_test(TupleTest, CreateTuple5AndCopyItToOther)
  _add_test(TupleTest, CreateTuple6AndCopyItToOther)
  _add_test(TupleTest, CreateTuple7AndCopyItToOther)
  _add_test(TupleTest, CreateTupleRestAndCopyItToOther)
  _add_test(TupleTest, Create2SameTuple1AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple1ByItem1AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple2ByItem1AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple2ByItem2AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple3ByItem1AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple3ByItem2AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple3ByItem3AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple4ByItem1AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple4ByItem2AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple4ByItem3AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple4ByItem4AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple5ByItem1AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple5ByItem2AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple5ByItem3AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple5ByItem4AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple5ByItem5AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple6ByItem1AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple6ByItem2AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple6ByItem3AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple6ByItem4AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple6ByItem5AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple6ByItem6AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple7ByItem1AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple7ByItem2AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple7ByItem3AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple7ByItem4AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple7ByItem5AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple7ByItem6AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTuple7ByItem7AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTupleRestByItem1AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTupleRestByItem2AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTupleRestByItem3AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTupleRestByItem4AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTupleRestByItem5AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTupleRestByItem6AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTupleRestByItem7AndCheckEquals)
  _add_test(TupleTest, Create2DifferentsTupleRestByRestAndCheckEquals)

  _add_test(TupleTest, MyTuple)
  _add_test(TupleTest, CreateArrayOfTuples)
  _add_test(TupleTest, CreateListOfTuples)
  _add_test(TupleTest, CreateDictionaryOfTuples)
  
  TEST(Tuple, NativeTuple) {
    Tuple<int32, char> tuple1(Int32(2), 'C');
    EXPECT_EQ(tuple1.Item1(), 2);
    EXPECT_EQ(tuple1.Item2(), 'C');
    EXPECT_EQ(tuple1.ToString(), "(2, C)");
  }
  
  TEST(Tuple, SharedPointerTuple) {
    refptr<String> s1 = new String("Item1");
    refptr<Int32> s2 = new Int32(2);
    refptr<String> s3 = new String("Item3");
    Tuple<refptr<String>, refptr<Int32>> tuple1(s1, s2);
    Tuple<refptr<Int32>, refptr<String>> tuple2(s2, s3);
    EXPECT_EQ(tuple1.Item1(), s1);
    EXPECT_EQ(tuple1.Item2(), s2);
  }
}
