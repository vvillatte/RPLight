#include "PkgRPLight.h"

RPLight::RPLight(){
    p_ItsCLDR = new(C_LDR);
}

RPLight::~RPLight(){
    delete (p_ItsCLDR);
}

int RPLight::init(void){
    int res = 0;

    // Start serial communication
    Serial.begin(115200);

    if(NULL != p_ItsCLDR){
        p_ItsILDR = p_ItsCLDR->get_ItsILDR();
        res = p_ItsILDR->init(A0);
        Serial.println("RPLights initialised");
    }
    else{
        Serial.println("RPLights failed to initialise");
        res = -1;
    }

    return res;
}

int RPLight::run(void){
    static boolean bRunning = false;
    static int previous_time = 0, time = 0, time_difference = 0;
    if(false == bRunning) {
        Serial.println("RPLights is running");
        previous_time = millis();
        bRunning = true;
    }

    time = millis();
    time_difference = time - previous_time;
    if(1000 < time_difference){
        Serial.println(p_ItsILDR->get_Resistance());
    }
}