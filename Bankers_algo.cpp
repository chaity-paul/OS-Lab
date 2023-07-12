#include<bits/stdc++.h>
using namespace std;

int allocation[10][10], max_need[10][10], need[10][10];
int available[10];
int np, nr;

void read_matrix(int matrix[10][10]){
    for(int i = 0; i < np; i++){
        for(int j = 0; j < nr; j++){
            cin>>matrix[i][j];
        }
    }
}

void display_matrix(int matrix[10][10]){
    for(int i = 0; i < np; i++){
        for(int j = 0; j < nr; j++){
            cout<<matrix[i][j]<<' ';
        }
        cout<<endl;
    }
}

void count_need(){
    for(int i = 0; i < np; i++){
        for(int j = 0; j < nr; j++){
            need[i][j] = max_need[i][j] - allocation[i][j];
        }
    }
}

void Banker(){
    int finish[10] = {0};
    int safe_seq[10];
    int i, j, flag, k = 0;
    for(i = 0; i < np; i++){
        flag = 0;
      if(finish[i] == 0){
         for(j = 0; j < nr; j++){
             if(need[i][j] > available[j]){
                flag = 1;
                break;
             }
         }
      if(flag == 0){
         finish[i] = 1;
         safe_seq[k] = i + 1;
         k++;
         for(j = 0; j < nr; j++){
            available[j] += allocation[i][j];
         }
         i = -1;
      }
    }
    }

     flag = 0;
     for(i = 0; i < np; i++){
        if(finish[i] == 0){
            flag = 1;
            cout<<"The system is in deadlock"<<endl;
            break;
        }
     }
     if(flag == 0){
        cout<<"The system is in safe state"<<endl<<"The safe sequence is : ";
        for(i = 0; i < np; i++){
            cout<<'P'<<safe_seq[i]<<' ';
        }
        cout<<endl;
     }

}
    int main(){
        freopen("input.txt", "r", stdin);
        cout<<"Enter the number of process : ";
        cin>>np;
        cout<<endl<<"Enter the number of resources : ";
        cin>>nr;
        cout<<endl<<"Enter the allocation matrix : "<<endl;
        read_matrix(allocation);
        cout<<"Enter the max need matrix : " <<endl;
        read_matrix(max_need);
        cout<<"Enter the available resources : "<<endl;
        for(int i = 0; i < nr; i++){
            cin>>available[i];
        }

        //display
        cout<<"*********Entered data is**********"<<endl;
        cout<<"Allocation :"<<endl;
        display_matrix(allocation);
        cout<<"Max need :"<<endl;
        display_matrix(max_need);
        cout<<"Available resource :"<<endl;
        for(int i = 0; i < nr; i++){
            cout<<available[i]<<' ';
        }
        cout<<endl;
        count_need();

        cout<<"Remaining need :"<<endl;
        display_matrix(need);
        Banker();
        return 0;

    }
