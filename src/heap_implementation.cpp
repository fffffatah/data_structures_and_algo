//Heap
#include<iostream>
using namespace std;

const int MAX_SIZE=100;
int Heap[MAX_SIZE+1], N=0;

void Heapify()
{
    int p=N/2,swapCount=0;
    while(p>=1) //repeat for each parent
    {
        int curr=p,lc=curr*2, rc=lc+1, sm;
        while(lc<=N) //repeat till leaf nodes are reached
        {
            if(rc>N)sm=lc;
            else sm=Heap[lc]<Heap[rc]?lc:rc;
            if(Heap[curr]>Heap[sm])
            {
                int tmp=Heap[curr];
                Heap[curr]=Heap[sm];
                Heap[sm]=tmp;
                swapCount++;
                curr=sm;
                lc=curr*2;
                rc=lc+1;
            }
            else break;
        }
        p--;
    }
    cout<<"Total Swap: "<<swapCount<<"\n\n";
}

int insertHeap(int data)
{
    //implement this function
    Heap[N++]=data;
    int p=N/2,SWAP;
    while(p!=0)
    {
        if(Heap[p]>data)
        {
            SWAP=Heap[p];
            Heap[p]=data;
            Heap[N]=SWAP;
        }
        p=p/2;
    }
}
int deleteRoot()
{
    //implement this function
    int SWAP,p=1,SChild;
    SWAP=Heap[1];
    Heap[1]=Heap[N];
    Heap[N]=SWAP;
    N--;
    while(p<=N/2)
    {
        int LC=p*2,RC=p*2+1;
        //find smaller child between right and left
        if(RC>N||Heap[LC]<Heap[RC]){
            SChild=LC;
        }
        else {
            SChild=RC;
        }
        //swap
        if(Heap[p]>Heap[SChild])
        {
            SWAP=Heap[p];
            Heap[p]=Heap[SChild];
            Heap[SChild]=SWAP;
            p=SChild;
        }
    }
}

void sortHeap()
{
    int tmp=N;
    for(int i=0; i<tmp; i++)deleteRoot();
    cout<<"Sorted List: ";
    for(int i=1; i<=tmp; i++)cout<<Heap[i]<<" ";
    cout<<"\n\n";
    N=tmp;
    Heapify();
}

void showHeap()
{
    if(N>0)
    {
        for(int i=1; i<=N; i++)cout<<Heap[i]<<" ";
        cout<<"\n\n";
    }
    else cout<<"Heap does not exist!\n\n";
}

int main()
{
    //cout<<"Enter Number of elements? ";
    //cin>> N;
    //while(N<1 || N>100){
    //    cout<<"Enter a value less than 100\n\n";
    //    cin>> N;
    //}
    N=12;
    int a[13]= {0,45,38,30,32,40,15,5,43,20,10,35,25};
    for(int i=1; i<=N; i++)
    {
        //cout<<"Heap["<<i<<"]: ";
        //cin>>Heap[i];
        Heap[i]=a[i];
    }


    showHeap();
    Heapify();
    showHeap();

    while(1)
    {
        int choice=-1;
        cout<<"0) Exit\n1) Insert\n2) Delete root\n3) sort \nEnter Option: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            int value;
            cout<<"Enter a value to insert: ";
            cin>>value;
            insertHeap(value);
            showHeap();
            break;
        case 2:
            deleteRoot();
            showHeap();
            break;
        case 3:
            sortHeap();
            showHeap();
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }
    return 0;
}
