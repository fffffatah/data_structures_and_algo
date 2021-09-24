//NAME: A.F.M. NOORULLAH
//ID: 18-38830-3
//COURSE: ALGORITHMS
//SECTION: D

#include <iostream>
#include <stdlib.h>
#include <cstring>
#define MAX_FINAL_ARR_SIZE 100

using namespace std;

struct Activity{
    string act_name;
    int act_start;
    int act_finish;
};

void Show(Activity act_arr[], int arr_size){
    cout<<"Activity Name: Starting Time -> Finishing Time\n----------------------------------------------\n";
    for(int i=0; i<arr_size; i++){
        cout<<act_arr[i].act_name<<": "<<act_arr[i].act_start<<" -> "<<act_arr[i].act_finish<<"\n";
    }
}

void TakeInput(Activity initial_act_arr[], int arr_size){
    for(int i=0; i<arr_size; i++){
        cout<<"ACTIVITY SELECTION PROBLEM(FOR INTEGER TIME)\n-----------------------------------------------\n";
        cout<<"Input Details for Activity "<<(i+1)<<"\n--------------------------\n";
        cout<<"Activity Name: ";
        cin>>initial_act_arr[i].act_name;
        cout<<"Activity Starting Time: ";
        cin>>initial_act_arr[i].act_start;
        cout<<"Activity Finishing Time: ";
        cin>>initial_act_arr[i].act_finish;
        system("CLS");
    }
}

void CompareAct(Activity initial_act_arr[], Activity final_act_arr[], int &arr_size){
    int i=0;
    final_act_arr[0]=initial_act_arr[0];//TAKE THE FIRST ACTIVITY IN FINAL ARRAY
    for(int j=1; j<arr_size; j++){
        //IF THE FINISHING TIME OF ACTIVITY AT I'TH INDEX OF FINAL ARRAY IS LESS THAN OR EQUAL TO
        //THE STARTING TIME OF ACTIVITY AT J'TH INDEX OF INITIAL ARRAY THEN
        //INCREMENT I BY ONE AND PLACE THE ACTIVITY OF INITIAL ARRAY AT J'TH INDEX IN ALREADY
        //INCREMENTED I'TH INDEX OF FINAL ARRAY
        if(final_act_arr[i].act_finish <= initial_act_arr[j].act_start){
            i++;
            final_act_arr[i]=initial_act_arr[j];
        }
    }
    //THE NEW ARRAY SIZE WILL BE THE NUMBER OF INCREMENTETION OF I PLUS 1
    arr_size = ++i;
}

void SortAct(Activity initial_act_arr[], int arr_size){
    //SORT THE ARRAY IN ASCENDING ORDER BASED ON THE FINISHING TIME (INSERTION SORT)
    int j;
    Activity key;
    for(int i=1; i<arr_size; i++){
        key=initial_act_arr[i];
        j=i-1;
        while(j>=0 && initial_act_arr[j].act_finish>key.act_finish){
            initial_act_arr[j+1]=initial_act_arr[j];
            j--;
        }
        initial_act_arr[j+1]=key;
    }
}

int main(){
    int arr_size;
    cout<<"Input the number of activities: ";
    cin>>arr_size;

    //THIS IS THE INITIAL ARRAY WHICH HOLDS THE INPUTED ACTIVITIES AS IT IS
    Activity initial_act_arr[arr_size];
    //THIS IS THE FINAL ARRAY WHICH WILL HOLD THE COMPATIBLE ACTIVITIES AFTER COMPARISON
    Activity final_act_arr[MAX_FINAL_ARR_SIZE];
    system("CLS");

    //TAKING INPUT FOR THE STRUCT ARRAY
    TakeInput(initial_act_arr,arr_size);

    //CALLING SHOW METHOD TO PRINT THE INPUTED DATA AS IT IS
    cout<<"INPUTED ACTIVITIES\n---------------------\n";
    Show(initial_act_arr,arr_size);

    //SORT AND CALL COMPARE METHOD TO COMPARE EACH ACTIVITY TO FIND OVERLAPPING ACTIVITIES
    SortAct(initial_act_arr,arr_size);
    CompareAct(initial_act_arr,final_act_arr,arr_size);

    //CALLING SHOW METHOD TO PRINT THE FINAL ARRAY
    cout<<"\nCOMPATIBLE ACTIVITIES\n---------------------\n";
    Show(final_act_arr,arr_size);
    return 0;
}
