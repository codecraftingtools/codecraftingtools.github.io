#include "generated/HVAC/Temperature/Controller/Base.hpp"

class HVAC::Temperature::Controller::Impl : public Base {
 public:
  using Base::Base;

 protected:
  virtual void handle(Initialize &msg) override;
  virtual void handle(Finalize &msg) override;
  
  virtual void handle(Measurement &msg) override;
}
