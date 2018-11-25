// This program demonstrates the linear search algorithm.
#include <iostream>
#include <limits>
using namespace std;

//*****************************************************************
// The linearSearch function performs a linear search on an       *
// integer array. The array arr, which has a maximum of size      *
// elements, is searched for the number stored in value. If the   *
// number is found, its array subscript is returned. Otherwise,   *
// -1 is returned indicating the value was not in the array.      *
//*****************************************************************
template<typename T>
int linearSearch(const T arr[], int size, T value)
{
   int index = 0;       // Used as a subscript to search array
   int position = -1;   // To record position of search value
   bool found = false;  // Flag to indicate if the value was found

   while (index < size && !found)
   {
      if (arr[index] == value)  // If the value is found
      {
         found = true;         // Set the flag
         position = index;     // Record the value's subscript
      }
      index++;                  // Go to the next element
   }
   return position;              // Return the position, or -1
}

