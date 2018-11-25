//Author:               Avery Vanausdal
//Assignment Number:    Lab 6
//File Name:			AveryVanAusdalLab6Part1Driver.cpp
//Course/Selection:     COSC 2436 Section 003
//Due Date:             11/25/18
//Instructor:           Ku, Bernard
//Description:			Allows user input testing of binarySearch and linearSearch using menus.

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
	int searchChoice;
	int dataChoice;
	while (true)
	{
		searchChoice = get_input<int>("What type of search would you like to use?\n1) Binary\n2) Linear\n3) Exit\n","Please enter an integer between 1 and 3.\n\n");
		switch(searchChoice)
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
How many items are you searching? 8
#0: 1
#1: 5
#2: 9
#3: 12
#4: 15
#5: 21
#6: 29
#7: 31
What are you looking for? 12
Sorted array is:
#0: 1
#1: 5
#2: 9
#3: 12
#4: 15
#5: 21
#6: 29
#7: 31

12 found at position 3!

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
How many items are you searching? 8
#0: 1
#1: 5
#2: 9
#3: 12
#4: 15
#5: 21
#6: 29
#7: 31
What are you looking for? 29

29 found at position 6!

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
How many items are you searching? 5
#0: david
#1: john
#2: josh
#3: mason
#4: richard
What are you looking for? josh

josh found at position 2!

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
#0: john
#1: david
#2: josh
#3: mason
#4: richard
What are you looking for? richard
Sorted array is:
#0: david
#1: john
#2: josh
#3: mason
#4: richard

richard found at position 4!

What type of search would you like to use?
1) Binary
2) Linear
3) Exit
3
Thank you, goodbye!
--------------------------------
Process exited after 126.2 seconds with return value 0
Press any key to continue . . .
*/
