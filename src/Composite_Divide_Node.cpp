/* Copyright G. Hemingway @ 2019, All Rights Reserved */
#include "Composite_Divide_Node.h"
#include "Visitor.h"

// Ctor
Composite_Divide_Node::Composite_Divide_Node(Component_Node* left, Component_Node* right)
    : Composite_Binary_Node(left, right)
    , isRoot(false)
{
}

int Composite_Divide_Node::item() const
{
    return '/';
}

// accept a visitor
void Composite_Divide_Node::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}

bool Composite_Divide_Node::query() const
{
    return isRoot;
}

void Composite_Divide_Node::trigger()
{
    isRoot = true;
}