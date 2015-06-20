//
// Created by indrek on 17.06.2015.
//

#ifndef PROGRAMMINGPADLIBRARYDEV_COMMAND_H
#define PROGRAMMINGPADLIBRARYDEV_COMMAND_H

#include "Callback.h"


class Command {

public:
    virtual void execute(Callback & callback) = 0;

};


#endif //PROGRAMMINGPADLIBRARYDEV_COMMAND_H
