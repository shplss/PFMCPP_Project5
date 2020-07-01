#include "RecStudio.h"

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

void RecStudio::usingThis1()
{
    std::cout << "\nAmount to charge to the studio client is: " << this->chargeSession(20, 0.1f,50.5f) << " euros." << std::endl;
}

void RecStudio::usingThis2()
{
    std::cout << "\nRevenew amount for the year is: " << this->yearlyRevenew(this->revenewPerMonth, 12) << " euros." << std::endl;
}
