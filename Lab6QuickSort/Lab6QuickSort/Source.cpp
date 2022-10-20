#include "Sort.h"
void print(int* arr, int size) {
	cout << endl << "Massive: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}
int Partition(int* arr, int low, int high) {
	int p = arr[high];
	int i = low - 1;
	for (int j = low; j < high; j++) {

		if (arr[j] <= p) {
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

		}
		cout << endl << j << " " << i << endl;

	}

	int temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;


	return i + 1;
}
void QuickSort(int* A, int p, int r) {
	if (p < r) {
		int q = Partition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
	}
}
int RandomizedPartition(int* arr, int p, int r) {
	int i = rand() % (r - p) + p;
	int temp = arr[i];
	arr[i] = arr[r];
	arr[r] = temp;
	return Partition(arr, p, r);
}
void RandomQuickSort(int* A, int p, int r) {
	if (p < r) {
		int q = RandomizedPartition(A, p, r);
		RandomQuickSort(A, p, q - 1);
		RandomQuickSort(A, q + 1, r);
	}
}