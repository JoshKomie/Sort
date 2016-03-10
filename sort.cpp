//josh komie 3/10/16
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include <string>
using namespace std;

int main()
{
	srand(time(NULL));

	while (1)
	{
		cout << "would you like to (t)est or (q)uit\n";
		string input;
		cin >> input;
		if (input.compare("t") == 0)
		{
			cout << "running test" << endl;
			int asc[SIZE], dsc[SIZE], rd[SIZE];
			cout << "Running Mergesort test" << endl;
			createInputData(asc, dsc, rd);
			cout << "Mergesort the ascending array..." << endl;
			mergesort(asc, SIZE);
			cout << "Mergesort the descending array..." << endl;
			mergesort(dsc, SIZE);
			cout << "Mergesort the random array..." << endl;
			mergesort(rd, SIZE);

			cout << "Running Quicksort test" << endl;
			createInputData(asc, dsc, rd);
			cout << "Quicksort the ascending array..." << endl;
			quicksort(asc, SIZE);
			cout << "Quicksort the descending array..." << endl;
			quicksort(dsc, SIZE);
			cout << "Quicksort the random array..." << endl;
			quicksort(rd, SIZE);

			cout << "Running insertionsort test" << endl;
			createInputData(asc, dsc, rd);
			cout << "insertionsort the ascending array..." << endl;
			insertionsort(asc, SIZE);
			cout << "insertionsort the descending array..." << endl;
			insertionsort(dsc, SIZE);
			cout << "insertionsort the random array..." << endl;
			insertionsort(rd, SIZE);

			
		}
		else if (input.compare("q") == 0)
		{
			return 0;
		}
		
	}

}

///////////////////////////////////////////////////////////////////////////
//Utility functions
///////////////////////////////////////////////////////////////////////////
void print(int values[], int length)
{
	cout << "[" ;
	for (int i = 0; i < length; i++)
	{
		cout << values[i];
		if (i != length - 1)
			cout << ", ";
	}
	cout << "]" << endl;
}

//copy array A into array B
void copy(int B[], int A[], int start, int end)
{
	for (int i = start; i < end; i++)
	{
		B[i] = A[i];
	}
}

int random(int low, int high)
{
	int range = high - low;
	return rand() % range + low;
}

void swap(int &one, int &two)
{
	int temp = one;
	one = two;
	two = temp;
}

void createInputData(int asc[], int dsc[], int rd[])
{
	for (int i = 0; i < SIZE; i++)
	{
		asc[i] = i;
		dsc[i] = SIZE - 1 - i;
		rd[i] = random(0, SIZE);
	}
	cout << "Created 3 arrays with length " << SIZE << ": one ascending, one descending, and one random" << endl;
}

///////////////////////////////////////////////////////////////////////////
//Quick Sort
///////////////////////////////////////////////////////////////////////////
void quicksort(int A[], int length)
{
	qsort(A, 0, length - 1);
}
void qsort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = randomPartition(A, p, r);
		qsort(A, p, q - 1);
		qsort(A, q + 1, r);
	}
}

int partition(int A[], int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for(int j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			i = i + 1;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

int randomPartition(int A[], int p, int r)
{
	int i = random(p, r);
	swap(A[r], A[i]);
	return partition(A, p, r);
}

///////////////////////////////////////////////////////////////////////////
//Merge Sort
///////////////////////////////////////////////////////////////////////////
void mergesort(int A[], int length)
{
	int * B = new int[length];
	divide(A, B, 0, length);
}

void divide(int A[], int B[], int start, int end)
{
	if ((end - start) < 2)
		return;
	int middle = (end + start) / 2;
	divide(A, B, start, middle);
	divide(A, B, middle, end);
	merge(A, B, start, middle, end);
	copy(A, B, start, end);
}

void merge(int A[], int B[], int start, int mid, int end)
{
	int i = start, j = mid;
	for (int k = start; k < end; k++)
	{
		if (i < mid && (j >= end || A[i] <= A[j]))
		{
			B[k] = A[i];
			i = i + 1;
		}
		else
		{
			B[k] = A[j];
			j = j + 1;
		}
	}
}

///////////////////////////////////////////////////////////////////////////
//Insertion Sort
///////////////////////////////////////////////////////////////////////////

void insertionsort(int A[], int length)
{
	for (int i = 1; i < length; i++)
	{
		int j = i;
		while (j > 0 && A[j - 1] > A[j])
		{
			swap(A[j], A[j - 1]);
			j = j - 1;
		}
	}
}