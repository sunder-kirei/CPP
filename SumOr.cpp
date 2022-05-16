#include<bits/stdc++.h>
using namespace std;

void solve(int s,vector<int> &xi,vector<int> &coeff){

int temp=s;
int pwr=coeff.size()-1;
for(int i=pwr;i>=0;i--){
    if(xi[i]==0){
        continue;
    }
    int curr=pow(2,i);
    
    int currCoeff=s/curr;
    // cout<<i<<" " <<curr<<" "<<currCoeff<<endl;
    s=s%curr;
    coeff[i]=currCoeff;
}

}

int main(){

    int t;
    cin>>t;
    while(t--){
        int x,s;
        cin>>x>>s;
        if(x%2==0 and s%2!=0){
            cout<<"-1"<<endl;
            continue;
        }




        vector<int> xi(32,0);
        int temp=x,pos=0;
        while(temp>0){
            if(temp%2!=0){
                xi[pos]=1;
            }
            pos++;
            temp=temp>>1;
        }
        
        int len=floor(log2(x))+1;
        // cout<<log2(x)<<endl;

        vector<int> coeff(len,0);
        // cout<<coeff.size()<<endl;

        solve(s,xi,coeff);
        int ans=-1;
        for(int i=0;i<len;i++){
            ans=max(ans,coeff[i]);
        }
        cout<<ans<<endl;



    }


}