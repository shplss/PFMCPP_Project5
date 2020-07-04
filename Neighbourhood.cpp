#include "Neighbourhood.h"

Neighbourhood::Neighbourhood() 
{ 
    
}

Neighbourhood::~Neighbourhood()
{
    Bakery bakeryOnDestruction;

    std::cout << "\nThe Desctruction Bakery made " << bakeryOnDestruction.daySales << " euros today." << std::endl;
}

Bakery Neighbourhood::createNewBakery(int flourBags, int breadAmount, int cakeAmount, float salesDay, int clientDeliveryProd)
{
    Bakery newBakery;

    newBakery.numBagsFlour = flourBags;
    newBakery.XBread_Amount = breadAmount;
    newBakery.XCake_Amount = cakeAmount;
    newBakery.daySales = salesDay;
    newBakery.XClient_totalProdDeliver = clientDeliveryProd;

    return newBakery;
}

Supermarket::Product Neighbourhood::createNewProduct(int id, std::string name, float price, int stock, int stockComing)
{
    Supermarket::Product newProduct;

    newProduct.productID = id;
    newProduct.productName = name;
    newProduct.retailPrice = price;
    newProduct.currentStock = stock;
    newProduct.orderedStock = stockComing;

    return newProduct;
}
