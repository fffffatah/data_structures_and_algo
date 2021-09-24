/*
This code define four functions namely insertion, deletion, search and traverse
for linked list data structure.
*/
#include<iostream>
using namespace std;

//Defining the node
struct node
{
    int data;
    node * link;
};

//initializing head (first node) to null
node *head=NULL;

//Defining a function to add a node after a previous node
node* addNode(int num, node * prev=NULL)
{
    // creating the node
    node *newNode = new node;
    newNode -> data = num;
    newNode -> link = NULL;

    //adding node at head (prev = null)
    if(prev==NULL){
        newNode->link = head;
        head = newNode;
    }

    //adding node after previous
    else
    {
        newNode->link = prev->link;
        prev->link =newNode;
    }
    return newNode;
}

// Now implement a function named deleteNode to delete a node (data)


void show()
{
    node * curr = head;
    while(curr != NULL)
    {
        cout<< curr->data << "->";
        curr = curr->link;
    }
    cout<<"\n\n";
}

/*
Now implement a function named searchData to search a particular value.
The function should return address of the node where the search element is found
otherwise return NULL.
*/
node* searchData(int key){
    //COMPLETE THE FUNCTION
    node * curr = head; int pos=0,flag=0;
    if (head==NULL){
        cout<<"\nLinked list already empty!";
    }
    while(curr != NULL)
    {
        pos++; //increase position on each check
        if (curr->data==key){
            cout<<"\n";
            cout<<"Found " <<key<<" at position: "<<pos;
            flag++;//increase flag by one if found
            break;
        }
        else{
        curr = curr->link;}
    }
    if(flag==0){cout<<"\nElement not found!";}
    return curr;
}

node *deleteData(int pos){
    //delete data from linked list
    node * curr = head; node *prev=NULL; int counter=1;
        while(counter!=pos)
        {
            prev=curr;
            curr=curr->link;
            counter++;//increase counter until it is same as the position of the element to delete
        }
        if(counter==pos)
        {
            cout<<"\nDeleted Element is: "<<curr->data;
            prev->link=curr->link;
        }
        else
            cout<<"\nCan't delete!";
    return 0;
}


int main()
{
    // populate linked list with some values
    int n,elem,i;
    head = NULL;

    cout<<"How many elements? ";
    cin>>n;
    node *p=NULL,*tmp;
    for(i=0; i<n; i++)
    {
        cout<<"Element "<<i+1<<": ";
        cin>>elem;
        p = addNode(elem,p);
    }
    show();

    int choice;
    while(true)
    {
        cout<<"\n1) search data\n2) add data\n3) add data at head\n4) delete data\n5) show List\n0) Exit\nEnter option: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            //use searchData function here
            cout<<"\nWhich element to search? : "; cin>>elem;
            searchData(elem);
            break;
        case 2:
            //use addData function here
            cout<<"\nAfter which element to insert? ";
            cin>>elem;
            tmp = searchData(elem);
            if(tmp == NULL)
                cout<<elem <<" does not exist in the linked list!\n";
            else
            {
                cout<<"Which element to insert? ";
                cin>>elem;
                addNode(elem,tmp);
            }
            break;
        case 3:
            cout<<"Which element to insert? ";
            cin>>elem;
            addNode(elem);
            break;
        case 4:
            //use deleteData here
            cout<<"Enter the position of the element to delete: ";
            cin>>elem;
            deleteData(elem);
            break;
        case 5:
            show();
            break;
        case 0:
            return 0;
        }
    }


    return 0;
}
