#pragma once

#include "LeakedObjectDetector.h"

/*
 copied UDT 2:
 */

struct Supermarket 
{
    int employPerShift { 15 };
    int numActiveChashiers { 5 };
    float salesPerDay { 10000.0f };
    float profitPerDay { 3000.0f };
    int topSellerID { 0 };

    Supermarket();

    ~Supermarket();

    struct Product 
    {
        int productID;
        std::string productName;
        float retailPrice;
        int currentStock;
        int orderedStock;

        Product();

        bool updatePrice(float newPrice);
        int stockPrediction(int salesPeriodInMonths, int salesAmount, int currentStock);
        float priceComparison(Product prodToCompareWith);

        JUCE_LEAK_DETECTOR(Product)
    };                       

    float chargeClient(float productTotal, float taxAmount = 0.21f, float discount = 0);
    bool restockProducts(Product prod, int restockQuantity);
    void bakeBread(int breadType, int bakeQuantity);

    void checkCashiers(int cashierAmount);

    void usingThis();

    JUCE_LEAK_DETECTOR(Supermarket)
};
