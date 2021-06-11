#include<stdio.h>
#include<algorithm>
#include<iostream>


typedef long long ll;
using namespace std;
int n;
long long a[1100000];


int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        long long sum = 0;
        for(int i = 1; i <= n;i++){
            cin>>a[i];
            sum += a[i];
        }
        if(sum % n != 0 ){
            cout<<"-1"<<endl;
        }else{
            ll val = sum/n;
            int ans = 0;
            for(int i = 1; i <= n;i++){
                if(a[i] > val){
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
    }
}