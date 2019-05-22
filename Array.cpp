// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//Default Constructor
template <typename T>
Array <T>::Array (void)
	: Array_Base <T> ()
{}

//Initializing constructor
template <typename T>
Array <T>::Array (size_t length)
	: Array_Base <T> (length)
{}

//Initializing Constructor (fill)
template <typename T>
Array <T>::Array (size_t length, T fill)
	: Array_Base <T> (length, fill)
{}

//Copy Constructor
template <typename T>
Array <T>::Array (const Array & array)
	: Array_Base <T> (array)
{}

//Destructor
template <typename T>
Array <T>::~Array (void)
{}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	int x;
	T *newArray, *temp;

	if(*this == rhs)
		return *this;

	//If this array is large enough to hold rhs, simply adjust the cur_size_
	if(rhs.size() <= this->max_size_)
		this->cur_size_ = rhs.size();

	//Otherwise allocate new memory for data_ in the correct size and free the old
	else
	{
		//Set data_to the new location and free the old
		newArray = new T[rhs.size()]();
		temp = this->data_;
		this->data_ = newArray;
		delete [] temp;
		this->cur_size_ = rhs.size();
		this->max_size_ = rhs.size();
	}

	//Copy the elements of the given array into this array
	for(x=0;x<this->cur_size_;x++)
	{
		this->set(x, rhs[x]);
	}
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	T *temp, *newArray;	
	int x;


	//If the new size is smaller than the max size
	if(new_size <= this->max_size_)
		this->cur_size_ = new_size;	//Simply change current size


	//If the new size is larger than max size
	else
	{
		//Allocate space for the resized array
		newArray = new T[new_size];

		//Assign the elements to be the same as this array
		for(x=0;x<this->cur_size_;x++)
		{
			newArray[x] = this->data_[x];
		}

		//Update the size variables
		this->max_size_ = new_size;
		this->cur_size_ = new_size;

		//Set the new memory location as data_ and free the old 
		temp = this->data_;
		this->data_ = newArray;
		delete [] temp;

	}
}


//Added back functions from assignmant 1

//Shrink
template <typename T>
void Array <T>::shrink (void)
{
	T *temp, *newArray;
	int x;

	//Do nothing if there is no extra space
	if(this->cur_size_ == this->max_size_)
		return;
	
	//Set max size to current size
	this->max_size_ = this->cur_size_;

	//Allocate new memory for the shrunken array
	newArray = new T[this->cur_size_];

	//Copy the elements of this array to the new location
	for(x=0;x<this->cur_size_;x++)
	{
		temp = newArray + x;
		*temp = this->data_[x];
	}

	//Point data_ to new location and free old memory location
	temp = this->data_;
	this->data_ = newArray;
	delete [] temp;
}


//Creates and returns a copy this array starting from the given index
template <typename T>
Array <T> Array <T>::slice (size_t begin) const	//This def didn't match the prototype originally
{
	T *temp;	//Temp pointer to reference specific elements
	int newsize = this->cur_size_ - begin;	//Calculates the new size
	int x, y = 0;


	//Make sure the begin index is within range
	if(begin >= this->cur_size_ || begin < 0)
		throw std::out_of_range ("Index out of range!");

	//Creates a new Array instance using initializing constructor
	Array newArray(newsize);

	//Copies the contents of the given slice into the new array
	 for(x=begin;x<this->cur_size_;x++, y++)
	 {
		//Copies the contents of this array into the new
		newArray.set(y, this->data_[x]);
	 }

	return newArray;	//Return the new array object
}

//Creates and returns a copy this array from "begin" to "end"
template <typename T>
Array <T> Array<T>::slice (size_t begin, size_t end) const
{
	T *temp;	//Temp pointer to reference specific elements
	int newsize = end - begin + 1;	//Calculates the new size
	int x, y = 0;

	//Make sure the begin and the end index is within range
	if(begin >= this->cur_size_ || end >= this->cur_size_ || begin < 0)
		throw std::out_of_range ("Index out of range!");

	//Make sure begin is less than end
	if(end <= begin)
		throw std::invalid_argument ("end should be after begin");

	//Creates a new Array instance using initializing constructor
	Array newArray(newsize);

	 //Copies the contents of the given slice into the new array
	 for(x=begin;x<=end;x++, y++)
	{
		//Copies the contents of this array into the new
		newArray.set(y, this->data_[x]);
	}

	return newArray;	//Return the new array object
}