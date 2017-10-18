#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector <int> arr, int value, int low, int high)
{
	int middle = (low + high) / 2;

	if (arr[middle] == value)
		return middle;
	else if (low >= high)
		return -1;
	else
	{
		if (value > arr[middle])
			return binarySearch(arr, value, middle + 1, high);
		else
			return binarySearch(arr, value, low, middle);
	}
	return -1;
}

int main()
{
	vector <int> testInput = {1, 3, 2, 4, 6, 8};
    sort(testInput.begin(), testInput.end());
	int valueToFind = 3;

	int low = 0;
	int high = testInput.size() - 1;
	int index = binarySearch(testInput, valueToFind, low, high);
	
	if (index == -1)
		cout << "Value not found in array" << endl;
	else
		cout << "Value found at index: " << index << endl;

	return 0;
}