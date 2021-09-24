#include <iostream>
#include <stdlib.h>

using namespace std;

void _countingSort(int arr,)

int _partition(int arr[],int first, int last)
{
    i = first + 1;
    piv = arr[first] ;
    for( j =first + 1; j <= last ; j++ )
    {
        if ( arr[ j ] < piv)
        {
            swap (arr[ i ],arr[ j ]);
            i += 1;
        }
    }
    swap ( arr[ first ],arr[ i-1 ] ) ;
    return i-1;
}
void _quickSort(int arr[], int first, int last)
{
    if( start < end )
    {
        int piv_pos = Partition (arr,first,last ) ;
        _quickSort(arr, first, piv_pos -1);
        _quickSort(arr, piv_pos +1, last) ;
    }
}

void _merge(int A[], int first,int mid, int last)
{
    int i = first,j = mid+1,i;
    int Arr[last-first+1], k=0;
    for(z = first ; z <= end ; z++)
    {
        if(i > mid)
            Arr[ k++ ] = A[ j++] ;
        else if ( j > end)
            Arr[ k++ ] = A[ i++ ];
        else if( A[ i ] < A[ j ])
            Arr[ k++ ] = A[ i++ ];
        else
            Arr[ k++ ] = A[ j++];
    }
    for (int p=0 ; p< k ; p ++)
        A[ first++ ] = Arr[ p ] ;
}
void _mergeSort(int arr[], int first, int last)
{
    if( first < last )
    {
        int mid = (first + last ) / 2 ;
        _mergeSort(A, first, mid );
        _mergeSort(A,mid+1, last );
        _merge(arr,first, mid, last );
    }
}

void _selectionSort(int arr[], int n)
{
    int select, minIndex, minValue;
    for(select=0; select<n-1; select++)
    {
        minIndex=select;
        minValue=arr[select];
        for(int i=select+1; i<n; i++)
        {
            if(arr[i]<minValue)
            {
                minValue=arr[i];
                minIndex=i;
            }
        }
        arr[minIndex]=arr[i];
        minIndex=i;
    }
}

void _insertionSort(int arr, int n)
{
    int key,j;
    for(int i=0; i<n; i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void _bubbleSort(int arr[], int n)
{
    int flag;
    for(int i=1; i<n; i++)
    {
        flag=0;
        for(int j=0; j<n-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j+1],arr[j]);
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

void _takeInput(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"Input at Index["<<i<<"]= ";
        cin>>arr[i];
    }
}

void _show(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"Index["<<i<<"]= "<<arr[i]<<"\n";
    }
}

void _menu(int arr[], int n){
    int choice=1;
    while(choice){
        cout<<"MENU--------\n1)Bubble Sort\n2)Insertion Sort\n3)Merge Sort\n4)Quick Sort\n5)Counting Sort\n6)Selection Sort\n7)Binary Search\n0)EXIT\nCHOICE: ";
        cin>>choice;
        switch(choice){
    case 1:
        _bubbleSort(arr,n);
        system("CLS");
        _show(arr,n);
        break;
    case 2:
        _insertionSort(arr,n);
        system("CLS");
        _show(arr,n);
        break;
    case 3:

        }
    }
}

int main()
{
    int choice=1, n;
    cout<<"Enter the array size: ";
    cin>>n;
    int arr[n];
    _takeInput(arr,n);

}
