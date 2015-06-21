//
// Created by indrek on 18.06.2015.
//

#include "gtest/gtest.h"
#include "Arduino.h"
#include "Scheduler.h"
#include "ProgramSub.h"
#include "mock/MockNodeReader.h"
#include "mock/MockCommandCountExecutions.h"
#include "CommandCallSub.h"
#include "CommandDelay.h"



#define COMMAND_COUNT 7
static uint16_t CMD_EXEC_CNT_1_R1 = 1000;
static uint16_t CMD_EXEC_CNT_2_R1 = 1100;
static uint16_t CMD_EXEC_CNT_3_R1 = 1200;
static uint16_t CMD_CALL_SUB_1_R1 = 2000;
static uint16_t CMD_CALL_SUB_2_R1 = 2100;
static uint16_t CMD_DELAY_1000_R1 = 3000;
static uint16_t CMD_DELAY_15000_R1 = 3100;


class SubExecutionTest : public ::testing::Test {

private:

protected:

    MockNodeReader m_nodeReader;
    NodeExecuterConfiguration<COMMAND_COUNT> m_nodeExecuter;

    ProgramSub m_main;
    ProgramSub m_sub1;
    ProgramSub m_sub2;

    MockCommandCountExecutions m_commandCountExecutions1;
    MockCommandCountExecutions m_commandCountExecutions2;
    MockCommandCountExecutions m_commandCountExecutions3;
    CommandCallSub m_commandCallSub1;
    CommandCallSub m_commandCallSub2;
    CommandDelay m_commandDelay1000ms;
    CommandDelay m_commandDelay15000ms;


    SubExecutionTest() :
            m_commandCallSub1(m_sub1),
            m_commandCallSub2(m_sub2),
            m_commandDelay1000ms(1000),
            m_commandDelay15000ms(15000)
    {
        m_nodeExecuter.initCommand(0, CMD_EXEC_CNT_1_R1, m_commandCountExecutions1);
        m_nodeExecuter.initCommand(1, CMD_EXEC_CNT_2_R1, m_commandCountExecutions2);
        m_nodeExecuter.initCommand(2, CMD_EXEC_CNT_3_R1, m_commandCountExecutions3);
        m_nodeExecuter.initCommand(3, CMD_CALL_SUB_1_R1, m_commandCallSub1);
        m_nodeExecuter.initCommand(4, CMD_CALL_SUB_2_R1, m_commandCallSub2);
        m_nodeExecuter.initCommand(5, CMD_DELAY_1000_R1, m_commandDelay1000ms);
        m_nodeExecuter.initCommand(6, CMD_DELAY_15000_R1, m_commandDelay15000ms);
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
    m_nodeReader.setNode(0, CMD_EXEC_CNT_1_R1);
    m_nodeReader.setNode(2, CMD_EXEC_CNT_1_R1);

    m_main.init(0, 3, m_nodeReader, m_nodeExecuter);
    m_main.start(nullptr);

    ASSERT_EQ(2, m_commandCountExecutions1.getExecutinoCount());
};



TEST_F(SubExecutionTest, testExecuteSub) {
    m_nodeReader.setNode(0, CMD_EXEC_CNT_1_R1);
    m_nodeReader.setNode(1, CMD_CALL_SUB_1_R1);

    m_nodeReader.setNode(10, CMD_EXEC_CNT_2_R1);

    m_main.init(0, 2, m_nodeReader, m_nodeExecuter);
    m_sub1.init(10, 1, m_nodeReader, m_nodeExecuter);
    m_main.start(nullptr);

    ASSERT_EQ(1, m_commandCountExecutions1.getExecutinoCount());
    ASSERT_EQ(1, m_commandCountExecutions2.getExecutinoCount());
};




TEST_F(SubExecutionTest, testExecuteMultipleSubs) {
    m_nodeReader.setNode(0, CMD_EXEC_CNT_1_R1); // 1: cnt_1 = 1
    m_nodeReader.setNode(1, CMD_EXEC_CNT_1_R1); // 2: cnt_1 = 2
    m_nodeReader.setNode(2, CMD_CALL_SUB_2_R1); // 3: call sub 2
    m_nodeReader.setNode(3, CMD_EXEC_CNT_1_R1); // 8: cnt_1 = 3

    m_nodeReader.setNode(10, CMD_EXEC_CNT_2_R1); // 7: cnt_2 = 1

    m_nodeReader.setNode(20, CMD_EXEC_CNT_3_R1); // 4: cnt_3 = 1
    m_nodeReader.setNode(21, CMD_EXEC_CNT_3_R1); // 5: cnt_3 = 1
    m_nodeReader.setNode(22, CMD_CALL_SUB_1_R1); // 6: call sub 1


    m_main.init(0, 4, m_nodeReader, m_nodeExecuter);
    m_sub1.init(10, 1, m_nodeReader, m_nodeExecuter);
    m_sub2.init(20, 3, m_nodeReader, m_nodeExecuter);
    m_main.start(nullptr);

    ASSERT_EQ(3, m_commandCountExecutions1.getExecutinoCount());
    ASSERT_EQ(1, m_commandCountExecutions2.getExecutinoCount());
    ASSERT_EQ(2, m_commandCountExecutions3.getExecutinoCount());
};





TEST_F(SubExecutionTest, testWaitCommand) {
    m_nodeReader.setNode(0, CMD_DELAY_1000_R1);
    m_nodeReader.setNode(1, CMD_EXEC_CNT_1_R1);
    m_nodeReader.setNode(2, CMD_DELAY_15000_R1);
    m_nodeReader.setNode(3, CMD_EXEC_CNT_1_R1);

    m_main.init(0, 4, m_nodeReader, m_nodeExecuter);
    m_main.start(nullptr);

    ASSERT_EQ(0, m_commandCountExecutions1.getExecutinoCount());
    runProgram(1000 - 5);
    ASSERT_EQ(0, m_commandCountExecutions1.getExecutinoCount());
    runProgram(10);
    ASSERT_EQ(1, m_commandCountExecutions1.getExecutinoCount());
    runProgram(15000 - 10);
    ASSERT_EQ(1, m_commandCountExecutions1.getExecutinoCount());
    runProgram(10);
    ASSERT_EQ(2, m_commandCountExecutions1.getExecutinoCount());
};

