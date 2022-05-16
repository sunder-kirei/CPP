#include<bits/stdc++.h>
using namespace std;
#define ll long long


int findPar(int node,vector<int>&parent){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=findPar(parent[node],parent);
}


void Union(int i,int j,vector<int>&parent,vector<int>&rank){

    i=findPar(i,parent);
    j=findPar(j,parent);
    if(rank[i]<rank[j]){
        parent[i]=j;
    }else if(rank[i]>rank[j]){
        parent[j]=i;
    }else{
        parent[j]=i;
        rank[i]++;
    }


}

void makeSet(vector<int> &parent,vector<int> &rank){
    for(int i=0;i<parent.size();i++){
        parent[i] =i;
        rank[i] =0;
    }
}

bool solve(vector<ll>& arr,vector<ll> & crt,int n){

vector<int> parent(32);
vector<int> rank(32);
makeSet(parent,rank);

for(int i=0;i<n;i++){
   for(int j=0;j<31;j++){
       for(int k=j+1;k<31;k++){
           if(arr[i]&(1LL<<j) and arr[i]&(1LL<<k)){
               Union(j,k,parent,rank);
           }
       }
   }
}
bool poss=true;
for(int i=0;i<n;i++){
    if(!arr[i] && !crt[i]){
        continue;
    }
    bool found=false;
    for(int j=0;j<31;j++){
        for(int k=0;k<31;k++){
            if(arr[i]&(1LL<<j) and crt[i]&(1LL<<k) and   findPar(j,parent)==findPar(k,parent)){
                found=true;
            }
        }
    }
    poss&=found;
}

return poss;


}


int main(){
int t;
cin >> t;
while(t--){
int n;
cin >> n;
vector<ll> arr(n,-1),crt(n,-1);
for(int i=0;i<n;i++){
    cin>>arr[i];
    crt[i] = arr[i];
}
sort(crt.begin(),crt.end());
bool ans=solve(arr,crt,n);
if(ans){
    cout<<"YES"<<endl;
}else{
    cout<<"NO"<<endl;
}


}


}