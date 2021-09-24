#include <iostream>

using namespace std;

void Merge(int arr[], int first, int mid, int last){

     int scndArr[last-first+1],k=0, tempFirst=first, m=mid+1;

     for(int i=first; i<=last; i++){
        if(tempFirst>mid){
            scndArr[k++]=arr[m++];
        }
        else if(m>last){
            scndArr[k++]=arr[tempFirst++];
        }
        else if(arr[tempFirst]<arr[m]){
            scndArr[k++]=arr[tempFirst++];
        }
        else{
            scndArr[k++]=arr[m++];
        }
     }

     for(int i=0; i<k; i++){
        arr[first++]=scndArr[i];
     }
}

void MergeSort(int arr[], int first,int last){
     if(first<last){
        int mid=(first+last)/2;
        MergeSort(arr,first,mid);
        MergeSort(arr,mid+1,last);
        Merge(arr,first,mid,last);
     }
}

void Show(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<"Index["<<i<<"]= "<<arr[i]<<"\n";
    }
}

int main()
{
    int n;
    cout<<"MERGE SORT\n=============\n";
    cout<<"Input the size of the array: ";
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cout<<"Input at Index["<<i<<"]= ";
        cin>>arr[i];
    }
    MergeSort(arr,0,n-1);
    Show(arr,n);
    return 0;
}
