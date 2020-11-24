#include "generated/HVAC/Heating/Element/Base.hpp"

class HVAC::Heating::Element::Implementation : public Base {
 public:
  using Base::Base;

  void handle(Enable &msg) override;
  void handle(Disable &msg) override;
}
