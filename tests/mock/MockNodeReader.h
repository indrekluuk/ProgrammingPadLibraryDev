//
// Created by indrek on 18.06.2015.
//

#ifndef PROGRAMMINGPADLIBRARYDEV_MOCKNODEREADER_H
#define PROGRAMMINGPADLIBRARYDEV_MOCKNODEREADER_H

#include "NodeReader.h"
#include <map>


class MockNodeReader : public NodeReader {

private:
    std::map<uint8_t, uint16_t> idR1Map;

public:

    void setNode(uint8_t nodeId, uint16_t r1) {
        idR1Map[nodeId] = r1;
    }

    uint16_t getNodeR1(uint8_t nodeId) {
        uint16_t r1 = idR1Map.count(nodeId) > 0 ?
                      idR1Map[nodeId] :
                      (uint16_t)0;

        return r1;
    }


};

#endif //PROGRAMMINGPADLIBRARYDEV_MOCKNODEREADER_H
