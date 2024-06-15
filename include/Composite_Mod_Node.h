//
// Created by asus on 2020/4/17.
//

#ifndef EXPRESSIONTREE_COMPOSITE_MOD_NODE_H
#define EXPRESSIONTREE_COMPOSITE_MOD_NODE_H

class Component_Node;

#include "Composite_Binary_Node.h"

class Visitor;

class Composite_Mod_Node : public Composite_Binary_Node {
public:
    // Ctor
    Composite_Mod_Node(Component_Node* left, Component_Node* right);

    // Dtor
    ~Composite_Mod_Node() override = default;

    // Return the printable character stored in the node.
    int item() const override;

    // Define the accept() operation used for the Visitor pattern.
    void accept(Visitor& visitor) const override;

    bool query() const override;

    void trigger() override;

private:

    bool isRoot;
};

#endif //EXPRESSIONTREE_COMPOSITE_MOD_NODE_H
