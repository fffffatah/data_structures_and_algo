/*
#include<iostream>
using namespace std;
void print(const int*, int);
int main(){
//######## declaring the required variable to represent an array
    //  MAX = the size of the array
    //  N = the number of elements stored in the array
    //  Array = a pointer to an integer number
    int *Array, MAX, N;

//######## Initializing the MAX variable
    while(true){
        cout << "Enter the size of the array: ";
        cin >> MAX;
        if(MAX<1 || MAX>999)cout<<"Wrong input!!!\n";
        else break;
    }

//######## Assigning memory address to the array pointer
    Array = new int[MAX];

//########  Initializing N [how many elements to store??]
    while(true){
        cout << "Number of Elements: ";
        cin >> N;
        if(N<1 || N>MAX)cout<<"Wrong input!!!\n";
        else break;
    }

//######## Reading N Elements to store in the array
    for(int i=0; i < N; i++){
        cout<<"Array["<<i<<"] = ";
        cin >> Array[i];
    }

    int choice=0, item, pos,i;
    bool found=false;
    int cnt;
    while(true){
    //######## Choose option to do different operations on the array
      cout<<"\n0)Exit 1)Insert 2)Delete 3) Search 4)Print \nEnter option: ";
      cin>>choice;
      switch(choice){
        case 1:
            //######## check if the array is full
            if(N == MAX){
                cout<<"Array is already Full!!! Can't insert.\n";
                break;
            }

            //######## if the array is not full take inputs
            cout<<"Enter the element to insert: ";
            cin >> item;
            while(true){
                cout<<"Insert at index: ";
                cin >> pos;
                if(pos<0 || pos > N)cout<<"Wrong input!!!\n";
                else break;
            }

            //print the array before insertion
            print(Array,N);

            //######## Insertion operation starts
            //shifting all elements to right [starting from last index to the position]
            for(i = N; i > pos; i--)Array[i] = Array[i-1];
            //insert the value
            Array[pos] = item;
            // increase N by 1
            N++;
            //######## Insertion operation finished
            // print the array after insertion
            print(Array,N);
            break;
        case 2:
            //######## check if the array is empty
            if(N == 0){
                cout<<"Array is already Empty!!! Can't delete.\n";
                break;
            }
            while(true){
                cout<<"Enter Position (Index) to delete: ";
                cin >> pos;
                if(pos<0 || pos >= N)cout<<"Wrong input!!!\n";
                else break;
            }
            //print the array before deletion
            print(Array,N);
            //######## Deletion operation starts

            // COMPLETE THIS CODE
            for (i = pos; i <= N; i++){
                    Array[i] = Array [i+1];
            }
            N--;

            // IMPLEMENT DELETE OPERATION HERE

            //######## Deletion operation finished
            //print the array before deletion
            print(Array,N);
            break;
        case 3:
            //######## check if the array is empty
            cnt=0;
            if(N == 0){
                cout<<"Array is already Empty!!!\n";
                break;
            }
            cout<<"Which element to search? ";
            cin>>item;

            // COMPLETE THIS CODE
            for(i=0; i<N; i++)
        {
                if(Array[i]==item)
                {
                        cnt=1;
                        pos=i+1;
                        break;
                }
        }
        if(cnt==0)
        {
                cout<<"\n Element Not Found..!!";
        }
        else
        {
                cout<<"\n Element "<<item<<" Found At Position "<<pos;
        }
            // IMPLEMENT SEARCH OPERATION HERE


            break;
        case 4:
            print(Array,N);
            break;
        case 0:
            return 0;
      }
    }
    return 0;
}

void print(const int* a, int s){
    cout<<"\nArray: [ ";
    for(int i=0; i < s; i++)cout<<a[i]<<" ";
    cout<<"]\n";
}
*/

























#include<iostream>
using namespace std;
void insertion(int* , int& , int , int );
void deletion(int* , int& , int );
int searching(int* , int , int , int );
void print(const int*, int);

