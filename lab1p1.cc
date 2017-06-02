#include <iostream>
 
/*Implements bubblesort on integer arrays*/
void bubbleSort(int array[], int passed_length)
{
    int length = passed_length;
    int temp = 0;
    for(int i = 1; i<=length-1; i++) // Performs n-1 passes where n is the length of the Array.         
    {
        for(int j=1; j<=length-1;j++) // Performs n-1 passes where n is the length of the Array.
        {
            if(array[j]<array[j-1]) // Checks for out of order elements.
            {
                temp = array[j]; // Temporary storage to implement swapping.
                array[j]=array[j-1];
                array[j-1]=temp;
            }
        }    
    }
    
    
    for(int x = 0; x < length; x++) // Iterates through the array and outputs each element.
    {
        std::cout<< "\n" << array[x];
    }
    
}
 
int main()
{
    std::cout<< "Delaney Ramalho\nLab 1\n";
    int array[] = {34,54,1,23,0,4,5,67,8,34,5,65,77868,7,21,11}; // Initializes a test array of integers.
    int length = sizeof(array)/sizeof(int); // Calclates the length of the array.
    bubbleSort(array, length);
    return 0;
}
