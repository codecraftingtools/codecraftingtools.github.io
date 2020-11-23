#include "Controller.hpp"

using namespace HVAC::Temperature::Controller;

bool Implementation::handle(Initialize &msg) {
  send(Disable());
  return true;
}

bool Implementation::handle(Finalize &msg) {
  send(Disable());
  return true;
}

bool Implementation::handle(Measurement &msg) {
  if (msg.Temperature() > config.Setpoint + config.Hysteresis/2.0) {
    send(Disable());
  } else if (msg.Temperature() < config.Setpoint - config.Hysteresis/2.0) {
    send(Enable());
  }
  return true;
}
