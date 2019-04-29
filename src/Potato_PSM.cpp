#include <Arduino.h>
#include <Wire.h>
#include <Sodaq_wdt.h>
#include <Sodaq_LSM303AGR.h>
#include <ArduinoLowPower.h>

Sodaq_LSM303AGR accelerometer;

void configSleepMode() {
    Wire.begin();
    accelerometer.disableAccelerometer();
    accelerometer.disableMagnetometer();

    pinMode(LED_BUILTIN,  OUTPUT);
    pinMode(MAG_INT,  OUTPUT);
    pinMode(GPS_ENABLE,  OUTPUT);

    digitalWrite(LED_BUILTIN, LOW);   // led low=off, high=on
    digitalWrite(MAG_INT, LOW);       // we need to make this low otherwise this pin on the LSM303AGR starts leaking current
    digitalWrite(GPS_ENABLE, LOW);    // low=poweredoff, high=poweredon
    
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

    SerialUSB.flush();
    SerialUSB.end();
    USBDevice.detach();
    USB->DEVICE.CTRLA.reg &= ~USB_CTRLA_ENABLE; // Disable USB
}

void enableAcceleroInt() {

}

void enableSleepMode() {

}

void enableSleepModeTimed() {
    LowPower.sleep(120000);
}

void disableInterrupts() {

}