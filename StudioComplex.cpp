#include "StudioComplex.h"

StudioComplex::~StudioComplex()
{ 
    std::cout << "\nStudio Complex no longer exists." << std::endl; 
}

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

void StudioComplex::usingThis()
{
    this->mainStudio.numMicrophones = this->buyMicrophones(5);
    std::cout << "\nNew Microphone Quantity: " << this->mainStudio.numMicrophones << std::endl;
}
