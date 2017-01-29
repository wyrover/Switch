#include <Pcf/System/Runtime/Serialization.h>
#include <Pcf/System/IO/StreamReader.h>
#include <Pcf/System/IO/StreamWriter.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

class Role : public object, public System::Runtime::Serialization::ISerializable {
public:
  virtual void GetObjectData(System::Runtime::Serialization::SerializationInfo& info) const {
    info.AddValue("RoleName", this->RoleName);
    info.AddValue("Flags", this->Flags);
  }

  static sp<Role> Deserialize(const System::Runtime::Serialization::SerializationInfo& info) {
    sp<Role> role = new Role();
    role->RoleName = info.GetString("RoleName");
    role->Flags = info.GetByte("Flags");
    return role;
  }

  string RoleName;
  byte Flags;
};


class Person : public object, public System::Runtime::Serialization::ISerializable {
public:
  virtual void GetObjectData(System::Runtime::Serialization::SerializationInfo& info) const {
    info.AddValue("PrsFirstName", this->FirstName);
    info.AddValue("PrsLastName", this->LastName);
    info.AddValue("PrsAge", this->Age);
    info.AddValue("PrsMale", this->Male);
    info.AddValue("PrsRole", this->Role);
  }
  
  static sp<Person> Deserialize(const System::Runtime::Serialization::SerializationInfo& info) {
    sp<Person> person = new Person();

    person->FirstName = info.GetString("PrsFirstName");
    person->LastName = info.GetString("PrsLastName");
    person->Age = info.GetInt32("PrsAge");
    person->Male = info.GetBoolean("PrsMale");
    person->Role = info.GetValue<::Role>("PrsRole").ToObject();

    return person;
  }

  string FirstName;
  string LastName;
  int32 Age;
  bool Male;
  ::Role Role;
};

class TestSerializer : public System::Runtime::Serialization::IFormatter {
public:
  void Deserialize(const sp<System::IO::Stream>& serializationStream, System::Runtime::Serialization::ISerializable& graph) override {
    System::Runtime::Serialization::SerializationInfo serializationInfo;
    as<System::Runtime::Serialization::ISerializable>(graph).GetObjectData(serializationInfo);
    IO::StreamReader SerializeStreamReader(*serializationStream);
    while (!SerializeStreamReader.EndOfStream()) {
      string line = SerializeStreamReader.ReadLine();
      string key = line.Remove(line.IndexOf('='));
      string value = line.Substring(line.IndexOf('=')+1);
    }
  }

  using IFormatter::Deserialize;
  
  void Serialize(const sp<System::IO::Stream>& serializationStream, const Object& graph) override {
    System::Runtime::Serialization::SerializationInfo serializationInfo;
    as<System::Runtime::Serialization::ISerializable>(graph).GetObjectData(serializationInfo);
    IO::StreamWriter SerializeStreamWriter(*serializationStream);
    
    System::Collections::Generic::Enumerator<System::Collections::Generic::KeyValuePair<string, System::Runtime::Serialization::SerializationEntry >> enumerator = serializationInfo.GetEnumerator();
    while (enumerator.MoveNext())
      SerializeStreamWriter.WriteLine(String::Format("{0}()={1}", enumerator.Current().Key(), enumerator.Current().Value().Value().ToObject()));
  }
};

TEST(Serialization, Serialize) {
  Role role;
  role.RoleName = "Architect";
  role.Flags = 0x22;

  Person person;
  person.Age = 42;
  person.FirstName = "Yves";
  person.LastName = "Fiumefreddo";
  person.Male = true;
  person.Role = role;

  System::Runtime::Serialization::SerializationInfo serializationInfo;

  person.GetObjectData(serializationInfo);

  sp<Person> newPerson = Person::Deserialize(serializationInfo);

  EXPECT_EQ(person.Age, newPerson->Age);
  EXPECT_EQ(person.Role.Flags, newPerson->Role.Flags);
}

