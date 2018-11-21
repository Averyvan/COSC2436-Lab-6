// This program demonstrates the linear search algorithm.
#include <iostream>
#include <limits>
using namespace std;

// Function prototype
template<typename T>
int linearSearch(const T[], int, T);

/*
//basic input template
template <typename T>
T get_input(const string& prompt="", const string& error_msg="", 
T min=-numeric_limits<T>::max(), T max=numeric_limits<T>::max()) {
	T value{};
	while (not(cout<<prompt && cin>>value && value>=min && value<=max)) {
		cout<<error_msg;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}
	return value;
}
*/

/*
int main()
{
	cout<<"Welcome to linearSearch!\n";
	int choice;
	int size;
	int result = -1;
	while (true)
	{
		choice = get_input<int>("What type of data are you searching?\n1) Integers\n2) Strings\n3) Exit\n","Please enter an integer between 1 and 3.\n\n", 1, 3);
		switch(choice)
		{
			case 1:
			{
				size = get_input<int>("How many items are you searching? ", "Please enter an integer.\n");
				int array[size];
				for (int i=0; i<size; ++i)
				{
					cout<<"#"<<i<<": ";
					array[i] = get_input<int>("","Please enter a integer instead.\n");
				}
				int target = get_input<int>("What are you looking for? ", "Please enter an integer.\n");
				result = linearSearch<int>(array, size, target);
				if (result == -1)
					cout<<endl<<target<<" not found.\n\n";
				else
					cout<<endl<<target<<" found at position "<<result<<"!\n\n";
				break;
			}
			case 2:
			{
				size = get_input<int>("How many items are you searching? ", "Please enter an integer.\n");
				string array[size];
				for (int i=0; i<size; ++i)
				{
					cout<<"#"<<i<<": ";
					cin>>array[i];
				}
				string target;
				cout<<"What are you looking for? ";
				cin>>target;
				result = linearSearch<string>(array, size, target);
				if (result == -1)
					cout<<endl<<target<<" not found.\n\n";
				else
					cout<<endl<<target<<" found at position "<<result<<"!\n\n";
				break;
			}
			case 3:
				{
					cout<<"Thank you, goodbye!";
					return 0;
				}
		}
		
	}
	
	return 0;
}
*/

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

/* Sample output:
Welcome to linearSearch!
What type of data are you searching?
1) Integers
2) Strings
3) Exit
1
How many items are you searching? 4
#0: 2
#1: 6
#2: 123
#3: 1203
What are you looking for? 123

123 found at position 2!

What type of data are you searching?
1) Integers
2) Strings
3) Exit
2
How many items are you searching? 4
#0: car
#1: tire
#2: wheel
#3: boot
What are you looking for? tire

tire found at position 1!

What type of data are you searching?
1) Integers
2) Strings
3) Exit
3
Thank you, goodbye!
--------------------------------
Process exited after 70.55 seconds with return value 0
Press any key to continue . . .
*/
