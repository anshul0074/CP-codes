//dfs
#include<bits/stdc++.h>
using namespace std;
#define int long long 

vector<bool>visited;
void add(vector<int>arr[],int u,int v){
	arr[u].push_back(v);
	arr[v].push_back(u);
}
void dfs(vector<int>arr[],int s){
	if(visited[s]==true){
		return;
	}
	visited[s]=true;
	cout<<s<<" ";
	vector<int>::iterator i;
	for(i=arr[s].begin();i!=arr[s].end();i++){
		dfs(arr,*i);
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N=6;
    vector<int> arr[N];
	add(arr,0,3);
	add(arr,0,4);
	add(arr,1,2);
	add(arr,1,4);
	add(arr,4,5);
	add(arr,2,5);
	for(int i=0;i<N;i++){
		visited.push_back(false);
	}
	dfs(arr,0);
}
