#pragma once

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

    RecStudio();

    ~RecStudio();

    void recordAlbum(int numMusicians, int genreCode, int amountTime);
    float chargeSession(int hoursUsed, float discount, float extraCosts = 0.0f);
    void testAllEquipment();

    float yearlyRevenew(float monthRevenew, int periodInMonths);

    void usingThis1();
    void usingThis2();

    JUCE_LEAK_DETECTOR(RecStudio)
};
