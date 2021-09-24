#include<iostream>

using namespace std;

//Defining a BST node
struct node
{
    int data;
    node *left;
    node *right;
};

node * root = NULL;

//declaration of all functions used in this code
node* insertData(int);
int deleteData(int);
node *searchData(int);
void visit(node*);
void visitRootPreOrder(node*);
int minValue(node*);
int maxValue(node*);

int main()
{
    // populate BST with some values
    int n,elem,i;
    root = NULL;

    cout<<"How many elements? ";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"Element "<<i+1<<": ";
        cin>>elem;
        insertData(elem);
    }
    visit(root);

    int choice;
    while(true)
    {
        cout<<"\n1) search data\n2) add data\n3) delete data\n4) show BST\n0) Exit\nEnter option: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            //use searchData function here
            cout<<"Which element to search? ";
            cin>>elem;
            if(searchData(elem)==NULL)
                cout<<"Not found!\n";
            else
                cout<<"Found!\n";
            break;
        case 2:
            //use insertData function here
            cout<<"Which element to insert? ";
            cin>>elem;
            insertData(elem);
            break;
        case 3:
            //use deleteData here
            cout<<"Which element to delete? ";
            cin>>elem;
            //call deleteData here
            if(deleteData(elem)!=0)
            {
                cout<<"Deleted!"<<endl;
                visitRootPreOrder(root);
            }
            else
            {
                cout<<"Element not found!"<<endl;
            }

            break;
        case 4:
            visit(root);
            break;
        case 0:
            return 0;
        }
    }
    return 0;
}

//Defining a function to add a node in BST
node* insertData(int num)
{
    //create node
    node *nn=new node;
    nn->data=num;
    nn->left= NULL;
    nn->right=NULL;

    if(root == NULL)
    {
        root=nn;
    }
    else
    {
        node *child=root,*parent;
        while(child!=NULL)
        {
            parent=child;
            if(child->data < num)
                child=child->right;
            else if(child->data > num)
                child=child->left;
            else if(child->data == num)
            {
                cout<<num<< " is a duplicate data!!!\n\n";
                return NULL;
            }
        }
        if(parent->data < num)
            parent->right=nn;
        else
            parent->left=nn;
    }
    return nn;
}

void visit(node *parent)
{
    if(root == NULL)
        cout<<"Tree does not exist!\n\n";
    if(parent!=NULL)
    {
        visit(parent->right);
        cout<<parent->data<< " ";
        visit(parent->left);
    }
}

void visitRootPreOrder(node *parent)
{
    if(root == NULL)
        cout<<"Tree does not exist!\n\n";
    if(parent!=NULL)
    {

        cout<<parent->data<< " ";

        visit(parent->left);
        visit(parent->right);
    }
}

node *searchData(int num)
{
    if(root == NULL)
        cout<<"Tree does not exist!\n\n";
    else
    {
        //COMPLETE THE FUNCTION
        node *child=root;
        while(child!=NULL)
        {
            if(child->data < num)
                child=child->right;
            else if(child->data > num)
                child=child->left;
            else if(child->data == num)
            {
                return child;
            }
        }
    }
    return NULL;
}


int deleteData(int num)
{
    //implement delete function, return 1 if deleted or 0 if not found
    if(root == NULL)
    {
        cout<<"Tree does not exist!\n\n";
        return 2;
    }
    //search
    node *curr=root,*prev=NULL; int key;
    while(curr!=NULL)
    {
        if(curr->data < num)
        {
            prev=curr;
            curr=curr->right;
        }
        else if(curr->data > num)
        {
            prev=curr;
            curr=curr->left;
        }
        else if(curr->data == num)
        {
            break;
        }
    }
    //delete root
    //delete parent with two child
    if(curr->left!=NULL&&curr->right!=NULL)
    {
        if(prev->data>num)
            {
                key= minValue(prev->left);
                deleteData(key);
                curr->data=key;
                return 1;
            }
            else
            {
                key= maxValue(prev->right);
                deleteData(key);
                curr->data=key;

                return 1;
            }
    }
    //delete parent with no child
    else if(curr->left==NULL&&curr->right==NULL)
    {
        if(prev->data<num)
        {
            prev->right=NULL;
            delete(curr);
        }
        else
            prev->left=NULL;
            delete(curr);
        return 1;
    }
    //delete parent with single child
    else
    {
        if(prev->data<num)
        {
            if(curr->left!=NULL)
            {
                prev->right=curr->left;
                delete(curr);

                return 1;
            }
            else{
                prev->right=curr->right;
                delete(curr);

                return 1;
            }
        }
        else if(prev->data>num)
        {
            if(curr->left!=NULL)
            {
                prev->left=curr->left;
                delete(curr);

                return 1;
            }
            else{
                prev->right=curr->right;
                delete(curr);

                return 1;
            }
        }

    }

    return 0;

}

int minValue(node * curr)
{
    int key;
    while(curr!=NULL)
    {

        key=curr->data;
        curr=curr->right;
    }
    return key;
}
int maxValue(node * curr){

    int key;
    while(curr!=NULL)
    {

        key=curr->data;
        curr=curr->left;
    }

    return key;

}

