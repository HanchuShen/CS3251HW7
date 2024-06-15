

#include "Composite_Power_Node.h"
#include "Visitor.h"
Composite_Power_Node::Composite_Power_Node(Component_Node* left, Component_Node* right)
        : Composite_Binary_Node(left, right)
        , isRoot(false)
{
}

int Composite_Power_Node::item() const
{
    return '^';
}

// accept a visitor
void Composite_Power_Node::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}

bool Composite_Power_Node::query() const
{
    return isRoot;
}

void Composite_Power_Node::trigger()
{
    isRoot = true;
}
