#include "Controller.hpp"

using namespace HVAC::Temperature::Controller;

void Implementation::handle(Initialize &msg) {
  send(Disable());
}

void Implementation::handle(Finalize &msg) {
  send(Disable());
}

void Implementation::handle(Measurement &msg) {
  if (msg.Temperature() > config.Setpoint + config.Hysteresis/2.0) {
    send(Disable());
  } else if (msg.Temperature() < config.Setpoint - config.Hysteresis/2.0) {
    send(Enable());
  }
}
