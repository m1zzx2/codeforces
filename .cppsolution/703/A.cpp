#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
const int maxn = 1e2 + 10;
int h[maxn];
int t,n;

void init(){
    memset(h,0,sizeof(h));
}

bool check(){
    int target = h[n - 1];
    for(int i = n - 2; i >= 0;i--){
        if (h[i] > (target + 1)){
            return false;
        }
        if(h[i] < target){
            target = h[i];
        }
    }
    return true;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0; i < n;i++)
            cin>>h[i];
        if(check()){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}