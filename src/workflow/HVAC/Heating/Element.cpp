#include "Element.hpp"

using namespace HVAC::Heating::Element;

void Impl::handle(Enable &msg) {
  log.verbose("heat enabled");
}

void Impl::handle(Disable &msg) {
  log.verbose("heat disabled");
}
