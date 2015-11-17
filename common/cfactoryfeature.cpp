#include "cfactoryfeature.h"

CFactoryFeature::CFactoryFeature()
{
}
CFeature* CFactoryFeature::createFeature(int featureNumber, QVariant value, int testor){
    CFeature* defaultObj;

    if (featureNumber == 1){
       defaultObj = new CFeature1();
       defaultObj->setDefault(value, testor);

    }else if (featureNumber == 2){
        defaultObj= new CFeature2();
        defaultObj->setDefault(value, testor);

    }else if (featureNumber == 3){
        defaultObj = new CFeature3();
        defaultObj->setDefault(value, testor);

    }else if (featureNumber == 4){
        defaultObj = new CFeature4();
        defaultObj->setDefault(value, testor);

    }else if (featureNumber == 5){
        defaultObj = new CFeature5();
        defaultObj->setDefault(value, testor);

    }else if (featureNumber == 6){
        defaultObj = new CFeature6();
        defaultObj->setDefault(value, testor);

    }else if (featureNumber == 7){
        defaultObj = new CFeature7();
        defaultObj->setDefault(value, testor);

    }else if (featureNumber == 8){
        defaultObj = new CFeature8();
        defaultObj->setDefault(value, testor);

    }else if (featureNumber == 9){
        defaultObj = new CFeature9();
        defaultObj->setDefault(value, testor);

    }else if (featureNumber == 10){
        defaultObj = new CFeature10();
        defaultObj->setDefault(value, testor);

    }else if (featureNumber == 11){
        defaultObj = new CFeature11();
        defaultObj->setDefault(value, testor);

    }else if (featureNumber == 12){
        defaultObj = new CFeature12();
        defaultObj->setDefault(value, testor);

    }else if (featureNumber == 13){
        defaultObj = new CFeature13();
        defaultObj->setDefault(value, testor);

    }else if (featureNumber == 14){
        defaultObj = new CFeature14();
        defaultObj->setDefault(value, testor);

    }else if (featureNumber == 15){
        defaultObj = new CFeature15();
        defaultObj->setDefault(value, testor);
    }
    return defaultObj;
}
