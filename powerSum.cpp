#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int i,n,s=0,b,j=1;
        cin>>n;
        int a[n],d[n];

        for(int i=0;i<n;i++){
            cin>>a[i];
            d[i]=a[i];
            s+=a[i];
        }
        sort(a,a+n);
        b=ceil(log2(s));
        auto c=find(d,d+n,a[0]);
        j=((pow(2,b)-s)+a[0])/a[0];
        if((s&s-1)==0){
            cout<<0<<endl;
        }
        else{
            cout<<1<<endl;
            cout<<1<<" "<<j;
            cout<<endl;
            cout<<(distance(d,c))+1<<endl;
        }

    }

}