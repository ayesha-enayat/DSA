#include <iostream>

using namespace std;


int left(int i) {
  return 2 * i + 1;
}


int right(int i) {
  return 2 * i + 2;
}


int parent(int i) {
  return (i - 1) / 2;
}


void swap(int* a, int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}


void minHeapify(int arr[], int n, int i) {
  int smallest = i;
  int l = left(i);
  int r = right(i);

  
  if (l < n && arr[l] < arr[smallest]) {
    smallest = l;
  }
  if (r < n && arr[r] < arr[smallest]) {
    smallest = r;
  }

  
  if (smallest != i) {
    swap(arr, i, smallest);
    minHeapify(arr, n, smallest);
  }
}


void buildMinHeap(int arr[], int n) {
  
  for (int i = n / 2 - 1; i >= 0; i--) {
    minHeapify(arr, n, i);
  }
}


void printMinHeap(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}





int main() {
  int arr[] = {29, 7, 11, 15, 42, 81};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Min Heap representation is \n";
  buildMinHeap(arr, n);
  printMinHeap(arr, n);

 
  return 0;
}
