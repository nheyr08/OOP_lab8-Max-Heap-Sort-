#include <iostream>
#include <vector>
#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<algorithm>
#include<map>

#define INFINITY 10000
using namespace std;


	void swap(int *a, int *b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}
	void MaxHeapify(std::vector<int> &array, int root, int length) {

		int left = 2 * root,
			right = 2 * root + 1,
			largest;

		if (left <= length && array[left] > array[root])
			largest = left;
		else
			largest = root;

		if (right <= length && array[right] > array[largest])
			largest = right;

		if (largest != root) {
			swap(&array[largest], &array[root]);
			MaxHeapify(array, largest, length);
		}
	}
	void BuildMaxHeap(std::vector<int>&array) {

		for (int i = (int)array.size() / 2; i >= 1; i--) {
			MaxHeapify(array, i, (int)array.size() - 1);
		}
	}

	void MyHeapSort(std::vector<int>&array) {
		array.insert(array.begin(), 0);
		BuildMaxHeap(array);
		int size = (int)array.size() - 1;
		for (int i = (int)array.size() - 1; i >= 2; i--) {
			swap(&array[1], &array[i]);
			size--;
			MaxHeapify(array, 1, size);
		}
	}
	void PrintArray(std::vector<int> &array) {
		for (int i = 0; i < array.size(); i++) {
			cout << array[i] << "  ";
		}
		   cout << std::endl;
	}
	void PrintArrays(std::vector<int> &array) {
		for (int i = 1; i < array.size(); i++) {
			cout << array[i] << "  ";
		}
		cout << std::endl;
	}


	int main() {

	fstream  file;
	file.open("input.txt");

	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return 0;
	}

	int TestCase = 0;
	file >> TestCase;

	vector<int> v;
	for (int i = 0; i < TestCase; i++) {
		int temp;
		file >> temp;
		v.push_back(temp);
	
	}
	cout << "original:\n";
	PrintArray(v);
	MyHeapSort(v);

	cout << "sorted:\n";
	PrintArrays(v);

	return 0;
}
