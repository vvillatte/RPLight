#ifndef _LDR_H
#define _LDR_H

#include <Arduino.h>

class C_LDR;
class I_LDR;
class LDR;

class C_LDR{
    private:
    I_LDR* p_itsILDR = NULL;

    public:
    C_LDR();
    ~C_LDR();
    C_LDR* get_ItsCLDR(void);
    I_LDR* get_ItsILDR(void);
    void set_ItsILDR(I_LDR* arg);
};

class I_LDR{
    protected:
    C_LDR* p_itsCLDR = NULL;

    public:
    virtual I_LDR* get_ItsILDR(void);
    virtual void set_ItsCLDR(C_LDR* arg);
    virtual int init(int pin);
    virtual float get_Voltage(void);
};

class LDR : public I_LDR{
    private:
    int its_Pin = A0;

    int get_RawVoltage(void);
    
    public:
    LDR();
    ~LDR();
    I_LDR* get_ItsILDR(void);
    void set_ItsCLDR(C_LDR* arg);
    int init(int pin);
    float get_Voltage(void);
};
#endif