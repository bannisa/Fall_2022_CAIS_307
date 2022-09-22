/*This is a basic library of functions/methods for manipulating an array of integers
it is written using an structured programming approach*/

#include <stdlib.h>
 
float getAverage(int intArray[], int size)
{
	int total = 0;
	
	for (int i = 0; i < size; i++)
	{
		total += intArray[i]; 
	}

	return  total/(float)size;
}

/* INT_MIN and INT_MAX are constants declared within "stdlib.h" that
are equal to the smallest and largest integers that can be represented in
the C language*/

int getMax(int intArray[], int size)
{
	int max = INT_MIN;
	
	for (int i = 0; i < size; i++)
	{
		if ( intArray[i] > max )
			max = intArray[i]; 
	}

	return  max;
}

int getMin(int intArray[], int size)
{
	int min = INT_MAX;
	
	for (int i = 0; i < size; i++)
	{
		if ( intArray[i] < min )
			min = intArray[i]; 
	}
	return  min;
}

/* This subroutine removes an element at a certain position from the
array, it updates the array size in the calling program by returning
the updated size*/
int remove(int intArray[], int size, int elementIndex)
{
	/*We must test first if the position of the element
	we want to delete is within the array bounds, if not
	we should return with an error code*/
	if ( elementIndex < 0 || elementIndex >= size )
		return -1;
	
	for (int i = elementIndex + 1; i < size; i++)
	{
		intArray[i-1] = intArray[i];
	}
	return (size - 1);
}

/* This subroutine removes an element at a certain position from the
array, it updates the array size in the calling program by passing
the size by reference*/
bool remove(int intArray[], int* size, int elementIndex)
{
	/*We must test first if the position of the element
	we want to delete is within the array bounds, if not
	we should return with an error code*/
	if ( elementIndex < 0 || elementIndex >= *size )
		return false;
	
	for (int i = elementIndex + 1; i < *size; i++)
	{
		intArray[i-1] = intArray[i];
	}
	*size -= 1;
	return true;
}


/*The first parameter should be the address of a memory location in the calling
program containing the address of the array, since we need to modify the actual
address of the array in the caller program memory variable from within the method/subroutine, 
hence the int** type.*/
int insert(int** intArray, int* size, int* capacity,
		   int position, int value)
{
	/*If out of bounds we must return with an error code*/
	if (position < 0 || position > *size )
		return false;
	
	/*Check if the current block is large enough to
	store the new element, otherwise we need to request
	a larger block from the OS*/
	if ( *size + 1 > *capacity )
	{
		int* _intArray = NULL;
		/*We must allocate a larger block of memory big enough to hold
		 the current array size plus the new element, but its better to 
		 allocate a larger block than needed to minimize the amount of 
		 calls to the OS to allocate new memory (calls to malloc are 
		 time consuming) */
		int newCapacity = *capacity * 2; 
		_intArray = (int*) malloc( newCapacity * sizeof(int) );
		/*If memory allocation failed we must return with an error code*/
		if (_intArray == NULL)
			return false;

		//Copy contents from original array into new memory location
		for (int i = 0; i < *size; i++)
		{
			_intArray[i] = (*intArray)[i];
		}
		//We must deallocate the old memory block, otherwise we will cause a memory leak
		free(*intArray);

		//Make sure to update the array in the main
		//program to point to the new memory block
		*intArray = _intArray;

		//make sure to update the array size and capacity
		(*size)++;
		*capacity = newCapacity;
	}

	for (int i = *size; i > position; i--)
	{
		(*intArray)[i] = (*intArray)[i-1];
	}
	(*intArray)[position] = value;

	return true;
}


