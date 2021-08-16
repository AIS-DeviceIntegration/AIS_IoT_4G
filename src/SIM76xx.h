#ifndef __SIM76XX_H__
#define __SIM76XX_H__

#include "Arduino.h"
#include "SIMBase.h"
#include "GSMNetwok.h"

class SIM76XX {
    private:
        int rx_pin, tx_pin, pwr_pin;

    public:
        SIM76XX(int rx_pin, int tx_pin, int power_pin) ;

        bool begin() ;
        bool shutdown() ;

        bool AT() ;

        // Modem
        String getIMEI() ;


};

extern SIM76XX GSM;

#endif
