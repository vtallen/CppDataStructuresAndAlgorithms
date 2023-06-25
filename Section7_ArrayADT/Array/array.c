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

enum SortOrder {
  ASSCENDING,
  DESCENDING,
};

void display(struct Array arr) {
  printf("\nElements: ");
  for (int i = 0; i < arr.length; ++i) {
    printf("%d ", arr.A[i]);
  }
  printf("\n");
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

void reverseNTime(struct Array *arr) {
  int *B =  (int *)malloc(arr->size * sizeof(int));
  int j = 0;

  for (int i = arr->length - 1; i >= 0; --i) {
    B[j] = arr->A[i];
    ++j;
  }

  free(arr->A);
  arr->A = B;
}

void reverse(struct Array *arr) {
  int i = 0;
  int j = arr->length - 1;
  for (i = 0; i < j; ++i) {
    int temp = arr->A[i];
    arr->A[i] = arr->A[j];
    arr->A[j] = temp;
    --j;
  }
}

void shiftLeft(struct Array *arr) {
  assert(!(arr->length == 0) && "Can't shift an array left that only has no values");
  for (int i = 1; i < arr->length; ++i) {
    arr->A[i - 1] = arr->A[i];
  }
  --arr->length;
}

void rotateLeft(struct Array *arr) {
  int temp = arr->A[0];
  for (int i = 1; i < arr->length; ++i) {
    arr->A[i - 1] = arr->A[i];
  }
  arr->A[arr->length - 1] = temp;
}

void shiftRight(struct Array *arr) {
  for (int i = arr->length - 2; i >= 0; --i) {
    arr->A[i + 1] = arr->A[i];
  } 
  arr->A[0] = 0;
}

void rotateRight(struct Array *arr) {
  int temp = arr->A[arr->length - 1];
  for (int i = arr->length - 2; i >= 0; --i) {
    arr->A[i + 1] = arr->A[i];
  } 
  arr->A[0] = temp;
}

int isSorted(struct Array *arr, enum SortOrder order) {
  for (int i = 0; i < arr->length - 1; ++i) {
    if ((order == ASSCENDING) && !(arr->A[i + 1] > arr->A[i])) return 0; 
    if ((order == DESCENDING) && !(arr->A[i + 1] < arr->A[i])) return 0; 
  }
  return 1;
}

int sum(struct Array *arr) {
  int n = 0;
  for (int i = 0; i < arr->length; ++i) n += arr->A[i];
  return n;
}

struct Array *merge(struct Array *arr1, struct Array *arr2, enum SortOrder order) {
  if (!isSorted(arr1, order) || !isSorted(arr2, order)) return NULL;

  struct Array *newArr = (struct Array *)malloc(sizeof(struct Array));
  newArr->length = arr1->length + arr2->length;
  newArr->size = newArr->length * 2;
  newArr->A = malloc(newArr->size*sizeof(int));

  int i, j, k;
  i=j=k=0;

  while ((i < arr1->length) && (j < arr2->length)) {
    if (arr1->A[i] < arr2->A[j]) newArr->A[k++] = arr1->A[i++];
    else newArr->A[k++] = arr2->A[j++];
  }

  for (;i < arr1->length; ++i) {
    newArr->A[k++] = arr1->A[i];
  }

  for (;j < arr2->length; ++j) {
    newArr->A[k++] = arr2->A[j];
  }
  display(*newArr); 
  return newArr;
}

struct Array *unionUnsorted(struct Array *arr1, struct Array *arr2) {
  struct Array *newArr = (struct Array *)malloc(sizeof(struct Array));
  newArr->size = arr1->length + arr2->length;
  newArr->A = malloc(newArr->size * sizeof(int));
  
  int newArrLen = 0;
  // Copy all elements in arr1 into the new array
  for (int i = 0; i < arr1->length; ++i) {
    newArr->A[i] = arr1->A[i];
    ++newArrLen;
  }
  
  // Check if each element in arr2 is in newArr. If it is, skip it, if it is not, append it
  for (int i = 0; i < arr2->length; ++i) {
    int unique = 1;
    for (int j = 0; j < newArrLen; ++j) {
      if (newArr->A[j] == arr2->A[i]) unique = 0;   
    }

    if (unique == 1) {
      newArr->A[newArrLen] = arr2->A[i];
      ++newArrLen;
    }
  }
  
  newArr->length = newArrLen;
  return newArr;
}

struct Array *intersectionUnsorted(struct Array *arr1, struct Array *arr2) {
  struct Array *newArr = (struct Array *)malloc(sizeof(struct Array));
  newArr->size = arr1->length + arr2->length;
  newArr->A = malloc(newArr->size * sizeof(int));
  
  int newArrLen = 0;
  for (int i = 0; i < arr1->length; ++i) {
    int intFound = 0;
    for (int j = 0; j < arr2->length; ++j) {
      if (arr1->A[i] == arr2->A[j]) {
        intFound = 1;
        break;
      }      
    }

    if (intFound == 1) {
      newArr->A[newArrLen] = arr1->A[i];
      ++newArrLen;
    }
  }

  newArr->length = newArrLen;
  return newArr;
}

struct Array *diffUnsorted(struct Array *arr1, struct Array *arr2) {
  struct Array *newArr = (struct Array *)malloc(sizeof(struct Array));
  newArr->size = arr1->length + arr2->length;
  newArr->A = malloc(newArr->size * sizeof(int));

  int newArrLen = 0;
  
  for (int i = 0; i < arr1->length; ++i) {
    int isDuplicate = 0;
    for (int j = 0; j < arr2->length; ++j) {
      if (arr2->A[j] == arr1->A[i]) isDuplicate = 1;
    }

    if (isDuplicate == 0) {
      newArr->A[newArrLen] = arr1->A[i];
      ++newArrLen;
    }
  }

  newArr->length = newArrLen;
  return newArr;
}


struct Array *unionSorted(struct Array *arr1, struct Array *arr2, enum SortOrder order) {
  if (!isSorted(arr1, order) || !isSorted(arr2, order)) return NULL;

  struct Array *newArr = (struct Array *)malloc(sizeof(struct Array));
  newArr->size = arr1->length + arr2->length;
  newArr->A = malloc(newArr->size*sizeof(int));

  int i, j, k;
  i=j=k=0;

  while ((i < arr1->length) && (j < arr2->length)) {
    if (arr1->A[i] < arr2->A[j]) newArr->A[k++] = arr1->A[i++];
    else if (arr1->A[i] > arr2->A[j]) newArr->A[k++] = arr2->A[j++];
    else {
      newArr->A[k++] = arr1->A[i++];
      j++;
    }
  }

  for (;i < arr1->length; ++i) {
    newArr->A[k++] = arr1->A[i];
  }

  for (;j < arr2->length; ++j) {
    newArr->A[k++] = arr2->A[j];
  }
  newArr->length = k;
  return newArr;
}

struct Array *intersectionSorted(struct Array *arr1, struct Array *arr2, enum SortOrder order) {
  if (!isSorted(arr1, order) || !isSorted(arr2, order)) return NULL;

  struct Array *newArr = (struct Array *)malloc(sizeof(struct Array));
  newArr->size = arr1->length + arr2->length;
  newArr->A = malloc(newArr->size*sizeof(int));

  int i, j, k;
  i=j=k=0;

  while ((i < arr1->length) && (j < arr2->length)) {
    if (arr1->A[i] < arr2->A[j]) i++; 
    else if (arr1->A[i] > arr2->A[j]) j++; 
    else {
      newArr->A[k++] = arr1->A[i++];
      j++;
    }
  }

  newArr->length = k;
  return newArr;
}

struct Array *diffSorted(struct Array *arr1, struct Array *arr2, enum SortOrder order) {
  if (!isSorted(arr1, order) || !isSorted(arr2, order)) return NULL;

  struct Array *newArr = (struct Array *)malloc(sizeof(struct Array));
  newArr->size = arr1->length; 
  newArr->A = malloc(newArr->size*sizeof(int));

  int i, j, k;
  i=j=k=0;

  while ((i < arr1->length) && (j < arr2->length)) {
    if (arr1->A[i] < arr2->A[j]) newArr->A[k++] = arr1->A[i++]; 
    else if (arr1->A[i] > arr2->A[j]) j++; 
    else {
      i++; 
      j++;
    }
  }
  for (; i < arr1->length; i++) newArr->A[k++] = arr1->A[i];

  newArr->length = k;
  return newArr;
}

int findMissFirstN(struct Array *arr) {
  int arrSum = sum(arr);
  int lastElm = arr->A[arr->length - 1];
  int sumNaturalFormula = (lastElm * (lastElm + 1)) / 2;
  return sumNaturalFormula - arrSum;
}

int findMiss(struct Array *arr) {
  int firstElm = arr->A[0];
  for (int i = 0; i < arr->length; ++i) {
    if ((arr->A[i] - i) != firstElm) return i + firstElm;
  }

  return -1;
}

void findMultipleMissingElm(struct Array *arr) {
  int correctDiff = arr->A[0];
  for (int i = 0; i < arr->length; ++i) {
    if ((arr->A[i] - i) != correctDiff) {
      printf("Missing: %d\n", i + correctDiff);
      ++correctDiff;
    } 
  }
}

// Works only on sorted arrays
void printDuplicates(struct Array *arr) {
  int lastDup = 0;
  for (int i = 0; i < arr->length - 1; ++i) {
    if (arr->A[i] == arr->A[i + 1]) {
      if (arr->A[i + 1] != lastDup) {
        lastDup = arr->A[i];
        printf("Duplicate: %d\n", arr->A[i]);
      } 
    }
  }
}

// Works only on sorted arrays
void countDuplicates(struct Array *arr) {
  int lastDup = 0;
  for (int i = 0; i < arr->length - 1; ++i) {


    if (arr->A[i] == arr->A[i + 1]) {
      if (arr->A[i + 1] != lastDup) {
        lastDup = arr->A[i];
        printf("Duplicate: %d", arr->A[i]);
        
        int j = i + 1;
        for (; j < arr->length; ++i) {
          if (arr->A[i] == arr->A[j]) {
          } else {
            --j;
            break;
          }
        }
        printf(" | Num duplicates: %d\n", i - j);
      } 
    }
  }
}

void flush() {
   while ((getchar()) != '\n');
}

struct Array *getArray() {
  struct Array *arr = malloc(sizeof(struct Array));
  
  printf("Enter size of an array: ");
  scanf("%d", &arr->size);
  flush();

  arr->A = (int *)malloc(arr->size*sizeof(int));
  arr->length = 0;
  
  int n;
  printf("Enter number of numbers: ");
  scanf("%d", &n);
  flush();
  printf("Enter all elements:\n");
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr->A[i]);
    flush();
  }

  arr->length = n;

  return arr;
}

int main() {
  struct Array *arr = malloc(sizeof(struct Array));
  arr = getArray();
  
  display(*arr);
  findMultipleMissingElm(arr);
  printf("The missing number is %d\n", findMiss(arr));
  countDuplicates(arr);
  
}
