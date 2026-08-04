/*
Copyright (c) 2020, Advanced Wireless Network
All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
* Neither the name of the copyright holder nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
support SIMCOM SIM7600E(AIS 4G Board)

Author:(POC Device Magellan team)
Create Date: 25 April 2022.
Modified: 31 Jul 2026.
*/
#ifndef MAGELLAN_SIM7600E_MQTT_h
#define MAGELLAN_SIM7600E_MQTT_h
#include <Arduino.h>
#include "./MAGELLAN_MQTT_4G_BOARD.h"
#include <Update.h>
class MAGELLAN_SIM7600E_MQTT : public MAGELLAN_MQTT_4G_BOARD
{

private:
  bool usesInjectedClient = false;

public:
  MAGELLAN_SIM7600E_MQTT() = default;
  explicit MAGELLAN_SIM7600E_MQTT(Client &client)
      : MAGELLAN_MQTT_4G_BOARD(client), usesInjectedClient(true) {}

  void begin(MagellanSetting setting = ::setting)
  {
    if (usesInjectedClient)
    {
      MAGELLAN_MQTT_TEMP::begin(setting);
      MAGELLAN_MQTT_TEMP::clientConfig.add("libVersion", String(lib_model_device) + "(extClient)-" + String(lib_ver));
      MAGELLAN_MQTT_TEMP::clientConfig.add("preferredMode", "ExternalClient");
      MAGELLAN_MQTT_TEMP::clientConfig.save();
      return;
    }
    MAGELLAN_MQTT_4G_BOARD::begin(setting);
  }

  void loop() override
  {
    if (usesInjectedClient)
    {
      MAGELLAN_MQTT_TEMP::loop();
      return;
    }
    MAGELLAN_MQTT_4G_BOARD::loop();
  }

protected:
};
#endif
