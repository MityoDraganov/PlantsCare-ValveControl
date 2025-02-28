#ifndef VALVECONTROL_H
#define VALVECONTROL_H

#include  "../Control/Control.h"
#include <Arduino.h>

class ValveControl : public Control
{
public:
    ValveControl();  // Constructor declaration

    void init(int gpioPin) override;         // Initialize the valve control (GPIO pin setup)
    int getONValue() const override;         // Return the ON value for the control (low level signal)
    int getOFFValue() const override;        // Return the OFF value for the control (high level signal)
    const std::string &getDependentSensor() const override;  // Return the sensor's serial number

    // Optionally, you can add more functions to control the valve

private:
    static const int RELAY_ON = LOW;    // Low signal activates the relay (logic 0)
    static const int RELAY_OFF = HIGH;   // High signal deactivates the relay (logic 1)
    std::string dependentSensorSerial;   // Serial number of the dependent sensor (could be a unique ID or other)
};

#endif // VALVECONTROL_H
