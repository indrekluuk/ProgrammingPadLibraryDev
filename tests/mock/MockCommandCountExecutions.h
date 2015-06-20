//
// Created by indrek on 20.06.2015.
//

#ifndef PROGRAMMINGPADLIBRARYDEV_MOCKCOMMANDCOUNTEXECUTIONS_H
#define PROGRAMMINGPADLIBRARYDEV_MOCKCOMMANDCOUNTEXECUTIONS_H

#include "Command.h"


class MockCommandCountExecutions : public Command{

private:
    uint16_t m_executionCount;

public:
    MockCommandCountExecutions() : m_executionCount(0)
    {
    }

    void execute(Callback & done) {
        m_executionCount++;
        done.call();
    }


    uint16_t getExecutinoCount() {
        return m_executionCount;
    }

};


#endif //PROGRAMMINGPADLIBRARYDEV_MOCKCOMMANDCOUNTEXECUTIONS_H
