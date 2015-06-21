//
// Created by indrek on 17.06.2015.
//

#ifndef PROGRAMMINGPADLIBRARYDEV_NODEREADER_H
#define PROGRAMMINGPADLIBRARYDEV_NODEREADER_H


#include "global.h"

class NodeReader {

public:
    virtual uint16_t getNodeR1(uint8_t nodeId) = 0;

};



class HardwareNodeReader : public NodeReader {

private:

    uint16_t m_r2;

public:
    HardwareNodeReader(uint16_t r2);

    uint16_t getNodeR1(uint8_t nodeId);

};


#endif //PROGRAMMINGPADLIBRARYDEV_NODEREADER_H
