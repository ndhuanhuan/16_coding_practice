#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintArray(vector<int> arr) {
	for (auto a : arr)
		cout << a << " " << endl;
}

void Merger(vector<int>& arr, int lo, int  mi, int hi) {
	vector<int> temp(hi - lo + 1);
	int i = lo, j = mi + 1;//i is for left-hand,j is for right-hand
	int k = 0;//k is for the temporary array
	while (i <= mi && j <= hi) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	//rest elements of left-half
	while (i <= mi)
		temp[k++] = arr[i++];
	//rest elements of right-half
	while (j <= hi)
		temp[k++] = arr[j++];
	//copy the mergered temporary array to the original array
	for (k = 0, i = lo; i <= hi; ++i, ++k)
		arr[i] = temp[k];

	temp.clear();
}
void MergeSortHelper(vector<int>& arr, int lo, int hi) {
	int mid;
	if (lo < hi) {
		mid = (lo + hi) >> 1;
		MergeSortHelper(arr, lo, mid);
		MergeSortHelper(arr, mid + 1, hi);
		Merger(arr, lo, mid, hi);
	}
}
void MergeSort(vector<int>& arr) {
	int arr_size = arr.size();
	MergeSortHelper(arr, 0, arr_size - 1);
}

int main() {
	vector<int> arr = { 94, 42, 50, 95, 333, 65, 54, 456, 1, 1234 };
	 

	std::cout << "Before Merge Sort :" << std::endl;
	PrintArray(arr);

	MergeSort(arr);

	std::cout << "After Merge Sort :" << std::endl;
	PrintArray(arr);
	return (0);
}

