#pragma once
#include <Pcf/Types.h>

#ifndef WM_NULL
const int WM_NULL = 0x0000;
const int WM_CREATE = 0x0001;
const int WM_DESTROY = 0x0002;
const int WM_MOVE = 0x0003;
// not defined 0x0004
const int WM_SIZE = 0x0005;
const int WM_ACTIVATE = 0x0006;
const int WM_SETFOCUS = 0x0007;
const int WM_KILLFOCUS = 0x0008;
// not defined 0x0009
const int WM_ENABLE = 0x000A;
const int WM_SETREDRAW = 0x000B;
const int WM_SETTEXT = 0x000C;
const int WM_GETTEXT = 0x000D;
const int WM_GETTEXTLENGTH = 0x000E;
const int WM_PAINT = 0x000F;
const int WM_CLOSE = 0x0010;
const int WM_QUERYENDSESSION = 0x0011;
const int WM_QUIT = 0x0012;
const int WM_QUERYOPEN = 0x0013;
const int WM_ERASEBKGND = 0x0014;
const int WM_SYSCOLORCHANGE = 0x0015;
const int WM_ENDSESSION = 0x0016;
// not defined 0x0017
const int WM_SHOWWINDOW = 0x0018;
const int WM_CTLCOLOR = 0x0019;
const int WM_WININICHANGE = 0x001A;
const int WM_DEVMODECHANGE = 0x001B;
const int WM_ACTIVATEAPP = 0x001C;
const int WM_FONTCHANGE = 0x001D;
const int WM_TIMECHANGE = 0x001E;
const int WM_CANCELMODE = 0x001F;
const int WM_SETCURSOR = 0x0020;
const int WM_MOUSEACTIVATE = 0x0021;
const int WM_CHILDACTIVATE = 0x0022;
const int WM_QUEUESYNC = 0x0023;
const int WM_GETMINMAXINFO = 0x0024;
// not defined 0x0025
const int WM_PAINTICON = 0x0026;
const int WM_ICONERASEBKGND = 0x0027;
const int WM_NEXTDLGCTL = 0x0028;
// not defined 0x0029
const int WM_SPOOLERSTATUS = 0x002A;
const int WM_DRAWITEM = 0x002B;
const int WM_MEASUREITEM = 0x002C;
const int WM_DELETEITEM = 0x002D;
const int WM_VKEYTOITEM = 0x002E;
const int WM_CHARTOITEM = 0x002F;
const int WM_SETFONT = 0x0030;
const int WM_GETFONT = 0x0031;
const int WM_SETHOTKEY = 0x0032;
const int WM_GETHOTKEY = 0x0033;
// not defined 0x0034 - 0x0036
const int WM_QUERYDRAGICON = 0x0037;
const int WM_COMPAREITEM = 0x0039;
const int WM_GETOBJECT = 0x003D;
const int WM_COMPACTING = 0x0041;
const int WM_COMMNOTIFY = 0x0044;
const int WM_WINDOWPOSCHANGING = 0x0046;
const int WM_WINDOWPOSCHANGED = 0x0047;
const int WM_POWER = 0x0048;
const int WM_COPYDATA = 0x004A;
const int WM_CANCELJOURNAL = 0x004B;
// not defined 0x004C - 0x004D
const int WM_NOTIFY = 0x004E;
// not defined 0x004F
const int WM_INPUTLANGCHANGEREQUEST = 0x0050;
const int WM_INPUTLANGCHANGE = 0x0051;
const int WM_TCARD = 0x0052;
const int WM_HELP = 0x0053;
const int WM_USERCHANGED = 0x0054;
const int WM_NOTIFYFORMAT = 0x0055;
// not defined 0x0056 - 0x007A
const int WM_CONTEXTMENU = 0x007B;
const int WM_STYLECHANGING = 0x007C;
const int WM_STYLECHANGED = 0x007D;
const int WM_DISPLAYCHANGE = 0x007E;
const int WM_GETICON = 0x007F;
const int WM_SETICON = 0x0080;
const int WM_NCCREATE = 0x0081;
const int WM_NCDESTROY = 0x0082;
const int WM_NCCALCSIZE = 0x0083;
const int WM_NCHITTEST = 0x0084;
const int WM_NCPAINT = 0x0085;
const int WM_NCACTIVATE = 0x0086;
const int WM_GETDLGCODE = 0x0087;
const int WM_SYNCPAINT = 0x0088;
// not defined 0x0089 - 0x000F
const int WM_NCMOUSEMOVE = 0x00A0;
const int WM_NCLBUTTONDOWN = 0x00A1;
const int WM_NCLBUTTONUP = 0x00A2;
const int WM_NCLBUTTONDBLCLK = 0x00A3;
const int WM_NCRBUTTONDOWN = 0x00A4;
const int WM_NCRBUTTONUP = 0x00A5;
const int WM_NCRBUTTONDBLCLK = 0x00A6;
const int WM_NCMBUTTONDOWN = 0x00A7;
const int WM_NCMBUTTONUP = 0x00A8;
const int WM_NCMBUTTONDBLCLK = 0x00A9;
// not defined 0x00AA
const int WM_NCXBUTTONDOWN = 0x00AB;
const int WM_NCXBUTTONUP = 0x00AC;
const int WM_NCXBUTTONDBLCLK = 0x00AD;
const int WM_INPUT_DEVICE_CHANGE = 0x00FE;
const int WM_INPUT = 0x00FF;
const int WM_KEYDOWN = 0x0100;
const int WM_KEYUP = 0x0101;
const int WM_CHAR = 0x0102;
const int WM_DEADCHAR = 0x0103;
const int WM_SYSKEYDOWN = 0x0104;
const int WM_SYSKEYUP = 0x0105;
const int WM_SYSCHAR = 0x0106;
const int WM_SYSDEADCHAR = 0x0107;
//const int WM_KEYLAST = 0x0108;
//const int WM_UNICHAR = 0x0109;
const int WM_KEYLAST = 0x0109;
// not defined 0x010B - 0x010C
const int WM_IME_STARTCOMPOSITION = 0x010D;
const int WM_IME_ENDCOMPOSITION = 0x010E;
const int WM_INITDIALOG = 0x0110;
const int WM_COMMAND = 0x0111;
const int WM_SYSCOMMAND = 0x0112;
const int WM_TIMER = 0x0113;
const int WM_HSCROLL = 0x0114;
const int WM_VSCROLL = 0x0115;
const int WM_INITMENU = 0x0116;
const int WM_INITMENUPOPUP = 0x0117;
// not defined 0x0118
const int WM_GESTURE = 0x0119;
const int WM_GESTURENOTIFY = 0x011A;
// not defined 0x011B - 0x011E
const int WM_MENUSELECT = 0x011F;
const int WM_MENUCHAR = 0x0120;
const int WM_ENTERIDLE = 0x0121;
const int WM_MENURBUTTONUP = 0x0122;
const int WM_MENUDRAG = 0x0123;
const int WM_MENUGETOBJECT = 0x0124;
const int WM_UNINITMENUPOPUP = 0x0125;
const int WM_MENUCOMMAND = 0x0126;
const int WM_CHANGEUISTATE = 0x0127;
const int WM_UPDATEUISTATE = 0x0128;
const int WM_QUERYUISTATE = 0x0129;
// not defined 0x0130 - 0x0131
const int WM_CTLCOLORMSGBOX = 0x0132;
const int WM_CTLCOLOREDIT = 0x0133;
const int WM_CTLCOLORLISTBOX = 0x0134;
const int WM_CTLCOLORBTN = 0x0135;
const int WM_CTLCOLORDLG = 0x0136;
const int WM_CTLCOLORSCROLLBAR = 0x0137;
const int WM_CTLCOLORSTATIC = 0x0138;
// not defined 0x0139 - 01E0
const int MN_GETHMENU = 0x01E1;
// not defined 0x01E2 - 0x019F
const int WM_MOUSEMOVE = 0x0200;
const int WM_LBUTTONDOWN = 0x0201;
const int WM_LBUTTONUP = 0x0202;
const int WM_LBUTTONDBLCLK = 0x0203;
const int WM_RBUTTONDOWN = 0x0204;
const int WM_RBUTTONUP = 0x0205;
const int WM_RBUTTONDBLCLK = 0x0206;
const int WM_MBUTTONDOWN = 0x0207;
const int WM_MBUTTONUP = 0x0208;
const int WM_MBUTTONDBLCLK = 0x0209;
const int WM_MOUSEWHEEL = 0x020A;
const int WM_XBUTTONDOWN = 0x020B;
const int WM_XBUTTONUP = 0x020C;
const int WM_XBUTTONDBLCLK = 0x020D;
const int WM_MOUSEHWHEEL = 0x020E;
// not defined 0x020F
const int WM_PARENTNOTIFY = 0x0210;
const int WM_ENTERMENULOOP = 0x0211;
const int WM_EXITMENULOOP = 0x0212;
const int WM_NEXTMENU = 0x0213;
const int WM_SIZING = 0x0214;
const int WM_CAPTURECHANGED = 0x0215;
const int WM_MOVING = 0x0216;
// not defined 0x0217
const int WM_POWERBROADCAST = 0x0218;
const int WM_DEVICECHANGE = 0x0219;
const int WM_MDICREATE = 0x0220;
const int WM_MDIDESTROY = 0x0221;
const int WM_MDIACTIVATE = 0x0222;
const int WM_MDIRESTORE = 0x0223;
const int WM_MDINEXT = 0x0224;
const int WM_MDIMAXIMIZE = 0x0225;
const int WM_MDITILE = 0x0226;
const int WM_MDICASCADE = 0x0227;
const int WM_MDIICONARRANGE = 0x0228;
const int WM_MDIGETACTIVE = 0x0229;
const int WM_MDISETMENU = 0x0230;
const int WM_ENTERSIZEMOVE = 0x0231;
const int WM_EXITSIZEMOVE = 0x0232;
const int WM_DROPFILES = 0x0233;
const int WM_MDIREFRESHMENU = 0x0234;
// not defined 0x0235 - 0x0237
const int WM_POINTERDEVICECHANGE = 0x0238;
const int WM_POINTERDEVICEINRANGE = 0x0239;
const int WM_POINTERDEVICEOUTOFRANGE = 0x023A;
const int WM_TOUCH = 0x0240;
const int WM_NCPOINTERUPDATE = 0x0241;
const int WM_NCPOINTERDOWN = 0x0242;
const int WM_NCPOINTERUP = 0x0243;
const int WM_POINTERUPDATE = 0x0245;
const int WM_POINTERDOWN = 0x0246;
const int WM_POINTERUP = 0x0247;
const int WM_POINTERENTER = 0x0249;
const int WM_POINTERLEAVE = 0x024A;
const int WM_POINTERACTIVATE = 0x024B;
const int WM_POINTERCAPTURECHANGED = 0x024C;
const int WM_TOUCHHITTESTING = 0x024D;
const int WM_POINTERWHEEL = 0x024E;
const int WM_POINTERHWHEEL = 0x024F;
const int DM_POINTERHITTEST = 0x0250;
// not defined 0x0251 - 0x0280
const int WM_IME_SETCONTEXT = 0x0281;
const int WM_IME_NOTIFY = 0x0282;
const int WM_IME_CONTROL = 0x0283;
const int WM_IME_COMPOSITIONFULL = 0x0284;
const int WM_IME_SELECT = 0x0285;
const int WM_IME_CHAR = 0x0286;
// not defined 0x0287
const int WM_IME_REQUEST = 0x0288;
// not defined 0x0289
const int WM_IME_KEYDOWN = 0x0290;
const int WM_IME_KEYUP = 0x0291;
// not defined 0x0292 - 0x02A0
const int WM_MOUSEHOVER = 0x02A1;
const int WM_MOUSELEAVE = 0x2A3;
// not defined 0x02A4 - 0x02A9
const int WM_NCMOUSEHOVER = 0x02A0;
const int WM_NCMOUSELEAVE = 0x02A2;
// not defined 0x02A3 - 0x02B0
const int WM_WTSSESSION_CHANGE = 0x02B1;
// not defined 0x02B2 - 0x02BF
const int WM_TABLET_FIRST = 0x02C0;
// not defined 0x02C1 - 0x02DE
const int WM_TABLET_LAST = 0x02DF;
const int WM_DPICHANGED = 0x02E0;
// not defined 0x02E1 - 0x029F
const int WM_CUT = 0x0300;
const int WM_COPY = 0x0301;
const int WM_PASTE = 0x0302;
const int WM_CLEAR = 0x0303;
const int WM_UNDO = 0x0304;
const int WM_RENDERFORMAT = 0x0305;
const int WM_RENDERALLFORMATS = 0x0306;
const int WM_DESTROYCLIPBOARD = 0x0307;
const int WM_DRAWCLIPBOARD = 0x0308;
const int WM_PAINTCLIPBOARD = 0x0309;
const int WM_VSCROLLCLIPBOARD = 0x030A;
const int WM_SIZECLIPBOARD = 0x030B;
const int WM_ASKCBFORMATNAME = 0x030C;
const int WM_CHANGECBCHAIN = 0x030D;
const int WM_HSCROLLCLIPBOARD = 0x030E;
const int WM_QUERYNEWPALETTE = 0x030F;
const int WM_PALETTEISCHANGING = 0x0310;
const int WM_PALETTECHANGED = 0x0311;
const int WM_HOTKEY = 0x0312;
// not defined 0x0313 - 0x0316
const int WM_PRINT = 0x0317;
const int WM_PRINTCLIENT = 0x0318;
const int WM_APPCOMMAND = 0x0319;
const int WM_THEMECHANGED = 0x031A;
// not defined 0x031B - 0x031C
const int WM_CLIPBOARDUPDATE = 0x031D;
const int WM_DWMCOMPOSITIONCHANGED = 0x031E;
const int WM_DWMNCRENDERINGCHANGED = 0x031F;
const int WM_DWMCOLORIZATIONCOLORCHANGED = 0x0320;
const int WM_DWMWINDOWMAXIMIZEDCHANGE = 0x0321;
const int WM_DWMSENDICONICTHUMBNAIL = 0x0323;
const int WM_DWMSENDICONICLIVEPREVIEWBITMAP = 0x0326;
// not defined 0x0327 - 0x033E
const int WM_GETTITLEBARINFOEX = 0x033F;
// not defined 0x0340 - 0x0357
const int WM_HANDHELDFIRST = 0x0358;
// not defined 0x0359 - 0x035E
const int WM_HANDHELDLAST = 0x035F;
const int WM_AFXFIRST = 0x0360;
// not defined 0x0361 - 0x037E
const int WM_AFXLAST = 0x037F;
const int WM_PENWINFIRST = 0x0380;
// not defined 0x0381 - 0x038E
const int WM_PENWINLAST = 0x038F;
// not defined 0x0390 - 0x039F

// NOTE: All Message Numbers below 0x0400 are RESERVED.
// Private Window Messages Start Here:
const int WM_USER = 0x0400;
// Private Window Messages Stop Here : 0x7FFF;

// NOTE: Messages available for use by applications.
const int WM_APP = 0x8000;
#endif

const int WM_MOUSEENTER = WM_USER + 0x0001;
