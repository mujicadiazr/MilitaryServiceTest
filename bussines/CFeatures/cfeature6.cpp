#include "cfeature6.h"

CFeature6::CFeature6()
{
    m_description = "Prueba Dental";
}

int CFeature6::getPruebaDental()
{
    return this->m_value.toInt();
}

int CFeature6::compare(IComparable *obj)
{
    if (CFeature6 *temp = dynamic_cast<CFeature6*>(obj)) {  //Si obj es un CFeature6 lo meto en temp
        if (temp->getPruebaDental() == this->getPruebaDental())    //y si su valor de la prueba dental es igual al mio
            return 1;
    }
    return 0;
}
