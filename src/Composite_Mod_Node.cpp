//
// Created by asus on 2020/4/17.
//

#include "Composite_Mod_Node.h"
#include "Visitor.h"
Composite_Mod_Node::Composite_Mod_Node(Component_Node* left, Component_Node* right)
        : Composite_Binary_Node(left, right)
        , isRoot(false)
{
}

int Composite_Mod_Node::item() const
{
    return '%';
}

// accept a visitor
void Composite_Mod_Node::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}

bool Composite_Mod_Node::query() const
{
    return isRoot;
}

void Composite_Mod_Node::trigger()
{
    isRoot = true;
}