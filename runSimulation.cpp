#include<bits/stdc++.h>
using namespace std;
int runsim(int,string);
int main(){
    cout << runsim(2, "ABBAJJKZKZ") << endl;
    cout << runsim(3, "GACCBDDBAGEE") << endl;
    cout << runsim(3, "GACCBGDDBAEE") << endl;
    cout << runsim(1, "ABCBCA") << endl;
    cout << runsim(1, "ABCBCADEED") << endl;
    return 0;
}
int runsim(int n,string str){
    int temp=n;
    int occ[26]={0};
    int pending[26]={0};
    int ans=0;
   
    for(int i=0;i<str.size();i++){
        if(occ[str[i]-'A']==1){
            occ[str[i]-'A']=0;
            temp++;
            int minm=INT_MAX;
            int next=-1;
            for(int j=0;j<26;j++){
                if(pending[j]!=0 and pending[j]<minm){
                    next=j;
                    minm=pending[j];
                }
            }
            if(next!=-1){
                occ[next]=1;
                pending[next]=0;
                temp--;
            }
        }
        else{
           
            if(pending[str[i]-'A']!=0){
                
                pending[str[i]-'A']=0;
                
                ans++;
            }
            
            else if(temp>0){
                occ[str[i]-'A']=1;
                temp--;
            }else{
                pending[str[i]-'A']=i;       
            }
        }
        
    }
    
    
    return ans;
}