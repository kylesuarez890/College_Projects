template <typename T>
  Stack<T>::Stack() //constructor w/o parameters
  {}

template <typename T>
  Stack<T>::~Stack() //destructor
  {}

template <typename T>
  Stack<T>::Stack(const Stack<T>& s) //copy constructor
  {
    list = s.list;
  }

template <typename T>
  Stack<T>::Stack(Stack<T> && s) //move constructor
  {
    list = std::move(s.list);
  }

template <typename T>
  Stack<T> & Stack<T>::operator=(const Stack<T>& s) //copy assignment operator=
  {
    if(*this != s)
      list = s.list;
    return *this;
  }

template <typename T>
  Stack<T> & Stack<T>::operator=(Stack<T> && s) //move assignemnt operator=
  {
    list = std::move(s.list);
    return *this;
  }

template <typename T>
  bool Stack<T>::empty() const //returns true if stack is empty
  {
      if((this -> size()) == 0)
        return true;
      else
        return false;
  }

template <typename T>
  void Stack<T>::clear() //deletes all elements of the stack
  {
    list.clear();
  }

template <typename T>
  void Stack<T>::push(const T& x) //adds x to stack (copy version)
  {
    list.push_back(x);
  }

template <typename T>
  void Stack<T>::push(T && x) //adds x to stack (move version)
  {
    list.push_back(std::move(x));
  }

template <typename T>
  void Stack<T>::pop() //removes most recent addition to the stack
  {
    if(!(this -> empty()))
      list.pop_back();
  }

template <typename T>
  T & Stack<T>::top() //returns reference to the top of the stack
  {
      return list.back();
  }

template <typename T>
  const T & Stack<T>::top() const //returns the element at the top of the stack
  {
      return list.back();         //auto senses const call
  }

template <typename T>
  int Stack<T>::size() const //returns the number or elements in the stack
  {
    return list.size();
  }

template <typename T>
  void Stack<T>::print(std::ostream& os, char ofc) const //prints all elements in stack (oldest first)
  {
    for( auto i = list.begin(); i != list.end(); ++i )
		  os << *i << ofc;
  }

  //new comparison operators
template <typename T>
  bool operator==(const Stack<T>& s1, const Stack<T>& s2)
  {
    if(s1.size() == s2.size())
    {
      Stack<T> s1cpy = s1;
      Stack<T> s2cpy = s2;
      bool test;
      do{
        test = (s1cpy.top() == s2cpy.top());
        s1cpy.pop();
        s2cpy.pop();
      }while(test && (!s1cpy.empty()));
      return test;
    }
    else
    return false;
  }

template <typename T>
  bool operator!=(const Stack<T>& s1, const Stack<T>& s2)
  {
    if(s1 == s2)
    return false;
    else return true;
  }

template <typename T>
  bool operator<=(const Stack<T>& s1, const Stack<T>& s2)
  {
    if(s1 == s2)
    return true;
    else if(s1.size() > s2.size())
    return false;
    else
    {
      Stack<T> s1cpy = s1;
      Stack<T> s2cpy = s2;
      bool test;
      do{
        test = (s1cpy.top() < s2cpy.top());
        s1cpy.pop();
        s2cpy.pop();
      }while(test && (!s1cpy.empty()));
      return test;
    }
  }

//new output operator
template <typename T>
  std::ostream& operator<< (std::ostream& os, const Stack<T>& s)
  {
    s.print(os);
    return os;
  }
