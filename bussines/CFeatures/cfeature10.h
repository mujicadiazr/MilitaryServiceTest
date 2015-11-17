#ifndef CFEATURE10_H
#define CFEATURE10_H
#include <QVariant>

#include "../cfeature.h"

class CFeature10 : public CFeature
{
public:
    CFeature10();

    int getAsmaticoCronico();

    int compare(IComparable *obj);
};

#endif // CFEATURE10_H
