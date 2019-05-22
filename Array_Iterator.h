// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"

#ifndef _ARRAY_ITERATOR_H_
#define _ARRAY_ITERATOR_H_

//Iterator class for arrays
template <typename T>
class Array_Iterator
{
	/// Type definition of the element type.
  typedef T type;

public:
	Array_Iterator(Array <T> & A);
	~Array_Iterator(void);

	bool is_done(void);
	bool advance(void);
	T & operator * (void);
	T * operator -> (void);

private:
	Array <T> & a;
	size_t curr;

};

#include "Array_Iterator.cpp"

#endif