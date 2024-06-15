/* Copyright G. Hemingway @ 2019, All Rights Reserved */
#include "Evaluation_Visitor.h"
#include "Composite_Add_Node.h"
#include "Composite_Divide_Node.h"
#include "Composite_Multiply_Node.h"
#include "Composite_Negate_Node.h"
#include "Composite_Subtract_Node.h"
#include "Composite_Factorial_Node.h"
#include "Composite_Mod_Node.h"
#include "Composite_Power_Node.h"
#include "Leaf_Node.h"
#include <iostream>
#include <memory>
#include <iostream>
#include <cmath>

// base evaluation for a node. This is used by Leaf_Node
void Evaluation_Visitor::visit(const Leaf_Node& node)
{
    stack.push(node.item());
}

// evaluation of a negation (Composite_Negate_Node)
void Evaluation_Visitor::visit(const Composite_Negate_Node&)
{
    if (stack.size() >= 1) {
        auto value = stack.top();
        stack.pop();
        stack.push(-value);
    }
}

// evaluation of an addition (Composite_Add_Node)
void Evaluation_Visitor::visit(const Composite_Add_Node&)
{
    if (stack.size() >= 2) {
        auto rhs = stack.top();
        stack.pop();
        auto lhs = stack.top();
        stack.pop();
        stack.push(lhs + rhs);
    }
}

// evaluation of an addition (Composite_Subtract_Node)
void Evaluation_Visitor::visit(const Composite_Subtract_Node&)
{
    if (stack.size() >= 2) {
        auto rhs = stack.top();
        stack.pop();
        auto lhs = stack.top();
        stack.pop();
        stack.push(lhs - rhs);
    }
}

// evaluations of a division (Composite_Divide_Node)
void Evaluation_Visitor::visit(const Composite_Divide_Node&)
{
    if (stack.size() >= 2 && stack.top()) {
        auto rhs = stack.top();
        stack.pop();
        auto lhs = stack.top();
        stack.pop();
        stack.push(lhs / rhs);
    } else {
        std::cout << "\n\n**ERROR**: Division by zero is not allowed. ";
        std::cout << "Resetting evaluation visitor.\n\n";
        reset();
    }
}

// evaluations of a division (Composite_Multiply_Node)
void Evaluation_Visitor::visit(const Composite_Multiply_Node&)
{
    if (stack.size() >= 2) {
        auto rhs = stack.top();
        stack.pop();
        auto lhs = stack.top();
        stack.pop();
        stack.push(lhs * rhs);
    }
}

// evaluation of a Factorial (Composite_Factorial_Node)
void Evaluation_Visitor::visit(const Composite_Factorial_Node&)
{

    if (stack.size() >= 1) {
        auto value = stack.top();
        stack.pop();
        long long val = 1;
        while (value) {
            val *= value--;
        }
        stack.push(val);
    }
}

// evaluation of a Mod (Composite_Mod_Node)
void Evaluation_Visitor::visit(const Composite_Mod_Node&)
{
    if (stack.size() >= 2) {
        auto rhs = stack.top();
        stack.pop();
        auto lhs = stack.top();
        stack.pop();
        stack.push(lhs % rhs);
    }
}

// evaluation of a Power (Composite_Power_Node)
void Evaluation_Visitor::visit(const Composite_Power_Node&)
{
    if (stack.size() >= 2) {
        auto rhs = stack.top();
        stack.pop();
        auto lhs = stack.top();
        stack.pop();
        stack.push(int(pow(lhs, rhs)));
    }
}

// print a total for the evaluation
int Evaluation_Visitor::total()
{
    if (!stack.empty())
        return stack.top();
    else
        return 0;
}

// reset the evaluation
void Evaluation_Visitor::reset()
{
    while (!stack.empty())
        stack.pop();
}
