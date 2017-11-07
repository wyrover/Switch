#include <Switch/System/TimeZoneInfo.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  TEST(TimeZoneInfoTest, Local) {
    ASSERT_FALSE(string::IsNullOrEmpty(TimeZoneInfo::Local().Id()));
    ASSERT_FALSE(string::IsNullOrEmpty(TimeZoneInfo::Local().DaylightName()));
    ASSERT_FALSE(string::IsNullOrEmpty(TimeZoneInfo::Local().DisplayName()));
    ASSERT_FALSE(string::IsNullOrEmpty(TimeZoneInfo::Local().StandardName()));
    //Console::WriteLine(string::Format("Local : \"{0}\", {1}, \"{2}\", \"{3}\", \"{4}\", {5}", TimeZoneInfo::Local().Id(), TimeZoneInfo::Local().BaseUtcOffset(), TimeZoneInfo::Local().DaylightName(), TimeZoneInfo::Local().DisplayName(), TimeZoneInfo::Local().StandardName(), TimeZoneInfo::Local().SupportsDaylightSavingTime()));
  }
  
  TEST(TimeZoneInfoTest, Utc) {
    ASSERT_EQ("UTC", TimeZoneInfo::Utc().Id());
    ASSERT_EQ("", TimeZoneInfo::Utc().DaylightName());
    ASSERT_EQ("UTC", TimeZoneInfo::Utc().DisplayName());
    ASSERT_EQ("UTC", TimeZoneInfo::Utc().StandardName());
    ASSERT_EQ(0, TimeZoneInfo::Utc().BaseUtcOffset().Ticks());
    ASSERT_FALSE(TimeZoneInfo::Utc().SupportsDaylightSavingTime());
    //Console::WriteLine(string::Format("Utc : \"{0}\", {1}, \"{2}\", \"{3}\", \"{4}\", {5}", TimeZoneInfo::Utc().Id(), TimeZoneInfo::Utc().BaseUtcOffset(), TimeZoneInfo::Utc().DaylightName(), TimeZoneInfo::Utc().DisplayName(), TimeZoneInfo::Utc().StandardName(), TimeZoneInfo::Utc().SupportsDaylightSavingTime()));
  }
  
  TEST(TimeZoneInfoTest, TimeFindSystemTimeZoneById) {
    ASSERT_EQ(TimeZoneInfo::Local().Id(), TimeZoneInfo::TimeFindSystemTimeZoneById(TimeZoneInfo::Local().Id()).Id());
    ASSERT_EQ(TimeZoneInfo::Utc().Id(), TimeZoneInfo::TimeFindSystemTimeZoneById("UTC").Id());
    ASSERT_EQ("Africa/Abidjan", TimeZoneInfo::TimeFindSystemTimeZoneById("Africa/Abidjan").Id());
    ASSERT_EQ("Europe/Brussels", TimeZoneInfo::TimeFindSystemTimeZoneById("Europe/Brussels").Id());
    ASSERT_EQ("US/Pacific", TimeZoneInfo::TimeFindSystemTimeZoneById("US/Pacific").Id());
    ASSERT_EQ("US/Samoa", TimeZoneInfo::TimeFindSystemTimeZoneById("US/Samoa").Id());
    
   ASSERT_THROW(TimeZoneInfo::TimeFindSystemTimeZoneById("Any/Nothing"), TimeZoneNotFoundException);
    
    //Console::WriteLine(TimeZoneInfo::ConvertTimeToUtc(DateTime::Now));
    //Console::WriteLine(DateTime::Now + TimeZoneInfo::Local().BaseUtcOffset());
  }
  
  TEST(TimeZoneInfoTest, ConvertTimeToUtc) {
    DateTime now = DateTime::Now();
    ASSERT_EQ(now.ToUniversalTime(), TimeZoneInfo::ConvertTimeToUtc(now));

    //Console::WriteLine("Local {0}", now);
    //Console::WriteLine("Utc   {0}", TimeZoneInfo::ConvertTimeToUtc(now));
  }
  
  /*
  TEST(TimeZoneInfoTest, List) {
    for (TimeZoneInfo item : TimeZoneInfo::GetSystemTimeZones()) {
      Console::WriteLine("{0,-25} {1,-40} {2,10}", item.Id(), item.DisplayName(), item.BaseUtcOffset());
    }
  }
   */

  /* Generate by this c# code source :
   
  using System;
  using System::Collections::ObjectModel;
  using System::Windows::Forms;
  
  namespace TestConsole {
    class MainClass {
      [STAThread]
      static void Main()  {
        ReadOnlyCollection<TimeZoneInfo> systemTimeZones = TimeZoneInfo.GetSystemTimeZones();
        string expects = "";
        int index = 0;
        for (TimeZoneInfo item : systemTimeZones) {
          expects += string.Format("  TEST(TimeZoneInfoTest, GetSystemTimeZones{0}) {{\n", item.Id.Replace(' ', '_').Replace('-', '_').Replace('(', '_').Replace(')', '_').Replace('.', '_').Replace('+', '_').Replace('/', '_'));
          expects += string.Format("    ASSERT_EQ(\"{0}\", TimeZoneInfo::GetSystemTimeZones()[{1}].Id());\n", item.Id, index);
          expects += string.Format("    ASSERT_EQ(\"{0} {1}\", TimeZoneInfo::GetSystemTimeZones()[{2}].DisplayName());\n", item.BaseUtcOffset.Ticks == 0 ? "(UTC)" : string.Format("(UTC{0}{1})", item.BaseUtcOffset.Ticks >= 0 ? "+" : "", item.BaseUtcOffset), item.DisplayName, index);
          expects += string.Format("    ASSERT_EQ(\"{0}\", TimeZoneInfo::GetSystemTimeZones()[{1}].DaylightName());\n", item.DaylightName, index);
          expects += string.Format("    ASSERT_EQ(\"{0}\", TimeZoneInfo::GetSystemTimeZones()[{1}].BaseUtcOffset().ToString());\n", item.BaseUtcOffset, index);
          expects += string.Format("    ASSERT_EQ(\"{0}\", TimeZoneInfo::GetSystemTimeZones()[{1}].StandardName());\n", item.StandardName, index);
          expects += string.Format("    EXPECT_{0}(TimeZoneInfo::GetSystemTimeZones()[{1}].SupportsDaylightSavingTime());\n", item.SupportsDaylightSavingTime.ToString().ToUpper(), index);
          expects += "  }\n\n";
          index++;
        }
        Clipboard.SetText(expects);
        Console.WriteLine(expects);
        Console.ReadKey();
      }
    }
  }

   */
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Abidjan) {
    ASSERT_EQ("Africa/Abidjan", TimeZoneInfo::GetSystemTimeZones()[0].Id());
    ASSERT_EQ("(UTC) Africa/Abidjan", TimeZoneInfo::GetSystemTimeZones()[0].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[0].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[0].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[0].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[0].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Accra) {
    ASSERT_EQ("Africa/Accra", TimeZoneInfo::GetSystemTimeZones()[1].Id());
    ASSERT_EQ("(UTC) Africa/Accra", TimeZoneInfo::GetSystemTimeZones()[1].DisplayName());
    ASSERT_EQ("GHST", TimeZoneInfo::GetSystemTimeZones()[1].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[1].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[1].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[1].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Addis_Ababa) {
    ASSERT_EQ("Africa/Addis_Ababa", TimeZoneInfo::GetSystemTimeZones()[2].Id());
    ASSERT_EQ("(UTC+03:00:00) Africa/Addis_Ababa", TimeZoneInfo::GetSystemTimeZones()[2].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[2].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[2].BaseUtcOffset().ToString());
    ASSERT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[2].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[2].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Algiers) {
    ASSERT_EQ("Africa/Algiers", TimeZoneInfo::GetSystemTimeZones()[3].Id());
    ASSERT_EQ("(UTC+01:00:00) Africa/Algiers", TimeZoneInfo::GetSystemTimeZones()[3].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[3].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[3].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[3].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[3].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Asmara) {
    ASSERT_EQ("Africa/Asmara", TimeZoneInfo::GetSystemTimeZones()[4].Id());
    ASSERT_EQ("(UTC+03:00:00) Africa/Asmara", TimeZoneInfo::GetSystemTimeZones()[4].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[4].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[4].BaseUtcOffset().ToString());
    ASSERT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[4].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[4].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Asmera) {
    ASSERT_EQ("Africa/Asmera", TimeZoneInfo::GetSystemTimeZones()[5].Id());
    ASSERT_EQ("(UTC+03:00:00) Africa/Asmera", TimeZoneInfo::GetSystemTimeZones()[5].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[5].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[5].BaseUtcOffset().ToString());
    ASSERT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[5].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[5].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Bamako) {
    ASSERT_EQ("Africa/Bamako", TimeZoneInfo::GetSystemTimeZones()[6].Id());
    ASSERT_EQ("(UTC) Africa/Bamako", TimeZoneInfo::GetSystemTimeZones()[6].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[6].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[6].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[6].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[6].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Bangui) {
    ASSERT_EQ("Africa/Bangui", TimeZoneInfo::GetSystemTimeZones()[7].Id());
    ASSERT_EQ("(UTC+01:00:00) Africa/Bangui", TimeZoneInfo::GetSystemTimeZones()[7].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[7].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[7].BaseUtcOffset().ToString());
    ASSERT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[7].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[7].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Banjul) {
    ASSERT_EQ("Africa/Banjul", TimeZoneInfo::GetSystemTimeZones()[8].Id());
    ASSERT_EQ("(UTC) Africa/Banjul", TimeZoneInfo::GetSystemTimeZones()[8].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[8].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[8].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[8].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[8].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Bissau) {
    ASSERT_EQ("Africa/Bissau", TimeZoneInfo::GetSystemTimeZones()[9].Id());
    ASSERT_EQ("(UTC) Africa/Bissau", TimeZoneInfo::GetSystemTimeZones()[9].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[9].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[9].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[9].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[9].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Blantyre) {
    ASSERT_EQ("Africa/Blantyre", TimeZoneInfo::GetSystemTimeZones()[10].Id());
    ASSERT_EQ("(UTC+02:00:00) Africa/Blantyre", TimeZoneInfo::GetSystemTimeZones()[10].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[10].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[10].BaseUtcOffset().ToString());
    ASSERT_EQ("CAT", TimeZoneInfo::GetSystemTimeZones()[10].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[10].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Brazzaville) {
    ASSERT_EQ("Africa/Brazzaville", TimeZoneInfo::GetSystemTimeZones()[11].Id());
    ASSERT_EQ("(UTC+01:00:00) Africa/Brazzaville", TimeZoneInfo::GetSystemTimeZones()[11].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[11].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[11].BaseUtcOffset().ToString());
    ASSERT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[11].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[11].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Bujumbura) {
    ASSERT_EQ("Africa/Bujumbura", TimeZoneInfo::GetSystemTimeZones()[12].Id());
    ASSERT_EQ("(UTC+02:00:00) Africa/Bujumbura", TimeZoneInfo::GetSystemTimeZones()[12].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[12].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[12].BaseUtcOffset().ToString());
    ASSERT_EQ("CAT", TimeZoneInfo::GetSystemTimeZones()[12].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[12].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Cairo) {
    ASSERT_EQ("Africa/Cairo", TimeZoneInfo::GetSystemTimeZones()[13].Id());
    ASSERT_EQ("(UTC+02:00:00) Africa/Cairo", TimeZoneInfo::GetSystemTimeZones()[13].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[13].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[13].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[13].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[13].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Casablanca) {
    ASSERT_EQ("Africa/Casablanca", TimeZoneInfo::GetSystemTimeZones()[14].Id());
    ASSERT_EQ("(UTC) Africa/Casablanca", TimeZoneInfo::GetSystemTimeZones()[14].DisplayName());
    ASSERT_EQ("WEST", TimeZoneInfo::GetSystemTimeZones()[14].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[14].BaseUtcOffset().ToString());
    ASSERT_EQ("WET", TimeZoneInfo::GetSystemTimeZones()[14].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[14].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Ceuta) {
    ASSERT_EQ("Africa/Ceuta", TimeZoneInfo::GetSystemTimeZones()[15].Id());
    ASSERT_EQ("(UTC+01:00:00) Africa/Ceuta", TimeZoneInfo::GetSystemTimeZones()[15].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[15].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[15].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[15].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[15].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Conakry) {
    ASSERT_EQ("Africa/Conakry", TimeZoneInfo::GetSystemTimeZones()[16].Id());
    ASSERT_EQ("(UTC) Africa/Conakry", TimeZoneInfo::GetSystemTimeZones()[16].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[16].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[16].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[16].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[16].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Dakar) {
    ASSERT_EQ("Africa/Dakar", TimeZoneInfo::GetSystemTimeZones()[17].Id());
    ASSERT_EQ("(UTC) Africa/Dakar", TimeZoneInfo::GetSystemTimeZones()[17].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[17].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[17].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[17].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[17].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Dar_es_Salaam) {
    ASSERT_EQ("Africa/Dar_es_Salaam", TimeZoneInfo::GetSystemTimeZones()[18].Id());
    ASSERT_EQ("(UTC+03:00:00) Africa/Dar_es_Salaam", TimeZoneInfo::GetSystemTimeZones()[18].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[18].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[18].BaseUtcOffset().ToString());
    ASSERT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[18].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[18].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Djibouti) {
    ASSERT_EQ("Africa/Djibouti", TimeZoneInfo::GetSystemTimeZones()[19].Id());
    ASSERT_EQ("(UTC+03:00:00) Africa/Djibouti", TimeZoneInfo::GetSystemTimeZones()[19].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[19].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[19].BaseUtcOffset().ToString());
    ASSERT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[19].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[19].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Douala) {
    ASSERT_EQ("Africa/Douala", TimeZoneInfo::GetSystemTimeZones()[20].Id());
    ASSERT_EQ("(UTC+01:00:00) Africa/Douala", TimeZoneInfo::GetSystemTimeZones()[20].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[20].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[20].BaseUtcOffset().ToString());
    ASSERT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[20].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[20].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_El_Aaiun) {
    ASSERT_EQ("Africa/El_Aaiun", TimeZoneInfo::GetSystemTimeZones()[21].Id());
    ASSERT_EQ("(UTC) Africa/El_Aaiun", TimeZoneInfo::GetSystemTimeZones()[21].DisplayName());
    ASSERT_EQ("WEST", TimeZoneInfo::GetSystemTimeZones()[21].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[21].BaseUtcOffset().ToString());
    ASSERT_EQ("WET", TimeZoneInfo::GetSystemTimeZones()[21].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[21].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Freetown) {
    ASSERT_EQ("Africa/Freetown", TimeZoneInfo::GetSystemTimeZones()[22].Id());
    ASSERT_EQ("(UTC) Africa/Freetown", TimeZoneInfo::GetSystemTimeZones()[22].DisplayName());
    ASSERT_EQ("SLST", TimeZoneInfo::GetSystemTimeZones()[22].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[22].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[22].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[22].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Gaborone) {
    ASSERT_EQ("Africa/Gaborone", TimeZoneInfo::GetSystemTimeZones()[23].Id());
    ASSERT_EQ("(UTC+02:00:00) Africa/Gaborone", TimeZoneInfo::GetSystemTimeZones()[23].DisplayName());
    ASSERT_EQ("CAST", TimeZoneInfo::GetSystemTimeZones()[23].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[23].BaseUtcOffset().ToString());
    ASSERT_EQ("CAT", TimeZoneInfo::GetSystemTimeZones()[23].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[23].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Harare) {
    ASSERT_EQ("Africa/Harare", TimeZoneInfo::GetSystemTimeZones()[24].Id());
    ASSERT_EQ("(UTC+02:00:00) Africa/Harare", TimeZoneInfo::GetSystemTimeZones()[24].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[24].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[24].BaseUtcOffset().ToString());
    ASSERT_EQ("CAT", TimeZoneInfo::GetSystemTimeZones()[24].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[24].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Johannesburg) {
    ASSERT_EQ("Africa/Johannesburg", TimeZoneInfo::GetSystemTimeZones()[25].Id());
    ASSERT_EQ("(UTC+02:00:00) Africa/Johannesburg", TimeZoneInfo::GetSystemTimeZones()[25].DisplayName());
    ASSERT_EQ("SAST", TimeZoneInfo::GetSystemTimeZones()[25].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[25].BaseUtcOffset().ToString());
    ASSERT_EQ("SAST", TimeZoneInfo::GetSystemTimeZones()[25].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[25].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Juba) {
    ASSERT_EQ("Africa/Juba", TimeZoneInfo::GetSystemTimeZones()[26].Id());
    ASSERT_EQ("(UTC+03:00:00) Africa/Juba", TimeZoneInfo::GetSystemTimeZones()[26].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[26].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[26].BaseUtcOffset().ToString());
    ASSERT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[26].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[26].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Kampala) {
    ASSERT_EQ("Africa/Kampala", TimeZoneInfo::GetSystemTimeZones()[27].Id());
    ASSERT_EQ("(UTC+03:00:00) Africa/Kampala", TimeZoneInfo::GetSystemTimeZones()[27].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[27].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[27].BaseUtcOffset().ToString());
    ASSERT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[27].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[27].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Khartoum) {
    ASSERT_EQ("Africa/Khartoum", TimeZoneInfo::GetSystemTimeZones()[28].Id());
    ASSERT_EQ("(UTC+03:00:00) Africa/Khartoum", TimeZoneInfo::GetSystemTimeZones()[28].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[28].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[28].BaseUtcOffset().ToString());
    ASSERT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[28].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[28].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Kigali) {
    ASSERT_EQ("Africa/Kigali", TimeZoneInfo::GetSystemTimeZones()[29].Id());
    ASSERT_EQ("(UTC+02:00:00) Africa/Kigali", TimeZoneInfo::GetSystemTimeZones()[29].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[29].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[29].BaseUtcOffset().ToString());
    ASSERT_EQ("CAT", TimeZoneInfo::GetSystemTimeZones()[29].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[29].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Kinshasa) {
    ASSERT_EQ("Africa/Kinshasa", TimeZoneInfo::GetSystemTimeZones()[30].Id());
    ASSERT_EQ("(UTC+01:00:00) Africa/Kinshasa", TimeZoneInfo::GetSystemTimeZones()[30].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[30].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[30].BaseUtcOffset().ToString());
    ASSERT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[30].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[30].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Lagos) {
    ASSERT_EQ("Africa/Lagos", TimeZoneInfo::GetSystemTimeZones()[31].Id());
    ASSERT_EQ("(UTC+01:00:00) Africa/Lagos", TimeZoneInfo::GetSystemTimeZones()[31].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[31].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[31].BaseUtcOffset().ToString());
    ASSERT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[31].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[31].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Libreville) {
    ASSERT_EQ("Africa/Libreville", TimeZoneInfo::GetSystemTimeZones()[32].Id());
    ASSERT_EQ("(UTC+01:00:00) Africa/Libreville", TimeZoneInfo::GetSystemTimeZones()[32].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[32].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[32].BaseUtcOffset().ToString());
    ASSERT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[32].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[32].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Lome) {
    ASSERT_EQ("Africa/Lome", TimeZoneInfo::GetSystemTimeZones()[33].Id());
    ASSERT_EQ("(UTC) Africa/Lome", TimeZoneInfo::GetSystemTimeZones()[33].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[33].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[33].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[33].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[33].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Luanda) {
    ASSERT_EQ("Africa/Luanda", TimeZoneInfo::GetSystemTimeZones()[34].Id());
    ASSERT_EQ("(UTC+01:00:00) Africa/Luanda", TimeZoneInfo::GetSystemTimeZones()[34].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[34].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[34].BaseUtcOffset().ToString());
    ASSERT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[34].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[34].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Lubumbashi) {
    ASSERT_EQ("Africa/Lubumbashi", TimeZoneInfo::GetSystemTimeZones()[35].Id());
    ASSERT_EQ("(UTC+02:00:00) Africa/Lubumbashi", TimeZoneInfo::GetSystemTimeZones()[35].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[35].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[35].BaseUtcOffset().ToString());
    ASSERT_EQ("CAT", TimeZoneInfo::GetSystemTimeZones()[35].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[35].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Lusaka) {
    ASSERT_EQ("Africa/Lusaka", TimeZoneInfo::GetSystemTimeZones()[36].Id());
    ASSERT_EQ("(UTC+02:00:00) Africa/Lusaka", TimeZoneInfo::GetSystemTimeZones()[36].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[36].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[36].BaseUtcOffset().ToString());
    ASSERT_EQ("CAT", TimeZoneInfo::GetSystemTimeZones()[36].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[36].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Malabo) {
    ASSERT_EQ("Africa/Malabo", TimeZoneInfo::GetSystemTimeZones()[37].Id());
    ASSERT_EQ("(UTC+01:00:00) Africa/Malabo", TimeZoneInfo::GetSystemTimeZones()[37].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[37].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[37].BaseUtcOffset().ToString());
    ASSERT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[37].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[37].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Maputo) {
    ASSERT_EQ("Africa/Maputo", TimeZoneInfo::GetSystemTimeZones()[38].Id());
    ASSERT_EQ("(UTC+02:00:00) Africa/Maputo", TimeZoneInfo::GetSystemTimeZones()[38].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[38].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[38].BaseUtcOffset().ToString());
    ASSERT_EQ("CAT", TimeZoneInfo::GetSystemTimeZones()[38].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[38].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Maseru) {
    ASSERT_EQ("Africa/Maseru", TimeZoneInfo::GetSystemTimeZones()[39].Id());
    ASSERT_EQ("(UTC+02:00:00) Africa/Maseru", TimeZoneInfo::GetSystemTimeZones()[39].DisplayName());
    ASSERT_EQ("SAST", TimeZoneInfo::GetSystemTimeZones()[39].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[39].BaseUtcOffset().ToString());
    ASSERT_EQ("SAST", TimeZoneInfo::GetSystemTimeZones()[39].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[39].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Mbabane) {
    ASSERT_EQ("Africa/Mbabane", TimeZoneInfo::GetSystemTimeZones()[40].Id());
    ASSERT_EQ("(UTC+02:00:00) Africa/Mbabane", TimeZoneInfo::GetSystemTimeZones()[40].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[40].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[40].BaseUtcOffset().ToString());
    ASSERT_EQ("SAST", TimeZoneInfo::GetSystemTimeZones()[40].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[40].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Mogadishu) {
    ASSERT_EQ("Africa/Mogadishu", TimeZoneInfo::GetSystemTimeZones()[41].Id());
    ASSERT_EQ("(UTC+03:00:00) Africa/Mogadishu", TimeZoneInfo::GetSystemTimeZones()[41].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[41].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[41].BaseUtcOffset().ToString());
    ASSERT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[41].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[41].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Monrovia) {
    ASSERT_EQ("Africa/Monrovia", TimeZoneInfo::GetSystemTimeZones()[42].Id());
    ASSERT_EQ("(UTC) Africa/Monrovia", TimeZoneInfo::GetSystemTimeZones()[42].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[42].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[42].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[42].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[42].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Nairobi) {
    ASSERT_EQ("Africa/Nairobi", TimeZoneInfo::GetSystemTimeZones()[43].Id());
    ASSERT_EQ("(UTC+03:00:00) Africa/Nairobi", TimeZoneInfo::GetSystemTimeZones()[43].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[43].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[43].BaseUtcOffset().ToString());
    ASSERT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[43].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[43].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Ndjamena) {
    ASSERT_EQ("Africa/Ndjamena", TimeZoneInfo::GetSystemTimeZones()[44].Id());
    ASSERT_EQ("(UTC+01:00:00) Africa/Ndjamena", TimeZoneInfo::GetSystemTimeZones()[44].DisplayName());
    ASSERT_EQ("WAST", TimeZoneInfo::GetSystemTimeZones()[44].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[44].BaseUtcOffset().ToString());
    ASSERT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[44].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[44].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Niamey) {
    ASSERT_EQ("Africa/Niamey", TimeZoneInfo::GetSystemTimeZones()[45].Id());
    ASSERT_EQ("(UTC+01:00:00) Africa/Niamey", TimeZoneInfo::GetSystemTimeZones()[45].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[45].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[45].BaseUtcOffset().ToString());
    ASSERT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[45].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[45].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Nouakchott) {
    ASSERT_EQ("Africa/Nouakchott", TimeZoneInfo::GetSystemTimeZones()[46].Id());
    ASSERT_EQ("(UTC) Africa/Nouakchott", TimeZoneInfo::GetSystemTimeZones()[46].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[46].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[46].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[46].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[46].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Ouagadougou) {
    ASSERT_EQ("Africa/Ouagadougou", TimeZoneInfo::GetSystemTimeZones()[47].Id());
    ASSERT_EQ("(UTC) Africa/Ouagadougou", TimeZoneInfo::GetSystemTimeZones()[47].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[47].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[47].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[47].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[47].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Porto_Novo) {
    ASSERT_EQ("Africa/Porto-Novo", TimeZoneInfo::GetSystemTimeZones()[48].Id());
    ASSERT_EQ("(UTC+01:00:00) Africa/Porto-Novo", TimeZoneInfo::GetSystemTimeZones()[48].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[48].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[48].BaseUtcOffset().ToString());
    ASSERT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[48].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[48].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Sao_Tome) {
    ASSERT_EQ("Africa/Sao_Tome", TimeZoneInfo::GetSystemTimeZones()[49].Id());
    ASSERT_EQ("(UTC) Africa/Sao_Tome", TimeZoneInfo::GetSystemTimeZones()[49].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[49].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[49].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[49].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[49].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Timbuktu) {
    ASSERT_EQ("Africa/Timbuktu", TimeZoneInfo::GetSystemTimeZones()[50].Id());
    ASSERT_EQ("(UTC) Africa/Timbuktu", TimeZoneInfo::GetSystemTimeZones()[50].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[50].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[50].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[50].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[50].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Tripoli) {
    ASSERT_EQ("Africa/Tripoli", TimeZoneInfo::GetSystemTimeZones()[51].Id());
    ASSERT_EQ("(UTC+02:00:00) Africa/Tripoli", TimeZoneInfo::GetSystemTimeZones()[51].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[51].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[51].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[51].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[51].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Tunis) {
    ASSERT_EQ("Africa/Tunis", TimeZoneInfo::GetSystemTimeZones()[52].Id());
    ASSERT_EQ("(UTC+01:00:00) Africa/Tunis", TimeZoneInfo::GetSystemTimeZones()[52].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[52].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[52].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[52].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[52].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAfrica_Windhoek) {
    ASSERT_EQ("Africa/Windhoek", TimeZoneInfo::GetSystemTimeZones()[53].Id());
    ASSERT_EQ("(UTC+01:00:00) Africa/Windhoek", TimeZoneInfo::GetSystemTimeZones()[53].DisplayName());
    ASSERT_EQ("WAST", TimeZoneInfo::GetSystemTimeZones()[53].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[53].BaseUtcOffset().ToString());
    ASSERT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[53].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[53].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Adak) {
    ASSERT_EQ("America/Adak", TimeZoneInfo::GetSystemTimeZones()[54].Id());
    ASSERT_EQ("(UTC-10:00:00) America/Adak", TimeZoneInfo::GetSystemTimeZones()[54].DisplayName());
    ASSERT_EQ("HADT", TimeZoneInfo::GetSystemTimeZones()[54].DaylightName());
    ASSERT_EQ("-10:00:00", TimeZoneInfo::GetSystemTimeZones()[54].BaseUtcOffset().ToString());
    ASSERT_EQ("HAST", TimeZoneInfo::GetSystemTimeZones()[54].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[54].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Anchorage) {
    ASSERT_EQ("America/Anchorage", TimeZoneInfo::GetSystemTimeZones()[55].Id());
    ASSERT_EQ("(UTC-09:00:00) America/Anchorage", TimeZoneInfo::GetSystemTimeZones()[55].DisplayName());
    ASSERT_EQ("AKDT", TimeZoneInfo::GetSystemTimeZones()[55].DaylightName());
    ASSERT_EQ("-09:00:00", TimeZoneInfo::GetSystemTimeZones()[55].BaseUtcOffset().ToString());
    ASSERT_EQ("AKST", TimeZoneInfo::GetSystemTimeZones()[55].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[55].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Anguilla) {
    ASSERT_EQ("America/Anguilla", TimeZoneInfo::GetSystemTimeZones()[56].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Anguilla", TimeZoneInfo::GetSystemTimeZones()[56].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[56].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[56].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[56].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[56].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Antigua) {
    ASSERT_EQ("America/Antigua", TimeZoneInfo::GetSystemTimeZones()[57].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Antigua", TimeZoneInfo::GetSystemTimeZones()[57].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[57].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[57].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[57].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[57].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Araguaina) {
    ASSERT_EQ("America/Araguaina", TimeZoneInfo::GetSystemTimeZones()[58].Id());
    ASSERT_EQ("(UTC-03:00:00) America/Araguaina", TimeZoneInfo::GetSystemTimeZones()[58].DisplayName());
    ASSERT_EQ("BRST", TimeZoneInfo::GetSystemTimeZones()[58].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[58].BaseUtcOffset().ToString());
    ASSERT_EQ("BRT", TimeZoneInfo::GetSystemTimeZones()[58].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[58].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Aruba) {
    ASSERT_EQ("America/Aruba", TimeZoneInfo::GetSystemTimeZones()[59].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Aruba", TimeZoneInfo::GetSystemTimeZones()[59].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[59].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[59].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[59].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[59].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Asuncion) {
    ASSERT_EQ("America/Asuncion", TimeZoneInfo::GetSystemTimeZones()[60].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Asuncion", TimeZoneInfo::GetSystemTimeZones()[60].DisplayName());
    ASSERT_EQ("PYST", TimeZoneInfo::GetSystemTimeZones()[60].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[60].BaseUtcOffset().ToString());
    ASSERT_EQ("PYT", TimeZoneInfo::GetSystemTimeZones()[60].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[60].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Atikokan) {
    ASSERT_EQ("America/Atikokan", TimeZoneInfo::GetSystemTimeZones()[61].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Atikokan", TimeZoneInfo::GetSystemTimeZones()[61].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[61].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[61].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[61].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[61].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Atka) {
    ASSERT_EQ("America/Atka", TimeZoneInfo::GetSystemTimeZones()[62].Id());
    ASSERT_EQ("(UTC-10:00:00) America/Atka", TimeZoneInfo::GetSystemTimeZones()[62].DisplayName());
    ASSERT_EQ("HADT", TimeZoneInfo::GetSystemTimeZones()[62].DaylightName());
    ASSERT_EQ("-10:00:00", TimeZoneInfo::GetSystemTimeZones()[62].BaseUtcOffset().ToString());
    ASSERT_EQ("HAST", TimeZoneInfo::GetSystemTimeZones()[62].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[62].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Bahia) {
    ASSERT_EQ("America/Bahia", TimeZoneInfo::GetSystemTimeZones()[63].Id());
    ASSERT_EQ("(UTC-03:00:00) America/Bahia", TimeZoneInfo::GetSystemTimeZones()[63].DisplayName());
    ASSERT_EQ("BRST", TimeZoneInfo::GetSystemTimeZones()[63].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[63].BaseUtcOffset().ToString());
    ASSERT_EQ("BRT", TimeZoneInfo::GetSystemTimeZones()[63].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[63].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Bahia_Banderas) {
    ASSERT_EQ("America/Bahia_Banderas", TimeZoneInfo::GetSystemTimeZones()[64].Id());
    ASSERT_EQ("(UTC-06:00:00) America/Bahia_Banderas", TimeZoneInfo::GetSystemTimeZones()[64].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[64].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[64].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[64].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[64].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Barbados) {
    ASSERT_EQ("America/Barbados", TimeZoneInfo::GetSystemTimeZones()[65].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Barbados", TimeZoneInfo::GetSystemTimeZones()[65].DisplayName());
    ASSERT_EQ("ADT", TimeZoneInfo::GetSystemTimeZones()[65].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[65].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[65].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[65].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Belem) {
    ASSERT_EQ("America/Belem", TimeZoneInfo::GetSystemTimeZones()[66].Id());
    ASSERT_EQ("(UTC-03:00:00) America/Belem", TimeZoneInfo::GetSystemTimeZones()[66].DisplayName());
    ASSERT_EQ("BRST", TimeZoneInfo::GetSystemTimeZones()[66].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[66].BaseUtcOffset().ToString());
    ASSERT_EQ("BRT", TimeZoneInfo::GetSystemTimeZones()[66].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[66].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Belize) {
    ASSERT_EQ("America/Belize", TimeZoneInfo::GetSystemTimeZones()[67].Id());
    ASSERT_EQ("(UTC-06:00:00) America/Belize", TimeZoneInfo::GetSystemTimeZones()[67].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[67].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[67].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[67].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[67].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Blanc_Sablon) {
    ASSERT_EQ("America/Blanc-Sablon", TimeZoneInfo::GetSystemTimeZones()[68].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Blanc-Sablon", TimeZoneInfo::GetSystemTimeZones()[68].DisplayName());
    ASSERT_EQ("APT", TimeZoneInfo::GetSystemTimeZones()[68].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[68].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[68].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[68].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Boa_Vista) {
    ASSERT_EQ("America/Boa_Vista", TimeZoneInfo::GetSystemTimeZones()[69].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Boa_Vista", TimeZoneInfo::GetSystemTimeZones()[69].DisplayName());
    ASSERT_EQ("AMST", TimeZoneInfo::GetSystemTimeZones()[69].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[69].BaseUtcOffset().ToString());
    ASSERT_EQ("AMT", TimeZoneInfo::GetSystemTimeZones()[69].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[69].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Bogota) {
    ASSERT_EQ("America/Bogota", TimeZoneInfo::GetSystemTimeZones()[70].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Bogota", TimeZoneInfo::GetSystemTimeZones()[70].DisplayName());
    ASSERT_EQ("COST", TimeZoneInfo::GetSystemTimeZones()[70].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[70].BaseUtcOffset().ToString());
    ASSERT_EQ("COT", TimeZoneInfo::GetSystemTimeZones()[70].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[70].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Boise) {
    ASSERT_EQ("America/Boise", TimeZoneInfo::GetSystemTimeZones()[71].Id());
    ASSERT_EQ("(UTC-07:00:00) America/Boise", TimeZoneInfo::GetSystemTimeZones()[71].DisplayName());
    ASSERT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[71].DaylightName());
    ASSERT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[71].BaseUtcOffset().ToString());
    ASSERT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[71].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[71].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Buenos_Aires) {
    ASSERT_EQ("America/Buenos_Aires", TimeZoneInfo::GetSystemTimeZones()[72].Id());
    ASSERT_EQ("(UTC-03:00:00) America/Buenos_Aires", TimeZoneInfo::GetSystemTimeZones()[72].DisplayName());
    ASSERT_EQ("ARST", TimeZoneInfo::GetSystemTimeZones()[72].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[72].BaseUtcOffset().ToString());
    ASSERT_EQ("ART", TimeZoneInfo::GetSystemTimeZones()[72].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[72].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Cambridge_Bay) {
    ASSERT_EQ("America/Cambridge_Bay", TimeZoneInfo::GetSystemTimeZones()[73].Id());
    ASSERT_EQ("(UTC-07:00:00) America/Cambridge_Bay", TimeZoneInfo::GetSystemTimeZones()[73].DisplayName());
    ASSERT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[73].DaylightName());
    ASSERT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[73].BaseUtcOffset().ToString());
    ASSERT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[73].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[73].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Campo_Grande) {
    ASSERT_EQ("America/Campo_Grande", TimeZoneInfo::GetSystemTimeZones()[74].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Campo_Grande", TimeZoneInfo::GetSystemTimeZones()[74].DisplayName());
    ASSERT_EQ("AMST", TimeZoneInfo::GetSystemTimeZones()[74].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[74].BaseUtcOffset().ToString());
    ASSERT_EQ("AMT", TimeZoneInfo::GetSystemTimeZones()[74].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[74].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Cancun) {
    ASSERT_EQ("America/Cancun", TimeZoneInfo::GetSystemTimeZones()[75].Id());
    ASSERT_EQ("(UTC-06:00:00) America/Cancun", TimeZoneInfo::GetSystemTimeZones()[75].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[75].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[75].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[75].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[75].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Caracas) {
    ASSERT_EQ("America/Caracas", TimeZoneInfo::GetSystemTimeZones()[76].Id());
    ASSERT_EQ("(UTC-04:30:00) America/Caracas", TimeZoneInfo::GetSystemTimeZones()[76].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[76].DaylightName());
    ASSERT_EQ("-04:30:00", TimeZoneInfo::GetSystemTimeZones()[76].BaseUtcOffset().ToString());
    ASSERT_EQ("VET", TimeZoneInfo::GetSystemTimeZones()[76].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[76].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Catamarca) {
    ASSERT_EQ("America/Catamarca", TimeZoneInfo::GetSystemTimeZones()[77].Id());
    ASSERT_EQ("(UTC-03:00:00) America/Catamarca", TimeZoneInfo::GetSystemTimeZones()[77].DisplayName());
    ASSERT_EQ("ARST", TimeZoneInfo::GetSystemTimeZones()[77].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[77].BaseUtcOffset().ToString());
    ASSERT_EQ("ART", TimeZoneInfo::GetSystemTimeZones()[77].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[77].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Cayenne) {
    ASSERT_EQ("America/Cayenne", TimeZoneInfo::GetSystemTimeZones()[78].Id());
    ASSERT_EQ("(UTC-03:00:00) America/Cayenne", TimeZoneInfo::GetSystemTimeZones()[78].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[78].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[78].BaseUtcOffset().ToString());
    ASSERT_EQ("GFT", TimeZoneInfo::GetSystemTimeZones()[78].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[78].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Cayman) {
    ASSERT_EQ("America/Cayman", TimeZoneInfo::GetSystemTimeZones()[79].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Cayman", TimeZoneInfo::GetSystemTimeZones()[79].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[79].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[79].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[79].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[79].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Chicago) {
    ASSERT_EQ("America/Chicago", TimeZoneInfo::GetSystemTimeZones()[80].Id());
    ASSERT_EQ("(UTC-06:00:00) America/Chicago", TimeZoneInfo::GetSystemTimeZones()[80].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[80].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[80].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[80].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[80].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Chihuahua) {
    ASSERT_EQ("America/Chihuahua", TimeZoneInfo::GetSystemTimeZones()[81].Id());
    ASSERT_EQ("(UTC-07:00:00) America/Chihuahua", TimeZoneInfo::GetSystemTimeZones()[81].DisplayName());
    ASSERT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[81].DaylightName());
    ASSERT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[81].BaseUtcOffset().ToString());
    ASSERT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[81].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[81].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Coral_Harbour) {
    ASSERT_EQ("America/Coral_Harbour", TimeZoneInfo::GetSystemTimeZones()[82].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Coral_Harbour", TimeZoneInfo::GetSystemTimeZones()[82].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[82].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[82].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[82].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[82].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Cordoba) {
    ASSERT_EQ("America/Cordoba", TimeZoneInfo::GetSystemTimeZones()[83].Id());
    ASSERT_EQ("(UTC-03:00:00) America/Cordoba", TimeZoneInfo::GetSystemTimeZones()[83].DisplayName());
    ASSERT_EQ("ARST", TimeZoneInfo::GetSystemTimeZones()[83].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[83].BaseUtcOffset().ToString());
    ASSERT_EQ("ART", TimeZoneInfo::GetSystemTimeZones()[83].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[83].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Costa_Rica) {
    ASSERT_EQ("America/Costa_Rica", TimeZoneInfo::GetSystemTimeZones()[84].Id());
    ASSERT_EQ("(UTC-06:00:00) America/Costa_Rica", TimeZoneInfo::GetSystemTimeZones()[84].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[84].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[84].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[84].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[84].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Creston) {
    ASSERT_EQ("America/Creston", TimeZoneInfo::GetSystemTimeZones()[85].Id());
    ASSERT_EQ("(UTC-07:00:00) America/Creston", TimeZoneInfo::GetSystemTimeZones()[85].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[85].DaylightName());
    ASSERT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[85].BaseUtcOffset().ToString());
    ASSERT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[85].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[85].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Cuiaba) {
    ASSERT_EQ("America/Cuiaba", TimeZoneInfo::GetSystemTimeZones()[86].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Cuiaba", TimeZoneInfo::GetSystemTimeZones()[86].DisplayName());
    ASSERT_EQ("AMST", TimeZoneInfo::GetSystemTimeZones()[86].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[86].BaseUtcOffset().ToString());
    ASSERT_EQ("AMT", TimeZoneInfo::GetSystemTimeZones()[86].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[86].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Curacao) {
    ASSERT_EQ("America/Curacao", TimeZoneInfo::GetSystemTimeZones()[87].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Curacao", TimeZoneInfo::GetSystemTimeZones()[87].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[87].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[87].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[87].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[87].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Danmarkshavn) {
    ASSERT_EQ("America/Danmarkshavn", TimeZoneInfo::GetSystemTimeZones()[88].Id());
    ASSERT_EQ("(UTC) America/Danmarkshavn", TimeZoneInfo::GetSystemTimeZones()[88].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[88].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[88].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[88].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[88].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Dawson) {
    ASSERT_EQ("America/Dawson", TimeZoneInfo::GetSystemTimeZones()[89].Id());
    ASSERT_EQ("(UTC-08:00:00) America/Dawson", TimeZoneInfo::GetSystemTimeZones()[89].DisplayName());
    ASSERT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[89].DaylightName());
    ASSERT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[89].BaseUtcOffset().ToString());
    ASSERT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[89].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[89].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Dawson_Creek) {
    ASSERT_EQ("America/Dawson_Creek", TimeZoneInfo::GetSystemTimeZones()[90].Id());
    ASSERT_EQ("(UTC-07:00:00) America/Dawson_Creek", TimeZoneInfo::GetSystemTimeZones()[90].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[90].DaylightName());
    ASSERT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[90].BaseUtcOffset().ToString());
    ASSERT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[90].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[90].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Denver) {
    ASSERT_EQ("America/Denver", TimeZoneInfo::GetSystemTimeZones()[91].Id());
    ASSERT_EQ("(UTC-07:00:00) America/Denver", TimeZoneInfo::GetSystemTimeZones()[91].DisplayName());
    ASSERT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[91].DaylightName());
    ASSERT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[91].BaseUtcOffset().ToString());
    ASSERT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[91].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[91].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Detroit) {
    ASSERT_EQ("America/Detroit", TimeZoneInfo::GetSystemTimeZones()[92].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Detroit", TimeZoneInfo::GetSystemTimeZones()[92].DisplayName());
    ASSERT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[92].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[92].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[92].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[92].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Dominica) {
    ASSERT_EQ("America/Dominica", TimeZoneInfo::GetSystemTimeZones()[93].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Dominica", TimeZoneInfo::GetSystemTimeZones()[93].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[93].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[93].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[93].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[93].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Edmonton) {
    ASSERT_EQ("America/Edmonton", TimeZoneInfo::GetSystemTimeZones()[94].Id());
    ASSERT_EQ("(UTC-07:00:00) America/Edmonton", TimeZoneInfo::GetSystemTimeZones()[94].DisplayName());
    ASSERT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[94].DaylightName());
    ASSERT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[94].BaseUtcOffset().ToString());
    ASSERT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[94].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[94].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Eirunepe) {
    ASSERT_EQ("America/Eirunepe", TimeZoneInfo::GetSystemTimeZones()[95].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Eirunepe", TimeZoneInfo::GetSystemTimeZones()[95].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[95].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[95].BaseUtcOffset().ToString());
    ASSERT_EQ("ACT", TimeZoneInfo::GetSystemTimeZones()[95].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[95].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_El_Salvador) {
    ASSERT_EQ("America/El_Salvador", TimeZoneInfo::GetSystemTimeZones()[96].Id());
    ASSERT_EQ("(UTC-06:00:00) America/El_Salvador", TimeZoneInfo::GetSystemTimeZones()[96].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[96].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[96].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[96].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[96].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Ensenada) {
    ASSERT_EQ("America/Ensenada", TimeZoneInfo::GetSystemTimeZones()[97].Id());
    ASSERT_EQ("(UTC-08:00:00) America/Ensenada", TimeZoneInfo::GetSystemTimeZones()[97].DisplayName());
    ASSERT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[97].DaylightName());
    ASSERT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[97].BaseUtcOffset().ToString());
    ASSERT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[97].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[97].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Fort_Wayne) {
    ASSERT_EQ("America/Fort_Wayne", TimeZoneInfo::GetSystemTimeZones()[98].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Fort_Wayne", TimeZoneInfo::GetSystemTimeZones()[98].DisplayName());
    ASSERT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[98].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[98].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[98].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[98].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Fortaleza) {
    ASSERT_EQ("America/Fortaleza", TimeZoneInfo::GetSystemTimeZones()[99].Id());
    ASSERT_EQ("(UTC-03:00:00) America/Fortaleza", TimeZoneInfo::GetSystemTimeZones()[99].DisplayName());
    ASSERT_EQ("BRST", TimeZoneInfo::GetSystemTimeZones()[99].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[99].BaseUtcOffset().ToString());
    ASSERT_EQ("BRT", TimeZoneInfo::GetSystemTimeZones()[99].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[99].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Glace_Bay) {
    ASSERT_EQ("America/Glace_Bay", TimeZoneInfo::GetSystemTimeZones()[100].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Glace_Bay", TimeZoneInfo::GetSystemTimeZones()[100].DisplayName());
    ASSERT_EQ("ADT", TimeZoneInfo::GetSystemTimeZones()[100].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[100].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[100].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[100].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Godthab) {
    ASSERT_EQ("America/Godthab", TimeZoneInfo::GetSystemTimeZones()[101].Id());
    ASSERT_EQ("(UTC-03:00:00) America/Godthab", TimeZoneInfo::GetSystemTimeZones()[101].DisplayName());
    ASSERT_EQ("WGST", TimeZoneInfo::GetSystemTimeZones()[101].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[101].BaseUtcOffset().ToString());
    ASSERT_EQ("WGT", TimeZoneInfo::GetSystemTimeZones()[101].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[101].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Goose_Bay) {
    ASSERT_EQ("America/Goose_Bay", TimeZoneInfo::GetSystemTimeZones()[102].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Goose_Bay", TimeZoneInfo::GetSystemTimeZones()[102].DisplayName());
    ASSERT_EQ("ADT", TimeZoneInfo::GetSystemTimeZones()[102].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[102].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[102].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[102].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Grand_Turk) {
    ASSERT_EQ("America/Grand_Turk", TimeZoneInfo::GetSystemTimeZones()[103].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Grand_Turk", TimeZoneInfo::GetSystemTimeZones()[103].DisplayName());
    ASSERT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[103].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[103].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[103].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[103].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Grenada) {
    ASSERT_EQ("America/Grenada", TimeZoneInfo::GetSystemTimeZones()[104].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Grenada", TimeZoneInfo::GetSystemTimeZones()[104].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[104].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[104].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[104].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[104].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Guadeloupe) {
    ASSERT_EQ("America/Guadeloupe", TimeZoneInfo::GetSystemTimeZones()[105].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Guadeloupe", TimeZoneInfo::GetSystemTimeZones()[105].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[105].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[105].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[105].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[105].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Guatemala) {
    ASSERT_EQ("America/Guatemala", TimeZoneInfo::GetSystemTimeZones()[106].Id());
    ASSERT_EQ("(UTC-06:00:00) America/Guatemala", TimeZoneInfo::GetSystemTimeZones()[106].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[106].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[106].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[106].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[106].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Guayaquil) {
    ASSERT_EQ("America/Guayaquil", TimeZoneInfo::GetSystemTimeZones()[107].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Guayaquil", TimeZoneInfo::GetSystemTimeZones()[107].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[107].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[107].BaseUtcOffset().ToString());
    ASSERT_EQ("ECT", TimeZoneInfo::GetSystemTimeZones()[107].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[107].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Guyana) {
    ASSERT_EQ("America/Guyana", TimeZoneInfo::GetSystemTimeZones()[108].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Guyana", TimeZoneInfo::GetSystemTimeZones()[108].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[108].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[108].BaseUtcOffset().ToString());
    ASSERT_EQ("GYT", TimeZoneInfo::GetSystemTimeZones()[108].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[108].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Halifax) {
    ASSERT_EQ("America/Halifax", TimeZoneInfo::GetSystemTimeZones()[109].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Halifax", TimeZoneInfo::GetSystemTimeZones()[109].DisplayName());
    ASSERT_EQ("ADT", TimeZoneInfo::GetSystemTimeZones()[109].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[109].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[109].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[109].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Havana) {
    ASSERT_EQ("America/Havana", TimeZoneInfo::GetSystemTimeZones()[110].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Havana", TimeZoneInfo::GetSystemTimeZones()[110].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[110].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[110].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[110].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[110].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Hermosillo) {
    ASSERT_EQ("America/Hermosillo", TimeZoneInfo::GetSystemTimeZones()[111].Id());
    ASSERT_EQ("(UTC-07:00:00) America/Hermosillo", TimeZoneInfo::GetSystemTimeZones()[111].DisplayName());
    ASSERT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[111].DaylightName());
    ASSERT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[111].BaseUtcOffset().ToString());
    ASSERT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[111].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[111].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Indianapolis) {
    ASSERT_EQ("America/Indianapolis", TimeZoneInfo::GetSystemTimeZones()[112].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Indianapolis", TimeZoneInfo::GetSystemTimeZones()[112].DisplayName());
    ASSERT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[112].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[112].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[112].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[112].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Inuvik) {
    ASSERT_EQ("America/Inuvik", TimeZoneInfo::GetSystemTimeZones()[113].Id());
    ASSERT_EQ("(UTC-07:00:00) America/Inuvik", TimeZoneInfo::GetSystemTimeZones()[113].DisplayName());
    ASSERT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[113].DaylightName());
    ASSERT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[113].BaseUtcOffset().ToString());
    ASSERT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[113].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[113].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Iqaluit) {
    ASSERT_EQ("America/Iqaluit", TimeZoneInfo::GetSystemTimeZones()[114].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Iqaluit", TimeZoneInfo::GetSystemTimeZones()[114].DisplayName());
    ASSERT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[114].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[114].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[114].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[114].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Jamaica) {
    ASSERT_EQ("America/Jamaica", TimeZoneInfo::GetSystemTimeZones()[115].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Jamaica", TimeZoneInfo::GetSystemTimeZones()[115].DisplayName());
    ASSERT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[115].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[115].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[115].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[115].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Jujuy) {
    ASSERT_EQ("America/Jujuy", TimeZoneInfo::GetSystemTimeZones()[116].Id());
    ASSERT_EQ("(UTC-03:00:00) America/Jujuy", TimeZoneInfo::GetSystemTimeZones()[116].DisplayName());
    ASSERT_EQ("ARST", TimeZoneInfo::GetSystemTimeZones()[116].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[116].BaseUtcOffset().ToString());
    ASSERT_EQ("ART", TimeZoneInfo::GetSystemTimeZones()[116].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[116].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Juneau) {
    ASSERT_EQ("America/Juneau", TimeZoneInfo::GetSystemTimeZones()[117].Id());
    ASSERT_EQ("(UTC-09:00:00) America/Juneau", TimeZoneInfo::GetSystemTimeZones()[117].DisplayName());
    ASSERT_EQ("AKDT", TimeZoneInfo::GetSystemTimeZones()[117].DaylightName());
    ASSERT_EQ("-09:00:00", TimeZoneInfo::GetSystemTimeZones()[117].BaseUtcOffset().ToString());
    ASSERT_EQ("AKST", TimeZoneInfo::GetSystemTimeZones()[117].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[117].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Knox_IN) {
    ASSERT_EQ("America/Knox_IN", TimeZoneInfo::GetSystemTimeZones()[118].Id());
    ASSERT_EQ("(UTC-06:00:00) America/Knox_IN", TimeZoneInfo::GetSystemTimeZones()[118].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[118].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[118].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[118].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[118].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Kralendijk) {
    ASSERT_EQ("America/Kralendijk", TimeZoneInfo::GetSystemTimeZones()[119].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Kralendijk", TimeZoneInfo::GetSystemTimeZones()[119].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[119].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[119].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[119].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[119].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_La_Paz) {
    ASSERT_EQ("America/La_Paz", TimeZoneInfo::GetSystemTimeZones()[120].Id());
    ASSERT_EQ("(UTC-04:00:00) America/La_Paz", TimeZoneInfo::GetSystemTimeZones()[120].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[120].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[120].BaseUtcOffset().ToString());
    ASSERT_EQ("BOT", TimeZoneInfo::GetSystemTimeZones()[120].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[120].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Lima) {
    ASSERT_EQ("America/Lima", TimeZoneInfo::GetSystemTimeZones()[121].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Lima", TimeZoneInfo::GetSystemTimeZones()[121].DisplayName());
    ASSERT_EQ("PEST", TimeZoneInfo::GetSystemTimeZones()[121].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[121].BaseUtcOffset().ToString());
    ASSERT_EQ("PET", TimeZoneInfo::GetSystemTimeZones()[121].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[121].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Los_Angeles) {
    ASSERT_EQ("America/Los_Angeles", TimeZoneInfo::GetSystemTimeZones()[122].Id());
    ASSERT_EQ("(UTC-08:00:00) America/Los_Angeles", TimeZoneInfo::GetSystemTimeZones()[122].DisplayName());
    ASSERT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[122].DaylightName());
    ASSERT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[122].BaseUtcOffset().ToString());
    ASSERT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[122].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[122].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Louisville) {
    ASSERT_EQ("America/Louisville", TimeZoneInfo::GetSystemTimeZones()[123].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Louisville", TimeZoneInfo::GetSystemTimeZones()[123].DisplayName());
    ASSERT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[123].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[123].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[123].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[123].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Lower_Princes) {
    ASSERT_EQ("America/Lower_Princes", TimeZoneInfo::GetSystemTimeZones()[124].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Lower_Princes", TimeZoneInfo::GetSystemTimeZones()[124].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[124].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[124].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[124].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[124].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Maceio) {
    ASSERT_EQ("America/Maceio", TimeZoneInfo::GetSystemTimeZones()[125].Id());
    ASSERT_EQ("(UTC-03:00:00) America/Maceio", TimeZoneInfo::GetSystemTimeZones()[125].DisplayName());
    ASSERT_EQ("BRST", TimeZoneInfo::GetSystemTimeZones()[125].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[125].BaseUtcOffset().ToString());
    ASSERT_EQ("BRT", TimeZoneInfo::GetSystemTimeZones()[125].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[125].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Managua) {
    ASSERT_EQ("America/Managua", TimeZoneInfo::GetSystemTimeZones()[126].Id());
    ASSERT_EQ("(UTC-06:00:00) America/Managua", TimeZoneInfo::GetSystemTimeZones()[126].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[126].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[126].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[126].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[126].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Manaus) {
    ASSERT_EQ("America/Manaus", TimeZoneInfo::GetSystemTimeZones()[127].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Manaus", TimeZoneInfo::GetSystemTimeZones()[127].DisplayName());
    ASSERT_EQ("AMST", TimeZoneInfo::GetSystemTimeZones()[127].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[127].BaseUtcOffset().ToString());
    ASSERT_EQ("AMT", TimeZoneInfo::GetSystemTimeZones()[127].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[127].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Marigot) {
    ASSERT_EQ("America/Marigot", TimeZoneInfo::GetSystemTimeZones()[128].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Marigot", TimeZoneInfo::GetSystemTimeZones()[128].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[128].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[128].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[128].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[128].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Martinique) {
    ASSERT_EQ("America/Martinique", TimeZoneInfo::GetSystemTimeZones()[129].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Martinique", TimeZoneInfo::GetSystemTimeZones()[129].DisplayName());
    ASSERT_EQ("ADT", TimeZoneInfo::GetSystemTimeZones()[129].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[129].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[129].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[129].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Matamoros) {
    ASSERT_EQ("America/Matamoros", TimeZoneInfo::GetSystemTimeZones()[130].Id());
    ASSERT_EQ("(UTC-06:00:00) America/Matamoros", TimeZoneInfo::GetSystemTimeZones()[130].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[130].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[130].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[130].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[130].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Mazatlan) {
    ASSERT_EQ("America/Mazatlan", TimeZoneInfo::GetSystemTimeZones()[131].Id());
    ASSERT_EQ("(UTC-07:00:00) America/Mazatlan", TimeZoneInfo::GetSystemTimeZones()[131].DisplayName());
    ASSERT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[131].DaylightName());
    ASSERT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[131].BaseUtcOffset().ToString());
    ASSERT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[131].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[131].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Mendoza) {
    ASSERT_EQ("America/Mendoza", TimeZoneInfo::GetSystemTimeZones()[132].Id());
    ASSERT_EQ("(UTC-03:00:00) America/Mendoza", TimeZoneInfo::GetSystemTimeZones()[132].DisplayName());
    ASSERT_EQ("ARST", TimeZoneInfo::GetSystemTimeZones()[132].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[132].BaseUtcOffset().ToString());
    ASSERT_EQ("ART", TimeZoneInfo::GetSystemTimeZones()[132].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[132].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Menominee) {
    ASSERT_EQ("America/Menominee", TimeZoneInfo::GetSystemTimeZones()[133].Id());
    ASSERT_EQ("(UTC-06:00:00) America/Menominee", TimeZoneInfo::GetSystemTimeZones()[133].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[133].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[133].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[133].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[133].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Merida) {
    ASSERT_EQ("America/Merida", TimeZoneInfo::GetSystemTimeZones()[134].Id());
    ASSERT_EQ("(UTC-06:00:00) America/Merida", TimeZoneInfo::GetSystemTimeZones()[134].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[134].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[134].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[134].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[134].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Metlakatla) {
    ASSERT_EQ("America/Metlakatla", TimeZoneInfo::GetSystemTimeZones()[135].Id());
    ASSERT_EQ("(UTC-08:00:00) America/Metlakatla", TimeZoneInfo::GetSystemTimeZones()[135].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[135].DaylightName());
    ASSERT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[135].BaseUtcOffset().ToString());
    ASSERT_EQ("MeST", TimeZoneInfo::GetSystemTimeZones()[135].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[135].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Mexico_City) {
    ASSERT_EQ("America/Mexico_City", TimeZoneInfo::GetSystemTimeZones()[136].Id());
    ASSERT_EQ("(UTC-06:00:00) America/Mexico_City", TimeZoneInfo::GetSystemTimeZones()[136].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[136].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[136].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[136].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[136].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Miquelon) {
    ASSERT_EQ("America/Miquelon", TimeZoneInfo::GetSystemTimeZones()[137].Id());
    ASSERT_EQ("(UTC-03:00:00) America/Miquelon", TimeZoneInfo::GetSystemTimeZones()[137].DisplayName());
    ASSERT_EQ("PMDT", TimeZoneInfo::GetSystemTimeZones()[137].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[137].BaseUtcOffset().ToString());
    ASSERT_EQ("PMST", TimeZoneInfo::GetSystemTimeZones()[137].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[137].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Moncton) {
    ASSERT_EQ("America/Moncton", TimeZoneInfo::GetSystemTimeZones()[138].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Moncton", TimeZoneInfo::GetSystemTimeZones()[138].DisplayName());
    ASSERT_EQ("ADT", TimeZoneInfo::GetSystemTimeZones()[138].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[138].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[138].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[138].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Monterrey) {
    ASSERT_EQ("America/Monterrey", TimeZoneInfo::GetSystemTimeZones()[139].Id());
    ASSERT_EQ("(UTC-06:00:00) America/Monterrey", TimeZoneInfo::GetSystemTimeZones()[139].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[139].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[139].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[139].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[139].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Montevideo) {
    ASSERT_EQ("America/Montevideo", TimeZoneInfo::GetSystemTimeZones()[140].Id());
    ASSERT_EQ("(UTC-03:00:00) America/Montevideo", TimeZoneInfo::GetSystemTimeZones()[140].DisplayName());
    ASSERT_EQ("UYST", TimeZoneInfo::GetSystemTimeZones()[140].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[140].BaseUtcOffset().ToString());
    ASSERT_EQ("UYT", TimeZoneInfo::GetSystemTimeZones()[140].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[140].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Montreal) {
    ASSERT_EQ("America/Montreal", TimeZoneInfo::GetSystemTimeZones()[141].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Montreal", TimeZoneInfo::GetSystemTimeZones()[141].DisplayName());
    ASSERT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[141].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[141].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[141].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[141].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Montserrat) {
    ASSERT_EQ("America/Montserrat", TimeZoneInfo::GetSystemTimeZones()[142].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Montserrat", TimeZoneInfo::GetSystemTimeZones()[142].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[142].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[142].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[142].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[142].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Nassau) {
    ASSERT_EQ("America/Nassau", TimeZoneInfo::GetSystemTimeZones()[143].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Nassau", TimeZoneInfo::GetSystemTimeZones()[143].DisplayName());
    ASSERT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[143].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[143].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[143].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[143].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_New_York) {
    ASSERT_EQ("America/New_York", TimeZoneInfo::GetSystemTimeZones()[144].Id());
    ASSERT_EQ("(UTC-05:00:00) America/New_York", TimeZoneInfo::GetSystemTimeZones()[144].DisplayName());
    ASSERT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[144].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[144].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[144].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[144].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Nipigon) {
    ASSERT_EQ("America/Nipigon", TimeZoneInfo::GetSystemTimeZones()[145].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Nipigon", TimeZoneInfo::GetSystemTimeZones()[145].DisplayName());
    ASSERT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[145].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[145].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[145].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[145].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Nome) {
    ASSERT_EQ("America/Nome", TimeZoneInfo::GetSystemTimeZones()[146].Id());
    ASSERT_EQ("(UTC-09:00:00) America/Nome", TimeZoneInfo::GetSystemTimeZones()[146].DisplayName());
    ASSERT_EQ("AKDT", TimeZoneInfo::GetSystemTimeZones()[146].DaylightName());
    ASSERT_EQ("-09:00:00", TimeZoneInfo::GetSystemTimeZones()[146].BaseUtcOffset().ToString());
    ASSERT_EQ("AKST", TimeZoneInfo::GetSystemTimeZones()[146].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[146].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Noronha) {
    ASSERT_EQ("America/Noronha", TimeZoneInfo::GetSystemTimeZones()[147].Id());
    ASSERT_EQ("(UTC-02:00:00) America/Noronha", TimeZoneInfo::GetSystemTimeZones()[147].DisplayName());
    ASSERT_EQ("FNST", TimeZoneInfo::GetSystemTimeZones()[147].DaylightName());
    ASSERT_EQ("-02:00:00", TimeZoneInfo::GetSystemTimeZones()[147].BaseUtcOffset().ToString());
    ASSERT_EQ("FNT", TimeZoneInfo::GetSystemTimeZones()[147].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[147].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Ojinaga) {
    ASSERT_EQ("America/Ojinaga", TimeZoneInfo::GetSystemTimeZones()[148].Id());
    ASSERT_EQ("(UTC-07:00:00) America/Ojinaga", TimeZoneInfo::GetSystemTimeZones()[148].DisplayName());
    ASSERT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[148].DaylightName());
    ASSERT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[148].BaseUtcOffset().ToString());
    ASSERT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[148].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[148].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Panama) {
    ASSERT_EQ("America/Panama", TimeZoneInfo::GetSystemTimeZones()[149].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Panama", TimeZoneInfo::GetSystemTimeZones()[149].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[149].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[149].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[149].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[149].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Pangnirtung) {
    ASSERT_EQ("America/Pangnirtung", TimeZoneInfo::GetSystemTimeZones()[150].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Pangnirtung", TimeZoneInfo::GetSystemTimeZones()[150].DisplayName());
    ASSERT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[150].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[150].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[150].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[150].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Paramaribo) {
    ASSERT_EQ("America/Paramaribo", TimeZoneInfo::GetSystemTimeZones()[151].Id());
    ASSERT_EQ("(UTC-03:00:00) America/Paramaribo", TimeZoneInfo::GetSystemTimeZones()[151].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[151].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[151].BaseUtcOffset().ToString());
    ASSERT_EQ("SRT", TimeZoneInfo::GetSystemTimeZones()[151].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[151].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Phoenix) {
    ASSERT_EQ("America/Phoenix", TimeZoneInfo::GetSystemTimeZones()[152].Id());
    ASSERT_EQ("(UTC-07:00:00) America/Phoenix", TimeZoneInfo::GetSystemTimeZones()[152].DisplayName());
    ASSERT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[152].DaylightName());
    ASSERT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[152].BaseUtcOffset().ToString());
    ASSERT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[152].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[152].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Port_au_Prince) {
    ASSERT_EQ("America/Port-au-Prince", TimeZoneInfo::GetSystemTimeZones()[153].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Port-au-Prince", TimeZoneInfo::GetSystemTimeZones()[153].DisplayName());
    ASSERT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[153].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[153].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[153].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[153].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Port_of_Spain) {
    ASSERT_EQ("America/Port_of_Spain", TimeZoneInfo::GetSystemTimeZones()[154].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Port_of_Spain", TimeZoneInfo::GetSystemTimeZones()[154].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[154].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[154].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[154].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[154].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Porto_Acre) {
    ASSERT_EQ("America/Porto_Acre", TimeZoneInfo::GetSystemTimeZones()[155].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Porto_Acre", TimeZoneInfo::GetSystemTimeZones()[155].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[155].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[155].BaseUtcOffset().ToString());
    ASSERT_EQ("ACT", TimeZoneInfo::GetSystemTimeZones()[155].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[155].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Porto_Velho) {
    ASSERT_EQ("America/Porto_Velho", TimeZoneInfo::GetSystemTimeZones()[156].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Porto_Velho", TimeZoneInfo::GetSystemTimeZones()[156].DisplayName());
    ASSERT_EQ("AMST", TimeZoneInfo::GetSystemTimeZones()[156].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[156].BaseUtcOffset().ToString());
    ASSERT_EQ("AMT", TimeZoneInfo::GetSystemTimeZones()[156].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[156].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Puerto_Rico) {
    ASSERT_EQ("America/Puerto_Rico", TimeZoneInfo::GetSystemTimeZones()[157].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Puerto_Rico", TimeZoneInfo::GetSystemTimeZones()[157].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[157].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[157].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[157].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[157].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Rainy_River) {
    ASSERT_EQ("America/Rainy_River", TimeZoneInfo::GetSystemTimeZones()[158].Id());
    ASSERT_EQ("(UTC-06:00:00) America/Rainy_River", TimeZoneInfo::GetSystemTimeZones()[158].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[158].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[158].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[158].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[158].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Rankin_Inlet) {
    ASSERT_EQ("America/Rankin_Inlet", TimeZoneInfo::GetSystemTimeZones()[159].Id());
    ASSERT_EQ("(UTC-06:00:00) America/Rankin_Inlet", TimeZoneInfo::GetSystemTimeZones()[159].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[159].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[159].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[159].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[159].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Recife) {
    ASSERT_EQ("America/Recife", TimeZoneInfo::GetSystemTimeZones()[160].Id());
    ASSERT_EQ("(UTC-03:00:00) America/Recife", TimeZoneInfo::GetSystemTimeZones()[160].DisplayName());
    ASSERT_EQ("BRST", TimeZoneInfo::GetSystemTimeZones()[160].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[160].BaseUtcOffset().ToString());
    ASSERT_EQ("BRT", TimeZoneInfo::GetSystemTimeZones()[160].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[160].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Regina) {
    ASSERT_EQ("America/Regina", TimeZoneInfo::GetSystemTimeZones()[161].Id());
    ASSERT_EQ("(UTC-06:00:00) America/Regina", TimeZoneInfo::GetSystemTimeZones()[161].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[161].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[161].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[161].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[161].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Resolute) {
    ASSERT_EQ("America/Resolute", TimeZoneInfo::GetSystemTimeZones()[162].Id());
    ASSERT_EQ("(UTC-06:00:00) America/Resolute", TimeZoneInfo::GetSystemTimeZones()[162].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[162].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[162].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[162].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[162].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Rio_Branco) {
    ASSERT_EQ("America/Rio_Branco", TimeZoneInfo::GetSystemTimeZones()[163].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Rio_Branco", TimeZoneInfo::GetSystemTimeZones()[163].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[163].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[163].BaseUtcOffset().ToString());
    ASSERT_EQ("ACT", TimeZoneInfo::GetSystemTimeZones()[163].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[163].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Rosario) {
    ASSERT_EQ("America/Rosario", TimeZoneInfo::GetSystemTimeZones()[164].Id());
    ASSERT_EQ("(UTC-03:00:00) America/Rosario", TimeZoneInfo::GetSystemTimeZones()[164].DisplayName());
    ASSERT_EQ("ARST", TimeZoneInfo::GetSystemTimeZones()[164].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[164].BaseUtcOffset().ToString());
    ASSERT_EQ("ART", TimeZoneInfo::GetSystemTimeZones()[164].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[164].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Santa_Isabel) {
    ASSERT_EQ("America/Santa_Isabel", TimeZoneInfo::GetSystemTimeZones()[165].Id());
    ASSERT_EQ("(UTC-08:00:00) America/Santa_Isabel", TimeZoneInfo::GetSystemTimeZones()[165].DisplayName());
    ASSERT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[165].DaylightName());
    ASSERT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[165].BaseUtcOffset().ToString());
    ASSERT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[165].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[165].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Santarem) {
    ASSERT_EQ("America/Santarem", TimeZoneInfo::GetSystemTimeZones()[166].Id());
    ASSERT_EQ("(UTC-03:00:00) America/Santarem", TimeZoneInfo::GetSystemTimeZones()[166].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[166].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[166].BaseUtcOffset().ToString());
    ASSERT_EQ("BRT", TimeZoneInfo::GetSystemTimeZones()[166].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[166].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Santiago) {
    ASSERT_EQ("America/Santiago", TimeZoneInfo::GetSystemTimeZones()[167].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Santiago", TimeZoneInfo::GetSystemTimeZones()[167].DisplayName());
    ASSERT_EQ("CLST", TimeZoneInfo::GetSystemTimeZones()[167].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[167].BaseUtcOffset().ToString());
    ASSERT_EQ("CLT", TimeZoneInfo::GetSystemTimeZones()[167].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[167].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Santo_Domingo) {
    ASSERT_EQ("America/Santo_Domingo", TimeZoneInfo::GetSystemTimeZones()[168].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Santo_Domingo", TimeZoneInfo::GetSystemTimeZones()[168].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[168].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[168].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[168].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[168].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Sao_Paulo) {
    ASSERT_EQ("America/Sao_Paulo", TimeZoneInfo::GetSystemTimeZones()[169].Id());
    ASSERT_EQ("(UTC-03:00:00) America/Sao_Paulo", TimeZoneInfo::GetSystemTimeZones()[169].DisplayName());
    ASSERT_EQ("BRST", TimeZoneInfo::GetSystemTimeZones()[169].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[169].BaseUtcOffset().ToString());
    ASSERT_EQ("BRT", TimeZoneInfo::GetSystemTimeZones()[169].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[169].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Scoresbysund) {
    ASSERT_EQ("America/Scoresbysund", TimeZoneInfo::GetSystemTimeZones()[170].Id());
    ASSERT_EQ("(UTC-01:00:00) America/Scoresbysund", TimeZoneInfo::GetSystemTimeZones()[170].DisplayName());
    ASSERT_EQ("EGST", TimeZoneInfo::GetSystemTimeZones()[170].DaylightName());
    ASSERT_EQ("-01:00:00", TimeZoneInfo::GetSystemTimeZones()[170].BaseUtcOffset().ToString());
    ASSERT_EQ("EGT", TimeZoneInfo::GetSystemTimeZones()[170].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[170].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Shiprock) {
    ASSERT_EQ("America/Shiprock", TimeZoneInfo::GetSystemTimeZones()[171].Id());
    ASSERT_EQ("(UTC-07:00:00) America/Shiprock", TimeZoneInfo::GetSystemTimeZones()[171].DisplayName());
    ASSERT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[171].DaylightName());
    ASSERT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[171].BaseUtcOffset().ToString());
    ASSERT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[171].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[171].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Sitka) {
    ASSERT_EQ("America/Sitka", TimeZoneInfo::GetSystemTimeZones()[172].Id());
    ASSERT_EQ("(UTC-09:00:00) America/Sitka", TimeZoneInfo::GetSystemTimeZones()[172].DisplayName());
    ASSERT_EQ("AKDT", TimeZoneInfo::GetSystemTimeZones()[172].DaylightName());
    ASSERT_EQ("-09:00:00", TimeZoneInfo::GetSystemTimeZones()[172].BaseUtcOffset().ToString());
    ASSERT_EQ("AKST", TimeZoneInfo::GetSystemTimeZones()[172].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[172].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_St_Barthelemy) {
    ASSERT_EQ("America/St_Barthelemy", TimeZoneInfo::GetSystemTimeZones()[173].Id());
    ASSERT_EQ("(UTC-04:00:00) America/St_Barthelemy", TimeZoneInfo::GetSystemTimeZones()[173].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[173].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[173].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[173].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[173].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_St_Johns) {
    ASSERT_EQ("America/St_Johns", TimeZoneInfo::GetSystemTimeZones()[174].Id());
    ASSERT_EQ("(UTC-03:30:00) America/St_Johns", TimeZoneInfo::GetSystemTimeZones()[174].DisplayName());
    ASSERT_EQ("NDT", TimeZoneInfo::GetSystemTimeZones()[174].DaylightName());
    ASSERT_EQ("-03:30:00", TimeZoneInfo::GetSystemTimeZones()[174].BaseUtcOffset().ToString());
    ASSERT_EQ("NST", TimeZoneInfo::GetSystemTimeZones()[174].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[174].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_St_Kitts) {
    ASSERT_EQ("America/St_Kitts", TimeZoneInfo::GetSystemTimeZones()[175].Id());
    ASSERT_EQ("(UTC-04:00:00) America/St_Kitts", TimeZoneInfo::GetSystemTimeZones()[175].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[175].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[175].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[175].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[175].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_St_Lucia) {
    ASSERT_EQ("America/St_Lucia", TimeZoneInfo::GetSystemTimeZones()[176].Id());
    ASSERT_EQ("(UTC-04:00:00) America/St_Lucia", TimeZoneInfo::GetSystemTimeZones()[176].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[176].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[176].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[176].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[176].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_St_Thomas) {
    ASSERT_EQ("America/St_Thomas", TimeZoneInfo::GetSystemTimeZones()[177].Id());
    ASSERT_EQ("(UTC-04:00:00) America/St_Thomas", TimeZoneInfo::GetSystemTimeZones()[177].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[177].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[177].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[177].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[177].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_St_Vincent) {
    ASSERT_EQ("America/St_Vincent", TimeZoneInfo::GetSystemTimeZones()[178].Id());
    ASSERT_EQ("(UTC-04:00:00) America/St_Vincent", TimeZoneInfo::GetSystemTimeZones()[178].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[178].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[178].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[178].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[178].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Swift_Current) {
    ASSERT_EQ("America/Swift_Current", TimeZoneInfo::GetSystemTimeZones()[179].Id());
    ASSERT_EQ("(UTC-06:00:00) America/Swift_Current", TimeZoneInfo::GetSystemTimeZones()[179].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[179].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[179].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[179].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[179].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Tegucigalpa) {
    ASSERT_EQ("America/Tegucigalpa", TimeZoneInfo::GetSystemTimeZones()[180].Id());
    ASSERT_EQ("(UTC-06:00:00) America/Tegucigalpa", TimeZoneInfo::GetSystemTimeZones()[180].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[180].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[180].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[180].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[180].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Thule) {
    ASSERT_EQ("America/Thule", TimeZoneInfo::GetSystemTimeZones()[181].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Thule", TimeZoneInfo::GetSystemTimeZones()[181].DisplayName());
    ASSERT_EQ("ADT", TimeZoneInfo::GetSystemTimeZones()[181].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[181].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[181].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[181].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Thunder_Bay) {
    ASSERT_EQ("America/Thunder_Bay", TimeZoneInfo::GetSystemTimeZones()[182].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Thunder_Bay", TimeZoneInfo::GetSystemTimeZones()[182].DisplayName());
    ASSERT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[182].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[182].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[182].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[182].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Tijuana) {
    ASSERT_EQ("America/Tijuana", TimeZoneInfo::GetSystemTimeZones()[183].Id());
    ASSERT_EQ("(UTC-08:00:00) America/Tijuana", TimeZoneInfo::GetSystemTimeZones()[183].DisplayName());
    ASSERT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[183].DaylightName());
    ASSERT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[183].BaseUtcOffset().ToString());
    ASSERT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[183].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[183].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Toronto) {
    ASSERT_EQ("America/Toronto", TimeZoneInfo::GetSystemTimeZones()[184].Id());
    ASSERT_EQ("(UTC-05:00:00) America/Toronto", TimeZoneInfo::GetSystemTimeZones()[184].DisplayName());
    ASSERT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[184].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[184].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[184].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[184].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Tortola) {
    ASSERT_EQ("America/Tortola", TimeZoneInfo::GetSystemTimeZones()[185].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Tortola", TimeZoneInfo::GetSystemTimeZones()[185].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[185].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[185].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[185].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[185].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Vancouver) {
    ASSERT_EQ("America/Vancouver", TimeZoneInfo::GetSystemTimeZones()[186].Id());
    ASSERT_EQ("(UTC-08:00:00) America/Vancouver", TimeZoneInfo::GetSystemTimeZones()[186].DisplayName());
    ASSERT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[186].DaylightName());
    ASSERT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[186].BaseUtcOffset().ToString());
    ASSERT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[186].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[186].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Virgin) {
    ASSERT_EQ("America/Virgin", TimeZoneInfo::GetSystemTimeZones()[187].Id());
    ASSERT_EQ("(UTC-04:00:00) America/Virgin", TimeZoneInfo::GetSystemTimeZones()[187].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[187].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[187].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[187].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[187].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Whitehorse) {
    ASSERT_EQ("America/Whitehorse", TimeZoneInfo::GetSystemTimeZones()[188].Id());
    ASSERT_EQ("(UTC-08:00:00) America/Whitehorse", TimeZoneInfo::GetSystemTimeZones()[188].DisplayName());
    ASSERT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[188].DaylightName());
    ASSERT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[188].BaseUtcOffset().ToString());
    ASSERT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[188].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[188].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Winnipeg) {
    ASSERT_EQ("America/Winnipeg", TimeZoneInfo::GetSystemTimeZones()[189].Id());
    ASSERT_EQ("(UTC-06:00:00) America/Winnipeg", TimeZoneInfo::GetSystemTimeZones()[189].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[189].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[189].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[189].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[189].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Yakutat) {
    ASSERT_EQ("America/Yakutat", TimeZoneInfo::GetSystemTimeZones()[190].Id());
    ASSERT_EQ("(UTC-09:00:00) America/Yakutat", TimeZoneInfo::GetSystemTimeZones()[190].DisplayName());
    ASSERT_EQ("AKDT", TimeZoneInfo::GetSystemTimeZones()[190].DaylightName());
    ASSERT_EQ("-09:00:00", TimeZoneInfo::GetSystemTimeZones()[190].BaseUtcOffset().ToString());
    ASSERT_EQ("AKST", TimeZoneInfo::GetSystemTimeZones()[190].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[190].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAmerica_Yellowknife) {
    ASSERT_EQ("America/Yellowknife", TimeZoneInfo::GetSystemTimeZones()[191].Id());
    ASSERT_EQ("(UTC-07:00:00) America/Yellowknife", TimeZoneInfo::GetSystemTimeZones()[191].DisplayName());
    ASSERT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[191].DaylightName());
    ASSERT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[191].BaseUtcOffset().ToString());
    ASSERT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[191].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[191].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAntarctica_Casey) {
    ASSERT_EQ("Antarctica/Casey", TimeZoneInfo::GetSystemTimeZones()[192].Id());
    ASSERT_EQ("(UTC+08:00:00) Antarctica/Casey", TimeZoneInfo::GetSystemTimeZones()[192].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[192].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[192].BaseUtcOffset().ToString());
    ASSERT_EQ("WST", TimeZoneInfo::GetSystemTimeZones()[192].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[192].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAntarctica_Davis) {
    ASSERT_EQ("Antarctica/Davis", TimeZoneInfo::GetSystemTimeZones()[193].Id());
    ASSERT_EQ("(UTC+07:00:00) Antarctica/Davis", TimeZoneInfo::GetSystemTimeZones()[193].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[193].DaylightName());
    ASSERT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[193].BaseUtcOffset().ToString());
    ASSERT_EQ("DAVT", TimeZoneInfo::GetSystemTimeZones()[193].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[193].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAntarctica_DumontDUrville) {
    ASSERT_EQ("Antarctica/DumontDUrville", TimeZoneInfo::GetSystemTimeZones()[194].Id());
    ASSERT_EQ("(UTC+10:00:00) Antarctica/DumontDUrville", TimeZoneInfo::GetSystemTimeZones()[194].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[194].DaylightName());
    ASSERT_EQ("10:00:00", TimeZoneInfo::GetSystemTimeZones()[194].BaseUtcOffset().ToString());
    ASSERT_EQ("DDUT", TimeZoneInfo::GetSystemTimeZones()[194].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[194].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAntarctica_Macquarie) {
    ASSERT_EQ("Antarctica/Macquarie", TimeZoneInfo::GetSystemTimeZones()[195].Id());
    ASSERT_EQ("(UTC+11:00:00) Antarctica/Macquarie", TimeZoneInfo::GetSystemTimeZones()[195].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[195].DaylightName());
    ASSERT_EQ("11:00:00", TimeZoneInfo::GetSystemTimeZones()[195].BaseUtcOffset().ToString());
    ASSERT_EQ("MIST", TimeZoneInfo::GetSystemTimeZones()[195].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[195].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAntarctica_Mawson) {
    ASSERT_EQ("Antarctica/Mawson", TimeZoneInfo::GetSystemTimeZones()[196].Id());
    ASSERT_EQ("(UTC+05:00:00) Antarctica/Mawson", TimeZoneInfo::GetSystemTimeZones()[196].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[196].DaylightName());
    ASSERT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[196].BaseUtcOffset().ToString());
    ASSERT_EQ("MAWT", TimeZoneInfo::GetSystemTimeZones()[196].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[196].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAntarctica_McMurdo) {
    ASSERT_EQ("Antarctica/McMurdo", TimeZoneInfo::GetSystemTimeZones()[197].Id());
    ASSERT_EQ("(UTC+12:00:00) Antarctica/McMurdo", TimeZoneInfo::GetSystemTimeZones()[197].DisplayName());
    ASSERT_EQ("NZDT", TimeZoneInfo::GetSystemTimeZones()[197].DaylightName());
    ASSERT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[197].BaseUtcOffset().ToString());
    ASSERT_EQ("NZST", TimeZoneInfo::GetSystemTimeZones()[197].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[197].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAntarctica_Palmer) {
    ASSERT_EQ("Antarctica/Palmer", TimeZoneInfo::GetSystemTimeZones()[198].Id());
    ASSERT_EQ("(UTC-04:00:00) Antarctica/Palmer", TimeZoneInfo::GetSystemTimeZones()[198].DisplayName());
    ASSERT_EQ("CLST", TimeZoneInfo::GetSystemTimeZones()[198].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[198].BaseUtcOffset().ToString());
    ASSERT_EQ("CLT", TimeZoneInfo::GetSystemTimeZones()[198].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[198].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAntarctica_Rothera) {
    ASSERT_EQ("Antarctica/Rothera", TimeZoneInfo::GetSystemTimeZones()[199].Id());
    ASSERT_EQ("(UTC-03:00:00) Antarctica/Rothera", TimeZoneInfo::GetSystemTimeZones()[199].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[199].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[199].BaseUtcOffset().ToString());
    ASSERT_EQ("ROTT", TimeZoneInfo::GetSystemTimeZones()[199].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[199].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAntarctica_South_Pole) {
    ASSERT_EQ("Antarctica/South_Pole", TimeZoneInfo::GetSystemTimeZones()[200].Id());
    ASSERT_EQ("(UTC+12:00:00) Antarctica/South_Pole", TimeZoneInfo::GetSystemTimeZones()[200].DisplayName());
    ASSERT_EQ("NZDT", TimeZoneInfo::GetSystemTimeZones()[200].DaylightName());
    ASSERT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[200].BaseUtcOffset().ToString());
    ASSERT_EQ("NZST", TimeZoneInfo::GetSystemTimeZones()[200].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[200].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAntarctica_Syowa) {
    ASSERT_EQ("Antarctica/Syowa", TimeZoneInfo::GetSystemTimeZones()[201].Id());
    ASSERT_EQ("(UTC+03:00:00) Antarctica/Syowa", TimeZoneInfo::GetSystemTimeZones()[201].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[201].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[201].BaseUtcOffset().ToString());
    ASSERT_EQ("SYOT", TimeZoneInfo::GetSystemTimeZones()[201].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[201].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAntarctica_Vostok) {
    ASSERT_EQ("Antarctica/Vostok", TimeZoneInfo::GetSystemTimeZones()[202].Id());
    ASSERT_EQ("(UTC+06:00:00) Antarctica/Vostok", TimeZoneInfo::GetSystemTimeZones()[202].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[202].DaylightName());
    ASSERT_EQ("06:00:00", TimeZoneInfo::GetSystemTimeZones()[202].BaseUtcOffset().ToString());
    ASSERT_EQ("VOST", TimeZoneInfo::GetSystemTimeZones()[202].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[202].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesArctic_Longyearbyen) {
    ASSERT_EQ("Arctic/Longyearbyen", TimeZoneInfo::GetSystemTimeZones()[203].Id());
    ASSERT_EQ("(UTC+01:00:00) Arctic/Longyearbyen", TimeZoneInfo::GetSystemTimeZones()[203].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[203].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[203].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[203].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[203].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Aden) {
    ASSERT_EQ("Asia/Aden", TimeZoneInfo::GetSystemTimeZones()[204].Id());
    ASSERT_EQ("(UTC+03:00:00) Asia/Aden", TimeZoneInfo::GetSystemTimeZones()[204].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[204].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[204].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[204].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[204].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Almaty) {
    ASSERT_EQ("Asia/Almaty", TimeZoneInfo::GetSystemTimeZones()[205].Id());
    ASSERT_EQ("(UTC+06:00:00) Asia/Almaty", TimeZoneInfo::GetSystemTimeZones()[205].DisplayName());
    ASSERT_EQ("ALMST", TimeZoneInfo::GetSystemTimeZones()[205].DaylightName());
    ASSERT_EQ("06:00:00", TimeZoneInfo::GetSystemTimeZones()[205].BaseUtcOffset().ToString());
    ASSERT_EQ("ALMT", TimeZoneInfo::GetSystemTimeZones()[205].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[205].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Amman) {
    ASSERT_EQ("Asia/Amman", TimeZoneInfo::GetSystemTimeZones()[206].Id());
    ASSERT_EQ("(UTC+02:00:00) Asia/Amman", TimeZoneInfo::GetSystemTimeZones()[206].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[206].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[206].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[206].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[206].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Anadyr) {
    ASSERT_EQ("Asia/Anadyr", TimeZoneInfo::GetSystemTimeZones()[207].Id());
    ASSERT_EQ("(UTC+12:00:00) Asia/Anadyr", TimeZoneInfo::GetSystemTimeZones()[207].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[207].DaylightName());
    ASSERT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[207].BaseUtcOffset().ToString());
    ASSERT_EQ("ANAT", TimeZoneInfo::GetSystemTimeZones()[207].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[207].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Aqtau) {
    ASSERT_EQ("Asia/Aqtau", TimeZoneInfo::GetSystemTimeZones()[208].Id());
    ASSERT_EQ("(UTC+05:00:00) Asia/Aqtau", TimeZoneInfo::GetSystemTimeZones()[208].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[208].DaylightName());
    ASSERT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[208].BaseUtcOffset().ToString());
    ASSERT_EQ("AQTT", TimeZoneInfo::GetSystemTimeZones()[208].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[208].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Aqtobe) {
    ASSERT_EQ("Asia/Aqtobe", TimeZoneInfo::GetSystemTimeZones()[209].Id());
    ASSERT_EQ("(UTC+05:00:00) Asia/Aqtobe", TimeZoneInfo::GetSystemTimeZones()[209].DisplayName());
    ASSERT_EQ("AQTST", TimeZoneInfo::GetSystemTimeZones()[209].DaylightName());
    ASSERT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[209].BaseUtcOffset().ToString());
    ASSERT_EQ("AQTT", TimeZoneInfo::GetSystemTimeZones()[209].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[209].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Ashgabat) {
    ASSERT_EQ("Asia/Ashgabat", TimeZoneInfo::GetSystemTimeZones()[210].Id());
    ASSERT_EQ("(UTC+05:00:00) Asia/Ashgabat", TimeZoneInfo::GetSystemTimeZones()[210].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[210].DaylightName());
    ASSERT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[210].BaseUtcOffset().ToString());
    ASSERT_EQ("TMT", TimeZoneInfo::GetSystemTimeZones()[210].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[210].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Ashkhabad) {
    ASSERT_EQ("Asia/Ashkhabad", TimeZoneInfo::GetSystemTimeZones()[211].Id());
    ASSERT_EQ("(UTC+05:00:00) Asia/Ashkhabad", TimeZoneInfo::GetSystemTimeZones()[211].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[211].DaylightName());
    ASSERT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[211].BaseUtcOffset().ToString());
    ASSERT_EQ("TMT", TimeZoneInfo::GetSystemTimeZones()[211].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[211].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Baghdad) {
    ASSERT_EQ("Asia/Baghdad", TimeZoneInfo::GetSystemTimeZones()[212].Id());
    ASSERT_EQ("(UTC+03:00:00) Asia/Baghdad", TimeZoneInfo::GetSystemTimeZones()[212].DisplayName());
    ASSERT_EQ("ADT", TimeZoneInfo::GetSystemTimeZones()[212].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[212].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[212].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[212].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Bahrain) {
    ASSERT_EQ("Asia/Bahrain", TimeZoneInfo::GetSystemTimeZones()[213].Id());
    ASSERT_EQ("(UTC+03:00:00) Asia/Bahrain", TimeZoneInfo::GetSystemTimeZones()[213].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[213].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[213].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[213].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[213].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Baku) {
    ASSERT_EQ("Asia/Baku", TimeZoneInfo::GetSystemTimeZones()[214].Id());
    ASSERT_EQ("(UTC+04:00:00) Asia/Baku", TimeZoneInfo::GetSystemTimeZones()[214].DisplayName());
    ASSERT_EQ("AZST", TimeZoneInfo::GetSystemTimeZones()[214].DaylightName());
    ASSERT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[214].BaseUtcOffset().ToString());
    ASSERT_EQ("AZT", TimeZoneInfo::GetSystemTimeZones()[214].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[214].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Bangkok) {
    ASSERT_EQ("Asia/Bangkok", TimeZoneInfo::GetSystemTimeZones()[215].Id());
    ASSERT_EQ("(UTC+07:00:00) Asia/Bangkok", TimeZoneInfo::GetSystemTimeZones()[215].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[215].DaylightName());
    ASSERT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[215].BaseUtcOffset().ToString());
    ASSERT_EQ("ICT", TimeZoneInfo::GetSystemTimeZones()[215].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[215].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Beirut) {
    ASSERT_EQ("Asia/Beirut", TimeZoneInfo::GetSystemTimeZones()[216].Id());
    ASSERT_EQ("(UTC+02:00:00) Asia/Beirut", TimeZoneInfo::GetSystemTimeZones()[216].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[216].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[216].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[216].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[216].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Bishkek) {
    ASSERT_EQ("Asia/Bishkek", TimeZoneInfo::GetSystemTimeZones()[217].Id());
    ASSERT_EQ("(UTC+06:00:00) Asia/Bishkek", TimeZoneInfo::GetSystemTimeZones()[217].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[217].DaylightName());
    ASSERT_EQ("06:00:00", TimeZoneInfo::GetSystemTimeZones()[217].BaseUtcOffset().ToString());
    ASSERT_EQ("KGT", TimeZoneInfo::GetSystemTimeZones()[217].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[217].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Brunei) {
    ASSERT_EQ("Asia/Brunei", TimeZoneInfo::GetSystemTimeZones()[218].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Brunei", TimeZoneInfo::GetSystemTimeZones()[218].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[218].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[218].BaseUtcOffset().ToString());
    ASSERT_EQ("BNT", TimeZoneInfo::GetSystemTimeZones()[218].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[218].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Calcutta) {
    ASSERT_EQ("Asia/Calcutta", TimeZoneInfo::GetSystemTimeZones()[219].Id());
    ASSERT_EQ("(UTC+05:30:00) Asia/Calcutta", TimeZoneInfo::GetSystemTimeZones()[219].DisplayName());
    ASSERT_EQ("IST", TimeZoneInfo::GetSystemTimeZones()[219].DaylightName());
    ASSERT_EQ("05:30:00", TimeZoneInfo::GetSystemTimeZones()[219].BaseUtcOffset().ToString());
    ASSERT_EQ("IST", TimeZoneInfo::GetSystemTimeZones()[219].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[219].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Choibalsan) {
    ASSERT_EQ("Asia/Choibalsan", TimeZoneInfo::GetSystemTimeZones()[220].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Choibalsan", TimeZoneInfo::GetSystemTimeZones()[220].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[220].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[220].BaseUtcOffset().ToString());
    ASSERT_EQ("CHOT", TimeZoneInfo::GetSystemTimeZones()[220].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[220].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Chongqing) {
    ASSERT_EQ("Asia/Chongqing", TimeZoneInfo::GetSystemTimeZones()[221].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Chongqing", TimeZoneInfo::GetSystemTimeZones()[221].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[221].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[221].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[221].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[221].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Chungking) {
    ASSERT_EQ("Asia/Chungking", TimeZoneInfo::GetSystemTimeZones()[222].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Chungking", TimeZoneInfo::GetSystemTimeZones()[222].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[222].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[222].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[222].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[222].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Colombo) {
    ASSERT_EQ("Asia/Colombo", TimeZoneInfo::GetSystemTimeZones()[223].Id());
    ASSERT_EQ("(UTC+05:30:00) Asia/Colombo", TimeZoneInfo::GetSystemTimeZones()[223].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[223].DaylightName());
    ASSERT_EQ("05:30:00", TimeZoneInfo::GetSystemTimeZones()[223].BaseUtcOffset().ToString());
    ASSERT_EQ("IST", TimeZoneInfo::GetSystemTimeZones()[223].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[223].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Dacca) {
    ASSERT_EQ("Asia/Dacca", TimeZoneInfo::GetSystemTimeZones()[224].Id());
    ASSERT_EQ("(UTC+06:00:00) Asia/Dacca", TimeZoneInfo::GetSystemTimeZones()[224].DisplayName());
    ASSERT_EQ("BDST", TimeZoneInfo::GetSystemTimeZones()[224].DaylightName());
    ASSERT_EQ("06:00:00", TimeZoneInfo::GetSystemTimeZones()[224].BaseUtcOffset().ToString());
    ASSERT_EQ("BDT", TimeZoneInfo::GetSystemTimeZones()[224].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[224].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Damascus) {
    ASSERT_EQ("Asia/Damascus", TimeZoneInfo::GetSystemTimeZones()[225].Id());
    ASSERT_EQ("(UTC+02:00:00) Asia/Damascus", TimeZoneInfo::GetSystemTimeZones()[225].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[225].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[225].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[225].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[225].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Dhaka) {
    ASSERT_EQ("Asia/Dhaka", TimeZoneInfo::GetSystemTimeZones()[226].Id());
    ASSERT_EQ("(UTC+06:00:00) Asia/Dhaka", TimeZoneInfo::GetSystemTimeZones()[226].DisplayName());
    ASSERT_EQ("BDST", TimeZoneInfo::GetSystemTimeZones()[226].DaylightName());
    ASSERT_EQ("06:00:00", TimeZoneInfo::GetSystemTimeZones()[226].BaseUtcOffset().ToString());
    ASSERT_EQ("BDT", TimeZoneInfo::GetSystemTimeZones()[226].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[226].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Dili) {
    ASSERT_EQ("Asia/Dili", TimeZoneInfo::GetSystemTimeZones()[227].Id());
    ASSERT_EQ("(UTC+09:00:00) Asia/Dili", TimeZoneInfo::GetSystemTimeZones()[227].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[227].DaylightName());
    ASSERT_EQ("09:00:00", TimeZoneInfo::GetSystemTimeZones()[227].BaseUtcOffset().ToString());
    ASSERT_EQ("TLT", TimeZoneInfo::GetSystemTimeZones()[227].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[227].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Dubai) {
    ASSERT_EQ("Asia/Dubai", TimeZoneInfo::GetSystemTimeZones()[228].Id());
    ASSERT_EQ("(UTC+04:00:00) Asia/Dubai", TimeZoneInfo::GetSystemTimeZones()[228].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[228].DaylightName());
    ASSERT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[228].BaseUtcOffset().ToString());
    ASSERT_EQ("GST", TimeZoneInfo::GetSystemTimeZones()[228].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[228].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Dushanbe) {
    ASSERT_EQ("Asia/Dushanbe", TimeZoneInfo::GetSystemTimeZones()[229].Id());
    ASSERT_EQ("(UTC+05:00:00) Asia/Dushanbe", TimeZoneInfo::GetSystemTimeZones()[229].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[229].DaylightName());
    ASSERT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[229].BaseUtcOffset().ToString());
    ASSERT_EQ("TJT", TimeZoneInfo::GetSystemTimeZones()[229].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[229].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Gaza) {
    ASSERT_EQ("Asia/Gaza", TimeZoneInfo::GetSystemTimeZones()[230].Id());
    ASSERT_EQ("(UTC+02:00:00) Asia/Gaza", TimeZoneInfo::GetSystemTimeZones()[230].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[230].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[230].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[230].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[230].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Harbin) {
    ASSERT_EQ("Asia/Harbin", TimeZoneInfo::GetSystemTimeZones()[231].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Harbin", TimeZoneInfo::GetSystemTimeZones()[231].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[231].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[231].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[231].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[231].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Hebron) {
    ASSERT_EQ("Asia/Hebron", TimeZoneInfo::GetSystemTimeZones()[232].Id());
    ASSERT_EQ("(UTC+02:00:00) Asia/Hebron", TimeZoneInfo::GetSystemTimeZones()[232].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[232].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[232].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[232].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[232].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Ho_Chi_Minh) {
    ASSERT_EQ("Asia/Ho_Chi_Minh", TimeZoneInfo::GetSystemTimeZones()[233].Id());
    ASSERT_EQ("(UTC+07:00:00) Asia/Ho_Chi_Minh", TimeZoneInfo::GetSystemTimeZones()[233].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[233].DaylightName());
    ASSERT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[233].BaseUtcOffset().ToString());
    ASSERT_EQ("ICT", TimeZoneInfo::GetSystemTimeZones()[233].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[233].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Hong_Kong) {
    ASSERT_EQ("Asia/Hong_Kong", TimeZoneInfo::GetSystemTimeZones()[234].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Hong_Kong", TimeZoneInfo::GetSystemTimeZones()[234].DisplayName());
    ASSERT_EQ("HKST", TimeZoneInfo::GetSystemTimeZones()[234].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[234].BaseUtcOffset().ToString());
    ASSERT_EQ("HKT", TimeZoneInfo::GetSystemTimeZones()[234].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[234].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Hovd) {
    ASSERT_EQ("Asia/Hovd", TimeZoneInfo::GetSystemTimeZones()[235].Id());
    ASSERT_EQ("(UTC+07:00:00) Asia/Hovd", TimeZoneInfo::GetSystemTimeZones()[235].DisplayName());
    ASSERT_EQ("HOVST", TimeZoneInfo::GetSystemTimeZones()[235].DaylightName());
    ASSERT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[235].BaseUtcOffset().ToString());
    ASSERT_EQ("HOVT", TimeZoneInfo::GetSystemTimeZones()[235].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[235].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Irkutsk) {
    ASSERT_EQ("Asia/Irkutsk", TimeZoneInfo::GetSystemTimeZones()[236].Id());
    ASSERT_EQ("(UTC+09:00:00) Asia/Irkutsk", TimeZoneInfo::GetSystemTimeZones()[236].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[236].DaylightName());
    ASSERT_EQ("09:00:00", TimeZoneInfo::GetSystemTimeZones()[236].BaseUtcOffset().ToString());
    ASSERT_EQ("IRKT", TimeZoneInfo::GetSystemTimeZones()[236].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[236].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Istanbul) {
    ASSERT_EQ("Asia/Istanbul", TimeZoneInfo::GetSystemTimeZones()[237].Id());
    ASSERT_EQ("(UTC+02:00:00) Asia/Istanbul", TimeZoneInfo::GetSystemTimeZones()[237].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[237].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[237].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[237].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[237].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Jakarta) {
    ASSERT_EQ("Asia/Jakarta", TimeZoneInfo::GetSystemTimeZones()[238].Id());
    ASSERT_EQ("(UTC+07:00:00) Asia/Jakarta", TimeZoneInfo::GetSystemTimeZones()[238].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[238].DaylightName());
    ASSERT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[238].BaseUtcOffset().ToString());
    ASSERT_EQ("WIB", TimeZoneInfo::GetSystemTimeZones()[238].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[238].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Jayapura) {
    ASSERT_EQ("Asia/Jayapura", TimeZoneInfo::GetSystemTimeZones()[239].Id());
    ASSERT_EQ("(UTC+09:00:00) Asia/Jayapura", TimeZoneInfo::GetSystemTimeZones()[239].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[239].DaylightName());
    ASSERT_EQ("09:00:00", TimeZoneInfo::GetSystemTimeZones()[239].BaseUtcOffset().ToString());
    ASSERT_EQ("WIT", TimeZoneInfo::GetSystemTimeZones()[239].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[239].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Jerusalem) {
    ASSERT_EQ("Asia/Jerusalem", TimeZoneInfo::GetSystemTimeZones()[240].Id());
    ASSERT_EQ("(UTC+02:00:00) Asia/Jerusalem", TimeZoneInfo::GetSystemTimeZones()[240].DisplayName());
    ASSERT_EQ("IDT", TimeZoneInfo::GetSystemTimeZones()[240].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[240].BaseUtcOffset().ToString());
    ASSERT_EQ("IST", TimeZoneInfo::GetSystemTimeZones()[240].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[240].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Kabul) {
    ASSERT_EQ("Asia/Kabul", TimeZoneInfo::GetSystemTimeZones()[241].Id());
    ASSERT_EQ("(UTC+04:30:00) Asia/Kabul", TimeZoneInfo::GetSystemTimeZones()[241].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[241].DaylightName());
    ASSERT_EQ("04:30:00", TimeZoneInfo::GetSystemTimeZones()[241].BaseUtcOffset().ToString());
    ASSERT_EQ("AFT", TimeZoneInfo::GetSystemTimeZones()[241].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[241].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Kamchatka) {
    ASSERT_EQ("Asia/Kamchatka", TimeZoneInfo::GetSystemTimeZones()[242].Id());
    ASSERT_EQ("(UTC+12:00:00) Asia/Kamchatka", TimeZoneInfo::GetSystemTimeZones()[242].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[242].DaylightName());
    ASSERT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[242].BaseUtcOffset().ToString());
    ASSERT_EQ("PETT", TimeZoneInfo::GetSystemTimeZones()[242].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[242].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Karachi) {
    ASSERT_EQ("Asia/Karachi", TimeZoneInfo::GetSystemTimeZones()[243].Id());
    ASSERT_EQ("(UTC+05:00:00) Asia/Karachi", TimeZoneInfo::GetSystemTimeZones()[243].DisplayName());
    ASSERT_EQ("PKST", TimeZoneInfo::GetSystemTimeZones()[243].DaylightName());
    ASSERT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[243].BaseUtcOffset().ToString());
    ASSERT_EQ("PKT", TimeZoneInfo::GetSystemTimeZones()[243].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[243].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Kashgar) {
    ASSERT_EQ("Asia/Kashgar", TimeZoneInfo::GetSystemTimeZones()[244].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Kashgar", TimeZoneInfo::GetSystemTimeZones()[244].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[244].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[244].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[244].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[244].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Kathmandu) {
    ASSERT_EQ("Asia/Kathmandu", TimeZoneInfo::GetSystemTimeZones()[245].Id());
    ASSERT_EQ("(UTC+05:45:00) Asia/Kathmandu", TimeZoneInfo::GetSystemTimeZones()[245].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[245].DaylightName());
    ASSERT_EQ("05:45:00", TimeZoneInfo::GetSystemTimeZones()[245].BaseUtcOffset().ToString());
    ASSERT_EQ("NPT", TimeZoneInfo::GetSystemTimeZones()[245].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[245].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Katmandu) {
    ASSERT_EQ("Asia/Katmandu", TimeZoneInfo::GetSystemTimeZones()[246].Id());
    ASSERT_EQ("(UTC+05:45:00) Asia/Katmandu", TimeZoneInfo::GetSystemTimeZones()[246].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[246].DaylightName());
    ASSERT_EQ("05:45:00", TimeZoneInfo::GetSystemTimeZones()[246].BaseUtcOffset().ToString());
    ASSERT_EQ("NPT", TimeZoneInfo::GetSystemTimeZones()[246].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[246].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Khandyga) {
    ASSERT_EQ("Asia/Khandyga", TimeZoneInfo::GetSystemTimeZones()[247].Id());
    ASSERT_EQ("(UTC+10:00:00) Asia/Khandyga", TimeZoneInfo::GetSystemTimeZones()[247].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[247].DaylightName());
    ASSERT_EQ("10:00:00", TimeZoneInfo::GetSystemTimeZones()[247].BaseUtcOffset().ToString());
    ASSERT_EQ("YAKT", TimeZoneInfo::GetSystemTimeZones()[247].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[247].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Kolkata) {
    ASSERT_EQ("Asia/Kolkata", TimeZoneInfo::GetSystemTimeZones()[248].Id());
    ASSERT_EQ("(UTC+05:30:00) Asia/Kolkata", TimeZoneInfo::GetSystemTimeZones()[248].DisplayName());
    ASSERT_EQ("IST", TimeZoneInfo::GetSystemTimeZones()[248].DaylightName());
    ASSERT_EQ("05:30:00", TimeZoneInfo::GetSystemTimeZones()[248].BaseUtcOffset().ToString());
    ASSERT_EQ("IST", TimeZoneInfo::GetSystemTimeZones()[248].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[248].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Krasnoyarsk) {
    ASSERT_EQ("Asia/Krasnoyarsk", TimeZoneInfo::GetSystemTimeZones()[249].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Krasnoyarsk", TimeZoneInfo::GetSystemTimeZones()[249].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[249].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[249].BaseUtcOffset().ToString());
    ASSERT_EQ("KRAT", TimeZoneInfo::GetSystemTimeZones()[249].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[249].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Kuala_Lumpur) {
    ASSERT_EQ("Asia/Kuala_Lumpur", TimeZoneInfo::GetSystemTimeZones()[250].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Kuala_Lumpur", TimeZoneInfo::GetSystemTimeZones()[250].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[250].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[250].BaseUtcOffset().ToString());
    ASSERT_EQ("MYT", TimeZoneInfo::GetSystemTimeZones()[250].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[250].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Kuching) {
    ASSERT_EQ("Asia/Kuching", TimeZoneInfo::GetSystemTimeZones()[251].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Kuching", TimeZoneInfo::GetSystemTimeZones()[251].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[251].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[251].BaseUtcOffset().ToString());
    ASSERT_EQ("MYT", TimeZoneInfo::GetSystemTimeZones()[251].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[251].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Kuwait) {
    ASSERT_EQ("Asia/Kuwait", TimeZoneInfo::GetSystemTimeZones()[252].Id());
    ASSERT_EQ("(UTC+03:00:00) Asia/Kuwait", TimeZoneInfo::GetSystemTimeZones()[252].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[252].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[252].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[252].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[252].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Macao) {
    ASSERT_EQ("Asia/Macao", TimeZoneInfo::GetSystemTimeZones()[253].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Macao", TimeZoneInfo::GetSystemTimeZones()[253].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[253].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[253].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[253].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[253].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Macau) {
    ASSERT_EQ("Asia/Macau", TimeZoneInfo::GetSystemTimeZones()[254].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Macau", TimeZoneInfo::GetSystemTimeZones()[254].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[254].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[254].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[254].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[254].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Magadan) {
    ASSERT_EQ("Asia/Magadan", TimeZoneInfo::GetSystemTimeZones()[255].Id());
    ASSERT_EQ("(UTC+12:00:00) Asia/Magadan", TimeZoneInfo::GetSystemTimeZones()[255].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[255].DaylightName());
    ASSERT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[255].BaseUtcOffset().ToString());
    ASSERT_EQ("MAGT", TimeZoneInfo::GetSystemTimeZones()[255].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[255].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Makassar) {
    ASSERT_EQ("Asia/Makassar", TimeZoneInfo::GetSystemTimeZones()[256].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Makassar", TimeZoneInfo::GetSystemTimeZones()[256].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[256].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[256].BaseUtcOffset().ToString());
    ASSERT_EQ("WITA", TimeZoneInfo::GetSystemTimeZones()[256].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[256].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Manila) {
    ASSERT_EQ("Asia/Manila", TimeZoneInfo::GetSystemTimeZones()[257].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Manila", TimeZoneInfo::GetSystemTimeZones()[257].DisplayName());
    ASSERT_EQ("PHST", TimeZoneInfo::GetSystemTimeZones()[257].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[257].BaseUtcOffset().ToString());
    ASSERT_EQ("PHT", TimeZoneInfo::GetSystemTimeZones()[257].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[257].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Muscat) {
    ASSERT_EQ("Asia/Muscat", TimeZoneInfo::GetSystemTimeZones()[258].Id());
    ASSERT_EQ("(UTC+04:00:00) Asia/Muscat", TimeZoneInfo::GetSystemTimeZones()[258].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[258].DaylightName());
    ASSERT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[258].BaseUtcOffset().ToString());
    ASSERT_EQ("GST", TimeZoneInfo::GetSystemTimeZones()[258].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[258].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Nicosia) {
    ASSERT_EQ("Asia/Nicosia", TimeZoneInfo::GetSystemTimeZones()[259].Id());
    ASSERT_EQ("(UTC+02:00:00) Asia/Nicosia", TimeZoneInfo::GetSystemTimeZones()[259].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[259].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[259].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[259].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[259].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Novokuznetsk) {
    ASSERT_EQ("Asia/Novokuznetsk", TimeZoneInfo::GetSystemTimeZones()[260].Id());
    ASSERT_EQ("(UTC+07:00:00) Asia/Novokuznetsk", TimeZoneInfo::GetSystemTimeZones()[260].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[260].DaylightName());
    ASSERT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[260].BaseUtcOffset().ToString());
    ASSERT_EQ("NOVT", TimeZoneInfo::GetSystemTimeZones()[260].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[260].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Novosibirsk) {
    ASSERT_EQ("Asia/Novosibirsk", TimeZoneInfo::GetSystemTimeZones()[261].Id());
    ASSERT_EQ("(UTC+07:00:00) Asia/Novosibirsk", TimeZoneInfo::GetSystemTimeZones()[261].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[261].DaylightName());
    ASSERT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[261].BaseUtcOffset().ToString());
    ASSERT_EQ("NOVT", TimeZoneInfo::GetSystemTimeZones()[261].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[261].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Omsk) {
    ASSERT_EQ("Asia/Omsk", TimeZoneInfo::GetSystemTimeZones()[262].Id());
    ASSERT_EQ("(UTC+07:00:00) Asia/Omsk", TimeZoneInfo::GetSystemTimeZones()[262].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[262].DaylightName());
    ASSERT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[262].BaseUtcOffset().ToString());
    ASSERT_EQ("OMST", TimeZoneInfo::GetSystemTimeZones()[262].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[262].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Oral) {
    ASSERT_EQ("Asia/Oral", TimeZoneInfo::GetSystemTimeZones()[263].Id());
    ASSERT_EQ("(UTC+05:00:00) Asia/Oral", TimeZoneInfo::GetSystemTimeZones()[263].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[263].DaylightName());
    ASSERT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[263].BaseUtcOffset().ToString());
    ASSERT_EQ("ORAT", TimeZoneInfo::GetSystemTimeZones()[263].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[263].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Phnom_Penh) {
    ASSERT_EQ("Asia/Phnom_Penh", TimeZoneInfo::GetSystemTimeZones()[264].Id());
    ASSERT_EQ("(UTC+07:00:00) Asia/Phnom_Penh", TimeZoneInfo::GetSystemTimeZones()[264].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[264].DaylightName());
    ASSERT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[264].BaseUtcOffset().ToString());
    ASSERT_EQ("ICT", TimeZoneInfo::GetSystemTimeZones()[264].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[264].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Pontianak) {
    ASSERT_EQ("Asia/Pontianak", TimeZoneInfo::GetSystemTimeZones()[265].Id());
    ASSERT_EQ("(UTC+07:00:00) Asia/Pontianak", TimeZoneInfo::GetSystemTimeZones()[265].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[265].DaylightName());
    ASSERT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[265].BaseUtcOffset().ToString());
    ASSERT_EQ("WIB", TimeZoneInfo::GetSystemTimeZones()[265].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[265].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Pyongyang) {
    ASSERT_EQ("Asia/Pyongyang", TimeZoneInfo::GetSystemTimeZones()[266].Id());
    ASSERT_EQ("(UTC+09:00:00) Asia/Pyongyang", TimeZoneInfo::GetSystemTimeZones()[266].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[266].DaylightName());
    ASSERT_EQ("09:00:00", TimeZoneInfo::GetSystemTimeZones()[266].BaseUtcOffset().ToString());
    ASSERT_EQ("KST", TimeZoneInfo::GetSystemTimeZones()[266].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[266].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Qatar) {
    ASSERT_EQ("Asia/Qatar", TimeZoneInfo::GetSystemTimeZones()[267].Id());
    ASSERT_EQ("(UTC+03:00:00) Asia/Qatar", TimeZoneInfo::GetSystemTimeZones()[267].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[267].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[267].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[267].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[267].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Qyzylorda) {
    ASSERT_EQ("Asia/Qyzylorda", TimeZoneInfo::GetSystemTimeZones()[268].Id());
    ASSERT_EQ("(UTC+06:00:00) Asia/Qyzylorda", TimeZoneInfo::GetSystemTimeZones()[268].DisplayName());
    ASSERT_EQ("QYZST", TimeZoneInfo::GetSystemTimeZones()[268].DaylightName());
    ASSERT_EQ("06:00:00", TimeZoneInfo::GetSystemTimeZones()[268].BaseUtcOffset().ToString());
    ASSERT_EQ("QYZT", TimeZoneInfo::GetSystemTimeZones()[268].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[268].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Rangoon) {
    ASSERT_EQ("Asia/Rangoon", TimeZoneInfo::GetSystemTimeZones()[269].Id());
    ASSERT_EQ("(UTC+06:30:00) Asia/Rangoon", TimeZoneInfo::GetSystemTimeZones()[269].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[269].DaylightName());
    ASSERT_EQ("06:30:00", TimeZoneInfo::GetSystemTimeZones()[269].BaseUtcOffset().ToString());
    ASSERT_EQ("MMT", TimeZoneInfo::GetSystemTimeZones()[269].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[269].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Riyadh) {
    ASSERT_EQ("Asia/Riyadh", TimeZoneInfo::GetSystemTimeZones()[270].Id());
    ASSERT_EQ("(UTC+03:00:00) Asia/Riyadh", TimeZoneInfo::GetSystemTimeZones()[270].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[270].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[270].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[270].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[270].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Saigon) {
    ASSERT_EQ("Asia/Saigon", TimeZoneInfo::GetSystemTimeZones()[271].Id());
    ASSERT_EQ("(UTC+07:00:00) Asia/Saigon", TimeZoneInfo::GetSystemTimeZones()[271].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[271].DaylightName());
    ASSERT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[271].BaseUtcOffset().ToString());
    ASSERT_EQ("ICT", TimeZoneInfo::GetSystemTimeZones()[271].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[271].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Sakhalin) {
    ASSERT_EQ("Asia/Sakhalin", TimeZoneInfo::GetSystemTimeZones()[272].Id());
    ASSERT_EQ("(UTC+11:00:00) Asia/Sakhalin", TimeZoneInfo::GetSystemTimeZones()[272].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[272].DaylightName());
    ASSERT_EQ("11:00:00", TimeZoneInfo::GetSystemTimeZones()[272].BaseUtcOffset().ToString());
    ASSERT_EQ("SAKT", TimeZoneInfo::GetSystemTimeZones()[272].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[272].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Samarkand) {
    ASSERT_EQ("Asia/Samarkand", TimeZoneInfo::GetSystemTimeZones()[273].Id());
    ASSERT_EQ("(UTC+05:00:00) Asia/Samarkand", TimeZoneInfo::GetSystemTimeZones()[273].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[273].DaylightName());
    ASSERT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[273].BaseUtcOffset().ToString());
    ASSERT_EQ("UZT", TimeZoneInfo::GetSystemTimeZones()[273].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[273].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Seoul) {
    ASSERT_EQ("Asia/Seoul", TimeZoneInfo::GetSystemTimeZones()[274].Id());
    ASSERT_EQ("(UTC+09:00:00) Asia/Seoul", TimeZoneInfo::GetSystemTimeZones()[274].DisplayName());
    ASSERT_EQ("KDT", TimeZoneInfo::GetSystemTimeZones()[274].DaylightName());
    ASSERT_EQ("09:00:00", TimeZoneInfo::GetSystemTimeZones()[274].BaseUtcOffset().ToString());
    ASSERT_EQ("KST", TimeZoneInfo::GetSystemTimeZones()[274].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[274].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Shanghai) {
    ASSERT_EQ("Asia/Shanghai", TimeZoneInfo::GetSystemTimeZones()[275].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Shanghai", TimeZoneInfo::GetSystemTimeZones()[275].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[275].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[275].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[275].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[275].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Singapore) {
    ASSERT_EQ("Asia/Singapore", TimeZoneInfo::GetSystemTimeZones()[276].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Singapore", TimeZoneInfo::GetSystemTimeZones()[276].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[276].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[276].BaseUtcOffset().ToString());
    ASSERT_EQ("SGT", TimeZoneInfo::GetSystemTimeZones()[276].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[276].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Taipei) {
    ASSERT_EQ("Asia/Taipei", TimeZoneInfo::GetSystemTimeZones()[277].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Taipei", TimeZoneInfo::GetSystemTimeZones()[277].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[277].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[277].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[277].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[277].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Tashkent) {
    ASSERT_EQ("Asia/Tashkent", TimeZoneInfo::GetSystemTimeZones()[278].Id());
    ASSERT_EQ("(UTC+05:00:00) Asia/Tashkent", TimeZoneInfo::GetSystemTimeZones()[278].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[278].DaylightName());
    ASSERT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[278].BaseUtcOffset().ToString());
    ASSERT_EQ("UZT", TimeZoneInfo::GetSystemTimeZones()[278].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[278].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Tbilisi) {
    ASSERT_EQ("Asia/Tbilisi", TimeZoneInfo::GetSystemTimeZones()[279].Id());
    ASSERT_EQ("(UTC+04:00:00) Asia/Tbilisi", TimeZoneInfo::GetSystemTimeZones()[279].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[279].DaylightName());
    ASSERT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[279].BaseUtcOffset().ToString());
    ASSERT_EQ("GET", TimeZoneInfo::GetSystemTimeZones()[279].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[279].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Tehran) {
    ASSERT_EQ("Asia/Tehran", TimeZoneInfo::GetSystemTimeZones()[280].Id());
    ASSERT_EQ("(UTC+03:30:00) Asia/Tehran", TimeZoneInfo::GetSystemTimeZones()[280].DisplayName());
    ASSERT_EQ("IRDT", TimeZoneInfo::GetSystemTimeZones()[280].DaylightName());
    ASSERT_EQ("03:30:00", TimeZoneInfo::GetSystemTimeZones()[280].BaseUtcOffset().ToString());
    ASSERT_EQ("IRST", TimeZoneInfo::GetSystemTimeZones()[280].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[280].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Tel_Aviv) {
    ASSERT_EQ("Asia/Tel_Aviv", TimeZoneInfo::GetSystemTimeZones()[281].Id());
    ASSERT_EQ("(UTC+02:00:00) Asia/Tel_Aviv", TimeZoneInfo::GetSystemTimeZones()[281].DisplayName());
    ASSERT_EQ("IDT", TimeZoneInfo::GetSystemTimeZones()[281].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[281].BaseUtcOffset().ToString());
    ASSERT_EQ("IST", TimeZoneInfo::GetSystemTimeZones()[281].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[281].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Thimbu) {
    ASSERT_EQ("Asia/Thimbu", TimeZoneInfo::GetSystemTimeZones()[282].Id());
    ASSERT_EQ("(UTC+06:00:00) Asia/Thimbu", TimeZoneInfo::GetSystemTimeZones()[282].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[282].DaylightName());
    ASSERT_EQ("06:00:00", TimeZoneInfo::GetSystemTimeZones()[282].BaseUtcOffset().ToString());
    ASSERT_EQ("BTT", TimeZoneInfo::GetSystemTimeZones()[282].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[282].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Thimphu) {
    ASSERT_EQ("Asia/Thimphu", TimeZoneInfo::GetSystemTimeZones()[283].Id());
    ASSERT_EQ("(UTC+06:00:00) Asia/Thimphu", TimeZoneInfo::GetSystemTimeZones()[283].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[283].DaylightName());
    ASSERT_EQ("06:00:00", TimeZoneInfo::GetSystemTimeZones()[283].BaseUtcOffset().ToString());
    ASSERT_EQ("BTT", TimeZoneInfo::GetSystemTimeZones()[283].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[283].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Tokyo) {
    ASSERT_EQ("Asia/Tokyo", TimeZoneInfo::GetSystemTimeZones()[284].Id());
    ASSERT_EQ("(UTC+09:00:00) Asia/Tokyo", TimeZoneInfo::GetSystemTimeZones()[284].DisplayName());
    ASSERT_EQ("JDT", TimeZoneInfo::GetSystemTimeZones()[284].DaylightName());
    ASSERT_EQ("09:00:00", TimeZoneInfo::GetSystemTimeZones()[284].BaseUtcOffset().ToString());
    ASSERT_EQ("JST", TimeZoneInfo::GetSystemTimeZones()[284].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[284].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Ujung_Pandang) {
    ASSERT_EQ("Asia/Ujung_Pandang", TimeZoneInfo::GetSystemTimeZones()[285].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Ujung_Pandang", TimeZoneInfo::GetSystemTimeZones()[285].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[285].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[285].BaseUtcOffset().ToString());
    ASSERT_EQ("WITA", TimeZoneInfo::GetSystemTimeZones()[285].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[285].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Ulaanbaatar) {
    ASSERT_EQ("Asia/Ulaanbaatar", TimeZoneInfo::GetSystemTimeZones()[286].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Ulaanbaatar", TimeZoneInfo::GetSystemTimeZones()[286].DisplayName());
    ASSERT_EQ("ULAST", TimeZoneInfo::GetSystemTimeZones()[286].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[286].BaseUtcOffset().ToString());
    ASSERT_EQ("ULAT", TimeZoneInfo::GetSystemTimeZones()[286].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[286].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Ulan_Bator) {
    ASSERT_EQ("Asia/Ulan_Bator", TimeZoneInfo::GetSystemTimeZones()[287].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Ulan_Bator", TimeZoneInfo::GetSystemTimeZones()[287].DisplayName());
    ASSERT_EQ("ULAST", TimeZoneInfo::GetSystemTimeZones()[287].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[287].BaseUtcOffset().ToString());
    ASSERT_EQ("ULAT", TimeZoneInfo::GetSystemTimeZones()[287].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[287].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Urumqi) {
    ASSERT_EQ("Asia/Urumqi", TimeZoneInfo::GetSystemTimeZones()[288].Id());
    ASSERT_EQ("(UTC+08:00:00) Asia/Urumqi", TimeZoneInfo::GetSystemTimeZones()[288].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[288].DaylightName());
    ASSERT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[288].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[288].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[288].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Ust_Nera) {
    ASSERT_EQ("Asia/Ust-Nera", TimeZoneInfo::GetSystemTimeZones()[289].Id());
    ASSERT_EQ("(UTC+11:00:00) Asia/Ust-Nera", TimeZoneInfo::GetSystemTimeZones()[289].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[289].DaylightName());
    ASSERT_EQ("11:00:00", TimeZoneInfo::GetSystemTimeZones()[289].BaseUtcOffset().ToString());
    ASSERT_EQ("VLAT", TimeZoneInfo::GetSystemTimeZones()[289].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[289].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Vientiane) {
    ASSERT_EQ("Asia/Vientiane", TimeZoneInfo::GetSystemTimeZones()[290].Id());
    ASSERT_EQ("(UTC+07:00:00) Asia/Vientiane", TimeZoneInfo::GetSystemTimeZones()[290].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[290].DaylightName());
    ASSERT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[290].BaseUtcOffset().ToString());
    ASSERT_EQ("ICT", TimeZoneInfo::GetSystemTimeZones()[290].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[290].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Vladivostok) {
    ASSERT_EQ("Asia/Vladivostok", TimeZoneInfo::GetSystemTimeZones()[291].Id());
    ASSERT_EQ("(UTC+11:00:00) Asia/Vladivostok", TimeZoneInfo::GetSystemTimeZones()[291].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[291].DaylightName());
    ASSERT_EQ("11:00:00", TimeZoneInfo::GetSystemTimeZones()[291].BaseUtcOffset().ToString());
    ASSERT_EQ("VLAT", TimeZoneInfo::GetSystemTimeZones()[291].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[291].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Yakutsk) {
    ASSERT_EQ("Asia/Yakutsk", TimeZoneInfo::GetSystemTimeZones()[292].Id());
    ASSERT_EQ("(UTC+10:00:00) Asia/Yakutsk", TimeZoneInfo::GetSystemTimeZones()[292].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[292].DaylightName());
    ASSERT_EQ("10:00:00", TimeZoneInfo::GetSystemTimeZones()[292].BaseUtcOffset().ToString());
    ASSERT_EQ("YAKT", TimeZoneInfo::GetSystemTimeZones()[292].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[292].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Yekaterinburg) {
    ASSERT_EQ("Asia/Yekaterinburg", TimeZoneInfo::GetSystemTimeZones()[293].Id());
    ASSERT_EQ("(UTC+06:00:00) Asia/Yekaterinburg", TimeZoneInfo::GetSystemTimeZones()[293].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[293].DaylightName());
    ASSERT_EQ("06:00:00", TimeZoneInfo::GetSystemTimeZones()[293].BaseUtcOffset().ToString());
    ASSERT_EQ("YEKT", TimeZoneInfo::GetSystemTimeZones()[293].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[293].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAsia_Yerevan) {
    ASSERT_EQ("Asia/Yerevan", TimeZoneInfo::GetSystemTimeZones()[294].Id());
    ASSERT_EQ("(UTC+04:00:00) Asia/Yerevan", TimeZoneInfo::GetSystemTimeZones()[294].DisplayName());
    ASSERT_EQ("AMST", TimeZoneInfo::GetSystemTimeZones()[294].DaylightName());
    ASSERT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[294].BaseUtcOffset().ToString());
    ASSERT_EQ("AMT", TimeZoneInfo::GetSystemTimeZones()[294].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[294].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAtlantic_Azores) {
    ASSERT_EQ("Atlantic/Azores", TimeZoneInfo::GetSystemTimeZones()[295].Id());
    ASSERT_EQ("(UTC-01:00:00) Atlantic/Azores", TimeZoneInfo::GetSystemTimeZones()[295].DisplayName());
    ASSERT_EQ("AZOST", TimeZoneInfo::GetSystemTimeZones()[295].DaylightName());
    ASSERT_EQ("-01:00:00", TimeZoneInfo::GetSystemTimeZones()[295].BaseUtcOffset().ToString());
    ASSERT_EQ("AZOT", TimeZoneInfo::GetSystemTimeZones()[295].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[295].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAtlantic_Bermuda) {
    ASSERT_EQ("Atlantic/Bermuda", TimeZoneInfo::GetSystemTimeZones()[296].Id());
    ASSERT_EQ("(UTC-04:00:00) Atlantic/Bermuda", TimeZoneInfo::GetSystemTimeZones()[296].DisplayName());
    ASSERT_EQ("ADT", TimeZoneInfo::GetSystemTimeZones()[296].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[296].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[296].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[296].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAtlantic_Canary) {
    ASSERT_EQ("Atlantic/Canary", TimeZoneInfo::GetSystemTimeZones()[297].Id());
    ASSERT_EQ("(UTC) Atlantic/Canary", TimeZoneInfo::GetSystemTimeZones()[297].DisplayName());
    ASSERT_EQ("WEST", TimeZoneInfo::GetSystemTimeZones()[297].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[297].BaseUtcOffset().ToString());
    ASSERT_EQ("WET", TimeZoneInfo::GetSystemTimeZones()[297].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[297].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAtlantic_Cape_Verde) {
    ASSERT_EQ("Atlantic/Cape_Verde", TimeZoneInfo::GetSystemTimeZones()[298].Id());
    ASSERT_EQ("(UTC-01:00:00) Atlantic/Cape_Verde", TimeZoneInfo::GetSystemTimeZones()[298].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[298].DaylightName());
    ASSERT_EQ("-01:00:00", TimeZoneInfo::GetSystemTimeZones()[298].BaseUtcOffset().ToString());
    ASSERT_EQ("CVT", TimeZoneInfo::GetSystemTimeZones()[298].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[298].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAtlantic_Faeroe) {
    ASSERT_EQ("Atlantic/Faeroe", TimeZoneInfo::GetSystemTimeZones()[299].Id());
    ASSERT_EQ("(UTC) Atlantic/Faeroe", TimeZoneInfo::GetSystemTimeZones()[299].DisplayName());
    ASSERT_EQ("WEST", TimeZoneInfo::GetSystemTimeZones()[299].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[299].BaseUtcOffset().ToString());
    ASSERT_EQ("WET", TimeZoneInfo::GetSystemTimeZones()[299].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[299].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAtlantic_Faroe) {
    ASSERT_EQ("Atlantic/Faroe", TimeZoneInfo::GetSystemTimeZones()[300].Id());
    ASSERT_EQ("(UTC) Atlantic/Faroe", TimeZoneInfo::GetSystemTimeZones()[300].DisplayName());
    ASSERT_EQ("WEST", TimeZoneInfo::GetSystemTimeZones()[300].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[300].BaseUtcOffset().ToString());
    ASSERT_EQ("WET", TimeZoneInfo::GetSystemTimeZones()[300].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[300].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAtlantic_Jan_Mayen) {
    ASSERT_EQ("Atlantic/Jan_Mayen", TimeZoneInfo::GetSystemTimeZones()[301].Id());
    ASSERT_EQ("(UTC+01:00:00) Atlantic/Jan_Mayen", TimeZoneInfo::GetSystemTimeZones()[301].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[301].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[301].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[301].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[301].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAtlantic_Madeira) {
    ASSERT_EQ("Atlantic/Madeira", TimeZoneInfo::GetSystemTimeZones()[302].Id());
    ASSERT_EQ("(UTC) Atlantic/Madeira", TimeZoneInfo::GetSystemTimeZones()[302].DisplayName());
    ASSERT_EQ("WEST", TimeZoneInfo::GetSystemTimeZones()[302].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[302].BaseUtcOffset().ToString());
    ASSERT_EQ("WET", TimeZoneInfo::GetSystemTimeZones()[302].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[302].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAtlantic_Reykjavik) {
    ASSERT_EQ("Atlantic/Reykjavik", TimeZoneInfo::GetSystemTimeZones()[303].Id());
    ASSERT_EQ("(UTC) Atlantic/Reykjavik", TimeZoneInfo::GetSystemTimeZones()[303].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[303].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[303].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[303].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[303].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAtlantic_South_Georgia) {
    ASSERT_EQ("Atlantic/South_Georgia", TimeZoneInfo::GetSystemTimeZones()[304].Id());
    ASSERT_EQ("(UTC-02:00:00) Atlantic/South_Georgia", TimeZoneInfo::GetSystemTimeZones()[304].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[304].DaylightName());
    ASSERT_EQ("-02:00:00", TimeZoneInfo::GetSystemTimeZones()[304].BaseUtcOffset().ToString());
    ASSERT_EQ("GST", TimeZoneInfo::GetSystemTimeZones()[304].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[304].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAtlantic_St_Helena) {
    ASSERT_EQ("Atlantic/St_Helena", TimeZoneInfo::GetSystemTimeZones()[305].Id());
    ASSERT_EQ("(UTC) Atlantic/St_Helena", TimeZoneInfo::GetSystemTimeZones()[305].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[305].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[305].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[305].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[305].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesAtlantic_Stanley) {
    ASSERT_EQ("Atlantic/Stanley", TimeZoneInfo::GetSystemTimeZones()[306].Id());
    ASSERT_EQ("(UTC-03:00:00) Atlantic/Stanley", TimeZoneInfo::GetSystemTimeZones()[306].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[306].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[306].BaseUtcOffset().ToString());
    ASSERT_EQ("FKST", TimeZoneInfo::GetSystemTimeZones()[306].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[306].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesBrazil_Acre) {
    ASSERT_EQ("Brazil/Acre", TimeZoneInfo::GetSystemTimeZones()[307].Id());
    ASSERT_EQ("(UTC-05:00:00) Brazil/Acre", TimeZoneInfo::GetSystemTimeZones()[307].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[307].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[307].BaseUtcOffset().ToString());
    ASSERT_EQ("ACT", TimeZoneInfo::GetSystemTimeZones()[307].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[307].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesBrazil_DeNoronha) {
    ASSERT_EQ("Brazil/DeNoronha", TimeZoneInfo::GetSystemTimeZones()[308].Id());
    ASSERT_EQ("(UTC-02:00:00) Brazil/DeNoronha", TimeZoneInfo::GetSystemTimeZones()[308].DisplayName());
    ASSERT_EQ("FNST", TimeZoneInfo::GetSystemTimeZones()[308].DaylightName());
    ASSERT_EQ("-02:00:00", TimeZoneInfo::GetSystemTimeZones()[308].BaseUtcOffset().ToString());
    ASSERT_EQ("FNT", TimeZoneInfo::GetSystemTimeZones()[308].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[308].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesBrazil_East) {
    ASSERT_EQ("Brazil/East", TimeZoneInfo::GetSystemTimeZones()[309].Id());
    ASSERT_EQ("(UTC-03:00:00) Brazil/East", TimeZoneInfo::GetSystemTimeZones()[309].DisplayName());
    ASSERT_EQ("BRST", TimeZoneInfo::GetSystemTimeZones()[309].DaylightName());
    ASSERT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[309].BaseUtcOffset().ToString());
    ASSERT_EQ("BRT", TimeZoneInfo::GetSystemTimeZones()[309].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[309].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesBrazil_West) {
    ASSERT_EQ("Brazil/West", TimeZoneInfo::GetSystemTimeZones()[310].Id());
    ASSERT_EQ("(UTC-04:00:00) Brazil/West", TimeZoneInfo::GetSystemTimeZones()[310].DisplayName());
    ASSERT_EQ("AMST", TimeZoneInfo::GetSystemTimeZones()[310].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[310].BaseUtcOffset().ToString());
    ASSERT_EQ("AMT", TimeZoneInfo::GetSystemTimeZones()[310].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[310].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesCanada_Atlantic) {
    ASSERT_EQ("Canada/Atlantic", TimeZoneInfo::GetSystemTimeZones()[311].Id());
    ASSERT_EQ("(UTC-04:00:00) Canada/Atlantic", TimeZoneInfo::GetSystemTimeZones()[311].DisplayName());
    ASSERT_EQ("ADT", TimeZoneInfo::GetSystemTimeZones()[311].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[311].BaseUtcOffset().ToString());
    ASSERT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[311].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[311].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesCanada_Central) {
    ASSERT_EQ("Canada/Central", TimeZoneInfo::GetSystemTimeZones()[312].Id());
    ASSERT_EQ("(UTC-06:00:00) Canada/Central", TimeZoneInfo::GetSystemTimeZones()[312].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[312].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[312].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[312].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[312].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesCanada_East_Saskatchewan) {
    ASSERT_EQ("Canada/East-Saskatchewan", TimeZoneInfo::GetSystemTimeZones()[313].Id());
    ASSERT_EQ("(UTC-06:00:00) Canada/East-Saskatchewan", TimeZoneInfo::GetSystemTimeZones()[313].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[313].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[313].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[313].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[313].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesCanada_Eastern) {
    ASSERT_EQ("Canada/Eastern", TimeZoneInfo::GetSystemTimeZones()[314].Id());
    ASSERT_EQ("(UTC-05:00:00) Canada/Eastern", TimeZoneInfo::GetSystemTimeZones()[314].DisplayName());
    ASSERT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[314].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[314].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[314].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[314].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesCanada_Mountain) {
    ASSERT_EQ("Canada/Mountain", TimeZoneInfo::GetSystemTimeZones()[315].Id());
    ASSERT_EQ("(UTC-07:00:00) Canada/Mountain", TimeZoneInfo::GetSystemTimeZones()[315].DisplayName());
    ASSERT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[315].DaylightName());
    ASSERT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[315].BaseUtcOffset().ToString());
    ASSERT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[315].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[315].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesCanada_Newfoundland) {
    ASSERT_EQ("Canada/Newfoundland", TimeZoneInfo::GetSystemTimeZones()[316].Id());
    ASSERT_EQ("(UTC-03:30:00) Canada/Newfoundland", TimeZoneInfo::GetSystemTimeZones()[316].DisplayName());
    ASSERT_EQ("NDT", TimeZoneInfo::GetSystemTimeZones()[316].DaylightName());
    ASSERT_EQ("-03:30:00", TimeZoneInfo::GetSystemTimeZones()[316].BaseUtcOffset().ToString());
    ASSERT_EQ("NST", TimeZoneInfo::GetSystemTimeZones()[316].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[316].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesCanada_Pacific) {
    ASSERT_EQ("Canada/Pacific", TimeZoneInfo::GetSystemTimeZones()[317].Id());
    ASSERT_EQ("(UTC-08:00:00) Canada/Pacific", TimeZoneInfo::GetSystemTimeZones()[317].DisplayName());
    ASSERT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[317].DaylightName());
    ASSERT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[317].BaseUtcOffset().ToString());
    ASSERT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[317].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[317].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesCanada_Saskatchewan) {
    ASSERT_EQ("Canada/Saskatchewan", TimeZoneInfo::GetSystemTimeZones()[318].Id());
    ASSERT_EQ("(UTC-06:00:00) Canada/Saskatchewan", TimeZoneInfo::GetSystemTimeZones()[318].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[318].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[318].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[318].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[318].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesCanada_Yukon) {
    ASSERT_EQ("Canada/Yukon", TimeZoneInfo::GetSystemTimeZones()[319].Id());
    ASSERT_EQ("(UTC-08:00:00) Canada/Yukon", TimeZoneInfo::GetSystemTimeZones()[319].DisplayName());
    ASSERT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[319].DaylightName());
    ASSERT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[319].BaseUtcOffset().ToString());
    ASSERT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[319].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[319].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesChile_Continental) {
    ASSERT_EQ("Chile/Continental", TimeZoneInfo::GetSystemTimeZones()[320].Id());
    ASSERT_EQ("(UTC-04:00:00) Chile/Continental", TimeZoneInfo::GetSystemTimeZones()[320].DisplayName());
    ASSERT_EQ("CLST", TimeZoneInfo::GetSystemTimeZones()[320].DaylightName());
    ASSERT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[320].BaseUtcOffset().ToString());
    ASSERT_EQ("CLT", TimeZoneInfo::GetSystemTimeZones()[320].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[320].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesChile_EasterIsland) {
    ASSERT_EQ("Chile/EasterIsland", TimeZoneInfo::GetSystemTimeZones()[321].Id());
    ASSERT_EQ("(UTC-06:00:00) Chile/EasterIsland", TimeZoneInfo::GetSystemTimeZones()[321].DisplayName());
    ASSERT_EQ("EASST", TimeZoneInfo::GetSystemTimeZones()[321].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[321].BaseUtcOffset().ToString());
    ASSERT_EQ("EAST", TimeZoneInfo::GetSystemTimeZones()[321].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[321].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Amsterdam) {
    ASSERT_EQ("Europe/Amsterdam", TimeZoneInfo::GetSystemTimeZones()[322].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Amsterdam", TimeZoneInfo::GetSystemTimeZones()[322].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[322].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[322].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[322].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[322].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Andorra) {
    ASSERT_EQ("Europe/Andorra", TimeZoneInfo::GetSystemTimeZones()[323].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Andorra", TimeZoneInfo::GetSystemTimeZones()[323].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[323].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[323].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[323].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[323].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Athens) {
    ASSERT_EQ("Europe/Athens", TimeZoneInfo::GetSystemTimeZones()[324].Id());
    ASSERT_EQ("(UTC+02:00:00) Europe/Athens", TimeZoneInfo::GetSystemTimeZones()[324].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[324].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[324].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[324].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[324].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Belfast) {
    ASSERT_EQ("Europe/Belfast", TimeZoneInfo::GetSystemTimeZones()[325].Id());
    ASSERT_EQ("(UTC) Europe/Belfast", TimeZoneInfo::GetSystemTimeZones()[325].DisplayName());
    ASSERT_EQ("BST", TimeZoneInfo::GetSystemTimeZones()[325].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[325].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[325].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[325].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Belgrade) {
    ASSERT_EQ("Europe/Belgrade", TimeZoneInfo::GetSystemTimeZones()[326].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Belgrade", TimeZoneInfo::GetSystemTimeZones()[326].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[326].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[326].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[326].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[326].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Berlin) {
    ASSERT_EQ("Europe/Berlin", TimeZoneInfo::GetSystemTimeZones()[327].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Berlin", TimeZoneInfo::GetSystemTimeZones()[327].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[327].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[327].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[327].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[327].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Bratislava) {
    ASSERT_EQ("Europe/Bratislava", TimeZoneInfo::GetSystemTimeZones()[328].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Bratislava", TimeZoneInfo::GetSystemTimeZones()[328].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[328].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[328].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[328].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[328].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Brussels) {
    ASSERT_EQ("Europe/Brussels", TimeZoneInfo::GetSystemTimeZones()[329].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Brussels", TimeZoneInfo::GetSystemTimeZones()[329].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[329].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[329].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[329].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[329].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Bchar32est) {
    ASSERT_EQ("Europe/Bchar32est", TimeZoneInfo::GetSystemTimeZones()[330].Id());
    ASSERT_EQ("(UTC+02:00:00) Europe/Bchar32est", TimeZoneInfo::GetSystemTimeZones()[330].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[330].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[330].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[330].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[330].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Budapest) {
    ASSERT_EQ("Europe/Budapest", TimeZoneInfo::GetSystemTimeZones()[331].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Budapest", TimeZoneInfo::GetSystemTimeZones()[331].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[331].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[331].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[331].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[331].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Busingen) {
    ASSERT_EQ("Europe/Busingen", TimeZoneInfo::GetSystemTimeZones()[332].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Busingen", TimeZoneInfo::GetSystemTimeZones()[332].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[332].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[332].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[332].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[332].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Chisinau) {
    ASSERT_EQ("Europe/Chisinau", TimeZoneInfo::GetSystemTimeZones()[333].Id());
    ASSERT_EQ("(UTC+02:00:00) Europe/Chisinau", TimeZoneInfo::GetSystemTimeZones()[333].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[333].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[333].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[333].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[333].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Copenhagen) {
    ASSERT_EQ("Europe/Copenhagen", TimeZoneInfo::GetSystemTimeZones()[334].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Copenhagen", TimeZoneInfo::GetSystemTimeZones()[334].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[334].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[334].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[334].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[334].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Dublin) {
    ASSERT_EQ("Europe/Dublin", TimeZoneInfo::GetSystemTimeZones()[335].Id());
    ASSERT_EQ("(UTC) Europe/Dublin", TimeZoneInfo::GetSystemTimeZones()[335].DisplayName());
    ASSERT_EQ("IST", TimeZoneInfo::GetSystemTimeZones()[335].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[335].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[335].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[335].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Gibraltar) {
    ASSERT_EQ("Europe/Gibraltar", TimeZoneInfo::GetSystemTimeZones()[336].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Gibraltar", TimeZoneInfo::GetSystemTimeZones()[336].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[336].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[336].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[336].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[336].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Guernsey) {
    ASSERT_EQ("Europe/Guernsey", TimeZoneInfo::GetSystemTimeZones()[337].Id());
    ASSERT_EQ("(UTC) Europe/Guernsey", TimeZoneInfo::GetSystemTimeZones()[337].DisplayName());
    ASSERT_EQ("BST", TimeZoneInfo::GetSystemTimeZones()[337].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[337].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[337].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[337].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Helsinki) {
    ASSERT_EQ("Europe/Helsinki", TimeZoneInfo::GetSystemTimeZones()[338].Id());
    ASSERT_EQ("(UTC+02:00:00) Europe/Helsinki", TimeZoneInfo::GetSystemTimeZones()[338].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[338].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[338].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[338].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[338].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Isle_of_Man) {
    ASSERT_EQ("Europe/Isle_of_Man", TimeZoneInfo::GetSystemTimeZones()[339].Id());
    ASSERT_EQ("(UTC) Europe/Isle_of_Man", TimeZoneInfo::GetSystemTimeZones()[339].DisplayName());
    ASSERT_EQ("BST", TimeZoneInfo::GetSystemTimeZones()[339].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[339].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[339].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[339].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Istanbul) {
    ASSERT_EQ("Europe/Istanbul", TimeZoneInfo::GetSystemTimeZones()[340].Id());
    ASSERT_EQ("(UTC+02:00:00) Europe/Istanbul", TimeZoneInfo::GetSystemTimeZones()[340].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[340].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[340].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[340].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[340].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Jersey) {
    ASSERT_EQ("Europe/Jersey", TimeZoneInfo::GetSystemTimeZones()[341].Id());
    ASSERT_EQ("(UTC) Europe/Jersey", TimeZoneInfo::GetSystemTimeZones()[341].DisplayName());
    ASSERT_EQ("BST", TimeZoneInfo::GetSystemTimeZones()[341].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[341].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[341].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[341].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Kaliningrad) {
    ASSERT_EQ("Europe/Kaliningrad", TimeZoneInfo::GetSystemTimeZones()[342].Id());
    ASSERT_EQ("(UTC+03:00:00) Europe/Kaliningrad", TimeZoneInfo::GetSystemTimeZones()[342].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[342].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[342].BaseUtcOffset().ToString());
    ASSERT_EQ("FET", TimeZoneInfo::GetSystemTimeZones()[342].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[342].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Kiev) {
    ASSERT_EQ("Europe/Kiev", TimeZoneInfo::GetSystemTimeZones()[343].Id());
    ASSERT_EQ("(UTC+02:00:00) Europe/Kiev", TimeZoneInfo::GetSystemTimeZones()[343].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[343].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[343].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[343].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[343].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Lisbon) {
    ASSERT_EQ("Europe/Lisbon", TimeZoneInfo::GetSystemTimeZones()[344].Id());
    ASSERT_EQ("(UTC) Europe/Lisbon", TimeZoneInfo::GetSystemTimeZones()[344].DisplayName());
    ASSERT_EQ("WEST", TimeZoneInfo::GetSystemTimeZones()[344].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[344].BaseUtcOffset().ToString());
    ASSERT_EQ("WET", TimeZoneInfo::GetSystemTimeZones()[344].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[344].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Ljubljana) {
    ASSERT_EQ("Europe/Ljubljana", TimeZoneInfo::GetSystemTimeZones()[345].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Ljubljana", TimeZoneInfo::GetSystemTimeZones()[345].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[345].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[345].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[345].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[345].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_London) {
    ASSERT_EQ("Europe/London", TimeZoneInfo::GetSystemTimeZones()[346].Id());
    ASSERT_EQ("(UTC) Europe/London", TimeZoneInfo::GetSystemTimeZones()[346].DisplayName());
    ASSERT_EQ("BST", TimeZoneInfo::GetSystemTimeZones()[346].DaylightName());
    ASSERT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[346].BaseUtcOffset().ToString());
    ASSERT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[346].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[346].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Luxembourg) {
    ASSERT_EQ("Europe/Luxembourg", TimeZoneInfo::GetSystemTimeZones()[347].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Luxembourg", TimeZoneInfo::GetSystemTimeZones()[347].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[347].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[347].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[347].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[347].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Madrid) {
    ASSERT_EQ("Europe/Madrid", TimeZoneInfo::GetSystemTimeZones()[348].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Madrid", TimeZoneInfo::GetSystemTimeZones()[348].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[348].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[348].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[348].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[348].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Malta) {
    ASSERT_EQ("Europe/Malta", TimeZoneInfo::GetSystemTimeZones()[349].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Malta", TimeZoneInfo::GetSystemTimeZones()[349].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[349].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[349].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[349].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[349].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Mariehamn) {
    ASSERT_EQ("Europe/Mariehamn", TimeZoneInfo::GetSystemTimeZones()[350].Id());
    ASSERT_EQ("(UTC+02:00:00) Europe/Mariehamn", TimeZoneInfo::GetSystemTimeZones()[350].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[350].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[350].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[350].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[350].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Minsk) {
    ASSERT_EQ("Europe/Minsk", TimeZoneInfo::GetSystemTimeZones()[351].Id());
    ASSERT_EQ("(UTC+03:00:00) Europe/Minsk", TimeZoneInfo::GetSystemTimeZones()[351].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[351].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[351].BaseUtcOffset().ToString());
    ASSERT_EQ("FET", TimeZoneInfo::GetSystemTimeZones()[351].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[351].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Monaco) {
    ASSERT_EQ("Europe/Monaco", TimeZoneInfo::GetSystemTimeZones()[352].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Monaco", TimeZoneInfo::GetSystemTimeZones()[352].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[352].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[352].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[352].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[352].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Moscow) {
    ASSERT_EQ("Europe/Moscow", TimeZoneInfo::GetSystemTimeZones()[353].Id());
    ASSERT_EQ("(UTC+04:00:00) Europe/Moscow", TimeZoneInfo::GetSystemTimeZones()[353].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[353].DaylightName());
    ASSERT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[353].BaseUtcOffset().ToString());
    ASSERT_EQ("MSK", TimeZoneInfo::GetSystemTimeZones()[353].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[353].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Nicosia) {
    ASSERT_EQ("Europe/Nicosia", TimeZoneInfo::GetSystemTimeZones()[354].Id());
    ASSERT_EQ("(UTC+02:00:00) Europe/Nicosia", TimeZoneInfo::GetSystemTimeZones()[354].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[354].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[354].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[354].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[354].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Oslo) {
    ASSERT_EQ("Europe/Oslo", TimeZoneInfo::GetSystemTimeZones()[355].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Oslo", TimeZoneInfo::GetSystemTimeZones()[355].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[355].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[355].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[355].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[355].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Paris) {
    ASSERT_EQ("Europe/Paris", TimeZoneInfo::GetSystemTimeZones()[356].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Paris", TimeZoneInfo::GetSystemTimeZones()[356].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[356].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[356].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[356].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[356].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Podgorica) {
    ASSERT_EQ("Europe/Podgorica", TimeZoneInfo::GetSystemTimeZones()[357].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Podgorica", TimeZoneInfo::GetSystemTimeZones()[357].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[357].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[357].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[357].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[357].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Prague) {
    ASSERT_EQ("Europe/Prague", TimeZoneInfo::GetSystemTimeZones()[358].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Prague", TimeZoneInfo::GetSystemTimeZones()[358].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[358].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[358].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[358].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[358].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Riga) {
    ASSERT_EQ("Europe/Riga", TimeZoneInfo::GetSystemTimeZones()[359].Id());
    ASSERT_EQ("(UTC+02:00:00) Europe/Riga", TimeZoneInfo::GetSystemTimeZones()[359].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[359].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[359].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[359].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[359].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Rome) {
    ASSERT_EQ("Europe/Rome", TimeZoneInfo::GetSystemTimeZones()[360].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Rome", TimeZoneInfo::GetSystemTimeZones()[360].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[360].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[360].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[360].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[360].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Samara) {
    ASSERT_EQ("Europe/Samara", TimeZoneInfo::GetSystemTimeZones()[361].Id());
    ASSERT_EQ("(UTC+04:00:00) Europe/Samara", TimeZoneInfo::GetSystemTimeZones()[361].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[361].DaylightName());
    ASSERT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[361].BaseUtcOffset().ToString());
    ASSERT_EQ("SAMT", TimeZoneInfo::GetSystemTimeZones()[361].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[361].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_San_Marino) {
    ASSERT_EQ("Europe/San_Marino", TimeZoneInfo::GetSystemTimeZones()[362].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/San_Marino", TimeZoneInfo::GetSystemTimeZones()[362].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[362].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[362].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[362].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[362].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Sarajevo) {
    ASSERT_EQ("Europe/Sarajevo", TimeZoneInfo::GetSystemTimeZones()[363].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Sarajevo", TimeZoneInfo::GetSystemTimeZones()[363].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[363].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[363].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[363].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[363].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Simferopol) {
    ASSERT_EQ("Europe/Simferopol", TimeZoneInfo::GetSystemTimeZones()[364].Id());
    ASSERT_EQ("(UTC+02:00:00) Europe/Simferopol", TimeZoneInfo::GetSystemTimeZones()[364].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[364].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[364].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[364].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[364].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Skopje) {
    ASSERT_EQ("Europe/Skopje", TimeZoneInfo::GetSystemTimeZones()[365].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Skopje", TimeZoneInfo::GetSystemTimeZones()[365].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[365].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[365].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[365].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[365].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Sofia) {
    ASSERT_EQ("Europe/Sofia", TimeZoneInfo::GetSystemTimeZones()[366].Id());
    ASSERT_EQ("(UTC+02:00:00) Europe/Sofia", TimeZoneInfo::GetSystemTimeZones()[366].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[366].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[366].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[366].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[366].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Stockholm) {
    ASSERT_EQ("Europe/Stockholm", TimeZoneInfo::GetSystemTimeZones()[367].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Stockholm", TimeZoneInfo::GetSystemTimeZones()[367].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[367].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[367].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[367].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[367].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Tallinn) {
    ASSERT_EQ("Europe/Tallinn", TimeZoneInfo::GetSystemTimeZones()[368].Id());
    ASSERT_EQ("(UTC+02:00:00) Europe/Tallinn", TimeZoneInfo::GetSystemTimeZones()[368].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[368].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[368].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[368].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[368].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Tirane) {
    ASSERT_EQ("Europe/Tirane", TimeZoneInfo::GetSystemTimeZones()[369].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Tirane", TimeZoneInfo::GetSystemTimeZones()[369].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[369].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[369].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[369].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[369].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Tiraspol) {
    ASSERT_EQ("Europe/Tiraspol", TimeZoneInfo::GetSystemTimeZones()[370].Id());
    ASSERT_EQ("(UTC+02:00:00) Europe/Tiraspol", TimeZoneInfo::GetSystemTimeZones()[370].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[370].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[370].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[370].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[370].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Uzhgorod) {
    ASSERT_EQ("Europe/Uzhgorod", TimeZoneInfo::GetSystemTimeZones()[371].Id());
    ASSERT_EQ("(UTC+02:00:00) Europe/Uzhgorod", TimeZoneInfo::GetSystemTimeZones()[371].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[371].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[371].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[371].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[371].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Vaduz) {
    ASSERT_EQ("Europe/Vaduz", TimeZoneInfo::GetSystemTimeZones()[372].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Vaduz", TimeZoneInfo::GetSystemTimeZones()[372].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[372].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[372].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[372].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[372].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Vatican) {
    ASSERT_EQ("Europe/Vatican", TimeZoneInfo::GetSystemTimeZones()[373].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Vatican", TimeZoneInfo::GetSystemTimeZones()[373].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[373].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[373].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[373].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[373].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Vienna) {
    ASSERT_EQ("Europe/Vienna", TimeZoneInfo::GetSystemTimeZones()[374].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Vienna", TimeZoneInfo::GetSystemTimeZones()[374].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[374].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[374].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[374].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[374].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Vilnius) {
    ASSERT_EQ("Europe/Vilnius", TimeZoneInfo::GetSystemTimeZones()[375].Id());
    ASSERT_EQ("(UTC+02:00:00) Europe/Vilnius", TimeZoneInfo::GetSystemTimeZones()[375].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[375].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[375].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[375].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[375].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Volgograd) {
    ASSERT_EQ("Europe/Volgograd", TimeZoneInfo::GetSystemTimeZones()[376].Id());
    ASSERT_EQ("(UTC+04:00:00) Europe/Volgograd", TimeZoneInfo::GetSystemTimeZones()[376].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[376].DaylightName());
    ASSERT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[376].BaseUtcOffset().ToString());
    ASSERT_EQ("VOLT", TimeZoneInfo::GetSystemTimeZones()[376].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[376].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Warsaw) {
    ASSERT_EQ("Europe/Warsaw", TimeZoneInfo::GetSystemTimeZones()[377].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Warsaw", TimeZoneInfo::GetSystemTimeZones()[377].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[377].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[377].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[377].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[377].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Zagreb) {
    ASSERT_EQ("Europe/Zagreb", TimeZoneInfo::GetSystemTimeZones()[378].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Zagreb", TimeZoneInfo::GetSystemTimeZones()[378].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[378].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[378].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[378].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[378].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Zaporozhye) {
    ASSERT_EQ("Europe/Zaporozhye", TimeZoneInfo::GetSystemTimeZones()[379].Id());
    ASSERT_EQ("(UTC+02:00:00) Europe/Zaporozhye", TimeZoneInfo::GetSystemTimeZones()[379].DisplayName());
    ASSERT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[379].DaylightName());
    ASSERT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[379].BaseUtcOffset().ToString());
    ASSERT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[379].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[379].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesEurope_Zurich) {
    ASSERT_EQ("Europe/Zurich", TimeZoneInfo::GetSystemTimeZones()[380].Id());
    ASSERT_EQ("(UTC+01:00:00) Europe/Zurich", TimeZoneInfo::GetSystemTimeZones()[380].DisplayName());
    ASSERT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[380].DaylightName());
    ASSERT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[380].BaseUtcOffset().ToString());
    ASSERT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[380].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[380].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesIndian_Antananarivo) {
    ASSERT_EQ("Indian/Antananarivo", TimeZoneInfo::GetSystemTimeZones()[381].Id());
    ASSERT_EQ("(UTC+03:00:00) Indian/Antananarivo", TimeZoneInfo::GetSystemTimeZones()[381].DisplayName());
    ASSERT_EQ("EAST", TimeZoneInfo::GetSystemTimeZones()[381].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[381].BaseUtcOffset().ToString());
    ASSERT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[381].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[381].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesIndian_Chagos) {
    ASSERT_EQ("Indian/Chagos", TimeZoneInfo::GetSystemTimeZones()[382].Id());
    ASSERT_EQ("(UTC+06:00:00) Indian/Chagos", TimeZoneInfo::GetSystemTimeZones()[382].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[382].DaylightName());
    ASSERT_EQ("06:00:00", TimeZoneInfo::GetSystemTimeZones()[382].BaseUtcOffset().ToString());
    ASSERT_EQ("IOT", TimeZoneInfo::GetSystemTimeZones()[382].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[382].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesIndian_Christmas) {
    ASSERT_EQ("Indian/Christmas", TimeZoneInfo::GetSystemTimeZones()[383].Id());
    ASSERT_EQ("(UTC+07:00:00) Indian/Christmas", TimeZoneInfo::GetSystemTimeZones()[383].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[383].DaylightName());
    ASSERT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[383].BaseUtcOffset().ToString());
    ASSERT_EQ("CXT", TimeZoneInfo::GetSystemTimeZones()[383].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[383].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesIndian_Cocos) {
    ASSERT_EQ("Indian/Cocos", TimeZoneInfo::GetSystemTimeZones()[384].Id());
    ASSERT_EQ("(UTC+06:30:00) Indian/Cocos", TimeZoneInfo::GetSystemTimeZones()[384].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[384].DaylightName());
    ASSERT_EQ("06:30:00", TimeZoneInfo::GetSystemTimeZones()[384].BaseUtcOffset().ToString());
    ASSERT_EQ("CCT", TimeZoneInfo::GetSystemTimeZones()[384].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[384].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesIndian_Comoro) {
    ASSERT_EQ("Indian/Comoro", TimeZoneInfo::GetSystemTimeZones()[385].Id());
    ASSERT_EQ("(UTC+03:00:00) Indian/Comoro", TimeZoneInfo::GetSystemTimeZones()[385].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[385].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[385].BaseUtcOffset().ToString());
    ASSERT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[385].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[385].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesIndian_Kerguelen) {
    ASSERT_EQ("Indian/Kerguelen", TimeZoneInfo::GetSystemTimeZones()[386].Id());
    ASSERT_EQ("(UTC+05:00:00) Indian/Kerguelen", TimeZoneInfo::GetSystemTimeZones()[386].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[386].DaylightName());
    ASSERT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[386].BaseUtcOffset().ToString());
    ASSERT_EQ("TFT", TimeZoneInfo::GetSystemTimeZones()[386].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[386].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesIndian_Mahe) {
    ASSERT_EQ("Indian/Mahe", TimeZoneInfo::GetSystemTimeZones()[387].Id());
    ASSERT_EQ("(UTC+04:00:00) Indian/Mahe", TimeZoneInfo::GetSystemTimeZones()[387].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[387].DaylightName());
    ASSERT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[387].BaseUtcOffset().ToString());
    ASSERT_EQ("SCT", TimeZoneInfo::GetSystemTimeZones()[387].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[387].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesIndian_Maldives) {
    ASSERT_EQ("Indian/Maldives", TimeZoneInfo::GetSystemTimeZones()[388].Id());
    ASSERT_EQ("(UTC+05:00:00) Indian/Maldives", TimeZoneInfo::GetSystemTimeZones()[388].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[388].DaylightName());
    ASSERT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[388].BaseUtcOffset().ToString());
    ASSERT_EQ("MVT", TimeZoneInfo::GetSystemTimeZones()[388].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[388].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesIndian_Mauritius) {
    ASSERT_EQ("Indian/Mauritius", TimeZoneInfo::GetSystemTimeZones()[389].Id());
    ASSERT_EQ("(UTC+04:00:00) Indian/Mauritius", TimeZoneInfo::GetSystemTimeZones()[389].DisplayName());
    ASSERT_EQ("MUST", TimeZoneInfo::GetSystemTimeZones()[389].DaylightName());
    ASSERT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[389].BaseUtcOffset().ToString());
    ASSERT_EQ("MUT", TimeZoneInfo::GetSystemTimeZones()[389].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[389].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesIndian_Mayotte) {
    ASSERT_EQ("Indian/Mayotte", TimeZoneInfo::GetSystemTimeZones()[390].Id());
    ASSERT_EQ("(UTC+03:00:00) Indian/Mayotte", TimeZoneInfo::GetSystemTimeZones()[390].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[390].DaylightName());
    ASSERT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[390].BaseUtcOffset().ToString());
    ASSERT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[390].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[390].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesIndian_Reunion) {
    ASSERT_EQ("Indian/Reunion", TimeZoneInfo::GetSystemTimeZones()[391].Id());
    ASSERT_EQ("(UTC+04:00:00) Indian/Reunion", TimeZoneInfo::GetSystemTimeZones()[391].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[391].DaylightName());
    ASSERT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[391].BaseUtcOffset().ToString());
    ASSERT_EQ("RET", TimeZoneInfo::GetSystemTimeZones()[391].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[391].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesMexico_BajaNorte) {
    ASSERT_EQ("Mexico/BajaNorte", TimeZoneInfo::GetSystemTimeZones()[392].Id());
    ASSERT_EQ("(UTC-08:00:00) Mexico/BajaNorte", TimeZoneInfo::GetSystemTimeZones()[392].DisplayName());
    ASSERT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[392].DaylightName());
    ASSERT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[392].BaseUtcOffset().ToString());
    ASSERT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[392].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[392].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesMexico_BajaSur) {
    ASSERT_EQ("Mexico/BajaSur", TimeZoneInfo::GetSystemTimeZones()[393].Id());
    ASSERT_EQ("(UTC-07:00:00) Mexico/BajaSur", TimeZoneInfo::GetSystemTimeZones()[393].DisplayName());
    ASSERT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[393].DaylightName());
    ASSERT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[393].BaseUtcOffset().ToString());
    ASSERT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[393].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[393].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesMexico_General) {
    ASSERT_EQ("Mexico/General", TimeZoneInfo::GetSystemTimeZones()[394].Id());
    ASSERT_EQ("(UTC-06:00:00) Mexico/General", TimeZoneInfo::GetSystemTimeZones()[394].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[394].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[394].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[394].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[394].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Apia) {
    ASSERT_EQ("Pacific/Apia", TimeZoneInfo::GetSystemTimeZones()[395].Id());
    ASSERT_EQ("(UTC+13:00:00) Pacific/Apia", TimeZoneInfo::GetSystemTimeZones()[395].DisplayName());
    ASSERT_EQ("WSDT", TimeZoneInfo::GetSystemTimeZones()[395].DaylightName());
    ASSERT_EQ("13:00:00", TimeZoneInfo::GetSystemTimeZones()[395].BaseUtcOffset().ToString());
    ASSERT_EQ("WST", TimeZoneInfo::GetSystemTimeZones()[395].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[395].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Auckland) {
    ASSERT_EQ("Pacific/Auckland", TimeZoneInfo::GetSystemTimeZones()[396].Id());
    ASSERT_EQ("(UTC+12:00:00) Pacific/Auckland", TimeZoneInfo::GetSystemTimeZones()[396].DisplayName());
    ASSERT_EQ("NZDT", TimeZoneInfo::GetSystemTimeZones()[396].DaylightName());
    ASSERT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[396].BaseUtcOffset().ToString());
    ASSERT_EQ("NZST", TimeZoneInfo::GetSystemTimeZones()[396].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[396].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Chatham) {
    ASSERT_EQ("Pacific/Chatham", TimeZoneInfo::GetSystemTimeZones()[397].Id());
    ASSERT_EQ("(UTC+12:45:00) Pacific/Chatham", TimeZoneInfo::GetSystemTimeZones()[397].DisplayName());
    ASSERT_EQ("CHADT", TimeZoneInfo::GetSystemTimeZones()[397].DaylightName());
    ASSERT_EQ("12:45:00", TimeZoneInfo::GetSystemTimeZones()[397].BaseUtcOffset().ToString());
    ASSERT_EQ("CHAST", TimeZoneInfo::GetSystemTimeZones()[397].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[397].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Chuuk) {
    ASSERT_EQ("Pacific/Chuuk", TimeZoneInfo::GetSystemTimeZones()[398].Id());
    ASSERT_EQ("(UTC+10:00:00) Pacific/Chuuk", TimeZoneInfo::GetSystemTimeZones()[398].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[398].DaylightName());
    ASSERT_EQ("10:00:00", TimeZoneInfo::GetSystemTimeZones()[398].BaseUtcOffset().ToString());
    ASSERT_EQ("CHUT", TimeZoneInfo::GetSystemTimeZones()[398].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[398].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Easter) {
    ASSERT_EQ("Pacific/Easter", TimeZoneInfo::GetSystemTimeZones()[399].Id());
    ASSERT_EQ("(UTC-06:00:00) Pacific/Easter", TimeZoneInfo::GetSystemTimeZones()[399].DisplayName());
    ASSERT_EQ("EASST", TimeZoneInfo::GetSystemTimeZones()[399].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[399].BaseUtcOffset().ToString());
    ASSERT_EQ("EAST", TimeZoneInfo::GetSystemTimeZones()[399].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[399].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Efate) {
    ASSERT_EQ("Pacific/Efate", TimeZoneInfo::GetSystemTimeZones()[400].Id());
    ASSERT_EQ("(UTC+11:00:00) Pacific/Efate", TimeZoneInfo::GetSystemTimeZones()[400].DisplayName());
    ASSERT_EQ("VUST", TimeZoneInfo::GetSystemTimeZones()[400].DaylightName());
    ASSERT_EQ("11:00:00", TimeZoneInfo::GetSystemTimeZones()[400].BaseUtcOffset().ToString());
    ASSERT_EQ("VUT", TimeZoneInfo::GetSystemTimeZones()[400].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[400].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Enderbury) {
    ASSERT_EQ("Pacific/Enderbury", TimeZoneInfo::GetSystemTimeZones()[401].Id());
    ASSERT_EQ("(UTC+13:00:00) Pacific/Enderbury", TimeZoneInfo::GetSystemTimeZones()[401].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[401].DaylightName());
    ASSERT_EQ("13:00:00", TimeZoneInfo::GetSystemTimeZones()[401].BaseUtcOffset().ToString());
    ASSERT_EQ("PHOT", TimeZoneInfo::GetSystemTimeZones()[401].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[401].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Fakaofo) {
    ASSERT_EQ("Pacific/Fakaofo", TimeZoneInfo::GetSystemTimeZones()[402].Id());
    ASSERT_EQ("(UTC+13:00:00) Pacific/Fakaofo", TimeZoneInfo::GetSystemTimeZones()[402].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[402].DaylightName());
    ASSERT_EQ("13:00:00", TimeZoneInfo::GetSystemTimeZones()[402].BaseUtcOffset().ToString());
    ASSERT_EQ("TKT", TimeZoneInfo::GetSystemTimeZones()[402].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[402].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Fiji) {
    ASSERT_EQ("Pacific/Fiji", TimeZoneInfo::GetSystemTimeZones()[403].Id());
    ASSERT_EQ("(UTC+12:00:00) Pacific/Fiji", TimeZoneInfo::GetSystemTimeZones()[403].DisplayName());
    ASSERT_EQ("FJST", TimeZoneInfo::GetSystemTimeZones()[403].DaylightName());
    ASSERT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[403].BaseUtcOffset().ToString());
    ASSERT_EQ("FJT", TimeZoneInfo::GetSystemTimeZones()[403].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[403].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Funafuti) {
    ASSERT_EQ("Pacific/Funafuti", TimeZoneInfo::GetSystemTimeZones()[404].Id());
    ASSERT_EQ("(UTC+12:00:00) Pacific/Funafuti", TimeZoneInfo::GetSystemTimeZones()[404].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[404].DaylightName());
    ASSERT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[404].BaseUtcOffset().ToString());
    ASSERT_EQ("TVT", TimeZoneInfo::GetSystemTimeZones()[404].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[404].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Galapagos) {
    ASSERT_EQ("Pacific/Galapagos", TimeZoneInfo::GetSystemTimeZones()[405].Id());
    ASSERT_EQ("(UTC-06:00:00) Pacific/Galapagos", TimeZoneInfo::GetSystemTimeZones()[405].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[405].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[405].BaseUtcOffset().ToString());
    ASSERT_EQ("GALT", TimeZoneInfo::GetSystemTimeZones()[405].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[405].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Gambier) {
    ASSERT_EQ("Pacific/Gambier", TimeZoneInfo::GetSystemTimeZones()[406].Id());
    ASSERT_EQ("(UTC-09:00:00) Pacific/Gambier", TimeZoneInfo::GetSystemTimeZones()[406].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[406].DaylightName());
    ASSERT_EQ("-09:00:00", TimeZoneInfo::GetSystemTimeZones()[406].BaseUtcOffset().ToString());
    ASSERT_EQ("GAMT", TimeZoneInfo::GetSystemTimeZones()[406].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[406].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Guadalcanal) {
    ASSERT_EQ("Pacific/Guadalcanal", TimeZoneInfo::GetSystemTimeZones()[407].Id());
    ASSERT_EQ("(UTC+11:00:00) Pacific/Guadalcanal", TimeZoneInfo::GetSystemTimeZones()[407].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[407].DaylightName());
    ASSERT_EQ("11:00:00", TimeZoneInfo::GetSystemTimeZones()[407].BaseUtcOffset().ToString());
    ASSERT_EQ("SBT", TimeZoneInfo::GetSystemTimeZones()[407].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[407].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Guam) {
    ASSERT_EQ("Pacific/Guam", TimeZoneInfo::GetSystemTimeZones()[408].Id());
    ASSERT_EQ("(UTC+10:00:00) Pacific/Guam", TimeZoneInfo::GetSystemTimeZones()[408].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[408].DaylightName());
    ASSERT_EQ("10:00:00", TimeZoneInfo::GetSystemTimeZones()[408].BaseUtcOffset().ToString());
    ASSERT_EQ("ChST", TimeZoneInfo::GetSystemTimeZones()[408].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[408].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Honolulu) {
    ASSERT_EQ("Pacific/Honolulu", TimeZoneInfo::GetSystemTimeZones()[409].Id());
    ASSERT_EQ("(UTC-10:00:00) Pacific/Honolulu", TimeZoneInfo::GetSystemTimeZones()[409].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[409].DaylightName());
    ASSERT_EQ("-10:00:00", TimeZoneInfo::GetSystemTimeZones()[409].BaseUtcOffset().ToString());
    ASSERT_EQ("HST", TimeZoneInfo::GetSystemTimeZones()[409].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[409].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Johnston) {
    ASSERT_EQ("Pacific/Johnston", TimeZoneInfo::GetSystemTimeZones()[410].Id());
    ASSERT_EQ("(UTC-10:00:00) Pacific/Johnston", TimeZoneInfo::GetSystemTimeZones()[410].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[410].DaylightName());
    ASSERT_EQ("-10:00:00", TimeZoneInfo::GetSystemTimeZones()[410].BaseUtcOffset().ToString());
    ASSERT_EQ("HST", TimeZoneInfo::GetSystemTimeZones()[410].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[410].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Kiritimati) {
    ASSERT_EQ("Pacific/Kiritimati", TimeZoneInfo::GetSystemTimeZones()[411].Id());
    ASSERT_EQ("(UTC+14:00:00) Pacific/Kiritimati", TimeZoneInfo::GetSystemTimeZones()[411].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[411].DaylightName());
    ASSERT_EQ("14:00:00", TimeZoneInfo::GetSystemTimeZones()[411].BaseUtcOffset().ToString());
    ASSERT_EQ("LINT", TimeZoneInfo::GetSystemTimeZones()[411].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[411].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Kosrae) {
    ASSERT_EQ("Pacific/Kosrae", TimeZoneInfo::GetSystemTimeZones()[412].Id());
    ASSERT_EQ("(UTC+11:00:00) Pacific/Kosrae", TimeZoneInfo::GetSystemTimeZones()[412].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[412].DaylightName());
    ASSERT_EQ("11:00:00", TimeZoneInfo::GetSystemTimeZones()[412].BaseUtcOffset().ToString());
    ASSERT_EQ("KOST", TimeZoneInfo::GetSystemTimeZones()[412].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[412].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Kwajalein) {
    ASSERT_EQ("Pacific/Kwajalein", TimeZoneInfo::GetSystemTimeZones()[413].Id());
    ASSERT_EQ("(UTC+12:00:00) Pacific/Kwajalein", TimeZoneInfo::GetSystemTimeZones()[413].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[413].DaylightName());
    ASSERT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[413].BaseUtcOffset().ToString());
    ASSERT_EQ("MHT", TimeZoneInfo::GetSystemTimeZones()[413].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[413].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Majuro) {
    ASSERT_EQ("Pacific/Majuro", TimeZoneInfo::GetSystemTimeZones()[414].Id());
    ASSERT_EQ("(UTC+12:00:00) Pacific/Majuro", TimeZoneInfo::GetSystemTimeZones()[414].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[414].DaylightName());
    ASSERT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[414].BaseUtcOffset().ToString());
    ASSERT_EQ("MHT", TimeZoneInfo::GetSystemTimeZones()[414].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[414].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Marquesas) {
    ASSERT_EQ("Pacific/Marquesas", TimeZoneInfo::GetSystemTimeZones()[415].Id());
    ASSERT_EQ("(UTC-09:30:00) Pacific/Marquesas", TimeZoneInfo::GetSystemTimeZones()[415].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[415].DaylightName());
    ASSERT_EQ("-09:30:00", TimeZoneInfo::GetSystemTimeZones()[415].BaseUtcOffset().ToString());
    ASSERT_EQ("MART", TimeZoneInfo::GetSystemTimeZones()[415].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[415].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Midway) {
    ASSERT_EQ("Pacific/Midway", TimeZoneInfo::GetSystemTimeZones()[416].Id());
    ASSERT_EQ("(UTC-11:00:00) Pacific/Midway", TimeZoneInfo::GetSystemTimeZones()[416].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[416].DaylightName());
    ASSERT_EQ("-11:00:00", TimeZoneInfo::GetSystemTimeZones()[416].BaseUtcOffset().ToString());
    ASSERT_EQ("SST", TimeZoneInfo::GetSystemTimeZones()[416].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[416].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Nauru) {
    ASSERT_EQ("Pacific/Nauru", TimeZoneInfo::GetSystemTimeZones()[417].Id());
    ASSERT_EQ("(UTC+12:00:00) Pacific/Nauru", TimeZoneInfo::GetSystemTimeZones()[417].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[417].DaylightName());
    ASSERT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[417].BaseUtcOffset().ToString());
    ASSERT_EQ("NRT", TimeZoneInfo::GetSystemTimeZones()[417].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[417].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Niue) {
    ASSERT_EQ("Pacific/Niue", TimeZoneInfo::GetSystemTimeZones()[418].Id());
    ASSERT_EQ("(UTC-11:00:00) Pacific/Niue", TimeZoneInfo::GetSystemTimeZones()[418].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[418].DaylightName());
    ASSERT_EQ("-11:00:00", TimeZoneInfo::GetSystemTimeZones()[418].BaseUtcOffset().ToString());
    ASSERT_EQ("NUT", TimeZoneInfo::GetSystemTimeZones()[418].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[418].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Norfolk) {
    ASSERT_EQ("Pacific/Norfolk", TimeZoneInfo::GetSystemTimeZones()[419].Id());
    ASSERT_EQ("(UTC+11:30:00) Pacific/Norfolk", TimeZoneInfo::GetSystemTimeZones()[419].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[419].DaylightName());
    ASSERT_EQ("11:30:00", TimeZoneInfo::GetSystemTimeZones()[419].BaseUtcOffset().ToString());
    ASSERT_EQ("NFT", TimeZoneInfo::GetSystemTimeZones()[419].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[419].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Noumea) {
    ASSERT_EQ("Pacific/Noumea", TimeZoneInfo::GetSystemTimeZones()[420].Id());
    ASSERT_EQ("(UTC+11:00:00) Pacific/Noumea", TimeZoneInfo::GetSystemTimeZones()[420].DisplayName());
    ASSERT_EQ("NCST", TimeZoneInfo::GetSystemTimeZones()[420].DaylightName());
    ASSERT_EQ("11:00:00", TimeZoneInfo::GetSystemTimeZones()[420].BaseUtcOffset().ToString());
    ASSERT_EQ("NCT", TimeZoneInfo::GetSystemTimeZones()[420].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[420].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Pago_Pago) {
    ASSERT_EQ("Pacific/Pago_Pago", TimeZoneInfo::GetSystemTimeZones()[421].Id());
    ASSERT_EQ("(UTC-11:00:00) Pacific/Pago_Pago", TimeZoneInfo::GetSystemTimeZones()[421].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[421].DaylightName());
    ASSERT_EQ("-11:00:00", TimeZoneInfo::GetSystemTimeZones()[421].BaseUtcOffset().ToString());
    ASSERT_EQ("SST", TimeZoneInfo::GetSystemTimeZones()[421].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[421].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Palau) {
    ASSERT_EQ("Pacific/Palau", TimeZoneInfo::GetSystemTimeZones()[422].Id());
    ASSERT_EQ("(UTC+09:00:00) Pacific/Palau", TimeZoneInfo::GetSystemTimeZones()[422].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[422].DaylightName());
    ASSERT_EQ("09:00:00", TimeZoneInfo::GetSystemTimeZones()[422].BaseUtcOffset().ToString());
    ASSERT_EQ("PWT", TimeZoneInfo::GetSystemTimeZones()[422].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[422].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Pitcairn) {
    ASSERT_EQ("Pacific/Pitcairn", TimeZoneInfo::GetSystemTimeZones()[423].Id());
    ASSERT_EQ("(UTC-08:00:00) Pacific/Pitcairn", TimeZoneInfo::GetSystemTimeZones()[423].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[423].DaylightName());
    ASSERT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[423].BaseUtcOffset().ToString());
    ASSERT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[423].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[423].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Pohnpei) {
    ASSERT_EQ("Pacific/Pohnpei", TimeZoneInfo::GetSystemTimeZones()[424].Id());
    ASSERT_EQ("(UTC+11:00:00) Pacific/Pohnpei", TimeZoneInfo::GetSystemTimeZones()[424].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[424].DaylightName());
    ASSERT_EQ("11:00:00", TimeZoneInfo::GetSystemTimeZones()[424].BaseUtcOffset().ToString());
    ASSERT_EQ("PONT", TimeZoneInfo::GetSystemTimeZones()[424].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[424].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Ponape) {
    ASSERT_EQ("Pacific/Ponape", TimeZoneInfo::GetSystemTimeZones()[425].Id());
    ASSERT_EQ("(UTC+11:00:00) Pacific/Ponape", TimeZoneInfo::GetSystemTimeZones()[425].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[425].DaylightName());
    ASSERT_EQ("11:00:00", TimeZoneInfo::GetSystemTimeZones()[425].BaseUtcOffset().ToString());
    ASSERT_EQ("PONT", TimeZoneInfo::GetSystemTimeZones()[425].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[425].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Port_Moresby) {
    ASSERT_EQ("Pacific/Port_Moresby", TimeZoneInfo::GetSystemTimeZones()[426].Id());
    ASSERT_EQ("(UTC+10:00:00) Pacific/Port_Moresby", TimeZoneInfo::GetSystemTimeZones()[426].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[426].DaylightName());
    ASSERT_EQ("10:00:00", TimeZoneInfo::GetSystemTimeZones()[426].BaseUtcOffset().ToString());
    ASSERT_EQ("PGT", TimeZoneInfo::GetSystemTimeZones()[426].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[426].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Rarotonga) {
    ASSERT_EQ("Pacific/Rarotonga", TimeZoneInfo::GetSystemTimeZones()[427].Id());
    ASSERT_EQ("(UTC-10:00:00) Pacific/Rarotonga", TimeZoneInfo::GetSystemTimeZones()[427].DisplayName());
    ASSERT_EQ("CKHST", TimeZoneInfo::GetSystemTimeZones()[427].DaylightName());
    ASSERT_EQ("-10:00:00", TimeZoneInfo::GetSystemTimeZones()[427].BaseUtcOffset().ToString());
    ASSERT_EQ("CKT", TimeZoneInfo::GetSystemTimeZones()[427].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[427].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Saipan) {
    ASSERT_EQ("Pacific/Saipan", TimeZoneInfo::GetSystemTimeZones()[428].Id());
    ASSERT_EQ("(UTC+10:00:00) Pacific/Saipan", TimeZoneInfo::GetSystemTimeZones()[428].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[428].DaylightName());
    ASSERT_EQ("10:00:00", TimeZoneInfo::GetSystemTimeZones()[428].BaseUtcOffset().ToString());
    ASSERT_EQ("ChST", TimeZoneInfo::GetSystemTimeZones()[428].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[428].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Samoa) {
    ASSERT_EQ("Pacific/Samoa", TimeZoneInfo::GetSystemTimeZones()[429].Id());
    ASSERT_EQ("(UTC-11:00:00) Pacific/Samoa", TimeZoneInfo::GetSystemTimeZones()[429].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[429].DaylightName());
    ASSERT_EQ("-11:00:00", TimeZoneInfo::GetSystemTimeZones()[429].BaseUtcOffset().ToString());
    ASSERT_EQ("SST", TimeZoneInfo::GetSystemTimeZones()[429].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[429].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Tahiti) {
    ASSERT_EQ("Pacific/Tahiti", TimeZoneInfo::GetSystemTimeZones()[430].Id());
    ASSERT_EQ("(UTC-10:00:00) Pacific/Tahiti", TimeZoneInfo::GetSystemTimeZones()[430].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[430].DaylightName());
    ASSERT_EQ("-10:00:00", TimeZoneInfo::GetSystemTimeZones()[430].BaseUtcOffset().ToString());
    ASSERT_EQ("TAHT", TimeZoneInfo::GetSystemTimeZones()[430].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[430].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Tarawa) {
    ASSERT_EQ("Pacific/Tarawa", TimeZoneInfo::GetSystemTimeZones()[431].Id());
    ASSERT_EQ("(UTC+12:00:00) Pacific/Tarawa", TimeZoneInfo::GetSystemTimeZones()[431].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[431].DaylightName());
    ASSERT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[431].BaseUtcOffset().ToString());
    ASSERT_EQ("GILT", TimeZoneInfo::GetSystemTimeZones()[431].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[431].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Tongatapu) {
    ASSERT_EQ("Pacific/Tongatapu", TimeZoneInfo::GetSystemTimeZones()[432].Id());
    ASSERT_EQ("(UTC+13:00:00) Pacific/Tongatapu", TimeZoneInfo::GetSystemTimeZones()[432].DisplayName());
    ASSERT_EQ("TOST", TimeZoneInfo::GetSystemTimeZones()[432].DaylightName());
    ASSERT_EQ("13:00:00", TimeZoneInfo::GetSystemTimeZones()[432].BaseUtcOffset().ToString());
    ASSERT_EQ("TOT", TimeZoneInfo::GetSystemTimeZones()[432].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[432].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Truk) {
    ASSERT_EQ("Pacific/Truk", TimeZoneInfo::GetSystemTimeZones()[433].Id());
    ASSERT_EQ("(UTC+10:00:00) Pacific/Truk", TimeZoneInfo::GetSystemTimeZones()[433].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[433].DaylightName());
    ASSERT_EQ("10:00:00", TimeZoneInfo::GetSystemTimeZones()[433].BaseUtcOffset().ToString());
    ASSERT_EQ("CHUT", TimeZoneInfo::GetSystemTimeZones()[433].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[433].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Wake) {
    ASSERT_EQ("Pacific/Wake", TimeZoneInfo::GetSystemTimeZones()[434].Id());
    ASSERT_EQ("(UTC+12:00:00) Pacific/Wake", TimeZoneInfo::GetSystemTimeZones()[434].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[434].DaylightName());
    ASSERT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[434].BaseUtcOffset().ToString());
    ASSERT_EQ("WAKT", TimeZoneInfo::GetSystemTimeZones()[434].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[434].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Wallis) {
    ASSERT_EQ("Pacific/Wallis", TimeZoneInfo::GetSystemTimeZones()[435].Id());
    ASSERT_EQ("(UTC+12:00:00) Pacific/Wallis", TimeZoneInfo::GetSystemTimeZones()[435].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[435].DaylightName());
    ASSERT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[435].BaseUtcOffset().ToString());
    ASSERT_EQ("WFT", TimeZoneInfo::GetSystemTimeZones()[435].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[435].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesPacific_Yap) {
    ASSERT_EQ("Pacific/Yap", TimeZoneInfo::GetSystemTimeZones()[436].Id());
    ASSERT_EQ("(UTC+10:00:00) Pacific/Yap", TimeZoneInfo::GetSystemTimeZones()[436].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[436].DaylightName());
    ASSERT_EQ("10:00:00", TimeZoneInfo::GetSystemTimeZones()[436].BaseUtcOffset().ToString());
    ASSERT_EQ("CHUT", TimeZoneInfo::GetSystemTimeZones()[436].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[436].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesUS_Alaska) {
    ASSERT_EQ("US/Alaska", TimeZoneInfo::GetSystemTimeZones()[437].Id());
    ASSERT_EQ("(UTC-09:00:00) US/Alaska", TimeZoneInfo::GetSystemTimeZones()[437].DisplayName());
    ASSERT_EQ("AKDT", TimeZoneInfo::GetSystemTimeZones()[437].DaylightName());
    ASSERT_EQ("-09:00:00", TimeZoneInfo::GetSystemTimeZones()[437].BaseUtcOffset().ToString());
    ASSERT_EQ("AKST", TimeZoneInfo::GetSystemTimeZones()[437].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[437].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesUS_Aleutian) {
    ASSERT_EQ("US/Aleutian", TimeZoneInfo::GetSystemTimeZones()[438].Id());
    ASSERT_EQ("(UTC-10:00:00) US/Aleutian", TimeZoneInfo::GetSystemTimeZones()[438].DisplayName());
    ASSERT_EQ("HADT", TimeZoneInfo::GetSystemTimeZones()[438].DaylightName());
    ASSERT_EQ("-10:00:00", TimeZoneInfo::GetSystemTimeZones()[438].BaseUtcOffset().ToString());
    ASSERT_EQ("HAST", TimeZoneInfo::GetSystemTimeZones()[438].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[438].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesUS_Arizona) {
    ASSERT_EQ("US/Arizona", TimeZoneInfo::GetSystemTimeZones()[439].Id());
    ASSERT_EQ("(UTC-07:00:00) US/Arizona", TimeZoneInfo::GetSystemTimeZones()[439].DisplayName());
    ASSERT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[439].DaylightName());
    ASSERT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[439].BaseUtcOffset().ToString());
    ASSERT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[439].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[439].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesUS_Central) {
    ASSERT_EQ("US/Central", TimeZoneInfo::GetSystemTimeZones()[440].Id());
    ASSERT_EQ("(UTC-06:00:00) US/Central", TimeZoneInfo::GetSystemTimeZones()[440].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[440].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[440].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[440].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[440].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesUS_East_Indiana) {
    ASSERT_EQ("US/East-Indiana", TimeZoneInfo::GetSystemTimeZones()[441].Id());
    ASSERT_EQ("(UTC-05:00:00) US/East-Indiana", TimeZoneInfo::GetSystemTimeZones()[441].DisplayName());
    ASSERT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[441].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[441].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[441].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[441].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesUS_Eastern) {
    ASSERT_EQ("US/Eastern", TimeZoneInfo::GetSystemTimeZones()[442].Id());
    ASSERT_EQ("(UTC-05:00:00) US/Eastern", TimeZoneInfo::GetSystemTimeZones()[442].DisplayName());
    ASSERT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[442].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[442].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[442].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[442].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesUS_Hawaii) {
    ASSERT_EQ("US/Hawaii", TimeZoneInfo::GetSystemTimeZones()[443].Id());
    ASSERT_EQ("(UTC-10:00:00) US/Hawaii", TimeZoneInfo::GetSystemTimeZones()[443].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[443].DaylightName());
    ASSERT_EQ("-10:00:00", TimeZoneInfo::GetSystemTimeZones()[443].BaseUtcOffset().ToString());
    ASSERT_EQ("HST", TimeZoneInfo::GetSystemTimeZones()[443].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[443].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesUS_Indiana_Starke) {
    ASSERT_EQ("US/Indiana-Starke", TimeZoneInfo::GetSystemTimeZones()[444].Id());
    ASSERT_EQ("(UTC-06:00:00) US/Indiana-Starke", TimeZoneInfo::GetSystemTimeZones()[444].DisplayName());
    ASSERT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[444].DaylightName());
    ASSERT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[444].BaseUtcOffset().ToString());
    ASSERT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[444].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[444].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesUS_Michigan) {
    ASSERT_EQ("US/Michigan", TimeZoneInfo::GetSystemTimeZones()[445].Id());
    ASSERT_EQ("(UTC-05:00:00) US/Michigan", TimeZoneInfo::GetSystemTimeZones()[445].DisplayName());
    ASSERT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[445].DaylightName());
    ASSERT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[445].BaseUtcOffset().ToString());
    ASSERT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[445].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[445].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesUS_Mountain) {
    ASSERT_EQ("US/Mountain", TimeZoneInfo::GetSystemTimeZones()[446].Id());
    ASSERT_EQ("(UTC-07:00:00) US/Mountain", TimeZoneInfo::GetSystemTimeZones()[446].DisplayName());
    ASSERT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[446].DaylightName());
    ASSERT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[446].BaseUtcOffset().ToString());
    ASSERT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[446].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[446].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesUS_Pacific) {
    ASSERT_EQ("US/Pacific", TimeZoneInfo::GetSystemTimeZones()[447].Id());
    ASSERT_EQ("(UTC-08:00:00) US/Pacific", TimeZoneInfo::GetSystemTimeZones()[447].DisplayName());
    ASSERT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[447].DaylightName());
    ASSERT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[447].BaseUtcOffset().ToString());
    ASSERT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[447].StandardName());
    ASSERT_TRUE(TimeZoneInfo::GetSystemTimeZones()[447].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfoTest, GetSystemTimeZonesUS_Samoa) {
    ASSERT_EQ("US/Samoa", TimeZoneInfo::GetSystemTimeZones()[448].Id());
    ASSERT_EQ("(UTC-11:00:00) US/Samoa", TimeZoneInfo::GetSystemTimeZones()[448].DisplayName());
    ASSERT_EQ("", TimeZoneInfo::GetSystemTimeZones()[448].DaylightName());
    ASSERT_EQ("-11:00:00", TimeZoneInfo::GetSystemTimeZones()[448].BaseUtcOffset().ToString());
    ASSERT_EQ("SST", TimeZoneInfo::GetSystemTimeZones()[448].StandardName());
    ASSERT_FALSE(TimeZoneInfo::GetSystemTimeZones()[448].SupportsDaylightSavingTime());
  }
}
