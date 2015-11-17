#ifndef ICOMPARABLE_H
#define ICOMPARABLE_H

/**
 * Interfaz que define que un objeto se puede comparar
 */

class IComparable
{
public:
    IComparable();
    virtual int compare(IComparable *obj) = 0;
};

#endif // ICOMPARABLE_H
