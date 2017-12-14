#include <Switch/System/Type.hpp>
#include <Switch/System/Int32.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  TEST(TypeTest, Object) {
    Object obj;
    Type type = obj.GetType();
    //ASSERT_EQ("System::Object", type.FullName());
    //ASSERT_EQ("Object", type.Name());
    //ASSERT_EQ("System", type.Namespace());

    //ASSERT_TRUE(type == _typeof<Object>());
    //ASSERT_TRUE(type != _typeof<ValueType>());

    ASSERT_TRUE(type == Object().GetType());

    ASSERT_EQ(Type::GetTypeCode(obj), TypeCode::Object);

    ASSERT_TRUE(Type::IsInstanceOfType<Object>(obj));
    ASSERT_FALSE(Type::IsInstanceOfType<ValueType>(obj));
    ASSERT_FALSE(Type::IsInstanceOfType<IComparable>(obj));
    ASSERT_FALSE(Type::IsInstanceOfType<string>(obj));

    ASSERT_TRUE(is<Object>(obj));
    ASSERT_FALSE(is<ValueType>(obj));
    ASSERT_FALSE(is<IComparable>(obj));
    ASSERT_FALSE(is<string>(obj));

    ASSERT_FALSE(Type::IsComparable(obj));
    ASSERT_FALSE(Type::IsValueType(obj));
  }

  TEST(TypeTest, Type) {
    Object obj;
    const Type type = obj.GetType();

    //ASSERT_EQ(type.GetType().GetFullName(), "System::Type");
    //ASSERT_EQ(type.GetType().GetName(), "Type");
    //ASSERT_EQ(type.GetType().GetNamespace(), "System");
    //ASSERT_EQ(type.GetType().ToString(), "System::Type");

    //ASSERT_TRUE(type.GetType() == _typeof<Type>());
    //ASSERT_TRUE(type.GetType() != _typeof<ValueType>());

    ASSERT_EQ(Type::GetTypeCode(obj), TypeCode::Object);

    ASSERT_TRUE(is<Object>(type));
    ASSERT_FALSE(is<ValueType>(type));
    ASSERT_TRUE(is<Type>(type));
    ASSERT_FALSE(is<IComparable>(type));
    ASSERT_FALSE(is<string>(type));

    ASSERT_TRUE(Type::IsInstanceOfType<Object>(type));
    ASSERT_FALSE(Type::IsInstanceOfType<ValueType>(type));
    ASSERT_TRUE(Type::IsInstanceOfType<Type>(type.GetType()));
    ASSERT_FALSE(Type::IsInstanceOfType<string>(type));

    ASSERT_FALSE(Type::IsComparable(type));
    ASSERT_FALSE(Type::IsValueType(type));

    ASSERT_TRUE(static_cast<const Object*>(&type) != null);
  }

  TEST(TypeTest, Int32) {
    const Int32 i32 = 5;

    //ASSERT_EQ(string("System::Int32"), i32.GetType().GetFullName());
    //ASSERT_EQ(string("Int32"), i32.GetType().GetName());
    //ASSERT_EQ(string("System"), i32.GetType().GetNamespace());
    //ASSERT_EQ(string("System::Int32"), i32.GetType().ToString());

    //ASSERT_TRUE(i32.GetType() == _typeof<Int32>());
    //ASSERT_TRUE(i32.GetType() != _typeof<ValueType>());

    ASSERT_TRUE(i32.GetType() == Int32().GetType());

    ASSERT_EQ(Type::GetTypeCode(i32), TypeCode::Int32);

    ASSERT_TRUE(is<Object>(i32));
    ASSERT_TRUE(is<ValueType>(i32));
    ASSERT_TRUE(is<Int32>(i32));
    ASSERT_TRUE(is<IComparable>(i32));
    ASSERT_FALSE(is<string>(i32));

    ASSERT_TRUE(Type::IsInstanceOfType<Object>(i32));
    ASSERT_TRUE(Type::IsInstanceOfType<ValueType>(i32));
    ASSERT_TRUE(Type::IsInstanceOfType<Int32>(i32));
    ASSERT_TRUE(Type::IsInstanceOfType<IComparable>(i32));
    ASSERT_FALSE(Type::IsInstanceOfType<string>(i32));

    ASSERT_TRUE(Type::IsComparable(i32));
    ASSERT_TRUE(Type::IsValueType(i32));

    ASSERT_TRUE(static_cast<const Object*>(&i32) != null);
    ASSERT_TRUE(static_cast<const ValueType*>(&i32) != null);

    ASSERT_EQ(static_cast<const Object&>(i32).ToString(), "5");
    ASSERT_EQ(static_cast<const ValueType&>(i32).ToString(), "5");
    ASSERT_EQ(static_cast<const Int32&>(i32).ToString(), "5");
  }
}
