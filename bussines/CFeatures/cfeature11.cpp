#include "cfeature11.h"

CFeature11::CFeature11()
{
    m_description = "Cardiopatia";
}


int CFeature11::compare(IComparable *obj)
{
    if (CFeature11 *temp = dynamic_cast<CFeature11*>(obj)) {              //Si obj es un CFeature11 lo meto en temp
        if (temp->getCardiopatia() == this->getCardiopatia())                      //y si su valor de asmatico cronico es igual al mio
            return 1;
    }
    return 0;
}

int CFeature11::getCardiopatia()
{
    return this->m_value.toInt();
}
