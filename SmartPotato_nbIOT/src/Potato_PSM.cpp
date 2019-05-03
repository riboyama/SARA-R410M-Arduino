#include <Arduino.h>
#include <Wire.h>
#include <Sodaq_wdt.h>
#include <ArduinoLowPower.h>
#include "Potato_PSM.h"

Sodaq_LSM303AGR accelerometer;
double threshold = 1.5;

PowerSave::PowerSave(Sodaq_LSM303AGR accMeter) :
    accelerometer(accMeter)
 {
     
};
void PowerSave::configSleepMode() {
    Wire.begin();
    accelerometer.disableAccelerometer();
    accelerometer.disableMagnetometer();

    pinMode(LED_BUILTIN,  OUTPUT);
    pinMode(MAG_INT,  OUTPUT);
    pinMode(GPS_ENABLE,  OUTPUT);

    digitalWrite(LED_BUILTIN, LOW);   // led low=off, high=on
    digitalWrite(MAG_INT, LOW);       // we need to make this low otherwise this pin on the LSM303AGR starts leaking current
    digitalWrite(GPS_ENABLE, LOW);    // low=poweredoff, high=poweredon
}

void PowerSave::detachUSB() {
    SerialUSB.flush();
    SerialUSB.end();
    USBDevice.detach();
    USB->DEVICE.CTRLA.reg &= ~USB_CTRLA_ENABLE; // Disable USB
}

void PowerSave::enableAcceleroInt(voidFuncPtr callback) {
    pinMode(ACCEL_INT1, INPUT_PULLDOWN);
    accelerometer.rebootAccelerometer();
    delay(1000);
    accelerometer.enableAccelerometer(accelerometer.LowPowerMode, accelerometer.HrNormalLowPower25Hz, accelerometer.XYZ, accelerometer.Scale2g, false);
    attachInterrupt();
    LowPower.attachInterruptWakeup(ACCEL_INT1, callback, RISING);
}


void PowerSave::enableSleepModeTimed(int millis) {
    detachUSB();
    LowPower.sleep();
}

void PowerSave::attachInterrupt() {
    accelerometer.enableInterrupt1(accelerometer.ZHigh, threshold, 0, accelerometer.MovementRecognition);
}

void PowerSave::disableInterrupts() {
    accelerometer.disableInterrupt1();
}