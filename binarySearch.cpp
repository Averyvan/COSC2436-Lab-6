#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

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
template<class ItemType>
int binarySearch(ItemType anArray[], int first, int last, ItemType target)
{
   int index;
   if (first > last)
      index = -1; // target not in original array
   else
   {
      // If target is in anArray,
      // anArray[first] <= target <= anArray[last]
      int mid = first + (last - first) / 2;
      if (target == anArray[mid])
         index = mid; // target found at anArray[mid]
      else if (target < anArray[mid])
         // Point X
         index = binarySearch(anArray, first, mid - 1, target);
      else
         // Point Y
         index = binarySearch(anArray, mid + 1, last, target);
   }  // end if
   
   return index;
}  // end binarySearch

/*
int main()
{
	cout<<"Welcome to binarySearch!\n";
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
				sort(array, array+size);
				cout<<"Sorted array is:\n";
				for (int i=0; i<size; ++i)
					cout<<"#"<<i<<": "<<array[i]<<"\n";
				result = binarySearch<int>(array, 0, size-1, target);
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
				sort(array, array+size);
				cout<<"Sorted array is:\n";
				for (int i=0; i<size; ++i)
					cout<<"#"<<i<<": "<<array[i]<<"\n";
				result = binarySearch<string>(array, 0, size-1, target);
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

/* Sample output:
Welcome to binarySearch!
What type of data are you searching?
1) Integers
2) Strings
3) Exit
1
How many items are you searching? 5
#0: 123
#1: 599999
#2: 3
#3: 213
#4: 23
What are you looking for? 213
Sorted array is:
#0: 3
#1: 23
#2: 123
#3: 213
#4: 599999

213 found at position 3!

What type of data are you searching?
1) Integers
2) Strings
3) Exit
2
How many items are you searching? 5
#0: john
#1: joe
#2: james
#3: aardvark
#4: zane
What are you looking for? james
Sorted array is:
#0: aardvark
#1: james
#2: joe
#3: john
#4: zane

james found at position 1!

What type of data are you searching?
1) Integers
2) Strings
3) Exit
3
Thank you, goodbye!
--------------------------------
Process exited after 40.84 seconds with return value 0
Press any key to continue . . .
*/
