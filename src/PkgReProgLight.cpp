#include "PkgReProgLight.h"

int ReProgLight::init(void){
    Serial.begin(115200);
    Serial.println("ReProgLights initialised");
}