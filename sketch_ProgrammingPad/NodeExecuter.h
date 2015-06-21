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

public:

    void execute(uint16_t nodeR1, Callback & done);

public:
    virtual Command & getCommand(uint16_t r1) = 0;

};





template<uint8_t commandCount>
class NodeExecuterConfiguration : public NodeExecuter {

private:
    uint16_t m_commandR1[commandCount];
    Command * m_commands[commandCount];
    CommandDoNothing m_commandDoNothing;


public:

    NodeExecuterConfiguration() {
        for (uint8_t i=0; i<commandCount; i++) {
            m_commandR1[i] = 0;
            m_commands[i] = &m_commandDoNothing;
        }
    }

    void initCommand(uint8_t index, uint16_t r1, Command & command) {
        if (index < commandCount) {
            m_commandR1[index] = r1;
            m_commands[index] = &command;
        }
    }

    Command & getCommand(uint16_t r1) {
        if (r1 == 0) {
            return m_commandDoNothing;
        } else {
            return findClosest(r1);
        }
    }


private:

    Command & findClosest(uint16_t r1) {
        uint8_t commandIndex = commandCount;
        int32_t minDifference = 100000;

        for (uint8_t i=0; i<commandCount; i++) {
            if (isCommandInitialized(i)) {
                int32_t diff = getDifference(m_commandR1[i], r1);
                if (diff < minDifference) {
                    minDifference = diff;
                    commandIndex = i;
                }
            }
        }

        return commandIndex < commandCount ? *m_commands[commandIndex] : m_commandDoNothing;
    }

    bool isCommandInitialized(uint8_t index) {
        return m_commandR1[index] > 0;
    }

    int32_t getDifference(int32_t ra, int32_t rb) {
        return abs(ra - rb);
    }

};


#endif //PROGRAMMINGPADLIBRARYDEV_NODEEXECUTER_H
