#include "ValveControl.h"
#include "../ControlManager/ControlManager.h"

static ValveControl valveControl;

ValveControl::ValveControl() : dependentSensorSerial("12345")  // Constructor with default sensor serial
{
    ControlManager::registerControl(this); 
}

void ValveControl::init(int gpioPin)
{
    gpio = gpioPin;  // Store the GPIO pin for the control
    pinMode(gpio, OUTPUT);  // Set the GPIO pin as output for controlling the relay
    digitalWrite(gpio, RELAY_OFF);  // Start with the relay off (set the pin to HIGH)
}

const std::string &ValveControl::getDependentSensor() const
{
    return dependentSensorSerial;  // Return the serial number of the dependent sensor
}


void ValveControl::start()
{
    digitalWrite(gpio, RELAY_ON);  // Activate the relay (set the pin to LOW)
}

void ValveControl::stop()
{
    digitalWrite(gpio, RELAY_OFF);  // Deactivate the relay (set the pin to HIGH)
}

void ValveControl::setMinValue(int minValue)
{
    this->minValue = minValue;  // Set the minimum value
}

int ValveControl::getMinValue() const
{
    return minValue;  // Return the minimum value
}

void ValveControl::setMaxValue(int maxValue)
{
    this->maxValue = maxValue;  // Set the maximum value
}

int ValveControl::getMaxValue() const
{
    return maxValue;  // Return the maximum value
}

const std::string &ValveControl::getType() const
{
    static const std::string type = "ValveControl";  // Return the type of the control
    return type;
}