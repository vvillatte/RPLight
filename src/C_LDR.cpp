#include "C_LDR.h"

C_LDR::C_LDR(){
    p_itsILDR = (I_LDR*) new (LDR);
    p_itsILDR->set_ItsCLDR(this);
}

C_LDR::~C_LDR(){
    delete (p_itsILDR);
}

C_LDR* C_LDR::get_ItsCLDR(void){
    return this;
}

I_LDR* C_LDR::get_ItsILDR(void){
    return p_itsILDR;
}

void C_LDR::set_ItsILDR(I_LDR* arg){
    p_itsILDR = arg;
}

LDR::LDR(){
    its_Pin = A0;
}

LDR::~LDR(){

}

I_LDR* LDR::get_ItsILDR(void){
    return (I_LDR*) this;
}

void LDR::set_ItsCLDR(C_LDR* arg){
    p_itsCLDR = arg;
}

int LDR::init(int pin){
    int res = -1;
    its_Pin = pin;
    Serial.println("LDR initialised");
    res = 1;
    return res;
}

int LDR::get_RawVoltage(){
    return analogRead(its_Pin);
}

float LDR::get_Voltage(){
    return (5.0 * (float) this->get_RawVoltage() / 1023.0);
}