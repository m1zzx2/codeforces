#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;

typedef long long ll;

ll dp[30][10]; //第i位，数字是j的变动总量  dp[4][9] 就是 9000-9999 的变化   dp[4][0] 就是 0000 到 0999的



void init(){
    memset(dp, 0, sizeof(dp));
    for(int i = 1 ; i < 10;i++){
        dp[1][i] = 1;
    }
    for(int i = 2; i <= 10;i++){
        for(int j = 0; j < 10;j++){
            for(int k = 0; k < 10;k++){
                dp[i][j] += dp[i - 1][k];
            }
            if(j != 0){
                dp[i][j] += i;
            }
        }
    }
}


ll calc(ll n){
    int bit = 1;
    ll ret = 0;
    while(n > 0){
        ll num= n % 10;
        n/=10;
        for(int i = 0; i < num;i++){
            ret += dp[bit][i];
        }
        if(bit == 1){
             ret += dp[bit][num];
        }else if(num > 0){
            ret += bit;
        }
        bit++;
    }
    return ret;
}

int main(){
    init();
    int t;
    ll a, b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<calc(b)-calc(a )<<endl;
    }
}