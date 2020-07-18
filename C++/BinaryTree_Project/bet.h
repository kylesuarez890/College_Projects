/* Kyle Suarez
 * COP4530
 * Project 4
 * Binary Expression Tree Header File
 */

#ifndef BET_H
#define BET_H
#include <stack>
#include <string>

class BET{
    private:
        struct BinaryNode{
                std::string element; //Actual data held by node
                BinaryNode *left;     //pointer for left child node
                BinaryNode *right;    //pointer for right child node


                BinaryNode() : left{nullptr},right{nullptr}{} //Constructor for struct
                BinaryNode(const std::string &e, BinaryNode *l, BinaryNode *r)
                    : element{e}, left{l},right{r}{}
            };
    public:
        BET();  //default constructor
        BET(const std::string postfix); //one parameter constructor
        BET(const BET&);    //copy constructor
        ~BET(); //destructor

        bool buildFromPostfix(const std::string postfix); //Builds tree from Postfix expression (returns false if failure)
        const BET & operator=(const BET &); //assignment operator

        void printInfixExpression();    //print infix expression (calls private version)
        void printPostfixExpression();  //print postfix expression (calls private version)

        size_t size();  //returns number of nodes in tree
        size_t leaf_nodes();    //returns number of leaf nodes in tree
        bool empty();   //checks if tree is empty

    private:
        BinaryNode *root;   //Root node

        //Functionailty for stacks to read expressions
        std::stack<BinaryNode*> betStack;   //Expression stack
        void ClearStack();
        bool IsOperator(const std::string &s);
        bool IsOperand(const std::string &s);

        //Necessary Functionality
        void printInfixExpression(BinaryNode *n);   //print infix expression
        void makeEmpty(BinaryNode* &t);           //delete all nodes from passed in node onward
        BinaryNode * clone(BinaryNode *t) const;   //clone all nodes from passed node onwards
        void printPostfixExpression(BinaryNode *n); //print postfix expression
        size_t size(BinaryNode *t);                 //number of nodes in subtree of node passed in
        size_t leaf_nodes(BinaryNode *t);           //number of  leafnodes
    };

    #include "bet.hpp"

#endif
