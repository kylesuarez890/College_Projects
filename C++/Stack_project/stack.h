#ifndef LIST_STACK_H
#define LIST_STACK_H
#include <iostream>
#include <list>

namespace cop4530 {

  template <typename T>
    class Stack {
    public:
      Stack();  //constructor
      ~Stack(); //destructor
      Stack(const Stack<T>& s); //copy constructor
      Stack(Stack<T> && s); //move constructor

      Stack<T>& operator=(const Stack<T>& s); //copy assignment operator=
      Stack<T> & operator=(Stack<T> && s); //move assignment operator=

      bool empty() const; //true if empty
      void clear(); //deletes all elements in stack

      void push(const T& x); //adds x to stack (copy version)
      void push(T && x); //adds x to stack (move version)

      void pop(); //removes most recent addition to the stack
      T& top(); //returns reference to the top of the stack
      const T& top() const; //returns the element at the top of the stack

      int size() const; //returns the number or elements in the stack

      void print(std::ostream& os, char ofc=' ') const; //prints all elements in stack (oldest first)
    private:
      std::list<T> list;
    };

    //new comparison operators
    template <typename T>
      bool operator==(const Stack<T>& s1, const Stack<T>& s2);

    template <typename T>
      bool operator!=(const Stack<T>& s1, const Stack<T>& s2);

    template <typename T>
      bool operator<=(const Stack<T>& s1, const Stack<T>& s2);

    //new output operator
    template <typename T>
      std::ostream& operator<< (std::ostream& os, const Stack<T>& s);

      #include "stack.hpp"
}

#endif
