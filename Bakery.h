#pragma once

#include "LeakedObjectDetector.h"

/*
 copied UDT 3:
 */

struct Bakery
{
    int numBagsFlour;
    int XBread_Amount;
    int XCake_Amount;
    float daySales;
    int XClient_totalProdDeliver;

    Bakery();

    ~Bakery();

    struct Bread 
    {
        std::string name = ""; 
        int units = 0;

        Bread(std::string n, int u) : name(n), units(u) { }

        JUCE_LEAK_DETECTOR(Bread)
    };  

    void bakeCake(int cakeType, int bakeQuantity);
    bool deliverBread(int clientID, int orderID, int deliveryTime);
    float foodWaste_Kg(int amountDays);

    Bread makeBread(std::string breadName, int amountBake);

    void usingThis();

    JUCE_LEAK_DETECTOR(Bakery)
};
