//
// Created by indrek on 18.06.2015.
//

#include "gtest/gtest.h"
#include "Arduino.h"
#include "Scheduler.h"
#include "ProgramSub.h"
#include "mock/MockNodeReader.h"



static uint16_t CMD_1_R1 = 1000;


class SubExecutionTest : public ::testing::Test {

private:

protected:

    MockNodeReader m_nodeReader;
    NodeExecuterConfiguration<1> m_nodeExecuter;

    CommandDoNothing m_command;

    SubExecutionTest()
    {
        m_nodeExecuter.initCommand(0, CMD_1_R1, m_command);
    }

    virtual void SetUp() {
    }



    void runProgram(uint32_t time_ms) {
        for (int i=0; i<time_ms; i++) {
            arduino_increase_millis(1);
            Scheduler::run();
        }
    }


};



TEST_F(SubExecutionTest, testExecuteSubNodes) {
    ProgramSub sub;
    sub.init(0, 5, m_nodeReader, m_nodeExecuter);

};


