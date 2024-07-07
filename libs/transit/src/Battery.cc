#include "Battery.h"


Battery::Battery(JsonObject &obj) : IEntity(obj) {}

Vector3 Battery::getDestination() const {
  return destination;
}

void Battery::update(double dt) {}
