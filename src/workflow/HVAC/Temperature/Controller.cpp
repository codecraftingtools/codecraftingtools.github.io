#include "Controller.hpp"

using namespace HVAC::Temperature::Controller;

void Impl::handle(Initialize &msg) {
  send(Disable());
}

void Impl::handle(Finalize &msg) {
  send(Disable());
}

void Impl::handle(Measurement &msg) {
  if (msg.Temperature() > config.Setpoint() + config.Hysteresis()/2.0) {
    send(Disable());
  } else if (msg.Temperature() < config.Setpoint() - config.Hysteresis()/2.0) {
    send(Enable());
  }
}
