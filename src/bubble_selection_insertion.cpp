// SORTING IN ARRAY

#include<iostream>
using namespace std;
void print(const int*, int);
void bubbleSort(int* ,int);
void selectionSort(int* ,int);
void insertionSort(int* ,int);
int main()
{
//######## declaring the required variable to represent an array
    //  N = the number of elements stored in the array
    //  Array = a pointer to an integer number
    int *Array, N;

    while(true)
    {
        cout << "How many numbers to store: ";
        cin >> N;
        if(N<1 || N>10)cout<<"Wrong input!!!\n";
        else break;
    }

    Array = new int[N];

//######## Reading N Elements to store in the array
    for(int i=0; i < N; i++)
    {
        cout<<"Array["<<i<<"] = ";
        cin >> Array[i];
    }
    print(Array,N);
//######## Choose option to do different operations on the array
    int choice=0,item,i,firstIndex,lastIndex,midIndex,pos=-1;
    while(true)
    {
        cout<<"\n0)Exit \n1) Bubble Sorting \n2) Selection Sorting \n3) Insertion Sorting\nEnter option: ";
        cin>>choice;
        bool sorted;
        switch(choice)
        {
        case 1:
            bubbleSort(Array,N);
            break;
        case 2:
            selectionSort(Array,N);
            break;
        case 3:
            insertionSort(Array,N);
            break;
        case 0:
            return 0;
        }
    }
    return 0;
}

void bubbleSort(int* Array, int N){
    //IMPLEMENT Bubble sort here
    int i,j,SWAP;
            for(i=0; i<N-1; i++)
            {
                for(j=0; j<N-i-1; j++) //compare
                {
                    if(Array[i]<Array[j])
                    {
                        SWAP=Array[i];
                        Array[i]=Array[j];
                        Array[j]=SWAP;
                    }
                }
            }
            cout<< "After sorting: ";
            print(Array,N);
}

void selectionSort(int* Array, int N){
//IMPLEMENT Selection sort here
            int i,j,minIndex;
            for(i=0; i<N-1; i++)
            {
                minIndex = i;
                for (j = i+1; j < N; j++)
                {
                    if (Array[j] < Array[minIndex])
                        minIndex = j;
                }
                //Swap
                int SWAP=Array[minIndex];
                Array[minIndex]=Array[i];
                Array[i]=SWAP;
            }
            cout<< "After sorting: ";
            print(Array,N);
}

void insertionSort(int* Array, int N){
//IMPLEMENT Insertion sort here
            int K,i,j;
            for(i=1; i<N; i++)
            {
                K = Array[i];
                j = i-1;
                //right shifting
                while(j>=0 && Array[j]>K)
                {
                    Array[j+1] = Array[j];
                    j = j-1;
                }
                Array[j+1] = K;
            }
            cout<< "After sorting: ";
            print(Array,N);
}

void print(const int* a, int s)
{
    cout<<"\nArray: [ ";
    for(int i=0; i < s; i++)cout<<a[i]<<" ";
    cout<<"]\n";
}




/*
// A program implementing array operations including traversing (printing), searching, insertion, deletion

#include<iostream>
using namespace std;
void print(const int*, int);
int main()
{
//######## declaring the required variable to represent an array
    //  N = the number of elements stored in the array
    //  Array = a pointer to an integer number
    int *Array, N;

    while(true)
    {
        cout << "How many numbers to store: ";
        cin >> N;
        if(N<1 || N>10)cout<<"Wrong input!!!\n";
        else break;
    }

    Array = new int[N];

//######## Reading N Elements to store in the array
    cout<< "Insert elements in increasing order:";
    cout<<"\nArray[0] = ";
    cin >> Array[0];
    for(int i=1; i < N; i++)
    {
        cout<<"Array["<<i<<"] = ";
        cin >> Array[i];
        if(Array[i]<Array[i-1])
        {
            i--;
            cout<<"Not in increasing order!!\n";
            continue;
        }
    }
    print(Array,N);
//######## Choose option to do different operations on the array
    int choice=0,item,i,firstIndex,lastIndex,midIndex,pos=-1;
    while(true)
    {
        cout<<"\n0)Exit 1) Search\nEnter option: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Which element to search? ";
            cin>>item;
            pos = -1, firstIndex=0, lastIndex=N-1;
            //IMPLEMENT Binary search here
            int middleIndex;
            while(firstIndex<=lastIndex)
            {
                middleIndex=(firstIndex+lastIndex)/2;
                if(Array[middleIndex]==item)
                {
                    pos=middleIndex;
                    break;
                }
                else if(Array[middleIndex]>item)
                {
                    lastIndex=middleIndex-1;
                }
                else
                {
                    firstIndex=middleIndex+1;
                }
            }
            if(pos>=0)cout<<item<<" found at index "<<pos<<endl;
            else cout<< item<<" not found!!!\n";
            break;
        case 0:
            return 0;
        }
    }
    return 0;
}

void print(const int* a, int s)
{
    cout<<"\nArray: [ ";
    for(int i=0; i < s; i++)cout<<a[i]<<" ";
    cout<<"]\n";
}

*/
