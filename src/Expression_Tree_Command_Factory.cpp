/* Copyright G. Hemingway @ 2019, All Rights Reserved */
#ifndef EXPRESSION_TREE_COMMAND_FACTORY_CPP
#define EXPRESSION_TREE_COMMAND_FACTORY_CPP

#include "Expression_Tree_Command_Factory.h"

// Default constructor.
Expression_Tree_Command_Factory::Expression_Tree_Command_Factory(
    Expression_Tree_Context& tree_context)
    // so far there is only one tree implementation, so we just create it here.
    : factory_impl(new Concrete_Expression_Tree_Command_Factory_Impl(tree_context))
{
}

// Copy ctor - needed for reference counting.
Expression_Tree_Command_Factory::Expression_Tree_Command_Factory(
    const Expression_Tree_Command_Factory& f)
    // wrap the pointer in a ref count object
    : factory_impl(f.factory_impl)
{
}

// Assignment operator - needed for reference counting.
Expression_Tree_Command_Factory& Expression_Tree_Command_Factory::operator=(
    const Expression_Tree_Command_Factory& f)
{
    // check for self assignment first
    if (this != &f)
        // we just make use of the Refcounter functionality here
        factory_impl = f.factory_impl;
    return *this;
}

// Method to create the binary tree to traverse.
Expression_Tree_Command Expression_Tree_Command_Factory::make_command(const std::string& s)
{
    return factory_impl->make_command(s);
}

Expression_Tree_Command Expression_Tree_Command_Factory::make_format_command(const std::string& s)
{
    return factory_impl->make_format_command(s);
}

Expression_Tree_Command Expression_Tree_Command_Factory::make_list_command(const std::string& s)
{
    return factory_impl->make_list_command(s);
}

Expression_Tree_Command Expression_Tree_Command_Factory::make_history_command(const std::string& s)
{
    return factory_impl->make_history_command(s);
}

Expression_Tree_Command Expression_Tree_Command_Factory::make_expr_command(const std::string& s)
{
    return factory_impl->make_expr_command(s);
}

Expression_Tree_Command Expression_Tree_Command_Factory::make_print_command(const std::string& s)
{
    return factory_impl->make_print_command(s);
}

Expression_Tree_Command Expression_Tree_Command_Factory::make_eval_command(const std::string& s)
{
    return factory_impl->make_eval_command(s);
}

Expression_Tree_Command Expression_Tree_Command_Factory::make_set_command(const std::string& s)
{
    return factory_impl->make_set_command(s);
}

Expression_Tree_Command Expression_Tree_Command_Factory::make_quit_command(const std::string& s)
{
    return factory_impl->make_quit_command(s);
}

Expression_Tree_Command Expression_Tree_Command_Factory::make_macro_command(const std::string& s)
{
    return factory_impl->make_macro_command(s);
}

#endif // EXPRESSION_TREE_COMMAND_FACTORY_H
