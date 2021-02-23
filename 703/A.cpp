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
    long long target = (long long)(n - 1)*(long long)(n)/2;
    long long sum = 0;
    for(int i = 0; i < n;i++){
        long long target = (long long)(i)*(long long)(i + 1)/2;
        sum += h[i];
        if(sum < target){
            return false;
        }
    }
    return true;
}
int main(){
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
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