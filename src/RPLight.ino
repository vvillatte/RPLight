#include "PkgRPLight.h"

RPLight* itsRPLight = new(RPLight);

void setup(void){
    itsRPLight->init();
}

void loop(void){
    itsRPLight->run();
}