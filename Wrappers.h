#pragma once

#include "LeakedObjectDetector.h"

#include "Supermarket.h"
#include "Bakery.h"

struct RecStudio;
struct StudioComplex;
struct Neighbourhood;

struct RecStudioWrapper
{
    RecStudioWrapper(RecStudio*);
    
    ~RecStudioWrapper();

    RecStudio* ptrToStudio = nullptr;

    JUCE_LEAK_DETECTOR(RecStudioWrapper)
};

struct SupermarketWrapper
{
    SupermarketWrapper(Supermarket*);
    
    ~SupermarketWrapper();

    Supermarket* ptrToSupermarket = nullptr;

    JUCE_LEAK_DETECTOR(SupermarketWrapper)
};

struct ProductWrapper
{
    ProductWrapper(Supermarket::Product*);
    
    ~ProductWrapper();

    Supermarket::Product* ptrToProduct = nullptr;

    JUCE_LEAK_DETECTOR(ProductWrapper)
};

struct BakeryWrapper
{
    BakeryWrapper(Bakery*);
    
    ~BakeryWrapper();

    Bakery* ptrToBakery = nullptr;

    JUCE_LEAK_DETECTOR(BakeryWrapper)
};

struct BreadWrapper
{
    BreadWrapper(Bakery::Bread*);
    
    ~BreadWrapper();

    Bakery::Bread* ptrToBread = nullptr;

    JUCE_LEAK_DETECTOR(BreadWrapper)
};

struct StudioComplexWrapper
{
    StudioComplexWrapper(StudioComplex*);
    
    ~StudioComplexWrapper();

    StudioComplex* ptrToStudioComplex = nullptr;

    JUCE_LEAK_DETECTOR(StudioComplexWrapper)
};

struct NeighbourhoodWrapper
{
    NeighbourhoodWrapper(Neighbourhood*);
    
    ~NeighbourhoodWrapper();

    Neighbourhood* ptrToNeighbourhood = nullptr;

    JUCE_LEAK_DETECTOR(NeighbourhoodWrapper)
};
