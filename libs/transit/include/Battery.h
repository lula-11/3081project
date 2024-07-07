#ifndef BATTERY_H_
#define BATTERY_H_

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"

/**
 * @class Battery
 * @brief Represents a battery entity in the simulation.
 *
 * This class inherits from IEntity and represents a battery
 * It encapsulates all the functionalities of a battery including updating its state with time.
 */
class Battery : public IEntity {
 private:
        Vector3 destination;

 public:
        /**
        * @brief Construct a new Battery object from a JSON object.
        *
        * The JSON object should provide all necessary information to initialize the battery entity,
        * including its destination.
        *
        * @param obj The JSON object containing battery details.
        */
        Battery(JsonObject& obj);
        /**
        * @brief Get the destination of the battery.
        *
        * This function returns the current destination set for the battery.
        * 
        * @return Vector3 The destination of the battery.
        */
        Vector3 getDestination() const;
        /**
        * @brief Update the battery's state with the passage of time.
        *
        * This function updates the internal state of the battery for a given time step.
        *
        * @param dt The time step to update the battery's state by.
        */
        void update(double dt);
};
#endif
