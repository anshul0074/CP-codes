#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n=8,k=4;
    int arr[n]={2,1,4,5,3,4,1,2};
    deque<pair<int,int>>dq;
    for(int i=0;i<n;i++){
        while(!dq.empty() and dq.back().first>=arr[i]){
            dq.pop_back();
        }
        dq.push_back({arr[i],i});
        while(dq.front().second<=i-k){
            dq.pop_front();
        }
        cout<<dq.front().first<<" ";
    }
}