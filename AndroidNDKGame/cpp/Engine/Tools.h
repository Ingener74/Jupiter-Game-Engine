/*
 * Tools.h
 *
 *  Created on: May 25, 2014
 *      Author: ingener
 */

#ifndef TOOLS_H_
#define TOOLS_H_

#include <Engine/Common.h>

namespace ndk_game
{

class Tools
{
public:
    Tools();
    virtual ~Tools();

    static void glError() throw (std::runtime_error);
};

} /* namespace ndk_game */

#endif /* TOOLS_H_ */
