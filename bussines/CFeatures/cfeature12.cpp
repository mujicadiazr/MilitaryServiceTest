#include "cfeature12.h"

CFeature12::CFeature12()
{
    m_description = "Problemas Digestivos Cronicos";
}

int CFeature12::compare(IComparable *obj)
{
    if (CFeature12 *temp = dynamic_cast<CFeature12*>(obj)) {              //Si obj es un CFeature11 lo meto en temp
        if (temp->getProblemasDigestivos() == this->getProblemasDigestivos())      //y si su valor de asmatico cronico es igual al mio
            return 1;
    }
    return 0;
}

int CFeature12::getProblemasDigestivos()
{
    return this->m_value.toInt();
}
