#pragma once

#include "LeakedObjectDetector.h"

#include "RecStudio.h"

/*
 new UDT 4:
 with 2 member functions
 */

struct StudioComplex
{
    RecStudio mainStudio;

    StudioComplex(RecStudio rec);

    ~StudioComplex();

    void printStudioInfo();
    int buyMicrophones(int quantity);

    void usingThis();

    JUCE_LEAK_DETECTOR(StudioComplex)
};
