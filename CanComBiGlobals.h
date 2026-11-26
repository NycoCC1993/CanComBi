#ifndef CCBGLOBALS_H
#define CCBGLOBALS_H

// C++ includes
#include <iostream>
#include <cstdint>
#include <vector>

// define data sources
typedef enum
{
    FILE = 0,       // indicates something came from the File Parser
    VEHICLE = 1,    // indicates something came from the bus
    INTERNAL = 2    // indicates something came from the software
} dataSource;

typedef struct canFrame
{
    uint8_t lFrameBytes[64];
} canFrame;

#endif