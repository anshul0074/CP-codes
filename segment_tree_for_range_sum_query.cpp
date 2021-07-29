//segment tree implementation to find range sum query
#include<bits/stdc++.h>
using namespace std;
#define int long long 

int sum(int arr[],int t[],int v,int tl,int tr,int l,int r){
	if(l>r){
		return 0;
	}
	else if(l==tl and r==tr){
		return t[v];
	}
	else{
		int tm=(tr+tl)/2;
		return sum(arr,t,2*v+1,tl,tm,l,min(tm,r))+sum(arr,t,2*v+2,tm+1,tr,max(l,tm+1),r);
	}
}
void build(int arr[],int t[],int v,int tl,int tr){
	if(tl==tr){
		t[v]=arr[tl];
	}
	else{
		int tm=(tl+tr)/2;
		build(arr,t,2*v+1,tl,tm);
		build(arr,t,2*v+2,tm+1,tr);
		t[v]=t[2*v+1]+t[2*v+2];
	}
}
void update(int t[],int v,int tl,int tr,int pos,int val){
	if(tl==tr){
		t[v]=val;
	}
	else{
		int tm=(tl+tr)/2;
		if(pos<=tm){
			update(t,2*v+1,tl,tm,pos,val);
		}
		else{
			update(t,2*v+2,tm+1,tr,pos,val);
		}
		t[v]=t[2*v+1]+t[2*v+2];
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);	
	int n=5;
	int arr[n]={6,2,5,1,4};
	int t[4*n];
	for(int i=0;i<4*n;i++){
		t[i]=0;
	}
	build(arr,t,0,0,n-1);
	cout<<sum(arr,t,0,0,n-1,1,3);
	arr[2]=7;
	update(t,0,0,n-1,2,7);
	arr[1]=3;
	update(t,0,0,n-1,1,3);
	cout<<"\n";
	cout<<sum(arr,t,0,0,n-1,1,3);
}
/*
*/
