#include<bits/stdc++.h>
using namespace std;
int makePart(int *arr,int idx,int k,int* maxm,int gtrCount,int n,int x,vector<vector<int>> &dp){
    if(k==1 and gtrCount>0 and idx<n){
        maxm[k]=-1;
        return 1;
    }
    if(gtrCount==0 || k<1 || idx==n){
        return 0;
    }

    if(dp[k][idx]!=-1){
        return dp[k][idx];
    }


    if(arr[idx]<x and maxm[k]==-1){
        int ans= makePart(arr,idx+1,k,maxm,gtrCount,n,x,dp);
        dp[k][idx]=ans;
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
            ans+=makePart(arr,i+1,k-1,maxm,gtrCount,n,x,dp);
        }
        maxm[k]=-1;
        dp[k][idx]=ans;
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

    vector<vector<int> >dp;
    for(int i=0; i<n+1; i++){
        vector<int> temp;
        for(int j=0; j<n; j++){
            temp.push_back(-1);
        }
        dp.push_back(temp);

    }


    for(int i=1; i<=n; i++){
        if(i>gtrCount){
            ans[i]=0;
        }
        else{

            int temp=makePart(arr,0,i,maxm,gtrCount,n,x,dp);
            ans[i]=temp;
        }

    }

//     for(int i=0; i<n+1; i++){
        
//         for(int j=0; j<n; j++){
//            cout<<dp[i][j]<<" ";
//         }
//         cout<<endl;

//     }
    
// cout<<"ans:"<<endl;
    for(int i=1;i<=n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    }

}