#include "generated/HVAC/Heating/Element/Base.hpp"

class HVAC::Heating::Element::Impl : public Base {
 public:
  using Base::Base;

 protected:
  virtual void handle(Enable &msg) override;
  virtual void handle(Disable &msg) override;
}
