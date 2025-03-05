#ifndef VALVECONTROL_H
#define VALVECONTROL_H

#include  "../Control/Control.h"
#include <Arduino.h>

class ValveControl : public Control
{
public:
    ValveControl();  // Constructor declaration

    void setMinValue(int minValue) override;  // Set the minimum value for the control
    void setMaxValue(int maxValue) override;  // Set the maximum value for the control

    void start() override;  // Start the valve control
    void stop() override;   // Stop the valve control

    void init(int gpioPin) override;         // Initialize the valve control (GPIO pin setup)
    int getMinValue() const override;         // Return the ON value for the control (low level signal)
    int getMaxValue() const override;        // Return the OFF value for the control (high level signal)
    const std::string &getDependentSensor() const override;  // Return the sensor's serial number

    // Optionally, you can add more functions to control the valve

    const std::string& getType() const override;


private:
    static const int RELAY_ON = LOW;    // Low signal activates the relay (logic 0)
    static const int RELAY_OFF = HIGH;   // High signal deactivates the relay (logic 1)
    std::string dependentSensorSerial;   // Serial number of the dependent sensor (could be a unique ID or other)
    int minValue;                        // Minimum value for the control
    int maxValue;                        // Maximum value for the control
};

#endif // VALVECONTROL_H
