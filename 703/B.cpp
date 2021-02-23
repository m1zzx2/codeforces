#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
ll t,n;
ll x[maxn], y[maxn];
int main(){
    // freopen("B.in", "r", stdin);
    // freopen("B.out", "w", stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ll target = 0;
        for(int i = 0; i < n;i++)
            cin>>x[i]>>y[i];
        sort(x, x + n);
        sort(y, y + n);
        ll ans = 0;
        if(n % 2 == 0){
            ans = (x[n/2] - x[n/2  - 1] + 1)*(y[n/2] - y[n/2 - 1] + 1);
        }else{
            ans = 1;
        }
        cout<<ans<<endl;
    }
}