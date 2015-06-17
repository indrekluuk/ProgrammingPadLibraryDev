//
// Created by indrek on 17.06.2015.
//

#ifndef PROGRAMMINGPADLIBRARYDEV_NODEEXECUTER_H
#define PROGRAMMINGPADLIBRARYDEV_NODEEXECUTER_H

#include "global.h"
#include "NodeReader.h"
#include "CommandSelector.h"
#include "Callback.h"


class NodeExecuter {

private:
    NodeReader & m_nodeReader;
    CommandSelector & m_commandSelector;

public:
    NodeExecuter(NodeReader & nodeReader, CommandSelector & commandSelector);

    void execute(uint8_t nodeId, Callback & done);

};


#endif //PROGRAMMINGPADLIBRARYDEV_NODEEXECUTER_H
