//
// Created by indrek on 18.06.2015.
//

#ifndef PROGRAMMINGPADLIBRARYDEV_MOCKNODEREADER_H
#define PROGRAMMINGPADLIBRARYDEV_MOCKNODEREADER_H

#include "NodeReader.h"


class MockNodeReader : public NodeReader {


public:
    uint16_t getNodeR1(uint8_t nodeId) {
        return 0; //todo
    }

};

#endif //PROGRAMMINGPADLIBRARYDEV_MOCKNODEREADER_H
