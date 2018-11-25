//Author:               Avery Vanausdal
//Assignment Number:    Lab 6
//File Name:			AveryVanAusdalLab6Part2Driver.cpp
//Course/Selection:     COSC 2436 Section 003
//Due Date:             11/25/18
//Instructor:           Ku, Bernard
//Description:			

#include "linearSearch.cpp"
#include "binarySearch.cpp"
#include "quicksort.cpp"

#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <limits>
#include <algorithm>
using namespace std;

template <typename T> //basic input function
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

void fillIntArray(int array[], int size)
{
	for(int i = 0; i < size; i++)
		array[i] = (rand()*rand() % 100000000) + 1;
}

void fillStrArray(string array[], int size)
{
	ifstream inFile("LastName2010new.txt"); //435670 items
	for(int i = 0; i < size; i++)
	{
		getline(inFile, array[i]);
	}
	inFile.close();
}

template<class T>
void linearTrialRuns(int trials, ofstream &outFile, int size, void fillArray(T[], int), T target)
{
	T **array = new T*[trials];
	for(int i=0; i < trials; i++)
		array[i] = new T[size];
	for(int j=0; j < trials; j++)
	{
		fillArray(&array[j][0], size);
	}

	double start = double(clock()) / CLOCKS_PER_SEC; //starts timer

	for (int i=1; i<=trials; i++)
	{
		cout<<linearSearch(&array[i-1][0], size, target)<<endl;
	}
	outFile << fixed << showpoint << setprecision (5) << "Algorithm: Linear Search"<<endl;
	double finish = double(clock()) / CLOCKS_PER_SEC;														   
	double elapsed = (finish - start);  //Takes final time - beginning time, to get time to complete all iterative trials
	double average = (finish - start)/trials;//finds average time to complete each trial
	outFile << "Time Elapsed: " << setw(5) << elapsed << " seconds" << endl; //displays elapsed time
	outFile << "Average time trial over " << trials << " runs: " << setw(5) << average << " seconds with "<<size<< " elements\n" <<endl; //displays average time
	for(int i=0; i < trials; i++)
		delete[] array[i];
	delete[] array;
}

//Randomly picks targets for each trial
void linearTrialRunsInt(int trials, ofstream &outFile, int size)
{
	int *array = new int[size];
	fillIntArray(array, size);

	double start = double(clock()) / CLOCKS_PER_SEC; //starts timer
	for (int i=1; i<=trials; i++)
	{
		cout<<linearSearch(array, size, (rand()*rand() % 100000000) + 1)<<endl;
	}
	outFile << fixed << showpoint << setprecision (5) << "Algorithm: Linear Search"<<endl;
	double finish = double(clock()) / CLOCKS_PER_SEC;														   
	double elapsed = (finish - start);  //Takes final time - beginning time, to get time to complete all iterative trials
	double average = (finish - start)/trials;//finds average time to complete each trial
	outFile << "Time Elapsed: " << setw(5) << elapsed << " seconds" << endl; //displays elapsed time
	outFile << "Average time trial over " << trials << " runs: " << setw(5) << average << " seconds with "<<size<< " elements\n" <<endl; //displays average time
	delete[] array;
}

//Randomly picks targets for each trial
void linearTrialRunsStr(int trials, ofstream &outFile, int size = 450000)
{
	string *array = new string[size];
	fillStrArray(array, size);

	double start = double(clock()) / CLOCKS_PER_SEC; //starts timer
	for (int i=1; i<=trials; i++)
	{
		cout<<linearSearch(array, size, array[(rand()*rand() % size)])<<endl;
	}
	outFile << fixed << showpoint << setprecision (5) << "Algorithm: Linear Search"<<endl;
	double finish = double(clock()) / CLOCKS_PER_SEC;														   
	double elapsed = (finish - start);  //Takes final time - beginning time, to get time to complete all iterative trials
	double average = (finish - start)/trials;//finds average time to complete each trial
	outFile << "Time Elapsed: " << setw(5) << elapsed << " seconds" << endl; //displays elapsed time
	outFile << "Average time trial over " << trials << " runs: " << setw(5) << average << " seconds with "<<size<< " elements\n" <<endl; //displays average time
	delete[] array;
}

template<class T>
void binaryTrialRuns(int trials, ofstream &outFile, int size, void fillArray(T[], int), T target)
{
	T **array = new T*[trials];
	for(int i=0; i < trials; i++)
		array[i] = new T[size];
	for(int j=0; j < trials; j++)
	{
		fillArray(&array[j][0], size);
	}
	
	//presorts arrays
	for(int l=0; l < trials; l++)
	{
//		quickSort(&array[l][0], 0, size-1);
		sort(&array[l][0],&array[l][size-1]);
	}
	
	double start = double(clock()) / CLOCKS_PER_SEC; //starts timer

	for (int i=1; i<=trials; i++)
	{
		cout<<"Position: "<<binarySearch(&array[i-1][0], 0, size-1, target)<<endl;
	}
	outFile << fixed << showpoint << setprecision (5) << "Algorithm: Binary Search"<<endl;
	double finish = double(clock()) / CLOCKS_PER_SEC;														   
	double elapsed = (finish - start);  //Takes final time - beginning time, to get time to complete all iterative trials
	double average = (finish - start)/trials;//finds average time to complete each trial
	outFile << "Time Elapsed: " << setw(5) << elapsed << " seconds" << endl; //displays elapsed time
	outFile << "Average time trial over " << trials << " runs: " << setw(5) << average << " seconds with "<<size<< " elements\n" <<endl; //displays average time
	for(int i=0; i < trials; i++)
		delete[] array[i];
	delete[] array;
}

