#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int findIdx(vector<ll>& stacks ,ll num){
    
    int minIdx=-1;
    ll minm=INT_MAX;
    int l=0,r=stacks.size()-1;
    
    while(l<=r){
        ll mid=(l+r)/2;
        
        if(stacks[mid]>num and stacks[mid]<INT_MAX){
            minm=stacks[mid];
            r=mid-1;
    }else{
        
        l=mid+1;
    }
       
    }
    
    return minIdx;
    
    
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    ll arr[n];
	    
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    
	    vector<ll> stacks;
	    
	   stacks.push_back(arr[0]);
	   
	   for(int i=1;i<n;i++){
	       
	      int idx=findIdx(stacks,arr[i]);
	      if(idx==-1){
	          stacks.push_back(arr[i]);
	          
	      }else{
	          stacks[idx]=arr[i];
	      }
	      
	       
	   }
	   cout<<stacks.size()<<endl;
	   for(int i=0;i<stacks.size();i++){
	       cout<<stacks[i]<<" ";
	   }
	   cout<<endl;
	    
	    
	    
	}
	
	return 0;
}
