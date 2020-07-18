template <typename T>
    List<T>::const_iterator::const_iterator() : current{nullptr}
    {}
template <typename T>
    const T & List<T>::const_iterator::operator* () const
    { return retrieve();}
template <typename T>
    typename List<T>::const_iterator & List<T>::const_iterator::operator++()
    {
      current = current -> next;
      return *this;
    }
template <typename T>
    typename List<T>::const_iterator List<T>::const_iterator::operator++(int)
    {
      auto change = *this;
      current = current -> next;
      return change;
    }
template <typename T>
    typename List<T>::const_iterator & List<T>::const_iterator::operator--()
    {
      current = current -> prev;
      return *this;
    }
template <typename T>
    typename List<T>::const_iterator List<T>::const_iterator::operator--(int)
    {
      const_iterator change = *this;
      --(*this);
      return change;
    }
template <typename T>
    bool List<T>::const_iterator::operator== (const typename List<T>::const_iterator & rhs) const
    {
      return current == rhs.current;
    }
template <typename T>
    bool List<T>::const_iterator::operator!= (const typename List<T>::const_iterator & rhs) const
    {
      return !(*this == rhs);
    }

template <typename T>
    List<T>::const_iterator::const_iterator(typename List<T>::Node* p) : current{p}
    {}
template <typename T>
    List<T>::iterator::iterator()
    {}
template <typename T>
    T & List<T>::iterator::operator*()
    {
      return this -> current -> data;
    }
template <typename T>
      T & List<T>::const_iterator::retrieve() const
      {return current -> data;}
template <typename T>
      const T & List<T>::iterator::operator*() const
      {
        return this -> retrieve();
      }
//Second iteration of operators for iterator
template <typename T>
      typename List<T>::iterator & List<T>::iterator::operator++()
      {
        this -> current = this -> current -> next;
        return *this;
      }
template <typename T>
      typename List<T>::iterator List<T>::iterator::operator++(int)
      {
        auto dup = *this;
        this -> current = this -> current -> next;
        return dup;
      }
template <typename T>
      typename List<T>::iterator & List<T>::iterator::operator--()
      {
        this -> current = this -> current -> prev;
        return *this;
      }
template <typename T>
      typename List<T>::iterator List<T>::iterator::operator--(int)
      {
        auto dup = *this;
        this -> current = this -> current -> prev;
        return *this;
      }
template <typename T>
      List<T>::iterator::iterator(typename List<T>::Node* p) : List<T>::const_iterator{p}
      {}
//constructor
template <typename T>
List<T>::List()
{
  init();
}

//destructor
template <typename T>
List<T>::~List()
{
  clear();
  delete head;
  delete tail;
}

//copy constructor
template <typename T>
List<T>::List(const List<T> & rhs)
{
  init();
  for(auto itr = rhs.begin(); itr != rhs.end(); ++itr)
      push_back(*itr);
}

//move constructor
template <typename T>
List<T>::List( List<T> && rhs ) : theSize(rhs.theSize), head{rhs.head}, tail{rhs.tail}
{
  rhs.head = nullptr;
  rhs.tail = nullptr;
  rhs.theSize = 0;
}

//copy assignement
template <typename T>
const List<T> & List<T>::operator=(const List<T> & rhs)
{
  auto dup = rhs;
  std::swap(*this, dup);
  return *this;
}

//move assignment
template <typename T>
List<T> & List<T>::operator=(List<T> && rhs)
{
  init();
  *this = std::move(rhs);
  return *this;
}

template <typename T>
List<T>::List(int num, const T & val)
{
  init();
  int index;
  for(index = 0; index < num; index++)
    push_back(val);
}

//constructor with values
template <typename T>
List<T>::List(typename List<T>::const_iterator start, typename List<T>::const_iterator end)
{
  init();
  for(auto itr = start; itr != end; ++itr)
    push_back(*itr);
}

//quantity
template <typename T>
int List<T>::size() const
{
  return theSize;
}

//Checks if List is empty
template <typename T>
bool List<T>::empty() const
{
  return (size() == 0);
}

//Delete all elements in list
template<typename T>
void List<T>::clear()
{
	while(!empty())
		pop_back();
}

//reverse order
template <typename T>
void List<T>::reverse()
{
  if(!empty())
  {
    auto current = head;
    while(current != nullptr)
    {
      std::swap(current -> next, current -> prev);
      current = current -> prev;
    }
  }
  std::swap(head,tail);
}

