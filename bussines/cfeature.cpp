#include "cfeature.h"



CFeature::CFeature()
{
}
void CFeature::setDescription(QString descrip){
    this->m_description = descrip;
}
void CFeature::setValue(QVariant value){
    this->m_value = value;
}
void CFeature::setTestor(int testor){
    this->m_testor = testor;
}

void CFeature::setDefault(QVariant value, int testor){
    setValue(value);
    setTestor(testor);
    return;
}
QVariant CFeature::getValue(){
    return this->m_value;
}
QString CFeature::getDescription(){
    return this->m_description;
}
int CFeature::getTestor(){
    return this->m_testor;
}
