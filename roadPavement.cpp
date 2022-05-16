#include <iostream>
using namespace std;
#define ll long long
long long days(int total, int good, int bad){
    long long toGood = (total+1)/2;
    long long toBad = total-toGood;

    long long i = toGood/good;
    long long counter = 0;
    counter += (good * i);
    long long j = 0;
    
    i = (good * i);
    if(i<toGood){
        counter += (bad * (i/good));
        j = (bad * (i/good));
    }
    else{
        counter += (bad * ((i/good)-1));
        j = (bad * ((i/good)-1));
    }

    counter += (toGood - i);
    if(j < toBad){
        counter += (toBad - j);
    }

    return counter;
    // ll part1=(total+1)/2;
    // ll part2=total-part1;

    // ll ans=0;

    // long long neededCylce=(part1)/good;
    // // cout<<neededCylce<<endl;
    // ans+=(neededCylce)*(good+bad);
    // if(part1%good==0){
    //     ans-=bad;
    // }
    // part1-=neededCylce*good;
    // part2-=neededCylce*bad;
    // if(part1>0){
    //     ans+=part1;
    // }
    // if(part2>=0){
    //     ans+=part2;
    // }
    
    // return max(ans,(long long)total);
}

int main(){
    int t;
    cin>>t;
    while(t > 0){
        int n, g, b;
        cin>> n >>g >>b;
        t--;
        cout<< days(n,g,b) <<endl;
    }
}