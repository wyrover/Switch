#include <Pcf/System/Collections/Generic/List.h>
#include <Pcf/System/Collections/ObjectModel/ReadOnlyCollection.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace TUnit;

namespace {
  TEST(ReadOnlyCollection, ReadOnlyCollectionLastIndexOf) {
    List<string> dinosaurs;
  
    // Add 9 items
    dinosaurs.Add("Dilophosaurus"); // 0
    dinosaurs.Add("Compsognathus"); // 1
    dinosaurs.Add("Dilophosaurus"); // 2
    dinosaurs.Add("Oviraptor");     // 3
    dinosaurs.Add("Velociraptor");  // 4
    dinosaurs.Add("Deinonychus");   // 5
    dinosaurs.Add("Dilophosaurus"); // 6
    dinosaurs.Add("Gallimimus");    // 7
    dinosaurs.Add("Triceratops");   // 8

    Collections::ObjectModel::ReadOnlyCollection<string> read_only(dinosaurs);
    Collections::ObjectModel::ReadOnlyCollection<string> read_only2(dinosaurs);
  
    EXPECT_EQ(read_only.LastIndexOf("Dilophosaurus"), 6);
    EXPECT_EQ(read_only.LastIndexOf("Hello Kitty"), -1);

    EXPECT_EQ(read_only.LastIndexOf("Dilophosaurus", 0), 0);
    EXPECT_EQ(read_only.LastIndexOf("Dilophosaurus", 2), 2);
    EXPECT_EQ(read_only.LastIndexOf("Dilophosaurus", 3), 2);
    EXPECT_EQ(read_only.LastIndexOf("Dilophosaurus", 7), 6);
    EXPECT_THROW(read_only.LastIndexOf("Dilophosaurus", 9), ArgumentOutOfRangeException);

    EXPECT_EQ(read_only.LastIndexOf("Dilophosaurus", 5, 3), -1);
    EXPECT_EQ(read_only.LastIndexOf("Dilophosaurus", 8, 6), 6);
    EXPECT_EQ(read_only.LastIndexOf("Dilophosaurus", 2, 3), 2);
    EXPECT_EQ(read_only.LastIndexOf("Dilophosaurus", 2, 0), -1);
    EXPECT_EQ(read_only.LastIndexOf("Dilophosaurus", 2, 1), 2);
    EXPECT_THROW(read_only.LastIndexOf("Dilophosaurus", 2,4), ArgumentException);
    EXPECT_THROW(read_only.LastIndexOf("Dilophosaurus", 9,2), ArgumentOutOfRangeException);
  
    EXPECT_THROW(read_only.LastIndexOf("Dilophosaurus", 0, -1), ArgumentOutOfRangeException);
  
    EXPECT_THROW(read_only.LastIndexOf("Dilophosaurus", 10, 1), ArgumentOutOfRangeException);
    EXPECT_THROW(read_only.LastIndexOf("Dilophosaurus", 0, 10), ArgumentException);
  
    EXPECT_THROW(read_only[0] = "change", NotSupportedException);
    EXPECT_THROW(read_only = read_only2, NotSupportedException);
  }
}