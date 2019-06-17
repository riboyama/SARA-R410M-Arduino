/*
    Copyright (c) 2019 Niek Beukema.  All rights reserved.

    This file is part of the unofficial r410m library.

    This program is free software: you can redistribute it and/or modify 
    it under the terms of the GNU Affero General Public License as 
    published by the Free Software Foundation, either version 3 of 
    the License, or (at your option) any later version. 
    
    This program is distributed in the hope that it will be useful, 
    but WITHOUT ANY WARRANTY; without even the implied warranty of 
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
    See the GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public 
    License along with this program. If not, see
    <https://www.gnu.org/licenses/>. 
*/
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
