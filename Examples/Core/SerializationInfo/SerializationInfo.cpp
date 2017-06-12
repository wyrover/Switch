#include <Pcf/Pcf>

using namespace System;

namespace Pcf {
  namespace System {
    namespace Runtime {
      namespace Serialization {
        namespace Json {
          class JSonSerializer : public System::Runtime::Serialization::IFormatter {
          public:
            void Deserialize(const refptr<System::IO::Stream>& serializationStream, System::Runtime::Serialization::ISerializable& graph) override {
              System::Runtime::Serialization::SerializationInfo serializationInfo;
              as<System::Runtime::Serialization::ISerializable>(graph).GetObjectData(serializationInfo);
              string json = IO::StreamReader(serializationStream).ReadToEnd();
              json = json.Substring(json.IndexOf('{')+1);
              json = json.Remove(json.LastIndexOf('}'));
              Array<char32> unusedChar = {' ', '\n', '\r', '\t'};
              json.TrimStart(unusedChar);
              json.TrimEnd(unusedChar);
              string keyValue = json.Remove(IndexOfEndKeyValue(json));
              json = json.Substring(IndexOfEndKeyValue(json)+1);
              
              //Console::WriteLine(json);
            }
            
            using IFormatter::Deserialize;
            
            void Serialize(const refptr<System::IO::Stream>& serializationStream, const Object& graph) override {
              System::Runtime::Serialization::SerializationInfo serializationInfo;
              as<System::Runtime::Serialization::ISerializable>(graph).GetObjectData(serializationInfo);
              this->writer = pcf_new<IO::StreamWriter>(serializationStream);
              Serialize(serializationInfo);
              this->writer->WriteLine();
            }
            
          private:
            int32 IndexOfEndKeyValue(const string& json) {
              //int32 count
              return 0;
            }
            
            void Serialize(const System::Runtime::Serialization::SerializationInfo& graph) {
              string tailing;
              writer->Write("{");
              for (System::Collections::Generic::KeyValuePair<string, System::Runtime::Serialization::SerializationEntry> item : graph) {
                writer->Write(tailing);
                tailing = ",";
                if (is<System::Runtime::Serialization::SerializationInfo>(item.Value().Value())) {
                  writer->Write("\"{0}\":", item.Key());
                  Serialize(as<System::Runtime::Serialization::SerializationInfo>(item.Value().Value()).ToObject());
                } else if (is<System::Array<string>>(item.Value().Value())) {
                  //} else if (IsArray(item.Value().Value().ToObject())) {
                  writer->Write("\"{0}\":", item.Key());
                  Serialize(as<System::Array<string>>(item.Value().Value()).ToObject());
                } else
                  if (IsNumber(item.Value().Value().ToObject()))
                    writer->Write("\"{0}\":{1}", item.Key(), item.Value().Value().ToObject());
                  else
                    writer->Write("\"{0}\":\"{1}\"", item.Key(), item.Value().Value().ToObject());
              }
              writer->Write("}");
            }
            
            template<typename T>
            void Serialize(const System::Array<T>& graph) {
              string tailing;
              writer->Write("[");
              
              for (T item : graph) {
                writer->Write(tailing);
                tailing = ",";
                if (is<System::Runtime::Serialization::SerializationInfo>(item)) {
                  Serialize(as<System::Runtime::Serialization::SerializationInfo>(item));
                } else if (is<System::Array<string>>(item)) {
                  Serialize(as<System::Array<string>>(item));
                } else
                  writer->Write("\"{0}\"", item);
              }
              
              writer->Write("]");
            }
            
            template<typename T>
            bool IsArray(const System::Array<T>& array) {return true;}
            
            template<typename T>
            bool IsArray(System::Array<T>& array) {return true;}
            
            bool IsArray(const object& array) {return false;}
            
            bool IsNumber(const object& number) {
              return is<Byte>(number) || is<Decimal>(number) || is<Double>(number) || is<Int16>(number) || is<Int32>(number) || is<Int64>(number) || is<SByte>(number) || is<Single>(number) || is<UInt16>(number) || is<UInt32>(number) || is<UInt64>(number);
            }
            
            refptr<IO::StreamWriter> writer;
          };
        }
      }
    }
  }
}

namespace Test {
  class Role : public object, public System::Runtime::Serialization::ISerializable {
  public:
    Role() {}
    Role(const string& name, byte info) : Name(name), Info(info) {}
    
    string Name;
    byte Info = 0;

    void GetObjectData(System::Runtime::Serialization::SerializationInfo& info) const override {
      info.SetObjectType("Role");
      info.AddValue("Name", this->Name);
      info.AddValue("Info", this->Info);
    }
    
    static refptr<Role> Deserialize(const System::Runtime::Serialization::SerializationInfo& info) {
      refptr<Role> role = pcf_new<Role>();
      role->Name = info.GetString("Name");
      role->Info = info.GetByte("Info");
      return role;
    }
    
