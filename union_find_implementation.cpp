#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<int>link;
vector<int>size;

int leader(int x){
	while(x!=link[x]){
		x=link[x];
	}
	return x;
}
void unite(int a,int b){
	a=leader(a);
	b=leader(b);
	if(size[a]>=size[b]){
		link[b]=a;
		size[a]+=size[b];
		size[b]=0;
	}
	else{
		link[a]=b;
		size[b]+=size[a];
		size[a]=0;
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n=7;
	for(int i=0;i<n;i++){
		link.push_back(i);
		size.push_back(1);
	}
	unite(0,4);
	unite(0,3);
	unite(4,6);
	unite(1,2);
	unite(2,5);
	for(int i=0;i<n;i++){
		cout<<leader(i)<<" "<<size[i]<<"\n";
	}
}
