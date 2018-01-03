#include <Switch/Switch>

using namespace System;

namespace Examples {
  // The following class represents simple functionality of the trapezoid.
  class MathTrapezoidSample : public object {
  public:
    // The main entry point for the application.
    static void Main() {
      MathTrapezoidSample trpz(20.0, 10.0, 8.0, 6.0);
      Console::WriteLine("The trapezoid's bases are 20.0 and 10.0, the trapezoid's legs are 8.0 and 6.0");
      double h = trpz.GetHeight();
      Console::WriteLine("Trapezoid height is: {0}", h);
      double dxR = trpz.GetLeftBaseRadianAngle();
      Console::WriteLine("Trapezoid left base angle is: {0} Radians", dxR);
      double dyR = trpz.GetRightBaseRadianAngle();
      Console::WriteLine("Trapezoid right base angle is: {0} Radians", dyR);
      double dxD = trpz.GetLeftBaseDegreeAngle();
      Console::WriteLine("Trapezoid left base angle is: {0} Degrees", dxD);
      double dyD = trpz.GetRightBaseDegreeAngle();
      Console::WriteLine("Trapezoid left base angle is: {0} Degrees", dyD);
    }

    MathTrapezoidSample(double longbase, double shortbase, double leftLeg, double rightLeg) {
      this->longBase = Math::Abs(longbase);
      this->shortBase = Math::Abs(shortbase);
      this->leftLeg = Math::Abs(leftLeg);
      this->rightLeg = Math::Abs(rightLeg);
    }

    double GetHeight() {
      double x = GetRightSmallBase();
      return Math::Sqrt(Math::Pow(this->rightLeg, 2.0) - Math::Pow(x, 2.0));
    }

    double GetSquare() {
      return GetHeight() * this->longBase / 2.0;
    }

    double GetLeftBaseRadianAngle() {
      double sinX = GetHeight() / this->leftLeg;
      return Math::Round(Math::Asin(sinX), 2);
    }

    double GetRightBaseRadianAngle() {
      double x = GetRightSmallBase();
      double cosX = (Math::Pow(this->rightLeg, 2.0) + Math::Pow(x, 2.0) - Math::Pow(GetHeight(), 2.0)) / (2 * x * this->rightLeg);
      return Math::Round(Math::Acos(cosX), 2);
    }

    double GetLeftBaseDegreeAngle() {
      double x = GetLeftBaseRadianAngle() * 180 / Math::PI;
      return Math::Round(x, 2);
    }

    double GetRightBaseDegreeAngle() {
      double x = GetRightBaseRadianAngle() * 180 / Math::PI;
      return Math::Round(x, 2);
    }

  private:
    double longBase;
    double shortBase;
    double leftLeg;
    double rightLeg;

    double GetRightSmallBase() {
      return (Math::Pow(this->rightLeg, 2.0) - Math::Pow(this->leftLeg, 2.0) + Math::Pow(this->longBase, 2.0) + Math::Pow(this->shortBase, 2.0) - 2 * this->shortBase * this->longBase) / (2 * (this->longBase - this->shortBase));
    }
  };
}

startup_(Examples::MathTrapezoidSample);

// This code produces the following output:
//
// The trapezoid's bases are 20.0 and 10.0, the trapezoid's legs are 8.0 and 6.0
// Trapezoid height is: 4.8
// Trapezoid left base angle is: 0.64 Radians
// Trapezoid right base angle is: 0.93 Radians
// Trapezoid left base angle is: 36.67 Degrees
// Trapezoid left base angle is: 53.29 Degrees
