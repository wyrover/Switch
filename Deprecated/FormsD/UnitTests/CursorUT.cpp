#include <FL/Fltk.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>
#include <Pcf/System/Int32.h>
#include <Pcf/System/Windows/Forms/Cursors.h>

using namespace TUnit;

TEST(Cursor, Ctor) {
  ASSERT_EQ(System::Windows::FormsD::Cursors::Default, System::Windows::FormsD::Cursor());
}

TEST(Cursor, AppStarting) {
  ASSERT_EQ(FL_CURSOR_WAIT, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::AppStarting.Tag()));
}

TEST(Cursor, Arrow) {
  ASSERT_EQ(FL_CURSOR_ARROW, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::Arrow.Tag()));
}

TEST(Cursor, Cross) {
  ASSERT_EQ(FL_CURSOR_CROSS, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::Cross.Tag()));
}

TEST(Cursor, Default) {
  ASSERT_EQ(FL_CURSOR_DEFAULT, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::Default.Tag()));
}

TEST(Cursor, Hand) {
  ASSERT_EQ(FL_CURSOR_HAND, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::Hand.Tag()));
}

TEST(Cursor, Help) {
  ASSERT_EQ(FL_CURSOR_HELP, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::Help.Tag()));
}

TEST(Cursor, HSplit) {
  ASSERT_EQ(FL_CURSOR_NS, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::HSplit.Tag()));
}

TEST(Cursor, IBeam) {
  ASSERT_EQ(FL_CURSOR_INSERT, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::IBeam.Tag()));
}

TEST(Cursor, No) {
  ASSERT_EQ(FL_CURSOR_NONE, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::No.Tag()));
}

TEST(Cursor, NoMove2D) {
  ASSERT_EQ(FL_CURSOR_DEFAULT, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::NoMove2D.Tag()));
}

TEST(Cursor, NoMoveHoriz) {
  ASSERT_EQ(FL_CURSOR_DEFAULT, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::NoMoveHoriz.Tag()));
}

TEST(Cursor, NoMoveVert) {
  ASSERT_EQ(FL_CURSOR_DEFAULT, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::NoMoveVert.Tag()));
}

TEST(Cursor, PanEast) {
  ASSERT_EQ(FL_CURSOR_E, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::PanEast.Tag()));
}

TEST(Cursor, PanNE) {
  ASSERT_EQ(FL_CURSOR_NE, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::PanNE.Tag()));
}

TEST(Cursor, PanNorth) {
  ASSERT_EQ(FL_CURSOR_N, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::PanNorth.Tag()));
}

TEST(Cursor, PanNW) {
  ASSERT_EQ(FL_CURSOR_NW, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::PanNW.Tag()));
}

TEST(Cursor, PanSE) {
  ASSERT_EQ(FL_CURSOR_SE, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::PanSE.Tag()));
}

TEST(Cursor, PanSouth) {
  ASSERT_EQ(FL_CURSOR_S, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::PanSouth.Tag()));
}

TEST(Cursor, PanSW) {
  ASSERT_EQ(FL_CURSOR_SW, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::PanSW.Tag()));
}

TEST(Cursor, PanWest) {
  ASSERT_EQ(FL_CURSOR_W, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::PanWest.Tag()));
}

TEST(Cursor, SizeAll) {
  ASSERT_EQ(FL_CURSOR_MOVE, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::SizeAll.Tag()));
}

TEST(Cursor, SizeNESW) {
  ASSERT_EQ(FL_CURSOR_NESW, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::SizeNESW.Tag()));
}

TEST(Cursor, SizeNS) {
  ASSERT_EQ(FL_CURSOR_NS, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::SizeNS.Tag()));
}

TEST(Cursor, PanNWSE) {
  ASSERT_EQ(FL_CURSOR_NWSE, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::SizeNWSE.Tag()));
}

TEST(Cursor, SizeWE) {
  ASSERT_EQ(FL_CURSOR_WE, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::SizeWE.Tag()));
}

TEST(Cursor, UpArrow) {
  ASSERT_EQ(FL_CURSOR_DEFAULT, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::UpArrow.Tag()));
}

TEST(Cursor, VSplit) {
  ASSERT_EQ(FL_CURSOR_WE, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::VSplit.Tag()));
}

TEST(Cursor, WaitCursor) {
  ASSERT_EQ(FL_CURSOR_WAIT, static_cast<const System::Int32&>(System::Windows::FormsD::Cursors::WaitCursor.Tag()));
}
