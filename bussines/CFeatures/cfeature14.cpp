#include "cfeature14.h"

CFeature14::CFeature14()
{
    m_description = "Migrana";
}

int CFeature14::getMigrana()
{
    return this->m_value.toInt();
}

int CFeature14::compare(IComparable *obj)
{
    if (CFeature14 *temp = dynamic_cast<CFeature14*>(obj)) {              //Si obj es un CFeature14 lo meto en temp
        if (temp->getMigrana() == this->getMigrana())                      //y si su valor de migrana es igual al mio
            return 1;
    }
    return 0;
}


