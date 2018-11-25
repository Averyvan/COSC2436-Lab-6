//Author:               Avery Vanausdal
//Assignment Number:    Lab 6
//File Name:			driver.cpp
//Course/Selection:     COSC 2436 Section 003
//Due Date:             11/25/18
//Instructor:           Ku, Bernard
//Description:			

#include "linearSearch.cpp"
#include "binarySearch.cpp"

#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

//basic input template
template <typename T>
T get_input(const string& prompt="", const string& error_msg="") {
	T value{};
	while (not(cout<<prompt && cin>>value)) {
		cout<<error_msg;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}
	return value;
}

template<typename T>
void binarySearchRun()
{
	int size = get_input<int>("How many items are you searching? ", "Error: Invalid input.\n");
	T array[size];
	for (int i=0; i<size; ++i)
	{
		cout<<"#"<<i<<": ";
		array[i] = get_input<T>("","Please enter a integer instead.\n");
	}
	T target = get_input<T>("What are you looking for? ", "Please enter an integer.\n");
	sort(array, array+size);
	cout<<"Sorted array is:\n";
	for (int i=0; i<size; ++i)
		cout<<"#"<<i<<": "<<array[i]<<"\n";
	int result = binarySearch<T>(array, 0, size-1, target);
	if (result == -1)
		cout<<endl<<target<<" not found.\n\n";
	else
		cout<<endl<<target<<" found at position "<<result<<"!\n\n";
}

template<typename T>
void linearSearchRun()
{
	int size = get_input<int>("How many items are you searching? ", "Error: Invalid input.\n");
	T array[size];
	for (int i=0; i<size; ++i)
	{
		cout<<"#"<<i<<": ";
		array[i] = get_input<T>("","Please enter a integer instead.\n");
	}
	T target = get_input<T>("What are you looking for? ", "Please enter an integer.\n");
	int result = linearSearch<T>(array, size, target);
	if (result == -1)
		cout<<endl<<target<<" not found.\n\n";
	else
		cout<<endl<<target<<" found at position "<<result<<"!\n\n";
}

int main()
{
	cout<<"Welcome to the search driver!\n";
	int sortChoice;
	int dataChoice;
	while (true)
	{
		sortChoice = get_input<int>("What type of search would you like to use?\n1) Binary\n2) Linear\n3) Exit\n","Please enter an integer between 1 and 3.\n\n");
		switch(sortChoice)
		{
			case 1:
			{
				dataChoice = get_input<int>("What type of data are you searching?\n1) Integers\n2) Strings\n3) Exit\n","Please enter an integer between 1 and 3.\n\n");
				switch(dataChoice)
				{
					case 1:
					{
						binarySearchRun<int>();
						break;
					}
					case 2:
					{
						binarySearchRun<string>();
						break;
					}
					case 3:
					{
						cout<<"Thank you, goodbye!";
						return 0;
					}
				}
				break;
			}
			case 2:
			{
				dataChoice = get_input<int>("What type of data are you searching?\n1) Integers\n2) Strings\n3) Exit\n","Please enter an integer between 1 and 3.\n\n");
				switch(dataChoice)
				{
					case 1:
					{
						linearSearchRun<int>();
						break;
					}
					case 2:
					{
						linearSearchRun<string>();
						break;
					}
					case 3:
					{
						cout<<"Thank you, goodbye!";
						return 0;
					}
				}
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

/* Sample output:
Welcome to the search driver!
What type of search would you like to use?
1) Binary
2) Linear
3) Exit
1
What type of data are you searching?
1) Integers
2) Strings
3) Exit
1
How many items are you searching? 4
#0: 1
#1: 2
#2: 7
#3: 3
What are you looking for? 3
Sorted array is:
#0: 1
#1: 2
#2: 3
#3: 7

3 found at position 2!

What type of search would you like to use?
1) Binary
2) Linear
3) Exit
2
What type of data are you searching?
1) Integers
2) Strings
3) Exit
1
How many items are you searching? 5
#0: 23
#1: dwadsd
Please enter a integer instead.
23123
#2: 32
#3: 2
#4: 5
What are you looking for? 23

23 found at position 0!

What type of search would you like to use?
1) Binary
2) Linear
3) Exit
1
What type of data are you searching?
1) Integers
2) Strings
3) Exit
2
How many items are you searching? 5
#0: dwal
#1: book
#2: door
#3: dog
#4: line
What are you looking for? dog
Sorted array is:
#0: book
#1: dog
#2: door
#3: dwal
#4: line

dog found at position 1!

What type of search would you like to use?
1) Binary
2) Linear
3) Exit
2
What type of data are you searching?
1) Integers
2) Strings
3) Exit
2
How many items are you searching? 6
#0: dwadk
#1: wacka
#2: pacman
#3: cats
#4: misc
#5: headphones
What are you looking for? misc

misc found at position 4!

What type of search would you like to use?
1) Binary
2) Linear
3) Exit
3
Thank you, goodbye!
--------------------------------
Process exited after 151.7 seconds with return value 0
Press any key to continue . . .
*/
