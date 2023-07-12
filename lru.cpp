#include<bits/stdc++.h>
using namespace std;
int pageFaults(vector<int> pages, int n, int capacity){
    unordered_set<int> us;
    unordered_map<int, int> um;
    int count_fault = 0;
    for(int i = 0; i < n; i++){
        if(us.size() < capacity){
            if(us.find(pages[i]) == us.end()){
                us.insert(pages[i]);
                count_fault++;
                }
            um[pages[i]] = i;
        }
        else{
            if(us.find(pages[i]) == us.end()){
                int lru = INT_MAX, val;
                for(auto it = us.begin(); it != us.end(); it++){
                    if(um[*it] < lru){
                        lru = um[*it];
                        val = *it;
                    }
                }
                us.erase(val);
                us.insert(pages[i]);
                count_fault++;
            }
            um[pages[i]] = i;
        }
    }
    return count_fault;
}
int main(){
    vector<int>pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int len = pages.size();
    int capacity = 3;
    //cin>>capacity;
    cout<<pageFaults(pages, len, capacity)<<endl;
}
