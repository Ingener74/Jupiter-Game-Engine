/*
 * File-default.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: pavel
 */

#include "Jupiter/FileFactory.h"

namespace jupiter {

using namespace std;

static FileFactory fileFactory;

BufferFactory* File::factory = &fileFactory;
string File::base = "";

}  // namespace jupiter


