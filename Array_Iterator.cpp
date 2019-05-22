// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

//Constructor
template <typename T>
Array_Iterator <T>::Array_Iterator (Array <T> & A)
	: a (A),
	curr (0)
{}

//Destructor
template <typename T>
Array_Iterator <T>::~Array_Iterator (void)
{}

//Method to see if iterator has reached the end
template <typename T>
bool Array_Iterator <T>::is_done (void)
{
	return this->curr >= this->a.size();
}

//Method to advance the iterator
template <typename T>
bool Array_Iterator <T>::advance (void)
{
	++this->curr;
}

//Operator *
template <typename T>
T & Array_Iterator <T>::operator * (void)
{
	return this->a[this->curr];
}

//Operator ->
template <typename T>
T * Array_Iterator <T>::operator -> (void)
{
	return &this->a[this->curr];
}