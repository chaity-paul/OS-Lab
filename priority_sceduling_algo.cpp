#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, burst_time[100], waiting_time[100], turn_time[100], priority[100], temp[100];
    int avg_wt = 0, avg_tat = 0;
    //freopen("input.txt", "r", stdin);
    cout<<"Number of processes : "<<endl;
    cin>>n;

    cout<<"Burst time of the processes : "<<endl;
    for(int i = 0; i < n; i++){
        cout<<"P"<<i + 1<<" : ";
        cin>>burst_time[i];
        temp[i] = i;
    }

    cout<<"process priority : "<<endl;
    for(int i = 0; i < n; i++){
        cout<<"P"<<i + 1<<" : ";
        cin>>priority[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (priority[j] < priority[i]){
                swap(priority[i], priority[j]);
                swap(burst_time[i], burst_time[j]);
                swap(temp[i], temp[j]);
            }
        }
    }
    cout<<endl<<"Process \tBurst Time \tTurn_around Time \tWaiting Time " << endl;
    waiting_time[0] = 0;
    for(int i = 0; i < n; i ++){
        turn_time[i] = burst_time[i] + waiting_time[i];
        waiting_time[i + 1] = waiting_time[i] + burst_time[i];
        avg_wt += waiting_time[i];
        avg_tat += turn_time[i];
        cout << "P" << temp[i] + 1 << "\t\t" << burst_time[i] << "\t\t" << turn_time[i] << "\t\t\t" << waiting_time[i] << endl;
    }
    cout << endl<< "Average Turn_around time: " << float(avg_tat) / n << endl;
    cout << "Average waiting Time: " << float(avg_wt) / n << endl;
}
