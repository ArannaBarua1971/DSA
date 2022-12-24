#include <stdio.h>
 
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void selection_sort(int arr[], int n)
{
    int start, idx = 0;
    for (int i = 0; i < (n - 1); i++)
    {
        start = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (start > arr[j])
            {
                start = arr[j];
                idx = j;
            }
        }
        if (arr[i] > start)
        {
            int temp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = temp;
        }
    }
 
    print(arr, n);
}
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    print(arr, n);
}
void insertion_sort(int arr[],int n){
    int key, j;
    for (int i = 0; i < (n-1); i++)
    {
        key = arr[i + 1];
        j = i;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
        print(arr, n);
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
 
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
 
    selection_sort(arr,n);
    printf("\n");
    bubble_sort(arr,n);
    printf("\n");
    insertion_sort(arr,n);
 
}