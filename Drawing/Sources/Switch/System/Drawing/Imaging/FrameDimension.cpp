#include "../../../../../Includes/Switch/System/Drawing/Imaging/FrameDimension.hpp"

using namespace System::Drawing::Imaging;

property<FrameDimension, readonly> FrameDimension::Page {
  [] {return FrameDimension("7462dc86-6180-4c7e-8e3f-ee7333a7a483", "Page");}
};

property<FrameDimension, readonly> FrameDimension::Resolution {
  [] {return FrameDimension("84236f7b-3bd3-428f-8dab-4ea1439ca315", "Resolution");}
};

property<FrameDimension, readonly> FrameDimension::Time {
  [] {return FrameDimension("6aedbd6d-3fb5-418a-83a6-7f45229dc872", "Time");}
};

