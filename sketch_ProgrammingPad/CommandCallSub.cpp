//
// Created by indrek on 21.06.2015.
//

#include "CommandCallSub.h"

CommandCallSub::CommandCallSub() :
        m_programSub(nullptr)
{
}

CommandCallSub::CommandCallSub(ProgramSub &sub) :
        m_programSub(&sub)
{
}

void CommandCallSub::execute(Callback &done) {
    if (m_programSub != nullptr) {
        m_programSub->start(&done);
    } else {
        done.call();
    }
}


void CommandCallSub::init(ProgramSub & sub) {
    m_programSub = &sub;
}
