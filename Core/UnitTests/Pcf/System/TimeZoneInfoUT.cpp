#include <Pcf/System/TimeZoneInfo.hpp>
#include <Pcf/TUnit/Assert.hpp>
#include <Pcf/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  TEST(TimeZoneInfo, Local) {
    EXPECT_FALSE(string::IsNullOrEmpty(TimeZoneInfo::Local().Id()));
    EXPECT_FALSE(string::IsNullOrEmpty(TimeZoneInfo::Local().DaylightName()));
    EXPECT_FALSE(string::IsNullOrEmpty(TimeZoneInfo::Local().DisplayName()));
    EXPECT_FALSE(string::IsNullOrEmpty(TimeZoneInfo::Local().StandardName()));
    //Console::WriteLine(string::Format("Local : \"{0}\", {1}, \"{2}\", \"{3}\", \"{4}\", {5}", TimeZoneInfo::Local().Id(), TimeZoneInfo::Local().BaseUtcOffset(), TimeZoneInfo::Local().DaylightName(), TimeZoneInfo::Local().DisplayName(), TimeZoneInfo::Local().StandardName(), TimeZoneInfo::Local().SupportsDaylightSavingTime()));
  }
  
  TEST(TimeZoneInfo, Utc) {
    EXPECT_EQ("UTC", TimeZoneInfo::Utc().Id());
    EXPECT_EQ("", TimeZoneInfo::Utc().DaylightName());
    EXPECT_EQ("UTC", TimeZoneInfo::Utc().DisplayName());
    EXPECT_EQ("UTC", TimeZoneInfo::Utc().StandardName());
    EXPECT_EQ(0, TimeZoneInfo::Utc().BaseUtcOffset().Ticks());
    EXPECT_FALSE(TimeZoneInfo::Utc().SupportsDaylightSavingTime());
    //Console::WriteLine(string::Format("Utc : \"{0}\", {1}, \"{2}\", \"{3}\", \"{4}\", {5}", TimeZoneInfo::Utc().Id(), TimeZoneInfo::Utc().BaseUtcOffset(), TimeZoneInfo::Utc().DaylightName(), TimeZoneInfo::Utc().DisplayName(), TimeZoneInfo::Utc().StandardName(), TimeZoneInfo::Utc().SupportsDaylightSavingTime()));
  }
  
  TEST(TimeZoneInfo, TimeFindSystemTimeZoneById) {
    EXPECT_EQ(TimeZoneInfo::Local().Id(), TimeZoneInfo::TimeFindSystemTimeZoneById(TimeZoneInfo::Local().Id()).Id());
    EXPECT_EQ(TimeZoneInfo::Utc().Id(), TimeZoneInfo::TimeFindSystemTimeZoneById("UTC").Id());
    EXPECT_EQ("Africa/Abidjan", TimeZoneInfo::TimeFindSystemTimeZoneById("Africa/Abidjan").Id());
    EXPECT_EQ("Europe/Brussels", TimeZoneInfo::TimeFindSystemTimeZoneById("Europe/Brussels").Id());
    EXPECT_EQ("US/Pacific", TimeZoneInfo::TimeFindSystemTimeZoneById("US/Pacific").Id());
    EXPECT_EQ("US/Samoa", TimeZoneInfo::TimeFindSystemTimeZoneById("US/Samoa").Id());
    
   EXPECT_THROW(TimeZoneInfo::TimeFindSystemTimeZoneById("Any/Nothing"), TimeZoneNotFoundException);
    
    //Console::WriteLine(TimeZoneInfo::ConvertTimeToUtc(DateTime::Now));
    //Console::WriteLine(DateTime::Now + TimeZoneInfo::Local().BaseUtcOffset());
  }
  
  TEST(TimeZoneInfo, ConvertTimeToUtc) {
    DateTime now = DateTime::Now;
    EXPECT_EQ(now.ToUniversalTime(), TimeZoneInfo::ConvertTimeToUtc(now));

    //Console::WriteLine("Local {0}", now);
    //Console::WriteLine("Utc   {0}", TimeZoneInfo::ConvertTimeToUtc(now));
  }
  
  /*
  TEST(TimeZoneInfo, List) {
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
          expects += string.Format("  TEST(TimeZoneInfo, GetSystemTimeZones{0}) {{\n", item.Id.Replace(' ', '_').Replace('-', '_').Replace('(', '_').Replace(')', '_').Replace('.', '_').Replace('+', '_').Replace('/', '_'));
          expects += string.Format("    EXPECT_EQ(\"{0}\", TimeZoneInfo::GetSystemTimeZones()[{1}].Id());\n", item.Id, index);
          expects += string.Format("    EXPECT_EQ(\"{0} {1}\", TimeZoneInfo::GetSystemTimeZones()[{2}].DisplayName());\n", item.BaseUtcOffset.Ticks == 0 ? "(UTC)" : string.Format("(UTC{0}{1})", item.BaseUtcOffset.Ticks >= 0 ? "+" : "", item.BaseUtcOffset), item.DisplayName, index);
          expects += string.Format("    EXPECT_EQ(\"{0}\", TimeZoneInfo::GetSystemTimeZones()[{1}].DaylightName());\n", item.DaylightName, index);
          expects += string.Format("    EXPECT_EQ(\"{0}\", TimeZoneInfo::GetSystemTimeZones()[{1}].BaseUtcOffset().ToString());\n", item.BaseUtcOffset, index);
          expects += string.Format("    EXPECT_EQ(\"{0}\", TimeZoneInfo::GetSystemTimeZones()[{1}].StandardName());\n", item.StandardName, index);
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
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Abidjan) {
    EXPECT_EQ("Africa/Abidjan", TimeZoneInfo::GetSystemTimeZones()[0].Id());
    EXPECT_EQ("(UTC) Africa/Abidjan", TimeZoneInfo::GetSystemTimeZones()[0].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[0].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[0].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[0].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[0].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Accra) {
    EXPECT_EQ("Africa/Accra", TimeZoneInfo::GetSystemTimeZones()[1].Id());
    EXPECT_EQ("(UTC) Africa/Accra", TimeZoneInfo::GetSystemTimeZones()[1].DisplayName());
    EXPECT_EQ("GHST", TimeZoneInfo::GetSystemTimeZones()[1].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[1].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[1].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[1].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Addis_Ababa) {
    EXPECT_EQ("Africa/Addis_Ababa", TimeZoneInfo::GetSystemTimeZones()[2].Id());
    EXPECT_EQ("(UTC+03:00:00) Africa/Addis_Ababa", TimeZoneInfo::GetSystemTimeZones()[2].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[2].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[2].BaseUtcOffset().ToString());
    EXPECT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[2].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[2].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Algiers) {
    EXPECT_EQ("Africa/Algiers", TimeZoneInfo::GetSystemTimeZones()[3].Id());
    EXPECT_EQ("(UTC+01:00:00) Africa/Algiers", TimeZoneInfo::GetSystemTimeZones()[3].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[3].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[3].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[3].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[3].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Asmara) {
    EXPECT_EQ("Africa/Asmara", TimeZoneInfo::GetSystemTimeZones()[4].Id());
    EXPECT_EQ("(UTC+03:00:00) Africa/Asmara", TimeZoneInfo::GetSystemTimeZones()[4].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[4].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[4].BaseUtcOffset().ToString());
    EXPECT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[4].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[4].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Asmera) {
    EXPECT_EQ("Africa/Asmera", TimeZoneInfo::GetSystemTimeZones()[5].Id());
    EXPECT_EQ("(UTC+03:00:00) Africa/Asmera", TimeZoneInfo::GetSystemTimeZones()[5].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[5].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[5].BaseUtcOffset().ToString());
    EXPECT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[5].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[5].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Bamako) {
    EXPECT_EQ("Africa/Bamako", TimeZoneInfo::GetSystemTimeZones()[6].Id());
    EXPECT_EQ("(UTC) Africa/Bamako", TimeZoneInfo::GetSystemTimeZones()[6].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[6].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[6].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[6].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[6].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Bangui) {
    EXPECT_EQ("Africa/Bangui", TimeZoneInfo::GetSystemTimeZones()[7].Id());
    EXPECT_EQ("(UTC+01:00:00) Africa/Bangui", TimeZoneInfo::GetSystemTimeZones()[7].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[7].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[7].BaseUtcOffset().ToString());
    EXPECT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[7].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[7].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Banjul) {
    EXPECT_EQ("Africa/Banjul", TimeZoneInfo::GetSystemTimeZones()[8].Id());
    EXPECT_EQ("(UTC) Africa/Banjul", TimeZoneInfo::GetSystemTimeZones()[8].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[8].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[8].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[8].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[8].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Bissau) {
    EXPECT_EQ("Africa/Bissau", TimeZoneInfo::GetSystemTimeZones()[9].Id());
    EXPECT_EQ("(UTC) Africa/Bissau", TimeZoneInfo::GetSystemTimeZones()[9].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[9].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[9].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[9].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[9].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Blantyre) {
    EXPECT_EQ("Africa/Blantyre", TimeZoneInfo::GetSystemTimeZones()[10].Id());
    EXPECT_EQ("(UTC+02:00:00) Africa/Blantyre", TimeZoneInfo::GetSystemTimeZones()[10].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[10].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[10].BaseUtcOffset().ToString());
    EXPECT_EQ("CAT", TimeZoneInfo::GetSystemTimeZones()[10].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[10].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Brazzaville) {
    EXPECT_EQ("Africa/Brazzaville", TimeZoneInfo::GetSystemTimeZones()[11].Id());
    EXPECT_EQ("(UTC+01:00:00) Africa/Brazzaville", TimeZoneInfo::GetSystemTimeZones()[11].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[11].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[11].BaseUtcOffset().ToString());
    EXPECT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[11].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[11].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Bujumbura) {
    EXPECT_EQ("Africa/Bujumbura", TimeZoneInfo::GetSystemTimeZones()[12].Id());
    EXPECT_EQ("(UTC+02:00:00) Africa/Bujumbura", TimeZoneInfo::GetSystemTimeZones()[12].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[12].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[12].BaseUtcOffset().ToString());
    EXPECT_EQ("CAT", TimeZoneInfo::GetSystemTimeZones()[12].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[12].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Cairo) {
    EXPECT_EQ("Africa/Cairo", TimeZoneInfo::GetSystemTimeZones()[13].Id());
    EXPECT_EQ("(UTC+02:00:00) Africa/Cairo", TimeZoneInfo::GetSystemTimeZones()[13].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[13].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[13].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[13].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[13].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Casablanca) {
    EXPECT_EQ("Africa/Casablanca", TimeZoneInfo::GetSystemTimeZones()[14].Id());
    EXPECT_EQ("(UTC) Africa/Casablanca", TimeZoneInfo::GetSystemTimeZones()[14].DisplayName());
    EXPECT_EQ("WEST", TimeZoneInfo::GetSystemTimeZones()[14].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[14].BaseUtcOffset().ToString());
    EXPECT_EQ("WET", TimeZoneInfo::GetSystemTimeZones()[14].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[14].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Ceuta) {
    EXPECT_EQ("Africa/Ceuta", TimeZoneInfo::GetSystemTimeZones()[15].Id());
    EXPECT_EQ("(UTC+01:00:00) Africa/Ceuta", TimeZoneInfo::GetSystemTimeZones()[15].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[15].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[15].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[15].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[15].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Conakry) {
    EXPECT_EQ("Africa/Conakry", TimeZoneInfo::GetSystemTimeZones()[16].Id());
    EXPECT_EQ("(UTC) Africa/Conakry", TimeZoneInfo::GetSystemTimeZones()[16].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[16].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[16].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[16].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[16].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Dakar) {
    EXPECT_EQ("Africa/Dakar", TimeZoneInfo::GetSystemTimeZones()[17].Id());
    EXPECT_EQ("(UTC) Africa/Dakar", TimeZoneInfo::GetSystemTimeZones()[17].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[17].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[17].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[17].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[17].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Dar_es_Salaam) {
    EXPECT_EQ("Africa/Dar_es_Salaam", TimeZoneInfo::GetSystemTimeZones()[18].Id());
    EXPECT_EQ("(UTC+03:00:00) Africa/Dar_es_Salaam", TimeZoneInfo::GetSystemTimeZones()[18].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[18].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[18].BaseUtcOffset().ToString());
    EXPECT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[18].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[18].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Djibouti) {
    EXPECT_EQ("Africa/Djibouti", TimeZoneInfo::GetSystemTimeZones()[19].Id());
    EXPECT_EQ("(UTC+03:00:00) Africa/Djibouti", TimeZoneInfo::GetSystemTimeZones()[19].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[19].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[19].BaseUtcOffset().ToString());
    EXPECT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[19].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[19].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Douala) {
    EXPECT_EQ("Africa/Douala", TimeZoneInfo::GetSystemTimeZones()[20].Id());
    EXPECT_EQ("(UTC+01:00:00) Africa/Douala", TimeZoneInfo::GetSystemTimeZones()[20].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[20].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[20].BaseUtcOffset().ToString());
    EXPECT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[20].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[20].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_El_Aaiun) {
    EXPECT_EQ("Africa/El_Aaiun", TimeZoneInfo::GetSystemTimeZones()[21].Id());
    EXPECT_EQ("(UTC) Africa/El_Aaiun", TimeZoneInfo::GetSystemTimeZones()[21].DisplayName());
    EXPECT_EQ("WEST", TimeZoneInfo::GetSystemTimeZones()[21].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[21].BaseUtcOffset().ToString());
    EXPECT_EQ("WET", TimeZoneInfo::GetSystemTimeZones()[21].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[21].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Freetown) {
    EXPECT_EQ("Africa/Freetown", TimeZoneInfo::GetSystemTimeZones()[22].Id());
    EXPECT_EQ("(UTC) Africa/Freetown", TimeZoneInfo::GetSystemTimeZones()[22].DisplayName());
    EXPECT_EQ("SLST", TimeZoneInfo::GetSystemTimeZones()[22].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[22].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[22].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[22].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Gaborone) {
    EXPECT_EQ("Africa/Gaborone", TimeZoneInfo::GetSystemTimeZones()[23].Id());
    EXPECT_EQ("(UTC+02:00:00) Africa/Gaborone", TimeZoneInfo::GetSystemTimeZones()[23].DisplayName());
    EXPECT_EQ("CAST", TimeZoneInfo::GetSystemTimeZones()[23].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[23].BaseUtcOffset().ToString());
    EXPECT_EQ("CAT", TimeZoneInfo::GetSystemTimeZones()[23].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[23].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Harare) {
    EXPECT_EQ("Africa/Harare", TimeZoneInfo::GetSystemTimeZones()[24].Id());
    EXPECT_EQ("(UTC+02:00:00) Africa/Harare", TimeZoneInfo::GetSystemTimeZones()[24].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[24].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[24].BaseUtcOffset().ToString());
    EXPECT_EQ("CAT", TimeZoneInfo::GetSystemTimeZones()[24].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[24].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Johannesburg) {
    EXPECT_EQ("Africa/Johannesburg", TimeZoneInfo::GetSystemTimeZones()[25].Id());
    EXPECT_EQ("(UTC+02:00:00) Africa/Johannesburg", TimeZoneInfo::GetSystemTimeZones()[25].DisplayName());
    EXPECT_EQ("SAST", TimeZoneInfo::GetSystemTimeZones()[25].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[25].BaseUtcOffset().ToString());
    EXPECT_EQ("SAST", TimeZoneInfo::GetSystemTimeZones()[25].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[25].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Juba) {
    EXPECT_EQ("Africa/Juba", TimeZoneInfo::GetSystemTimeZones()[26].Id());
    EXPECT_EQ("(UTC+03:00:00) Africa/Juba", TimeZoneInfo::GetSystemTimeZones()[26].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[26].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[26].BaseUtcOffset().ToString());
    EXPECT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[26].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[26].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Kampala) {
    EXPECT_EQ("Africa/Kampala", TimeZoneInfo::GetSystemTimeZones()[27].Id());
    EXPECT_EQ("(UTC+03:00:00) Africa/Kampala", TimeZoneInfo::GetSystemTimeZones()[27].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[27].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[27].BaseUtcOffset().ToString());
    EXPECT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[27].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[27].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Khartoum) {
    EXPECT_EQ("Africa/Khartoum", TimeZoneInfo::GetSystemTimeZones()[28].Id());
    EXPECT_EQ("(UTC+03:00:00) Africa/Khartoum", TimeZoneInfo::GetSystemTimeZones()[28].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[28].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[28].BaseUtcOffset().ToString());
    EXPECT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[28].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[28].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Kigali) {
    EXPECT_EQ("Africa/Kigali", TimeZoneInfo::GetSystemTimeZones()[29].Id());
    EXPECT_EQ("(UTC+02:00:00) Africa/Kigali", TimeZoneInfo::GetSystemTimeZones()[29].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[29].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[29].BaseUtcOffset().ToString());
    EXPECT_EQ("CAT", TimeZoneInfo::GetSystemTimeZones()[29].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[29].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Kinshasa) {
    EXPECT_EQ("Africa/Kinshasa", TimeZoneInfo::GetSystemTimeZones()[30].Id());
    EXPECT_EQ("(UTC+01:00:00) Africa/Kinshasa", TimeZoneInfo::GetSystemTimeZones()[30].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[30].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[30].BaseUtcOffset().ToString());
    EXPECT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[30].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[30].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Lagos) {
    EXPECT_EQ("Africa/Lagos", TimeZoneInfo::GetSystemTimeZones()[31].Id());
    EXPECT_EQ("(UTC+01:00:00) Africa/Lagos", TimeZoneInfo::GetSystemTimeZones()[31].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[31].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[31].BaseUtcOffset().ToString());
    EXPECT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[31].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[31].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Libreville) {
    EXPECT_EQ("Africa/Libreville", TimeZoneInfo::GetSystemTimeZones()[32].Id());
    EXPECT_EQ("(UTC+01:00:00) Africa/Libreville", TimeZoneInfo::GetSystemTimeZones()[32].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[32].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[32].BaseUtcOffset().ToString());
    EXPECT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[32].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[32].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Lome) {
    EXPECT_EQ("Africa/Lome", TimeZoneInfo::GetSystemTimeZones()[33].Id());
    EXPECT_EQ("(UTC) Africa/Lome", TimeZoneInfo::GetSystemTimeZones()[33].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[33].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[33].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[33].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[33].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Luanda) {
    EXPECT_EQ("Africa/Luanda", TimeZoneInfo::GetSystemTimeZones()[34].Id());
    EXPECT_EQ("(UTC+01:00:00) Africa/Luanda", TimeZoneInfo::GetSystemTimeZones()[34].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[34].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[34].BaseUtcOffset().ToString());
    EXPECT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[34].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[34].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Lubumbashi) {
    EXPECT_EQ("Africa/Lubumbashi", TimeZoneInfo::GetSystemTimeZones()[35].Id());
    EXPECT_EQ("(UTC+02:00:00) Africa/Lubumbashi", TimeZoneInfo::GetSystemTimeZones()[35].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[35].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[35].BaseUtcOffset().ToString());
    EXPECT_EQ("CAT", TimeZoneInfo::GetSystemTimeZones()[35].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[35].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Lusaka) {
    EXPECT_EQ("Africa/Lusaka", TimeZoneInfo::GetSystemTimeZones()[36].Id());
    EXPECT_EQ("(UTC+02:00:00) Africa/Lusaka", TimeZoneInfo::GetSystemTimeZones()[36].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[36].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[36].BaseUtcOffset().ToString());
    EXPECT_EQ("CAT", TimeZoneInfo::GetSystemTimeZones()[36].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[36].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Malabo) {
    EXPECT_EQ("Africa/Malabo", TimeZoneInfo::GetSystemTimeZones()[37].Id());
    EXPECT_EQ("(UTC+01:00:00) Africa/Malabo", TimeZoneInfo::GetSystemTimeZones()[37].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[37].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[37].BaseUtcOffset().ToString());
    EXPECT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[37].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[37].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Maputo) {
    EXPECT_EQ("Africa/Maputo", TimeZoneInfo::GetSystemTimeZones()[38].Id());
    EXPECT_EQ("(UTC+02:00:00) Africa/Maputo", TimeZoneInfo::GetSystemTimeZones()[38].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[38].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[38].BaseUtcOffset().ToString());
    EXPECT_EQ("CAT", TimeZoneInfo::GetSystemTimeZones()[38].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[38].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Maseru) {
    EXPECT_EQ("Africa/Maseru", TimeZoneInfo::GetSystemTimeZones()[39].Id());
    EXPECT_EQ("(UTC+02:00:00) Africa/Maseru", TimeZoneInfo::GetSystemTimeZones()[39].DisplayName());
    EXPECT_EQ("SAST", TimeZoneInfo::GetSystemTimeZones()[39].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[39].BaseUtcOffset().ToString());
    EXPECT_EQ("SAST", TimeZoneInfo::GetSystemTimeZones()[39].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[39].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Mbabane) {
    EXPECT_EQ("Africa/Mbabane", TimeZoneInfo::GetSystemTimeZones()[40].Id());
    EXPECT_EQ("(UTC+02:00:00) Africa/Mbabane", TimeZoneInfo::GetSystemTimeZones()[40].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[40].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[40].BaseUtcOffset().ToString());
    EXPECT_EQ("SAST", TimeZoneInfo::GetSystemTimeZones()[40].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[40].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Mogadishu) {
    EXPECT_EQ("Africa/Mogadishu", TimeZoneInfo::GetSystemTimeZones()[41].Id());
    EXPECT_EQ("(UTC+03:00:00) Africa/Mogadishu", TimeZoneInfo::GetSystemTimeZones()[41].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[41].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[41].BaseUtcOffset().ToString());
    EXPECT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[41].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[41].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Monrovia) {
    EXPECT_EQ("Africa/Monrovia", TimeZoneInfo::GetSystemTimeZones()[42].Id());
    EXPECT_EQ("(UTC) Africa/Monrovia", TimeZoneInfo::GetSystemTimeZones()[42].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[42].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[42].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[42].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[42].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Nairobi) {
    EXPECT_EQ("Africa/Nairobi", TimeZoneInfo::GetSystemTimeZones()[43].Id());
    EXPECT_EQ("(UTC+03:00:00) Africa/Nairobi", TimeZoneInfo::GetSystemTimeZones()[43].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[43].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[43].BaseUtcOffset().ToString());
    EXPECT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[43].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[43].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Ndjamena) {
    EXPECT_EQ("Africa/Ndjamena", TimeZoneInfo::GetSystemTimeZones()[44].Id());
    EXPECT_EQ("(UTC+01:00:00) Africa/Ndjamena", TimeZoneInfo::GetSystemTimeZones()[44].DisplayName());
    EXPECT_EQ("WAST", TimeZoneInfo::GetSystemTimeZones()[44].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[44].BaseUtcOffset().ToString());
    EXPECT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[44].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[44].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Niamey) {
    EXPECT_EQ("Africa/Niamey", TimeZoneInfo::GetSystemTimeZones()[45].Id());
    EXPECT_EQ("(UTC+01:00:00) Africa/Niamey", TimeZoneInfo::GetSystemTimeZones()[45].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[45].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[45].BaseUtcOffset().ToString());
    EXPECT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[45].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[45].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Nouakchott) {
    EXPECT_EQ("Africa/Nouakchott", TimeZoneInfo::GetSystemTimeZones()[46].Id());
    EXPECT_EQ("(UTC) Africa/Nouakchott", TimeZoneInfo::GetSystemTimeZones()[46].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[46].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[46].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[46].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[46].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Ouagadougou) {
    EXPECT_EQ("Africa/Ouagadougou", TimeZoneInfo::GetSystemTimeZones()[47].Id());
    EXPECT_EQ("(UTC) Africa/Ouagadougou", TimeZoneInfo::GetSystemTimeZones()[47].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[47].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[47].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[47].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[47].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Porto_Novo) {
    EXPECT_EQ("Africa/Porto-Novo", TimeZoneInfo::GetSystemTimeZones()[48].Id());
    EXPECT_EQ("(UTC+01:00:00) Africa/Porto-Novo", TimeZoneInfo::GetSystemTimeZones()[48].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[48].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[48].BaseUtcOffset().ToString());
    EXPECT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[48].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[48].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Sao_Tome) {
    EXPECT_EQ("Africa/Sao_Tome", TimeZoneInfo::GetSystemTimeZones()[49].Id());
    EXPECT_EQ("(UTC) Africa/Sao_Tome", TimeZoneInfo::GetSystemTimeZones()[49].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[49].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[49].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[49].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[49].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Timbuktu) {
    EXPECT_EQ("Africa/Timbuktu", TimeZoneInfo::GetSystemTimeZones()[50].Id());
    EXPECT_EQ("(UTC) Africa/Timbuktu", TimeZoneInfo::GetSystemTimeZones()[50].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[50].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[50].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[50].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[50].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Tripoli) {
    EXPECT_EQ("Africa/Tripoli", TimeZoneInfo::GetSystemTimeZones()[51].Id());
    EXPECT_EQ("(UTC+02:00:00) Africa/Tripoli", TimeZoneInfo::GetSystemTimeZones()[51].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[51].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[51].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[51].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[51].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Tunis) {
    EXPECT_EQ("Africa/Tunis", TimeZoneInfo::GetSystemTimeZones()[52].Id());
    EXPECT_EQ("(UTC+01:00:00) Africa/Tunis", TimeZoneInfo::GetSystemTimeZones()[52].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[52].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[52].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[52].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[52].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAfrica_Windhoek) {
    EXPECT_EQ("Africa/Windhoek", TimeZoneInfo::GetSystemTimeZones()[53].Id());
    EXPECT_EQ("(UTC+01:00:00) Africa/Windhoek", TimeZoneInfo::GetSystemTimeZones()[53].DisplayName());
    EXPECT_EQ("WAST", TimeZoneInfo::GetSystemTimeZones()[53].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[53].BaseUtcOffset().ToString());
    EXPECT_EQ("WAT", TimeZoneInfo::GetSystemTimeZones()[53].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[53].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Adak) {
    EXPECT_EQ("America/Adak", TimeZoneInfo::GetSystemTimeZones()[54].Id());
    EXPECT_EQ("(UTC-10:00:00) America/Adak", TimeZoneInfo::GetSystemTimeZones()[54].DisplayName());
    EXPECT_EQ("HADT", TimeZoneInfo::GetSystemTimeZones()[54].DaylightName());
    EXPECT_EQ("-10:00:00", TimeZoneInfo::GetSystemTimeZones()[54].BaseUtcOffset().ToString());
    EXPECT_EQ("HAST", TimeZoneInfo::GetSystemTimeZones()[54].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[54].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Anchorage) {
    EXPECT_EQ("America/Anchorage", TimeZoneInfo::GetSystemTimeZones()[55].Id());
    EXPECT_EQ("(UTC-09:00:00) America/Anchorage", TimeZoneInfo::GetSystemTimeZones()[55].DisplayName());
    EXPECT_EQ("AKDT", TimeZoneInfo::GetSystemTimeZones()[55].DaylightName());
    EXPECT_EQ("-09:00:00", TimeZoneInfo::GetSystemTimeZones()[55].BaseUtcOffset().ToString());
    EXPECT_EQ("AKST", TimeZoneInfo::GetSystemTimeZones()[55].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[55].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Anguilla) {
    EXPECT_EQ("America/Anguilla", TimeZoneInfo::GetSystemTimeZones()[56].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Anguilla", TimeZoneInfo::GetSystemTimeZones()[56].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[56].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[56].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[56].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[56].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Antigua) {
    EXPECT_EQ("America/Antigua", TimeZoneInfo::GetSystemTimeZones()[57].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Antigua", TimeZoneInfo::GetSystemTimeZones()[57].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[57].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[57].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[57].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[57].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Araguaina) {
    EXPECT_EQ("America/Araguaina", TimeZoneInfo::GetSystemTimeZones()[58].Id());
    EXPECT_EQ("(UTC-03:00:00) America/Araguaina", TimeZoneInfo::GetSystemTimeZones()[58].DisplayName());
    EXPECT_EQ("BRST", TimeZoneInfo::GetSystemTimeZones()[58].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[58].BaseUtcOffset().ToString());
    EXPECT_EQ("BRT", TimeZoneInfo::GetSystemTimeZones()[58].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[58].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Aruba) {
    EXPECT_EQ("America/Aruba", TimeZoneInfo::GetSystemTimeZones()[59].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Aruba", TimeZoneInfo::GetSystemTimeZones()[59].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[59].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[59].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[59].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[59].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Asuncion) {
    EXPECT_EQ("America/Asuncion", TimeZoneInfo::GetSystemTimeZones()[60].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Asuncion", TimeZoneInfo::GetSystemTimeZones()[60].DisplayName());
    EXPECT_EQ("PYST", TimeZoneInfo::GetSystemTimeZones()[60].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[60].BaseUtcOffset().ToString());
    EXPECT_EQ("PYT", TimeZoneInfo::GetSystemTimeZones()[60].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[60].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Atikokan) {
    EXPECT_EQ("America/Atikokan", TimeZoneInfo::GetSystemTimeZones()[61].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Atikokan", TimeZoneInfo::GetSystemTimeZones()[61].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[61].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[61].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[61].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[61].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Atka) {
    EXPECT_EQ("America/Atka", TimeZoneInfo::GetSystemTimeZones()[62].Id());
    EXPECT_EQ("(UTC-10:00:00) America/Atka", TimeZoneInfo::GetSystemTimeZones()[62].DisplayName());
    EXPECT_EQ("HADT", TimeZoneInfo::GetSystemTimeZones()[62].DaylightName());
    EXPECT_EQ("-10:00:00", TimeZoneInfo::GetSystemTimeZones()[62].BaseUtcOffset().ToString());
    EXPECT_EQ("HAST", TimeZoneInfo::GetSystemTimeZones()[62].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[62].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Bahia) {
    EXPECT_EQ("America/Bahia", TimeZoneInfo::GetSystemTimeZones()[63].Id());
    EXPECT_EQ("(UTC-03:00:00) America/Bahia", TimeZoneInfo::GetSystemTimeZones()[63].DisplayName());
    EXPECT_EQ("BRST", TimeZoneInfo::GetSystemTimeZones()[63].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[63].BaseUtcOffset().ToString());
    EXPECT_EQ("BRT", TimeZoneInfo::GetSystemTimeZones()[63].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[63].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Bahia_Banderas) {
    EXPECT_EQ("America/Bahia_Banderas", TimeZoneInfo::GetSystemTimeZones()[64].Id());
    EXPECT_EQ("(UTC-06:00:00) America/Bahia_Banderas", TimeZoneInfo::GetSystemTimeZones()[64].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[64].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[64].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[64].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[64].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Barbados) {
    EXPECT_EQ("America/Barbados", TimeZoneInfo::GetSystemTimeZones()[65].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Barbados", TimeZoneInfo::GetSystemTimeZones()[65].DisplayName());
    EXPECT_EQ("ADT", TimeZoneInfo::GetSystemTimeZones()[65].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[65].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[65].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[65].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Belem) {
    EXPECT_EQ("America/Belem", TimeZoneInfo::GetSystemTimeZones()[66].Id());
    EXPECT_EQ("(UTC-03:00:00) America/Belem", TimeZoneInfo::GetSystemTimeZones()[66].DisplayName());
    EXPECT_EQ("BRST", TimeZoneInfo::GetSystemTimeZones()[66].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[66].BaseUtcOffset().ToString());
    EXPECT_EQ("BRT", TimeZoneInfo::GetSystemTimeZones()[66].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[66].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Belize) {
    EXPECT_EQ("America/Belize", TimeZoneInfo::GetSystemTimeZones()[67].Id());
    EXPECT_EQ("(UTC-06:00:00) America/Belize", TimeZoneInfo::GetSystemTimeZones()[67].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[67].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[67].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[67].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[67].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Blanc_Sablon) {
    EXPECT_EQ("America/Blanc-Sablon", TimeZoneInfo::GetSystemTimeZones()[68].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Blanc-Sablon", TimeZoneInfo::GetSystemTimeZones()[68].DisplayName());
    EXPECT_EQ("APT", TimeZoneInfo::GetSystemTimeZones()[68].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[68].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[68].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[68].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Boa_Vista) {
    EXPECT_EQ("America/Boa_Vista", TimeZoneInfo::GetSystemTimeZones()[69].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Boa_Vista", TimeZoneInfo::GetSystemTimeZones()[69].DisplayName());
    EXPECT_EQ("AMST", TimeZoneInfo::GetSystemTimeZones()[69].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[69].BaseUtcOffset().ToString());
    EXPECT_EQ("AMT", TimeZoneInfo::GetSystemTimeZones()[69].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[69].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Bogota) {
    EXPECT_EQ("America/Bogota", TimeZoneInfo::GetSystemTimeZones()[70].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Bogota", TimeZoneInfo::GetSystemTimeZones()[70].DisplayName());
    EXPECT_EQ("COST", TimeZoneInfo::GetSystemTimeZones()[70].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[70].BaseUtcOffset().ToString());
    EXPECT_EQ("COT", TimeZoneInfo::GetSystemTimeZones()[70].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[70].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Boise) {
    EXPECT_EQ("America/Boise", TimeZoneInfo::GetSystemTimeZones()[71].Id());
    EXPECT_EQ("(UTC-07:00:00) America/Boise", TimeZoneInfo::GetSystemTimeZones()[71].DisplayName());
    EXPECT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[71].DaylightName());
    EXPECT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[71].BaseUtcOffset().ToString());
    EXPECT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[71].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[71].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Buenos_Aires) {
    EXPECT_EQ("America/Buenos_Aires", TimeZoneInfo::GetSystemTimeZones()[72].Id());
    EXPECT_EQ("(UTC-03:00:00) America/Buenos_Aires", TimeZoneInfo::GetSystemTimeZones()[72].DisplayName());
    EXPECT_EQ("ARST", TimeZoneInfo::GetSystemTimeZones()[72].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[72].BaseUtcOffset().ToString());
    EXPECT_EQ("ART", TimeZoneInfo::GetSystemTimeZones()[72].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[72].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Cambridge_Bay) {
    EXPECT_EQ("America/Cambridge_Bay", TimeZoneInfo::GetSystemTimeZones()[73].Id());
    EXPECT_EQ("(UTC-07:00:00) America/Cambridge_Bay", TimeZoneInfo::GetSystemTimeZones()[73].DisplayName());
    EXPECT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[73].DaylightName());
    EXPECT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[73].BaseUtcOffset().ToString());
    EXPECT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[73].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[73].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Campo_Grande) {
    EXPECT_EQ("America/Campo_Grande", TimeZoneInfo::GetSystemTimeZones()[74].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Campo_Grande", TimeZoneInfo::GetSystemTimeZones()[74].DisplayName());
    EXPECT_EQ("AMST", TimeZoneInfo::GetSystemTimeZones()[74].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[74].BaseUtcOffset().ToString());
    EXPECT_EQ("AMT", TimeZoneInfo::GetSystemTimeZones()[74].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[74].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Cancun) {
    EXPECT_EQ("America/Cancun", TimeZoneInfo::GetSystemTimeZones()[75].Id());
    EXPECT_EQ("(UTC-06:00:00) America/Cancun", TimeZoneInfo::GetSystemTimeZones()[75].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[75].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[75].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[75].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[75].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Caracas) {
    EXPECT_EQ("America/Caracas", TimeZoneInfo::GetSystemTimeZones()[76].Id());
    EXPECT_EQ("(UTC-04:30:00) America/Caracas", TimeZoneInfo::GetSystemTimeZones()[76].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[76].DaylightName());
    EXPECT_EQ("-04:30:00", TimeZoneInfo::GetSystemTimeZones()[76].BaseUtcOffset().ToString());
    EXPECT_EQ("VET", TimeZoneInfo::GetSystemTimeZones()[76].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[76].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Catamarca) {
    EXPECT_EQ("America/Catamarca", TimeZoneInfo::GetSystemTimeZones()[77].Id());
    EXPECT_EQ("(UTC-03:00:00) America/Catamarca", TimeZoneInfo::GetSystemTimeZones()[77].DisplayName());
    EXPECT_EQ("ARST", TimeZoneInfo::GetSystemTimeZones()[77].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[77].BaseUtcOffset().ToString());
    EXPECT_EQ("ART", TimeZoneInfo::GetSystemTimeZones()[77].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[77].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Cayenne) {
    EXPECT_EQ("America/Cayenne", TimeZoneInfo::GetSystemTimeZones()[78].Id());
    EXPECT_EQ("(UTC-03:00:00) America/Cayenne", TimeZoneInfo::GetSystemTimeZones()[78].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[78].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[78].BaseUtcOffset().ToString());
    EXPECT_EQ("GFT", TimeZoneInfo::GetSystemTimeZones()[78].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[78].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Cayman) {
    EXPECT_EQ("America/Cayman", TimeZoneInfo::GetSystemTimeZones()[79].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Cayman", TimeZoneInfo::GetSystemTimeZones()[79].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[79].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[79].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[79].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[79].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Chicago) {
    EXPECT_EQ("America/Chicago", TimeZoneInfo::GetSystemTimeZones()[80].Id());
    EXPECT_EQ("(UTC-06:00:00) America/Chicago", TimeZoneInfo::GetSystemTimeZones()[80].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[80].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[80].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[80].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[80].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Chihuahua) {
    EXPECT_EQ("America/Chihuahua", TimeZoneInfo::GetSystemTimeZones()[81].Id());
    EXPECT_EQ("(UTC-07:00:00) America/Chihuahua", TimeZoneInfo::GetSystemTimeZones()[81].DisplayName());
    EXPECT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[81].DaylightName());
    EXPECT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[81].BaseUtcOffset().ToString());
    EXPECT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[81].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[81].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Coral_Harbour) {
    EXPECT_EQ("America/Coral_Harbour", TimeZoneInfo::GetSystemTimeZones()[82].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Coral_Harbour", TimeZoneInfo::GetSystemTimeZones()[82].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[82].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[82].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[82].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[82].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Cordoba) {
    EXPECT_EQ("America/Cordoba", TimeZoneInfo::GetSystemTimeZones()[83].Id());
    EXPECT_EQ("(UTC-03:00:00) America/Cordoba", TimeZoneInfo::GetSystemTimeZones()[83].DisplayName());
    EXPECT_EQ("ARST", TimeZoneInfo::GetSystemTimeZones()[83].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[83].BaseUtcOffset().ToString());
    EXPECT_EQ("ART", TimeZoneInfo::GetSystemTimeZones()[83].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[83].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Costa_Rica) {
    EXPECT_EQ("America/Costa_Rica", TimeZoneInfo::GetSystemTimeZones()[84].Id());
    EXPECT_EQ("(UTC-06:00:00) America/Costa_Rica", TimeZoneInfo::GetSystemTimeZones()[84].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[84].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[84].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[84].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[84].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Creston) {
    EXPECT_EQ("America/Creston", TimeZoneInfo::GetSystemTimeZones()[85].Id());
    EXPECT_EQ("(UTC-07:00:00) America/Creston", TimeZoneInfo::GetSystemTimeZones()[85].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[85].DaylightName());
    EXPECT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[85].BaseUtcOffset().ToString());
    EXPECT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[85].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[85].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Cuiaba) {
    EXPECT_EQ("America/Cuiaba", TimeZoneInfo::GetSystemTimeZones()[86].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Cuiaba", TimeZoneInfo::GetSystemTimeZones()[86].DisplayName());
    EXPECT_EQ("AMST", TimeZoneInfo::GetSystemTimeZones()[86].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[86].BaseUtcOffset().ToString());
    EXPECT_EQ("AMT", TimeZoneInfo::GetSystemTimeZones()[86].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[86].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Curacao) {
    EXPECT_EQ("America/Curacao", TimeZoneInfo::GetSystemTimeZones()[87].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Curacao", TimeZoneInfo::GetSystemTimeZones()[87].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[87].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[87].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[87].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[87].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Danmarkshavn) {
    EXPECT_EQ("America/Danmarkshavn", TimeZoneInfo::GetSystemTimeZones()[88].Id());
    EXPECT_EQ("(UTC) America/Danmarkshavn", TimeZoneInfo::GetSystemTimeZones()[88].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[88].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[88].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[88].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[88].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Dawson) {
    EXPECT_EQ("America/Dawson", TimeZoneInfo::GetSystemTimeZones()[89].Id());
    EXPECT_EQ("(UTC-08:00:00) America/Dawson", TimeZoneInfo::GetSystemTimeZones()[89].DisplayName());
    EXPECT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[89].DaylightName());
    EXPECT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[89].BaseUtcOffset().ToString());
    EXPECT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[89].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[89].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Dawson_Creek) {
    EXPECT_EQ("America/Dawson_Creek", TimeZoneInfo::GetSystemTimeZones()[90].Id());
    EXPECT_EQ("(UTC-07:00:00) America/Dawson_Creek", TimeZoneInfo::GetSystemTimeZones()[90].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[90].DaylightName());
    EXPECT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[90].BaseUtcOffset().ToString());
    EXPECT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[90].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[90].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Denver) {
    EXPECT_EQ("America/Denver", TimeZoneInfo::GetSystemTimeZones()[91].Id());
    EXPECT_EQ("(UTC-07:00:00) America/Denver", TimeZoneInfo::GetSystemTimeZones()[91].DisplayName());
    EXPECT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[91].DaylightName());
    EXPECT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[91].BaseUtcOffset().ToString());
    EXPECT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[91].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[91].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Detroit) {
    EXPECT_EQ("America/Detroit", TimeZoneInfo::GetSystemTimeZones()[92].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Detroit", TimeZoneInfo::GetSystemTimeZones()[92].DisplayName());
    EXPECT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[92].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[92].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[92].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[92].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Dominica) {
    EXPECT_EQ("America/Dominica", TimeZoneInfo::GetSystemTimeZones()[93].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Dominica", TimeZoneInfo::GetSystemTimeZones()[93].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[93].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[93].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[93].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[93].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Edmonton) {
    EXPECT_EQ("America/Edmonton", TimeZoneInfo::GetSystemTimeZones()[94].Id());
    EXPECT_EQ("(UTC-07:00:00) America/Edmonton", TimeZoneInfo::GetSystemTimeZones()[94].DisplayName());
    EXPECT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[94].DaylightName());
    EXPECT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[94].BaseUtcOffset().ToString());
    EXPECT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[94].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[94].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Eirunepe) {
    EXPECT_EQ("America/Eirunepe", TimeZoneInfo::GetSystemTimeZones()[95].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Eirunepe", TimeZoneInfo::GetSystemTimeZones()[95].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[95].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[95].BaseUtcOffset().ToString());
    EXPECT_EQ("ACT", TimeZoneInfo::GetSystemTimeZones()[95].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[95].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_El_Salvador) {
    EXPECT_EQ("America/El_Salvador", TimeZoneInfo::GetSystemTimeZones()[96].Id());
    EXPECT_EQ("(UTC-06:00:00) America/El_Salvador", TimeZoneInfo::GetSystemTimeZones()[96].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[96].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[96].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[96].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[96].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Ensenada) {
    EXPECT_EQ("America/Ensenada", TimeZoneInfo::GetSystemTimeZones()[97].Id());
    EXPECT_EQ("(UTC-08:00:00) America/Ensenada", TimeZoneInfo::GetSystemTimeZones()[97].DisplayName());
    EXPECT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[97].DaylightName());
    EXPECT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[97].BaseUtcOffset().ToString());
    EXPECT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[97].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[97].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Fort_Wayne) {
    EXPECT_EQ("America/Fort_Wayne", TimeZoneInfo::GetSystemTimeZones()[98].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Fort_Wayne", TimeZoneInfo::GetSystemTimeZones()[98].DisplayName());
    EXPECT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[98].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[98].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[98].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[98].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Fortaleza) {
    EXPECT_EQ("America/Fortaleza", TimeZoneInfo::GetSystemTimeZones()[99].Id());
    EXPECT_EQ("(UTC-03:00:00) America/Fortaleza", TimeZoneInfo::GetSystemTimeZones()[99].DisplayName());
    EXPECT_EQ("BRST", TimeZoneInfo::GetSystemTimeZones()[99].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[99].BaseUtcOffset().ToString());
    EXPECT_EQ("BRT", TimeZoneInfo::GetSystemTimeZones()[99].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[99].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Glace_Bay) {
    EXPECT_EQ("America/Glace_Bay", TimeZoneInfo::GetSystemTimeZones()[100].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Glace_Bay", TimeZoneInfo::GetSystemTimeZones()[100].DisplayName());
    EXPECT_EQ("ADT", TimeZoneInfo::GetSystemTimeZones()[100].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[100].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[100].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[100].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Godthab) {
    EXPECT_EQ("America/Godthab", TimeZoneInfo::GetSystemTimeZones()[101].Id());
    EXPECT_EQ("(UTC-03:00:00) America/Godthab", TimeZoneInfo::GetSystemTimeZones()[101].DisplayName());
    EXPECT_EQ("WGST", TimeZoneInfo::GetSystemTimeZones()[101].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[101].BaseUtcOffset().ToString());
    EXPECT_EQ("WGT", TimeZoneInfo::GetSystemTimeZones()[101].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[101].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Goose_Bay) {
    EXPECT_EQ("America/Goose_Bay", TimeZoneInfo::GetSystemTimeZones()[102].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Goose_Bay", TimeZoneInfo::GetSystemTimeZones()[102].DisplayName());
    EXPECT_EQ("ADT", TimeZoneInfo::GetSystemTimeZones()[102].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[102].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[102].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[102].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Grand_Turk) {
    EXPECT_EQ("America/Grand_Turk", TimeZoneInfo::GetSystemTimeZones()[103].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Grand_Turk", TimeZoneInfo::GetSystemTimeZones()[103].DisplayName());
    EXPECT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[103].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[103].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[103].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[103].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Grenada) {
    EXPECT_EQ("America/Grenada", TimeZoneInfo::GetSystemTimeZones()[104].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Grenada", TimeZoneInfo::GetSystemTimeZones()[104].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[104].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[104].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[104].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[104].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Guadeloupe) {
    EXPECT_EQ("America/Guadeloupe", TimeZoneInfo::GetSystemTimeZones()[105].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Guadeloupe", TimeZoneInfo::GetSystemTimeZones()[105].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[105].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[105].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[105].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[105].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Guatemala) {
    EXPECT_EQ("America/Guatemala", TimeZoneInfo::GetSystemTimeZones()[106].Id());
    EXPECT_EQ("(UTC-06:00:00) America/Guatemala", TimeZoneInfo::GetSystemTimeZones()[106].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[106].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[106].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[106].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[106].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Guayaquil) {
    EXPECT_EQ("America/Guayaquil", TimeZoneInfo::GetSystemTimeZones()[107].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Guayaquil", TimeZoneInfo::GetSystemTimeZones()[107].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[107].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[107].BaseUtcOffset().ToString());
    EXPECT_EQ("ECT", TimeZoneInfo::GetSystemTimeZones()[107].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[107].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Guyana) {
    EXPECT_EQ("America/Guyana", TimeZoneInfo::GetSystemTimeZones()[108].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Guyana", TimeZoneInfo::GetSystemTimeZones()[108].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[108].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[108].BaseUtcOffset().ToString());
    EXPECT_EQ("GYT", TimeZoneInfo::GetSystemTimeZones()[108].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[108].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Halifax) {
    EXPECT_EQ("America/Halifax", TimeZoneInfo::GetSystemTimeZones()[109].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Halifax", TimeZoneInfo::GetSystemTimeZones()[109].DisplayName());
    EXPECT_EQ("ADT", TimeZoneInfo::GetSystemTimeZones()[109].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[109].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[109].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[109].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Havana) {
    EXPECT_EQ("America/Havana", TimeZoneInfo::GetSystemTimeZones()[110].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Havana", TimeZoneInfo::GetSystemTimeZones()[110].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[110].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[110].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[110].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[110].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Hermosillo) {
    EXPECT_EQ("America/Hermosillo", TimeZoneInfo::GetSystemTimeZones()[111].Id());
    EXPECT_EQ("(UTC-07:00:00) America/Hermosillo", TimeZoneInfo::GetSystemTimeZones()[111].DisplayName());
    EXPECT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[111].DaylightName());
    EXPECT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[111].BaseUtcOffset().ToString());
    EXPECT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[111].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[111].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Indianapolis) {
    EXPECT_EQ("America/Indianapolis", TimeZoneInfo::GetSystemTimeZones()[112].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Indianapolis", TimeZoneInfo::GetSystemTimeZones()[112].DisplayName());
    EXPECT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[112].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[112].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[112].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[112].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Inuvik) {
    EXPECT_EQ("America/Inuvik", TimeZoneInfo::GetSystemTimeZones()[113].Id());
    EXPECT_EQ("(UTC-07:00:00) America/Inuvik", TimeZoneInfo::GetSystemTimeZones()[113].DisplayName());
    EXPECT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[113].DaylightName());
    EXPECT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[113].BaseUtcOffset().ToString());
    EXPECT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[113].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[113].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Iqaluit) {
    EXPECT_EQ("America/Iqaluit", TimeZoneInfo::GetSystemTimeZones()[114].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Iqaluit", TimeZoneInfo::GetSystemTimeZones()[114].DisplayName());
    EXPECT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[114].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[114].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[114].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[114].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Jamaica) {
    EXPECT_EQ("America/Jamaica", TimeZoneInfo::GetSystemTimeZones()[115].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Jamaica", TimeZoneInfo::GetSystemTimeZones()[115].DisplayName());
    EXPECT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[115].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[115].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[115].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[115].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Jujuy) {
    EXPECT_EQ("America/Jujuy", TimeZoneInfo::GetSystemTimeZones()[116].Id());
    EXPECT_EQ("(UTC-03:00:00) America/Jujuy", TimeZoneInfo::GetSystemTimeZones()[116].DisplayName());
    EXPECT_EQ("ARST", TimeZoneInfo::GetSystemTimeZones()[116].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[116].BaseUtcOffset().ToString());
    EXPECT_EQ("ART", TimeZoneInfo::GetSystemTimeZones()[116].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[116].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Juneau) {
    EXPECT_EQ("America/Juneau", TimeZoneInfo::GetSystemTimeZones()[117].Id());
    EXPECT_EQ("(UTC-09:00:00) America/Juneau", TimeZoneInfo::GetSystemTimeZones()[117].DisplayName());
    EXPECT_EQ("AKDT", TimeZoneInfo::GetSystemTimeZones()[117].DaylightName());
    EXPECT_EQ("-09:00:00", TimeZoneInfo::GetSystemTimeZones()[117].BaseUtcOffset().ToString());
    EXPECT_EQ("AKST", TimeZoneInfo::GetSystemTimeZones()[117].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[117].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Knox_IN) {
    EXPECT_EQ("America/Knox_IN", TimeZoneInfo::GetSystemTimeZones()[118].Id());
    EXPECT_EQ("(UTC-06:00:00) America/Knox_IN", TimeZoneInfo::GetSystemTimeZones()[118].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[118].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[118].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[118].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[118].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Kralendijk) {
    EXPECT_EQ("America/Kralendijk", TimeZoneInfo::GetSystemTimeZones()[119].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Kralendijk", TimeZoneInfo::GetSystemTimeZones()[119].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[119].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[119].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[119].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[119].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_La_Paz) {
    EXPECT_EQ("America/La_Paz", TimeZoneInfo::GetSystemTimeZones()[120].Id());
    EXPECT_EQ("(UTC-04:00:00) America/La_Paz", TimeZoneInfo::GetSystemTimeZones()[120].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[120].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[120].BaseUtcOffset().ToString());
    EXPECT_EQ("BOT", TimeZoneInfo::GetSystemTimeZones()[120].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[120].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Lima) {
    EXPECT_EQ("America/Lima", TimeZoneInfo::GetSystemTimeZones()[121].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Lima", TimeZoneInfo::GetSystemTimeZones()[121].DisplayName());
    EXPECT_EQ("PEST", TimeZoneInfo::GetSystemTimeZones()[121].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[121].BaseUtcOffset().ToString());
    EXPECT_EQ("PET", TimeZoneInfo::GetSystemTimeZones()[121].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[121].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Los_Angeles) {
    EXPECT_EQ("America/Los_Angeles", TimeZoneInfo::GetSystemTimeZones()[122].Id());
    EXPECT_EQ("(UTC-08:00:00) America/Los_Angeles", TimeZoneInfo::GetSystemTimeZones()[122].DisplayName());
    EXPECT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[122].DaylightName());
    EXPECT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[122].BaseUtcOffset().ToString());
    EXPECT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[122].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[122].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Louisville) {
    EXPECT_EQ("America/Louisville", TimeZoneInfo::GetSystemTimeZones()[123].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Louisville", TimeZoneInfo::GetSystemTimeZones()[123].DisplayName());
    EXPECT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[123].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[123].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[123].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[123].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Lower_Princes) {
    EXPECT_EQ("America/Lower_Princes", TimeZoneInfo::GetSystemTimeZones()[124].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Lower_Princes", TimeZoneInfo::GetSystemTimeZones()[124].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[124].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[124].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[124].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[124].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Maceio) {
    EXPECT_EQ("America/Maceio", TimeZoneInfo::GetSystemTimeZones()[125].Id());
    EXPECT_EQ("(UTC-03:00:00) America/Maceio", TimeZoneInfo::GetSystemTimeZones()[125].DisplayName());
    EXPECT_EQ("BRST", TimeZoneInfo::GetSystemTimeZones()[125].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[125].BaseUtcOffset().ToString());
    EXPECT_EQ("BRT", TimeZoneInfo::GetSystemTimeZones()[125].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[125].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Managua) {
    EXPECT_EQ("America/Managua", TimeZoneInfo::GetSystemTimeZones()[126].Id());
    EXPECT_EQ("(UTC-06:00:00) America/Managua", TimeZoneInfo::GetSystemTimeZones()[126].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[126].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[126].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[126].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[126].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Manaus) {
    EXPECT_EQ("America/Manaus", TimeZoneInfo::GetSystemTimeZones()[127].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Manaus", TimeZoneInfo::GetSystemTimeZones()[127].DisplayName());
    EXPECT_EQ("AMST", TimeZoneInfo::GetSystemTimeZones()[127].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[127].BaseUtcOffset().ToString());
    EXPECT_EQ("AMT", TimeZoneInfo::GetSystemTimeZones()[127].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[127].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Marigot) {
    EXPECT_EQ("America/Marigot", TimeZoneInfo::GetSystemTimeZones()[128].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Marigot", TimeZoneInfo::GetSystemTimeZones()[128].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[128].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[128].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[128].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[128].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Martinique) {
    EXPECT_EQ("America/Martinique", TimeZoneInfo::GetSystemTimeZones()[129].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Martinique", TimeZoneInfo::GetSystemTimeZones()[129].DisplayName());
    EXPECT_EQ("ADT", TimeZoneInfo::GetSystemTimeZones()[129].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[129].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[129].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[129].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Matamoros) {
    EXPECT_EQ("America/Matamoros", TimeZoneInfo::GetSystemTimeZones()[130].Id());
    EXPECT_EQ("(UTC-06:00:00) America/Matamoros", TimeZoneInfo::GetSystemTimeZones()[130].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[130].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[130].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[130].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[130].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Mazatlan) {
    EXPECT_EQ("America/Mazatlan", TimeZoneInfo::GetSystemTimeZones()[131].Id());
    EXPECT_EQ("(UTC-07:00:00) America/Mazatlan", TimeZoneInfo::GetSystemTimeZones()[131].DisplayName());
    EXPECT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[131].DaylightName());
    EXPECT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[131].BaseUtcOffset().ToString());
    EXPECT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[131].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[131].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Mendoza) {
    EXPECT_EQ("America/Mendoza", TimeZoneInfo::GetSystemTimeZones()[132].Id());
    EXPECT_EQ("(UTC-03:00:00) America/Mendoza", TimeZoneInfo::GetSystemTimeZones()[132].DisplayName());
    EXPECT_EQ("ARST", TimeZoneInfo::GetSystemTimeZones()[132].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[132].BaseUtcOffset().ToString());
    EXPECT_EQ("ART", TimeZoneInfo::GetSystemTimeZones()[132].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[132].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Menominee) {
    EXPECT_EQ("America/Menominee", TimeZoneInfo::GetSystemTimeZones()[133].Id());
    EXPECT_EQ("(UTC-06:00:00) America/Menominee", TimeZoneInfo::GetSystemTimeZones()[133].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[133].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[133].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[133].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[133].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Merida) {
    EXPECT_EQ("America/Merida", TimeZoneInfo::GetSystemTimeZones()[134].Id());
    EXPECT_EQ("(UTC-06:00:00) America/Merida", TimeZoneInfo::GetSystemTimeZones()[134].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[134].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[134].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[134].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[134].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Metlakatla) {
    EXPECT_EQ("America/Metlakatla", TimeZoneInfo::GetSystemTimeZones()[135].Id());
    EXPECT_EQ("(UTC-08:00:00) America/Metlakatla", TimeZoneInfo::GetSystemTimeZones()[135].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[135].DaylightName());
    EXPECT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[135].BaseUtcOffset().ToString());
    EXPECT_EQ("MeST", TimeZoneInfo::GetSystemTimeZones()[135].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[135].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Mexico_City) {
    EXPECT_EQ("America/Mexico_City", TimeZoneInfo::GetSystemTimeZones()[136].Id());
    EXPECT_EQ("(UTC-06:00:00) America/Mexico_City", TimeZoneInfo::GetSystemTimeZones()[136].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[136].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[136].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[136].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[136].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Miquelon) {
    EXPECT_EQ("America/Miquelon", TimeZoneInfo::GetSystemTimeZones()[137].Id());
    EXPECT_EQ("(UTC-03:00:00) America/Miquelon", TimeZoneInfo::GetSystemTimeZones()[137].DisplayName());
    EXPECT_EQ("PMDT", TimeZoneInfo::GetSystemTimeZones()[137].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[137].BaseUtcOffset().ToString());
    EXPECT_EQ("PMST", TimeZoneInfo::GetSystemTimeZones()[137].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[137].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Moncton) {
    EXPECT_EQ("America/Moncton", TimeZoneInfo::GetSystemTimeZones()[138].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Moncton", TimeZoneInfo::GetSystemTimeZones()[138].DisplayName());
    EXPECT_EQ("ADT", TimeZoneInfo::GetSystemTimeZones()[138].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[138].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[138].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[138].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Monterrey) {
    EXPECT_EQ("America/Monterrey", TimeZoneInfo::GetSystemTimeZones()[139].Id());
    EXPECT_EQ("(UTC-06:00:00) America/Monterrey", TimeZoneInfo::GetSystemTimeZones()[139].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[139].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[139].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[139].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[139].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Montevideo) {
    EXPECT_EQ("America/Montevideo", TimeZoneInfo::GetSystemTimeZones()[140].Id());
    EXPECT_EQ("(UTC-03:00:00) America/Montevideo", TimeZoneInfo::GetSystemTimeZones()[140].DisplayName());
    EXPECT_EQ("UYST", TimeZoneInfo::GetSystemTimeZones()[140].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[140].BaseUtcOffset().ToString());
    EXPECT_EQ("UYT", TimeZoneInfo::GetSystemTimeZones()[140].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[140].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Montreal) {
    EXPECT_EQ("America/Montreal", TimeZoneInfo::GetSystemTimeZones()[141].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Montreal", TimeZoneInfo::GetSystemTimeZones()[141].DisplayName());
    EXPECT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[141].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[141].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[141].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[141].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Montserrat) {
    EXPECT_EQ("America/Montserrat", TimeZoneInfo::GetSystemTimeZones()[142].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Montserrat", TimeZoneInfo::GetSystemTimeZones()[142].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[142].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[142].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[142].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[142].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Nassau) {
    EXPECT_EQ("America/Nassau", TimeZoneInfo::GetSystemTimeZones()[143].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Nassau", TimeZoneInfo::GetSystemTimeZones()[143].DisplayName());
    EXPECT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[143].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[143].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[143].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[143].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_New_York) {
    EXPECT_EQ("America/New_York", TimeZoneInfo::GetSystemTimeZones()[144].Id());
    EXPECT_EQ("(UTC-05:00:00) America/New_York", TimeZoneInfo::GetSystemTimeZones()[144].DisplayName());
    EXPECT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[144].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[144].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[144].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[144].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Nipigon) {
    EXPECT_EQ("America/Nipigon", TimeZoneInfo::GetSystemTimeZones()[145].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Nipigon", TimeZoneInfo::GetSystemTimeZones()[145].DisplayName());
    EXPECT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[145].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[145].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[145].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[145].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Nome) {
    EXPECT_EQ("America/Nome", TimeZoneInfo::GetSystemTimeZones()[146].Id());
    EXPECT_EQ("(UTC-09:00:00) America/Nome", TimeZoneInfo::GetSystemTimeZones()[146].DisplayName());
    EXPECT_EQ("AKDT", TimeZoneInfo::GetSystemTimeZones()[146].DaylightName());
    EXPECT_EQ("-09:00:00", TimeZoneInfo::GetSystemTimeZones()[146].BaseUtcOffset().ToString());
    EXPECT_EQ("AKST", TimeZoneInfo::GetSystemTimeZones()[146].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[146].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Noronha) {
    EXPECT_EQ("America/Noronha", TimeZoneInfo::GetSystemTimeZones()[147].Id());
    EXPECT_EQ("(UTC-02:00:00) America/Noronha", TimeZoneInfo::GetSystemTimeZones()[147].DisplayName());
    EXPECT_EQ("FNST", TimeZoneInfo::GetSystemTimeZones()[147].DaylightName());
    EXPECT_EQ("-02:00:00", TimeZoneInfo::GetSystemTimeZones()[147].BaseUtcOffset().ToString());
    EXPECT_EQ("FNT", TimeZoneInfo::GetSystemTimeZones()[147].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[147].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Ojinaga) {
    EXPECT_EQ("America/Ojinaga", TimeZoneInfo::GetSystemTimeZones()[148].Id());
    EXPECT_EQ("(UTC-07:00:00) America/Ojinaga", TimeZoneInfo::GetSystemTimeZones()[148].DisplayName());
    EXPECT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[148].DaylightName());
    EXPECT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[148].BaseUtcOffset().ToString());
    EXPECT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[148].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[148].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Panama) {
    EXPECT_EQ("America/Panama", TimeZoneInfo::GetSystemTimeZones()[149].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Panama", TimeZoneInfo::GetSystemTimeZones()[149].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[149].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[149].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[149].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[149].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Pangnirtung) {
    EXPECT_EQ("America/Pangnirtung", TimeZoneInfo::GetSystemTimeZones()[150].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Pangnirtung", TimeZoneInfo::GetSystemTimeZones()[150].DisplayName());
    EXPECT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[150].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[150].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[150].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[150].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Paramaribo) {
    EXPECT_EQ("America/Paramaribo", TimeZoneInfo::GetSystemTimeZones()[151].Id());
    EXPECT_EQ("(UTC-03:00:00) America/Paramaribo", TimeZoneInfo::GetSystemTimeZones()[151].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[151].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[151].BaseUtcOffset().ToString());
    EXPECT_EQ("SRT", TimeZoneInfo::GetSystemTimeZones()[151].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[151].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Phoenix) {
    EXPECT_EQ("America/Phoenix", TimeZoneInfo::GetSystemTimeZones()[152].Id());
    EXPECT_EQ("(UTC-07:00:00) America/Phoenix", TimeZoneInfo::GetSystemTimeZones()[152].DisplayName());
    EXPECT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[152].DaylightName());
    EXPECT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[152].BaseUtcOffset().ToString());
    EXPECT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[152].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[152].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Port_au_Prince) {
    EXPECT_EQ("America/Port-au-Prince", TimeZoneInfo::GetSystemTimeZones()[153].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Port-au-Prince", TimeZoneInfo::GetSystemTimeZones()[153].DisplayName());
    EXPECT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[153].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[153].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[153].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[153].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Port_of_Spain) {
    EXPECT_EQ("America/Port_of_Spain", TimeZoneInfo::GetSystemTimeZones()[154].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Port_of_Spain", TimeZoneInfo::GetSystemTimeZones()[154].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[154].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[154].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[154].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[154].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Porto_Acre) {
    EXPECT_EQ("America/Porto_Acre", TimeZoneInfo::GetSystemTimeZones()[155].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Porto_Acre", TimeZoneInfo::GetSystemTimeZones()[155].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[155].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[155].BaseUtcOffset().ToString());
    EXPECT_EQ("ACT", TimeZoneInfo::GetSystemTimeZones()[155].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[155].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Porto_Velho) {
    EXPECT_EQ("America/Porto_Velho", TimeZoneInfo::GetSystemTimeZones()[156].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Porto_Velho", TimeZoneInfo::GetSystemTimeZones()[156].DisplayName());
    EXPECT_EQ("AMST", TimeZoneInfo::GetSystemTimeZones()[156].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[156].BaseUtcOffset().ToString());
    EXPECT_EQ("AMT", TimeZoneInfo::GetSystemTimeZones()[156].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[156].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Puerto_Rico) {
    EXPECT_EQ("America/Puerto_Rico", TimeZoneInfo::GetSystemTimeZones()[157].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Puerto_Rico", TimeZoneInfo::GetSystemTimeZones()[157].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[157].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[157].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[157].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[157].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Rainy_River) {
    EXPECT_EQ("America/Rainy_River", TimeZoneInfo::GetSystemTimeZones()[158].Id());
    EXPECT_EQ("(UTC-06:00:00) America/Rainy_River", TimeZoneInfo::GetSystemTimeZones()[158].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[158].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[158].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[158].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[158].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Rankin_Inlet) {
    EXPECT_EQ("America/Rankin_Inlet", TimeZoneInfo::GetSystemTimeZones()[159].Id());
    EXPECT_EQ("(UTC-06:00:00) America/Rankin_Inlet", TimeZoneInfo::GetSystemTimeZones()[159].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[159].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[159].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[159].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[159].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Recife) {
    EXPECT_EQ("America/Recife", TimeZoneInfo::GetSystemTimeZones()[160].Id());
    EXPECT_EQ("(UTC-03:00:00) America/Recife", TimeZoneInfo::GetSystemTimeZones()[160].DisplayName());
    EXPECT_EQ("BRST", TimeZoneInfo::GetSystemTimeZones()[160].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[160].BaseUtcOffset().ToString());
    EXPECT_EQ("BRT", TimeZoneInfo::GetSystemTimeZones()[160].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[160].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Regina) {
    EXPECT_EQ("America/Regina", TimeZoneInfo::GetSystemTimeZones()[161].Id());
    EXPECT_EQ("(UTC-06:00:00) America/Regina", TimeZoneInfo::GetSystemTimeZones()[161].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[161].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[161].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[161].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[161].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Resolute) {
    EXPECT_EQ("America/Resolute", TimeZoneInfo::GetSystemTimeZones()[162].Id());
    EXPECT_EQ("(UTC-06:00:00) America/Resolute", TimeZoneInfo::GetSystemTimeZones()[162].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[162].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[162].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[162].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[162].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Rio_Branco) {
    EXPECT_EQ("America/Rio_Branco", TimeZoneInfo::GetSystemTimeZones()[163].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Rio_Branco", TimeZoneInfo::GetSystemTimeZones()[163].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[163].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[163].BaseUtcOffset().ToString());
    EXPECT_EQ("ACT", TimeZoneInfo::GetSystemTimeZones()[163].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[163].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Rosario) {
    EXPECT_EQ("America/Rosario", TimeZoneInfo::GetSystemTimeZones()[164].Id());
    EXPECT_EQ("(UTC-03:00:00) America/Rosario", TimeZoneInfo::GetSystemTimeZones()[164].DisplayName());
    EXPECT_EQ("ARST", TimeZoneInfo::GetSystemTimeZones()[164].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[164].BaseUtcOffset().ToString());
    EXPECT_EQ("ART", TimeZoneInfo::GetSystemTimeZones()[164].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[164].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Santa_Isabel) {
    EXPECT_EQ("America/Santa_Isabel", TimeZoneInfo::GetSystemTimeZones()[165].Id());
    EXPECT_EQ("(UTC-08:00:00) America/Santa_Isabel", TimeZoneInfo::GetSystemTimeZones()[165].DisplayName());
    EXPECT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[165].DaylightName());
    EXPECT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[165].BaseUtcOffset().ToString());
    EXPECT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[165].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[165].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Santarem) {
    EXPECT_EQ("America/Santarem", TimeZoneInfo::GetSystemTimeZones()[166].Id());
    EXPECT_EQ("(UTC-03:00:00) America/Santarem", TimeZoneInfo::GetSystemTimeZones()[166].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[166].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[166].BaseUtcOffset().ToString());
    EXPECT_EQ("BRT", TimeZoneInfo::GetSystemTimeZones()[166].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[166].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Santiago) {
    EXPECT_EQ("America/Santiago", TimeZoneInfo::GetSystemTimeZones()[167].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Santiago", TimeZoneInfo::GetSystemTimeZones()[167].DisplayName());
    EXPECT_EQ("CLST", TimeZoneInfo::GetSystemTimeZones()[167].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[167].BaseUtcOffset().ToString());
    EXPECT_EQ("CLT", TimeZoneInfo::GetSystemTimeZones()[167].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[167].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Santo_Domingo) {
    EXPECT_EQ("America/Santo_Domingo", TimeZoneInfo::GetSystemTimeZones()[168].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Santo_Domingo", TimeZoneInfo::GetSystemTimeZones()[168].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[168].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[168].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[168].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[168].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Sao_Paulo) {
    EXPECT_EQ("America/Sao_Paulo", TimeZoneInfo::GetSystemTimeZones()[169].Id());
    EXPECT_EQ("(UTC-03:00:00) America/Sao_Paulo", TimeZoneInfo::GetSystemTimeZones()[169].DisplayName());
    EXPECT_EQ("BRST", TimeZoneInfo::GetSystemTimeZones()[169].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[169].BaseUtcOffset().ToString());
    EXPECT_EQ("BRT", TimeZoneInfo::GetSystemTimeZones()[169].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[169].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Scoresbysund) {
    EXPECT_EQ("America/Scoresbysund", TimeZoneInfo::GetSystemTimeZones()[170].Id());
    EXPECT_EQ("(UTC-01:00:00) America/Scoresbysund", TimeZoneInfo::GetSystemTimeZones()[170].DisplayName());
    EXPECT_EQ("EGST", TimeZoneInfo::GetSystemTimeZones()[170].DaylightName());
    EXPECT_EQ("-01:00:00", TimeZoneInfo::GetSystemTimeZones()[170].BaseUtcOffset().ToString());
    EXPECT_EQ("EGT", TimeZoneInfo::GetSystemTimeZones()[170].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[170].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Shiprock) {
    EXPECT_EQ("America/Shiprock", TimeZoneInfo::GetSystemTimeZones()[171].Id());
    EXPECT_EQ("(UTC-07:00:00) America/Shiprock", TimeZoneInfo::GetSystemTimeZones()[171].DisplayName());
    EXPECT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[171].DaylightName());
    EXPECT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[171].BaseUtcOffset().ToString());
    EXPECT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[171].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[171].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Sitka) {
    EXPECT_EQ("America/Sitka", TimeZoneInfo::GetSystemTimeZones()[172].Id());
    EXPECT_EQ("(UTC-09:00:00) America/Sitka", TimeZoneInfo::GetSystemTimeZones()[172].DisplayName());
    EXPECT_EQ("AKDT", TimeZoneInfo::GetSystemTimeZones()[172].DaylightName());
    EXPECT_EQ("-09:00:00", TimeZoneInfo::GetSystemTimeZones()[172].BaseUtcOffset().ToString());
    EXPECT_EQ("AKST", TimeZoneInfo::GetSystemTimeZones()[172].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[172].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_St_Barthelemy) {
    EXPECT_EQ("America/St_Barthelemy", TimeZoneInfo::GetSystemTimeZones()[173].Id());
    EXPECT_EQ("(UTC-04:00:00) America/St_Barthelemy", TimeZoneInfo::GetSystemTimeZones()[173].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[173].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[173].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[173].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[173].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_St_Johns) {
    EXPECT_EQ("America/St_Johns", TimeZoneInfo::GetSystemTimeZones()[174].Id());
    EXPECT_EQ("(UTC-03:30:00) America/St_Johns", TimeZoneInfo::GetSystemTimeZones()[174].DisplayName());
    EXPECT_EQ("NDT", TimeZoneInfo::GetSystemTimeZones()[174].DaylightName());
    EXPECT_EQ("-03:30:00", TimeZoneInfo::GetSystemTimeZones()[174].BaseUtcOffset().ToString());
    EXPECT_EQ("NST", TimeZoneInfo::GetSystemTimeZones()[174].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[174].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_St_Kitts) {
    EXPECT_EQ("America/St_Kitts", TimeZoneInfo::GetSystemTimeZones()[175].Id());
    EXPECT_EQ("(UTC-04:00:00) America/St_Kitts", TimeZoneInfo::GetSystemTimeZones()[175].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[175].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[175].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[175].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[175].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_St_Lucia) {
    EXPECT_EQ("America/St_Lucia", TimeZoneInfo::GetSystemTimeZones()[176].Id());
    EXPECT_EQ("(UTC-04:00:00) America/St_Lucia", TimeZoneInfo::GetSystemTimeZones()[176].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[176].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[176].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[176].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[176].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_St_Thomas) {
    EXPECT_EQ("America/St_Thomas", TimeZoneInfo::GetSystemTimeZones()[177].Id());
    EXPECT_EQ("(UTC-04:00:00) America/St_Thomas", TimeZoneInfo::GetSystemTimeZones()[177].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[177].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[177].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[177].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[177].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_St_Vincent) {
    EXPECT_EQ("America/St_Vincent", TimeZoneInfo::GetSystemTimeZones()[178].Id());
    EXPECT_EQ("(UTC-04:00:00) America/St_Vincent", TimeZoneInfo::GetSystemTimeZones()[178].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[178].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[178].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[178].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[178].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Swift_Current) {
    EXPECT_EQ("America/Swift_Current", TimeZoneInfo::GetSystemTimeZones()[179].Id());
    EXPECT_EQ("(UTC-06:00:00) America/Swift_Current", TimeZoneInfo::GetSystemTimeZones()[179].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[179].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[179].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[179].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[179].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Tegucigalpa) {
    EXPECT_EQ("America/Tegucigalpa", TimeZoneInfo::GetSystemTimeZones()[180].Id());
    EXPECT_EQ("(UTC-06:00:00) America/Tegucigalpa", TimeZoneInfo::GetSystemTimeZones()[180].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[180].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[180].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[180].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[180].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Thule) {
    EXPECT_EQ("America/Thule", TimeZoneInfo::GetSystemTimeZones()[181].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Thule", TimeZoneInfo::GetSystemTimeZones()[181].DisplayName());
    EXPECT_EQ("ADT", TimeZoneInfo::GetSystemTimeZones()[181].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[181].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[181].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[181].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Thunder_Bay) {
    EXPECT_EQ("America/Thunder_Bay", TimeZoneInfo::GetSystemTimeZones()[182].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Thunder_Bay", TimeZoneInfo::GetSystemTimeZones()[182].DisplayName());
    EXPECT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[182].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[182].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[182].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[182].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Tijuana) {
    EXPECT_EQ("America/Tijuana", TimeZoneInfo::GetSystemTimeZones()[183].Id());
    EXPECT_EQ("(UTC-08:00:00) America/Tijuana", TimeZoneInfo::GetSystemTimeZones()[183].DisplayName());
    EXPECT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[183].DaylightName());
    EXPECT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[183].BaseUtcOffset().ToString());
    EXPECT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[183].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[183].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Toronto) {
    EXPECT_EQ("America/Toronto", TimeZoneInfo::GetSystemTimeZones()[184].Id());
    EXPECT_EQ("(UTC-05:00:00) America/Toronto", TimeZoneInfo::GetSystemTimeZones()[184].DisplayName());
    EXPECT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[184].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[184].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[184].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[184].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Tortola) {
    EXPECT_EQ("America/Tortola", TimeZoneInfo::GetSystemTimeZones()[185].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Tortola", TimeZoneInfo::GetSystemTimeZones()[185].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[185].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[185].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[185].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[185].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Vancouver) {
    EXPECT_EQ("America/Vancouver", TimeZoneInfo::GetSystemTimeZones()[186].Id());
    EXPECT_EQ("(UTC-08:00:00) America/Vancouver", TimeZoneInfo::GetSystemTimeZones()[186].DisplayName());
    EXPECT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[186].DaylightName());
    EXPECT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[186].BaseUtcOffset().ToString());
    EXPECT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[186].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[186].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Virgin) {
    EXPECT_EQ("America/Virgin", TimeZoneInfo::GetSystemTimeZones()[187].Id());
    EXPECT_EQ("(UTC-04:00:00) America/Virgin", TimeZoneInfo::GetSystemTimeZones()[187].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[187].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[187].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[187].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[187].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Whitehorse) {
    EXPECT_EQ("America/Whitehorse", TimeZoneInfo::GetSystemTimeZones()[188].Id());
    EXPECT_EQ("(UTC-08:00:00) America/Whitehorse", TimeZoneInfo::GetSystemTimeZones()[188].DisplayName());
    EXPECT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[188].DaylightName());
    EXPECT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[188].BaseUtcOffset().ToString());
    EXPECT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[188].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[188].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Winnipeg) {
    EXPECT_EQ("America/Winnipeg", TimeZoneInfo::GetSystemTimeZones()[189].Id());
    EXPECT_EQ("(UTC-06:00:00) America/Winnipeg", TimeZoneInfo::GetSystemTimeZones()[189].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[189].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[189].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[189].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[189].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Yakutat) {
    EXPECT_EQ("America/Yakutat", TimeZoneInfo::GetSystemTimeZones()[190].Id());
    EXPECT_EQ("(UTC-09:00:00) America/Yakutat", TimeZoneInfo::GetSystemTimeZones()[190].DisplayName());
    EXPECT_EQ("AKDT", TimeZoneInfo::GetSystemTimeZones()[190].DaylightName());
    EXPECT_EQ("-09:00:00", TimeZoneInfo::GetSystemTimeZones()[190].BaseUtcOffset().ToString());
    EXPECT_EQ("AKST", TimeZoneInfo::GetSystemTimeZones()[190].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[190].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAmerica_Yellowknife) {
    EXPECT_EQ("America/Yellowknife", TimeZoneInfo::GetSystemTimeZones()[191].Id());
    EXPECT_EQ("(UTC-07:00:00) America/Yellowknife", TimeZoneInfo::GetSystemTimeZones()[191].DisplayName());
    EXPECT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[191].DaylightName());
    EXPECT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[191].BaseUtcOffset().ToString());
    EXPECT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[191].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[191].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAntarctica_Casey) {
    EXPECT_EQ("Antarctica/Casey", TimeZoneInfo::GetSystemTimeZones()[192].Id());
    EXPECT_EQ("(UTC+08:00:00) Antarctica/Casey", TimeZoneInfo::GetSystemTimeZones()[192].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[192].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[192].BaseUtcOffset().ToString());
    EXPECT_EQ("WST", TimeZoneInfo::GetSystemTimeZones()[192].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[192].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAntarctica_Davis) {
    EXPECT_EQ("Antarctica/Davis", TimeZoneInfo::GetSystemTimeZones()[193].Id());
    EXPECT_EQ("(UTC+07:00:00) Antarctica/Davis", TimeZoneInfo::GetSystemTimeZones()[193].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[193].DaylightName());
    EXPECT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[193].BaseUtcOffset().ToString());
    EXPECT_EQ("DAVT", TimeZoneInfo::GetSystemTimeZones()[193].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[193].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAntarctica_DumontDUrville) {
    EXPECT_EQ("Antarctica/DumontDUrville", TimeZoneInfo::GetSystemTimeZones()[194].Id());
    EXPECT_EQ("(UTC+10:00:00) Antarctica/DumontDUrville", TimeZoneInfo::GetSystemTimeZones()[194].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[194].DaylightName());
    EXPECT_EQ("10:00:00", TimeZoneInfo::GetSystemTimeZones()[194].BaseUtcOffset().ToString());
    EXPECT_EQ("DDUT", TimeZoneInfo::GetSystemTimeZones()[194].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[194].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAntarctica_Macquarie) {
    EXPECT_EQ("Antarctica/Macquarie", TimeZoneInfo::GetSystemTimeZones()[195].Id());
    EXPECT_EQ("(UTC+11:00:00) Antarctica/Macquarie", TimeZoneInfo::GetSystemTimeZones()[195].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[195].DaylightName());
    EXPECT_EQ("11:00:00", TimeZoneInfo::GetSystemTimeZones()[195].BaseUtcOffset().ToString());
    EXPECT_EQ("MIST", TimeZoneInfo::GetSystemTimeZones()[195].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[195].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAntarctica_Mawson) {
    EXPECT_EQ("Antarctica/Mawson", TimeZoneInfo::GetSystemTimeZones()[196].Id());
    EXPECT_EQ("(UTC+05:00:00) Antarctica/Mawson", TimeZoneInfo::GetSystemTimeZones()[196].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[196].DaylightName());
    EXPECT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[196].BaseUtcOffset().ToString());
    EXPECT_EQ("MAWT", TimeZoneInfo::GetSystemTimeZones()[196].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[196].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAntarctica_McMurdo) {
    EXPECT_EQ("Antarctica/McMurdo", TimeZoneInfo::GetSystemTimeZones()[197].Id());
    EXPECT_EQ("(UTC+12:00:00) Antarctica/McMurdo", TimeZoneInfo::GetSystemTimeZones()[197].DisplayName());
    EXPECT_EQ("NZDT", TimeZoneInfo::GetSystemTimeZones()[197].DaylightName());
    EXPECT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[197].BaseUtcOffset().ToString());
    EXPECT_EQ("NZST", TimeZoneInfo::GetSystemTimeZones()[197].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[197].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAntarctica_Palmer) {
    EXPECT_EQ("Antarctica/Palmer", TimeZoneInfo::GetSystemTimeZones()[198].Id());
    EXPECT_EQ("(UTC-04:00:00) Antarctica/Palmer", TimeZoneInfo::GetSystemTimeZones()[198].DisplayName());
    EXPECT_EQ("CLST", TimeZoneInfo::GetSystemTimeZones()[198].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[198].BaseUtcOffset().ToString());
    EXPECT_EQ("CLT", TimeZoneInfo::GetSystemTimeZones()[198].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[198].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAntarctica_Rothera) {
    EXPECT_EQ("Antarctica/Rothera", TimeZoneInfo::GetSystemTimeZones()[199].Id());
    EXPECT_EQ("(UTC-03:00:00) Antarctica/Rothera", TimeZoneInfo::GetSystemTimeZones()[199].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[199].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[199].BaseUtcOffset().ToString());
    EXPECT_EQ("ROTT", TimeZoneInfo::GetSystemTimeZones()[199].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[199].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAntarctica_South_Pole) {
    EXPECT_EQ("Antarctica/South_Pole", TimeZoneInfo::GetSystemTimeZones()[200].Id());
    EXPECT_EQ("(UTC+12:00:00) Antarctica/South_Pole", TimeZoneInfo::GetSystemTimeZones()[200].DisplayName());
    EXPECT_EQ("NZDT", TimeZoneInfo::GetSystemTimeZones()[200].DaylightName());
    EXPECT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[200].BaseUtcOffset().ToString());
    EXPECT_EQ("NZST", TimeZoneInfo::GetSystemTimeZones()[200].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[200].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAntarctica_Syowa) {
    EXPECT_EQ("Antarctica/Syowa", TimeZoneInfo::GetSystemTimeZones()[201].Id());
    EXPECT_EQ("(UTC+03:00:00) Antarctica/Syowa", TimeZoneInfo::GetSystemTimeZones()[201].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[201].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[201].BaseUtcOffset().ToString());
    EXPECT_EQ("SYOT", TimeZoneInfo::GetSystemTimeZones()[201].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[201].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAntarctica_Vostok) {
    EXPECT_EQ("Antarctica/Vostok", TimeZoneInfo::GetSystemTimeZones()[202].Id());
    EXPECT_EQ("(UTC+06:00:00) Antarctica/Vostok", TimeZoneInfo::GetSystemTimeZones()[202].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[202].DaylightName());
    EXPECT_EQ("06:00:00", TimeZoneInfo::GetSystemTimeZones()[202].BaseUtcOffset().ToString());
    EXPECT_EQ("VOST", TimeZoneInfo::GetSystemTimeZones()[202].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[202].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesArctic_Longyearbyen) {
    EXPECT_EQ("Arctic/Longyearbyen", TimeZoneInfo::GetSystemTimeZones()[203].Id());
    EXPECT_EQ("(UTC+01:00:00) Arctic/Longyearbyen", TimeZoneInfo::GetSystemTimeZones()[203].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[203].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[203].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[203].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[203].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Aden) {
    EXPECT_EQ("Asia/Aden", TimeZoneInfo::GetSystemTimeZones()[204].Id());
    EXPECT_EQ("(UTC+03:00:00) Asia/Aden", TimeZoneInfo::GetSystemTimeZones()[204].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[204].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[204].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[204].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[204].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Almaty) {
    EXPECT_EQ("Asia/Almaty", TimeZoneInfo::GetSystemTimeZones()[205].Id());
    EXPECT_EQ("(UTC+06:00:00) Asia/Almaty", TimeZoneInfo::GetSystemTimeZones()[205].DisplayName());
    EXPECT_EQ("ALMST", TimeZoneInfo::GetSystemTimeZones()[205].DaylightName());
    EXPECT_EQ("06:00:00", TimeZoneInfo::GetSystemTimeZones()[205].BaseUtcOffset().ToString());
    EXPECT_EQ("ALMT", TimeZoneInfo::GetSystemTimeZones()[205].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[205].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Amman) {
    EXPECT_EQ("Asia/Amman", TimeZoneInfo::GetSystemTimeZones()[206].Id());
    EXPECT_EQ("(UTC+02:00:00) Asia/Amman", TimeZoneInfo::GetSystemTimeZones()[206].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[206].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[206].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[206].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[206].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Anadyr) {
    EXPECT_EQ("Asia/Anadyr", TimeZoneInfo::GetSystemTimeZones()[207].Id());
    EXPECT_EQ("(UTC+12:00:00) Asia/Anadyr", TimeZoneInfo::GetSystemTimeZones()[207].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[207].DaylightName());
    EXPECT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[207].BaseUtcOffset().ToString());
    EXPECT_EQ("ANAT", TimeZoneInfo::GetSystemTimeZones()[207].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[207].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Aqtau) {
    EXPECT_EQ("Asia/Aqtau", TimeZoneInfo::GetSystemTimeZones()[208].Id());
    EXPECT_EQ("(UTC+05:00:00) Asia/Aqtau", TimeZoneInfo::GetSystemTimeZones()[208].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[208].DaylightName());
    EXPECT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[208].BaseUtcOffset().ToString());
    EXPECT_EQ("AQTT", TimeZoneInfo::GetSystemTimeZones()[208].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[208].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Aqtobe) {
    EXPECT_EQ("Asia/Aqtobe", TimeZoneInfo::GetSystemTimeZones()[209].Id());
    EXPECT_EQ("(UTC+05:00:00) Asia/Aqtobe", TimeZoneInfo::GetSystemTimeZones()[209].DisplayName());
    EXPECT_EQ("AQTST", TimeZoneInfo::GetSystemTimeZones()[209].DaylightName());
    EXPECT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[209].BaseUtcOffset().ToString());
    EXPECT_EQ("AQTT", TimeZoneInfo::GetSystemTimeZones()[209].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[209].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Ashgabat) {
    EXPECT_EQ("Asia/Ashgabat", TimeZoneInfo::GetSystemTimeZones()[210].Id());
    EXPECT_EQ("(UTC+05:00:00) Asia/Ashgabat", TimeZoneInfo::GetSystemTimeZones()[210].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[210].DaylightName());
    EXPECT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[210].BaseUtcOffset().ToString());
    EXPECT_EQ("TMT", TimeZoneInfo::GetSystemTimeZones()[210].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[210].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Ashkhabad) {
    EXPECT_EQ("Asia/Ashkhabad", TimeZoneInfo::GetSystemTimeZones()[211].Id());
    EXPECT_EQ("(UTC+05:00:00) Asia/Ashkhabad", TimeZoneInfo::GetSystemTimeZones()[211].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[211].DaylightName());
    EXPECT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[211].BaseUtcOffset().ToString());
    EXPECT_EQ("TMT", TimeZoneInfo::GetSystemTimeZones()[211].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[211].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Baghdad) {
    EXPECT_EQ("Asia/Baghdad", TimeZoneInfo::GetSystemTimeZones()[212].Id());
    EXPECT_EQ("(UTC+03:00:00) Asia/Baghdad", TimeZoneInfo::GetSystemTimeZones()[212].DisplayName());
    EXPECT_EQ("ADT", TimeZoneInfo::GetSystemTimeZones()[212].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[212].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[212].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[212].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Bahrain) {
    EXPECT_EQ("Asia/Bahrain", TimeZoneInfo::GetSystemTimeZones()[213].Id());
    EXPECT_EQ("(UTC+03:00:00) Asia/Bahrain", TimeZoneInfo::GetSystemTimeZones()[213].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[213].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[213].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[213].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[213].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Baku) {
    EXPECT_EQ("Asia/Baku", TimeZoneInfo::GetSystemTimeZones()[214].Id());
    EXPECT_EQ("(UTC+04:00:00) Asia/Baku", TimeZoneInfo::GetSystemTimeZones()[214].DisplayName());
    EXPECT_EQ("AZST", TimeZoneInfo::GetSystemTimeZones()[214].DaylightName());
    EXPECT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[214].BaseUtcOffset().ToString());
    EXPECT_EQ("AZT", TimeZoneInfo::GetSystemTimeZones()[214].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[214].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Bangkok) {
    EXPECT_EQ("Asia/Bangkok", TimeZoneInfo::GetSystemTimeZones()[215].Id());
    EXPECT_EQ("(UTC+07:00:00) Asia/Bangkok", TimeZoneInfo::GetSystemTimeZones()[215].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[215].DaylightName());
    EXPECT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[215].BaseUtcOffset().ToString());
    EXPECT_EQ("ICT", TimeZoneInfo::GetSystemTimeZones()[215].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[215].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Beirut) {
    EXPECT_EQ("Asia/Beirut", TimeZoneInfo::GetSystemTimeZones()[216].Id());
    EXPECT_EQ("(UTC+02:00:00) Asia/Beirut", TimeZoneInfo::GetSystemTimeZones()[216].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[216].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[216].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[216].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[216].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Bishkek) {
    EXPECT_EQ("Asia/Bishkek", TimeZoneInfo::GetSystemTimeZones()[217].Id());
    EXPECT_EQ("(UTC+06:00:00) Asia/Bishkek", TimeZoneInfo::GetSystemTimeZones()[217].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[217].DaylightName());
    EXPECT_EQ("06:00:00", TimeZoneInfo::GetSystemTimeZones()[217].BaseUtcOffset().ToString());
    EXPECT_EQ("KGT", TimeZoneInfo::GetSystemTimeZones()[217].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[217].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Brunei) {
    EXPECT_EQ("Asia/Brunei", TimeZoneInfo::GetSystemTimeZones()[218].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Brunei", TimeZoneInfo::GetSystemTimeZones()[218].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[218].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[218].BaseUtcOffset().ToString());
    EXPECT_EQ("BNT", TimeZoneInfo::GetSystemTimeZones()[218].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[218].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Calcutta) {
    EXPECT_EQ("Asia/Calcutta", TimeZoneInfo::GetSystemTimeZones()[219].Id());
    EXPECT_EQ("(UTC+05:30:00) Asia/Calcutta", TimeZoneInfo::GetSystemTimeZones()[219].DisplayName());
    EXPECT_EQ("IST", TimeZoneInfo::GetSystemTimeZones()[219].DaylightName());
    EXPECT_EQ("05:30:00", TimeZoneInfo::GetSystemTimeZones()[219].BaseUtcOffset().ToString());
    EXPECT_EQ("IST", TimeZoneInfo::GetSystemTimeZones()[219].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[219].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Choibalsan) {
    EXPECT_EQ("Asia/Choibalsan", TimeZoneInfo::GetSystemTimeZones()[220].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Choibalsan", TimeZoneInfo::GetSystemTimeZones()[220].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[220].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[220].BaseUtcOffset().ToString());
    EXPECT_EQ("CHOT", TimeZoneInfo::GetSystemTimeZones()[220].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[220].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Chongqing) {
    EXPECT_EQ("Asia/Chongqing", TimeZoneInfo::GetSystemTimeZones()[221].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Chongqing", TimeZoneInfo::GetSystemTimeZones()[221].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[221].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[221].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[221].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[221].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Chungking) {
    EXPECT_EQ("Asia/Chungking", TimeZoneInfo::GetSystemTimeZones()[222].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Chungking", TimeZoneInfo::GetSystemTimeZones()[222].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[222].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[222].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[222].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[222].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Colombo) {
    EXPECT_EQ("Asia/Colombo", TimeZoneInfo::GetSystemTimeZones()[223].Id());
    EXPECT_EQ("(UTC+05:30:00) Asia/Colombo", TimeZoneInfo::GetSystemTimeZones()[223].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[223].DaylightName());
    EXPECT_EQ("05:30:00", TimeZoneInfo::GetSystemTimeZones()[223].BaseUtcOffset().ToString());
    EXPECT_EQ("IST", TimeZoneInfo::GetSystemTimeZones()[223].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[223].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Dacca) {
    EXPECT_EQ("Asia/Dacca", TimeZoneInfo::GetSystemTimeZones()[224].Id());
    EXPECT_EQ("(UTC+06:00:00) Asia/Dacca", TimeZoneInfo::GetSystemTimeZones()[224].DisplayName());
    EXPECT_EQ("BDST", TimeZoneInfo::GetSystemTimeZones()[224].DaylightName());
    EXPECT_EQ("06:00:00", TimeZoneInfo::GetSystemTimeZones()[224].BaseUtcOffset().ToString());
    EXPECT_EQ("BDT", TimeZoneInfo::GetSystemTimeZones()[224].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[224].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Damascus) {
    EXPECT_EQ("Asia/Damascus", TimeZoneInfo::GetSystemTimeZones()[225].Id());
    EXPECT_EQ("(UTC+02:00:00) Asia/Damascus", TimeZoneInfo::GetSystemTimeZones()[225].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[225].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[225].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[225].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[225].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Dhaka) {
    EXPECT_EQ("Asia/Dhaka", TimeZoneInfo::GetSystemTimeZones()[226].Id());
    EXPECT_EQ("(UTC+06:00:00) Asia/Dhaka", TimeZoneInfo::GetSystemTimeZones()[226].DisplayName());
    EXPECT_EQ("BDST", TimeZoneInfo::GetSystemTimeZones()[226].DaylightName());
    EXPECT_EQ("06:00:00", TimeZoneInfo::GetSystemTimeZones()[226].BaseUtcOffset().ToString());
    EXPECT_EQ("BDT", TimeZoneInfo::GetSystemTimeZones()[226].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[226].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Dili) {
    EXPECT_EQ("Asia/Dili", TimeZoneInfo::GetSystemTimeZones()[227].Id());
    EXPECT_EQ("(UTC+09:00:00) Asia/Dili", TimeZoneInfo::GetSystemTimeZones()[227].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[227].DaylightName());
    EXPECT_EQ("09:00:00", TimeZoneInfo::GetSystemTimeZones()[227].BaseUtcOffset().ToString());
    EXPECT_EQ("TLT", TimeZoneInfo::GetSystemTimeZones()[227].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[227].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Dubai) {
    EXPECT_EQ("Asia/Dubai", TimeZoneInfo::GetSystemTimeZones()[228].Id());
    EXPECT_EQ("(UTC+04:00:00) Asia/Dubai", TimeZoneInfo::GetSystemTimeZones()[228].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[228].DaylightName());
    EXPECT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[228].BaseUtcOffset().ToString());
    EXPECT_EQ("GST", TimeZoneInfo::GetSystemTimeZones()[228].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[228].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Dushanbe) {
    EXPECT_EQ("Asia/Dushanbe", TimeZoneInfo::GetSystemTimeZones()[229].Id());
    EXPECT_EQ("(UTC+05:00:00) Asia/Dushanbe", TimeZoneInfo::GetSystemTimeZones()[229].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[229].DaylightName());
    EXPECT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[229].BaseUtcOffset().ToString());
    EXPECT_EQ("TJT", TimeZoneInfo::GetSystemTimeZones()[229].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[229].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Gaza) {
    EXPECT_EQ("Asia/Gaza", TimeZoneInfo::GetSystemTimeZones()[230].Id());
    EXPECT_EQ("(UTC+02:00:00) Asia/Gaza", TimeZoneInfo::GetSystemTimeZones()[230].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[230].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[230].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[230].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[230].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Harbin) {
    EXPECT_EQ("Asia/Harbin", TimeZoneInfo::GetSystemTimeZones()[231].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Harbin", TimeZoneInfo::GetSystemTimeZones()[231].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[231].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[231].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[231].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[231].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Hebron) {
    EXPECT_EQ("Asia/Hebron", TimeZoneInfo::GetSystemTimeZones()[232].Id());
    EXPECT_EQ("(UTC+02:00:00) Asia/Hebron", TimeZoneInfo::GetSystemTimeZones()[232].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[232].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[232].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[232].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[232].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Ho_Chi_Minh) {
    EXPECT_EQ("Asia/Ho_Chi_Minh", TimeZoneInfo::GetSystemTimeZones()[233].Id());
    EXPECT_EQ("(UTC+07:00:00) Asia/Ho_Chi_Minh", TimeZoneInfo::GetSystemTimeZones()[233].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[233].DaylightName());
    EXPECT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[233].BaseUtcOffset().ToString());
    EXPECT_EQ("ICT", TimeZoneInfo::GetSystemTimeZones()[233].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[233].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Hong_Kong) {
    EXPECT_EQ("Asia/Hong_Kong", TimeZoneInfo::GetSystemTimeZones()[234].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Hong_Kong", TimeZoneInfo::GetSystemTimeZones()[234].DisplayName());
    EXPECT_EQ("HKST", TimeZoneInfo::GetSystemTimeZones()[234].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[234].BaseUtcOffset().ToString());
    EXPECT_EQ("HKT", TimeZoneInfo::GetSystemTimeZones()[234].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[234].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Hovd) {
    EXPECT_EQ("Asia/Hovd", TimeZoneInfo::GetSystemTimeZones()[235].Id());
    EXPECT_EQ("(UTC+07:00:00) Asia/Hovd", TimeZoneInfo::GetSystemTimeZones()[235].DisplayName());
    EXPECT_EQ("HOVST", TimeZoneInfo::GetSystemTimeZones()[235].DaylightName());
    EXPECT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[235].BaseUtcOffset().ToString());
    EXPECT_EQ("HOVT", TimeZoneInfo::GetSystemTimeZones()[235].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[235].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Irkutsk) {
    EXPECT_EQ("Asia/Irkutsk", TimeZoneInfo::GetSystemTimeZones()[236].Id());
    EXPECT_EQ("(UTC+09:00:00) Asia/Irkutsk", TimeZoneInfo::GetSystemTimeZones()[236].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[236].DaylightName());
    EXPECT_EQ("09:00:00", TimeZoneInfo::GetSystemTimeZones()[236].BaseUtcOffset().ToString());
    EXPECT_EQ("IRKT", TimeZoneInfo::GetSystemTimeZones()[236].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[236].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Istanbul) {
    EXPECT_EQ("Asia/Istanbul", TimeZoneInfo::GetSystemTimeZones()[237].Id());
    EXPECT_EQ("(UTC+02:00:00) Asia/Istanbul", TimeZoneInfo::GetSystemTimeZones()[237].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[237].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[237].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[237].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[237].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Jakarta) {
    EXPECT_EQ("Asia/Jakarta", TimeZoneInfo::GetSystemTimeZones()[238].Id());
    EXPECT_EQ("(UTC+07:00:00) Asia/Jakarta", TimeZoneInfo::GetSystemTimeZones()[238].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[238].DaylightName());
    EXPECT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[238].BaseUtcOffset().ToString());
    EXPECT_EQ("WIB", TimeZoneInfo::GetSystemTimeZones()[238].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[238].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Jayapura) {
    EXPECT_EQ("Asia/Jayapura", TimeZoneInfo::GetSystemTimeZones()[239].Id());
    EXPECT_EQ("(UTC+09:00:00) Asia/Jayapura", TimeZoneInfo::GetSystemTimeZones()[239].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[239].DaylightName());
    EXPECT_EQ("09:00:00", TimeZoneInfo::GetSystemTimeZones()[239].BaseUtcOffset().ToString());
    EXPECT_EQ("WIT", TimeZoneInfo::GetSystemTimeZones()[239].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[239].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Jerusalem) {
    EXPECT_EQ("Asia/Jerusalem", TimeZoneInfo::GetSystemTimeZones()[240].Id());
    EXPECT_EQ("(UTC+02:00:00) Asia/Jerusalem", TimeZoneInfo::GetSystemTimeZones()[240].DisplayName());
    EXPECT_EQ("IDT", TimeZoneInfo::GetSystemTimeZones()[240].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[240].BaseUtcOffset().ToString());
    EXPECT_EQ("IST", TimeZoneInfo::GetSystemTimeZones()[240].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[240].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Kabul) {
    EXPECT_EQ("Asia/Kabul", TimeZoneInfo::GetSystemTimeZones()[241].Id());
    EXPECT_EQ("(UTC+04:30:00) Asia/Kabul", TimeZoneInfo::GetSystemTimeZones()[241].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[241].DaylightName());
    EXPECT_EQ("04:30:00", TimeZoneInfo::GetSystemTimeZones()[241].BaseUtcOffset().ToString());
    EXPECT_EQ("AFT", TimeZoneInfo::GetSystemTimeZones()[241].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[241].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Kamchatka) {
    EXPECT_EQ("Asia/Kamchatka", TimeZoneInfo::GetSystemTimeZones()[242].Id());
    EXPECT_EQ("(UTC+12:00:00) Asia/Kamchatka", TimeZoneInfo::GetSystemTimeZones()[242].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[242].DaylightName());
    EXPECT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[242].BaseUtcOffset().ToString());
    EXPECT_EQ("PETT", TimeZoneInfo::GetSystemTimeZones()[242].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[242].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Karachi) {
    EXPECT_EQ("Asia/Karachi", TimeZoneInfo::GetSystemTimeZones()[243].Id());
    EXPECT_EQ("(UTC+05:00:00) Asia/Karachi", TimeZoneInfo::GetSystemTimeZones()[243].DisplayName());
    EXPECT_EQ("PKST", TimeZoneInfo::GetSystemTimeZones()[243].DaylightName());
    EXPECT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[243].BaseUtcOffset().ToString());
    EXPECT_EQ("PKT", TimeZoneInfo::GetSystemTimeZones()[243].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[243].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Kashgar) {
    EXPECT_EQ("Asia/Kashgar", TimeZoneInfo::GetSystemTimeZones()[244].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Kashgar", TimeZoneInfo::GetSystemTimeZones()[244].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[244].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[244].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[244].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[244].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Kathmandu) {
    EXPECT_EQ("Asia/Kathmandu", TimeZoneInfo::GetSystemTimeZones()[245].Id());
    EXPECT_EQ("(UTC+05:45:00) Asia/Kathmandu", TimeZoneInfo::GetSystemTimeZones()[245].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[245].DaylightName());
    EXPECT_EQ("05:45:00", TimeZoneInfo::GetSystemTimeZones()[245].BaseUtcOffset().ToString());
    EXPECT_EQ("NPT", TimeZoneInfo::GetSystemTimeZones()[245].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[245].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Katmandu) {
    EXPECT_EQ("Asia/Katmandu", TimeZoneInfo::GetSystemTimeZones()[246].Id());
    EXPECT_EQ("(UTC+05:45:00) Asia/Katmandu", TimeZoneInfo::GetSystemTimeZones()[246].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[246].DaylightName());
    EXPECT_EQ("05:45:00", TimeZoneInfo::GetSystemTimeZones()[246].BaseUtcOffset().ToString());
    EXPECT_EQ("NPT", TimeZoneInfo::GetSystemTimeZones()[246].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[246].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Khandyga) {
    EXPECT_EQ("Asia/Khandyga", TimeZoneInfo::GetSystemTimeZones()[247].Id());
    EXPECT_EQ("(UTC+10:00:00) Asia/Khandyga", TimeZoneInfo::GetSystemTimeZones()[247].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[247].DaylightName());
    EXPECT_EQ("10:00:00", TimeZoneInfo::GetSystemTimeZones()[247].BaseUtcOffset().ToString());
    EXPECT_EQ("YAKT", TimeZoneInfo::GetSystemTimeZones()[247].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[247].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Kolkata) {
    EXPECT_EQ("Asia/Kolkata", TimeZoneInfo::GetSystemTimeZones()[248].Id());
    EXPECT_EQ("(UTC+05:30:00) Asia/Kolkata", TimeZoneInfo::GetSystemTimeZones()[248].DisplayName());
    EXPECT_EQ("IST", TimeZoneInfo::GetSystemTimeZones()[248].DaylightName());
    EXPECT_EQ("05:30:00", TimeZoneInfo::GetSystemTimeZones()[248].BaseUtcOffset().ToString());
    EXPECT_EQ("IST", TimeZoneInfo::GetSystemTimeZones()[248].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[248].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Krasnoyarsk) {
    EXPECT_EQ("Asia/Krasnoyarsk", TimeZoneInfo::GetSystemTimeZones()[249].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Krasnoyarsk", TimeZoneInfo::GetSystemTimeZones()[249].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[249].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[249].BaseUtcOffset().ToString());
    EXPECT_EQ("KRAT", TimeZoneInfo::GetSystemTimeZones()[249].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[249].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Kuala_Lumpur) {
    EXPECT_EQ("Asia/Kuala_Lumpur", TimeZoneInfo::GetSystemTimeZones()[250].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Kuala_Lumpur", TimeZoneInfo::GetSystemTimeZones()[250].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[250].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[250].BaseUtcOffset().ToString());
    EXPECT_EQ("MYT", TimeZoneInfo::GetSystemTimeZones()[250].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[250].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Kuching) {
    EXPECT_EQ("Asia/Kuching", TimeZoneInfo::GetSystemTimeZones()[251].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Kuching", TimeZoneInfo::GetSystemTimeZones()[251].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[251].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[251].BaseUtcOffset().ToString());
    EXPECT_EQ("MYT", TimeZoneInfo::GetSystemTimeZones()[251].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[251].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Kuwait) {
    EXPECT_EQ("Asia/Kuwait", TimeZoneInfo::GetSystemTimeZones()[252].Id());
    EXPECT_EQ("(UTC+03:00:00) Asia/Kuwait", TimeZoneInfo::GetSystemTimeZones()[252].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[252].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[252].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[252].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[252].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Macao) {
    EXPECT_EQ("Asia/Macao", TimeZoneInfo::GetSystemTimeZones()[253].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Macao", TimeZoneInfo::GetSystemTimeZones()[253].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[253].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[253].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[253].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[253].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Macau) {
    EXPECT_EQ("Asia/Macau", TimeZoneInfo::GetSystemTimeZones()[254].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Macau", TimeZoneInfo::GetSystemTimeZones()[254].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[254].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[254].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[254].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[254].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Magadan) {
    EXPECT_EQ("Asia/Magadan", TimeZoneInfo::GetSystemTimeZones()[255].Id());
    EXPECT_EQ("(UTC+12:00:00) Asia/Magadan", TimeZoneInfo::GetSystemTimeZones()[255].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[255].DaylightName());
    EXPECT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[255].BaseUtcOffset().ToString());
    EXPECT_EQ("MAGT", TimeZoneInfo::GetSystemTimeZones()[255].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[255].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Makassar) {
    EXPECT_EQ("Asia/Makassar", TimeZoneInfo::GetSystemTimeZones()[256].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Makassar", TimeZoneInfo::GetSystemTimeZones()[256].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[256].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[256].BaseUtcOffset().ToString());
    EXPECT_EQ("WITA", TimeZoneInfo::GetSystemTimeZones()[256].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[256].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Manila) {
    EXPECT_EQ("Asia/Manila", TimeZoneInfo::GetSystemTimeZones()[257].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Manila", TimeZoneInfo::GetSystemTimeZones()[257].DisplayName());
    EXPECT_EQ("PHST", TimeZoneInfo::GetSystemTimeZones()[257].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[257].BaseUtcOffset().ToString());
    EXPECT_EQ("PHT", TimeZoneInfo::GetSystemTimeZones()[257].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[257].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Muscat) {
    EXPECT_EQ("Asia/Muscat", TimeZoneInfo::GetSystemTimeZones()[258].Id());
    EXPECT_EQ("(UTC+04:00:00) Asia/Muscat", TimeZoneInfo::GetSystemTimeZones()[258].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[258].DaylightName());
    EXPECT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[258].BaseUtcOffset().ToString());
    EXPECT_EQ("GST", TimeZoneInfo::GetSystemTimeZones()[258].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[258].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Nicosia) {
    EXPECT_EQ("Asia/Nicosia", TimeZoneInfo::GetSystemTimeZones()[259].Id());
    EXPECT_EQ("(UTC+02:00:00) Asia/Nicosia", TimeZoneInfo::GetSystemTimeZones()[259].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[259].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[259].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[259].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[259].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Novokuznetsk) {
    EXPECT_EQ("Asia/Novokuznetsk", TimeZoneInfo::GetSystemTimeZones()[260].Id());
    EXPECT_EQ("(UTC+07:00:00) Asia/Novokuznetsk", TimeZoneInfo::GetSystemTimeZones()[260].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[260].DaylightName());
    EXPECT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[260].BaseUtcOffset().ToString());
    EXPECT_EQ("NOVT", TimeZoneInfo::GetSystemTimeZones()[260].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[260].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Novosibirsk) {
    EXPECT_EQ("Asia/Novosibirsk", TimeZoneInfo::GetSystemTimeZones()[261].Id());
    EXPECT_EQ("(UTC+07:00:00) Asia/Novosibirsk", TimeZoneInfo::GetSystemTimeZones()[261].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[261].DaylightName());
    EXPECT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[261].BaseUtcOffset().ToString());
    EXPECT_EQ("NOVT", TimeZoneInfo::GetSystemTimeZones()[261].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[261].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Omsk) {
    EXPECT_EQ("Asia/Omsk", TimeZoneInfo::GetSystemTimeZones()[262].Id());
    EXPECT_EQ("(UTC+07:00:00) Asia/Omsk", TimeZoneInfo::GetSystemTimeZones()[262].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[262].DaylightName());
    EXPECT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[262].BaseUtcOffset().ToString());
    EXPECT_EQ("OMST", TimeZoneInfo::GetSystemTimeZones()[262].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[262].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Oral) {
    EXPECT_EQ("Asia/Oral", TimeZoneInfo::GetSystemTimeZones()[263].Id());
    EXPECT_EQ("(UTC+05:00:00) Asia/Oral", TimeZoneInfo::GetSystemTimeZones()[263].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[263].DaylightName());
    EXPECT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[263].BaseUtcOffset().ToString());
    EXPECT_EQ("ORAT", TimeZoneInfo::GetSystemTimeZones()[263].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[263].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Phnom_Penh) {
    EXPECT_EQ("Asia/Phnom_Penh", TimeZoneInfo::GetSystemTimeZones()[264].Id());
    EXPECT_EQ("(UTC+07:00:00) Asia/Phnom_Penh", TimeZoneInfo::GetSystemTimeZones()[264].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[264].DaylightName());
    EXPECT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[264].BaseUtcOffset().ToString());
    EXPECT_EQ("ICT", TimeZoneInfo::GetSystemTimeZones()[264].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[264].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Pontianak) {
    EXPECT_EQ("Asia/Pontianak", TimeZoneInfo::GetSystemTimeZones()[265].Id());
    EXPECT_EQ("(UTC+07:00:00) Asia/Pontianak", TimeZoneInfo::GetSystemTimeZones()[265].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[265].DaylightName());
    EXPECT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[265].BaseUtcOffset().ToString());
    EXPECT_EQ("WIB", TimeZoneInfo::GetSystemTimeZones()[265].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[265].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Pyongyang) {
    EXPECT_EQ("Asia/Pyongyang", TimeZoneInfo::GetSystemTimeZones()[266].Id());
    EXPECT_EQ("(UTC+09:00:00) Asia/Pyongyang", TimeZoneInfo::GetSystemTimeZones()[266].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[266].DaylightName());
    EXPECT_EQ("09:00:00", TimeZoneInfo::GetSystemTimeZones()[266].BaseUtcOffset().ToString());
    EXPECT_EQ("KST", TimeZoneInfo::GetSystemTimeZones()[266].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[266].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Qatar) {
    EXPECT_EQ("Asia/Qatar", TimeZoneInfo::GetSystemTimeZones()[267].Id());
    EXPECT_EQ("(UTC+03:00:00) Asia/Qatar", TimeZoneInfo::GetSystemTimeZones()[267].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[267].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[267].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[267].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[267].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Qyzylorda) {
    EXPECT_EQ("Asia/Qyzylorda", TimeZoneInfo::GetSystemTimeZones()[268].Id());
    EXPECT_EQ("(UTC+06:00:00) Asia/Qyzylorda", TimeZoneInfo::GetSystemTimeZones()[268].DisplayName());
    EXPECT_EQ("QYZST", TimeZoneInfo::GetSystemTimeZones()[268].DaylightName());
    EXPECT_EQ("06:00:00", TimeZoneInfo::GetSystemTimeZones()[268].BaseUtcOffset().ToString());
    EXPECT_EQ("QYZT", TimeZoneInfo::GetSystemTimeZones()[268].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[268].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Rangoon) {
    EXPECT_EQ("Asia/Rangoon", TimeZoneInfo::GetSystemTimeZones()[269].Id());
    EXPECT_EQ("(UTC+06:30:00) Asia/Rangoon", TimeZoneInfo::GetSystemTimeZones()[269].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[269].DaylightName());
    EXPECT_EQ("06:30:00", TimeZoneInfo::GetSystemTimeZones()[269].BaseUtcOffset().ToString());
    EXPECT_EQ("MMT", TimeZoneInfo::GetSystemTimeZones()[269].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[269].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Riyadh) {
    EXPECT_EQ("Asia/Riyadh", TimeZoneInfo::GetSystemTimeZones()[270].Id());
    EXPECT_EQ("(UTC+03:00:00) Asia/Riyadh", TimeZoneInfo::GetSystemTimeZones()[270].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[270].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[270].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[270].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[270].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Saigon) {
    EXPECT_EQ("Asia/Saigon", TimeZoneInfo::GetSystemTimeZones()[271].Id());
    EXPECT_EQ("(UTC+07:00:00) Asia/Saigon", TimeZoneInfo::GetSystemTimeZones()[271].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[271].DaylightName());
    EXPECT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[271].BaseUtcOffset().ToString());
    EXPECT_EQ("ICT", TimeZoneInfo::GetSystemTimeZones()[271].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[271].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Sakhalin) {
    EXPECT_EQ("Asia/Sakhalin", TimeZoneInfo::GetSystemTimeZones()[272].Id());
    EXPECT_EQ("(UTC+11:00:00) Asia/Sakhalin", TimeZoneInfo::GetSystemTimeZones()[272].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[272].DaylightName());
    EXPECT_EQ("11:00:00", TimeZoneInfo::GetSystemTimeZones()[272].BaseUtcOffset().ToString());
    EXPECT_EQ("SAKT", TimeZoneInfo::GetSystemTimeZones()[272].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[272].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Samarkand) {
    EXPECT_EQ("Asia/Samarkand", TimeZoneInfo::GetSystemTimeZones()[273].Id());
    EXPECT_EQ("(UTC+05:00:00) Asia/Samarkand", TimeZoneInfo::GetSystemTimeZones()[273].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[273].DaylightName());
    EXPECT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[273].BaseUtcOffset().ToString());
    EXPECT_EQ("UZT", TimeZoneInfo::GetSystemTimeZones()[273].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[273].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Seoul) {
    EXPECT_EQ("Asia/Seoul", TimeZoneInfo::GetSystemTimeZones()[274].Id());
    EXPECT_EQ("(UTC+09:00:00) Asia/Seoul", TimeZoneInfo::GetSystemTimeZones()[274].DisplayName());
    EXPECT_EQ("KDT", TimeZoneInfo::GetSystemTimeZones()[274].DaylightName());
    EXPECT_EQ("09:00:00", TimeZoneInfo::GetSystemTimeZones()[274].BaseUtcOffset().ToString());
    EXPECT_EQ("KST", TimeZoneInfo::GetSystemTimeZones()[274].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[274].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Shanghai) {
    EXPECT_EQ("Asia/Shanghai", TimeZoneInfo::GetSystemTimeZones()[275].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Shanghai", TimeZoneInfo::GetSystemTimeZones()[275].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[275].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[275].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[275].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[275].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Singapore) {
    EXPECT_EQ("Asia/Singapore", TimeZoneInfo::GetSystemTimeZones()[276].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Singapore", TimeZoneInfo::GetSystemTimeZones()[276].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[276].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[276].BaseUtcOffset().ToString());
    EXPECT_EQ("SGT", TimeZoneInfo::GetSystemTimeZones()[276].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[276].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Taipei) {
    EXPECT_EQ("Asia/Taipei", TimeZoneInfo::GetSystemTimeZones()[277].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Taipei", TimeZoneInfo::GetSystemTimeZones()[277].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[277].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[277].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[277].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[277].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Tashkent) {
    EXPECT_EQ("Asia/Tashkent", TimeZoneInfo::GetSystemTimeZones()[278].Id());
    EXPECT_EQ("(UTC+05:00:00) Asia/Tashkent", TimeZoneInfo::GetSystemTimeZones()[278].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[278].DaylightName());
    EXPECT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[278].BaseUtcOffset().ToString());
    EXPECT_EQ("UZT", TimeZoneInfo::GetSystemTimeZones()[278].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[278].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Tbilisi) {
    EXPECT_EQ("Asia/Tbilisi", TimeZoneInfo::GetSystemTimeZones()[279].Id());
    EXPECT_EQ("(UTC+04:00:00) Asia/Tbilisi", TimeZoneInfo::GetSystemTimeZones()[279].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[279].DaylightName());
    EXPECT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[279].BaseUtcOffset().ToString());
    EXPECT_EQ("GET", TimeZoneInfo::GetSystemTimeZones()[279].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[279].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Tehran) {
    EXPECT_EQ("Asia/Tehran", TimeZoneInfo::GetSystemTimeZones()[280].Id());
    EXPECT_EQ("(UTC+03:30:00) Asia/Tehran", TimeZoneInfo::GetSystemTimeZones()[280].DisplayName());
    EXPECT_EQ("IRDT", TimeZoneInfo::GetSystemTimeZones()[280].DaylightName());
    EXPECT_EQ("03:30:00", TimeZoneInfo::GetSystemTimeZones()[280].BaseUtcOffset().ToString());
    EXPECT_EQ("IRST", TimeZoneInfo::GetSystemTimeZones()[280].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[280].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Tel_Aviv) {
    EXPECT_EQ("Asia/Tel_Aviv", TimeZoneInfo::GetSystemTimeZones()[281].Id());
    EXPECT_EQ("(UTC+02:00:00) Asia/Tel_Aviv", TimeZoneInfo::GetSystemTimeZones()[281].DisplayName());
    EXPECT_EQ("IDT", TimeZoneInfo::GetSystemTimeZones()[281].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[281].BaseUtcOffset().ToString());
    EXPECT_EQ("IST", TimeZoneInfo::GetSystemTimeZones()[281].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[281].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Thimbu) {
    EXPECT_EQ("Asia/Thimbu", TimeZoneInfo::GetSystemTimeZones()[282].Id());
    EXPECT_EQ("(UTC+06:00:00) Asia/Thimbu", TimeZoneInfo::GetSystemTimeZones()[282].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[282].DaylightName());
    EXPECT_EQ("06:00:00", TimeZoneInfo::GetSystemTimeZones()[282].BaseUtcOffset().ToString());
    EXPECT_EQ("BTT", TimeZoneInfo::GetSystemTimeZones()[282].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[282].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Thimphu) {
    EXPECT_EQ("Asia/Thimphu", TimeZoneInfo::GetSystemTimeZones()[283].Id());
    EXPECT_EQ("(UTC+06:00:00) Asia/Thimphu", TimeZoneInfo::GetSystemTimeZones()[283].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[283].DaylightName());
    EXPECT_EQ("06:00:00", TimeZoneInfo::GetSystemTimeZones()[283].BaseUtcOffset().ToString());
    EXPECT_EQ("BTT", TimeZoneInfo::GetSystemTimeZones()[283].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[283].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Tokyo) {
    EXPECT_EQ("Asia/Tokyo", TimeZoneInfo::GetSystemTimeZones()[284].Id());
    EXPECT_EQ("(UTC+09:00:00) Asia/Tokyo", TimeZoneInfo::GetSystemTimeZones()[284].DisplayName());
    EXPECT_EQ("JDT", TimeZoneInfo::GetSystemTimeZones()[284].DaylightName());
    EXPECT_EQ("09:00:00", TimeZoneInfo::GetSystemTimeZones()[284].BaseUtcOffset().ToString());
    EXPECT_EQ("JST", TimeZoneInfo::GetSystemTimeZones()[284].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[284].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Ujung_Pandang) {
    EXPECT_EQ("Asia/Ujung_Pandang", TimeZoneInfo::GetSystemTimeZones()[285].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Ujung_Pandang", TimeZoneInfo::GetSystemTimeZones()[285].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[285].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[285].BaseUtcOffset().ToString());
    EXPECT_EQ("WITA", TimeZoneInfo::GetSystemTimeZones()[285].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[285].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Ulaanbaatar) {
    EXPECT_EQ("Asia/Ulaanbaatar", TimeZoneInfo::GetSystemTimeZones()[286].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Ulaanbaatar", TimeZoneInfo::GetSystemTimeZones()[286].DisplayName());
    EXPECT_EQ("ULAST", TimeZoneInfo::GetSystemTimeZones()[286].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[286].BaseUtcOffset().ToString());
    EXPECT_EQ("ULAT", TimeZoneInfo::GetSystemTimeZones()[286].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[286].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Ulan_Bator) {
    EXPECT_EQ("Asia/Ulan_Bator", TimeZoneInfo::GetSystemTimeZones()[287].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Ulan_Bator", TimeZoneInfo::GetSystemTimeZones()[287].DisplayName());
    EXPECT_EQ("ULAST", TimeZoneInfo::GetSystemTimeZones()[287].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[287].BaseUtcOffset().ToString());
    EXPECT_EQ("ULAT", TimeZoneInfo::GetSystemTimeZones()[287].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[287].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Urumqi) {
    EXPECT_EQ("Asia/Urumqi", TimeZoneInfo::GetSystemTimeZones()[288].Id());
    EXPECT_EQ("(UTC+08:00:00) Asia/Urumqi", TimeZoneInfo::GetSystemTimeZones()[288].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[288].DaylightName());
    EXPECT_EQ("08:00:00", TimeZoneInfo::GetSystemTimeZones()[288].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[288].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[288].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Ust_Nera) {
    EXPECT_EQ("Asia/Ust-Nera", TimeZoneInfo::GetSystemTimeZones()[289].Id());
    EXPECT_EQ("(UTC+11:00:00) Asia/Ust-Nera", TimeZoneInfo::GetSystemTimeZones()[289].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[289].DaylightName());
    EXPECT_EQ("11:00:00", TimeZoneInfo::GetSystemTimeZones()[289].BaseUtcOffset().ToString());
    EXPECT_EQ("VLAT", TimeZoneInfo::GetSystemTimeZones()[289].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[289].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Vientiane) {
    EXPECT_EQ("Asia/Vientiane", TimeZoneInfo::GetSystemTimeZones()[290].Id());
    EXPECT_EQ("(UTC+07:00:00) Asia/Vientiane", TimeZoneInfo::GetSystemTimeZones()[290].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[290].DaylightName());
    EXPECT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[290].BaseUtcOffset().ToString());
    EXPECT_EQ("ICT", TimeZoneInfo::GetSystemTimeZones()[290].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[290].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Vladivostok) {
    EXPECT_EQ("Asia/Vladivostok", TimeZoneInfo::GetSystemTimeZones()[291].Id());
    EXPECT_EQ("(UTC+11:00:00) Asia/Vladivostok", TimeZoneInfo::GetSystemTimeZones()[291].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[291].DaylightName());
    EXPECT_EQ("11:00:00", TimeZoneInfo::GetSystemTimeZones()[291].BaseUtcOffset().ToString());
    EXPECT_EQ("VLAT", TimeZoneInfo::GetSystemTimeZones()[291].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[291].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Yakutsk) {
    EXPECT_EQ("Asia/Yakutsk", TimeZoneInfo::GetSystemTimeZones()[292].Id());
    EXPECT_EQ("(UTC+10:00:00) Asia/Yakutsk", TimeZoneInfo::GetSystemTimeZones()[292].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[292].DaylightName());
    EXPECT_EQ("10:00:00", TimeZoneInfo::GetSystemTimeZones()[292].BaseUtcOffset().ToString());
    EXPECT_EQ("YAKT", TimeZoneInfo::GetSystemTimeZones()[292].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[292].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Yekaterinburg) {
    EXPECT_EQ("Asia/Yekaterinburg", TimeZoneInfo::GetSystemTimeZones()[293].Id());
    EXPECT_EQ("(UTC+06:00:00) Asia/Yekaterinburg", TimeZoneInfo::GetSystemTimeZones()[293].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[293].DaylightName());
    EXPECT_EQ("06:00:00", TimeZoneInfo::GetSystemTimeZones()[293].BaseUtcOffset().ToString());
    EXPECT_EQ("YEKT", TimeZoneInfo::GetSystemTimeZones()[293].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[293].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAsia_Yerevan) {
    EXPECT_EQ("Asia/Yerevan", TimeZoneInfo::GetSystemTimeZones()[294].Id());
    EXPECT_EQ("(UTC+04:00:00) Asia/Yerevan", TimeZoneInfo::GetSystemTimeZones()[294].DisplayName());
    EXPECT_EQ("AMST", TimeZoneInfo::GetSystemTimeZones()[294].DaylightName());
    EXPECT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[294].BaseUtcOffset().ToString());
    EXPECT_EQ("AMT", TimeZoneInfo::GetSystemTimeZones()[294].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[294].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAtlantic_Azores) {
    EXPECT_EQ("Atlantic/Azores", TimeZoneInfo::GetSystemTimeZones()[295].Id());
    EXPECT_EQ("(UTC-01:00:00) Atlantic/Azores", TimeZoneInfo::GetSystemTimeZones()[295].DisplayName());
    EXPECT_EQ("AZOST", TimeZoneInfo::GetSystemTimeZones()[295].DaylightName());
    EXPECT_EQ("-01:00:00", TimeZoneInfo::GetSystemTimeZones()[295].BaseUtcOffset().ToString());
    EXPECT_EQ("AZOT", TimeZoneInfo::GetSystemTimeZones()[295].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[295].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAtlantic_Bermuda) {
    EXPECT_EQ("Atlantic/Bermuda", TimeZoneInfo::GetSystemTimeZones()[296].Id());
    EXPECT_EQ("(UTC-04:00:00) Atlantic/Bermuda", TimeZoneInfo::GetSystemTimeZones()[296].DisplayName());
    EXPECT_EQ("ADT", TimeZoneInfo::GetSystemTimeZones()[296].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[296].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[296].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[296].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAtlantic_Canary) {
    EXPECT_EQ("Atlantic/Canary", TimeZoneInfo::GetSystemTimeZones()[297].Id());
    EXPECT_EQ("(UTC) Atlantic/Canary", TimeZoneInfo::GetSystemTimeZones()[297].DisplayName());
    EXPECT_EQ("WEST", TimeZoneInfo::GetSystemTimeZones()[297].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[297].BaseUtcOffset().ToString());
    EXPECT_EQ("WET", TimeZoneInfo::GetSystemTimeZones()[297].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[297].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAtlantic_Cape_Verde) {
    EXPECT_EQ("Atlantic/Cape_Verde", TimeZoneInfo::GetSystemTimeZones()[298].Id());
    EXPECT_EQ("(UTC-01:00:00) Atlantic/Cape_Verde", TimeZoneInfo::GetSystemTimeZones()[298].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[298].DaylightName());
    EXPECT_EQ("-01:00:00", TimeZoneInfo::GetSystemTimeZones()[298].BaseUtcOffset().ToString());
    EXPECT_EQ("CVT", TimeZoneInfo::GetSystemTimeZones()[298].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[298].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAtlantic_Faeroe) {
    EXPECT_EQ("Atlantic/Faeroe", TimeZoneInfo::GetSystemTimeZones()[299].Id());
    EXPECT_EQ("(UTC) Atlantic/Faeroe", TimeZoneInfo::GetSystemTimeZones()[299].DisplayName());
    EXPECT_EQ("WEST", TimeZoneInfo::GetSystemTimeZones()[299].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[299].BaseUtcOffset().ToString());
    EXPECT_EQ("WET", TimeZoneInfo::GetSystemTimeZones()[299].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[299].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAtlantic_Faroe) {
    EXPECT_EQ("Atlantic/Faroe", TimeZoneInfo::GetSystemTimeZones()[300].Id());
    EXPECT_EQ("(UTC) Atlantic/Faroe", TimeZoneInfo::GetSystemTimeZones()[300].DisplayName());
    EXPECT_EQ("WEST", TimeZoneInfo::GetSystemTimeZones()[300].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[300].BaseUtcOffset().ToString());
    EXPECT_EQ("WET", TimeZoneInfo::GetSystemTimeZones()[300].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[300].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAtlantic_Jan_Mayen) {
    EXPECT_EQ("Atlantic/Jan_Mayen", TimeZoneInfo::GetSystemTimeZones()[301].Id());
    EXPECT_EQ("(UTC+01:00:00) Atlantic/Jan_Mayen", TimeZoneInfo::GetSystemTimeZones()[301].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[301].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[301].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[301].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[301].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAtlantic_Madeira) {
    EXPECT_EQ("Atlantic/Madeira", TimeZoneInfo::GetSystemTimeZones()[302].Id());
    EXPECT_EQ("(UTC) Atlantic/Madeira", TimeZoneInfo::GetSystemTimeZones()[302].DisplayName());
    EXPECT_EQ("WEST", TimeZoneInfo::GetSystemTimeZones()[302].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[302].BaseUtcOffset().ToString());
    EXPECT_EQ("WET", TimeZoneInfo::GetSystemTimeZones()[302].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[302].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAtlantic_Reykjavik) {
    EXPECT_EQ("Atlantic/Reykjavik", TimeZoneInfo::GetSystemTimeZones()[303].Id());
    EXPECT_EQ("(UTC) Atlantic/Reykjavik", TimeZoneInfo::GetSystemTimeZones()[303].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[303].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[303].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[303].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[303].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAtlantic_South_Georgia) {
    EXPECT_EQ("Atlantic/South_Georgia", TimeZoneInfo::GetSystemTimeZones()[304].Id());
    EXPECT_EQ("(UTC-02:00:00) Atlantic/South_Georgia", TimeZoneInfo::GetSystemTimeZones()[304].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[304].DaylightName());
    EXPECT_EQ("-02:00:00", TimeZoneInfo::GetSystemTimeZones()[304].BaseUtcOffset().ToString());
    EXPECT_EQ("GST", TimeZoneInfo::GetSystemTimeZones()[304].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[304].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAtlantic_St_Helena) {
    EXPECT_EQ("Atlantic/St_Helena", TimeZoneInfo::GetSystemTimeZones()[305].Id());
    EXPECT_EQ("(UTC) Atlantic/St_Helena", TimeZoneInfo::GetSystemTimeZones()[305].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[305].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[305].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[305].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[305].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesAtlantic_Stanley) {
    EXPECT_EQ("Atlantic/Stanley", TimeZoneInfo::GetSystemTimeZones()[306].Id());
    EXPECT_EQ("(UTC-03:00:00) Atlantic/Stanley", TimeZoneInfo::GetSystemTimeZones()[306].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[306].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[306].BaseUtcOffset().ToString());
    EXPECT_EQ("FKST", TimeZoneInfo::GetSystemTimeZones()[306].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[306].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesBrazil_Acre) {
    EXPECT_EQ("Brazil/Acre", TimeZoneInfo::GetSystemTimeZones()[307].Id());
    EXPECT_EQ("(UTC-05:00:00) Brazil/Acre", TimeZoneInfo::GetSystemTimeZones()[307].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[307].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[307].BaseUtcOffset().ToString());
    EXPECT_EQ("ACT", TimeZoneInfo::GetSystemTimeZones()[307].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[307].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesBrazil_DeNoronha) {
    EXPECT_EQ("Brazil/DeNoronha", TimeZoneInfo::GetSystemTimeZones()[308].Id());
    EXPECT_EQ("(UTC-02:00:00) Brazil/DeNoronha", TimeZoneInfo::GetSystemTimeZones()[308].DisplayName());
    EXPECT_EQ("FNST", TimeZoneInfo::GetSystemTimeZones()[308].DaylightName());
    EXPECT_EQ("-02:00:00", TimeZoneInfo::GetSystemTimeZones()[308].BaseUtcOffset().ToString());
    EXPECT_EQ("FNT", TimeZoneInfo::GetSystemTimeZones()[308].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[308].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesBrazil_East) {
    EXPECT_EQ("Brazil/East", TimeZoneInfo::GetSystemTimeZones()[309].Id());
    EXPECT_EQ("(UTC-03:00:00) Brazil/East", TimeZoneInfo::GetSystemTimeZones()[309].DisplayName());
    EXPECT_EQ("BRST", TimeZoneInfo::GetSystemTimeZones()[309].DaylightName());
    EXPECT_EQ("-03:00:00", TimeZoneInfo::GetSystemTimeZones()[309].BaseUtcOffset().ToString());
    EXPECT_EQ("BRT", TimeZoneInfo::GetSystemTimeZones()[309].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[309].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesBrazil_West) {
    EXPECT_EQ("Brazil/West", TimeZoneInfo::GetSystemTimeZones()[310].Id());
    EXPECT_EQ("(UTC-04:00:00) Brazil/West", TimeZoneInfo::GetSystemTimeZones()[310].DisplayName());
    EXPECT_EQ("AMST", TimeZoneInfo::GetSystemTimeZones()[310].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[310].BaseUtcOffset().ToString());
    EXPECT_EQ("AMT", TimeZoneInfo::GetSystemTimeZones()[310].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[310].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesCanada_Atlantic) {
    EXPECT_EQ("Canada/Atlantic", TimeZoneInfo::GetSystemTimeZones()[311].Id());
    EXPECT_EQ("(UTC-04:00:00) Canada/Atlantic", TimeZoneInfo::GetSystemTimeZones()[311].DisplayName());
    EXPECT_EQ("ADT", TimeZoneInfo::GetSystemTimeZones()[311].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[311].BaseUtcOffset().ToString());
    EXPECT_EQ("AST", TimeZoneInfo::GetSystemTimeZones()[311].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[311].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesCanada_Central) {
    EXPECT_EQ("Canada/Central", TimeZoneInfo::GetSystemTimeZones()[312].Id());
    EXPECT_EQ("(UTC-06:00:00) Canada/Central", TimeZoneInfo::GetSystemTimeZones()[312].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[312].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[312].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[312].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[312].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesCanada_East_Saskatchewan) {
    EXPECT_EQ("Canada/East-Saskatchewan", TimeZoneInfo::GetSystemTimeZones()[313].Id());
    EXPECT_EQ("(UTC-06:00:00) Canada/East-Saskatchewan", TimeZoneInfo::GetSystemTimeZones()[313].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[313].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[313].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[313].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[313].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesCanada_Eastern) {
    EXPECT_EQ("Canada/Eastern", TimeZoneInfo::GetSystemTimeZones()[314].Id());
    EXPECT_EQ("(UTC-05:00:00) Canada/Eastern", TimeZoneInfo::GetSystemTimeZones()[314].DisplayName());
    EXPECT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[314].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[314].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[314].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[314].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesCanada_Mountain) {
    EXPECT_EQ("Canada/Mountain", TimeZoneInfo::GetSystemTimeZones()[315].Id());
    EXPECT_EQ("(UTC-07:00:00) Canada/Mountain", TimeZoneInfo::GetSystemTimeZones()[315].DisplayName());
    EXPECT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[315].DaylightName());
    EXPECT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[315].BaseUtcOffset().ToString());
    EXPECT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[315].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[315].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesCanada_Newfoundland) {
    EXPECT_EQ("Canada/Newfoundland", TimeZoneInfo::GetSystemTimeZones()[316].Id());
    EXPECT_EQ("(UTC-03:30:00) Canada/Newfoundland", TimeZoneInfo::GetSystemTimeZones()[316].DisplayName());
    EXPECT_EQ("NDT", TimeZoneInfo::GetSystemTimeZones()[316].DaylightName());
    EXPECT_EQ("-03:30:00", TimeZoneInfo::GetSystemTimeZones()[316].BaseUtcOffset().ToString());
    EXPECT_EQ("NST", TimeZoneInfo::GetSystemTimeZones()[316].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[316].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesCanada_Pacific) {
    EXPECT_EQ("Canada/Pacific", TimeZoneInfo::GetSystemTimeZones()[317].Id());
    EXPECT_EQ("(UTC-08:00:00) Canada/Pacific", TimeZoneInfo::GetSystemTimeZones()[317].DisplayName());
    EXPECT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[317].DaylightName());
    EXPECT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[317].BaseUtcOffset().ToString());
    EXPECT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[317].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[317].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesCanada_Saskatchewan) {
    EXPECT_EQ("Canada/Saskatchewan", TimeZoneInfo::GetSystemTimeZones()[318].Id());
    EXPECT_EQ("(UTC-06:00:00) Canada/Saskatchewan", TimeZoneInfo::GetSystemTimeZones()[318].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[318].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[318].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[318].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[318].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesCanada_Yukon) {
    EXPECT_EQ("Canada/Yukon", TimeZoneInfo::GetSystemTimeZones()[319].Id());
    EXPECT_EQ("(UTC-08:00:00) Canada/Yukon", TimeZoneInfo::GetSystemTimeZones()[319].DisplayName());
    EXPECT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[319].DaylightName());
    EXPECT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[319].BaseUtcOffset().ToString());
    EXPECT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[319].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[319].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesChile_Continental) {
    EXPECT_EQ("Chile/Continental", TimeZoneInfo::GetSystemTimeZones()[320].Id());
    EXPECT_EQ("(UTC-04:00:00) Chile/Continental", TimeZoneInfo::GetSystemTimeZones()[320].DisplayName());
    EXPECT_EQ("CLST", TimeZoneInfo::GetSystemTimeZones()[320].DaylightName());
    EXPECT_EQ("-04:00:00", TimeZoneInfo::GetSystemTimeZones()[320].BaseUtcOffset().ToString());
    EXPECT_EQ("CLT", TimeZoneInfo::GetSystemTimeZones()[320].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[320].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesChile_EasterIsland) {
    EXPECT_EQ("Chile/EasterIsland", TimeZoneInfo::GetSystemTimeZones()[321].Id());
    EXPECT_EQ("(UTC-06:00:00) Chile/EasterIsland", TimeZoneInfo::GetSystemTimeZones()[321].DisplayName());
    EXPECT_EQ("EASST", TimeZoneInfo::GetSystemTimeZones()[321].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[321].BaseUtcOffset().ToString());
    EXPECT_EQ("EAST", TimeZoneInfo::GetSystemTimeZones()[321].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[321].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Amsterdam) {
    EXPECT_EQ("Europe/Amsterdam", TimeZoneInfo::GetSystemTimeZones()[322].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Amsterdam", TimeZoneInfo::GetSystemTimeZones()[322].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[322].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[322].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[322].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[322].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Andorra) {
    EXPECT_EQ("Europe/Andorra", TimeZoneInfo::GetSystemTimeZones()[323].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Andorra", TimeZoneInfo::GetSystemTimeZones()[323].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[323].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[323].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[323].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[323].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Athens) {
    EXPECT_EQ("Europe/Athens", TimeZoneInfo::GetSystemTimeZones()[324].Id());
    EXPECT_EQ("(UTC+02:00:00) Europe/Athens", TimeZoneInfo::GetSystemTimeZones()[324].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[324].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[324].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[324].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[324].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Belfast) {
    EXPECT_EQ("Europe/Belfast", TimeZoneInfo::GetSystemTimeZones()[325].Id());
    EXPECT_EQ("(UTC) Europe/Belfast", TimeZoneInfo::GetSystemTimeZones()[325].DisplayName());
    EXPECT_EQ("BST", TimeZoneInfo::GetSystemTimeZones()[325].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[325].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[325].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[325].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Belgrade) {
    EXPECT_EQ("Europe/Belgrade", TimeZoneInfo::GetSystemTimeZones()[326].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Belgrade", TimeZoneInfo::GetSystemTimeZones()[326].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[326].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[326].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[326].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[326].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Berlin) {
    EXPECT_EQ("Europe/Berlin", TimeZoneInfo::GetSystemTimeZones()[327].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Berlin", TimeZoneInfo::GetSystemTimeZones()[327].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[327].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[327].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[327].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[327].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Bratislava) {
    EXPECT_EQ("Europe/Bratislava", TimeZoneInfo::GetSystemTimeZones()[328].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Bratislava", TimeZoneInfo::GetSystemTimeZones()[328].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[328].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[328].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[328].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[328].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Brussels) {
    EXPECT_EQ("Europe/Brussels", TimeZoneInfo::GetSystemTimeZones()[329].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Brussels", TimeZoneInfo::GetSystemTimeZones()[329].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[329].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[329].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[329].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[329].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Bchar32est) {
    EXPECT_EQ("Europe/Bchar32est", TimeZoneInfo::GetSystemTimeZones()[330].Id());
    EXPECT_EQ("(UTC+02:00:00) Europe/Bchar32est", TimeZoneInfo::GetSystemTimeZones()[330].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[330].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[330].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[330].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[330].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Budapest) {
    EXPECT_EQ("Europe/Budapest", TimeZoneInfo::GetSystemTimeZones()[331].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Budapest", TimeZoneInfo::GetSystemTimeZones()[331].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[331].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[331].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[331].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[331].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Busingen) {
    EXPECT_EQ("Europe/Busingen", TimeZoneInfo::GetSystemTimeZones()[332].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Busingen", TimeZoneInfo::GetSystemTimeZones()[332].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[332].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[332].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[332].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[332].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Chisinau) {
    EXPECT_EQ("Europe/Chisinau", TimeZoneInfo::GetSystemTimeZones()[333].Id());
    EXPECT_EQ("(UTC+02:00:00) Europe/Chisinau", TimeZoneInfo::GetSystemTimeZones()[333].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[333].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[333].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[333].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[333].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Copenhagen) {
    EXPECT_EQ("Europe/Copenhagen", TimeZoneInfo::GetSystemTimeZones()[334].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Copenhagen", TimeZoneInfo::GetSystemTimeZones()[334].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[334].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[334].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[334].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[334].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Dublin) {
    EXPECT_EQ("Europe/Dublin", TimeZoneInfo::GetSystemTimeZones()[335].Id());
    EXPECT_EQ("(UTC) Europe/Dublin", TimeZoneInfo::GetSystemTimeZones()[335].DisplayName());
    EXPECT_EQ("IST", TimeZoneInfo::GetSystemTimeZones()[335].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[335].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[335].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[335].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Gibraltar) {
    EXPECT_EQ("Europe/Gibraltar", TimeZoneInfo::GetSystemTimeZones()[336].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Gibraltar", TimeZoneInfo::GetSystemTimeZones()[336].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[336].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[336].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[336].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[336].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Guernsey) {
    EXPECT_EQ("Europe/Guernsey", TimeZoneInfo::GetSystemTimeZones()[337].Id());
    EXPECT_EQ("(UTC) Europe/Guernsey", TimeZoneInfo::GetSystemTimeZones()[337].DisplayName());
    EXPECT_EQ("BST", TimeZoneInfo::GetSystemTimeZones()[337].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[337].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[337].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[337].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Helsinki) {
    EXPECT_EQ("Europe/Helsinki", TimeZoneInfo::GetSystemTimeZones()[338].Id());
    EXPECT_EQ("(UTC+02:00:00) Europe/Helsinki", TimeZoneInfo::GetSystemTimeZones()[338].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[338].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[338].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[338].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[338].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Isle_of_Man) {
    EXPECT_EQ("Europe/Isle_of_Man", TimeZoneInfo::GetSystemTimeZones()[339].Id());
    EXPECT_EQ("(UTC) Europe/Isle_of_Man", TimeZoneInfo::GetSystemTimeZones()[339].DisplayName());
    EXPECT_EQ("BST", TimeZoneInfo::GetSystemTimeZones()[339].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[339].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[339].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[339].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Istanbul) {
    EXPECT_EQ("Europe/Istanbul", TimeZoneInfo::GetSystemTimeZones()[340].Id());
    EXPECT_EQ("(UTC+02:00:00) Europe/Istanbul", TimeZoneInfo::GetSystemTimeZones()[340].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[340].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[340].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[340].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[340].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Jersey) {
    EXPECT_EQ("Europe/Jersey", TimeZoneInfo::GetSystemTimeZones()[341].Id());
    EXPECT_EQ("(UTC) Europe/Jersey", TimeZoneInfo::GetSystemTimeZones()[341].DisplayName());
    EXPECT_EQ("BST", TimeZoneInfo::GetSystemTimeZones()[341].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[341].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[341].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[341].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Kaliningrad) {
    EXPECT_EQ("Europe/Kaliningrad", TimeZoneInfo::GetSystemTimeZones()[342].Id());
    EXPECT_EQ("(UTC+03:00:00) Europe/Kaliningrad", TimeZoneInfo::GetSystemTimeZones()[342].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[342].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[342].BaseUtcOffset().ToString());
    EXPECT_EQ("FET", TimeZoneInfo::GetSystemTimeZones()[342].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[342].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Kiev) {
    EXPECT_EQ("Europe/Kiev", TimeZoneInfo::GetSystemTimeZones()[343].Id());
    EXPECT_EQ("(UTC+02:00:00) Europe/Kiev", TimeZoneInfo::GetSystemTimeZones()[343].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[343].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[343].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[343].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[343].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Lisbon) {
    EXPECT_EQ("Europe/Lisbon", TimeZoneInfo::GetSystemTimeZones()[344].Id());
    EXPECT_EQ("(UTC) Europe/Lisbon", TimeZoneInfo::GetSystemTimeZones()[344].DisplayName());
    EXPECT_EQ("WEST", TimeZoneInfo::GetSystemTimeZones()[344].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[344].BaseUtcOffset().ToString());
    EXPECT_EQ("WET", TimeZoneInfo::GetSystemTimeZones()[344].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[344].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Ljubljana) {
    EXPECT_EQ("Europe/Ljubljana", TimeZoneInfo::GetSystemTimeZones()[345].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Ljubljana", TimeZoneInfo::GetSystemTimeZones()[345].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[345].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[345].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[345].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[345].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_London) {
    EXPECT_EQ("Europe/London", TimeZoneInfo::GetSystemTimeZones()[346].Id());
    EXPECT_EQ("(UTC) Europe/London", TimeZoneInfo::GetSystemTimeZones()[346].DisplayName());
    EXPECT_EQ("BST", TimeZoneInfo::GetSystemTimeZones()[346].DaylightName());
    EXPECT_EQ("00:00:00", TimeZoneInfo::GetSystemTimeZones()[346].BaseUtcOffset().ToString());
    EXPECT_EQ("GMT", TimeZoneInfo::GetSystemTimeZones()[346].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[346].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Luxembourg) {
    EXPECT_EQ("Europe/Luxembourg", TimeZoneInfo::GetSystemTimeZones()[347].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Luxembourg", TimeZoneInfo::GetSystemTimeZones()[347].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[347].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[347].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[347].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[347].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Madrid) {
    EXPECT_EQ("Europe/Madrid", TimeZoneInfo::GetSystemTimeZones()[348].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Madrid", TimeZoneInfo::GetSystemTimeZones()[348].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[348].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[348].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[348].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[348].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Malta) {
    EXPECT_EQ("Europe/Malta", TimeZoneInfo::GetSystemTimeZones()[349].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Malta", TimeZoneInfo::GetSystemTimeZones()[349].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[349].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[349].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[349].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[349].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Mariehamn) {
    EXPECT_EQ("Europe/Mariehamn", TimeZoneInfo::GetSystemTimeZones()[350].Id());
    EXPECT_EQ("(UTC+02:00:00) Europe/Mariehamn", TimeZoneInfo::GetSystemTimeZones()[350].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[350].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[350].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[350].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[350].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Minsk) {
    EXPECT_EQ("Europe/Minsk", TimeZoneInfo::GetSystemTimeZones()[351].Id());
    EXPECT_EQ("(UTC+03:00:00) Europe/Minsk", TimeZoneInfo::GetSystemTimeZones()[351].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[351].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[351].BaseUtcOffset().ToString());
    EXPECT_EQ("FET", TimeZoneInfo::GetSystemTimeZones()[351].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[351].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Monaco) {
    EXPECT_EQ("Europe/Monaco", TimeZoneInfo::GetSystemTimeZones()[352].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Monaco", TimeZoneInfo::GetSystemTimeZones()[352].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[352].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[352].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[352].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[352].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Moscow) {
    EXPECT_EQ("Europe/Moscow", TimeZoneInfo::GetSystemTimeZones()[353].Id());
    EXPECT_EQ("(UTC+04:00:00) Europe/Moscow", TimeZoneInfo::GetSystemTimeZones()[353].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[353].DaylightName());
    EXPECT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[353].BaseUtcOffset().ToString());
    EXPECT_EQ("MSK", TimeZoneInfo::GetSystemTimeZones()[353].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[353].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Nicosia) {
    EXPECT_EQ("Europe/Nicosia", TimeZoneInfo::GetSystemTimeZones()[354].Id());
    EXPECT_EQ("(UTC+02:00:00) Europe/Nicosia", TimeZoneInfo::GetSystemTimeZones()[354].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[354].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[354].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[354].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[354].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Oslo) {
    EXPECT_EQ("Europe/Oslo", TimeZoneInfo::GetSystemTimeZones()[355].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Oslo", TimeZoneInfo::GetSystemTimeZones()[355].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[355].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[355].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[355].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[355].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Paris) {
    EXPECT_EQ("Europe/Paris", TimeZoneInfo::GetSystemTimeZones()[356].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Paris", TimeZoneInfo::GetSystemTimeZones()[356].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[356].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[356].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[356].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[356].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Podgorica) {
    EXPECT_EQ("Europe/Podgorica", TimeZoneInfo::GetSystemTimeZones()[357].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Podgorica", TimeZoneInfo::GetSystemTimeZones()[357].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[357].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[357].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[357].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[357].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Prague) {
    EXPECT_EQ("Europe/Prague", TimeZoneInfo::GetSystemTimeZones()[358].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Prague", TimeZoneInfo::GetSystemTimeZones()[358].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[358].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[358].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[358].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[358].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Riga) {
    EXPECT_EQ("Europe/Riga", TimeZoneInfo::GetSystemTimeZones()[359].Id());
    EXPECT_EQ("(UTC+02:00:00) Europe/Riga", TimeZoneInfo::GetSystemTimeZones()[359].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[359].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[359].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[359].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[359].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Rome) {
    EXPECT_EQ("Europe/Rome", TimeZoneInfo::GetSystemTimeZones()[360].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Rome", TimeZoneInfo::GetSystemTimeZones()[360].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[360].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[360].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[360].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[360].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Samara) {
    EXPECT_EQ("Europe/Samara", TimeZoneInfo::GetSystemTimeZones()[361].Id());
    EXPECT_EQ("(UTC+04:00:00) Europe/Samara", TimeZoneInfo::GetSystemTimeZones()[361].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[361].DaylightName());
    EXPECT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[361].BaseUtcOffset().ToString());
    EXPECT_EQ("SAMT", TimeZoneInfo::GetSystemTimeZones()[361].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[361].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_San_Marino) {
    EXPECT_EQ("Europe/San_Marino", TimeZoneInfo::GetSystemTimeZones()[362].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/San_Marino", TimeZoneInfo::GetSystemTimeZones()[362].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[362].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[362].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[362].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[362].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Sarajevo) {
    EXPECT_EQ("Europe/Sarajevo", TimeZoneInfo::GetSystemTimeZones()[363].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Sarajevo", TimeZoneInfo::GetSystemTimeZones()[363].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[363].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[363].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[363].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[363].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Simferopol) {
    EXPECT_EQ("Europe/Simferopol", TimeZoneInfo::GetSystemTimeZones()[364].Id());
    EXPECT_EQ("(UTC+02:00:00) Europe/Simferopol", TimeZoneInfo::GetSystemTimeZones()[364].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[364].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[364].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[364].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[364].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Skopje) {
    EXPECT_EQ("Europe/Skopje", TimeZoneInfo::GetSystemTimeZones()[365].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Skopje", TimeZoneInfo::GetSystemTimeZones()[365].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[365].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[365].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[365].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[365].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Sofia) {
    EXPECT_EQ("Europe/Sofia", TimeZoneInfo::GetSystemTimeZones()[366].Id());
    EXPECT_EQ("(UTC+02:00:00) Europe/Sofia", TimeZoneInfo::GetSystemTimeZones()[366].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[366].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[366].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[366].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[366].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Stockholm) {
    EXPECT_EQ("Europe/Stockholm", TimeZoneInfo::GetSystemTimeZones()[367].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Stockholm", TimeZoneInfo::GetSystemTimeZones()[367].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[367].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[367].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[367].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[367].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Tallinn) {
    EXPECT_EQ("Europe/Tallinn", TimeZoneInfo::GetSystemTimeZones()[368].Id());
    EXPECT_EQ("(UTC+02:00:00) Europe/Tallinn", TimeZoneInfo::GetSystemTimeZones()[368].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[368].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[368].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[368].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[368].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Tirane) {
    EXPECT_EQ("Europe/Tirane", TimeZoneInfo::GetSystemTimeZones()[369].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Tirane", TimeZoneInfo::GetSystemTimeZones()[369].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[369].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[369].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[369].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[369].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Tiraspol) {
    EXPECT_EQ("Europe/Tiraspol", TimeZoneInfo::GetSystemTimeZones()[370].Id());
    EXPECT_EQ("(UTC+02:00:00) Europe/Tiraspol", TimeZoneInfo::GetSystemTimeZones()[370].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[370].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[370].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[370].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[370].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Uzhgorod) {
    EXPECT_EQ("Europe/Uzhgorod", TimeZoneInfo::GetSystemTimeZones()[371].Id());
    EXPECT_EQ("(UTC+02:00:00) Europe/Uzhgorod", TimeZoneInfo::GetSystemTimeZones()[371].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[371].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[371].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[371].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[371].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Vaduz) {
    EXPECT_EQ("Europe/Vaduz", TimeZoneInfo::GetSystemTimeZones()[372].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Vaduz", TimeZoneInfo::GetSystemTimeZones()[372].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[372].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[372].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[372].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[372].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Vatican) {
    EXPECT_EQ("Europe/Vatican", TimeZoneInfo::GetSystemTimeZones()[373].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Vatican", TimeZoneInfo::GetSystemTimeZones()[373].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[373].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[373].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[373].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[373].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Vienna) {
    EXPECT_EQ("Europe/Vienna", TimeZoneInfo::GetSystemTimeZones()[374].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Vienna", TimeZoneInfo::GetSystemTimeZones()[374].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[374].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[374].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[374].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[374].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Vilnius) {
    EXPECT_EQ("Europe/Vilnius", TimeZoneInfo::GetSystemTimeZones()[375].Id());
    EXPECT_EQ("(UTC+02:00:00) Europe/Vilnius", TimeZoneInfo::GetSystemTimeZones()[375].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[375].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[375].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[375].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[375].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Volgograd) {
    EXPECT_EQ("Europe/Volgograd", TimeZoneInfo::GetSystemTimeZones()[376].Id());
    EXPECT_EQ("(UTC+04:00:00) Europe/Volgograd", TimeZoneInfo::GetSystemTimeZones()[376].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[376].DaylightName());
    EXPECT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[376].BaseUtcOffset().ToString());
    EXPECT_EQ("VOLT", TimeZoneInfo::GetSystemTimeZones()[376].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[376].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Warsaw) {
    EXPECT_EQ("Europe/Warsaw", TimeZoneInfo::GetSystemTimeZones()[377].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Warsaw", TimeZoneInfo::GetSystemTimeZones()[377].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[377].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[377].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[377].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[377].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Zagreb) {
    EXPECT_EQ("Europe/Zagreb", TimeZoneInfo::GetSystemTimeZones()[378].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Zagreb", TimeZoneInfo::GetSystemTimeZones()[378].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[378].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[378].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[378].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[378].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Zaporozhye) {
    EXPECT_EQ("Europe/Zaporozhye", TimeZoneInfo::GetSystemTimeZones()[379].Id());
    EXPECT_EQ("(UTC+02:00:00) Europe/Zaporozhye", TimeZoneInfo::GetSystemTimeZones()[379].DisplayName());
    EXPECT_EQ("EEST", TimeZoneInfo::GetSystemTimeZones()[379].DaylightName());
    EXPECT_EQ("02:00:00", TimeZoneInfo::GetSystemTimeZones()[379].BaseUtcOffset().ToString());
    EXPECT_EQ("EET", TimeZoneInfo::GetSystemTimeZones()[379].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[379].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesEurope_Zurich) {
    EXPECT_EQ("Europe/Zurich", TimeZoneInfo::GetSystemTimeZones()[380].Id());
    EXPECT_EQ("(UTC+01:00:00) Europe/Zurich", TimeZoneInfo::GetSystemTimeZones()[380].DisplayName());
    EXPECT_EQ("CEST", TimeZoneInfo::GetSystemTimeZones()[380].DaylightName());
    EXPECT_EQ("01:00:00", TimeZoneInfo::GetSystemTimeZones()[380].BaseUtcOffset().ToString());
    EXPECT_EQ("CET", TimeZoneInfo::GetSystemTimeZones()[380].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[380].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesIndian_Antananarivo) {
    EXPECT_EQ("Indian/Antananarivo", TimeZoneInfo::GetSystemTimeZones()[381].Id());
    EXPECT_EQ("(UTC+03:00:00) Indian/Antananarivo", TimeZoneInfo::GetSystemTimeZones()[381].DisplayName());
    EXPECT_EQ("EAST", TimeZoneInfo::GetSystemTimeZones()[381].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[381].BaseUtcOffset().ToString());
    EXPECT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[381].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[381].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesIndian_Chagos) {
    EXPECT_EQ("Indian/Chagos", TimeZoneInfo::GetSystemTimeZones()[382].Id());
    EXPECT_EQ("(UTC+06:00:00) Indian/Chagos", TimeZoneInfo::GetSystemTimeZones()[382].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[382].DaylightName());
    EXPECT_EQ("06:00:00", TimeZoneInfo::GetSystemTimeZones()[382].BaseUtcOffset().ToString());
    EXPECT_EQ("IOT", TimeZoneInfo::GetSystemTimeZones()[382].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[382].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesIndian_Christmas) {
    EXPECT_EQ("Indian/Christmas", TimeZoneInfo::GetSystemTimeZones()[383].Id());
    EXPECT_EQ("(UTC+07:00:00) Indian/Christmas", TimeZoneInfo::GetSystemTimeZones()[383].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[383].DaylightName());
    EXPECT_EQ("07:00:00", TimeZoneInfo::GetSystemTimeZones()[383].BaseUtcOffset().ToString());
    EXPECT_EQ("CXT", TimeZoneInfo::GetSystemTimeZones()[383].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[383].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesIndian_Cocos) {
    EXPECT_EQ("Indian/Cocos", TimeZoneInfo::GetSystemTimeZones()[384].Id());
    EXPECT_EQ("(UTC+06:30:00) Indian/Cocos", TimeZoneInfo::GetSystemTimeZones()[384].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[384].DaylightName());
    EXPECT_EQ("06:30:00", TimeZoneInfo::GetSystemTimeZones()[384].BaseUtcOffset().ToString());
    EXPECT_EQ("CCT", TimeZoneInfo::GetSystemTimeZones()[384].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[384].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesIndian_Comoro) {
    EXPECT_EQ("Indian/Comoro", TimeZoneInfo::GetSystemTimeZones()[385].Id());
    EXPECT_EQ("(UTC+03:00:00) Indian/Comoro", TimeZoneInfo::GetSystemTimeZones()[385].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[385].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[385].BaseUtcOffset().ToString());
    EXPECT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[385].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[385].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesIndian_Kerguelen) {
    EXPECT_EQ("Indian/Kerguelen", TimeZoneInfo::GetSystemTimeZones()[386].Id());
    EXPECT_EQ("(UTC+05:00:00) Indian/Kerguelen", TimeZoneInfo::GetSystemTimeZones()[386].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[386].DaylightName());
    EXPECT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[386].BaseUtcOffset().ToString());
    EXPECT_EQ("TFT", TimeZoneInfo::GetSystemTimeZones()[386].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[386].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesIndian_Mahe) {
    EXPECT_EQ("Indian/Mahe", TimeZoneInfo::GetSystemTimeZones()[387].Id());
    EXPECT_EQ("(UTC+04:00:00) Indian/Mahe", TimeZoneInfo::GetSystemTimeZones()[387].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[387].DaylightName());
    EXPECT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[387].BaseUtcOffset().ToString());
    EXPECT_EQ("SCT", TimeZoneInfo::GetSystemTimeZones()[387].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[387].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesIndian_Maldives) {
    EXPECT_EQ("Indian/Maldives", TimeZoneInfo::GetSystemTimeZones()[388].Id());
    EXPECT_EQ("(UTC+05:00:00) Indian/Maldives", TimeZoneInfo::GetSystemTimeZones()[388].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[388].DaylightName());
    EXPECT_EQ("05:00:00", TimeZoneInfo::GetSystemTimeZones()[388].BaseUtcOffset().ToString());
    EXPECT_EQ("MVT", TimeZoneInfo::GetSystemTimeZones()[388].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[388].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesIndian_Mauritius) {
    EXPECT_EQ("Indian/Mauritius", TimeZoneInfo::GetSystemTimeZones()[389].Id());
    EXPECT_EQ("(UTC+04:00:00) Indian/Mauritius", TimeZoneInfo::GetSystemTimeZones()[389].DisplayName());
    EXPECT_EQ("MUST", TimeZoneInfo::GetSystemTimeZones()[389].DaylightName());
    EXPECT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[389].BaseUtcOffset().ToString());
    EXPECT_EQ("MUT", TimeZoneInfo::GetSystemTimeZones()[389].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[389].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesIndian_Mayotte) {
    EXPECT_EQ("Indian/Mayotte", TimeZoneInfo::GetSystemTimeZones()[390].Id());
    EXPECT_EQ("(UTC+03:00:00) Indian/Mayotte", TimeZoneInfo::GetSystemTimeZones()[390].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[390].DaylightName());
    EXPECT_EQ("03:00:00", TimeZoneInfo::GetSystemTimeZones()[390].BaseUtcOffset().ToString());
    EXPECT_EQ("EAT", TimeZoneInfo::GetSystemTimeZones()[390].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[390].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesIndian_Reunion) {
    EXPECT_EQ("Indian/Reunion", TimeZoneInfo::GetSystemTimeZones()[391].Id());
    EXPECT_EQ("(UTC+04:00:00) Indian/Reunion", TimeZoneInfo::GetSystemTimeZones()[391].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[391].DaylightName());
    EXPECT_EQ("04:00:00", TimeZoneInfo::GetSystemTimeZones()[391].BaseUtcOffset().ToString());
    EXPECT_EQ("RET", TimeZoneInfo::GetSystemTimeZones()[391].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[391].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesMexico_BajaNorte) {
    EXPECT_EQ("Mexico/BajaNorte", TimeZoneInfo::GetSystemTimeZones()[392].Id());
    EXPECT_EQ("(UTC-08:00:00) Mexico/BajaNorte", TimeZoneInfo::GetSystemTimeZones()[392].DisplayName());
    EXPECT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[392].DaylightName());
    EXPECT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[392].BaseUtcOffset().ToString());
    EXPECT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[392].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[392].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesMexico_BajaSur) {
    EXPECT_EQ("Mexico/BajaSur", TimeZoneInfo::GetSystemTimeZones()[393].Id());
    EXPECT_EQ("(UTC-07:00:00) Mexico/BajaSur", TimeZoneInfo::GetSystemTimeZones()[393].DisplayName());
    EXPECT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[393].DaylightName());
    EXPECT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[393].BaseUtcOffset().ToString());
    EXPECT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[393].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[393].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesMexico_General) {
    EXPECT_EQ("Mexico/General", TimeZoneInfo::GetSystemTimeZones()[394].Id());
    EXPECT_EQ("(UTC-06:00:00) Mexico/General", TimeZoneInfo::GetSystemTimeZones()[394].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[394].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[394].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[394].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[394].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Apia) {
    EXPECT_EQ("Pacific/Apia", TimeZoneInfo::GetSystemTimeZones()[395].Id());
    EXPECT_EQ("(UTC+13:00:00) Pacific/Apia", TimeZoneInfo::GetSystemTimeZones()[395].DisplayName());
    EXPECT_EQ("WSDT", TimeZoneInfo::GetSystemTimeZones()[395].DaylightName());
    EXPECT_EQ("13:00:00", TimeZoneInfo::GetSystemTimeZones()[395].BaseUtcOffset().ToString());
    EXPECT_EQ("WST", TimeZoneInfo::GetSystemTimeZones()[395].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[395].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Auckland) {
    EXPECT_EQ("Pacific/Auckland", TimeZoneInfo::GetSystemTimeZones()[396].Id());
    EXPECT_EQ("(UTC+12:00:00) Pacific/Auckland", TimeZoneInfo::GetSystemTimeZones()[396].DisplayName());
    EXPECT_EQ("NZDT", TimeZoneInfo::GetSystemTimeZones()[396].DaylightName());
    EXPECT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[396].BaseUtcOffset().ToString());
    EXPECT_EQ("NZST", TimeZoneInfo::GetSystemTimeZones()[396].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[396].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Chatham) {
    EXPECT_EQ("Pacific/Chatham", TimeZoneInfo::GetSystemTimeZones()[397].Id());
    EXPECT_EQ("(UTC+12:45:00) Pacific/Chatham", TimeZoneInfo::GetSystemTimeZones()[397].DisplayName());
    EXPECT_EQ("CHADT", TimeZoneInfo::GetSystemTimeZones()[397].DaylightName());
    EXPECT_EQ("12:45:00", TimeZoneInfo::GetSystemTimeZones()[397].BaseUtcOffset().ToString());
    EXPECT_EQ("CHAST", TimeZoneInfo::GetSystemTimeZones()[397].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[397].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Chuuk) {
    EXPECT_EQ("Pacific/Chuuk", TimeZoneInfo::GetSystemTimeZones()[398].Id());
    EXPECT_EQ("(UTC+10:00:00) Pacific/Chuuk", TimeZoneInfo::GetSystemTimeZones()[398].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[398].DaylightName());
    EXPECT_EQ("10:00:00", TimeZoneInfo::GetSystemTimeZones()[398].BaseUtcOffset().ToString());
    EXPECT_EQ("CHUT", TimeZoneInfo::GetSystemTimeZones()[398].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[398].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Easter) {
    EXPECT_EQ("Pacific/Easter", TimeZoneInfo::GetSystemTimeZones()[399].Id());
    EXPECT_EQ("(UTC-06:00:00) Pacific/Easter", TimeZoneInfo::GetSystemTimeZones()[399].DisplayName());
    EXPECT_EQ("EASST", TimeZoneInfo::GetSystemTimeZones()[399].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[399].BaseUtcOffset().ToString());
    EXPECT_EQ("EAST", TimeZoneInfo::GetSystemTimeZones()[399].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[399].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Efate) {
    EXPECT_EQ("Pacific/Efate", TimeZoneInfo::GetSystemTimeZones()[400].Id());
    EXPECT_EQ("(UTC+11:00:00) Pacific/Efate", TimeZoneInfo::GetSystemTimeZones()[400].DisplayName());
    EXPECT_EQ("VUST", TimeZoneInfo::GetSystemTimeZones()[400].DaylightName());
    EXPECT_EQ("11:00:00", TimeZoneInfo::GetSystemTimeZones()[400].BaseUtcOffset().ToString());
    EXPECT_EQ("VUT", TimeZoneInfo::GetSystemTimeZones()[400].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[400].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Enderbury) {
    EXPECT_EQ("Pacific/Enderbury", TimeZoneInfo::GetSystemTimeZones()[401].Id());
    EXPECT_EQ("(UTC+13:00:00) Pacific/Enderbury", TimeZoneInfo::GetSystemTimeZones()[401].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[401].DaylightName());
    EXPECT_EQ("13:00:00", TimeZoneInfo::GetSystemTimeZones()[401].BaseUtcOffset().ToString());
    EXPECT_EQ("PHOT", TimeZoneInfo::GetSystemTimeZones()[401].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[401].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Fakaofo) {
    EXPECT_EQ("Pacific/Fakaofo", TimeZoneInfo::GetSystemTimeZones()[402].Id());
    EXPECT_EQ("(UTC+13:00:00) Pacific/Fakaofo", TimeZoneInfo::GetSystemTimeZones()[402].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[402].DaylightName());
    EXPECT_EQ("13:00:00", TimeZoneInfo::GetSystemTimeZones()[402].BaseUtcOffset().ToString());
    EXPECT_EQ("TKT", TimeZoneInfo::GetSystemTimeZones()[402].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[402].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Fiji) {
    EXPECT_EQ("Pacific/Fiji", TimeZoneInfo::GetSystemTimeZones()[403].Id());
    EXPECT_EQ("(UTC+12:00:00) Pacific/Fiji", TimeZoneInfo::GetSystemTimeZones()[403].DisplayName());
    EXPECT_EQ("FJST", TimeZoneInfo::GetSystemTimeZones()[403].DaylightName());
    EXPECT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[403].BaseUtcOffset().ToString());
    EXPECT_EQ("FJT", TimeZoneInfo::GetSystemTimeZones()[403].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[403].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Funafuti) {
    EXPECT_EQ("Pacific/Funafuti", TimeZoneInfo::GetSystemTimeZones()[404].Id());
    EXPECT_EQ("(UTC+12:00:00) Pacific/Funafuti", TimeZoneInfo::GetSystemTimeZones()[404].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[404].DaylightName());
    EXPECT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[404].BaseUtcOffset().ToString());
    EXPECT_EQ("TVT", TimeZoneInfo::GetSystemTimeZones()[404].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[404].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Galapagos) {
    EXPECT_EQ("Pacific/Galapagos", TimeZoneInfo::GetSystemTimeZones()[405].Id());
    EXPECT_EQ("(UTC-06:00:00) Pacific/Galapagos", TimeZoneInfo::GetSystemTimeZones()[405].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[405].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[405].BaseUtcOffset().ToString());
    EXPECT_EQ("GALT", TimeZoneInfo::GetSystemTimeZones()[405].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[405].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Gambier) {
    EXPECT_EQ("Pacific/Gambier", TimeZoneInfo::GetSystemTimeZones()[406].Id());
    EXPECT_EQ("(UTC-09:00:00) Pacific/Gambier", TimeZoneInfo::GetSystemTimeZones()[406].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[406].DaylightName());
    EXPECT_EQ("-09:00:00", TimeZoneInfo::GetSystemTimeZones()[406].BaseUtcOffset().ToString());
    EXPECT_EQ("GAMT", TimeZoneInfo::GetSystemTimeZones()[406].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[406].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Guadalcanal) {
    EXPECT_EQ("Pacific/Guadalcanal", TimeZoneInfo::GetSystemTimeZones()[407].Id());
    EXPECT_EQ("(UTC+11:00:00) Pacific/Guadalcanal", TimeZoneInfo::GetSystemTimeZones()[407].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[407].DaylightName());
    EXPECT_EQ("11:00:00", TimeZoneInfo::GetSystemTimeZones()[407].BaseUtcOffset().ToString());
    EXPECT_EQ("SBT", TimeZoneInfo::GetSystemTimeZones()[407].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[407].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Guam) {
    EXPECT_EQ("Pacific/Guam", TimeZoneInfo::GetSystemTimeZones()[408].Id());
    EXPECT_EQ("(UTC+10:00:00) Pacific/Guam", TimeZoneInfo::GetSystemTimeZones()[408].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[408].DaylightName());
    EXPECT_EQ("10:00:00", TimeZoneInfo::GetSystemTimeZones()[408].BaseUtcOffset().ToString());
    EXPECT_EQ("ChST", TimeZoneInfo::GetSystemTimeZones()[408].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[408].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Honolulu) {
    EXPECT_EQ("Pacific/Honolulu", TimeZoneInfo::GetSystemTimeZones()[409].Id());
    EXPECT_EQ("(UTC-10:00:00) Pacific/Honolulu", TimeZoneInfo::GetSystemTimeZones()[409].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[409].DaylightName());
    EXPECT_EQ("-10:00:00", TimeZoneInfo::GetSystemTimeZones()[409].BaseUtcOffset().ToString());
    EXPECT_EQ("HST", TimeZoneInfo::GetSystemTimeZones()[409].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[409].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Johnston) {
    EXPECT_EQ("Pacific/Johnston", TimeZoneInfo::GetSystemTimeZones()[410].Id());
    EXPECT_EQ("(UTC-10:00:00) Pacific/Johnston", TimeZoneInfo::GetSystemTimeZones()[410].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[410].DaylightName());
    EXPECT_EQ("-10:00:00", TimeZoneInfo::GetSystemTimeZones()[410].BaseUtcOffset().ToString());
    EXPECT_EQ("HST", TimeZoneInfo::GetSystemTimeZones()[410].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[410].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Kiritimati) {
    EXPECT_EQ("Pacific/Kiritimati", TimeZoneInfo::GetSystemTimeZones()[411].Id());
    EXPECT_EQ("(UTC+14:00:00) Pacific/Kiritimati", TimeZoneInfo::GetSystemTimeZones()[411].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[411].DaylightName());
    EXPECT_EQ("14:00:00", TimeZoneInfo::GetSystemTimeZones()[411].BaseUtcOffset().ToString());
    EXPECT_EQ("LINT", TimeZoneInfo::GetSystemTimeZones()[411].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[411].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Kosrae) {
    EXPECT_EQ("Pacific/Kosrae", TimeZoneInfo::GetSystemTimeZones()[412].Id());
    EXPECT_EQ("(UTC+11:00:00) Pacific/Kosrae", TimeZoneInfo::GetSystemTimeZones()[412].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[412].DaylightName());
    EXPECT_EQ("11:00:00", TimeZoneInfo::GetSystemTimeZones()[412].BaseUtcOffset().ToString());
    EXPECT_EQ("KOST", TimeZoneInfo::GetSystemTimeZones()[412].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[412].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Kwajalein) {
    EXPECT_EQ("Pacific/Kwajalein", TimeZoneInfo::GetSystemTimeZones()[413].Id());
    EXPECT_EQ("(UTC+12:00:00) Pacific/Kwajalein", TimeZoneInfo::GetSystemTimeZones()[413].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[413].DaylightName());
    EXPECT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[413].BaseUtcOffset().ToString());
    EXPECT_EQ("MHT", TimeZoneInfo::GetSystemTimeZones()[413].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[413].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Majuro) {
    EXPECT_EQ("Pacific/Majuro", TimeZoneInfo::GetSystemTimeZones()[414].Id());
    EXPECT_EQ("(UTC+12:00:00) Pacific/Majuro", TimeZoneInfo::GetSystemTimeZones()[414].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[414].DaylightName());
    EXPECT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[414].BaseUtcOffset().ToString());
    EXPECT_EQ("MHT", TimeZoneInfo::GetSystemTimeZones()[414].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[414].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Marquesas) {
    EXPECT_EQ("Pacific/Marquesas", TimeZoneInfo::GetSystemTimeZones()[415].Id());
    EXPECT_EQ("(UTC-09:30:00) Pacific/Marquesas", TimeZoneInfo::GetSystemTimeZones()[415].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[415].DaylightName());
    EXPECT_EQ("-09:30:00", TimeZoneInfo::GetSystemTimeZones()[415].BaseUtcOffset().ToString());
    EXPECT_EQ("MART", TimeZoneInfo::GetSystemTimeZones()[415].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[415].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Midway) {
    EXPECT_EQ("Pacific/Midway", TimeZoneInfo::GetSystemTimeZones()[416].Id());
    EXPECT_EQ("(UTC-11:00:00) Pacific/Midway", TimeZoneInfo::GetSystemTimeZones()[416].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[416].DaylightName());
    EXPECT_EQ("-11:00:00", TimeZoneInfo::GetSystemTimeZones()[416].BaseUtcOffset().ToString());
    EXPECT_EQ("SST", TimeZoneInfo::GetSystemTimeZones()[416].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[416].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Nauru) {
    EXPECT_EQ("Pacific/Nauru", TimeZoneInfo::GetSystemTimeZones()[417].Id());
    EXPECT_EQ("(UTC+12:00:00) Pacific/Nauru", TimeZoneInfo::GetSystemTimeZones()[417].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[417].DaylightName());
    EXPECT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[417].BaseUtcOffset().ToString());
    EXPECT_EQ("NRT", TimeZoneInfo::GetSystemTimeZones()[417].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[417].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Niue) {
    EXPECT_EQ("Pacific/Niue", TimeZoneInfo::GetSystemTimeZones()[418].Id());
    EXPECT_EQ("(UTC-11:00:00) Pacific/Niue", TimeZoneInfo::GetSystemTimeZones()[418].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[418].DaylightName());
    EXPECT_EQ("-11:00:00", TimeZoneInfo::GetSystemTimeZones()[418].BaseUtcOffset().ToString());
    EXPECT_EQ("NUT", TimeZoneInfo::GetSystemTimeZones()[418].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[418].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Norfolk) {
    EXPECT_EQ("Pacific/Norfolk", TimeZoneInfo::GetSystemTimeZones()[419].Id());
    EXPECT_EQ("(UTC+11:30:00) Pacific/Norfolk", TimeZoneInfo::GetSystemTimeZones()[419].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[419].DaylightName());
    EXPECT_EQ("11:30:00", TimeZoneInfo::GetSystemTimeZones()[419].BaseUtcOffset().ToString());
    EXPECT_EQ("NFT", TimeZoneInfo::GetSystemTimeZones()[419].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[419].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Noumea) {
    EXPECT_EQ("Pacific/Noumea", TimeZoneInfo::GetSystemTimeZones()[420].Id());
    EXPECT_EQ("(UTC+11:00:00) Pacific/Noumea", TimeZoneInfo::GetSystemTimeZones()[420].DisplayName());
    EXPECT_EQ("NCST", TimeZoneInfo::GetSystemTimeZones()[420].DaylightName());
    EXPECT_EQ("11:00:00", TimeZoneInfo::GetSystemTimeZones()[420].BaseUtcOffset().ToString());
    EXPECT_EQ("NCT", TimeZoneInfo::GetSystemTimeZones()[420].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[420].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Pago_Pago) {
    EXPECT_EQ("Pacific/Pago_Pago", TimeZoneInfo::GetSystemTimeZones()[421].Id());
    EXPECT_EQ("(UTC-11:00:00) Pacific/Pago_Pago", TimeZoneInfo::GetSystemTimeZones()[421].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[421].DaylightName());
    EXPECT_EQ("-11:00:00", TimeZoneInfo::GetSystemTimeZones()[421].BaseUtcOffset().ToString());
    EXPECT_EQ("SST", TimeZoneInfo::GetSystemTimeZones()[421].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[421].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Palau) {
    EXPECT_EQ("Pacific/Palau", TimeZoneInfo::GetSystemTimeZones()[422].Id());
    EXPECT_EQ("(UTC+09:00:00) Pacific/Palau", TimeZoneInfo::GetSystemTimeZones()[422].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[422].DaylightName());
    EXPECT_EQ("09:00:00", TimeZoneInfo::GetSystemTimeZones()[422].BaseUtcOffset().ToString());
    EXPECT_EQ("PWT", TimeZoneInfo::GetSystemTimeZones()[422].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[422].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Pitcairn) {
    EXPECT_EQ("Pacific/Pitcairn", TimeZoneInfo::GetSystemTimeZones()[423].Id());
    EXPECT_EQ("(UTC-08:00:00) Pacific/Pitcairn", TimeZoneInfo::GetSystemTimeZones()[423].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[423].DaylightName());
    EXPECT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[423].BaseUtcOffset().ToString());
    EXPECT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[423].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[423].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Pohnpei) {
    EXPECT_EQ("Pacific/Pohnpei", TimeZoneInfo::GetSystemTimeZones()[424].Id());
    EXPECT_EQ("(UTC+11:00:00) Pacific/Pohnpei", TimeZoneInfo::GetSystemTimeZones()[424].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[424].DaylightName());
    EXPECT_EQ("11:00:00", TimeZoneInfo::GetSystemTimeZones()[424].BaseUtcOffset().ToString());
    EXPECT_EQ("PONT", TimeZoneInfo::GetSystemTimeZones()[424].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[424].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Ponape) {
    EXPECT_EQ("Pacific/Ponape", TimeZoneInfo::GetSystemTimeZones()[425].Id());
    EXPECT_EQ("(UTC+11:00:00) Pacific/Ponape", TimeZoneInfo::GetSystemTimeZones()[425].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[425].DaylightName());
    EXPECT_EQ("11:00:00", TimeZoneInfo::GetSystemTimeZones()[425].BaseUtcOffset().ToString());
    EXPECT_EQ("PONT", TimeZoneInfo::GetSystemTimeZones()[425].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[425].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Port_Moresby) {
    EXPECT_EQ("Pacific/Port_Moresby", TimeZoneInfo::GetSystemTimeZones()[426].Id());
    EXPECT_EQ("(UTC+10:00:00) Pacific/Port_Moresby", TimeZoneInfo::GetSystemTimeZones()[426].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[426].DaylightName());
    EXPECT_EQ("10:00:00", TimeZoneInfo::GetSystemTimeZones()[426].BaseUtcOffset().ToString());
    EXPECT_EQ("PGT", TimeZoneInfo::GetSystemTimeZones()[426].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[426].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Rarotonga) {
    EXPECT_EQ("Pacific/Rarotonga", TimeZoneInfo::GetSystemTimeZones()[427].Id());
    EXPECT_EQ("(UTC-10:00:00) Pacific/Rarotonga", TimeZoneInfo::GetSystemTimeZones()[427].DisplayName());
    EXPECT_EQ("CKHST", TimeZoneInfo::GetSystemTimeZones()[427].DaylightName());
    EXPECT_EQ("-10:00:00", TimeZoneInfo::GetSystemTimeZones()[427].BaseUtcOffset().ToString());
    EXPECT_EQ("CKT", TimeZoneInfo::GetSystemTimeZones()[427].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[427].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Saipan) {
    EXPECT_EQ("Pacific/Saipan", TimeZoneInfo::GetSystemTimeZones()[428].Id());
    EXPECT_EQ("(UTC+10:00:00) Pacific/Saipan", TimeZoneInfo::GetSystemTimeZones()[428].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[428].DaylightName());
    EXPECT_EQ("10:00:00", TimeZoneInfo::GetSystemTimeZones()[428].BaseUtcOffset().ToString());
    EXPECT_EQ("ChST", TimeZoneInfo::GetSystemTimeZones()[428].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[428].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Samoa) {
    EXPECT_EQ("Pacific/Samoa", TimeZoneInfo::GetSystemTimeZones()[429].Id());
    EXPECT_EQ("(UTC-11:00:00) Pacific/Samoa", TimeZoneInfo::GetSystemTimeZones()[429].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[429].DaylightName());
    EXPECT_EQ("-11:00:00", TimeZoneInfo::GetSystemTimeZones()[429].BaseUtcOffset().ToString());
    EXPECT_EQ("SST", TimeZoneInfo::GetSystemTimeZones()[429].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[429].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Tahiti) {
    EXPECT_EQ("Pacific/Tahiti", TimeZoneInfo::GetSystemTimeZones()[430].Id());
    EXPECT_EQ("(UTC-10:00:00) Pacific/Tahiti", TimeZoneInfo::GetSystemTimeZones()[430].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[430].DaylightName());
    EXPECT_EQ("-10:00:00", TimeZoneInfo::GetSystemTimeZones()[430].BaseUtcOffset().ToString());
    EXPECT_EQ("TAHT", TimeZoneInfo::GetSystemTimeZones()[430].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[430].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Tarawa) {
    EXPECT_EQ("Pacific/Tarawa", TimeZoneInfo::GetSystemTimeZones()[431].Id());
    EXPECT_EQ("(UTC+12:00:00) Pacific/Tarawa", TimeZoneInfo::GetSystemTimeZones()[431].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[431].DaylightName());
    EXPECT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[431].BaseUtcOffset().ToString());
    EXPECT_EQ("GILT", TimeZoneInfo::GetSystemTimeZones()[431].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[431].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Tongatapu) {
    EXPECT_EQ("Pacific/Tongatapu", TimeZoneInfo::GetSystemTimeZones()[432].Id());
    EXPECT_EQ("(UTC+13:00:00) Pacific/Tongatapu", TimeZoneInfo::GetSystemTimeZones()[432].DisplayName());
    EXPECT_EQ("TOST", TimeZoneInfo::GetSystemTimeZones()[432].DaylightName());
    EXPECT_EQ("13:00:00", TimeZoneInfo::GetSystemTimeZones()[432].BaseUtcOffset().ToString());
    EXPECT_EQ("TOT", TimeZoneInfo::GetSystemTimeZones()[432].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[432].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Truk) {
    EXPECT_EQ("Pacific/Truk", TimeZoneInfo::GetSystemTimeZones()[433].Id());
    EXPECT_EQ("(UTC+10:00:00) Pacific/Truk", TimeZoneInfo::GetSystemTimeZones()[433].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[433].DaylightName());
    EXPECT_EQ("10:00:00", TimeZoneInfo::GetSystemTimeZones()[433].BaseUtcOffset().ToString());
    EXPECT_EQ("CHUT", TimeZoneInfo::GetSystemTimeZones()[433].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[433].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Wake) {
    EXPECT_EQ("Pacific/Wake", TimeZoneInfo::GetSystemTimeZones()[434].Id());
    EXPECT_EQ("(UTC+12:00:00) Pacific/Wake", TimeZoneInfo::GetSystemTimeZones()[434].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[434].DaylightName());
    EXPECT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[434].BaseUtcOffset().ToString());
    EXPECT_EQ("WAKT", TimeZoneInfo::GetSystemTimeZones()[434].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[434].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Wallis) {
    EXPECT_EQ("Pacific/Wallis", TimeZoneInfo::GetSystemTimeZones()[435].Id());
    EXPECT_EQ("(UTC+12:00:00) Pacific/Wallis", TimeZoneInfo::GetSystemTimeZones()[435].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[435].DaylightName());
    EXPECT_EQ("12:00:00", TimeZoneInfo::GetSystemTimeZones()[435].BaseUtcOffset().ToString());
    EXPECT_EQ("WFT", TimeZoneInfo::GetSystemTimeZones()[435].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[435].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesPacific_Yap) {
    EXPECT_EQ("Pacific/Yap", TimeZoneInfo::GetSystemTimeZones()[436].Id());
    EXPECT_EQ("(UTC+10:00:00) Pacific/Yap", TimeZoneInfo::GetSystemTimeZones()[436].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[436].DaylightName());
    EXPECT_EQ("10:00:00", TimeZoneInfo::GetSystemTimeZones()[436].BaseUtcOffset().ToString());
    EXPECT_EQ("CHUT", TimeZoneInfo::GetSystemTimeZones()[436].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[436].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesUS_Alaska) {
    EXPECT_EQ("US/Alaska", TimeZoneInfo::GetSystemTimeZones()[437].Id());
    EXPECT_EQ("(UTC-09:00:00) US/Alaska", TimeZoneInfo::GetSystemTimeZones()[437].DisplayName());
    EXPECT_EQ("AKDT", TimeZoneInfo::GetSystemTimeZones()[437].DaylightName());
    EXPECT_EQ("-09:00:00", TimeZoneInfo::GetSystemTimeZones()[437].BaseUtcOffset().ToString());
    EXPECT_EQ("AKST", TimeZoneInfo::GetSystemTimeZones()[437].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[437].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesUS_Aleutian) {
    EXPECT_EQ("US/Aleutian", TimeZoneInfo::GetSystemTimeZones()[438].Id());
    EXPECT_EQ("(UTC-10:00:00) US/Aleutian", TimeZoneInfo::GetSystemTimeZones()[438].DisplayName());
    EXPECT_EQ("HADT", TimeZoneInfo::GetSystemTimeZones()[438].DaylightName());
    EXPECT_EQ("-10:00:00", TimeZoneInfo::GetSystemTimeZones()[438].BaseUtcOffset().ToString());
    EXPECT_EQ("HAST", TimeZoneInfo::GetSystemTimeZones()[438].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[438].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesUS_Arizona) {
    EXPECT_EQ("US/Arizona", TimeZoneInfo::GetSystemTimeZones()[439].Id());
    EXPECT_EQ("(UTC-07:00:00) US/Arizona", TimeZoneInfo::GetSystemTimeZones()[439].DisplayName());
    EXPECT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[439].DaylightName());
    EXPECT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[439].BaseUtcOffset().ToString());
    EXPECT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[439].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[439].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesUS_Central) {
    EXPECT_EQ("US/Central", TimeZoneInfo::GetSystemTimeZones()[440].Id());
    EXPECT_EQ("(UTC-06:00:00) US/Central", TimeZoneInfo::GetSystemTimeZones()[440].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[440].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[440].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[440].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[440].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesUS_East_Indiana) {
    EXPECT_EQ("US/East-Indiana", TimeZoneInfo::GetSystemTimeZones()[441].Id());
    EXPECT_EQ("(UTC-05:00:00) US/East-Indiana", TimeZoneInfo::GetSystemTimeZones()[441].DisplayName());
    EXPECT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[441].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[441].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[441].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[441].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesUS_Eastern) {
    EXPECT_EQ("US/Eastern", TimeZoneInfo::GetSystemTimeZones()[442].Id());
    EXPECT_EQ("(UTC-05:00:00) US/Eastern", TimeZoneInfo::GetSystemTimeZones()[442].DisplayName());
    EXPECT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[442].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[442].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[442].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[442].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesUS_Hawaii) {
    EXPECT_EQ("US/Hawaii", TimeZoneInfo::GetSystemTimeZones()[443].Id());
    EXPECT_EQ("(UTC-10:00:00) US/Hawaii", TimeZoneInfo::GetSystemTimeZones()[443].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[443].DaylightName());
    EXPECT_EQ("-10:00:00", TimeZoneInfo::GetSystemTimeZones()[443].BaseUtcOffset().ToString());
    EXPECT_EQ("HST", TimeZoneInfo::GetSystemTimeZones()[443].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[443].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesUS_Indiana_Starke) {
    EXPECT_EQ("US/Indiana-Starke", TimeZoneInfo::GetSystemTimeZones()[444].Id());
    EXPECT_EQ("(UTC-06:00:00) US/Indiana-Starke", TimeZoneInfo::GetSystemTimeZones()[444].DisplayName());
    EXPECT_EQ("CDT", TimeZoneInfo::GetSystemTimeZones()[444].DaylightName());
    EXPECT_EQ("-06:00:00", TimeZoneInfo::GetSystemTimeZones()[444].BaseUtcOffset().ToString());
    EXPECT_EQ("CST", TimeZoneInfo::GetSystemTimeZones()[444].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[444].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesUS_Michigan) {
    EXPECT_EQ("US/Michigan", TimeZoneInfo::GetSystemTimeZones()[445].Id());
    EXPECT_EQ("(UTC-05:00:00) US/Michigan", TimeZoneInfo::GetSystemTimeZones()[445].DisplayName());
    EXPECT_EQ("EDT", TimeZoneInfo::GetSystemTimeZones()[445].DaylightName());
    EXPECT_EQ("-05:00:00", TimeZoneInfo::GetSystemTimeZones()[445].BaseUtcOffset().ToString());
    EXPECT_EQ("EST", TimeZoneInfo::GetSystemTimeZones()[445].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[445].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesUS_Mountain) {
    EXPECT_EQ("US/Mountain", TimeZoneInfo::GetSystemTimeZones()[446].Id());
    EXPECT_EQ("(UTC-07:00:00) US/Mountain", TimeZoneInfo::GetSystemTimeZones()[446].DisplayName());
    EXPECT_EQ("MDT", TimeZoneInfo::GetSystemTimeZones()[446].DaylightName());
    EXPECT_EQ("-07:00:00", TimeZoneInfo::GetSystemTimeZones()[446].BaseUtcOffset().ToString());
    EXPECT_EQ("MST", TimeZoneInfo::GetSystemTimeZones()[446].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[446].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesUS_Pacific) {
    EXPECT_EQ("US/Pacific", TimeZoneInfo::GetSystemTimeZones()[447].Id());
    EXPECT_EQ("(UTC-08:00:00) US/Pacific", TimeZoneInfo::GetSystemTimeZones()[447].DisplayName());
    EXPECT_EQ("PDT", TimeZoneInfo::GetSystemTimeZones()[447].DaylightName());
    EXPECT_EQ("-08:00:00", TimeZoneInfo::GetSystemTimeZones()[447].BaseUtcOffset().ToString());
    EXPECT_EQ("PST", TimeZoneInfo::GetSystemTimeZones()[447].StandardName());
    EXPECT_TRUE(TimeZoneInfo::GetSystemTimeZones()[447].SupportsDaylightSavingTime());
  }
  
  TEST(TimeZoneInfo, GetSystemTimeZonesUS_Samoa) {
    EXPECT_EQ("US/Samoa", TimeZoneInfo::GetSystemTimeZones()[448].Id());
    EXPECT_EQ("(UTC-11:00:00) US/Samoa", TimeZoneInfo::GetSystemTimeZones()[448].DisplayName());
    EXPECT_EQ("", TimeZoneInfo::GetSystemTimeZones()[448].DaylightName());
    EXPECT_EQ("-11:00:00", TimeZoneInfo::GetSystemTimeZones()[448].BaseUtcOffset().ToString());
    EXPECT_EQ("SST", TimeZoneInfo::GetSystemTimeZones()[448].StandardName());
    EXPECT_FALSE(TimeZoneInfo::GetSystemTimeZones()[448].SupportsDaylightSavingTime());
  }
}
