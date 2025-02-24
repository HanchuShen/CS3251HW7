/* Copyright G. Hemingway @ 2019, All Rights Reserved */
#include "Composite_Negate_Node.h"
#include "Visitor.h"

// Ctor
Composite_Negate_Node::Composite_Negate_Node(Component_Node* right)
    : Composite_Unary_Node(right)
        , isRoot(false)
{
}

int Composite_Negate_Node::item() const
{
    return '-';
}

// accept a visitor
void Composite_Negate_Node::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}

bool Composite_Negate_Node::query() const
{
    return isRoot;
}

void Composite_Negate_Node::trigger()
{
    isRoot = true;
}