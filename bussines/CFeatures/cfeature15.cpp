#include "cfeature15.h"

CFeature15::CFeature15()
{
    m_description = "Cancer";
}

int CFeature15::getCancer()
{
    return this->m_value.toInt();
}

int CFeature15::compare(IComparable *obj)
{
    if (CFeature15 *temp = dynamic_cast<CFeature15*>(obj)) {              //Si obj es un CFeature15 lo meto en temp
        if (temp->getCancer() == this->getCancer())                                //y si su valor de migrana es igual al mio
            return 1;
    }
    return 0;
}

