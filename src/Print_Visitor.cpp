/* Copyright G. Hemingway @ 2019, All Rights Reserved */
#ifndef PRINT_VISITOR_CPP
#define PRINT_VISITOR_CPP

#include "Print_Visitor.h"
#include "Composite_Add_Node.h"
#include "Composite_Divide_Node.h"
#include "Composite_Multiply_Node.h"
#include "Composite_Negate_Node.h"
#include "Composite_Subtract_Node.h"
#include "Leaf_Node.h"
#include <iostream>
#include <memory>

// visit function - prints Leaf_Negate_Node contents to std::cout
void Print_Visitor::visit(const Leaf_Node& node)
{
    std::cout << node.item() << " ";
}

// visit function - prints Composite_Negate_Node contents to std::cout
void Print_Visitor::visit(const Composite_Negate_Node&)
{
    std::cout << '-';
}

// visit function - prints Composite_Add_Node contents to std::cout
void Print_Visitor::visit(const Composite_Add_Node&)
{
    std::cout << "+ ";
}

// visit function - prints Composite_Subtract_Node contents to std::cout
void Print_Visitor::visit(const Composite_Subtract_Node&)
{
    std::cout << "- ";
}

// visit function - prints Composite_Divide_Node contents to std::cout
void Print_Visitor::visit(const Composite_Divide_Node&)
{
    std::cout << "/ ";
}

// visit function - prints Composite_Multiply_Node contents to std::cout
void Print_Visitor::visit(const Composite_Multiply_Node&)
{
    std::cout << "* ";
}

// visit function - prints Composite_Mod_Node contents to std::cout
void Print_Visitor::visit(const Composite_Mod_Node&)
{
    std::cout << "% ";
}

// visit function - prints Composite_Power_Node contents to std::cout
void Print_Visitor::visit(const Composite_Power_Node&)
{
    std::cout << "^ ";
}

// visit function - prints Composite_Factorial_Node contents to std::cout
void Print_Visitor::visit(const Composite_Factorial_Node&)
{
    std::cout << "!";
}

#endif // PRINT_VISITOR_CPP
