//
// Created by indrek on 17.06.2015.
//

#include "NodeReader.h"

HardwareNodeReader::HardwareNodeReader(uint16_t r2) :
        m_r2(r2)
{

}

uint16_t HardwareNodeReader::getNodeR1(uint8_t nodeId) {
    /*
     * R1 = m_r2 * (1023/ai - 1);
     */
    return 0;
}
