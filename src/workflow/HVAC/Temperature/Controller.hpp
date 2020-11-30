#include "generated/HVAC/Temperature/Controller/Base.hpp"

class HVAC::Temperature::Controller::Implementation : public Base {
 public:
  using Base::Base;

 protected:
  void handle(Initialize &msg) override;
  void handle(Finalize &msg) override;
  
  void handle(Measurement &msg) override;
}
