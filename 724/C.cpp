/*

log: 

    start at 2021-06-12 19:57
    sumbit 1 at  2021-06-12 21:08 wa2

    sumbit 2 at  2021-06-12 21:15 wa2
    .....
    sumbit n at  2021-06-12 21:27 accept


    reason : gcd
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;


typedef long long ll;
const int maxn =  5e5 + 10;

char input[maxn];
int n, t;
ll ans[maxn];

map<ll, int>mp;

void init(){
    mp.clear();
}

ll _max(ll a, ll b){
    return a > b ? a : b;
}

ll _gcd(ll a, ll b){
    return b == 0 ? a : _gcd(b , a % b);
}
ll calc_simpest(ll a, ll b){
    ll ret  = 0;
    ll gcd_a_b = _gcd(a, b);
    a = a/gcd_a_b;
    b = b/gcd_a_b;
    ret = a * 1000000 + b;
    return ret;
}

void deal(){
    scanf("%s",input);
    ll cntD = 0, cntK = 0, ret = 0;
    for(int i = 0 ;i < n;i++){
        if(input[i] == 'D'){
            cntD++;
        }else{
            cntK++;
        }
        if (cntD == 0 || cntK == 0){
                  ans[i] = i + 1;
        }else{
            ll sum = calc_simpest(cntD, cntK);
            //cout<<cntK<<" "<<cntD<<" "<<sum<<endl;
            mp[sum] = mp[sum]  + 1;
            ans[i] = mp[sum];
        }
    }
    for(int i = 0 ; i < n; i++){
        cout<<ans[i];
        if(i == n - 1){
            cout<<endl;
        }else{
            cout<<" ";
        }
    }
}

int main(){
    // freopen("C.in", "r", stdin);
    // freopen("C.out", "w", stdout);
    cin>>t;
    while(t--){
        cin>>n;
        init();
        deal();
    }
    return 0;
}