/*
 * ScaleListener.cpp
 *
 *  Created on: May 15, 2015
 *      Author: pavel
 */

#include <iostream>
#include "Jupiter/ScaleListener.h"

namespace jupiter {

ScaleListener::ScaleListener() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

ScaleListener::~ScaleListener() {
}

void ScaleListener::scale(float x, float y, float z) {
}

} /* namespace jupiter */
