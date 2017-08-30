#include <bits/stdc++.h>
using namespace std;

int Merge(int Arr[], int l, int m, int r)
{
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1], R[n2];

    for(i=0; i<n1; i++)
        L[i] = Arr[l+i];
    for(j=0; j<n2; j++)
        R[j] = Arr[m+1+j];

    i=0;j=0;k=l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            Arr[k] = L[i];
            i++;
        }

        else
        {
            Arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        Arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        Arr[k] = R[j];
        j++;
        k++;
    }
}

int MergeSort(int Arr[], int l, int r)
{
    if(l<r)
    {
        int m = l+(r-l)/2;

        MergeSort(Arr,l,m);
        MergeSort(Arr,m+1,r);

        Merge(Arr,l,m,r);
    }
}

int PrintArray(int A[], int size)
{
    for(int i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int Arr[] = {10,5,1,9,3,6,7,4,2,8};
    int Arr_size = sizeof(Arr)/sizeof(Arr[0]);

    cout << "Given Array is " << endl;
    PrintArray(Arr, Arr_size);

    MergeSort(Arr, 0, Arr_size - 1);

    cout << "Sorted Array is " << endl;
    PrintArray(Arr, Arr_size);

    return 0;
}
