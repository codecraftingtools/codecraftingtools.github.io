#include "Element.hpp"

using namespace HVAC::Heating::Element;

void Implementation::handle(Enable &msg) {
  log.verbose("heat enabled");
}

void Implementation::handle(Disable &msg) {
  log.verbose("heat disabled");
}
