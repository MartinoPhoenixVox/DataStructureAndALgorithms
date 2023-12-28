#pragma once
// reference: https://www.geeksforgeeks.org/
#include <iostream>
#define MAXSIZE 100
using namespace std;

struct Array {
	int n = 0;
	int a[MAXSIZE] = { 15, 25, 22, 16, 17, 2, 8, 3, 12, 5 };
	int InputArray() {
		if (n > 0) {
			for (int i = 0; i < n; i++) cin >> a[i];
			return 1;
		}
		return 0;
	}
	int OutputArray() {
		if (n > 0) {
			for (int i = 0; i < n; i++) cout << a[i] << " ";
			cout << endl;
			return 1;
		}
		return 0;
	}
	int LinearSearch(int x) { //no need sort
		for (int i = 0; i < n; i++) {
			if (x == a[i]) return i;
		}
		return -1;
	}
	int BinarySearch(int x) { //need sort
		int left = 0, right = n - 1, mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (a[mid] == x) return mid;
			if (x > a[mid]) left = mid + 1;
			else right = mid - 1;
		}
		return -1;
	}
	int BinarySearchRecursion(int x, int left, int right) { //first: left = 0, right = n - 1
		if (left > right) return -1;
		int mid = (left + right) / 2;
		if (a[mid] == x) return mid;
		if (a[mid] < x)
			return BinarySearchRecursion(x, mid + 1, right);
		return BinarySearchRecursion(x, left, mid - 1);
	}
	int InsertFirst(int x) {
		n++;
		if (n > 0) {
			if (n >= 2) {
				for (int i = n - 2; i >= 0; i--) {
					a[i + 1] = a[i];
					if (i == 0) a[i] = x;
				}
			}
			else a[0] = x;
			return 1;
		}
		return 0;
	}
	int InsertLast(int x) {
		n++;
		if (n > 0) {
			a[n - 1] = x;
			return 1;
		}
		return 0;
	}
	int InsertPosition(int x, int pos) {
		n++;
		if (n > 0) {
			if (n >= 2) {
				for (int i = n - 2; i >= pos; i--) {
					a[i + 1] = a[i];
					if (i == pos) a[i] = x;
				}
			}
			else a[0] = x;
			return 1;
		}
		return 0;
	}
	int DeleteFirst() {
		if (n > 0) {
			for (int i = 1; i < n; i++) {
				a[i - 1] = a[i];
				if (i == n - 1) {
					n--;
					return 1;
				}
			}
		}
		return 0;
	}
	int DeleteLast() {
		if (n > 0) {
			n--;
			return 1;
		}
		return 0;
	}
	int DeletePosition(int pos) {
		if (n > 0) {
			for (int i = pos; i < n; i++) {
				a[i] = a[i + 1];
				if (i == n - 1) {
					n--;
					return 1;
				}
			}
		}
		return 0;
	}
	int findDelFirst(int x) {
		if (LinearSearch(x) != -1) return DeletePosition(LinearSearch(x));
		return 0;
	}
	int findDelAll(int x) {
		int count = 0;
		while (LinearSearch(x) != -1) count += DeletePosition(LinearSearch(x));
		return count;
	}
	void Swap(int &a, int &b) {
		int temp = a;
		a = b;
		b = temp;
	}
	void SelectionSort() {
		int minPos;
		for (int i = 0; i < n - 1; i++) {
			minPos = i;
			for (int j = i + 1; j < n; j++)
				if (a[j] < a[minPos]) minPos = j;
			Swap(a[minPos], a[i]);
		}
	}
	void InsertionSort() {
		int x, j;
		for (int i = 1; i < n; i++) {
			x = a[i];
			j = i - 1;
			while (j >= 0 && a[j] > x) {
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = x;
		}
	}
	void BubbleSort() {
		for (int i = 0; i < n - 1; i++)
			for (int j = n - 1; j > i; j--)
				if (a[j - 1] > a[j])
					Swap(a[j], a[j - 1]);
	}
	void InterchangeSort() {
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (a[i] > a[j])
					Swap(a[i], a[j]);
	}
	void Merge(int left, int mid, int right) {
		int i, j, k;
		int n1 = mid - left + 1;
		int n2 = right - mid;
		int* Left = new int[n1]; //temporary left array
		int* Right = new int[n2]; //temporary right array
		/*each array reads the elements*/
		for (i = 0; i < n1; i++) Left[i] = a[left + i];
		for (j = 0; j < n2; j++) Right[j] = a[mid + 1 + j];
		/*mix the temporary arrays to a[left ... right]*/
		i = 0; //starting index of Left[]
		j = 0; //starting index of Right[]
		k = left; //starting index of the mixed array
		//choose the smaller element between the child arrays put into a[]
		while (i < n1 && j < n2) {
			if (Left[i] <= Right[j]) a[k] = Left[i++];
			else a[k] = Right[j++];
			k++;
		}
		/*if Right[] ends sooner, move other elements in Left[] to a[]*/
		while (i < n1) {
			a[k] = Left[i];
			i++;
			k++;
		}
		/*if Left[] ends sooner, move other elements in Right[] to a[]*/
		while (j < n2) {
			a[k] = Right[j];
			j++;
			k++;
		}
		delete[]Left;
		delete[]Right;
	}
	void MergeSort(int left, int right) { //first: left = 0, right = n - 1
		int mid;
		if (left < right) {
			mid = (left + right) / 2;
			MergeSort(left, mid);
			MergeSort(mid + 1, right);
			Merge(left, mid, right);
		}
	}
	// To heapify a subtree rooted with node i
	// which is an index in arr[].
	// n is size of heap
	void Heapify(int N, int i) {
		// Initialize largest as root
		int largest = i;

		// left = 2*i + 1
		int l = 2 * i + 1;

		// right = 2*i + 2
		int r = 2 * i + 2;

		// If left child is larger than root
		if (l < N && a[l] > a[largest])
			largest = l;

		// If right child is larger than largest
		// so far
		if (r < N && a[r] > a[largest])
			largest = r;

		// If largest is not root
		if (largest != i) {
			Swap(a[i], a[largest]);

			// Recursively heapify the affected
			// sub-tree
			Heapify(N, largest);
		}
	}
	// Main function to do heap sort
	void HeapSort()
	{

		// Build heap (rearrange array)
		for (int i = n / 2 - 1; i >= 0; i--)
			Heapify(n, i);

		// One by one extract an element
		// from heap
		for (int i = n - 1; i > 0; i--) {

			// Move current root to end
			Swap(a[0], a[i]);

			// call max heapify on the reduced heap
			Heapify(i, 0);
		}
	}
	/* This function takes last element as pivot, places
	the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
	to left of pivot and all greater elements to right
	of pivot */
	int Partition(int low, int high) {
		int pivot = a[high]; // pivot
		int i = low - 1; // Index of smaller element and indicates the right position of pivot found so far

		for (int j = low; j <= high - 1; j++) {
			// If current element is smaller than the pivot
			if (a[j] < pivot) {
				i++; //increment index of smaller element
				Swap(a[i], a[j]);
			}
		}
		Swap(a[i + 1], a[high]);
		return i + 1;

	}
	/* The main function that implements QuickSort
	arr[] --> Array to be sorted,
	low --> Starting index,
	high --> Ending index */
	void QuickSort(int low, int high) {
		if (low < high) {
			/* pi is partitioning index, arr[p] is now
		at right place */
			int pi = Partition(low, high);

			// Separately sort elements before 
			// partition and after partition 
			QuickSort(low, pi - 1);
			QuickSort(pi + 1, high);
		}
	}
};