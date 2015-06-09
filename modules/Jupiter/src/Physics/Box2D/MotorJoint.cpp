/*
 * MotorJoint.cpp
 *
 *  Created on: Jun 9, 2015
 *      Author: pavel
 */

#include <Jupiter/MotorJoint.h>

namespace jupiter {

MotorJoint::MotorJoint(Box2dVisitor* visitor, b2MotorJointDef jointDef) :
    _visitor(visitor) {
    _joint = _visitor->getWorld()->CreateJoint(&jointDef);
}

MotorJoint::~MotorJoint() {
}

b2MotorJoint* MotorJoint::getMotorJoint() {
    auto joint = dynamic_cast<b2MotorJoint*>(_joint);
    jassert(joint, "invalid cast");
    return joint;
}

} /* namespace jupiter */
