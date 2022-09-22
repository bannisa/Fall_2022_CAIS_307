#include <stdio.h>
#include <stdlib.h>
 
/*Define function signatures/headers, we could also have placed them
in an Array_Structured.h file and included that file*/ 
int remove(int intArray[], int size, int elementIndex);
bool remove(int intArray[], int* size, int elementIndex);
int insert(int** intArray, int* size, int* capacity, int position, int value);

int	main()
{
	//This is a simple program that tests some methods in the integer array library we implemented

    int initialSize1 = 40;
	int initialSize2 = 60;
	//We can't use the library on arrays declared in this way. Why?
	//int array1[40];
	//int array2[60];
	
	int* array1 = (int*)malloc( initialSize1 * sizeof(int) );
	for(int i = 0; i < initialSize1; i++)
		array1[i] = i;
	
	int newSize = remove(array1, initialSize1, 3);
	for(int i = 0; i < newSize; i++)
		printf( "%d\n", array1[i]);
	
	insert(&array1, &newSize, &initialSize1, 3, 3);
	printf("\n");
	for(int i = 0; i < newSize; i++)
		printf( "%d\n", array1[i]);
	
	int* array2 = (int*)malloc( initialSize2 * sizeof(int) );
	for(int i = 0; i < initialSize2; i++)
		array2[i] = 8;

	int newSize2 = initialSize2;
	bool success = remove(array2, &newSize2, 6);  
	
	insert(&array2, &newSize2, &initialSize2, 5, 222);
	printf("\n");
	for(int i = 0; i < newSize; i++)
		printf( "%d\n", array2[i]);

	//This code is just to prevent the console window from closing immediately in some IDEs
	char c = 'a';
	scanf("%c", &c);
	
	//Deallocate memory to avoid memory leaks
	free(array1);
	free(array2);

	return 0;


}