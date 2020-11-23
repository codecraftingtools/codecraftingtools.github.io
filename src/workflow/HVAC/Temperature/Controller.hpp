#include "generated/HVAC/Temperature/Controller/Base.hpp"

class HVAC::Temperature::Controller::Implementation : public Base {
 public:
  using Base::Base;

  bool handle(Initialize &msg) override;
  bool handle(Finalize &msg) override;
  
  bool handle(Measurement &msg) override;
}
