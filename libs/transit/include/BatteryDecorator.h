#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_

#include "BeelineStrategy.h"
#include "Drone.h"
#include <vector>
#include "IEntity.h"
#include "SimulationModel.h"

// battery capacity
// 300 is roughly enough to cover one worst-case trip from full

/**
 * @class BatteryDecorator
 * @brief Decorator class that adds battery management to Drone entities.
 *
 * BatteryDecorator extends the functionality of a Drone.
 * 
 */
class BatteryDecorator : public IEntity {
 private:
    double charge;
    double batteryThreshold = 36.0;
    Drone* decoratedDrone;
    IStrategy* toNearestRecharge = nullptr;
    bool ischarge = false;
    double minDistance;
    Vector3 rechargePosition;

 public:
    /**
     * @brief Construct a new Battery Decorator object
     * 
     * @param entity The Drone object to decorate with battery functionality.
     */
    BatteryDecorator(Drone* entity);

    /**
     * @brief Destroy the Battery Decorator object
     * 
     * Cleans up any allocated resources, including the decorated Drone and strategy objects.
     */
    virtual ~BatteryDecorator();

    /**
     * @brief Get the current battery charge level.
     * 
     * @return The current charge of the battery.
     */
    double getCharge();

    /**
     * @brief Recharge the drone's battery.
     */
    void rechargeBattery();

    /**
     * @brief Command the drone to find and go to the nearest recharge station.
     */
    Vector3 getNearestRecharge();

    /**
     * @brief Command the drone to find and go to the next delivery.
     */
    void getNextDelivery();

    /**
     * @brief Command the drone to charge or perform other actions when
     * the battery is below a certain point.
     */
    void goToCharge();

    /**
     * @brief Update the drone's state for the simulation time step.
     * 
     * @param dt The time.
     */
    void update(double dt);

    /**
     * @brief Check if the drone is available for tasks.
     * 
     * @return boolean value If the drone is available.
     */
    bool getAvailable();



     /**
   * @brief Links this drone to a simulation model,
   *  giving it access to the model's public variables
   *  and functions.
   * @param[in] model The simulation model to link.
   */
    virtual void linkModel(SimulationModel* model) {
        this->model = model;
        decoratedDrone->linkModel(model);
    }

  /**
   * @brief Gets the ID of the drone.
   * @return The ID of the drone.
   */
    virtual int getId() const {
        return decoratedDrone->getId();
    }

  /**
   * @brief Gets the position of the drone.
   * @return The position of the drone.
   */
    virtual Vector3 getPosition() const {
        return decoratedDrone->getPosition();
    }

  /**
   * @brief Gets the direction of the drone.
   * @return The direction of the drone.
   */
    virtual Vector3 getDirection() const {
        return decoratedDrone->getDirection();
    }

  /**
   * @brief Gets the details of the drone.
   * @return The details of the drone.
   */
    virtual const JsonObject& getDetails() const {
        return decoratedDrone->getDetails();
    }

  /**
   * @brief Gets the color of the drone
   * @return The color of the drone
   */
    virtual std::string getColor() const {
        return decoratedDrone->getColor();
    }

  /**
   * @brief Gets the name of the drone
   * @return The name of the drone
   */
    virtual std::string getName() const {
        return decoratedDrone->getName();
    }

  /**
   * @brief Gets the speed of the drone.
   * @return The speed of the drone.
   */
    virtual double getSpeed() const {
        return decoratedDrone->getSpeed();
    }

  /**
   * @brief Sets the position of the drone.
   * @param pos_ The desired position of the drone.
   */
    virtual void setPosition(Vector3 pos_) {
        decoratedDrone->setPosition(pos_);
    }

  /**
   *@brief Set the direction of the drone.
   *@param dir_ The new direction of the drone.
   */
    virtual void setDirection(Vector3 dir_) {
        decoratedDrone->setDirection(dir_);
    }

  /**
   * @brief Sets the color of the drone
   * @param col_ The new color of the drone
   */
    virtual void setColor(std::string col_) {
        decoratedDrone->setColor(col_);
    }

  /**
   * @brief Rotate the drone around y axis.
   * @param angle The angle to rotate the drone by.
   */
    virtual void rotate(double angle) {
        decoratedDrone->rotate(angle);
    }
};

#endif
