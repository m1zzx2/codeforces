#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
const int maxn = 5e2 + 10;
int h[maxn];
int now[maxn][maxn];
int pre[maxn][maxn];
int n;

void init(){
    memset(h,0,sizeof(h));
    memset(now,0,sizeof(now));
    memset(pre,0,sizeof(pre));
}

int main(){
//     freopen("C.in", "r", stdin);
//     freopen("C.out", "w", stdout);
    cin>>n;
    init();
    for(int i = 0 ; i < n;i++) {
        cin >> h[i];
        int x = i + 1;
        int y = i + 1;
        now[x][y] = h[i];
        int nt = h[i];
        while(nt--){
            now[x][y] = h[i];
            if(now[x][y - 1]  == 0 && y - 1 >= 1){//左边可以填写，优先左边的
                y--;
            }else{
                x++;
            }
        }
    }
    for(int i = 1 ; i <= n;i++){
        for(int j = 1; j <= i; j++){
            cout<<now[i][j];
            if(i != j){
                cout<<" ";
            }
        }
        cout<<endl;
    }
}