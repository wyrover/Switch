#include <Switch/System/Runtime/Serialization/SerializationInfo.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

class Role : public object, public System::Runtime::Serialization::ISerializable {
public:
  Role() {}
  Role(const Role& role) : roleName(role.roleName), flags(role.flags) {}
  Role& operator =(const Role& role ) {
    this->roleName = role.roleName;
    this->flags = role.flags;
    return *this;
  }
  
  _property<string> RoleName {
    _get->const string& {return this->roleName;},
    _set {this->roleName = value;}
  };
  
  _property<byte> Flags {
    _get {return this->flags;},
    _set {this->flags = value;}
  };
  
  virtual void GetObjectData(System::Runtime::Serialization::SerializationInfo& info) const {
    info.SetObjectType("Role");
    info.AddValue("RoleName", this->RoleName);
    info.AddValue("Flags", this->Flags);
  }

  static refptr<Role> Deserialize(const System::Runtime::Serialization::SerializationInfo& info) {    
    if (!info.GetObjectType().Equals("Role"))
      throw System::Runtime::Serialization::SerializationException(_current_information);

    refptr<Role> role = new Role();
    role->RoleName = info.GetString("RoleName");
    role->Flags = info.GetByte("Flags");
    return role;
  }

private:
  string roleName;
  byte flags = 0;
};

class Person : public object, public System::Runtime::Serialization::ISerializable {
public:
  virtual void GetObjectData(System::Runtime::Serialization::SerializationInfo& info) const {
    info.SetObjectType("Person");
    info.AddValue("PrsFirstName", this->FirstName);
    info.AddValue("PrsLastName", this->LastName);
    info.AddValue("PrsAge", this->Age);
    info.AddValue("PrsStrAge", this->StrAge);
    info.AddValue("PrsMale", this->Male);
    info.AddValue("PrsRole", this->Role, "Role");
  }

  static refptr<Person> Deserialize(const System::Runtime::Serialization::SerializationInfo& info) {
    if (!info.GetObjectType().Equals("Person"))
      throw System::Runtime::Serialization::SerializationException(_current_information);

    refptr<Person> person = new Person();

    person->FirstName = info.GetString("PrsFirstName");
    person->LastName = info.GetString("PrsLastName");
    person->Age = info.GetInt32("PrsAge");
    person->StrAge = info.GetString("PrsStrAge");
    person->Male = info.GetBoolean("PrsMale");
    person->Role = info.GetValue<::Role>("PrsRole").ToObject();

    return person;

  }

  string FirstName;
  string LastName;
  int32 Age;
  string StrAge;
  bool Male;
  ::Role Role;
};

TEST(SerializationInfo, Serialize) {
  Role role;
  role.RoleName = "Photographer";
  role.Flags = 0x22;

  Person person;
  person.Age = 42;
  person.StrAge = "42";
  person.FirstName = "Peter";
  person.LastName = "Parker";
  person.Male = true;
  person.Role = role;

  System::Runtime::Serialization::SerializationInfo info;

  person.GetObjectData(info);

  EXPECT_EQ("Person", info.GetObjectType());
  EXPECT_EQ(6, info.GetMemberCount());

  EXPECT_EQ("Peter", info.GetString("PrsFirstName"));
  EXPECT_EQ("Parker" , info.GetString("PrsLastName"));
  
  EXPECT_EQ(42, info.GetInt16("PrsAge"));
  EXPECT_EQ(42, info.GetInt32("PrsAge"));
  EXPECT_EQ(42, info.GetInt64("PrsAge"));
  EXPECT_EQ(42u, info.GetUInt16("PrsAge"));
  EXPECT_EQ(42u, info.GetUInt32("PrsAge"));
  EXPECT_EQ(42u, info.GetUInt64("PrsAge"));
  EXPECT_EQ(42, info.GetSingle("PrsAge"));
  EXPECT_EQ(42, info.GetDouble("PrsAge"));
  EXPECT_EQ("42", info.GetString("PrsAge"));

  EXPECT_EQ("42", info.GetString("PrsStrAge"));
  EXPECT_EQ(42, info.GetInt16("PrsStrAge"));
  EXPECT_EQ(42, info.GetInt32("PrsStrAge"));
  EXPECT_EQ(42, info.GetInt64("PrsStrAge"));
  EXPECT_EQ(42u, info.GetUInt16("PrsStrAge"));
  EXPECT_EQ(42u, info.GetUInt32("PrsStrAge"));
  EXPECT_EQ(42u, info.GetUInt64("PrsStrAge"));
  EXPECT_EQ(42, info.GetSingle("PrsStrAge"));
  EXPECT_EQ(42, info.GetDouble("PrsStrAge"));

  EXPECT_EQ(true, info.GetBoolean("PrsMale"));  

  EXPECT_THROW(info.GetObject("_Male"), ArgumentException);
  EXPECT_THROW(info.GetDouble("PrsRole"), System::Runtime::Serialization::SerializationException);
}

TEST(SerializationInfo, Deserialize) {
  Role role;
  role.RoleName = "Photographer";
  role.Flags = 0x22;

  Person person;
  person.Age = 42;
  person.StrAge = "42";
  person.FirstName = "Peter";
  person.LastName = "Parker";
  person.Male = true;
  person.Role = role;

  System::Runtime::Serialization::SerializationInfo serializationInfo;

  person.GetObjectData(serializationInfo);

  refptr<Person> newPerson = Person::Deserialize(serializationInfo);

  EXPECT_EQ(person.Age, newPerson->Age);
  EXPECT_EQ(person.StrAge, newPerson->StrAge);
  EXPECT_EQ(person.FirstName, newPerson->FirstName);
  EXPECT_EQ(person.LastName, newPerson->LastName);
  EXPECT_EQ(person.Male, newPerson->Male);
  EXPECT_EQ(person.Role.RoleName, newPerson->Role.RoleName);
  EXPECT_EQ(person.Role.Flags, newPerson->Role.Flags);
}
