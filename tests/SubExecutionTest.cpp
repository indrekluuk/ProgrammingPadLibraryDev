//
// Created by indrek on 18.06.2015.
//

#include "gtest/gtest.h"
#include "Arduino.h"
#include "Scheduler.h"
#include "ProgramSub.h"
#include "mock/MockNodeReader.h"
#include "mock/MockCommandCountExecutions.h"



static uint16_t CMD_EXEC_CNT_R1 = 1000;


class SubExecutionTest : public ::testing::Test {

private:

protected:

    MockNodeReader m_nodeReader;
    NodeExecuterConfiguration<1> m_nodeExecuter;

    MockCommandCountExecutions m_commandCountExecutions;

    SubExecutionTest()
    {
        m_nodeExecuter.initCommand(0, CMD_EXEC_CNT_R1, m_commandCountExecutions);
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
    m_nodeReader.setNode(0, CMD_EXEC_CNT_R1);
    m_nodeReader.setNode(1, CMD_EXEC_CNT_R1);
    m_nodeReader.setNode(2, CMD_EXEC_CNT_R1);

    ProgramSub sub;
    sub.init(0, 3, m_nodeReader, m_nodeExecuter);
    sub.start(nullptr);

    ASSERT_EQ(3, m_commandCountExecutions.getExecutinoCount());

};


