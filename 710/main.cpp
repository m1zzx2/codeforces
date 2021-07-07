#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

set<int> my_set;

int main(){
    for(int i = 0; i < 100;i++){
        my_set.insert(i);
    }
    set<int>::iterator  it = my_set.lower_bound(9);
    cout<<*it<<endl;
    my_set.erase(it);
    it =  my_set.lower_bound(9);
    cout<<*(--it)<<endl;
}