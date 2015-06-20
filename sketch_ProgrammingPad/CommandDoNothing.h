//
// Created by indrek on 20.06.2015.
//

#ifndef PROGRAMMINGPADLIBRARYDEV_COMMANDDONOTHING_H
#define PROGRAMMINGPADLIBRARYDEV_COMMANDDONOTHING_H

#include "Command.h"


class CommandDoNothing : public Command{

public:


    void execute(Callback & done);
};


#endif //PROGRAMMINGPADLIBRARYDEV_COMMANDDONOTHING_H
