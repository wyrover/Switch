#include <Pcf/System/Tuple.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace {
  
  TEST(Tuple, 1) {
    Tuple<Int32> tuple1(512);
    Tuple<Int32> tuple2(24);
    EXPECT_EQ(tuple1.Item1(), 512);
    EXPECT_EQ(tuple1.ToString(), "(512)");
    EXPECT_FALSE(tuple1.Equals(tuple2));
    EXPECT_GT(tuple1.CompareTo(tuple2), 0);
  }
  
  TEST(Tuple, 2) {
    Tuple<Int32, string> tuple1(Int32(2), string("Cats"));
    Tuple<Int32, string> tuple2(Int32(2), string("Dogs"));
    EXPECT_EQ(tuple1.Item1(), 2);
    EXPECT_EQ(tuple1.Item2(), "Cats");
    EXPECT_EQ(tuple1.ToString(), "(2, Cats)");
    EXPECT_FALSE(tuple1.Equals(tuple2));
    EXPECT_LT(tuple1.CompareTo(tuple2), 0);
  }
  
  TEST(Tuple, 3) {
    Tuple<uint32, string, string> tuple1(2, "Cats", "Color [Brown]");
    Tuple<uint32, string, string> tuple2(2, "Cats", "Color [Black]");
    EXPECT_EQ(tuple1.Item1(), 2u);
    EXPECT_EQ(tuple1.Item2(), "Cats");
    EXPECT_EQ(tuple1.Item3(), "Color [Brown]");
    EXPECT_EQ(tuple1.ToString(), "(2, Cats, Color [Brown])");
    EXPECT_FALSE(tuple1.Equals(tuple2));
    EXPECT_FALSE(tuple1.CompareTo(tuple2) == 0);
  }
  
  TEST(Tuple, 4) {
    Tuple<string, string, Int32, Boolean> tuple1("Yves", "Fiumefreddo", 41, true);
    Tuple<string, string, Int32, Boolean> tuple2("Julien", "Vilz", 35, true);
    EXPECT_EQ(tuple1.Item1(), "Yves");
    EXPECT_EQ(tuple1.Item2(), "Fiumefreddo");
    EXPECT_EQ(tuple1.Item3(), 41);
    EXPECT_EQ(tuple1.Item4(), true);
    EXPECT_EQ(tuple1.ToString(), "(Yves, Fiumefreddo, 41, True)");
    EXPECT_FALSE(tuple1.Equals(tuple2));
    EXPECT_GT(tuple1.CompareTo(tuple2), 0);
  }
  
  TEST(Tuple, 5) {
    Tuple<string, string, Int32, Boolean, string> tuple1("Yves", "Fiumefreddo", 41, true, "Rue Francisco Ferrer");
    Tuple<string, string, Int32, Boolean, string> tuple2("Julien", "Vilz", 35, true, "Dans une grange restaurée");
    EXPECT_EQ(tuple1.Item1(), "Yves");
    EXPECT_EQ(tuple1.Item2(), "Fiumefreddo");
    EXPECT_EQ(tuple1.Item3(), 41);
    EXPECT_EQ(tuple1.Item4(), true);
    EXPECT_EQ(tuple1.Item5(), "Rue Francisco Ferrer");
    EXPECT_EQ(tuple1.ToString(), "(Yves, Fiumefreddo, 41, True, Rue Francisco Ferrer)");
    EXPECT_FALSE(tuple1.Equals(tuple2));
    EXPECT_GT(tuple1.CompareTo(tuple2), 0);
  }
  
  TEST(Tuple, 6) {
    Tuple<string, string, Int32, Boolean, string, Int32> tuple1("Yves", "Fiumefreddo", 41, true, "Rue Francisco Ferrer", 4);
    Tuple<string, string, Int32, Boolean, string, Int32> tuple2("Julien", "Vilz", 35, true, "Rue du Bois St Jean", 16);
    EXPECT_EQ(tuple1.Item1(), "Yves");
    EXPECT_EQ(tuple1.Item2(), "Fiumefreddo");
    EXPECT_EQ(tuple1.Item3(), 41);
    EXPECT_EQ(tuple1.Item4(), true);
    EXPECT_EQ(tuple1.Item5(), "Rue Francisco Ferrer");
    EXPECT_EQ(tuple1.Item6(), 4);
    EXPECT_EQ(tuple1.ToString(), "(Yves, Fiumefreddo, 41, True, Rue Francisco Ferrer, 4)");
    EXPECT_FALSE(tuple1.Equals(tuple2));
    EXPECT_GT(tuple1.CompareTo(tuple2), 0);
  }
  
  TEST(Tuple, 7) {
    Tuple<string, string, Int32, Boolean, string, Int32, Int32> tuple1("Yves", "Fiumefreddo", 41, true, "Rue Francisco Ferrer", 4, 4460);
    Tuple<string, string, Int32, Boolean, string, Int32, Int32> tuple2("Julien", "Vilz", 35, true, "Rue du Bois St Jean", 16, 4100);
    EXPECT_EQ(tuple1.Item1(), "Yves");
    EXPECT_EQ(tuple1.Item2(), "Fiumefreddo");
    EXPECT_EQ(tuple1.Item3(), 41);
    EXPECT_EQ(tuple1.Item4(), true);
    EXPECT_EQ(tuple1.Item5(), "Rue Francisco Ferrer");
    EXPECT_EQ(tuple1.Item6(), 4);
    EXPECT_EQ(tuple1.Item7(), 4460);
    EXPECT_EQ(tuple1.ToString(), "(Yves, Fiumefreddo, 41, True, Rue Francisco Ferrer, 4, 4460)");
    EXPECT_FALSE(tuple1.Equals(tuple2));
    EXPECT_GT(tuple1.CompareTo(tuple2), 0);
  }
  
  TEST(Tuple, Rest) {
    Tuple<string, string, Int32, Boolean, string, Int32, Int32, Tuple<string, string>> tuple1(
                                                                                              "Yves", "Fiumefreddo", 41, true, "Rue Francisco Ferrer", 4, 4460,
                                                                                              Tuple<string, string>("Grace-Hollogne", "Belgique"));
    Tuple<string, string, Int32, Boolean, string, Int32, Int32, Tuple<string, string>> tuple2(
                                                                                              "Julien", "Vilz", 35, true, "Rue du Bois St Jean", 16, 4100,
                                                                                              Tuple<string, string>("Ougrée", "Belgique"));
    EXPECT_EQ(tuple1.Item1(), "Yves");
    EXPECT_EQ(tuple1.Item2(), "Fiumefreddo");
    EXPECT_EQ(tuple1.Item3(), 41);
    EXPECT_EQ(tuple1.Item4(), true);
    EXPECT_EQ(tuple1.Item5(), "Rue Francisco Ferrer");
    EXPECT_EQ(tuple1.Item6(), 4);
    EXPECT_EQ(tuple1.Item7(), 4460);
    EXPECT_EQ(tuple1.Rest().Item1(), "Grace-Hollogne");
    EXPECT_EQ(tuple1.Rest().Item2(), "Belgique");
    EXPECT_EQ(tuple1.ToString(), "(Yves, Fiumefreddo, 41, True, Rue Francisco Ferrer, 4, 4460, Grace-Hollogne, Belgique)");
    EXPECT_FALSE(tuple1.Equals(tuple2));
    EXPECT_GT(tuple1.CompareTo(tuple2), 0);
  }
  
  TEST(Tuple, Array) {
    Tuple<string, string, Int32, Boolean> tuple1("Yves", "Fiumefreddo", 41, true);
    Tuple<string, string, Int32, Boolean> tuple2("Julien", "Vilz", 35, true);
    Array<Tuple<string, string, Int32, Boolean>> tupleArray(2);
    tupleArray[0]=tuple1;
    tupleArray[1]=tuple2;
    EXPECT_TRUE(tupleArray[0].Equals(tuple1));
    EXPECT_TRUE(tupleArray[1].Equals(tuple2));
  }
  
  TEST(Tuple, NativeTuple) {
    Tuple<int32, char> tuple1(Int32(2), 'C');
    Tuple<int32, char> tuple2(Int32(2), 'D');
    EXPECT_EQ(tuple1.Item1(), 2);
    EXPECT_EQ(tuple1.Item2(), 'C');
    EXPECT_EQ(tuple1.ToString(), "(2, C)");
    EXPECT_FALSE(tuple1.Equals(tuple2));
    EXPECT_LT(tuple1.CompareTo(tuple2), 0);
  }
  
  TEST(Tuple, SharedPointerTuple) {
    SharedPointer<String> s1 = new String("Item1");
    SharedPointer<Int32> s2 = new Int32(2);
    SharedPointer<String> s3 = new String("Item3");
    Tuple<SharedPointer<String>, SharedPointer<Int32>> tuple1(s1, s2);
    Tuple<SharedPointer<Int32>, SharedPointer<String>> tuple2(s2, s3);
    EXPECT_EQ(tuple1.Item1(), s1);
    EXPECT_EQ(tuple1.Item2(), s2);
    EXPECT_FALSE(tuple1.Equals(tuple2));
    EXPECT_NE(tuple1.CompareTo(tuple2), 0);
  }
  
  TEST(Tuple, MyTuple) {
    using MyTuple = Tuple<Int32, string>;
    
    MyTuple my_1(Int32(2), string("Cats"));
    MyTuple myTuple2(Int32(2), string("Dogs"));
    EXPECT_EQ(my_1.Item1(), 2);
    EXPECT_EQ(my_1.Item2(), "Cats");
    EXPECT_EQ(my_1.ToString(), "(2, Cats)");
    EXPECT_FALSE(my_1.Equals(myTuple2));
    EXPECT_LT(my_1.CompareTo(myTuple2), 0);
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
    Tuple1<Int32> tuple2(24);
    EXPECT_EQ(tuple1.Item1(), 512);
    EXPECT_EQ(tuple1.ToString(), "(512)");
    EXPECT_FALSE(tuple1.Equals(tuple2));
    EXPECT_GT(tuple1.CompareTo(tuple2), 0);
  }
  
  TEST(Tuple, My2) {
    Tuple2<Int32, string> my_1(Int32(2), string("Cats"));
    Tuple2<Int32, string> myTuple2(Int32(2), string("Dogs"));
    EXPECT_EQ(my_1.Item1(), 2);
    EXPECT_EQ(my_1.Item2(), "Cats");
    EXPECT_EQ(my_1.ToString(), "(2, Cats)");
    EXPECT_FALSE(my_1.Equals(myTuple2));
    EXPECT_LT(my_1.CompareTo(myTuple2), 0);
  }
  
  TEST(Tuple, My3) {
    Tuple3<uint32, string, string> tuple1(2, "Cats", "Color [Brown]");
    Tuple3<uint32, string, string> tuple2(2, "Cats", "Color [Black]");
    EXPECT_EQ(tuple1.Item1(), 2u);
    EXPECT_EQ(tuple1.Item2(), "Cats");
    EXPECT_EQ(tuple1.Item3(), "Color [Brown]");
    EXPECT_EQ(tuple1.ToString(), "(2, Cats, Color [Brown])");
    EXPECT_FALSE(tuple1.Equals(tuple2));
    EXPECT_FALSE(tuple1.CompareTo(tuple2) == 0);
  }
  
  TEST(Tuple, My4) {
    Tuple4<string, string, Int32, Boolean> tuple1("Yves", "Fiumefreddo", 41, true);
    Tuple4<string, string, Int32, Boolean> tuple2("Julien", "Vilz", 35, true);
    EXPECT_EQ(tuple1.Item1(), "Yves");
    EXPECT_EQ(tuple1.Item2(), "Fiumefreddo");
    EXPECT_EQ(tuple1.Item3(), 41);
    EXPECT_EQ(tuple1.Item4(), true);
    EXPECT_EQ(tuple1.ToString(), "(Yves, Fiumefreddo, 41, True)");
    EXPECT_FALSE(tuple1.Equals(tuple2));
    EXPECT_GT(tuple1.CompareTo(tuple2), 0);
  }
  
  TEST(Tuple, My5) {
    Tuple5<string, string, Int32, Boolean, string> tuple1("Yves", "Fiumefreddo", 41, true, "Rue Francisco Ferrer");
    Tuple5<string, string, Int32, Boolean, string> tuple2("Julien", "Vilz", 35, true, "Dans une grange restaurée");
    EXPECT_EQ(tuple1.Item1(), "Yves");
    EXPECT_EQ(tuple1.Item2(), "Fiumefreddo");
    EXPECT_EQ(tuple1.Item3(), 41);
    EXPECT_EQ(tuple1.Item4(), true);
    EXPECT_EQ(tuple1.Item5(), "Rue Francisco Ferrer");
    EXPECT_EQ(tuple1.ToString(), "(Yves, Fiumefreddo, 41, True, Rue Francisco Ferrer)");
    EXPECT_FALSE(tuple1.Equals(tuple2));
    EXPECT_GT(tuple1.CompareTo(tuple2), 0);
  }
  
  TEST(Tuple, My6) {
    Tuple6<string, string, Int32, Boolean, string, Int32> tuple1("Yves", "Fiumefreddo", 41, true, "Rue Francisco Ferrer", 4);
    Tuple6<string, string, Int32, Boolean, string, Int32> tuple2("Julien", "Vilz", 35, true, "Rue du Bois St Jean", 16);
    EXPECT_EQ(tuple1.Item1(), "Yves");
    EXPECT_EQ(tuple1.Item2(), "Fiumefreddo");
    EXPECT_EQ(tuple1.Item3(), 41);
    EXPECT_EQ(tuple1.Item4(), true);
    EXPECT_EQ(tuple1.Item5(), "Rue Francisco Ferrer");
    EXPECT_EQ(tuple1.Item6(), 4);
    EXPECT_EQ(tuple1.ToString(), "(Yves, Fiumefreddo, 41, True, Rue Francisco Ferrer, 4)");
    EXPECT_FALSE(tuple1.Equals(tuple2));
    EXPECT_GT(tuple1.CompareTo(tuple2), 0);
  }
  
  TEST(Tuple, My7) {
    Tuple7<string, string, Int32, Boolean, string, Int32, Int32> tuple1("Yves", "Fiumefreddo", 41, true, "Rue Francisco Ferrer", 4, 4460);
    Tuple7<string, string, Int32, Boolean, string, Int32, Int32> tuple2("Julien", "Vilz", 35, true, "Rue du Bois St Jean", 16, 4100);
    EXPECT_EQ(tuple1.Item1(), "Yves");
    EXPECT_EQ(tuple1.Item2(), "Fiumefreddo");
    EXPECT_EQ(tuple1.Item3(), 41);
    EXPECT_EQ(tuple1.Item4(), true);
    EXPECT_EQ(tuple1.Item5(), "Rue Francisco Ferrer");
    EXPECT_EQ(tuple1.Item6(), 4);
    EXPECT_EQ(tuple1.Item7(), 4460);
    EXPECT_EQ(tuple1.ToString(), "(Yves, Fiumefreddo, 41, True, Rue Francisco Ferrer, 4, 4460)");
    EXPECT_FALSE(tuple1.Equals(tuple2));
    EXPECT_GT(tuple1.CompareTo(tuple2), 0);
  }
  
  TEST(Tuple, MyRest) {
    TupleRest<string, string, Int32, Boolean, string, Int32, Int32, Tuple<string, string>> tuple1(
                                                                                                  "Yves", "Fiumefreddo", 41, true, "Rue Francisco Ferrer", 4, 4460,
                                                                                                  Tuple<string, string>("Grace-Hollogne", "Belgique"));
    TupleRest<string, string, Int32, Boolean, string, Int32, Int32, Tuple<string, string>> tuple2(
                                                                                                  "Julien", "Vilz", 35, true, "Rue du Bois St Jean", 16, 4100,
                                                                                                  Tuple<string, string>("Ougrée", "Belgique"));
    EXPECT_EQ(tuple1.Item1(), "Yves");
    EXPECT_EQ(tuple1.Item2(), "Fiumefreddo");
    EXPECT_EQ(tuple1.Item3(), 41);
    EXPECT_EQ(tuple1.Item4(), true);
    EXPECT_EQ(tuple1.Item5(), "Rue Francisco Ferrer");
    EXPECT_EQ(tuple1.Item6(), 4);
    EXPECT_EQ(tuple1.Item7(), 4460);
    EXPECT_EQ(tuple1.Rest().Item1(), "Grace-Hollogne");
    EXPECT_EQ(tuple1.Rest().Item2(), "Belgique");
    EXPECT_EQ(tuple1.ToString(), "(Yves, Fiumefreddo, 41, True, Rue Francisco Ferrer, 4, 4460, Grace-Hollogne, Belgique)");
    EXPECT_FALSE(tuple1.Equals(tuple2));
    EXPECT_GT(tuple1.CompareTo(tuple2), 0);
  }
  
}
