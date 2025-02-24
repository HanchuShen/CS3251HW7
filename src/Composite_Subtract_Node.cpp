/* Copyright G. Hemingway @ 2019, All Rights Reserved */
#include "Composite_Subtract_Node.h"
#include "Visitor.h"

// Ctor
Composite_Subtract_Node::Composite_Subtract_Node(Component_Node* left, Component_Node* right)
    : Composite_Binary_Node(left, right)
    , isRoot(false)
{
}

int Composite_Subtract_Node::item() const
{
    return '-';
}

// accept a visitor
void Composite_Subtract_Node::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}

bool Composite_Subtract_Node::query() const
{
    return isRoot;
}

void Composite_Subtract_Node::trigger()
{
    isRoot = true;
}