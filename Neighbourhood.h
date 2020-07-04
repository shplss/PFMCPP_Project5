#pragma once

#include "LeakedObjectDetector.h"

#include "Supermarket.h"
#include "Bakery.h"

/*
 new UDT 5:
 with 2 member functions
 */

struct Neighbourhood
{
    Supermarket superMarket;
    Bakery bakery;

    Neighbourhood();

    ~Neighbourhood();

    Bakery createNewBakery(int flourBags, int breadAmount, int cakeAmount, float salesDay, int clientDeliveryProd);
    Supermarket::Product createNewProduct(int id, std::string name, float price, int stock, int stockComing);

    JUCE_LEAK_DETECTOR(Neighbourhood)
};
