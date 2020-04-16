// Program for insertion sort

#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int *insertion_sort(int *arr, int size)
{
  for(int idx=1; idx<size; idx++)
  {
    while((idx > 0)&&(arr[idx] < arr[idx-1]))
    {
      swap(&arr[idx], &arr[idx-1]);
      idx--;
    }
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

  arr = insertion_sort(arr, size);
  printf("Sorted array: ");
  for(int i=0; i<size; i++)
  {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}
