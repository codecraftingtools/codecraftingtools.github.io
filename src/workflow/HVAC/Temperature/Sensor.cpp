#include "Sensor.hpp"

using namespace HVAC::Temperature::Sensor;
using namespace chimps::chrono;

void Impl::handle(Reset &msg) {
  count_ = 0;
}

void Impl::handle(Start &msg) {
  schedule(Measure(), every(1.0_s * config.Period));
}

void Impl::handle(Measure &msg) {
  auto temperature = read_hardware();
  log.verbose("measured: {:.1f}", temperature);
  
  send(Measurement()
       .Temperature(temperature)
       .Humidity(0.60)
       );
}

float Impl::read_hardware() {
  const double pi = 3.14159;

  count_ += 1;
  
  auto t = count_ * config.Period; // s
  auto f = 0.1; // Hz
  auto temperature = 60.0 + 10.0 * sin(2*pi*f*t);
    
  return temperature;
}
