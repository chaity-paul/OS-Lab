#include<bits/stdc++.h>
using namespace std;
void firstFit(vector<int> holes, vector<int> pages, int n, int l){
    cout<<"First fit : "<<endl;
    cout<<"Page"<<"\tblock"<<endl;
    for(int i = 0; i < l; i++){
        bool t = 0;
        int ans;
        for(int j = 0; j < n; j++){
            if(holes[j] >= pages[i]){
                ans = j + 1;
                holes[j] -= pages[i];
                t = 1;
                break;
            }
        }
        if(!t)
            cout<<pages[i]<<"\tNot allocated "<<endl;
        else{
            cout<<pages[i]<<"\t"<<ans<<endl;
        }
    }
}
void bestFit(vector<int> holes, vector<int> pages, int n, int l){
    cout << endl << "Best fit: " << endl;
    cout<< "Page"<<"\tblock" <<endl;
    vector< pair<int,int> > bfit;
    for(int i = 0; i < n; i++) {
        bfit.push_back(make_pair(holes[i], i + 1));
    }
    for(int i = 0; i < l; i++){
        bool t =  0;
        int ans;
        sort(bfit.begin(), bfit.end());

        for(int j = 0; j < n; j++){

            if(bfit[j].first >= pages[i]){
                ans = bfit[j].second;
                bfit[j].first -= pages[i];
                t = 1;
                break;
            }
        }
        if(!t)
            cout<<pages[i]<<"\tNot allocated "<<endl;
        else{
            cout<<pages[i]<<"\t"<<ans<<endl;
        }
    }
}
void worstFit(vector<int> holes, vector<int> pages, int n, int l){
     vector<int> ans(n, 0);
    cout << endl << "Worst fit: " << endl;
    cout<< "Page"<<"\tblock" <<endl;
    vector< pair<int,int> > bfit;
    for(int i = 0; i < n; i++) {
        bfit.push_back(make_pair(holes[i], i + 1));
    }
    for(int i = 0; i < l; i++){
        bool t =  0;
        int ans;
        sort(bfit.rbegin(), bfit.rend());

        for(int j = 0; j < n; j++){

            if(bfit[j].first >= pages[i]){
                ans = bfit[j].second;
                bfit[j].first -= pages[i];
                t = 1;
                break;
            }
        }
        if(!t)
            cout<<pages[i]<<"\tNot allocated "<<endl;
        else{
            cout<<pages[i]<<"\t"<<ans<<endl;
        }
    }
}
int main(){
    vector<int> holes = {100, 500, 200, 300, 600};
    vector<int> pages = {212, 417, 112, 426};

    int len = holes.size();
    int lenp = pages.size();
    firstFit(holes, pages, len, lenp);
    bestFit(holes, pages, len, lenp);
    worstFit(holes, pages, len, lenp);

}
