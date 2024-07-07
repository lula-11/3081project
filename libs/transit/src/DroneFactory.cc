#include "DroneFactory.h"
#include "BatteryDecorator.h"

IEntity* DroneFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("drone") == 0) {
    std::cout << "BatteryDrone Created" << std::endl;
    Drone* batteryC = new Drone(entity);
    return new BatteryDecorator(batteryC);
  }
  return nullptr;
  }
