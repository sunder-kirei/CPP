#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       if(n==2){
           cout<<"NO"<<endl;
       }else{
           cout<<"YES"<<endl;
           
           int arr[n]={-1};
           
           int l=1,r=n;
           int maxm=INT_MIN;
           
           while(l<=r){
               
               vector<int> v(n,-1);
               int mid=(l+r)/2;
               int left=0,right=n-1;
               int leftNum=2,rightNum=1;
               while(left<=right  ){
                   v[left]=leftNum;
                   v[right]=rightNum;
                   leftNum+=2;
                   rightNum+=2;
                   left++;right--;
                   mid--;
               }
               if( ((l+r)/2) >maxm){
               for(int i=0;i<n;i++){
                   arr[i]=v[i];
               }
                   
               }
               
            //    cout<<mid<<" "<<endl;
               if(mid<=0){
                   int temp=(l+r)/2;
                   l=temp+1;;
               }else{
                   int temp= (l+r)/2;
                   r=temp-1;
               }
               
           }
           for(int i=0;i<n;i++){
               cout<<arr[i]<<" ";
           }
           cout<<endl;
           
           
           
           
       }
       
        
        
    }
    
    
}
