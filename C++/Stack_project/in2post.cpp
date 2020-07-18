#include <iostream>
#include <string>
#include <cctype>
#include "stack.h"

using namespace std;
using namespace cop4530;

int order(char x);          //defines pemdas
bool op(char x);      //defines if selected charater is operator or operand
void space();               //makes sure spaces are not added to stack
void operand(Stack<string>& s, bool& flag1, bool& flag2);
char operators(string& a);

int main()
{
  Stack<char> c_op;

  Stack<string> postfix;    //holds the postfix expression
  cout << "Enter infix expression (exit to quit):\n";

  while(cin.peek() != '\n')
  {
    c_op.clear();
    postfix.clear();

    int num_operators = 0;    //number of operators = number of operands - 1
    int num_parantheses = 0;    //number of left hand paranthese should equal number of right hand parantheses

    bool flag = true;     //flag for if input is not numerical
    bool doubles = false;    //flag for if the input is a double

    while( !cin.eof() && cin.peek() != '\n')
    {
      space();
      char next;
      next  = cin.peek();

      if(isalpha(next) || isdigit(next) || (next == '.') || (next == '_' ))   //checks for operand
      {
        if(isalpha(next) || (next == '_' ))
          flag = false;
        else if(next == '.')
          doubles = true;

          operand(postfix, flag, doubles);
          num_operators++;
      }
      else if( op(next) )   //checks for operator
      {
        char operators;
        cin.get(operators);
        num_operators--;
        if(c_op.empty())
          c_op.push(operators);
        else if(order(operators) < order(c_op.top()))
        {
          space();
          if((isdigit(cin.peek()) || isalpha(cin.peek())) || (cin.peek() == '_') || (cin.peek() == '.'))
          {
            operand(postfix,flag,doubles);
            num_operators++;
            string temp;
            temp = operators;
            postfix.push(temp);
          }
        }
        else if(order(c_op.top() == 0))  //a "("
        {
          c_op.push(operators);
        }
        else if(order(operators) >= order(c_op.top()))
        {
          string temp;
          temp = c_op.top();
          postfix.push(temp);
          c_op.pop();
          c_op.push(operators);
        }
        else
        {
          cout << "Unexepected input... \n";
          break;
        }
      }
      else if(next == '(')
      {
        char grab;
        cin.get(grab);
        num_parantheses++;
        c_op.push(grab);
      }
      else if(next == ')')
      {
        char grab;
        cin.get(grab);
        num_parantheses--;
        while(c_op.top() != '(')
        {
          string temp;
          temp = c_op.top();
          c_op.pop();
          postfix.push(temp);
        }
        c_op.pop();   //removes the left hand paranthese from Stack
      }
      else{
        cout << "End of Program\n";
        break;
      }
    }
    string temp;
    temp = c_op.top();
    postfix.push(temp);
    c_op.pop();

    //OUTPUTTING THE POSTFIX OR COMPUTATIONAL RESULTS
    if((num_parantheses  == 0) && (num_operators == 1))
    {
      cout << "Postfix expression: " << postfix << endl;
    }
    else
      cout << "Postfix expression: " << endl;

    while(cin.peek() == ' ')
    {
      char trash;
      cin.get(trash);
    }

    if(flag)
    {
      Stack<double> eval;
      Stack<string> store;    //essentially reverse stack of postfix stack
      cout << "Postfix Evaluation: ";

      while(!postfix.empty())
      {
        store.push(postfix.top());
        postfix.pop();
      }
      while(!store.empty())
      {
        double a, b;
        switch(operators(store.top()))
        {
          case '*':
		  	  	  a = eval.top();
  			  	  eval.pop();
			        b = eval.top();
			  		  eval.pop();
			  		  eval.push( b * a );
			  		  break;
			  	case '/':
    		  		a = eval.top();
    		  		eval.pop();
    		  		b = eval.top();
    		  		eval.pop();
    		  		eval.push( b / a );
			  		  break;
			  	case '-':
  			  		a = eval.top();
              eval.pop();
              b = eval.top();
              eval.pop();
              eval.push( b - a );
			  		  break;
			  	case '+':
  			  		a = eval.top();
              eval.pop();
              b = eval.top();
              eval.pop();
              eval.push( b + a );
              break;
			  	case 'N':
					    double d = stod(store.top());
			  		  eval.push( d );
			  		  break;
			}
      store.pop();
      if(store.empty())
        cout << eval << endl;
        }
      }
      if(num_operators < 1)
        cout << "Error: Missing operand in postfix string. Unable to evaluate postfix string!\n";
      else if(num_operators > 1)
        cout << "Error: Missing operator in postfix string. Unable to evaluate postfix string!\n";
      else if(num_parantheses != 0)
        cout << "Error: Uneven parenthesis. Unable to evaluate postfix string!\n";
    }


  return 0;
}

//Function definitions:

void space()
{
  char space;
  while((cin.peek() == ' ') || (cin.peek() == '\t'))
  {
    cin.get(space);
  }
}

void operand(Stack<string>& s, bool& flag1, bool& flag2)
{
  string c_operand;
  c_operand.clear();
  while(isdigit(cin.peek()) || isalpha(cin.peek()) || (cin.peek() == '_') || (cin.peek() == '.'))
  {
    char add;
    cin.get(add);
    if((add == '_') || isalpha(add))
      flag1 = false;
    if(add == '.')
    flag2 = true;

    c_operand = c_operand + add;
  }
  s.push(c_operand);
}

bool op(char x)
{
  return ((x == '/') || (x == '*') || (x == '+') || (x == '-'));
}

int order(char x)
{
  int order;
  switch(x){
    case '*':
      order = 2;
      break;
    case '/':
      order = 2;
      break;
    case '+':
      order = 3;
      break;
    case '-':
      order = 3;
      break;
    case '(':
      order = 0;
      break;
    case ')':
      order = 1;
      break;
  }
  return order;
}

char operators(string& a)
{
  if(a.size() == 1)
  {
    char b = a[0];
    if(op(b))
      return b;
    else if(isdigit(b))
      return 'N';   //used to signify number
    else
      return 'E';   //used to signify error;
  }
  else
    return 'N';
}
