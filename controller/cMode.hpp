#ifndef __cMode_hpp__
#define __cMode_hpp__

#include "pico/float.h"
#include <cDS18B20.hpp>
#include <cDisplay.hpp>
#include <eStatus.hpp>
#include <cEnergyMon.hpp>
#include <memory>

#include <map>
extern std::map<float, float> vapour;
extern std::map<float, float> liquid;
extern float maxTemp;
extern float minTemp;

constexpr uint _on  = 1;
constexpr uint _off = 0;

#ifdef LANG_RUSSIAN
#define TEMP "\x54\x45\x4D\xA8:"
#define FINISHING "\xA4\x61\xB3\x65\x70\xC1\x65\xBD\xB8\x65\x10"
#define FINISHED "\xA4\x61\xB3\x65\x70\xC1\x65\xBD\x6F!  "
#define ELECTRICITY "CET\x08:"
#define STATUS     "\x43\xBF\x61\xBF\x79\x63:"
#define RUNNINGSTR "\x42\xC3\xBE\x6F\xBB\xBD\xC7\x65\xBF\x63\xC7"
#else
#define TEMP      "TEMP:"
#define FINISHING "Finishing... "
#define FINISHED "\xEE All Done! \xEE"
#define ELECTRICITY "Power:"
#define STATUS      "Status:"
#define RUNNINGSTR  "In Progress"
#endif

class cMode
  {
  public:
    cMode();
    virtual void Start();
    void turnOffCooling();
    void Stop();
    void setDisplay(std::shared_ptr<cDisplay> _display);
#ifdef DEBUG
    void printValues();
#endif
  protected:
    void updateTemp();
    void updatePower();
    void updateStatus();
    void fillDisplayFields();
    void updateAlcConcentration(const std::map<float, float>&);
    float getAlcohol(const std::map<float, float>&);
//
    std::unique_ptr<cEnergyMon> mEnergyMon;
    std::unique_ptr<cDS18B20> mDS18B20;
    float                     stopTemp;
    float                     currentTemp;
    float                     volts;
    float                     ampers;
    std::shared_ptr<cDisplay> lcd_display;
    enum eStatus              mStatus;
  };
#endif
