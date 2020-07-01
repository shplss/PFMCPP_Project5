#include "Bakery.h"

Bakery::~Bakery()
{
    std::cout << "\nBakery Destructor." << std::endl;
}

void Bakery::bakeCake(int cakeType, int bakeQuantity)
{
    // Start baking method

    std::cout << "\n" << bakeQuantity << " cakes of type " << cakeType << " have been added to the baking queue. There are " << numBagsFlour << " bags of flour left." << std::endl;
}

bool Bakery::deliverBread(int clientID, int orderID, int deliveryTime)
{
    // Start delivery method

    std::cout << "\nFor client (ID) " << clientID << " and order (ID) " << orderID << " there are " << XClient_totalProdDeliver << " products to be delivered at " << deliveryTime << "." << std::endl;

    return true;                                // Success simulation
}

float Bakery::foodWaste_Kg(int amountDays)
{
    amountDays = 15;

    float totalFoodWaste = 0.0f;

    // Calculate food waste

    return totalFoodWaste;
}

Bakery::Bread Bakery::makeBread(std::string breadName, int amountBake)
{
    Bakery::Bread bread(breadName, 0);

    while(bread.units < amountBake)
    {
        bread.units += 1;

        if(bread.units >= amountBake)
        {
            return bread;
        }
    }

    return Bread {breadName, 0};
}

void Bakery::usingThis()
{
    Bread bread = this->makeBread("White Bread", 40);

    std::cout << "\n" << bread.units << " units of " << bread.name << " have just been baked." << std::endl;
}
