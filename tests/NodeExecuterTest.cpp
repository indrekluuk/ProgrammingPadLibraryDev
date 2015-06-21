//
// Created by indrek on 18.06.2015.
//

#include "gtest/gtest.h"
#include "Scheduler.h"
#include "ProgramSub.h"
#include "mock/MockCommandCountExecutions.h"



#define COMMAND_COUNT 3
static uint16_t CMD_EXEC_CNT_1_R1 = 1000;
static uint16_t CMD_EXEC_CNT_2_R1 = 2000;
static uint16_t CMD_EXEC_CNT_3_R1 = 30000;


class NodeExecuterTest : public ::testing::Test {

private:

protected:

    NodeExecuterConfiguration<COMMAND_COUNT> m_nodeExecuter;


    MockCommandCountExecutions m_commandCountExecutions1;
    MockCommandCountExecutions m_commandCountExecutions2;
    MockCommandCountExecutions m_commandCountExecutions3;


    NodeExecuterTest()
    {
        m_nodeExecuter.initCommand(0, CMD_EXEC_CNT_1_R1, m_commandCountExecutions1);
        m_nodeExecuter.initCommand(1, CMD_EXEC_CNT_2_R1, m_commandCountExecutions2);
        m_nodeExecuter.initCommand(2, CMD_EXEC_CNT_3_R1, m_commandCountExecutions3);
    }

    virtual void SetUp() {
    }


};



TEST_F(NodeExecuterTest, testGetCommand) {
    ASSERT_EQ(&m_commandCountExecutions1, &m_nodeExecuter.getCommand(CMD_EXEC_CNT_1_R1));
    ASSERT_EQ(&m_commandCountExecutions2, &m_nodeExecuter.getCommand(CMD_EXEC_CNT_2_R1));
    ASSERT_EQ(&m_commandCountExecutions3, &m_nodeExecuter.getCommand(CMD_EXEC_CNT_3_R1));
};


TEST_F(NodeExecuterTest, testFindClosest) {
    ASSERT_EQ(&m_commandCountExecutions1, &m_nodeExecuter.getCommand(1500-10));
    ASSERT_EQ(&m_commandCountExecutions2, &m_nodeExecuter.getCommand(1500+10));

    ASSERT_EQ(&m_commandCountExecutions2, &m_nodeExecuter.getCommand(16000-10));
    ASSERT_EQ(&m_commandCountExecutions3, &m_nodeExecuter.getCommand(16000+10));
};



TEST_F(NodeExecuterTest, testFindCloseToZero) {
    CommandDoNothing & doNothing = m_nodeExecuter.getCommandDoNothing();
    ASSERT_EQ(&doNothing, &m_nodeExecuter.getCommand(0));
    ASSERT_EQ(&doNothing, &m_nodeExecuter.getCommand(500 - 10));
    ASSERT_EQ(&m_commandCountExecutions1, &m_nodeExecuter.getCommand(500 + 10));
};















