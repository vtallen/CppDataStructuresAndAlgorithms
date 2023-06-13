#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define bool int
#define true 1
#define false 0

struct Array {
  int *A;
  int size;
  int length;
};

void display(struct Array arr) {
  printf("\nElements: ");
  for (int i = 0; i < arr.length; ++i) {
    printf("%d ", arr.A[i]);
  }
}

void swap(struct Array *arr, int pos1, int pos2) {
  if ((pos1 > arr->length) || (pos2 > arr->length)) return;
  int temp = arr->A[pos1];
  arr->A[pos1] = arr->A[pos2];
  arr->A[pos2] = temp;
}

void append(struct Array *arr, int data) {
  if (arr->length == arr->size) return; // resize(arr, arr.size * 2)
  
  arr->A[arr->length] = data;
  arr->length++;
}

void insert(struct Array *arr, int index, int data) {
  if (arr->length == arr->size) return; // resize(arr, arr.size * 2)

  for (int i = arr->length; i > index; --i) {
    arr->A[i + 1] = arr->A[i];
  }

  arr->A[index] = data;
  ++arr->length;
}

void delete(struct Array *arr, int index) {
  if (index > arr->length) return;
  
  for (int i = index; i < arr->length; ++i) {
    arr->A[i] = arr->A[i + 1];
  }

  --arr->length;
}

int search(struct Array *arr, int data) {
  for (int i = 0; i < arr->length; ++i) {
    if (arr->A[i] == data) return i;
  }

  return -1;
}

int bs(struct Array *arr, int data) {
  int l = 0;
  int h = arr->length;
  int mid = 0;

  while (l <= h) {
    mid = (l + h) / 2;
    if (arr->A[mid] == data) return mid;
    else if (data < arr->A[mid]) h = mid - 1;
    else if (data > arr->A[mid]) l = mid - 1;
  }
  return -1;
}

int bsRec(struct Array *arr, int l, int h, int data) {
  int mid = (l+h) / 2;
  if (l <= h) {
    if (arr->A[mid] == data) return mid;
    else if(data < arr->A[mid]) return bsRec(arr, l, mid - 1, data);
    else if (data > arr->A[mid]) return bsRec(arr, mid - 1, h, data);
  } 
  return -1;
}

int get(struct Array *arr, int index) {
  assert((index < arr->length) && "Index out of bounds");
  return arr->A[index];
}

void set(struct Array *arr, int index, int data) {
  assert((index < arr->length) && "Index out of bounds");
  arr->A[index] = data;
}

int max(struct Array *arr) {
  int maxN = 0;
  for (int i = 0; i < arr->length; ++i) {
    if (arr->A[i] > maxN) maxN = arr->A[i];
  }
  return maxN;
}

int main() {
  struct Array arr;
  printf("Enter size of an array:");
  scanf("%d", &arr.size);

  arr.A = (int *)malloc(arr.size*sizeof(int));
  arr.length = 0;
  
  int n;
  printf("Enter number of numbers:");
  scanf("%d", &n);
  printf("Enter all elements\n");
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr.A[i]);
  }

  arr.length = n;

  display(arr);
  printf("index of 1 using bs: %d\n", bs(&arr, 1));
  printf("getting value at index 2: %d", get(&arr, 2));
  printf("Mad number in the list is %d", max(&arr));
}
