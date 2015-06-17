//
// Created by indrek on 17.06.2015.
//

#include "NodeExecuter.h"


NodeExecuter::NodeExecuter(NodeReader &nodeReader, CommandSelector &commandSelector) :
        m_nodeReader(nodeReader), m_commandSelector(commandSelector)
{

}


void NodeExecuter::execute(uint8_t nodeId, Callback &done) {
    // todo read from nodeReader and execute command from commandSelector;
    done.call();
}

