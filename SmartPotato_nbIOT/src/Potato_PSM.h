#ifndef POTATO_PSM_H
#define POTATO_PSM_H
#include <Sodaq_LSM303AGR.h>

class PowerSave {
    public:
        PowerSave(Sodaq_LSM303AGR accMeter);
        void configSleepMode();
        void enableAcceleroInt(voidFuncPtr callback);
        void enableSleepModeTimed(int millis);
        void disableInterrupts();
        void attachInterrupt();
    private:
        void detachUSB();
        Sodaq_LSM303AGR accelerometer;
};

#endif
