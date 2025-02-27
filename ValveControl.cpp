#include "ValveControl.h"

ValveControl::ValveControl() : dependentSensorSerial("12345")  // Constructor with default sensor serial
{
    // Initialize any other members if necessary
}

void ValveControl::init(int gpioPin)
{
    gpio = gpioPin;  // Store the GPIO pin for the control
    pinMode(gpio, OUTPUT);  // Set the GPIO pin as output for controlling the relay
    digitalWrite(gpio, RELAY_OFF);  // Start with the relay off (set the pin to HIGH)
}

int ValveControl::getONValue() const
{
    return RELAY_ON;  // Low value to activate the relay
}

int ValveControl::getOFFValue() const
{
    return RELAY_OFF;  // High value to deactivate the relay
}

const std::string &ValveControl::getDependentSensor() const
{
    return dependentSensorSerial;  // Return the serial number of the dependent sensor
}
