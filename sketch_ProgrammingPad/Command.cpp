//
// Created by indrek on 17.06.2015.
//

#include "Command.h"



Scheduler Command::s_commandScheduler;

void Command::stop() {
    s_commandScheduler.stop();
}

