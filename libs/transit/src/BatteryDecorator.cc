#include "BatteryDecorator.h"
#include "Drone.h"

#include <cmath>
#include <limits>

#include "AstarStrategy.h"
#include "BeelineStrategy.h"
#include "DfsStrategy.h"
#include "BfsStrategy.h"
#include "DijkstraStrategy.h"
#include "JumpDecorator.h"
#include <vector>
#include "SpinDecorator.h"

#include "Package.h"
#include "SimulationModel.h"

BatteryDecorator::BatteryDecorator(Drone* entity)
    : decoratedDrone(entity), charge(120.0) {}




BatteryDecorator ::~BatteryDecorator() {
  if (decoratedDrone) {
    delete decoratedDrone;
  if (toNearestRecharge) {
    delete toNearestRecharge;
}
  }
}


double BatteryDecorator::getCharge() {
        return charge;
}


void BatteryDecorator::rechargeBattery() {
        charge = 120.0;
}



Vector3 BatteryDecorator::getNearestRecharge() {
    Vector3 current_position = decoratedDrone->getPosition();
    Vector3 nearestRechargePosition;

    for (int i = 0; i < model->rechargeStation.size(); ++i) {
        Battery* batteryCmp = model->rechargeStation[i];
        Vector3 batteryPosition = batteryCmp->getPosition();
        double dx = current_position.x - batteryPosition.x;
        double dz = current_position.z - batteryPosition.z;
        double distance = std::sqrt(dx * dx + dz * dz);

        if (distance <= minDistance) {
            minDistance = distance;
            nearestRechargePosition = batteryPosition;
        }
    }
    return nearestRechargePosition;
}





void BatteryDecorator::goToCharge() {
        if (charge < 1 && !toNearestRecharge) {
            if (toNearestRecharge) {
              delete toNearestRecharge;
            }
            toNearestRecharge = new SpinDecorator
            (new JumpDecorator
            (new BeelineStrategy
            (getPosition(), getPosition())));
        }
        if (charge <= batteryThreshold && charge > 1) {
            if (!toNearestRecharge) {
              toNearestRecharge = new BeelineStrategy(getPosition(),
                rechargePosition);
            }
        }

        double dx = rechargePosition.x - decoratedDrone->getPosition().x;
        double dz = rechargePosition.z - decoratedDrone->getPosition().z;
        double distance = std::sqrt(dx * dx + dz * dz);
        if (distance <= 1) {
          ischarge = true;
        }
}


void BatteryDecorator::update(double dt) {
        if (ischarge) {
          rechargeBattery();
          ischarge = false;
        }

        if (charge >= batteryThreshold) {
          decoratedDrone->update(dt);
          if (!decoratedDrone->getAvailable()) {
            charge -= dt;
            std::cout << "charge" << charge << std::endl;
          }
          if (charge == batteryThreshold) {
            minDistance = 100000.0;
            rechargePosition = getNearestRecharge();
          }
        }

        if (charge < 1) {
            goToCharge();
            if (toNearestRecharge) {
              toNearestRecharge->move(this, dt);
            }
        }
        if (charge <= batteryThreshold && charge >= 1) {
          if (!decoratedDrone->getAvailable()) {
            goToCharge();
            if (toNearestRecharge) {
              toNearestRecharge->move(this, dt);
              charge -= dt;
              std::cout << "gotostation Charge" << charge << std::endl;
            }
            if (toNearestRecharge->isCompleted() || charge <= 1) {
              delete toNearestRecharge;
              toNearestRecharge = nullptr;
            }
          }
    }
}




bool BatteryDecorator::getAvailable() {
  return decoratedDrone->getAvailable();
}
