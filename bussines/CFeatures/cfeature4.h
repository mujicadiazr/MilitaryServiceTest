#ifndef CFEATURE4_H
#define CFEATURE4_H

#include "../cfeature.h"

class CFeature4 : public CFeature
{
    int m_problemasPiel;
public:
    CFeature4();

    int getProblemasPiel();

    int compare(IComparable *obj);
};

#endif // CFEATURE4_H
