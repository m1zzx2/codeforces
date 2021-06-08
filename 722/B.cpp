#include<iostream>
#include<algorithm>
using namespace std;

long long Mod = 998244353;

const int maxn = 1e6 + 10;
long long fac_sum[maxn];

long long sum[maxn];

void init(){
    sum[0] = 0;
    sum[1] = 1;
    for(int i = 1; i < maxn;i++){
        for(int j = i; j < maxn;j = j + i){
            fac_sum[j] = fac_sum[j] + 1;
            fac_sum[j] = fac_sum[j] % Mod;
        }
    }
    long long total = 1;
    for(int i = 2;i < maxn;i++){
        sum[i] = total + fac_sum[i];
        sum[i] %= Mod;
        total = total + sum[i];
        total %= Mod;
    }
}

int main(){
    int n;
    init();
    while(cin>>n){
        cout<<sum[n]<<endl;
    }
    return 0;
}