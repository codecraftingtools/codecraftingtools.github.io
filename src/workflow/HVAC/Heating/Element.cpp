#include "Element.hpp"

using namespace HVAC::Heating::Element;

void Implementation::handle(Enable &msg) {
  log.verbose("enabled");
}

void Implementation::handle(Disable &msg) {
  log.verbose("disabled");
}
