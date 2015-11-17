#include "cobject.h"

CObject::CObject()
{
}

CFeature *CObject::getFeature(int index)
{
    if (index >= 0 && index < 15)
        return m_features.at(index);
    return nullptr;
}

bool CObject::addFeature(CFeature *feature)
{
    m_features.append(feature);
    return true;
}

void CObject::setClass(EClass p_class)
{
    m_class = p_class;
}

int CObject::compare(IComparable *obj)
{
    int ret = 0;

    if (CObject *temp = dynamic_cast<CObject*>(obj))   //Si obj es un CObject lo meto en temp
        for (int i = 0; i < m_features.size(); ++i)    //Recorro todos mis rasgos
            if (temp->getFeature(i)->getTestor())      // Si el rasgo i es testor
                ret += m_features.at(i)->compare(temp->getFeature(i));  //Sumo la comparacion en ret

    return ret;

}

EClass CObject::getClass()
{
    return m_class;
}
