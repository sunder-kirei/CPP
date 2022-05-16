#include<bits/stdc++.h>
using namespace std;

int makePart(int *arr,int idx,int k,int* maxm,int gtrCount,int n,int x){
    if(k==1 and gtrCount>0 and idx<n){
        maxm[k]=-1;
        return 1;
    }
    if(gtrCount==0 || k<1 || idx==n){
        return 0;
    }



    if(arr[idx]<x and maxm[k]==-1){
        return makePart(arr,idx+1,k,maxm,gtrCount,n,x);
    }
    else{
        int ans=0;
        
        if(maxm[k]<arr[idx]){
            maxm[k] = arr[idx];
        }

        for(int i=idx;i<n;i++){
            if(arr[i]>=x){
                gtrCount--;
            }
            ans+=makePart(arr,i+1,k-1,maxm,gtrCount,n,x);
        }
        maxm[k]=-1;
        
        return ans;
    }

}



int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;

    int arr[n];
    int x;
    cin>>x;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans[n+1]={0};
    int maxm[n+1]={-1};
    int gtrCount=0;
    for(int i=0; i<n; i++){
        if(arr[i]>=x){
            gtrCount++;
        }
    }
    for(int i=1; i<=n; i++){
        if(i>gtrCount){
            ans[i]=0;
        }
        else{

            int temp=makePart(arr,0,i,maxm,gtrCount,n,x);
            ans[i]=temp;
        }

    }
    for(int i=1;i<=n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    }

}