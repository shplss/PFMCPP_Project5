#pragma once

#include "LeakedObjectDetector.h"

#include "RecStudio.h"
#include "Supermarket.h"
#include "Bakery.h"
#include "StudioComplex.h"
#include "Neighbourhood.h"

struct RecStudioWrapper
{
    RecStudioWrapper(RecStudio* ptr) : ptrToStudio(ptr) {}
    
    ~RecStudioWrapper();

    RecStudio* ptrToStudio = nullptr;

    JUCE_LEAK_DETECTOR(RecStudioWrapper)
};

struct SupermarketWrapper
{
    SupermarketWrapper(Supermarket* ptr) : ptrToSupermarket(ptr) {}
    
    ~SupermarketWrapper();

    Supermarket* ptrToSupermarket = nullptr;

    JUCE_LEAK_DETECTOR(SupermarketWrapper)
};

struct ProductWrapper
{
    ProductWrapper(Supermarket::Product* ptr) : ptrToProduct(ptr) {}
    
    ~ProductWrapper();

    Supermarket::Product* ptrToProduct = nullptr;

    JUCE_LEAK_DETECTOR(ProductWrapper)
};

struct BakeryWrapper
{
    BakeryWrapper(Bakery* ptr) : ptrToBakery(ptr) {}
    
    ~BakeryWrapper();

    Bakery* ptrToBakery = nullptr;

    JUCE_LEAK_DETECTOR(BakeryWrapper)
};

struct BreadWrapper
{
    BreadWrapper(Bakery::Bread* ptr) : ptrToBread(ptr) {}
    
    ~BreadWrapper();

    Bakery::Bread* ptrToBread = nullptr;

    JUCE_LEAK_DETECTOR(BreadWrapper)
};

struct StudioComplexWrapper
{
    StudioComplexWrapper(StudioComplex* ptr) : ptrToStudioComplex(ptr) {}
    
    ~StudioComplexWrapper();

    StudioComplex* ptrToStudioComplex = nullptr;

    JUCE_LEAK_DETECTOR(StudioComplexWrapper)
};

struct NeighbourhoodWrapper
{
    NeighbourhoodWrapper(Neighbourhood* ptr) : ptrToNeighbourhood(ptr) {}
    
    ~NeighbourhoodWrapper();

    Neighbourhood* ptrToNeighbourhood = nullptr;

    JUCE_LEAK_DETECTOR(NeighbourhoodWrapper)
};
