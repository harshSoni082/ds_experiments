// Program for selection sort

#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int *selection_sort(int *arr, int size)
{
  int min_idx, idx;
  for(int i=0; i<size; i++)
  {
    idx = min_idx = i;
    while(idx<size)
    {
      if(arr[idx] < arr[min_idx])
      {
        min_idx = idx;
      }
      idx += 1;
    }
    swap(&arr[i], &arr[min_idx]);
  }
  return arr;
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

  arr = selection_sort(arr, size);
  printf("Sorted array: ");
  for(int i=0; i<size; i++)
  {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}
