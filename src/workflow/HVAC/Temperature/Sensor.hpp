#include "generated/HVAC/Temperature/Sensor/Base.hpp"

class HVAC::Temperature::Sensor::Implementation : public Base {
 public:
  using Base::Base;

  bool handle(Reset &msg) override;
  bool handle(Start &msg) override;
  
  bool handle(Measure &msg) override;

 protected:
  double read_hardware();
  
  unsigned int count_;
}
