//
// Created by indrek on 20.06.2015.
//

#include "CommandDoNothing.h"

void CommandDoNothing::execute(Callback & callback) {
    callback.call();
}
