#include<stdio.h>
#include<algorithm>
#include<iostream>


typedef long long ll;
using namespace std;
int n;
int a[110];

int _min(int a, int b){
    if(a > b){
        a = b;
    }
    return a;
}

int _max(int a, int b){
    if(a < b){
        a = b;
    }
    return a;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int l1, r1, l2, r2;
        for(int i = 1; i <= n;i++){
            cin>>a[i];
            if (a[i] == 1){
                l1 = i;
                r1 = n - i + 1;
            }
            if (a[i] == n){
                l2 = i;
                r2 = n - i + 1;
            }
        }
        int ans = _max(l1,l2);
        ans = _min(ans, _max(r1, r2));
        ans = _min(ans, l1 + r2);
        ans = _min(ans, l2 + r1);
        cout<<ans<<endl;
    }
}