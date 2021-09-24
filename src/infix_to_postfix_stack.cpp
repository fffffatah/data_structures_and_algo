#include<iostream>
using namespace std;

#define stack_size 10
#define array_size 100

int top= -1;
char stack[stack_size];

void push(char X){
    if(top > stack_size -1)cout<<"Overflow! \n";
    else{
        top++;
        stack[top]=X;
    }
}

char pop(){
    char X='!';
    if(top<0){
        //cout<<"Underflow!\n";
        return X;
    }

    else {
        X=stack[top];
        top--;
    }
    return X;
}

int priority(char op){
    if(op == '+' || op == '-')return 1;
    if(op == '*' || op == '/')return 2;
    if(op=='^')return 3;
    return 0;
}

char topElement(){
    return stack[top];
}

int main(){

    char infix[array_size], postfix[array_size];
    int n, i=0;

    //read infix expression
    cout<<"Enter Infix: ";
    char s=' ';
    while( s != '\n'){
        cin.get(infix[i]);
        s=infix[i];
        if(s == ' ')continue;
        //cout<< infix[i];
        i++;
    }
    n=i-1;

    //convert to postfix
    int k=0;
    for(i=0;i<n;i++){
        char t,s=infix[i];
        if(s == '+' || s == '-' || s == '*' || s=='/' || s=='^'){
           //CODE
            int PriorityS= priority(s);
           //check the precedence of top element
           //if precedence is same or more pop else stop
           while(PriorityS<=priority(topElement())){
            postfix[k++]=pop();
           }

            push(s);

           //push the current operator to stack
        }
        else if(s == '('){
            //CODE
            push(s);
        }
        else if(s == ')'){
            //pop from stack until ( is found
            char PopUntil=pop();
            while (PopUntil!='('){
                    postfix[k++]=PopUntil;
                    PopUntil=pop();
                   }
            //and add the popped elements to postfix
        }
        else{
                postfix[k++]=s;
            // append the current symbol to postfix
        }
    }

    //pop rest elements from stack
    char t= pop();
    while(t != '!'){
        postfix[k++]=t;
        t=pop();
    }
    //print postfix expression
    cout<< "\nPostfix: ";
    for(i=0; i < k ; i++){
        cout<<postfix[i]<<" ";
    }
    cout<< "\n\n";
    return 0;
}
