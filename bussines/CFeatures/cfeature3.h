#ifndef CFEATURE3_H
#define CFEATURE3_H

#include "../cfeature.h"
#include "../../common/enums.h"

class CFeature3 : public CFeature
{
public:
    CFeature3();

    int getAnalisisPsicologico();

    int compare(IComparable *obj);
};

#endif // CFEATURE3_H
