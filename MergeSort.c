#include <stdio.h>
int num[200];

void merge(int a, int b, int c, int d)
{
    int temp[d + 1];
    int i = 0;
    int l=a;
    while (a <= b && c <= d)
    {
        if (num[a] <= num[c])
            temp[i++] = num[a++];
        else
            temp[i++] = num[c++];
    }
    while (a <= b)
        temp[i++] = num[a++];
    while (c <= d)
        temp[i++] = num[c++];
    i=0;
    for (int j = l; j <= d; j++)
        num[j] = temp[i++];
}

void mergeSort(int left, int right)
{

    if (left == right)
        return;

    int mid = (left + right) / 2;

    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    merge(left, mid, mid + 1, right);
}

int main()
{
    int n;
    scanf("%d", &n);
    num[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", num[i]);
    }
}