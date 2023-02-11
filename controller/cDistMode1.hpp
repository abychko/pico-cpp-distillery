#ifndef __cDistMode1_hpp__
#define __cDistMode1_hpp__

#include <cMode.hpp>

#ifdef LANG_RUSSIAN
#define DIST1MODE "\x13\x50\x65\xB6\xB8\xBC\x20\xEF\xBF\xB4\x6F\xBD\x61\x20\x43\xC3\x70\xE5\x61\x14"
#define TEMP "\x54\x65\xBC\xBE\x65\x70\x61\xBF\x79\x70\x61:"
#else
#define DIST1MODE "Mode: 1st distillation"
#define TEMP      "Temperature:"
#endif

class cDistMode1 : public cMode
  {
  public:
    cDistMode1();
    void Start();
  };
#endif
