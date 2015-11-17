#ifndef CFACTORYFEATURE_H
#define CFACTORYFEATURE_H

#include <QVariant>

#include "./bussines/cfeature.h"
#include "./bussines/CFeatures/cfeature1.h"
#include "./bussines/CFeatures/cfeature2.h"
#include "./bussines/CFeatures/cfeature3.h"
#include "./bussines/CFeatures/cfeature4.h"
#include "./bussines/CFeatures/cfeature5.h"
#include "./bussines/CFeatures/cfeature6.h"
#include "./bussines/CFeatures/cfeature7.h"
#include "./bussines/CFeatures/cfeature8.h"
#include "./bussines/CFeatures/cfeature9.h"
#include "./bussines/CFeatures/cfeature10.h"
#include "./bussines/CFeatures/cfeature11.h"
#include "./bussines/CFeatures/cfeature12.h"
#include "./bussines/CFeatures/cfeature13.h"
#include "./bussines/CFeatures/cfeature14.h"
#include "./bussines/CFeatures/cfeature15.h"

class CFactoryFeature
{
public:
    CFactoryFeature();
    static CFeature* createFeature(int, QVariant, int);
};

#endif // CFACTORYFEATURE_H
