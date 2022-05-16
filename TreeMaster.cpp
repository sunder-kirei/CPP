#include<bits/stdc++.h>
using namespace std;


bool findpath(int x,int y,vector<vector<int> >&edges,vector<int>& path,int *visited){

if(x==y){
return true;
}
visited[x]=1;
bool ans=0;
for(int i=1;i<edges[x].size();i++){
    if(!visited[i] and edges[x][i]!=0){
        path.push_back(i);
        visited[i]=1;
        bool found=findpath(i,y,edges,path,visited);
        if(found==false){
            path.pop_back();
        }
        // visited[i]=;
        ans|=found;
    }
   
}
    return ans; 
}

int calculate(vector<int>& path,int*v_w,int n,vector<vector<int> >&edges){

    int sum=0;
    int x=path[0];
    int y=path[path.size()-1];
    
    for(int i=0;i<path.size();i++){
        int sum1=0,sum2=0;
        int j=0;
        while(j<i){
            sum1+=edges[path[j]][path[j+1]];
            j++;
        }
        while(j<path.size()-1){
            sum2+=edges[path[j]][path[j+1]];
            j++;
        }
        
        // cout<<i<<" "<<sum1<<" "<<sum2<<endl;
        
        int curr=(sum1-sum2)*v_w[path[i]];
        // cout<<curr<<endl;
        sum+=curr;
    }
    return sum;


}

int main(){

int t;
cin>>t;
while(t--){
int n,q;
cin>>n>>q;

int v_w[n+1]={0};

for(int i=1;i<n+1;i++){
cin>>v_w[i];
}
vector<vector<int> >edges(n+1,vector<int>(n+1,0));

for(int i=0;i<n-1;i++){
    int u,v,w;
    cin>>u>>v>>w;
    edges[u][v]=w;
    edges[v][u]=w;
}

for(int i=0;i<q;i++){
    int x,y;
    cin>>x>>y;
    vector<int> path;
    int visited[n+1]={0};
    path.push_back(x);
    findpath(x,y,edges,path,visited);

    // for(int j=0;j<path.size();j++){
    //     cout<<path[j]<<" ";
    // }
    // cout<<endl;


    int ans=calculate(path,v_w,n,edges);
    cout<<ans<<endl;
}

}


}