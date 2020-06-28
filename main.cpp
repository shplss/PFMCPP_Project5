/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example
 */





#include <iostream>
#include <math.h>
#include "LeakedObjectDetector.h"

/*
 copied UDT 1:
 */

struct RecStudio 
{
    int numMicrophones;
    int numOutboardUnits;
    int sessionPerMonth;
    float multiDayDiscount;
    float revenewPerMonth;

    RecStudio() : numMicrophones(25),
                  numOutboardUnits(30),
                  sessionPerMonth(10),
                  multiDayDiscount(0.2f),
                  revenewPerMonth(6000.0f) {}

    ~RecStudio();

    void recordAlbum(int numMusicians, int genreCode, int amountTime);
    float chargeSession(int hoursUsed, float discount, float extraCosts = 0.0f);
    void testAllEquipment();

    float yearlyRevenew(float monthRevenew, int periodInMonths);

    void usingThis1()
    {
        std::cout << "\nAmount to charge to the studio client is: " << this->chargeSession(20, 0.1f,50.5f) << " euros." << std::endl;
    }

    void usingThis2()
    {
        std::cout << "\nRevenew amount for the year is: " << this->yearlyRevenew(this->revenewPerMonth, 12) << " euros." << std::endl;
    }

    JUCE_LEAK_DETECTOR(RecStudio)
};

struct RecStudioWrapper
{
    RecStudioWrapper(RecStudio* ptr) : ptrToStudio(ptr) {}
    
    ~RecStudioWrapper()
    {
        delete ptrToStudio;
    }

    RecStudio* ptrToStudio = nullptr;

    JUCE_LEAK_DETECTOR(RecStudioWrapper)
};

RecStudio::~RecStudio()
{
    std::cout << "\nRecStudio Destructor." << std::endl;
}

void RecStudio::recordAlbum(int numMusicians, int genreCode, int amountTime)
{
    // Price Preview + Booking

    std::cout << "\nAn album recording with " << numMusicians << " musicians and genre " << genreCode << " has been booked. It will cost approximately " << amountTime * 50.0f << " euros." << std::endl;
}

float RecStudio::chargeSession(int hoursUsed, float discount, float extraCosts)
{
    float hourlyPrice = 50.0f;          // Variable would be created elsewhere
    float sessionPrice = 0.0f;

    sessionPrice = hoursUsed * hourlyPrice + extraCosts;
    sessionPrice -= sessionPrice * discount;

    return sessionPrice;
}

void RecStudio::testAllEquipment()
{
    // Check all equipment available + test procedure

    std::cout << "\n" << numMicrophones << " microphones to be tested. " << numOutboardUnits << " outboard units to be tested." << std::endl;
}

float RecStudio::yearlyRevenew(float monthRevenew, int periodInMonths)
{
    int months = 0;
    float totalRevenew = 0.0f;

    while(months < periodInMonths)
    {
        totalRevenew += monthRevenew;
        ++months;
    }

    return totalRevenew;
}

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

    Supermarket() {}

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

    struct ProductWrapper
    {
        ProductWrapper(Product* ptr) : ptrToProduct(ptr) {}
        
        ~ProductWrapper()
        {
            delete ptrToProduct;
        }

        Product* ptrToProduct = nullptr;

        JUCE_LEAK_DETECTOR(ProductWrapper)
    };              

    float chargeClient(float productTotal, float taxAmount = 0.21f, float discount = 0);
    bool restockProducts(Product prod, int restockQuantity);
    void bakeBread(int breadType, int bakeQuantity);

    void checkCashiers(int cashierAmount);

    void usingThis()
    {
        std::cout << "\nAmount to charge to the supermarket client is: " << this->chargeClient(25.6f) << " euros." << std::endl;
    }

    JUCE_LEAK_DETECTOR(Supermarket)
};

struct SupermarketWrapper
{
    SupermarketWrapper(Supermarket* ptr) : ptrToSupermarket(ptr) {}
    
    ~SupermarketWrapper()
    {
        delete ptrToSupermarket;
    }

    Supermarket* ptrToSupermarket = nullptr;

