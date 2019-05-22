// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#define defaultsize 10

#include <stdexcept> 

//Default Constructor
template <typename T>
Array_Base <T>::Array_Base (void)
	: data_ (new T[defaultsize]), 
	cur_size_ (defaultsize), 
	max_size_ (defaultsize)
{}

//Initializing constructor
template <typename T>
Array_Base <T>::Array_Base (size_t length)
	: data_ (new T[length]),			
	cur_size_ (length), 
	max_size_ (length)
{}

//Initializing Constructor (fill)
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill)
	: data_ (new T[length]),			
	cur_size_ (length), 
	max_size_ (length)
{
	T *temp = this->data_;	//Temp pointer to reference specific elements 
	int x = length;

	//Loop iterates length times, initializes each element to fill
	for(x=0;x<length;x++)
	{
		//Sets the element to fill
		*temp = fill;
		temp ++;			
	}
}


//Copy Constructor
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & array)
	: data_ (new T[array.max_size()]),	
	cur_size_ (array.size()), 
	max_size_ (array.max_size())
{
	T *temp = this->data_;	//Temp pointers to reference specific elements
	int x;

	//Fill in the elements of this array to match the passed array
	for(x=0;x<this->cur_size_;x++, temp++)
	{
		*temp = array[x];
	}
}

//Destructor
template <typename T>
Array_Base <T>::~Array_Base (void)
{
	delete [] this->data_;
}


// operator []
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
	//First checks if given index is valid
	if (index >= this->cur_size_)
		throw std::out_of_range ("Index out of range!");

	//If valid, returns the value at that index
	return this->data_[index];
}


// operator [] (const)
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
	//First checks if given index is valid
	if (index >= this->cur_size_)
		throw std::out_of_range ("Index out of range!");

	//If valid, returns the value at that index
	return this->data_[index];
}

//Get
template <typename T>
T Array_Base <T>::get (size_t index) const
{

	//First checks if given index is valid
	if (index >= this->cur_size_)
		throw std::out_of_range ("Index out of range!");

	//If valid, returns the value at that index
	else
	{
		T temp = this->data_[index];	
		return temp;
	}
}

//Set
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
	//First checks if given index is valid
	if (index >= this->cur_size_)
		throw std::out_of_range ("Index out of range!");

	//If valid, sets the value at that index
	else
		this->data_[index] = value;
}

//Find
template  <typename T>
int Array_Base <T>::find (T value) const
{
	int x;

	//Iterates until index is out of range, starting at "0"
	for(x=0;x<this->cur_size_;x++)
	{
		//If the element is a match, return the index
		if(this->data_[x] == value)
			return x;
	}

	//If no element was a match, return -1
	return -1;
}

//Find (with start)
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
	int x;

	//First checks if given starting index is valid
	if (start >= this->cur_size_)
		throw std::out_of_range ("Index out of range!");

	//If valid, searches for a match starting at that index
	else
	{
		//Iterates until index is out of range, starting at start
		for(x=start;x<this->cur_size_;x++)
		{
			//If the element is a match, return the index
			if(this->data_[x] == val)
				return x;
		}

		//If no element was a match, return -1
		return -1;
	}
}

//Operator ==
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
	int x;

	//First check for self-assignment
	if (this == &rhs)
		return true;

	//Check if the size is the same
	if (this->cur_size_ != rhs.size())
		return false;	//If the sizes don't match

	//If the sizes do match
	else
	{
		//Check each element to see if they match between the arrays
		for(x=0;x<this->cur_size_;x++)
		{
			//If any element is not a match, return false
			if (this->data_[x] != rhs[x])
				return false;
		}

		//If the loop finished succesfully, then it was a match!
		return true;
	}
}

//Operator !=
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
	//Return the opposite of the == operator
	return !(*this == rhs);
}

//Fill
template <typename T>
void Array_Base <T>::fill (T value)
{
	int x;

	//Assign each element to value one by one
	for(x=0;x<this->cur_size_;x++)
	{
		this->data_[x] = value;
	}
}

//Reverses the contents of the array
template <typename T>
void Array_Base <T>::reverse (void)
{
	int head = 0, tail = this->cur_size_ - 1;
	int temp;

	//Swap the contents of head and tail, then move each towards the center until done
	while(head < tail)
	{
		//swap
		temp = this->data_[head];
		this->data_[head] = this->data_[tail];
		this->data_[tail] = temp;

		head++; 
		tail--;
	}
}