/*
 * Shape.cpp
 *
 *  Created on: Dec 16, 2014
 *      Author: pavel
 */

#include <Jupiter/Shape.h>

namespace jupiter
{

Shape::Shape(const std::vector<float>& data)
{
}

int32_t Shape::vertexCount() const
{
    return _data.size() / DATA_IN_ONE_VERTEX;
}

const float* Shape::vertexData() const
{
    return _data.data();
}

Shape::Type Shape::type() const
{
    return _type;
}

} /* namespace jupiter */
