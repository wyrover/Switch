#include <Pcf/System/IO/MemoryStream.h>
#include <Pcf/System/IO/StringReader.h>
#include <Pcf/System/IO/StreamReader.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::IO;
using namespace TUnit;

namespace {

	TEST(StreamReader, Read) {
		Array<byte> buffer = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		IO::MemoryStream s(buffer, false);
		IO::StreamReader reader(s);

		int32 idx = 0;
		int32 current = reader.Read();
		while (current != -1)
		{
			EXPECT_EQ(buffer[idx], current);
			idx++;
			current = reader.Read();
		}
	}

	TEST(StreamReader, ReadLineUTF8) {
		Array<byte> utf8buffer = { 0x61, 0xC3, 0xA6, 0xC5, 0xA3, '\n', 0xCE, 0xA3, 0xDC, 0xA3, 0xE2, 0x96, 0x88, '\n', 0xE5, 0xA5, 0xBB, 0xF0, 0x9F, 0x90, 0xA8 };
		RefPtr<Text::Encoding> encoding = Text::Encoding::UTF8();
		IO::MemoryStream s(utf8buffer, false);
		IO::StreamReader reader(s, *encoding);

		string line =reader.ReadLine();
		EXPECT_EQ(3, line.Length());
		StringReader line1reader(line);
		EXPECT_EQ(0x61, line1reader.Read());
		EXPECT_EQ(0xE6, line1reader.Read());
		EXPECT_EQ(0x163, line1reader.Read());

		line = reader.ReadLine();
		EXPECT_EQ(3, line.Length());
		line = reader.ReadLine();
		EXPECT_EQ(2, line.Length());

	}

	TEST(StreamReader, ReadToEndUTF8) {
		Array<byte> utf8buffer = { 0x61, 0xC3, 0xA6, 0xC5, 0xA3, '\n', 0xCE, 0xA3, 0xDC, 0xA3, 0xE2, 0x96, 0x88, '\n', 0xE5, 0xA5, 0xBB, 0xF0, 0x9F, 0x90, 0xA8 };
		RefPtr<Text::Encoding> encoding = Text::Encoding::UTF8();
		IO::MemoryStream s(utf8buffer, false);
		IO::StreamReader reader(s, *encoding);

		string all = reader.ReadToEnd();
		EXPECT_EQ(10, all.Length());

		StringReader allreader(all);
		EXPECT_EQ(0x61, allreader.Read());
		EXPECT_EQ(0xE6, allreader.Read());
		EXPECT_EQ(0x163, allreader.Read());
		EXPECT_EQ('\n', allreader.Read());
	}

	TEST(StreamReader, ReadLine437) {
		Array<byte> buffer = { 0x61, 0x91, '\n', 0xE4, 0xDB};
		RefPtr<Text::Encoding> encoding = Text::Encoding::CreateEncoding(437);

		IO::MemoryStream s(buffer, false);
		IO::StreamReader reader(s, *encoding);

		string line = reader.ReadLine();

		EXPECT_EQ(2, line.Length());
		StringReader line1reader(line);
		EXPECT_EQ(0x61, line1reader.Read());
		EXPECT_EQ(0xE6, line1reader.Read());

		line = reader.ReadLine();
		EXPECT_EQ(2, line.Length());
		StringReader line2reader(line);
		EXPECT_EQ(0x3A3, line2reader.Read());
		EXPECT_EQ(0x2588, line2reader.Read());

	}

	TEST(StreamReader, ReadToEnd437) {
		Array<byte> buffer = { 0x61, 0x91, '\n', 0xE4, 0xDB };
		RefPtr<Text::Encoding> encoding = Text::Encoding::CreateEncoding(437);

		IO::MemoryStream s(buffer, false);
		IO::StreamReader reader(s, *encoding);

		string all = reader.ReadToEnd();

		EXPECT_EQ(5, all.Length());

		StringReader allreader(all);
		EXPECT_EQ(0x61, allreader.Read());
		EXPECT_EQ(0xE6, allreader.Read());
		EXPECT_EQ('\n', allreader.Read());
		EXPECT_EQ(0x3A3, allreader.Read());
		EXPECT_EQ(0x2588, allreader.Read());
	}
}
