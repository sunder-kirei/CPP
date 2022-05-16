#include <iostream>
#include<cmath>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int arr[3][3];
	    int n;
	    cin>>n;
	    int count=0;
	    for(int i=0;i<3;i++){
	        for(int j=0;j<3;j++){
	            
	            cin>>arr[i][j];
	            
	        }
	    }
	    int a=arr[1][0] + arr[2][0] +arr[2][1];
	    int b= arr[0][1] + arr[0][2] + arr[1][2];
	    int ans= max(a,b);
	    
	  for(int i=0;i<3;i++){
	      
	      for(int j=0;j<3;j++){
	          
	          if(i==j){
	              continue;
	          }
	          
	          if(arr[i][j]!=0){
	              
	              if(arr[j][i]>=arr[i][j]){
	                  int temp=arr[i][j];
	                  arr[i][i]+=temp;
	                  arr[j][j]+=temp;
	                  arr[j][i]-=temp;
	                  arr[i][j]-=temp;
	                  count+=temp;
	              }else if(arr[j][i]==0){
                      
                  }
                  else{
	                 int temp=arr[j][i];
	                  arr[i][i]+=temp;
	                  arr[j][j]+=temp;
	                  arr[j][i]-=temp;
	                  arr[i][j]-=temp;
	                  count+=temp; 
	              }
	              
	          }
	          
	      }
	  }
      
	  
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
	  
	  
	  cout<<ans<<endl;
	    
	    
	    
	}
	
	return 0;
}