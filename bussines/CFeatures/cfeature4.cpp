#include "cfeature4.h"

CFeature4::CFeature4()
{
    m_description = "Problemas de la piel";
}

int CFeature4::getProblemasPiel()
{
    return this->m_value.toInt();
}

int CFeature4::compare(IComparable *obj)
{
    if (CFeature4 *temp = dynamic_cast<CFeature4*>(obj)) {  //Si obj es un CFeature4 lo meto en temp
        if (temp->getProblemasPiel() == this->getProblemasPiel())    //y si su valor de problemas de la piel es igual al mio
            return 1;
    }
    return 0;
}
