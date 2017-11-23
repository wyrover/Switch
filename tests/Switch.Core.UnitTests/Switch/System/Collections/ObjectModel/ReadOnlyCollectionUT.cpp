#include <Switch/System/Collections/Generic/List.hpp>
#include <Switch/System/Collections/ObjectModel/ReadOnlyCollection.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

namespace {
  TEST(ReadOnlyCollectionTest, ReadOnlyCollectionLastIndexOf) {
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
    
    ASSERT_EQ(read_only.LastIndexOf("Dilophosaurus"), 6);
    ASSERT_EQ(read_only.LastIndexOf("Hello Kitty"), -1);
    
    ASSERT_EQ(read_only.LastIndexOf("Dilophosaurus", 0), 0);
    ASSERT_EQ(read_only.LastIndexOf("Dilophosaurus", 2), 2);
    ASSERT_EQ(read_only.LastIndexOf("Dilophosaurus", 3), 2);
    ASSERT_EQ(read_only.LastIndexOf("Dilophosaurus", 7), 6);
    ASSERT_THROW(read_only.LastIndexOf("Dilophosaurus", 9), ArgumentOutOfRangeException);
    
    ASSERT_EQ(read_only.LastIndexOf("Dilophosaurus", 5, 3), -1);
    ASSERT_EQ(read_only.LastIndexOf("Dilophosaurus", 8, 6), 6);
    ASSERT_EQ(read_only.LastIndexOf("Dilophosaurus", 2, 3), 2);
    ASSERT_EQ(read_only.LastIndexOf("Dilophosaurus", 2, 0), -1);
    ASSERT_EQ(read_only.LastIndexOf("Dilophosaurus", 2, 1), 2);
    ASSERT_THROW(read_only.LastIndexOf("Dilophosaurus", 2, 4), ArgumentException);
    ASSERT_THROW(read_only.LastIndexOf("Dilophosaurus", 9, 2), ArgumentOutOfRangeException);
    
    ASSERT_THROW(read_only.LastIndexOf("Dilophosaurus", 0, -1), ArgumentOutOfRangeException);
    
    ASSERT_THROW(read_only.LastIndexOf("Dilophosaurus", 10, 1), ArgumentOutOfRangeException);
    ASSERT_THROW(read_only.LastIndexOf("Dilophosaurus", 0, 10), ArgumentException);
    
    ASSERT_THROW(read_only[0] = "change", NotSupportedException);
    ASSERT_THROW(read_only = read_only2, NotSupportedException);
  }
}
