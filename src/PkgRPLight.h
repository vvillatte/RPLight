#ifndef _PKG_RPLight_H
#define _PKG_RPLight_H

class RPLight;

#include "C_LDR.h"

class RPLight{
    private:
    C_LDR* p_ItsCLDR = NULL;
    I_LDR* p_ItsILDR = NULL;

    public:
    RPLight();
    ~RPLight();
    int init(void);
    int run(void);
};

#endif