#include "generated/HVAC/Heating/Element/Base.hpp"

class HVAC::Heating::Element::Implementation : public Base {
 public:
  using Base::Base;

  bool handle(Enable &msg) override;
  bool handle(Disable &msg) override;
}
