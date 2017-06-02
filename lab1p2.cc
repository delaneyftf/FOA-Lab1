#include <iostream>

std::string ParsedBubbleSort(std::string namelist)
{
    int length = 0; // Length of the array.
    int substrindex = 0; // Tracks the starting point for the substr function.
    int substrcnt = 0; // Tracks the number of places to include for the substr function.
    int arrayindex = 0; // Tracks which place in the array the substr words go into.
    std::string temp; // Temporary storage for string swaps within an array.
    int x = 1;
    int comparisons = 0;
    
    /* Counts the number of spaces in the string to determine the size of the array to initialize. */
    for(int i=1; i<namelist.length(); i++) 
    {
        if(namelist.at(i) == ' ')
        {
            length++;
        }
    }
    length++;
    std::string *array = new std::string [length]; // Array initialization
    
    /* Tests every char in the string to check for whitespace. If whitespace is found it indicates the 
    start of a new word and this index is saved in substrindex. The loop then searches for the next whitespace 
    character indicating the end of the word. The number of chars between the start and end of the word is tracked
    by substrcnt. Finally the words are stored in an array with positions determined by arrayindex. */
    for(int i=0; i<namelist.length(); i++)
    {  
        if(std::isspace(namelist.at(i)))
        {
            array[arrayindex] = namelist.substr(substrindex, substrcnt);
            arrayindex++;
            substrindex= i+1 ;
            substrcnt = -1;
        }
        substrcnt++;
        if(i == namelist.length() -1)
        {
            array[arrayindex] = namelist.substr(substrindex, substrcnt);
        }
    }
    
    
    /* Implements bubblesort on string arrays */
    for(int i = 1; i<=length-1; i++) // Performs n-1 passes where n is the length of the Array.         
    {
        for(int j = 1; j<=length-x;j++) // Performs n-1 passes where n is the length of the Array.
        {
            if(array[j]<array[j-1]) // Checks for out of order elements.
            {
                temp = array[j]; // Temporary storage to implement swapping.
                array[j]=array[j-1];
                array[j-1]=temp;    
            }
            comparisons++;  // Tracks comparisons
        }   
        x++;
    }
    
    
    /* Iterates through the array and outputs each element. */
    for(int x = 0; x < length; x++)
    {
        std::cout << array[x] << " ";
    }
}

int main()
{
    std::cout<< "Delaney Ramalho\nLab 1\n";
    std::cout<< "Enter a list of names: ";
    std::string namelist;
    std::getline(std::cin, namelist); // Stores entire line of text as opposed to cin. 
    ParsedBubbleSort(namelist);
    return 0;
}