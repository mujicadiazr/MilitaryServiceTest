#include "cfeature13.h"

CFeature13::CFeature13()
{
    m_description = "Problemas de hemorroide";
}

int CFeature13::compare(IComparable *obj)
{
    if (CFeature13 *temp = dynamic_cast<CFeature13*>(obj)) {              //Si obj es un CFeature13 lo meto en temp
        if (temp->getHemorroides() == this->getHemorroides())                      //y si su valor de hemorroide es igual al mio
            return 1;
    }
    return 0;
}

int CFeature13::getHemorroides()
{
    return this->m_value.toInt();
}

