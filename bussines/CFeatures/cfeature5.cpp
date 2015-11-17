#include "cfeature5.h"

CFeature5::CFeature5()
{
    m_description = "Problemas de los testiculos";
}

int CFeature5::getProblemaTesticulos()
{
    return this->m_value.toInt();
}

int CFeature5::compare(IComparable *obj)
{
    if (CFeature5 *temp = dynamic_cast<CFeature5*>(obj)) {  //Si obj es un CFeature5 lo meto en temp
        if (temp->getProblemaTesticulos() == this->getProblemaTesticulos())    //y si su valor de problemas de los testiculos es igual al mio
            return 1;
    }
    return 0;
}