    JUCE_LEAK_DETECTOR(SupermarketWrapper)
};

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

    Bakery() : numBagsFlour(20),
               XBread_Amount(40),
               XCake_Amount(5),
               daySales(5000.0f),
               XClient_totalProdDeliver(5) {}

    ~Bakery();

    struct Bread 
    {
        std::string name = ""; 
        int units = 0;

        Bread(std::string n, int u) : name(n), units(u) { }

        JUCE_LEAK_DETECTOR(Bread)
    };  

    struct BreadWrapper
    {
        BreadWrapper(Bread* ptr) : ptrToBread(ptr) {}
        
        ~BreadWrapper()
        {
            delete ptrToBread;
        }

        Bread* ptrToBread = nullptr;

        JUCE_LEAK_DETECTOR(BreadWrapper)
    };

    void bakeCake(int cakeType, int bakeQuantity);
    bool deliverBread(int clientID, int orderID, int deliveryTime);
    float foodWaste_Kg(int amountDays);

    Bread makeBread(std::string breadName, int amountBake);

    void usingThis()
    {
        Bread bread = this->makeBread("White Bread", 40);

        std::cout << "\n" << bread.units << " units of " << bread.name << " have just been baked." << std::endl;
    }

    JUCE_LEAK_DETECTOR(Bakery)
};

struct BakeryWrapper
{
    BakeryWrapper(Bakery* ptr) : ptrToBakery(ptr) {}
    
    ~BakeryWrapper()
    {
        delete ptrToBakery;
    }

    Bakery* ptrToBakery = nullptr;

    JUCE_LEAK_DETECTOR(BakeryWrapper)
};

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

/*
 new UDT 4:
 with 2 member functions
 */

struct StudioComplex
{
    RecStudio mainStudio;

    StudioComplex(RecStudio rec) : mainStudio(rec) { }

    ~StudioComplex() 
    { 
        std::cout << "\nStudio Complex no longer exists." << std::endl; 
    }

    void printStudioInfo();
    int buyMicrophones(int quantity);

    void usingThis()
    {
        this->mainStudio.numMicrophones = this->buyMicrophones(5);
        std::cout << "\nNew Microphone Quantity: " << this->mainStudio.numMicrophones << std::endl;
    }

    JUCE_LEAK_DETECTOR(StudioComplex)
};

struct StudioComplexWrapper
{
    StudioComplexWrapper(StudioComplex* ptr) : ptrToStudioComplex(ptr) {}
    
    ~StudioComplexWrapper()
    {
        delete ptrToStudioComplex;
    }

    StudioComplex* ptrToStudioComplex = nullptr;

    JUCE_LEAK_DETECTOR(StudioComplexWrapper)
};

void StudioComplex::printStudioInfo()
{
    //mainStudio = rec;

    std::cout << "\nStudio Information:" << std::endl;

    std::cout << "\n- Microphones: " << mainStudio.numMicrophones << std::endl;
    std::cout << "\n- Outboard Units: " << mainStudio.numOutboardUnits << std::endl;
    std::cout << "\n- Session (per month): " << mainStudio.sessionPerMonth << std::endl;
    std::cout << "\n- Multiple Day Discount: " << mainStudio.multiDayDiscount << std::endl;
    std::cout << "\n- Revenew (per month): " << mainStudio.revenewPerMonth << std::endl;
}

int StudioComplex::buyMicrophones(int quantity)
{
    return mainStudio.numMicrophones += quantity;
}

/*
 new UDT 5:
 with 2 member functions
 */

struct Neighbourhood
{
    Supermarket superMarket;
    Bakery bakery;

    Neighbourhood() { }

    ~Neighbourhood() 
    {
        Bakery bakeryOnDestruction;

        std::cout << "\nThe Desctruction Bakery made " << bakeryOnDestruction.daySales << " euros today." << std::endl;
    }

    Bakery createNewBakery(int flourBags, int breadAmount, int cakeAmount, float salesDay, int clientDeliveryProd);
    Supermarket::Product createNewProduct(int id, std::string name, float price, int stock, int stockComing);

    JUCE_LEAK_DETECTOR(Neighbourhood)
};

