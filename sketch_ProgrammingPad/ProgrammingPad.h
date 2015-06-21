//
// Created by indrek on 17.06.2015.
//

#ifndef PROGRAMMABLEBOT_PROGRAMMINGPAD_H
#define PROGRAMMABLEBOT_PROGRAMMINGPAD_H

#include "global.h"
#include "NodeReader.h"
#include "NodeExecuter.h"
#include "Command.h"
#include "ProgramSub.h"


template<size_t commandCount, size_t subCount>
class ProgrammingPad {

private:
    HardwareNodeReader m_nodeReader;
    NodeExecuterConfiguration<commandCount> m_nodeExecuter;
    ProgramSub m_subs[subCount];


public:
    ProgrammingPad(
            uint8_t p1,
            uint8_t p2,
            uint8_t p3,
            uint8_t p4,
            uint8_t p5,
            uint8_t p6,
            uint16_t r2
    ) :
            m_nodeReader(r2)
    {
    }


    ProgramSub * initSub(uint8_t index, uint8_t firstNodeId, uint8_t nodeCount) {
        if (index < subCount) {
            m_subs[index].init(firstNodeId, nodeCount, m_nodeReader, m_nodeExecuter);
            return &m_subs[index];
        }
        return nullptr;
    }


    void initCommand(uint8_t index, uint16_t r1, Command & command) {
        m_nodeExecuter.initCommand(index, r1, command);
    }



};


#endif //PROGRAMMABLEBOT_PROGRAMMINGPAD_H
