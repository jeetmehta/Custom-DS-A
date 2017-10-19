#include <iostream>
#include <vector>

using namespace std;

void swap(vector <int> &arr, int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void print_vector(vector <int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int partitionAtEnd(vector <int> &arr, int low, int high)
{
	int pivotIdx = high;
	int pivot = arr[pivotIdx];
	int partitionIdx = low;

	for (int i = low; i < high; i++)
	{
		if (arr[i] <= pivot)
		{
			swap(arr, i, partitionIdx);
			partitionIdx++;
		}
	}

	swap(arr, partitionIdx, pivotIdx);
	return partitionIdx;
}

int partitionAtMiddle(vector <int> &arr, int low, int high)
{
	int pivot = (low + high) / 2;
	int pivotValue = arr[pivot];
	int left = low;
	int right = high;

	while (left <= right)
	{
		while (arr[left] < pivotValue)
			left++;

		while (arr[right] > pivotValue)
			right--;

		if (left <= right)
		{
			swap(arr, left, right);
			left++;
			right--;
		}
	}

	return left;
}

void quickSort(vector <int> &arr, int low, int high)
{
	if (low < high)
	{
		int partitionIdx = partitionAtEnd(arr, low, high);

		quickSort(arr, low, partitionIdx - 1);
		quickSort(arr, partitionIdx + 1, high); // change to quickSort(arr, partitionIdx, high) if using partitionAtMiddle
	}
}

int main()
{
	vector <int> testInput = {1, 3, 6, 2, 7, 4};
	quickSort(testInput, 0, testInput.size() - 1);
	print_vector(testInput);

	return 0;
}