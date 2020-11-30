#include "generated/HVAC/Temperature/Sensor/Base.hpp"

class HVAC::Temperature::Sensor::Implementation : public Base {
 public:
  using Base::Base;

 protected:
  void handle(Reset &msg) override;
  void handle(Start &msg) override;
  
  void handle(Measure &msg) override;

  double read_hardware();
  
  unsigned int count_;
}