//Randomly picks targets for each trial
void binaryTrialRunsInt(int trials, ofstream &outFile, int size)
{
	int *array = new int[size];
	fillIntArray(array, size);
	quickSort(array, 0, size-1);
	double start = double(clock()) / CLOCKS_PER_SEC; //starts timer
	for (int i=1; i<=trials; i++)
	{
		cout<<binarySearch(array, 0, size-1, (rand()*rand() % 100000000) + 1)<<endl;
	}
	outFile << fixed << showpoint << setprecision (5) << "Algorithm: Binary Search"<<endl;
	double finish = double(clock()) / CLOCKS_PER_SEC;														   
	double elapsed = (finish - start);  //Takes final time - beginning time, to get time to complete all iterative trials
	double average = (finish - start)/trials;//finds average time to complete each trial
	outFile << "Time Elapsed: " << setw(5) << elapsed << " seconds" << endl; //displays elapsed time
	outFile << "Average time trial over " << trials << " runs: " << setw(5) << average << " seconds with "<<size<< " elements\n" <<endl; //displays average time
	delete[] array;
}

//Randomly picks targets for each trial
void binaryTrialRunsStr(int trials, ofstream &outFile, int size = 450000)
{
	string *array = new string[size];
	fillStrArray(array, size);

	double start = double(clock()) / CLOCKS_PER_SEC; //starts timer
	for (int i=1; i<=trials; i++)
	{
		cout<<binarySearch(array, 0, size-1, array[(rand()*rand() % size)])<<endl;
	}
	outFile << fixed << showpoint << setprecision (5) << "Algorithm: Binary Search"<<endl;
	double finish = double(clock()) / CLOCKS_PER_SEC;														   
	double elapsed = (finish - start);  //Takes final time - beginning time, to get time to complete all iterative trials
	double average = (finish - start)/trials;//finds average time to complete each trial
	outFile << "Time Elapsed: " << setw(5) << elapsed << " seconds" << endl; //displays elapsed time
	outFile << "Average time trial over " << trials << " runs: " << setw(5) << average << " seconds with "<<size<< " elements\n" <<endl; //displays average time
	delete[] array;
}

int main()
{
	srand(time(0));
	ofstream outFile("TrialResults.txt", ios::app);
	int numTrials = 0, searchChoice, dataChoice, size, trials;
	while (true)
	{
		dataChoice = get_input<int>("Which type of data do you want to search:\n1. Random Integers\n2. String Names\n3. Full Testing Run (Lengthy)\n4. Exit\n", "Please enter an integer between 1 and 4.\n\n", 1, 4);
		cout<<endl;
		switch (dataChoice)
		{
			case 1: {
				searchChoice = get_input<int>("What type of search would you like to use?\n1) Binary\n2) Linear\n3) Back\n","Please enter an integer between 1 and 3.\n\n", 1, 3);
				size = get_input<int>("Enter how many elements in the array: ");
				int target = get_input<int>("Enter what number you are searching for: ");
				trials = get_input<int>("Enter how many times you want to search: ");
				if (searchChoice == 1) binaryTrialRuns(trials, outFile, size, fillIntArray, target);
				else if (searchChoice == 2) linearTrialRuns(trials, outFile, size, fillIntArray, target);
				break;
			}
			case 2: {
				searchChoice = get_input<int>("What type of search would you like to use?\n1) Binary\n2) Linear\n3) Back\n","Please enter an integer between 1 and 3.\n\n", 1, 3);
				size = 450000;
				string target;
				cout<<"Enter what last name you are searching for: ";
				cin>>target;
				trials = get_input<int>("Enter how many times you want to search: ");
				if (searchChoice == 1) binaryTrialRuns(trials, outFile, size, fillStrArray, target);
				else if (searchChoice == 2) linearTrialRuns(trials, outFile, size, fillStrArray, target);
				break;
			}
			case 3: {
				int intRuns[] = {100000000, 250000000, 500000000};
				int trials = 1000;
				cout<<"Bulk testing:\nInteger runs...\n";
				for (int size:intRuns) linearTrialRunsInt(trials, outFile, size);
				for (int size:intRuns) binaryTrialRunsInt(trials, outFile, size);
				cout<<"String runs...\n";
				outFile<<"String Test\n";
				linearTrialRunsStr(trials, outFile);
				outFile<<"String Test\n";
				binaryTrialRunsStr(trials, outFile);
				cout<<"We're done!\n";
				break;
			}
			case 4: {
				cout<<"Thank you, goodbye!";
				return 0;
			}
		}
	}
	outFile.close();
}

/*Sample output:
Which type of data do you want to search:
1. Random Integers
2. String Names
3. Full Testing Run (Lengthy)
4. Exit
3

Bulk testing:
Integer runs...
10416536
70773306
-1
98065098
17117819
201014902
229712531
84158360
221806922
-1
24756726
68256954
98498550
27417304
172240374
Position: 6204
Position: 6256
Position: 6192
Position: -1
Position: 6161
Position: 15539
Position: -1
Position: 15516
Position: 15445
Position: 15548
Position: 31121
Position: 31032
Position: 31116
Position: 31051
Position: 31149
String runs...
19634
19634
19634
19634
19634
Position: 251915
Position: 251915
Position: 251915
Position: 251915
Position: 251915
We're done!
Which type of data do you want to search:
1. Random Integers
2. String Names
3. Full Testing Run (Lengthy)
4. Exit
4

Thank you, goodbye!
--------------------------------
Process exited after 1492 seconds with return value 0
Press any key to continue . . .
*/
