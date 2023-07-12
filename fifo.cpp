#include<bits/stdc++.h>
using namespace std;

int pageFault(int pages[], int n, int capacity){
    unordered_set<int> us;
    queue<int> q;
    int count_fault = 0;

    for(int i = 0; i < n; i++){
        if(us.size() < capacity){
            if(us.find(pages[i]) == us.end()){
                us.insert(pages[i]);
                count_fault++;
                q.push(pages[i]);
            }
        }
        else{
            if(us.find(pages[i]) == us.end()){
                int t = q.front();
                q.pop();
                us.erase(t);
                us.insert(pages[i]);
                q.push(pages[i]);
                count_fault++;
            }
        }
    }
    return count_fault;
}
int main(){
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int capacity = 3;
    int n = sizeof(pages)/sizeof(pages[0]);
    cout<<pageFault(pages, n, capacity)<<endl;
}

