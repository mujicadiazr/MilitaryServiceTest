#include "cfeature1.h"

CFeature1::CFeature1()
{
    m_description = "Pies planos";
}

int CFeature1::compare(IComparable *obj)
{
    if (CFeature1 *temp = dynamic_cast<CFeature1*>(obj)) {  //Si obj es un CFeature1 lo meto en temp
        if (temp->isPiesPlanos() == this->isPiesPlanos())          //y si su valor de pies planos es igual al mio
            return 1;
    }
    return 0;
}


int CFeature1::isPiesPlanos()
{
    return this->m_value.toInt();
}
