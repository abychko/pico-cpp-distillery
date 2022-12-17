#ifndef __eExit_Statuses_hpp__
#define __eExit_Statuses_hpp__

enum eExit
  {
  eDS18B20Err,
  eHeaterErr
  };

struct exitStatus
  {
  eExit _status;
  char _string1[20];
  char _string2[20];
  char _string3[20];
  char _string4[20];
  };
#endif
