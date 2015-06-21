//
// Created by indrek on 17.06.2015.
//

#ifndef PROGRAMMINGPADLIBRARYDEV_NODEEXECUTER_H
#define PROGRAMMINGPADLIBRARYDEV_NODEEXECUTER_H

#include "global.h"

#include "CommandDoNothing.h"
#include "NodeReader.h"
#include "Callback.h"
#include <stdlib.h>


class NodeExecuter {

protected:
    CommandDoNothing m_commandDoNothing;

public:

    void execute(uint16_t nodeR1, Callback & done);

    CommandDoNothing & getCommandDoNothing();

public:
    virtual Command & getCommand(uint16_t r1) = 0;

};





template<uint8_t initCommandCount>
class NodeExecuterConfiguration : public NodeExecuter {

private:
    uint8_t m_commandCount;
    uint16_t m_commandR1[initCommandCount + 1];
    Command * m_commands[initCommandCount + 1];

public:

    NodeExecuterConfiguration() : m_commandCount(initCommandCount + (uint8_t)1) {
        for (uint8_t i=0; i<m_commandCount; i++) {
            m_commandR1[i] = 0;
            m_commands[i] = &m_commandDoNothing;
        }
    }

    void initCommand(uint8_t index, uint16_t r1, Command & command) {
        if (index < initCommandCount) {
            m_commandR1[index] = r1;
            m_commands[index] = &command;
        }
    }

    Command & getCommand(uint16_t r1) {
        return findClosest(r1);
    }

private:

    Command & findClosest(uint16_t r1) {
        uint8_t commandIndex = m_commandCount - (uint8_t)1;
        int32_t minDifference = 100000;

        for (uint8_t i=0; i<m_commandCount; i++) {
            int32_t diff = getDifference(m_commandR1[i], r1);
            if (diff < minDifference) {
                minDifference = diff;
                commandIndex = i;
            }
        }

        return *m_commands[commandIndex];
    }

    int32_t getDifference(int32_t ra, int32_t rb) {
        return abs(ra - rb);
    }

};


#endif //PROGRAMMINGPADLIBRARYDEV_NODEEXECUTER_H
