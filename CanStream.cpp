// The purpose of the CanStream is to store an array of CAN-FD data.

#include "CanStream.h"

// initialize
CanStream::CanStream()
{
    this->setIsFD(false); // reset FD-CAN status
    this->isMultiframe = false; // reset multiframe indicator

    // reset frame and data vectors
    this->myFrames.clear();
    this->myStream.clear();
}

// text
int8_t CanStream::populate()
{
    return 0;
}