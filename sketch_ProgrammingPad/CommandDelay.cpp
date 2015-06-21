//
// Created by indrek on 21.06.2015.
//

#include "CommandDelay.h"

CommandDelay::CommandDelay(uint32_t time_ms) : m_time_ms(time_ms) {

}

void CommandDelay::execute(Callback &done) {
    s_commandScheduler.set(&done).runOnce(m_time_ms);
}
