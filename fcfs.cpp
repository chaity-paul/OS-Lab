#include<bits/stdc++.h>
using namespace std;
int main(){
    int p[100], b[100], w[100], tat[100], avwt = 0, avtat = 0, n;
    cout<<"Enter total number of process : "<<endl;
    cin>>n;

    for(int i = 0; i < n; i++){
        cout<<"p["<<i+1<<"] : ";
        cin>>b[i];
    }

    w[0] = 0;
    for(int i = 1; i < n; i ++){
        w[i] = w[i - 1] + b[i - 1];
    }

    for(int i = 0; i < n; i ++){
        tat[i] = b[i] + w[i];
        avwt += w[i];
        avtat += tat[i];
    }

    avwt /= n;
    avtat /= n;

    cout<<"Processes\tBurst Time\twaiting time\tturnaround time"<<endl;

    for(int i = 0; i < n; i++){
        cout<<"P["<<i+1<<"]\t\t"<<b[i]<<"\t\t"<<w[i]<<"\t\t"<<tat[i]<<endl;
    }

    cout << "\nAverage waiting time: " << avwt;
    cout << "\nAverage turn around time: " << avtat << endl;
}
