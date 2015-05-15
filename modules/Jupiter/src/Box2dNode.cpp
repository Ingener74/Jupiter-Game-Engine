/*
 * Box2dNode.cpp
 *
 *  Created on: May 14, 2015
 *      Author: pavel
 */

#include <Box2D/Box2D.h>

#include "Jupiter/Image.h"
#include "Jupiter/CollisionListener.h"
#include "Jupiter/Box2dVisitor.h"
#include "Jupiter/Box2dNode.h"

namespace jupiter {

Box2dNode::Box2dNode(Box2dVisitor* v, Image* image) {
    b2BodyDef bodyDef;
    bodyDef.position.Set(getPositionX(), getPositionY());

    _body = v->getWorld()->CreateBody(&bodyDef);

    b2PolygonShape shape;
    shape.SetAsBox(image->getWidth(), image->getHeight());

    _body->CreateFixture(&shape, 0.3f);

    _body->SetUserData(this);
}

Box2dNode::~Box2dNode() {
}

Box2dNode* Box2dNode::setPosition(float x, float y, float z) {
    Node::setPosition(x, y, z);
    _body->SetTransform(b2Vec2(getPositionX(), getPositionY()), getRotationZ());
    return this;
}

Box2dNode* Box2dNode::translate(float x, float y, float z) {
    Node::translate(x, y, z);
    _body->SetTransform(b2Vec2(getPositionX(), getPositionY()), getRotationZ());
    return this;
}

Box2dNode* Box2dNode::setScale(float x, float y, float z) {
    Node::setScale(x, y, z);
    auto shape = dynamic_cast<b2PolygonShape*>(_body->GetFixtureList()->GetShape());
//    shape->SetAsBox()
    return this;
}

Box2dNode* jupiter::Box2dNode::scale(float x, float y, float z) {
    Node::scale(x, y, z);
    return this;
}

Box2dNode* Box2dNode::collision(Box2dNode* node) {
    if (_collisionListener)
        _collisionListener->collision(node);
    return this;
}

float Box2dNode::getBox2dX() const {
    return _body->GetPosition().x;
}

float Box2dNode::getBox2dY() const {
    return _body->GetPosition().y;
}

} /* namespace jupiter */
