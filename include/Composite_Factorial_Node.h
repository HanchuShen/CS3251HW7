
#ifndef EXPRESSIONTREE_COMPOSITE_FACTORIAL_NODE_H
#define EXPRESSIONTREE_COMPOSITE_FACTORIAL_NODE_H

#include "Composite_Unary_Node.h"

class Component_Node;

class Visitor;

class Composite_Factorial_Node : public Composite_Unary_Node {
public:
    // Ctor
    explicit Composite_Factorial_Node(Component_Node* right);

    // Dtor
    ~Composite_Factorial_Node() override = default;

    // Return the printable character stored in the node.
    int item() const override;

    // Define the accept() operation used for the Visitor pattern.
    void accept(Visitor& visitor) const override;

    bool query() const override;

    void trigger() override;

private:

    bool isRoot;
};

#endif //EXPRESSIONTREE_COMPOSITE_FACTORIAL_NODE_H
