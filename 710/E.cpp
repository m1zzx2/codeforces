/*
 2020-06-21 21:30 start div3 E
 2020-06-21 21:33 understand meaning
 2020-06-21 21:38 find the first style 
2020-06-21 21:53 find the first style  have some question...
2020-06-21 21:58 submit 1 ce
2020-06-21 21:59 submit 2 wa7
2020-06-21 22:00 submit 3 te10
2020-06-22 15:22 submit n  

STL SET
*/ 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
int t, n, q[maxn], min_p[maxn], max_p[maxn], min_hash[maxn];


set<int>my_set;

void init(){
    my_set.clear();
    for(int i = 0 ; i <= n + 1;i++){
        min_hash[i] = 0;
        my_set.insert(i);
    }
    q[0] = 0;
}

int   find_next_min_index(int min_index){
     for(int i = min_index; i <= n;i++){
            if(min_hash[i] == 0){
                return i;
            }
     }
     return -1;
}

int   find_next_max_index(int upper){
    set<int>::iterator  it = my_set.lower_bound(upper);
     //cout<<"upper "<<upper<<"it : "<<*it<<" size : "<<my_set.size()<<endl; 
    if((*it) > upper){
        --it;
    }
    int ret = *it;
    my_set.erase(it);
    return ret;
}


void deal(){
    int min_index = 1;
    for(int i = 1; i <= n;i++){
        if(q[i] != q[i - 1]){
            min_hash[q[i]]= 1;
            min_p[i] = q[i];
            max_p[i] = q[i];
        }else{
            min_index = find_next_min_index(min_index);
            min_hash[min_index] = 1;
            min_p[i] = min_index;
        }
    }
    for(int i = 1 ; i <= n;i++){
        int max_index = find_next_max_index(q[i]);
        max_p[i] = max_index;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // freopen("E.in", "r", stdin);
    // freopen("E.out", "w", stdout);
    cin>>t;
    while(t--){
        cin>>n;
        init();
        for(int i = 1 ; i <= n;i++){
            cin>>q[i];
        }
        deal();
        for(int i = 1; i <= n;i++){
            cout<<min_p[i];
            if(i  == n){
                cout<<endl;
            }else{
                cout<<" ";
            }
        }
        for(int i = 1; i <= n;i++){
            cout<<max_p[i];
            if(i  == n){
                cout<<endl;
            }else{
                cout<<" ";
            }
        }
    }

}