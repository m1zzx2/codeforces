#include<stdio.h>
#include<algorithm>
#include<iostream>


typedef long long ll;
using namespace std;
int n;
long long a[1100000];
ll dr_pos[205000] , dl_pos[205000];

int main(){
    int t;
    cin>>t;
    while(t--){
        ll l;
        ll r;
        cin>>n>>l>>r;
        for(int i = 1; i <= n;i++){
            cin>>a[i];
        }
        sort(a+1, a + 1 + n);
        ll i = 1, j1 = n,i2 = n , j2 = 1;
        ll ans = 0;

        //calc 
        while(i <= n){
            dr_pos[i] = 0;
            while(a[i] + a[j1] > r && j1 >= 1){
                j1--; 
            }
            if(a[i] + a[j1] <= r && j1 >= 1){
                dr_pos[i] = j1;
            }
            i++;
        }
        while(i2 >= 1){
            dl_pos[i2] = 0;
            while(a[i2] + a[j2] < l && j2 <= n){
                    j2++;
            }
            if(a[i2] + a[j2] >= l && j2 <= n){
               dl_pos[i2] = j2;
            }
            i2--;
        }
        for(int i = 1;i <= n;i++){
            //cout<<"dl_post["<<i<<"]"<<": "<<dl_pos[i]<<"  "<<"dr_post["<<i<<"]"<<": "<<dr_pos[i]<<endl;
            if(dl_pos[i] != 0 && dr_pos[i] != 0){
                ll ret = dr_pos[i] - dl_pos[i] + 1;
                if(dr_pos[i] >= i && dl_pos[i] <= i){
                    ret = ret - 1;
                }
                ans = ans + ret;
            }
        }
        cout<<ans/2<<endl;
    }
}