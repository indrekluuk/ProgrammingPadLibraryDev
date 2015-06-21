//
// Created by indrek on 21.06.2015.
//

#include "CommandCallSub.h"

CommandCallSub::CommandCallSub(ProgramSub &sub) :
        m_programSub(sub)
{

}

void CommandCallSub::execute(Callback &done) {
    done.call();
}
