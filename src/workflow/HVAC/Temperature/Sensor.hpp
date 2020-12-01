#include "generated/HVAC/Temperature/Sensor/Base.hpp"

class HVAC::Temperature::Sensor::Impl : public Base {
 public:
  using Base::Base;

 protected:
  virtual void handle(Reset &msg) override;
  virtual void handle(Start &msg) override;
  
  virtual void handle(Measure &msg) override;

  double read_hardware();
  
  unsigned int count_;
}
