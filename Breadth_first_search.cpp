//bfs 
#include<bits/stdc++.h>
using namespace std;
#define int long long 

vector<bool>visited;
queue<int>q;
vector<int>dist;
void add(vector<int>arr[],int u,int v){
	arr[u].push_back(v);
	arr[v].push_back(u);
}
void bfs(vector<int>arr[],int s){
	dist[s]=0;
	q.push(s);
	while(!q.empty()){
		s=q.front();q.pop();
		if(visited[s]==true){
			continue;
		}
		visited[s]=true;
		cout<<"Node-> "<<s<<" Distance-> "<<dist[s]<<"\n";
		vector<int>::iterator i;
		for(i=arr[s].begin();i!=arr[s].end();i++){
			dist[*i]=dist[s]+1;
			q.push(*i);
		}
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
		dist.push_back(0);
	}
	bfs(arr,0);
}
