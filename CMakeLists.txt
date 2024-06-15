cmake_minimum_required(VERSION 3.11)
project(ExpressionTree)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

include_directories("./include")
set(SOURCE_FILES
        ./src/Component_Node.cpp
        ./src/Composite_Add_Node.cpp
        ./src/Composite_Binary_Node.cpp
        ./src/Composite_Divide_Node.cpp
        ./src/Composite_Multiply_Node.cpp
        ./src/Composite_Negate_Node.cpp
        ./src/Composite_Subtract_Node.cpp
        ./src/Composite_Unary_Node.cpp
        ./src/Evaluation_Visitor.cpp
        ./src/Expression_Tree.cpp
        ./src/Expression_Tree_Command.cpp
        ./src/Expression_Tree_Command_Factory.cpp
        ./src/Expression_Tree_Command_Factory_Impl.cpp
        ./src/Expression_Tree_Command_Impl.cpp
        ./src/Expression_Tree_Context.cpp
        ./src/Expression_Tree_Event_Handler.cpp
        ./src/Expression_Tree_Iterator.cpp
        ./src/Expression_Tree_Iterator_Impl.cpp
        ./src/Expression_Tree_State.cpp
        ./src/getopt.cpp
        ./src/Interpreter.cpp
        ./src/Leaf_Node.cpp
        ./src/main.cpp
        ./src/Options.cpp
        ./src/Print_Visitor.cpp
        ./src/Reactor.cpp
         include/Composite_Factorial_Node.h include/Composite_Factorial_Node.h src/Composite_Factorial_Node.cpp include/Composite_Power_Node.h src/Composite_Power_Node.cpp include/Composite_Mod_Node.h src/Composite_Mod_Node.cpp)
add_executable(ExpressionTree ${SOURCE_FILES})