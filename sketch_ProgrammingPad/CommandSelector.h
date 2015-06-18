//
// Created by indrek on 17.06.2015.
//

#ifndef PROGRAMMINGPADLIBRARYDEV_COMMANDSELECTOR_H
#define PROGRAMMINGPADLIBRARYDEV_COMMANDSELECTOR_H

#include "global.h"
#include "Command.h"


class CommandSelector {

};



template<size_t commandCount>
class CommandSelectorList : public CommandSelector {

private:
    uint16_t commandR1[commandCount];
    Command * commands[commandCount];



public:

    void initCommand(uint8_t index, uint16_t r1, Command & command) {
        if (index < commandCount) {
            commandR1[index] = r1;
            commands[index] = &command;
        }
    }


};


#endif //PROGRAMMINGPADLIBRARYDEV_COMMANDSELECTOR_H
