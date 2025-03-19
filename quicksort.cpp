#include <iostream>
#include <algorithm>

using namespace std;

int partition(int arr[], int low, int high);
void printArray(int arr[], int size);
void quicksort(int arr[], int low, int high);


int main()
{
	const int SIZE = 6;

	int arr[SIZE] = {4, 7, 1, 9, 2, 3};

	printArray(arr, SIZE);
	quicksort(arr, 0, SIZE-1);
	printArray(arr, SIZE);

	return 0;
}


void printArray(int arr[], int size)
{
	for (int i=0; i<size; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}


int partition(int arr[], int low, int high)
{
	int pivot = arr[high];

	int i = low-1;

	for (int j=low; j<=high-1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[high]);
	return i+1;
}

void quicksort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quicksort(arr, low, pi-1);
		quicksort(arr, pi+1, high);
	}
}

