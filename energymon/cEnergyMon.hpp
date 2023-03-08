#ifndef __cEnergy_Monitor_hpp__
#define __cEnergy_Monitor_hpp__

#define DEFAULT_READ_TIMEOUT 1000
#define ERROR_VALUE -1.0

const int
DEFAULT_ADDR = 0xF8;
/*
  0xF8 is used as the general address
  (The address range of the slave is 0x01-0xF7)
*/

struct emCommand {
  int command;
  int addr[4];
  int data;
  int crc;
};

class cEnergyMon {
  public:
    cEnergyMon();
    ~cEnergyMon();

  private:
    int emSRC(int *data);
};

#endif
