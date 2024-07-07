#ifndef BATTERY_FACTORY_H_
#define BATTERY_FACTORY_H_

#include <vector>

#include "Battery.h"
#include "IEntityFactory.h"

/**
 * @class BatteryFactory
 * @brief Factory class for creating Battery entities.
 *
 * BatteryFactory is a concrete factory class that implements the IEntityFactory interface.
 *
 */
class BatteryFactory : public IEntityFactory {
 public:
        /**
        * @brief Destructor for BatteryFactory class.
        */
        virtual ~BatteryFactory() {}

        /**
        * @brief Creates a Battery entity based on the provided JSON object configuration.
        *
        * Analyzes the JSON object and if the type is "battery", constructs and returns a new Battery instance.
        * If the type is not "battery", returns a nullptr.
        *
        * @param entity A JSON object containing the configuration data for the Battery.
        * @return IEntity* A pointer to the created Battery object, or nullptr if the type does not match.
        */
        IEntity* CreateEntity(JsonObject& entity);
};
#endif
