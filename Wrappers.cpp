#include "Wrappers.h"

RecStudioWrapper::~RecStudioWrapper()
{
    delete ptrToStudio;
}

SupermarketWrapper::~SupermarketWrapper()
{
    delete ptrToSupermarket;
}

ProductWrapper::~ProductWrapper()
{
    delete ptrToProduct;
}

BakeryWrapper::~BakeryWrapper()
{
    delete ptrToBakery;
}

BreadWrapper::~BreadWrapper()
{
    delete ptrToBread;
}

StudioComplexWrapper::~StudioComplexWrapper()
{
    delete ptrToStudioComplex;
}

NeighbourhoodWrapper::~NeighbourhoodWrapper()
{
    delete ptrToNeighbourhood;
}
