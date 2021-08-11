#include<bits/stdc++.h>
using namespace std;
#define int long long

void add(vector<int>arr[],int u,int v){
    arr[u].push_back(v);
}
vector<int> topsort(vector<int>arr[],int n){
    vector<int>ans;
    bool visited[n];
    int indegree[n];
    for(int i=0;i<n;i++){
        indegree[i]=0;
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        vector<int>::iterator j;
        for(j=arr[i].begin();j!=arr[i].end();j++){
            indegree[*j]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty()){
        int x=q.front();q.pop();
        if(visited[x]==true){
            continue;
        }
        visited[x]=true;
        ans.push_back(x);
        cnt++;
        vector<int>::iterator v;
        for(v=arr[x].begin();v!=arr[x].end();v++){
            indegree[*v]--;
            if(indegree[*v]==0){
                q.push(*v);
            }
        }
    }
    if(cnt==n){
        return ans;
    }
    else{
        vector<int>e;
        return e;
    }
}
signed main(){
    int n=6;
    vector<int>arr[n];
    add(arr,0,1);
    add(arr,0,2);
    add(arr,1,3);
    add(arr,2,4);
    add(arr,2,5);
    vector<int> ans=topsort(arr,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}