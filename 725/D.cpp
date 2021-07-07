#include<stdio.h>
#include<algorithm>
#include<iostream>


typedef int ll;
using namespace std;
int n;
ll cal_c(ll n){
    ll ret = 0;
    ll now_n = n;
    for(ll i = 2; i * i <= now_n;i++){
        if(now_n % i ==0){
           while(now_n % i == 0){
               now_n = now_n /i;
               ret = ret + 1;
           }
        }
    }
    if(now_n > 1){
        ret++;
    }

    return ret;
}
ll _min(ll a, ll b){

    if(a > b){
        a = b;
    }
    return a;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll a, b, k;
        cin>>a>>b>>k;
        ll f_a = cal_c(a);
        ll f_b = cal_c(b);
        ll __max = f_a + f_b;
        ll __min = 2;
        if((a % b == 0 || b % a == 0)&& a != b){
            __min = 1;
        }
        if(__min <= k && k <= __max){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}