    string ToString() const override {return string::Format("{{{0}, {1}}}", this->Name, this->Info);}
  };
  
  class Person : public object, public System::Runtime::Serialization::ISerializable {
  public:
    Person() {}
    Person(const string& firstName, const string& lastName, int age, Array<string> childrens, const Role& role) : FirstName(firstName), LastName(lastName), Age(age), Childrens(childrens), Role(role) {}
    
    string FirstName;
    string LastName;
    int Age = 0;
    Array<string> Childrens;
    Test::Role Role;
    
    void GetObjectData(System::Runtime::Serialization::SerializationInfo& info) const override {
      info.AddValue("FirstName", this->FirstName);
      info.AddValue("LastName", this->LastName);
      info.AddValue("Age", this->Age);
      info.AddValue("Childrens", this->Childrens);
      info.AddValue("Role", this->Role);
    }
    
    static refptr<Person> Deserialize(const System::Runtime::Serialization::SerializationInfo& info) {
      refptr<Person> person = pcf_new<Person>();
      person->FirstName = info.GetString("FirstName");
      person->LastName = info.GetString("LastName");
      person->Age = info.GetInt32("Age");
      person->Role = info.GetValue<Test::Role>("Role").ToObject();
      
      return person;
    }
 
    string ToString() const override {return string::Format("{{{0}, {1}, {2}, [{3}], {4}}}", this->FirstName, this->LastName, this->Age, string::Join(", ", this->Childrens), this->Role);}
  };
  
  class TestSerializer : public System::Runtime::Serialization::IFormatter {
  public:
    void Deserialize(const refptr<System::IO::Stream>& serializationStream, System::Runtime::Serialization::ISerializable& graph) override {
    }
    
    using IFormatter::Deserialize;
    
    void Serialize(const refptr<System::IO::Stream>& serializationStream, const Object& graph) override {
      Serialize(as<System::Runtime::Serialization::ISerializable>(graph));
    }

  private:
    void Serialize(const System::Runtime::Serialization::ISerializable& graph) {
      Console::WriteLine("Serializing...");
      System::Runtime::Serialization::SerializationInfo serializationInfo;
      graph.GetObjectData(serializationInfo);
      for (System::Collections::Generic::KeyValuePair<string, System::Runtime::Serialization::SerializationEntry> item : serializationInfo) {
        Console::Write(item);
        if (IsInteger(item.Value().Value().ToObject())) {
          Console::Write(" is Integer");
        } else if (IsString(item.Value().Value().ToObject())) {
          Console::Write(" is String");
        } else if (IsSerializationInfo(item.Value().Value().ToObject())) {
          Console::Write(" is SerializationInfo");
        } else if (IsArray(item.Value().Value().ToObject())) {
          Console::Write(" is Array");
        } else {
          throw InvalidCastException(pcf_current_information);
        }
        Console::WriteLine();
      }
    }
    
    template<typename T>
    bool IsInteger(const T& value) const {
      return is<System::Int32>(value);
    }
    
    template<typename T>
    bool IsString(const T& value) const {
      return is<System::String>(value);
    }
    
    template<typename T>
    bool IsSerializationInfo(const T& value) const {
      return is<System::Runtime::Serialization::SerializationInfo>(value);
    }
    
    template<typename T>
    bool IsArray(const T& value) const {
      return _IsArray(value);
    }
    
    template<typename T, int32 rank, typename TAllocator>
    bool _IsArray(const Array<T, rank, TAllocator>& value) const {
      return is<System::Array<T>>(value);
    }
    
    template <typename T>
    bool _IsArray(const T& value) const {
      return false;
    }
    
  };
}

int main(int argc, char* argv[]) {
  Test::Person person("Yves", "Fiumefreddo", 45, {"Martin", "Arthur"}, Test::Role("Senior Software Architect", 42));
  Console::WriteLine("person = {0}", person);
  refptr<System::IO::Stream> stream = pcf_new<System::IO::MemoryStream>();
  
  Test::TestSerializer serializer;
  serializer.Serialize(stream, person);
  
  /*
   Test::Person person("Yves", "Fiumefreddo", 45, {"Martin", "Arthur"}, Test::Role("Senior Software Architect", 42));
   Console::WriteLine("person = {0}", person);
   Sp<System::IO::Stream> stream = pcf_new<System::IO::MemoryStream>();
   
   System::Runtime::Serialization::Json::JSonSerializer serializer;
   serializer.Serialize(stream, person);
   
   stream->Seek(0, System::IO::SeekOrigin::Begin);
   Console::WriteLine(System::IO::StreamReader(stream).ReadToEnd());
   
   stream->Seek(0, System::IO::SeekOrigin::Begin);
   Test::Person person2 = serializer.Deserialize<Person>(stream);
   Console::WriteLine("person2 = {0}", person);
   */
}

// This code produces the following output:
//
