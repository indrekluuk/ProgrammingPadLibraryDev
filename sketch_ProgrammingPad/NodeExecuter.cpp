//
// Created by indrek on 17.06.2015.
//

#include "NodeExecuter.h"


void NodeExecuter::execute(uint16_t nodeR1, Callback & done) {
    getCommand(nodeR1).execute(done);
}

