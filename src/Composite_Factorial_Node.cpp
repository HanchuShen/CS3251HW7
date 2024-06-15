//
// Created by asus on 2020/4/17.
//

#include "Composite_Factorial_Node.h"
#include "Visitor.h"

// Ctor
Composite_Factorial_Node::Composite_Factorial_Node(Component_Node* right)
        : Composite_Unary_Node(right)
        , isRoot(false)
{
}

int Composite_Factorial_Node::item() const
{
    return '!';
}

// accept a visitor
void Composite_Factorial_Node::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}
bool Composite_Factorial_Node::query() const
{
    return isRoot;
}
void Composite_Factorial_Node::trigger()
{
    isRoot = true;
}