#include <Pcf/System/Collections/Generic/List.h>
#include <Pcf/System/Threading/Thread.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Threading;
using namespace TUnit;

namespace {
  class Dinosaur : public object {
  public:
    Dinosaur(const string& name, const int32& numberOfLegsUsedToWalk) : name(name), numberOfLegsUsedToWalk(numberOfLegsUsedToWalk) {}

    Dinosaur(const Dinosaur& d) {*this = d;}

    Dinosaur& operator =(const Dinosaur& d) {
      name = d.name;
      numberOfLegsUsedToWalk = d.numberOfLegsUsedToWalk;
      return *this;
    }

    string ToString() const { return name; }
    const string& GetName() const { return name; }
    int32 GetNbLegs() const { return numberOfLegsUsedToWalk; }
    
  private:
    string name;
    Int32  numberOfLegsUsedToWalk;
  };

  struct DinosaurTest : public object {
  public:
    explicit DinosaurTest(int32 size) {names.Resize(size);}

    List<Dinosaur> list;
    sp<System::Collections::Generic::IComparer<Dinosaur>> comparer;
    System::Array<string> names;
  };
  
  class DinosaurComparer : public System::Collections::Generic::IComparer<Dinosaur> {
  public:
    DinosaurComparer(){}
    ~DinosaurComparer() {}

    virtual int32 Compare(const Dinosaur& d1, const Dinosaur& d2) const {
      Thread::Sleep(1);
      return d1.GetName().CompareTo(d2.GetName());
    }
  };

  class DinosaurComparerByLegs : public System::Collections::Generic::IComparer<Dinosaur> {
  public:
    DinosaurComparerByLegs() {}
    
    virtual int32 Compare(const Dinosaur& d1, const Dinosaur& d2) const {
      Thread::Sleep(1);
      int32 r = Int32(d1.GetNbLegs()).CompareTo(d2.GetNbLegs());
      if (r != 0) return r;
      return d1.GetName().CompareTo(d2.GetName());
    }
  };

  static void ThreadSort(const Object& obj) {
    DinosaurTest test = as<DinosaurTest>(obj);
    test.list.Sort(*test.comparer);
    int k = 0;
    for (Dinosaur d : test.list)
      EXPECT_TRUE(d.GetName().Equals(test.names[k++]));
  }

TEST(List, Sort) {
  sp<DinosaurTest> test1 = new DinosaurTest(9);
  sp<DinosaurTest> test2 = new DinosaurTest(9);

  test1->names[0] = "Amargasaurus";
  test1->names[1] = "Compsognathus";
  test1->names[2] = "Deinonychus";
  test1->names[3] = "Dilophosaurus";
  test1->names[4] = "Gallimimus";
  test1->names[5] = "Oviraptor";
  test1->names[6] = "Triceratops";
  test1->names[7] = "Tyrannosaurus";
  test1->names[8] = "Velociraptor";
  
  test2->names[0] = "Compsognathus";
  test2->names[1] = "Deinonychus";
  test2->names[2] = "Dilophosaurus";
  test2->names[3] = "Gallimimus";
  test2->names[4] = "Oviraptor";
  test2->names[5] = "Tyrannosaurus";
  test2->names[6] = "Velociraptor";
  test2->names[7] = "Amargasaurus";
  test2->names[8] = "Triceratops";
  
  // Add 6 items
  test1->list.Add(Dinosaur("Tyrannosaurus",2));
  test1->list.Add(Dinosaur("Compsognathus",2));
  test1->list.Add(Dinosaur("Amargasaurus",4));
  test1->list.Add(Dinosaur("Oviraptor",2));
  test1->list.Add(Dinosaur("Velociraptor",2));
  test1->list.Add(Dinosaur("Deinonychus",2));
  test1->list.Add(Dinosaur("Dilophosaurus",2));
  test1->list.Add(Dinosaur("Gallimimus",2));
  test1->list.Add(Dinosaur("Triceratops",4));
   
  for (Dinosaur d : test1->list)
    test2->list.Add(d);

  test1->comparer = sp<System::Collections::Generic::IComparer<Dinosaur>>::Create<DinosaurComparer>();
  test2->comparer = sp<System::Collections::Generic::IComparer<Dinosaur>>::Create<DinosaurComparerByLegs>();

  sp<Thread> thread1 = new Thread((ParameterizedThreadStart)&ThreadSort);
  sp<Thread> thread2 = new Thread((ParameterizedThreadStart)&ThreadSort);
  
  thread1->Start(*test1);
  Thread::Sleep(2);
  thread2->Start(*test2);

  thread1->Join();
  thread2->Join();
}

}
