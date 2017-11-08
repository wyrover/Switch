#include <Switch/System/Tuple.hpp>
#include <Switch/System/Convert.hpp>
#include <Switch/System/Int32.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/Version.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  TEST(TupleTest, Tuple1) {
    Tuple<string> t("Value"_s);
    ASSERT_EQ("Value", t.Item1());
  }
  
  TEST(TupleTest, Tuple2) {
    Tuple<string, int> t("Value", 42);
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
  }
  
  TEST(TupleTest, Tuple3) {
    Tuple<string, int, bool> t("Value", 42, true);
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
  }
  
  TEST(TupleTest, Tuple4) {
    Tuple<string, int, bool, DayOfWeek> t("Value", 42, true, DayOfWeek::Wednesday);
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
  }
  
  TEST(TupleTest, Tuple5) {
    Tuple<string, int, bool, DayOfWeek, double> t("Value", 42, true, DayOfWeek::Wednesday, .42);
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
  }
  
  TEST(TupleTest, Tuple6) {
    Tuple<string, int, bool, DayOfWeek, double, char32> t("Value", 42, true, DayOfWeek::Wednesday, .42, U'a');
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
  }
  
  TEST(TupleTest, Tuple7) {
    Tuple<string, int, bool, DayOfWeek, double, char32, byte> t("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', 21);
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
    ASSERT_EQ((byte)21, t.Item7());
  }
  
  TEST(TupleTest, TupleRest) {
    Tuple<string, int, bool, DayOfWeek, double, char32, byte, TimeSpan> t("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', 21, 12_h + 23_min + 2_s);
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
    ASSERT_EQ((byte)21, t.Item7());
    ASSERT_EQ(12_h + 23_min + 2_s, t.Rest());
  }
  
  TEST(TupleTest, TupleRestWithTuple) {
    Tuple<string, int, bool, DayOfWeek, double, char32, byte, Tuple<TimeSpan, Version>> t("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', 21, {12_h + 23_min + 2_s, {1, 2, 3}});
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
    ASSERT_EQ((byte)21, t.Item7());
    ASSERT_EQ(12_h + 23_min + 2_s, t.Rest().Item1());
    ASSERT_EQ(Version(1, 2, 3), t.Rest().Item2());
  }
  
  TEST(TupleTest, Tuple1ToString) {
    Tuple<string> t("Value"_s);
    ASSERT_EQ("(Value)", t.ToString());
  }
  
  TEST(TupleTest, Tuple2ToString) {
    Tuple<string, int> t("Value", 42);
    ASSERT_EQ("(Value, 42)", t.ToString());
  }
  
  TEST(TupleTest, Tuple3ToString) {
    Tuple<string, int, bool> t("Value", 42, true);
    ASSERT_EQ("(Value, 42, True)", t.ToString());
  }
  
  TEST(TupleTest, Tuple4ToString) {
    Tuple<string, int, bool, DayOfWeek> t("Value", 42, true, DayOfWeek::Wednesday);
    ASSERT_EQ("(Value, 42, True, Wednesday)", t.ToString());
  }
  
  TEST(TupleTest, Tuple5ToString) {
    Tuple<string, int, bool, DayOfWeek, double> t("Value", 42, true, DayOfWeek::Wednesday, .42);
    ASSERT_EQ("(Value, 42, True, Wednesday, 0.42)", t.ToString());
  }
  
  TEST(TupleTest, Tuple6ToString) {
    Tuple<string, int, bool, DayOfWeek, double, char32> t("Value", 42, true, DayOfWeek::Wednesday, .42, U'a');
    ASSERT_EQ("(Value, 42, True, Wednesday, 0.42, a)", t.ToString());
  }
  
  TEST(TupleTest, Tuple7ToString) {
    Tuple<string, int, bool, DayOfWeek, double, char32, byte> t("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', 21);
    ASSERT_EQ("(Value, 42, True, Wednesday, 0.42, a, 21)", t.ToString());
  }
  
  TEST(TupleTest, TupleRestToString) {
    Tuple<string, int, bool, DayOfWeek, double, char32, byte, TimeSpan> t("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', 21, 12_h + 23_min + 2_s);
    ASSERT_EQ("(Value, 42, True, Wednesday, 0.42, a, 21, 12:23:02)", t.ToString());
  }
  
  TEST(TupleTest, TupleRestWithTupleToString) {
    Tuple<string, int, bool, DayOfWeek, double, char32, byte, Tuple<TimeSpan, Version>> t("Value", 42, true, DayOfWeek::Wednesday, .42, U'a', 21, {12_h + 23_min + 2_s, {1, 2, 3}});
    ASSERT_EQ("(Value, 42, True, Wednesday, 0.42, a, 21, 12:23:02, 1.2.3)", t.ToString());
  }
  
  TEST(TupleTest, CreateTuple1) {
    auto t = Tuple<>::Create("Value"_s);
    ASSERT_EQ("Value", t.Item1());
  }
  
  TEST(TupleTest, CreateTuple2) {
    auto t = Tuple<>::Create("Value"_s, 42);
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
  }
  
  TEST(TupleTest, CreateTuple3) {
    auto t = Tuple<>::Create("Value"_s, 42, true);
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
  }
  
  TEST(TupleTest, CreateTuple4) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday);
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
  }
  
  TEST(TupleTest, CreateTuple5) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
  }
  
  TEST(TupleTest, CreateTuple6) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
  }
  
  TEST(TupleTest, CreateTuple7) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
    ASSERT_EQ((byte)21, t.Item7());
  }
  
  TEST(TupleTest, CreateTupleRest) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
    ASSERT_EQ((byte)21, t.Item7());
    ASSERT_EQ(12_h + 23_min + 2_s, t.Rest());
  }
  
  TEST(TupleTest, CreateTupleRestWithTuple) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, Tuple<>::Create(12_h + 23_min + 2_s, Version(1, 2, 3)));
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
    ASSERT_EQ((byte)21, t.Item7());
    ASSERT_EQ(12_h + 23_min + 2_s, t.Rest().Item1());
    ASSERT_EQ(Version(1, 2, 3), t.Rest().Item2());
  }
  
  TEST(TupleTest, CreateTuple1AndSetItem1) {
    auto t = Tuple<>::Create("Value"_s);
    t.Item1 = "Other";
    ASSERT_EQ("Other", t.Item1());
  }
  
  TEST(TupleTest, CreateTuple2AndSetItem1) {
    auto t = Tuple<>::Create("Value"_s, 42);
    t.Item1 = "Other";
    ASSERT_EQ("Other", t.Item1());
    ASSERT_EQ(42, t.Item2());
  }
  
  TEST(TupleTest, CreateTuple2AndSetItem2) {
    auto t = Tuple<>::Create("Value"_s, 42);
    t.Item2 = 84;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(84, t.Item2());
  }
  
  TEST(TupleTest, CreateTuple3AndSetItem1) {
    auto t = Tuple<>::Create("Value"_s, 42, true);
    t.Item1 = "Other";
    ASSERT_EQ("Other", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
  }
  
  TEST(TupleTest, CreateTuple3AndSetItem2) {
    auto t = Tuple<>::Create("Value"_s, 42, true);
    t.Item2 = 84;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(84, t.Item2());
    ASSERT_EQ(true, t.Item3());
  }
  
  TEST(TupleTest, CreateTuple3AndSetItem3) {
    auto t = Tuple<>::Create("Value"_s, 42, true);
    t.Item3 = false;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(false, t.Item3());
  }
  
  TEST(TupleTest, CreateTuple4AndSetItem1) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday);
    t.Item1 = "Other";
    ASSERT_EQ("Other", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
  }
  
  TEST(TupleTest, CreateTuple4AndSetItem2) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday);
    t.Item2 = 84;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(84, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
  }
  
  TEST(TupleTest, CreateTuple4AndSetItem3) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday);
    t.Item3 = false;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(false, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
  }
  
  TEST(TupleTest, CreateTuple4AndSetItem4) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday);
    t.Item4 = DayOfWeek::Sunday;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Sunday, t.Item4());
  }
  
  TEST(TupleTest, CreateTuple5AndSetItem1) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
    t.Item1 = "Other";
    ASSERT_EQ("Other", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
  }
  
  TEST(TupleTest, CreateTuple5AndSetItem2) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
    t.Item2 = 84;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(84, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
  }
  
  TEST(TupleTest, CreateTuple5AndSetItem3) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
    t.Item3 = false;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(false, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
  }
  
  TEST(TupleTest, CreateTuple5AndSetItem4) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
    t.Item4 = DayOfWeek::Sunday;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Sunday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
  }
  
  TEST(TupleTest, CreateTuple5AndSetItem5) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
    t.Item5 = .21;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.21, t.Item5());
  }
  
  TEST(TupleTest, CreateTuple6AndSetItem1) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
    t.Item1 = "Other";
    ASSERT_EQ("Other", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
  }
  
  TEST(TupleTest, CreateTuple6AndSetItem2) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
    t.Item2 = 84;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(84, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
  }
  
  TEST(TupleTest, CreateTuple6AndSetItem3) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
    t.Item3 = false;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(false, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
  }
  
  TEST(TupleTest, CreateTuple6AndSetItem4) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
    t.Item4 = DayOfWeek::Sunday;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Sunday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
  }
  
  TEST(TupleTest, CreateTuple6AndSetItem5) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
    t.Item5 = .21;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.21, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
  }
  
  TEST(TupleTest, CreateTuple6AndSetItem6) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
    t.Item6 = U'b';
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'b', t.Item6());
  }
  
  TEST(TupleTest, CreateTuple7AndSetItem1) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    t.Item1 = "Other";
    ASSERT_EQ("Other", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
    ASSERT_EQ((byte)21, t.Item7());
  }
  
  TEST(TupleTest, CreateTuple7AndSetItem2) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    t.Item2 = 84;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(84, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
    ASSERT_EQ((byte)21, t.Item7());
  }
  
  TEST(TupleTest, CreateTuple7AndSetItem3) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    t.Item3 = false;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(false, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
    ASSERT_EQ((byte)21, t.Item7());
  }
  
  TEST(TupleTest, CreateTuple7AndSetItem4) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    t.Item4 = DayOfWeek::Sunday;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Sunday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
    ASSERT_EQ((byte)21, t.Item7());
  }
  
  TEST(TupleTest, CreateTuple7AndSetItem5) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    t.Item5 = .21;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.21, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
    ASSERT_EQ((byte)21, t.Item7());
  }
  
  TEST(TupleTest, CreateTuple7AndSetItem6) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    t.Item6 = U'b';
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'b', t.Item6());
    ASSERT_EQ((byte)21, t.Item7());
  }
  
  TEST(TupleTest, CreateTuple7AndSetItem7) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    t.Item7 = 42;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
    ASSERT_EQ((byte)42, t.Item7());
  }
  
  TEST(TupleTest, CreateTupleRestAndSetItem1) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    t.Item1 = "Other";
    ASSERT_EQ("Other", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
    ASSERT_EQ((byte)21, t.Item7());
    ASSERT_EQ(12_h + 23_min + 2_s, t.Rest());
  }
  
  TEST(TupleTest, CreateTupleRestAndSetItem2) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    t.Item2 = 84;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(84, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
    ASSERT_EQ((byte)21, t.Item7());
    ASSERT_EQ(12_h + 23_min + 2_s, t.Rest());
  }
  
  TEST(TupleTest, CreateTupleRestAndSetItem3) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    t.Item3 = false;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(false, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
    ASSERT_EQ((byte)21, t.Item7());
    ASSERT_EQ(12_h + 23_min + 2_s, t.Rest());
  }
  
  TEST(TupleTest, CreateTupleRestAndSetItem4) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    t.Item4 = DayOfWeek::Sunday;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Sunday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
    ASSERT_EQ((byte)21, t.Item7());
    ASSERT_EQ(12_h + 23_min + 2_s, t.Rest());
  }
  
  TEST(TupleTest, CreateTupleRestAndSetItem5) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    t.Item5 = .21;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.21, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
    ASSERT_EQ((byte)21, t.Item7());
    ASSERT_EQ(12_h + 23_min + 2_s, t.Rest());
  }
  
  TEST(TupleTest, CreateTupleRestAndSetItem6) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    t.Item6 = U'b';
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'b', t.Item6());
    ASSERT_EQ((byte)21, t.Item7());
    ASSERT_EQ(12_h + 23_min + 2_s, t.Rest());
  }
  
  TEST(TupleTest, CreateTupleRestAndSetItem7) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    t.Item7 = 42;
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
    ASSERT_EQ((byte)42, t.Item7());
    ASSERT_EQ(12_h + 23_min + 2_s, t.Rest());
  }
  
  TEST(TupleTest, CreateTupleRestAndSetRest) {
    auto t = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    t.Rest = TimeSpan(5, 28, 19);
    ASSERT_EQ("Value", t.Item1());
    ASSERT_EQ(42, t.Item2());
    ASSERT_EQ(true, t.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t.Item4());
    ASSERT_EQ(.42, t.Item5());
    ASSERT_EQ(U'a', t.Item6());
    ASSERT_EQ((byte)21, t.Item7());
    ASSERT_EQ(5_h + 28_min + 19_s, t.Rest());
  }
  
  TEST(TupleTest, CreateTuple1AndCopyItToOther) {
    auto t1 = Tuple<>::Create("Value"_s);
    Tuple<string> t2;
    t2 = t1;
    ASSERT_EQ("Value", t2.Item1());
    
  }
  
  TEST(TupleTest, CreateTuple2AndCopyItToOther) {
    auto t1 = Tuple<>::Create("Value"_s, 42);
    Tuple<string, int32> t2;
    t2 = t1;
    ASSERT_EQ("Value", t2.Item1());
    ASSERT_EQ(42, t2.Item2());
  }
  
  TEST(TupleTest, CreateTuple3AndCopyItToOther) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true);
    Tuple<string, int32, bool> t2;
    t2 = t1;
    ASSERT_EQ("Value", t2.Item1());
    ASSERT_EQ(42, t2.Item2());
    ASSERT_EQ(true, t2.Item3());
  }
  
  TEST(TupleTest, CreateTuple4AndCopyItToOther) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday);
    Tuple<string, int32, bool, DayOfWeek> t2;
    t2 = t1;
    ASSERT_EQ("Value", t2.Item1());
    ASSERT_EQ(42, t2.Item2());
    ASSERT_EQ(true, t2.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t2.Item4());
  }
  
  TEST(TupleTest, CreateTuple5AndCopyItToOther) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
    Tuple<string, int32, bool, DayOfWeek, double> t2;
    t2 = t1;
    ASSERT_EQ("Value", t2.Item1());
    ASSERT_EQ(42, t2.Item2());
    ASSERT_EQ(true, t2.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t2.Item4());
    ASSERT_EQ(.42, t2.Item5());
  }
  
  TEST(TupleTest, CreateTuple6AndCopyItToOther) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
    Tuple<string, int32, bool, DayOfWeek, double, char32> t2;
    t2 = t1;
    ASSERT_EQ("Value", t2.Item1());
    ASSERT_EQ(42, t2.Item2());
    ASSERT_EQ(true, t2.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t2.Item4());
    ASSERT_EQ(.42, t2.Item5());
    ASSERT_EQ(U'a', t2.Item6());
  }
  
  TEST(TupleTest, CreateTuple7AndCopyItToOther) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    Tuple<string, int32, bool, DayOfWeek, double, char32, byte> t2;
    t2 = t1;
    ASSERT_EQ("Value", t2.Item1());
    ASSERT_EQ(42, t2.Item2());
    ASSERT_EQ(true, t2.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t2.Item4());
    ASSERT_EQ(.42, t2.Item5());
    ASSERT_EQ(U'a', t2.Item6());
    ASSERT_EQ((byte)21, t2.Item7());
  }
  
  TEST(TupleTest, CreateTupleRestAndCopyItToOther) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    Tuple<string, int32, bool, DayOfWeek, double, char32, byte, TimeSpan> t2;
    t2 = t1;
    ASSERT_EQ("Value", t2.Item1());
    ASSERT_EQ(42, t2.Item2());
    ASSERT_EQ(true, t2.Item3());
    ASSERT_EQ(DayOfWeek::Wednesday, t2.Item4());
    ASSERT_EQ(.42, t2.Item5());
    ASSERT_EQ(U'a', t2.Item6());
    ASSERT_EQ((byte)21, t2.Item7());
    ASSERT_EQ(TimeSpan(12, 23, 2), t2.Rest());
  }
  
  TEST(TupleTest, Create2SameTuple1AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s);
    auto t2 = Tuple<>::Create("Value"_s);
    ASSERT_TRUE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2SameTuple2AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42);
    auto t2 = Tuple<>::Create("Value"_s, 42);
    ASSERT_TRUE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2SameTuple3AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true);
    auto t2 = Tuple<>::Create("Value"_s, 42, true);
    ASSERT_TRUE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2SameTuple4AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday);
    auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday);
    ASSERT_TRUE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2SameTuple5AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
    auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
    ASSERT_TRUE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2SameTuple6AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
    auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
    ASSERT_TRUE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2SameTuple7AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    ASSERT_TRUE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2SameTupleRestAndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    ASSERT_TRUE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple1ByItem1AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s);
    auto t2 = Tuple<>::Create("Other"_s);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple2ByItem1AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42);
    auto t2 = Tuple<>::Create("Other"_s, 42);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple2ByItem2AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42);
    auto t2 = Tuple<>::Create("Value"_s, 84);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple3ByItem1AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true);
    auto t2 = Tuple<>::Create("Other"_s, 42, true);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple3ByItem2AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true);
    auto t2 = Tuple<>::Create("Value"_s, 84, true);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple3ByItem3AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true);
    auto t2 = Tuple<>::Create("Value"_s, 42, false);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple4ByItem1AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday);
    auto t2 = Tuple<>::Create("Other"_s, 42, true, DayOfWeek::Wednesday);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple4ByItem2AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday);
    auto t2 = Tuple<>::Create("Value"_s, 84, true, DayOfWeek::Wednesday);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple4ByItem3AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday);
    auto t2 = Tuple<>::Create("Value"_s, 42, false, DayOfWeek::Wednesday);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple4ByItem4AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday);
    auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Sunday);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple5ByItem1AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
    auto t2 = Tuple<>::Create("Other"_s, 42, true, DayOfWeek::Wednesday, .42);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple5ByItem2AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
    auto t2 = Tuple<>::Create("Value"_s, 84, true, DayOfWeek::Wednesday, .42);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple5ByItem3AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
    auto t2 = Tuple<>::Create("Value"_s, 42, false, DayOfWeek::Wednesday, .42);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple5ByItem4AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
    auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Sunday, .42);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple5ByItem5AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42);
    auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .21);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple6ByItem1AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
    auto t2 = Tuple<>::Create("Other"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple6ByItem2AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
    auto t2 = Tuple<>::Create("Value"_s, 84, true, DayOfWeek::Wednesday, .42, U'a');
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple6ByItem3AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
    auto t2 = Tuple<>::Create("Value"_s, 42, false, DayOfWeek::Wednesday, .42, U'a');
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple6ByItem4AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
    auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Sunday, .42, U'a');
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple6ByItem5AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
    auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .21, U'a');
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple6ByItem6AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a');
    auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'b');
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple7ByItem1AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    auto t2 = Tuple<>::Create("Other"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple7ByItem2AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    auto t2 = Tuple<>::Create("Value"_s, 84, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple7ByItem3AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    auto t2 = Tuple<>::Create("Value"_s, 42, false, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple7ByItem4AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Sunday, .42, U'a', (byte)21);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple7ByItem5AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .21, U'a', (byte)21);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple7ByItem6AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'b', (byte)21);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTuple7ByItem7AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21);
    auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)42);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTupleRestByItem1AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    auto t2 = Tuple<>::Create("Other"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTupleRestByItem2AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    auto t2 = Tuple<>::Create("Value"_s, 84, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTupleRestByItem3AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    auto t2 = Tuple<>::Create("Value"_s, 42, false, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTupleRestByItem4AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Sunday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTupleRestByItem5AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .21, U'a', (byte)21, 12_h + 23_min + 2_s);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTupleRestByItem6AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .21, U'b', (byte)21, 12_h + 23_min + 2_s);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTupleRestByItem7AndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, 42, U'a', (byte)42, 12_h + 23_min + 2_s);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, Create2DifferentsTupleRestByRestAndCheckEquals) {
    auto t1 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, .42, U'a', (byte)21, 12_h + 23_min + 2_s);
    auto t2 = Tuple<>::Create("Value"_s, 42, true, DayOfWeek::Wednesday, 42, U'a', (byte)21, 5_h + 28_min + 19_s);
    ASSERT_FALSE(t1.Equals(t2));
  }
  
  TEST(TupleTest, MyTuple) {
    using MyTuple = Tuple<Int32, string>;
    MyTuple tuple1(Int32(2), string("Cats"));
    ASSERT_EQ(2, tuple1.Item1());
    ASSERT_EQ("Cats", tuple1.Item2());
    ASSERT_EQ("(2, Cats)", tuple1.ToString());
  }
  
  TEST(TupleTest, CreateArrayOfTuples) {
    Array<Tuple<string, int32>> tuples {Tuple<string, int32>("Value 1", 42), Tuple<string, int32>("Value 2", 21)};
    
    ASSERT_EQ("Value 1", tuples[0].Item1());
    ASSERT_EQ(42, tuples[0].Item2());
    ASSERT_EQ("Value 2", tuples[1].Item1());
    ASSERT_EQ(21, tuples[1].Item2());
  }
  
  TEST(TupleTest, CreateListOfTuples) {
    System::Collections::Generic::List<Tuple<string, int32>> tuples {Tuple<string, int32>("Value 1", 42), Tuple<string, int32>("Value 2", 21)};
    ASSERT_EQ("Value 1", tuples[0].Item1());
    ASSERT_EQ(42, tuples[0].Item2());
    ASSERT_EQ("Value 2", tuples[1].Item1());
    ASSERT_EQ(21, tuples[1].Item2());
  }
  
  TEST(TupleTest, CreateDictionaryOfTuples) {
    System::Collections::Generic::Dictionary<Tuple<string, int32>, int32> tuples {{Tuple<string, int32>("Value 1", 1), -1}, {Tuple<string, int32>("Value 2", 2), -2}};
    ASSERT_EQ(-1, (tuples[{"Value 1"_s, 1}]));
    ASSERT_EQ(-2, (tuples[{"Value 2"_s, 2}]));
    ASSERT_EQ(0, (tuples[{"Value 3"_s, 3}]));
  }
  
  TEST(TupleTest, NativeTuple) {
    Tuple<int32, char> tuple1(Int32(2), 'C');
    ASSERT_EQ(tuple1.Item1(), 2);
    ASSERT_EQ(tuple1.Item2(), 'C');
    ASSERT_EQ(tuple1.ToString(), "(2, C)");
  }
  
  TEST(TupleTest, SharedPointerTuple) {
    refptr<String> s1 = new String("Item1");
    refptr<Int32> s2 = new Int32(2);
    refptr<String> s3 = new String("Item3");
    Tuple<refptr<String>, refptr<Int32>> tuple1(s1, s2);
    Tuple<refptr<Int32>, refptr<String>> tuple2(s2, s3);
    ASSERT_EQ(tuple1.Item1(), s1);
    ASSERT_EQ(tuple1.Item2(), s2);
  }
}

