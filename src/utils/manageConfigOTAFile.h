#ifndef MANAGECONFIGOTAFILE_H
#define MANAGECONFIGOTAFILE_H
#include <Arduino.h>
// #include "SPIFFS.h"
// #include "LittleFS.h"
#include "FS.h"
#include <vector>
#include "FileSystem.h"
#ifndef USE_ARDUINOJSON7_DEPENDENCY
#include "../ArduinoJson-v6.18.3.h"
#else
#include <ArduinoJson.h>
#endif
// typedef std::vector<String> ListFileString;

class manageConfigOTAFile
{
private:
    const char *configOTAFilePath = "/configOTAFile.json";
    const char *lastedOTAPath = "/lastedOTAFile.json";
#if ARDUINOJSON_VERSION_MAJOR >= 7
    // Code สำหรับ Version 7
    JsonDocument OTAdoc;
#else
    // Code สำหรับ Version 6
    StaticJsonDocument<512> OTAdoc;
#endif
    // StaticJsonDocument<512> OTAdoc;

public:
    void beginFileSystem(boolean formatIfFail = true);
    boolean checkFileOTA();
    boolean checkLastedOTA();
    boolean createConfigFileOTA();
    boolean createLastedOTA();
    String readConfigFileOTA();
    String readLastedOTA();
    JsonObject readObjectConfigFileOTA();
    JsonObject readObjectLastedOTA();
    String readSpacificFromConfFile(String readKey);
    boolean saveProfileOTA(JsonObject dataOTA, String stateOTA);
    boolean saveLastedOTA(String lastedDataOTA);
    boolean saveSuccessOrFail(String stateOTA);
    boolean compareFirmwareOTA(JsonObject dataOTA);        // using for incoming without check update
    boolean compareFirmwareIsUpToDate(JsonObject dataOTA); // using when incoming by check update
};
extern manageConfigOTAFile configOTAFile;
#endif