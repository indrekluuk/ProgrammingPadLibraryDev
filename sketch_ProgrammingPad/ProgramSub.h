//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMINGPADLIBRARYDEV_PROGRAMSUB_H
#define PROGRAMMINGPADLIBRARYDEV_PROGRAMSUB_H

#include "Sequencer.h"
#include "NodeReader.h"
#include "NodeExecuter.h"

class ProgramSub {

private:
    uint8_t m_firstNodeId;
    uint8_t m_nodeCount;
    NodeReader * m_nodeReader;
    NodeExecuter * m_nodeExecuter;

    MethodSequencer<ProgramSub> m_executionSequencer;

public:
    ProgramSub();

    void init(uint8_t firstNodeId, uint8_t nodeCount, NodeReader & nodeReader, NodeExecuter & nodeExecuter);

    void start(Callback* done);
    void stop();

private:

    void executeNode(Sequencer& sequencer, uint8_t step);
    uint8_t getNodeId(uint8_t nodeIndex);

};




#endif //PROGRAMMINGPADLIBRARYDEV_PROGRAMSUB_H
