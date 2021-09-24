/*#include<iostream>

using namespace std;

#define stack_size 10


int top= -1;
char stack[stack_size];

void push(char X){
    if(top > stack_size -1)cout<<"Overflow! \n";
    else{
        top++;
        stack[top]=X;
    }
}


bool pop(char & X){
    if(top<0){
        cout<<"Underflow!\n";
        return false;
    }

    else {
        X=stack[top];
        top--;
    }
    return true;
}


void display(){
    //define display to print all the elements in the stack

     for(int i=top; i>=0; i--)
     {
     cout << stack[i] << cout<< endl;
     }
}

int main(){
    int choice;
    while(1){
        cout<<"\n0)Exit 1)Push 2)Pop 3)Display\nOption: ";
        cin>> choice;
        if(choice==0)return 0;
        else if(choice == 1){
            char element;
            //input element and call push function
            cout<<"Input element to push: ";
            cin>>element;
            push(element);
        }

        else if(choice == 2){
            char v;
            //call pop here and assign the returned value to v
            bool c=pop(v);
            //and show the popped value
            if (c)
            cout<<"Popped value: "<<v;
        }

        else if(choice == 3){
            //call display here to show all elements in the stack
            display();
        }
        else cout<<"Wrong option!\n\n";
    }
    return 0;
}
*/




#include<iostream>

using namespace std;

#define stack_size 10


int top= -1;
int stack[stack_size];

void push(int X){
    if(top > stack_size -1)cout<<"Overflow! \n";
    else{
        top++;
        stack[top]=X;
    }
}


bool pop(int & X){
    if(top<0){
        cout<<"Underflow!\n";
        return false;
    }

    else {
        X=stack[top];
        top--;
    }
    return true;
}


void display(){
    //define display to print all the elements in the stack

     for(int i=top; i>=0; i--)
     {
     cout << stack[i]<<endl;
     }
}

int main(){
    int choice;
    while(1){
        cout<<"\n0)Exit 1)Push 2)Pop 3)Display\nOption: ";
        cin>> choice;
        if(choice==0)return 0;
        else if(choice == 1){
            int element;
            //input element and call push function
            cout<<"Input an integer to push: ";
            cin>>element;
            push(element);
        }

        else if(choice == 2){
            int v;
            //call pop here and assign the returned value to v
            bool c=pop(v);
            //and show the popped value
            if (c)
            cout<<"Popped value: "<<v;
        }

        else if(choice == 3){
            //call display here to show all elements in the stack
            display();
        }
        else cout<<"Wrong option!\n\n";
    }
    return 0;
}




