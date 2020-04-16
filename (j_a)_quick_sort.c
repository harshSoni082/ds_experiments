// Program for quick sort

#include <stdio.h>

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int partition(int *arr, int low, int high)
{
  int min_idx = low - 1;
  int min_val = A[low];
  for(int i=low+1; i<high; i++)
  {
    if(arr[i] < min_val)
    {
      swap(&arr[++min_idx], &arr[i]);
    }
  }
  swap(&arr[++min_idx], min_val);

  return min_idx
}

int *quick_sort(int *arr, int low, int high)
{
  if(low < high)
  {
    int part = partition(arr, low, high);
    quick_sort(arr, low, part-1);
    quick_sort(arr, part+1, high);

    return arr;
  }
}

int main()
{
  int *arr, size;
  printf("Enter size of array to inialize: ");
  scanf("%d", &size);

  arr = (int *)malloc(sizeof(int)*size);
  printf("Enter array to sort: \n");
  for(int i=0; i<size; i++)
  {
    scanf("%d", &arr[i]);
  }

  arr = quick_sort(arr, 0, size);
  printf("Sorted array: ");
  for(int i=0; i<size; i++)
  {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}
