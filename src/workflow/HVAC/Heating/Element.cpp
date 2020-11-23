#include "Element.hpp"

using namespace HVAC::Heating::Element;

bool Implementation::handle(Enable &msg) {
  log.verbose("enabled");
  return true;
}

bool Implementation::handle(Disable &msg) {
  log.verbose("disabled");
  return true;
}
