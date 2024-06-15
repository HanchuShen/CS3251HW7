/* Copyright G. Hemingway @ 2019, All Rights Reserved */
#include "Composite_Add_Node.h"
#include "Visitor.h"

// Ctor
Composite_Add_Node::Composite_Add_Node(Component_Node* left, Component_Node* right)
    : Composite_Binary_Node(left, right),
      isRoot(false)
{
}

int Composite_Add_Node::item() const
{
    return '+';
}

// accept a visitor
void Composite_Add_Node::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}

bool Composite_Add_Node::query() const
{
    return isRoot;
}

void Composite_Add_Node::trigger()
{
    isRoot = true;
}