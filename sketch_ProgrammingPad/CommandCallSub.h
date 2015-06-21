//
// Created by indrek on 21.06.2015.
//

#ifndef PROGRAMMINGPADLIBRARYDEV_COMMANDCALLSUB_H
#define PROGRAMMINGPADLIBRARYDEV_COMMANDCALLSUB_H

#include "Command.h"
#include "ProgramSub.h"

class CommandCallSub : public Command {

private:

    ProgramSub & m_programSub;

public:

    CommandCallSub(ProgramSub & sub);

    void execute(Callback &done);
};


#endif //PROGRAMMINGPADLIBRARYDEV_COMMANDCALLSUB_H
