#ifndef CANSTREAM_H
#define CANSTREAM_H

#include <cstdint>
#include <vector>

class CanStream
{
    public:
        CanStream();

        int8_t populate();

    private:
        std::vector<uint8_t[8]> myFrames; // individual frames of the message. Only has length > 1 if multibyte.
        std::vector<uint8_t[64]> myFramesFD; // CAN-FD supports 64 bits per frame instead of 8.
        std::vector<uint8_t> myStream; // the full string of CAN data

        bool isFD; // set true if setup for FD-CAN
        bool isMultiframe; // set true if message is multiframe 

        // calculate how many bytes will be sent. Can also set isMultiframe based on explicit context (10 0A)
        //   or implicit context (data length longer than allowed by used protocol)
        int32_t checkDataLength();
};

#endif