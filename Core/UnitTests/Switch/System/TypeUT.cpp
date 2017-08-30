#include <Switch/System/Type.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  
  TEST(Type, Object) {
    Object obj;
    Type type = obj.GetType();
    //EXPECT_EQ("System::Object", type.FullName());
    //EXPECT_EQ("Object", type.Name());
    //EXPECT_EQ("System", type.Namespace());
  
    //EXPECT_TRUE(type == sw_typeof<Object>());
    //EXPECT_TRUE(type != sw_typeof<ValueType>());

    EXPECT_TRUE(type == Object().GetType());

    EXPECT_EQ(Type::GetTypeCode(obj), TypeCode::Object);
  
    EXPECT_TRUE(Type::IsInstanceOfType<Object>(obj));
    EXPECT_FALSE(Type::IsInstanceOfType<ValueType>(obj));
    EXPECT_FALSE(Type::IsInstanceOfType<IComparable>(obj));
    EXPECT_FALSE(Type::IsInstanceOfType<string>(obj));

    EXPECT_TRUE(is<Object>(obj));
    EXPECT_FALSE(is<ValueType>(obj));
    EXPECT_FALSE(is<IComparable>(obj));
    EXPECT_FALSE(is<string>(obj));
  
    EXPECT_FALSE(Type::IsComparable(obj));
    EXPECT_FALSE(Type::IsValueType(obj));
  }

  TEST(Type, Type) {
    Object obj;
    const Type type = obj.GetType();
  
    //EXPECT_EQ(type.GetType().GetFullName(), "System::Type");
    //EXPECT_EQ(type.GetType().GetName(), "Type");
    //EXPECT_EQ(type.GetType().GetNamespace(), "System");
    //EXPECT_EQ(type.GetType().ToString(), "System::Type");
  
    //EXPECT_TRUE(type.GetType() == sw_typeof<Type>());
    //EXPECT_TRUE(type.GetType() != sw_typeof<ValueType>());
  
    EXPECT_EQ(Type::GetTypeCode(obj), TypeCode::Object);
  
    EXPECT_TRUE(is<Object>(type));
    EXPECT_FALSE(is<ValueType>(type));
    EXPECT_TRUE(is<Type>(type));
    EXPECT_FALSE(is<IComparable>(type));
    EXPECT_FALSE(is<string>(type));
  
    EXPECT_TRUE(Type::IsInstanceOfType<Object>(type));
    EXPECT_FALSE(Type::IsInstanceOfType<ValueType>(type));
    EXPECT_TRUE(Type::IsInstanceOfType<Type>(type.GetType()));
    EXPECT_FALSE(Type::IsInstanceOfType<string>(type));
  
    EXPECT_FALSE(Type::IsComparable(type));
    EXPECT_FALSE(Type::IsValueType(type));
  
    EXPECT_TRUE(static_cast<const Object*>(&type) != null);
  }

  TEST(Type, Int32) {
    const Int32 i32 = 5;

    //EXPECT_EQ(string("System::Int32"), i32.GetType().GetFullName());
    //EXPECT_EQ(string("Int32"), i32.GetType().GetName());
    //EXPECT_EQ(string("System"), i32.GetType().GetNamespace());
    //EXPECT_EQ(string("System::Int32"), i32.GetType().ToString());
  
    //EXPECT_TRUE(i32.GetType() == sw_typeof<Int32>());
    //EXPECT_TRUE(i32.GetType() != sw_typeof<ValueType>());

    EXPECT_TRUE(i32.GetType() == Int32().GetType());

    EXPECT_EQ(Type::GetTypeCode(i32), TypeCode::Int32);
  
    EXPECT_TRUE(is<Object>(i32));
    EXPECT_TRUE(is<ValueType>(i32));
    EXPECT_TRUE(is<Int32>(i32));
    EXPECT_TRUE(is<IComparable>(i32));
    EXPECT_FALSE(is<string>(i32));
  
    EXPECT_TRUE(Type::IsInstanceOfType<Object>(i32));
    EXPECT_TRUE(Type::IsInstanceOfType<ValueType>(i32));
    EXPECT_TRUE(Type::IsInstanceOfType<Int32>(i32));
    EXPECT_TRUE(Type::IsInstanceOfType<IComparable>(i32));
    EXPECT_FALSE(Type::IsInstanceOfType<string>(i32));
  
    EXPECT_TRUE(Type::IsComparable(i32));
    EXPECT_TRUE(Type::IsValueType(i32));
  
    EXPECT_TRUE(static_cast<const Object*>(&i32) != null);
    EXPECT_TRUE(static_cast<const ValueType*>(&i32) != null);
  
    EXPECT_EQ(static_cast<const Object&>(i32).ToString(), "5");
    EXPECT_EQ(static_cast<const ValueType&>(i32).ToString(), "5");
    EXPECT_EQ(static_cast<const Int32&>(i32).ToString(), "5");
  }
}
