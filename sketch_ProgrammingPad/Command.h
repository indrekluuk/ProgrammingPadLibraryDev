//
// Created by indrek on 17.06.2015.
//

#ifndef PROGRAMMINGPADLIBRARYDEV_COMMAND_H
#define PROGRAMMINGPADLIBRARYDEV_COMMAND_H

#include "Scheduler.h"


class Command {

protected:

    static Scheduler s_commandScheduler;

public:
    virtual void execute(Callback & done) = 0;
    static void stop();
};


#endif //PROGRAMMINGPADLIBRARYDEV_COMMAND_H
