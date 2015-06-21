//
// Created by indrek on 21.06.2015.
//

#ifndef PROGRAMMINGPADLIBRARYDEV_COMMANDDELAY_H
#define PROGRAMMINGPADLIBRARYDEV_COMMANDDELAY_H

#include "Command.h"


class CommandDelay : public Command {

private:
    uint32_t m_time_ms;

public:
    CommandDelay(uint32_t time_ms);

    void execute(Callback &done);

};


#endif //PROGRAMMINGPADLIBRARYDEV_COMMANDDELAY_H
