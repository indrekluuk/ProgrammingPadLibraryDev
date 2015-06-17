//
// Created by indrek on 17.06.2015.
//

#ifndef PROGRAMMINGPADLIBRARYDEV_NODEREADER_H
#define PROGRAMMINGPADLIBRARYDEV_NODEREADER_H


#include "global.h"

class NodeReader {

public:
    virtual uint16_t getNodeR2(uint8_t nodeId) = 0;

};



class HardwareNodeReader : public NodeReader {


public:
    uint16_t getNodeR2(uint8_t nodeId) {
        return 0; //todo
    }

};


#endif //PROGRAMMINGPADLIBRARYDEV_NODEREADER_H