//Get first value
template <typename T>
T & List<T>::front()
{
  return *begin();
}

//Get first value (const edition)
template <typename T>
const T & List<T>::front() const
{
  return *begin();
}

//Get last value
template <typename T>
T & List<T>::back()
{
  return *(--end());
}

//Get last value (const edition)
template <typename T>
const T & List<T>::back() const
{
  return *(--end());
}

//insert value in front
template <typename T>
void List<T>::push_front(const T & val)
{
  insert(begin(), val);
}

//insert value in specific spot
template <typename T>
void List<T>::push_back(T && val)
{
  insert(end(), std::move(val));
}

//remove first element
template<typename T>
void List<T>::pop_front()
{
	erase(begin());
}

//Insert right before end
template<typename T>
void List<T>::push_back(const T & val)
{
	insert(end(), val);
}
//remove last element
template <typename T>
void List<T>::pop_back()
{
  erase(--end());
}

//removes all iterations of a specific value
template <typename T>
void List<T>::remove(const T & val)
{
  for(auto itr = begin(); itr != end(); ++itr)
  {
    if(*itr == val)
    erase(itr);
  }
}

// print out all values in list
template<typename T>
void List<T>::print(std::ostream & os, char ofc) const
{
	for(auto itr = begin(); itr != end(); ++itr)
		os << *itr << ofc;
}

template<typename T>
typename List<T>::iterator List<T>::begin()
{
  if(!empty())
  {
    typename List<T>::iterator
    itr{head -> next};
    return itr;
  }
}

template<typename T>
typename List<T>::const_iterator List<T>::begin() const
{
  if(!empty())
  {
    typename List<T>::const_iterator
    const_itr{head->next};
    return const_itr;
  }
}

template<typename T>
typename List<T>::iterator List<T>::end()
{
	typename List<T>::iterator itr{ tail };
	return itr;
}

template<typename T>
typename List<T>::const_iterator List<T>::end() const
{
	typename List<T>::const_iterator const_itr{tail};
	return const_itr;
}

template<typename T>
typename List<T>::iterator List<T>::insert(typename List<T>::iterator itr, const T & val)
{
	auto* cpy = itr.current;  theSize++;
	auto* newptr = new List<T>::Node{val, cpy->prev, cpy};
	cpy->prev->next = newptr;
	cpy->prev = newptr;
	typename List<T>::iterator iter{newptr};	return iter;
}

template<typename T>
typename List<T>::iterator List<T>::insert(typename List<T>::iterator itr, T && val)
{
	auto* cpy = itr.current;	theSize++;
	auto* newptr = new List<T>::Node{ std::move( val ), cpy->prev, cpy};
	cpy->prev->next = newptr;
	cpy->prev = newptr;
	typename List<T>::iterator iter{newptr};	return iter;
}

//delete specific node
template<typename T>
typename List<T>::iterator List<T>::erase(typename List<T>::iterator start, typename List<T>::iterator end)
{
	for(auto itr = start; itr != end;)
		itr = erase(itr);

	return end;
}
template<typename T>
typename List<T>::iterator List<T>::erase(typename List<T>::iterator itr)
{
	auto* cpy = itr.current;
	typename List<T>::iterator value{cpy->next};
	cpy->prev->next = cpy->next;
	cpy->next->prev = cpy->prev;
	delete cpy;
  theSize--;
  return value;
}

// init() for initialization
template<typename T>
void List<T>::init()
{
	theSize = 0;
	head = new Node;
  tail = new Node;
	head->next = tail;
  tail->prev = head;
}


// global functions
template<typename T>
bool operator!=(const List<T> & lhs, const List<T> & rhs)
{
	return !(lhs == rhs);
}
template<typename T>
bool operator==(const List<T> & lhs, const List<T> & rhs)
{
	bool flag = true;
	if( lhs.size() == rhs.size())
	{
		auto rhs_itr = rhs.begin();
		for(auto lhs_itr=lhs.begin(); lhs_itr !=lhs.end(); ++lhs_itr)
		{
			if(*lhs_itr != *rhs_itr)
			   flag = false; break;
			++rhs_itr;
		}
		return flag;
	}
	else
		return false;
}

template<typename T>
std::ostream & operator<<(std::ostream & os, const List<T> & l)
{
	l.print(os);	return os;
}