struct NeighbourhoodWrapper
{
    NeighbourhoodWrapper(Neighbourhood* ptr) : ptrToNeighbourhood(ptr) {}
    
    ~NeighbourhoodWrapper()
    {
        delete ptrToNeighbourhood;
    }

    Neighbourhood* ptrToNeighbourhood = nullptr;

    JUCE_LEAK_DETECTOR(NeighbourhoodWrapper)
};

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

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()

{
    // RecStudio

    RecStudioWrapper recStudioWrap(new RecStudio());
    recStudioWrap.ptrToStudio->recordAlbum(5, 2, 10);
    recStudioWrap.ptrToStudio->testAllEquipment();

    std::cout << "\nAmount to charge to the studio client is: " << recStudioWrap.ptrToStudio->chargeSession(20, 0.1f,50.5f) << " euros." << std::endl;
    recStudioWrap.ptrToStudio->usingThis1();

    std::cout << "\nRevenew amount for the year is: " << recStudioWrap.ptrToStudio->yearlyRevenew(recStudioWrap.ptrToStudio->revenewPerMonth, 12) << " euros." << std::endl;
    recStudioWrap.ptrToStudio->usingThis2();

    // Supermarket

    SupermarketWrapper supermarketWrap(new Supermarket());
    supermarketWrap.ptrToSupermarket->bakeBread(3, 30);

    std::cout << "\nAmount to charge to the supermarket client is: " << supermarketWrap.ptrToSupermarket->chargeClient(25.6f) << " euros." << std::endl;
    supermarketWrap.ptrToSupermarket->usingThis();

    supermarketWrap.ptrToSupermarket->checkCashiers(supermarketWrap.ptrToSupermarket->numActiveChashiers);

    Supermarket::ProductWrapper prod1(new Supermarket::Product());
    Supermarket::ProductWrapper prod2(new Supermarket::Product());

    prod1.ptrToProduct->productID = 1;
    prod1.ptrToProduct->productName = "Bananas";
    prod1.ptrToProduct->retailPrice = 1.95f;
    prod1.ptrToProduct->currentStock = 40;
    prod1.ptrToProduct->orderedStock = 20;

    // Bakery

    BakeryWrapper bakeryWrap(new Bakery());
    bakeryWrap.ptrToBakery->bakeCake(1, 4);
    bakeryWrap.ptrToBakery->deliverBread(50, 724, 1345);

    Bakery::BreadWrapper breadWrap(new Bakery::Bread("White Bread", 40));

    auto bread = bakeryWrap.ptrToBakery->makeBread("White Bread", 40);

    std::cout << "\n" << breadWrap.ptrToBread->units << " units of " << breadWrap.ptrToBread->name << " have just been baked." << std::endl;
    bakeryWrap.ptrToBakery->usingThis();

    // StudioComplex

    StudioComplexWrapper studioComplexWrap(new StudioComplex(*recStudioWrap.ptrToStudio));

    studioComplexWrap.ptrToStudioComplex->printStudioInfo();
    studioComplexWrap.ptrToStudioComplex->mainStudio.numMicrophones = studioComplexWrap.ptrToStudioComplex->buyMicrophones(5);
    std::cout << "\nNew Microphone Quantity: " << studioComplexWrap.ptrToStudioComplex->mainStudio.numMicrophones << std::endl;
    studioComplexWrap.ptrToStudioComplex->usingThis();

    // Neighbourhood

    NeighbourhoodWrapper neighbourhoodWrap(new Neighbourhood());

    Bakery bakeryA = neighbourhoodWrap.ptrToNeighbourhood->createNewBakery(40, 30, 10, 3000.0f, 15);
    Bakery bakeryB = neighbourhoodWrap.ptrToNeighbourhood->createNewBakery(20, 10, 5, 1500.0f, 5);
    
    Supermarket::Product prodA = neighbourhoodWrap.ptrToNeighbourhood->createNewProduct(0, "Soap", 2.99f, 100, 50);
    Supermarket::Product prodB = neighbourhoodWrap.ptrToNeighbourhood->createNewProduct(1, "Shampoo", 2.59f, 200, 30);

    std::cout << "good to go!" << std::endl;

}



