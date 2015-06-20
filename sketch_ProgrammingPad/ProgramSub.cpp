//
// Created by indrek on 14.06.2015.
//

#include "ProgramSub.h"


ProgramSub::ProgramSub() :
        m_firstNodeId(0),
        m_nodeCount(0),
        m_nodeExecuter(nullptr),
        m_executionSequencer(this, &ProgramSub::executeNode)
{
}

void ProgramSub::init(uint8_t firstNodeId, uint8_t nodeCount, NodeReader & nodeReader, NodeExecuter & nodeExecuter) {
    m_firstNodeId = firstNodeId;
    m_nodeCount = nodeCount;
    m_nodeReader = &nodeReader;
    m_nodeExecuter = &nodeExecuter;
}

void ProgramSub::start(Callback * done) {
    m_executionSequencer.start(done);
}

void ProgramSub::stop() {
    m_executionSequencer.stop();
}

void ProgramSub::executeNode(Sequencer &sequencer, uint8_t step) {
    uint8_t nodeIndex = step - (uint8_t)1;
    if (nodeIndex < m_nodeCount) {
        uint16_t nodeR1 = m_nodeReader->getNodeR1(getNodeId(nodeIndex));
        m_nodeExecuter->execute(nodeR1, sequencer.nextWhenDone());
    }
}

uint8_t ProgramSub::getNodeId(uint8_t nodeIndex) {
    return m_firstNodeId+nodeIndex;
}

