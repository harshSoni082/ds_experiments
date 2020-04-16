// Program for merge sort

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *merge(int *arr, int low, int mid, int high)
{
  int i = 0, j = 0, k = low;
  int l = mid-low+1;
  int r = high-mid;
  int *left = (int *)malloc(sizeof(int)*l+1);
  int *right = (int *)malloc(sizeof(int)*r+1);
  for(i=0; i<l; i++)
  {
    left[i] = arr[i+low];
  }
  left[i] = INT_MAX;
  for(j=0; j<r; j++)
  {
    right[j] = arr[j+mid+1];
  }
  right[j] = INT_MAX;

  i = j = 0;
  while(k <= high)
  {
    if((i < l)&&(left[i] < right[j]))
    {
      arr[k++] = left[i++];
    }
    else if((j < r)&&(right[j] <= left[i]))
    {
      arr[k++] = right[j++];
    }
  }
  return arr;
}

int *merge_sort(int *arr, int low, int high)
{
  if(low < high)
  {
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    return merge(arr, low, mid, high);
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

  merge_sort(arr, 0, size-1);
  printf("Sorted array: ");
  for(int i=0; i<size; i++)
  {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}
