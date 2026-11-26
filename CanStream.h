#ifndef CANSTREAM_H
#define CANSTREAM_H

#include "CanComBiGlobals.h"

class CanStream
{
    public:
        CanStream();

        int8_t populate();

        bool getIsFD(); // allow external set FD-CAN or not
        void setIsFD(bool toSet);

    private:
        std::vector<canFrame> myFrames; // individual frames of the message. Only has length > 1 if multibyte. CAN frames only use 8 bytes.
        std::vector<uint8_t> myStream; // the full string of CAN data

        bool isFD; // set true if setup for FD-CAN
        bool isMultiframe; // set true if message is multiframe 

        // calculate how many bytes will be sent. Can also set isMultiframe based on explicit context (10 0A)
        //   or implicit context (data length longer than allowed by used protocol)
        int32_t checkDataLength();
};

#endif