int main(){
//######## declaring the required variable to represent an array
    //  MAX = the size of the array
    //  N = the number of elements stored in the array
    //  Array = a pointer to an integer number
    int *Array, MAX, N;

//######## Initializing the MAX variable
    while(true){
        cout << "Enter the size of the array: ";
        cin >> MAX;
        if(MAX<1 || MAX>999)cout<<"Wrong input!!!\n";
        else break;
    }

//######## Assigning memory address to the array pointer
    Array = new int[MAX];

//########  Initializing N [how many elements to store??]
    while(true){
        cout << "Number of Elements: ";
        cin >> N;
        if(N<1 || N>MAX)cout<<"Wrong input!!!\n";
        else break;
    }

//######## Reading N Elements to store in the array
    for(int i=0; i < N; i++){
        cout<<"Array["<<i<<"] = ";
        cin >> Array[i];
    }

    int choice=0, item, pos,i;
    bool found=false;
    while(true){
    //######## Choose option to do different operations on the array
      cout<<"\n0)Exit 1)Insert 2)Delete 3) Search 4)Print \nEnter option: ";
      cin>>choice;
      switch(choice){
        case 1:
            //######## check if the array is full
            if(N == MAX){
                cout<<"Array is already Full!!! Can't insert.\n";
                break;
            }

            //######## if the array is not full take inputs
            cout<<"Enter the element to insert: ";
            cin >> item;
            while(true){
                cout<<"Insert at index: ";
                cin >> pos;
                if(pos<0 || pos > N)cout<<"Wrong input!!!\n";
                else break;
            }

            //print the array before insertion
            print(Array,N);

            //######## Insertion operation starts
            //shifting all elements to right [starting from last index to the position]
            insertion(Array,N,pos,item);

            break;
        case 2:
            //######## check if the array is empty
            if(N == 0){
                cout<<"Array is already Empty!!! Can't delete.\n";
                break;
            }
            while(true){
                cout<<"Enter Position (Index) to delete: ";
                cin >> pos;
                if(pos<0 || pos >= N)cout<<"Wrong input!!!\n";
                else break;
            }
            //print the array before deletion
            print(Array,N);
            //######## Deletion operation starts

            // COMPLETE THIS CODE
            deletion(Array,N,pos);
            break;
        case 3:
            //######## check if the array is empty

            if(N == 0){
                cout<<"Array is already Empty!!!\n";
                break;
            }
            cout<<"Which element to search? ";
            cin>>item;

            // COMPLETE THIS CODE
            searching(Array,N,pos,item);



            break;
        case 4:
            print(Array,N);
            break;
        case 0:
            return 0;
      }
    }
    return 0;
}
void insertion(int* a1, int& s1, int pos1, int item1){
     int i;
     for(i = s1; i > pos1; i--)a1[i] = a1[i-1];
            //insert the value
            a1[pos1] = item1;
            // increase N by 1
            s1++;
            //######## Insertion operation finished
            // print the array after insertion
            print(a1,s1);
}


void deletion(int* a2, int& s2, int pos2){
    int i;
    for (i = pos2; i <= s2; i++){
                    a2[i] = a2 [i+1];
            }
            s2--;

            // IMPLEMENT DELETE OPERATION HERE

            //######## Deletion operation finished
            //print the array before deletion
            print(a2,s2);
}


int searching(int* a3, int s3, int pos3, int item3 ){
    int i,counter=0;
    for(i=0; i<s3; i++)
        {
                if(a3[i]==item3)
                {
                        counter=1;
                        pos3=i+1;
                        break;
                }
        }
        if(counter==0)
        {
                cout<<"\n Element Not Found..!!";
        }
        else
        {
                cout<<"\n Element "<<item3<<" Found At Position "<<pos3-1;
        }
            // IMPLEMENT SEARCH OPERATION HERE


}

void print(const int* a, int s){
    cout<<"\nArray: [ ";
    for(int i=0; i < s; i++)cout<<a[i]<<" ";
    cout<<"]\n";
}
