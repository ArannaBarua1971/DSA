#include <stdio.h>
long long int w[50], v[1000], carry[1000], idx;

void call(long long int n, long long int m)
{

    long long int vsum;
    for (int j = 0; j <= n; j++)
    {
        long long int temp = w[j];
        vsum = v[j];
        if (temp <= m)
        {
            carry[idx++] = vsum;
        }
        for (int k = 0; k <= n; k++)
        {
            if (j != k)
            {
                temp = temp + w[k];
                if (temp <= m)
                {
                    vsum += v[k];
                    carry[idx++] = vsum;
                }
                else
                {
                    temp = temp - w[k];
                }
            }
        }
    }
}

void selection_sort(int n)
{
    int start, idx = 0;
    for (int i = 0; i < (n - 1); i++)
    {
        start = w[i];
        for (int j = i + 1; j < n; j++)
        {
            if (start > w[j])
            {
                start = w[j];
                idx = j;
            }
        }
        if (w[i] > start)
        {
            int temp = w[i];
            w[i] = w[idx];
            w[idx] = temp;
            int tomp=v[i];
            v[i]=v[idx];
            v[idx]=temp;
        }
    }
 
}

int main()
{

    long long int n, m;
    scanf("%lld", &n);
    scanf("%lld", &m);

    for (long long int i = 0; i < n; i++)
    {
        scanf("%lld", &w[i]);
        scanf("%lld", &v[i]);
    }
    selection_sort(n);
    call(n - 1, m);
    long long int max = carry[0], index = 0;
    for (long long int i = 0; i < idx; i++)
    {
        if (max < carry[i])
        {
            max = carry[i];
            index = i;
        }
    }

    printf("%lld", carry[index]);
}