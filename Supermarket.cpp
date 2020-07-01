#include "Supermarket.h"

Supermarket::~Supermarket()
{
    std::cout << "\nSupermarket Destructor." << std::endl;
}

Supermarket::Product::Product()
{
    productID = 0;
    productName = "";
    retailPrice = 0.0f;
    currentStock = 0;
    orderedStock = 0;
}

bool Supermarket::Product::updatePrice(float newPrice)
{
    if(std::fabs(this->retailPrice - newPrice) < 0.005f)
    {
        this->retailPrice = newPrice;
        return true;
    }

    return false;
}

int Supermarket::Product::stockPrediction(int salesPeriodInMonths, int salesAmount, int curStock)
{
    salesPeriodInMonths = 6;
    salesAmount = 30;
    curStock = 5;

    int stockNeeded = 0;

    // Prediction based on sales

    return stockNeeded;
}

float Supermarket::Product::priceComparison(Supermarket::Product prodToCompareWith)
{
    float priceDiff = 0.0f;

    priceDiff = retailPrice - prodToCompareWith.retailPrice;

    return priceDiff;
}

float Supermarket::chargeClient(float productTotal, float taxAmount, float discount)
{
    float totalCharge = 0.0f;

    totalCharge = productTotal + (productTotal * taxAmount);
    totalCharge -= totalCharge * discount;

    return totalCharge;
}

bool Supermarket::restockProducts(Supermarket::Product prod, int restockQuantity)
{
    // Method to contact supplier

    bool contactSuccessful = true;              // Success simulation

    if(contactSuccessful)
    {
        prod.orderedStock = restockQuantity;
        return contactSuccessful;
    }

    return !contactSuccessful;
}

void Supermarket::bakeBread(int breadType, int bakeQuantity)
{
    // Start baking method

    std::cout << "\n" << bakeQuantity << " units of bread type " << breadType << " have been added to the queue." << std::endl;
}

void Supermarket::checkCashiers(int cashierAmount)
{
    for(int i = 0; i < cashierAmount; ++i)
    {
        // Prints name of cashier

        std::cout << "\n" << i + 1 << " - Cashier Name: Placeholder" << std::endl;
    }
}

void Supermarket::usingThis()
{
    std::cout << "\nAmount to charge to the supermarket client is: " << this->chargeClient(25.6f) << " euros." << std::endl;
}
