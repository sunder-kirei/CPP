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

vector<int> parent(n);
vector<int> rank(n);
makeSet(parent,rank);
vector<int>  pos[32];

for(int i=0;i<31;i++){
    for(int j=0;j<n;j++){
        if(arr[j]&(1<<i)){
            pos[i].push_back(j);
        }

    }
}

for(int i=0;i<31;i++){
    for(int j=1;j<pos[i].size();j++){
        Union(pos[i][0],pos[i][j],parent,rank);
    }
}
for(int i=0;i<n;i++){
int idx= lower_bound(crt.begin(),crt.end(),arr[i])-crt.begin();
if(findPar(i,parent)!=findPar(idx,parent)){
    return false;
}

}
return true;

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