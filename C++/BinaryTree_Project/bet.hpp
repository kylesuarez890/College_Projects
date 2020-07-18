/* Kyle Suarez
 * COP4530
 * Project 4
*/
//PUBLIC FUNCTIONS

//Default Constructor
BET::BET() : root{nullptr}
{}

//One parameter constructor with intialization list
BET::BET(const std::string postfix) : root{nullptr}
{
    //Call buildFromPostfix
    buildFromPostfix(postfix);
}

//Copy Constructor with initialization list
BET::BET(const BET& pass): root{nullptr}
{
    ClearStack();
    root = clone(pass.root);
    betStack.push(root);
}

//Destructor
BET::~BET()
{
    if(!empty())
        makeEmpty(root);
    if(root != nullptr)
        delete root;
}


// Tree built based on postfix, tokens are separated by space (Returns if tree is built successfully.)
bool BET::buildFromPostfix(const std::string postfix)
{
    //Erase any data that may have already existed within tree
    if(!empty())
    {
        makeEmpty(root);
        ClearStack();
    }

    bool flag = true;
    std::string post = postfix;
    std::string temp;

    //Iterate across postfix string
    for(std::string::iterator itr = post.begin(); itr!= post.end(); ++itr)
    {
        temp += *itr;   //Add next character to the temp string

        //If the charater is a space or the end of string, create the tree
        if(*itr == ' ' || itr == (post.end()- 1))
        {
            if(*itr == ' ')
                temp.pop_back();
            if(IsOperand(temp))   //Create nodes when Operand is found
            {
                BinaryNode *n = new BinaryNode(temp,nullptr,nullptr);
                betStack.push(n);
            }
            else if(IsOperator(temp))        //Create Tree based on when Operator is found
            {
                BinaryNode *r, *l;    //Right and left temp

                if(!betStack.empty())
                {
                    r = betStack.top();
                    betStack.pop();
                }
                else
                {
                  flag = false;
                  break;
                }

                if(!betStack.empty())
                {
                    l = betStack.top();
                    betStack.pop();
                }
                else
                {
                  flag = false;
                  break;
                }
                BinaryNode *op = new BinaryNode(temp,l,r);
                //push new node into stack
                betStack.push(op);
            }
            temp = ""; //Reset temp string
        }
    }

    if(!betStack.empty()){
        root = betStack.top();  //Get the expected 'root'
        if(betStack.size() > 1 && IsOperand(root->element))
            flag = false;
    }
    else
    flag = false;

    if(!flag)   //Error occurred
    {
        std::cout << "Wrong postfix expression" << std::endl;
        //Clear any attempted tree
        if(!empty()){
            makeEmpty(root);
            ClearStack();
        }
    }
    return flag;
}

//Assignment Operator
const BET & BET::operator=(const BET& pass)
{
    //Clone the root
    root = clone(pass.root);
    ClearStack();
    //Add root to current stack
    betStack.push(root);
    return *this;
}


void BET::printInfixExpression()    //prints infix expression
{
    printInfixExpression(root);
    std::cout << '\n';
}

void BET::printPostfixExpression()  //prints postfix expression
{
    printPostfixExpression(root);
    std::cout << '\n';
}

size_t BET::size()    //returns size aka number of nodes
{
    return size(root);
}

size_t BET::leaf_nodes()    //returns number of  leaf nodes
{
    return leaf_nodes(root);
}

bool BET::empty()   //checks if "root" node has any children
{
    return (root == nullptr);
}

//PRIVATE FUNCTIONS

void BET::ClearStack()    //empties stack
{
    while(!betStack.empty())
        betStack.pop();
}

bool BET::IsOperator(const std::string &s)  //checks if character is operator
{
    return(s == "+" || s == "-" || s == "/" || s == "*");
}

bool BET::IsOperand(const std::string &s) //checks if character is operand
{
    if(s.length() == 1)
    {
        char c = s[0];
        return((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c == '_'));
    }
    else return true;
}

void BET::printInfixExpression(BET::BinaryNode *n)
{
    if(n != nullptr)  //will run through the whole tree
    {
        if(IsOperator(n->element) && n != root)
            std::cout << "( ";

        printInfixExpression(n->left);  //recursive call

        std::cout << n->element << " ";

        printInfixExpression(n->right);

        if(IsOperator(n->element) && n != root)
            std::cout << ") ";
    }
}

void BET::makeEmpty(BinaryNode* &t)
{
    if(t != nullptr)    //make sure the subtree is not empty
    {
        if(t->left != nullptr)  //recursively call until last child is reached
            makeEmpty(t->left);
        if(t->right != nullptr)
            makeEmpty(t->right);
        delete t;   //will delete all the data as function is called recursively
    }
    //Set node to nullptr for recursion and deletion
    t = nullptr;
}

BET::BinaryNode * BET::clone(BET::BinaryNode* t) const
{
    if(t == nullptr)
        return nullptr;
    else return new BinaryNode{t->element,clone(t->left),clone(t->right)};
}

void BET::printPostfixExpression(BET::BinaryNode *n)
{
    if(n != nullptr)
    {
        printPostfixExpression(n->left);
        printPostfixExpression(n->right);
        std::cout << n->element << " ";
    }
}

size_t BET::size(BET::BinaryNode *t)
{
    if(t == nullptr)
        return 0;
    else return 1 + size(t->left) + size(t->right); //increments size recursively for each node
}

size_t BET::leaf_nodes(BET::BinaryNode *t){
    if(t == nullptr)
        return 0;
    //If node does not have any children, it is a leaf
    if(t->left == nullptr && t->right == nullptr)
        return 1;
    else return 0 + leaf_nodes(t->left) + leaf_nodes(t->right); //reursively sums
}
