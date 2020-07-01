/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */

#include <iostream>
#include <math.h>
#include "LeakedObjectDetector.h"

#include "RecStudio.h"
#include "Supermarket.h"
#include "Bakery.h"
#include "StudioComplex.h"
#include "Neighbourhood.h"
#include "Wrappers.h"

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

    ProductWrapper prod1(new Supermarket::Product());
    ProductWrapper prod2(new Supermarket::Product());

    prod1.ptrToProduct->productID = 1;
    prod1.ptrToProduct->productName = "Bananas";
    prod1.ptrToProduct->retailPrice = 1.95f;
    prod1.ptrToProduct->currentStock = 40;
    prod1.ptrToProduct->orderedStock = 20;

    // Bakery

    BakeryWrapper bakeryWrap(new Bakery());
    bakeryWrap.ptrToBakery->bakeCake(1, 4);
    bakeryWrap.ptrToBakery->deliverBread(50, 724, 1345);

    BreadWrapper breadWrap(new Bakery::Bread("White Bread", 40));

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
 