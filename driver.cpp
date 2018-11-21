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
#include <fstream>
using namespace std;

void fillIntArray(int array[], int size)
{
	for(int i = 0; i < size; i++)
		array[i] = rand();
}

void fillStrArray(string array[], int size)
{
	ifstream inFile("LastName2010new.txt"); //435670 items
	for(int i = 0; i < size; i++)
	{
		getline(inFile, array[i]);
	}
}

template<class T>
void linearTrialRuns(int trials, ofstream &outFile, int size, void fillArray(T[], int), T target)
{
	T **array = new T*[trials];
	for(int i=0; i < trials; i++)
		array[i] = new T[size];
	for(int j = 0; j < trials; j++)
	{
		fillArray(&array[j][0], size);
	}

	double start = double(clock()) / CLOCKS_PER_SEC; //starts timer

	for (int i=1; i<=trials; i++)
	{
		linearSearch(&array[i-1][0], size, target);
	}
	outFile << fixed << showpoint << setprecision (5) << "Algorithm: Linear Search"<<endl;
	double finish = double(clock()) / CLOCKS_PER_SEC;														   
	double elapsed = (finish - start);  //Takes final time - beginning time, to get time to complete all iterative trials
	double average = (finish - start)/trials;//finds average time to complete each trial
	outFile << "Time Elapsed: " << setw(5) << elapsed << " seconds" << endl; //displays elapsed time
	outFile << "Average time trial over " << trials << " times: " << setw(5) << average << " seconds with "<<size<< " elements\n" <<endl; //displays average time
	for(int i=0; i < trials; i++)
		delete[] array[i];
	delete[] array;
}

int main()
{
	
}
