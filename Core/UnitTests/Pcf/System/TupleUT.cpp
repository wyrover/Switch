#include <Pcf/System/Tuple.hpp>
#include <Pcf/TUnit/Assert.hpp>
#include <Pcf/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  
  TEST(Tuple, 1) {
    Tuple<Int32> tuple1(512);
    Tuple<Int32> tuple2(24);
    EXPECT_EQ(tuple1.Item1(), 512);
    EXPECT_EQ(tuple1.ToString(), "(512)");
    EXPECT_FALSE(tuple1.Equals(tuple2));
  }
  
  TEST(Tuple, 2) {
    Tuple<Int32, string> tuple1(Int32(2), string("Cats"));
    EXPECT_EQ(tuple1.Item1(), 2);
    EXPECT_EQ(tuple1.Item2(), "Cats");
    EXPECT_EQ(tuple1.ToString(), "(2, Cats)");
  }
  
  TEST(Tuple, 3) {
    Tuple<uint32, string, string> tuple1(2, "Cats", "Color [Brown]");
    EXPECT_EQ(tuple1.Item1(), 2u);
    EXPECT_EQ(tuple1.Item2(), "Cats");
    EXPECT_EQ(tuple1.Item3(), "Color [Brown]");
    EXPECT_EQ(tuple1.ToString(), "(2, Cats, Color [Brown])");
  }
  
  TEST(Tuple, 22) {
    Tuple<string, string, Int32, Boolean> tuple1("Yves", "Fiumefreddo", 41, true);
    EXPECT_EQ(tuple1.Item1(), "Yves");
    EXPECT_EQ(tuple1.Item2(), "Fiumefreddo");
    EXPECT_EQ(tuple1.Item3(), 41);
    EXPECT_EQ(tuple1.Item4(), true);
    EXPECT_EQ(tuple1.ToString(), "(Yves, Fiumefreddo, 41, True)");
  }
  
  TEST(Tuple, 5) {
    Tuple<string, string, Int32, Boolean, string> tuple1("Yves", "Fiumefreddo", 41, true, "Rue Jean Schinler");
    EXPECT_EQ(tuple1.Item1(), "Yves");
    EXPECT_EQ(tuple1.Item2(), "Fiumefreddo");
    EXPECT_EQ(tuple1.Item3(), 41);
    EXPECT_EQ(tuple1.Item4(), true);
    EXPECT_EQ(tuple1.Item5(), "Rue Jean Schinler");
    EXPECT_EQ(tuple1.ToString(), "(Yves, Fiumefreddo, 41, True, Rue Jean Schinler)");
  }
  
  TEST(Tuple, 6) {
    Tuple<string, string, Int32, Boolean, string, Int32> tuple1("Yves", "Fiumefreddo", 41, true, "Rue Jean Schinler", 22);
    EXPECT_EQ(tuple1.Item1(), "Yves");
    EXPECT_EQ(tuple1.Item2(), "Fiumefreddo");
    EXPECT_EQ(tuple1.Item3(), 41);
    EXPECT_EQ(tuple1.Item4(), true);
    EXPECT_EQ(tuple1.Item5(), "Rue Jean Schinler");
    EXPECT_EQ(tuple1.Item6(), 22);
    EXPECT_EQ(tuple1.ToString(), "(Yves, Fiumefreddo, 41, True, Rue Jean Schinler, 22)");
  }
  
  TEST(Tuple, 7) {
    Tuple<string, string, Int32, Boolean, string, Int32, Int32> tuple1("Yves", "Fiumefreddo", 41, true, "Rue Jean Schinler", 22, 4140);
    EXPECT_EQ(tuple1.Item1(), "Yves");
    EXPECT_EQ(tuple1.Item2(), "Fiumefreddo");
    EXPECT_EQ(tuple1.Item3(), 41);
    EXPECT_EQ(tuple1.Item4(), true);
    EXPECT_EQ(tuple1.Item5(), "Rue Jean Schinler");
    EXPECT_EQ(tuple1.Item6(), 22);
    EXPECT_EQ(tuple1.Item7(), 4140);
    EXPECT_EQ(tuple1.ToString(), "(Yves, Fiumefreddo, 41, True, Rue Jean Schinler, 22, 4140)");
  }
  
  TEST(Tuple, Rest) {
    Tuple<string, string, Int32, Boolean, string, Int32, Int32, Tuple<string, string>> tuple1("Yves", "Fiumefreddo", 41, true, "Rue Jean Schinler", 22, 4140, Tuple<string, string>("Sprimont", "Belgique"));
    EXPECT_EQ(tuple1.Item1(), "Yves");
    EXPECT_EQ(tuple1.Item2(), "Fiumefreddo");
    EXPECT_EQ(tuple1.Item3(), 41);
    EXPECT_EQ(tuple1.Item4(), true);
    EXPECT_EQ(tuple1.Item5(), "Rue Jean Schinler");
    EXPECT_EQ(tuple1.Item6(), 22);
    EXPECT_EQ(tuple1.Item7(), 4140);
    EXPECT_EQ(tuple1.Rest().Item1(), "Sprimont");
    EXPECT_EQ(tuple1.Rest().Item2(), "Belgique");
    EXPECT_EQ(tuple1.ToString(), "(Yves, Fiumefreddo, 41, True, Rue Jean Schinler, 22, 4140, Sprimont, Belgique)");
  }
  
  TEST(Tuple, Array) {
    Tuple<string, string, Int32, Boolean> tuple1("Yves", "Fiumefreddo", 41, true);
    Tuple<string, string, Int32, Boolean> tuple2("Valerie", "Lekeu", 32, true);
    Array<Tuple<string, string, Int32, Boolean>> tupleArray(2);
    tupleArray[0]=tuple1;
    tupleArray[1]=tuple2;
  }
  
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
  
  TEST(Tuple, MyTuple) {
    using MyTuple = Tuple<Int32, string>;
    
    MyTuple tuple1(Int32(2), string("Cats"));
     EXPECT_EQ(tuple1.Item1(), 2);
    EXPECT_EQ(tuple1.Item2(), "Cats");
    EXPECT_EQ(tuple1.ToString(), "(2, Cats)");
  }
  
  template<typename TA1>
  using Tuple1 = Tuple<TA1>;
  
  template<typename TA1, typename TA2>
  using Tuple2 = Tuple<TA1, TA2>;
  
  template<typename TA1, typename TA2, typename TA3>
  using Tuple3 = Tuple<TA1, TA2, TA3>;
  
  template<typename TA1, typename TA2, typename TA3, typename TA4>
  using Tuple4 = Tuple<TA1, TA2, TA3, TA4>;
  
  template<typename TA1, typename TA2, typename TA3, typename TA4, typename TA5>
  using Tuple5 = Tuple<TA1, TA2, TA3, TA4, TA5>;
  
  template<typename TA1, typename TA2, typename TA3, typename TA4, typename TA5, typename TA6>
  using Tuple6 = Tuple<TA1, TA2, TA3, TA4, TA5, TA6>;
  
  template<typename TA1, typename TA2, typename TA3, typename TA4, typename TA5, typename TA6, typename TA7>
  using Tuple7 = Tuple<TA1, TA2, TA3, TA4, TA5, TA6, TA7>;
  
  template<typename TA1, typename TA2, typename TA3, typename TA4, typename TA5, typename TA6, typename TA7, typename TR>
  using TupleRest = Tuple<TA1, TA2, TA3, TA4, TA5, TA6, TA7, TR>;
  
  TEST(Tuple, My1) {
    Tuple1<Int32> tuple1(512);
    EXPECT_EQ(tuple1.Item1(), 512);
    EXPECT_EQ(tuple1.ToString(), "(512)");
  }
  
  TEST(Tuple, My2) {
    Tuple2<Int32, string> tuple1(Int32(2), string("Cats"));
    EXPECT_EQ(tuple1.Item1(), 2);
    EXPECT_EQ(tuple1.Item2(), "Cats");
    EXPECT_EQ(tuple1.ToString(), "(2, Cats)");
  }
  
  TEST(Tuple, My3) {
    Tuple3<uint32, string, string> tuple1(2, "Cats", "Color [Brown]");
    EXPECT_EQ(tuple1.Item1(), 2u);
    EXPECT_EQ(tuple1.Item2(), "Cats");
    EXPECT_EQ(tuple1.Item3(), "Color [Brown]");
    EXPECT_EQ(tuple1.ToString(), "(2, Cats, Color [Brown])");
  }
  
  TEST(Tuple, My4) {
    Tuple4<string, string, Int32, Boolean> tuple1("Yves", "Fiumefreddo", 41, true);
    EXPECT_EQ(tuple1.Item1(), "Yves");
    EXPECT_EQ(tuple1.Item2(), "Fiumefreddo");
    EXPECT_EQ(tuple1.Item3(), 41);
    EXPECT_EQ(tuple1.Item4(), true);
    EXPECT_EQ(tuple1.ToString(), "(Yves, Fiumefreddo, 41, True)");
  }
  
  TEST(Tuple, My5) {
    Tuple5<string, string, Int32, Boolean, string> tuple1("Yves", "Fiumefreddo", 41, true, "Rue Jean Schinler");
    EXPECT_EQ(tuple1.Item1(), "Yves");
    EXPECT_EQ(tuple1.Item2(), "Fiumefreddo");
    EXPECT_EQ(tuple1.Item3(), 41);
    EXPECT_EQ(tuple1.Item4(), true);
    EXPECT_EQ(tuple1.Item5(), "Rue Jean Schinler");
    EXPECT_EQ(tuple1.ToString(), "(Yves, Fiumefreddo, 41, True, Rue Jean Schinler)");
  }
  
  TEST(Tuple, My6) {
    Tuple6<string, string, Int32, Boolean, string, Int32> tuple1("Yves", "Fiumefreddo", 41, true, "Rue Jean Schinler", 22);
    EXPECT_EQ(tuple1.Item1(), "Yves");
    EXPECT_EQ(tuple1.Item2(), "Fiumefreddo");
    EXPECT_EQ(tuple1.Item3(), 41);
    EXPECT_EQ(tuple1.Item4(), true);
    EXPECT_EQ(tuple1.Item5(), "Rue Jean Schinler");
    EXPECT_EQ(tuple1.Item6(), 22);
    EXPECT_EQ(tuple1.ToString(), "(Yves, Fiumefreddo, 41, True, Rue Jean Schinler, 22)");
  }
  
  TEST(Tuple, My7) {
    Tuple7<string, string, Int32, Boolean, string, Int32, Int32> tuple1("Yves", "Fiumefreddo", 41, true, "Rue Jean Schinler", 22, 4140);
    EXPECT_EQ(tuple1.Item1(), "Yves");
    EXPECT_EQ(tuple1.Item2(), "Fiumefreddo");
    EXPECT_EQ(tuple1.Item3(), 41);
    EXPECT_EQ(tuple1.Item4(), true);
    EXPECT_EQ(tuple1.Item5(), "Rue Jean Schinler");
    EXPECT_EQ(tuple1.Item6(), 22);
    EXPECT_EQ(tuple1.Item7(), 4140);
    EXPECT_EQ(tuple1.ToString(), "(Yves, Fiumefreddo, 41, True, Rue Jean Schinler, 22, 4140)");
  }
  
  TEST(Tuple, MyRest) {
    TupleRest<string, string, Int32, Boolean, string, Int32, Int32, Tuple<string, string>> tuple1("Yves", "Fiumefreddo", 41, true, "Rue Jean Schinler", 22, 4140, Tuple<string, string>("Sprimont", "Belgique"));
    EXPECT_EQ(tuple1.Item1(), "Yves");
    EXPECT_EQ(tuple1.Item2(), "Fiumefreddo");
    EXPECT_EQ(tuple1.Item3(), 41);
    EXPECT_EQ(tuple1.Item4(), true);
    EXPECT_EQ(tuple1.Item5(), "Rue Jean Schinler");
    EXPECT_EQ(tuple1.Item6(), 22);
    EXPECT_EQ(tuple1.Item7(), 4140);
    EXPECT_EQ(tuple1.Rest().Item1(), "Sprimont");
    EXPECT_EQ(tuple1.Rest().Item2(), "Belgique");
    EXPECT_EQ(tuple1.ToString(), "(Yves, Fiumefreddo, 41, True, Rue Jean Schinler, 22, 4140, Sprimont, Belgique)");
  }
  
}
