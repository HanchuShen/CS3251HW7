/* Copyright G. Hemingway @ 2019, All Rights Reserved */
#ifndef EXPRESSION_TREE_COMMAND_IMPL_H
#define EXPRESSION_TREE_COMMAND_IMPL_H

#include <iostream>
#include <string>
#include <vector>

// Forward declarations.
class Expression_Tree_Context;

class Expression_Tree_Command;

/**
 * @class Expression_Tree_Command_Impl
 * @brief Implementation of the Command pattern that is used to define a
 *        command performs an operation on the expression tree when
 *        executed.
 *
 *        Plays the role of the "implementor" base class in the Bridge
 *        pattern that is used as the basis for the subclasses that
 *        actually define the commands.
 */
class Expression_Tree_Command_Impl {
public:
    // Constructor that provides the appropriate Expression_Tree_Context.
    explicit Expression_Tree_Command_Impl(Expression_Tree_Context&);

    // Destructor.
    virtual ~Expression_Tree_Command_Impl() = default;

    // Pure virtual method for executing a command that must be defined
    // by subclasses.
    virtual bool execute() = 0;

protected:
    // Reference to the Expression_Tree_Context that's the target of
    // the command.
    Expression_Tree_Context& tree_context;
};

/**
 * @class Format_Command
 * @brief Set the desired format, e.g., "in-order," "pre-order,"
 *        "post-order", or "level-order".
 */
class Format_Command : public Expression_Tree_Command_Impl {
public:
    // Constructor that provides the appropriate @a
    // Expression_Tree_Context and the requested format.
    Format_Command(Expression_Tree_Context&, const std::string& new_format);

    // Set the desired format.
    bool execute() override;

private:
    // Requested format.
    std::string format;
};

/**
 * @class Expr_Command
 * @brief Set the desired expression, e.g., "1+2*3".
 */
class Expr_Command : public Expression_Tree_Command_Impl {
public:
    // Constructor that provides the appropriate @a
    // Expression_Tree_Context and the requested expression.
    Expr_Command(Expression_Tree_Context&, const std::string& new_expr);

    // Create the desired expression tree.
    bool execute() override;

private:
    // Requested expression.
    std::string expr;
};

/**
 * @class Print_Command
 * @brief Prints the expression tree in the desired format, e.g.,
 *        "in-order," "pre-order," "post-order", or "level-order".
 */
class Print_Command : public Expression_Tree_Command_Impl {
public:
    // Constructor that provides the appropriate @a
    // Expression_Tree_Context and the requested format.
    Print_Command(Expression_Tree_Context&, const std::string& print_format);

    // Print the expression tree.
    bool execute() override;

private:
    // Format to print out the tree.
    std::string format;
};

class Get_Command : public Expression_Tree_Command_Impl {
public:
    Get_Command(Expression_Tree_Context&, const std::string& new_format);
    bool execute() override;

private:
    std::string cmd;
};

class List_Command : public Expression_Tree_Command_Impl {
public:
    List_Command(Expression_Tree_Context&, const std::string& new_format);
    bool execute() override;

private:
    std::string cmd;
};

class Var_Command : public Expression_Tree_Command_Impl {
public:
    Var_Command(Expression_Tree_Context&, const std::string& new_format);
    bool execute() override;

private:
    std::string cmd;
};

class Hist_Command : public Expression_Tree_Command_Impl {
public:
    Hist_Command(Expression_Tree_Context&, const std::string& new_format);
    bool execute() override;

private:
    std::string cmd;
};

/**
 * @class Eval_Command
 * @brief Evaluates the expression tree in the desired format, e.g.,
 *        "in-order," "pre-order," "post-order", or "level-order".
 */
class Eval_Command : public Expression_Tree_Command_Impl {
public:
    // Constructor that provides the appropriate @a
    // Expression_Tree_Context and the requested format.
    Eval_Command(Expression_Tree_Context&, const std::string& eval_format);

    // Evaluate the expression tree.
    bool execute() override;

private:
    // Format to use for the evaluation.
    std::string format;
};

/**
 * @class Set_Command
 * @brief Sets a variable into the Interpreter_Context stored
 *        inside of Expression_Tree_Context.
 */
class Set_Command : public Expression_Tree_Command_Impl {
public:
    // Constructor that provides the appropriate @a
    // Expression_Tree_Context and the requested format.
    Set_Command(Expression_Tree_Context& context, const std::string& key_value_pair);

    // Evaluate the expression tree.
    bool execute() override;

private:
    // Format to use for the evaluation.
    std::string key_value_pair;
};

/**
 * @class Quit_Command
 * @brief Instructs the event loop to shut down.
 */
class Quit_Command : public Expression_Tree_Command_Impl {
public:
    // Constructor that provides the appropriate @a
    // Expression_Tree_Context.
    explicit Quit_Command(Expression_Tree_Context&);

    // Quit the event loop.
    bool execute() override;
};

/**
 * @class Macro_Command
 * @brief Execute a sequence of commands.
 */
class Macro_Command : public Expression_Tree_Command_Impl {
public:
    // Constructor that provides the appropriate @a
    // Expression_Tree_Context and sequence of commands.
    Macro_Command(
        Expression_Tree_Context&, const std::vector<Expression_Tree_Command>& macro_commands);

    // Quit the event loop.
    bool execute() override;

private:
    // Vector of commands that are executed as a macro.
    std::vector<Expression_Tree_Command> macro_commands_;

    // Expression input by the user.
    std::string expr;
};

/**
 * @class Null_Command
 * @brief No-op command
 */
class Null_Command : public Expression_Tree_Command_Impl {
public:
    // Constructor that provides the appropriate @a
    // Expression_Tree_Context and the requested format.
    explicit Null_Command(Expression_Tree_Context& context);

    // Set the desired format.
    bool execute() override;
};

#endif // EXPRESSION_TREE_COMMAND_IMPL_H
