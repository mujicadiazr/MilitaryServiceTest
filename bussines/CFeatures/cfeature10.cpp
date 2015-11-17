#include "cfeature10.h"

CFeature10::CFeature10()
{
    m_description = "Asmatico Cronico";
}

int CFeature10::compare(IComparable *obj)
{
    if (CFeature10 *temp = dynamic_cast<CFeature10*>(obj)) {              //Si obj es un CFeature10 lo meto en temp
        if (temp->getAsmaticoCronico() == this->getAsmaticoCronico())              //y si su valor de asmatico cronico es igual al mio
            return 1;
    }
    return 0;
}

int CFeature10::getAsmaticoCronico()
{
    return this->m_value.toInt();
}
