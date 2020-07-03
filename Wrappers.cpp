#include "Wrappers.h"

#include "RecStudio.h"
#include "StudioComplex.h"
#include "Neighbourhood.h"

RecStudioWrapper::RecStudioWrapper(RecStudio* ptr) : ptrToStudio(ptr) { }

RecStudioWrapper::~RecStudioWrapper()
{
    delete ptrToStudio;
}

SupermarketWrapper::SupermarketWrapper(Supermarket* ptr) : ptrToSupermarket(ptr) {}

SupermarketWrapper::~SupermarketWrapper()
{
    delete ptrToSupermarket;
}

ProductWrapper::ProductWrapper(Supermarket::Product* ptr) : ptrToProduct(ptr) {}

ProductWrapper::~ProductWrapper()
{
    delete ptrToProduct;
}

BakeryWrapper::BakeryWrapper(Bakery* ptr) : ptrToBakery(ptr) {}

BakeryWrapper::~BakeryWrapper()
{
    delete ptrToBakery;
}

BreadWrapper::BreadWrapper(Bakery::Bread* ptr) : ptrToBread(ptr) {}

BreadWrapper::~BreadWrapper()
{
    delete ptrToBread;
}

StudioComplexWrapper::StudioComplexWrapper(StudioComplex* ptr) : ptrToStudioComplex(ptr) {}

StudioComplexWrapper::~StudioComplexWrapper()
{
    delete ptrToStudioComplex;
}

NeighbourhoodWrapper::NeighbourhoodWrapper(Neighbourhood* ptr) : ptrToNeighbourhood(ptr) {}

NeighbourhoodWrapper::~NeighbourhoodWrapper()
{
    delete ptrToNeighbourhood;
}
