/*

LRRL. 1-4.  2-3. 3-4. 4-3 


RLRL i

LRRRRL


1 -> 6 
 

1 
2 

4 \

LRLRRL

1 -6     
*/

/*
 * @file D.cpp
 * @author your name (gugg726@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-27 21:45
 * @ end 2021-06-27 22:28 take time 33min
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;

int t;

char s[maxn];
int main(){
    //  freopen("D.in", "r", stdin);
    //  freopen("D.out", "w", stdout);
    cin>>t;
    while(t--){
        cin>>n;
        scanf("%s",s);
        int len_s = strlen(s);
        int sum = 1;
        // 先算头<->尾
        int end = len_s - 1;
        int start = 0;
        int ans = 0;
        bool is_h = 0;
        for(int i = start  + 1;i < len_s;i++){
                if(s[i] == s[0]){
                    sum++;
                }else{
                    start = i - 1;
                    break;
                }
                if(i == len_s - 1){
                    start = len_s - 1;
                    is_h = 1;
                }
        }
        for(int i = end ;i > start;i--){
            if(s[i] == s[0]){
                sum++;
            }else{
                end = i + 1;
                break;
            }
        }
        ans = sum/3 + (is_h && (sum%3 != 0));
         sum = 1;
        for(int i = start + 2;i <= end - 1;i++){
            // cout<<"i : "<<i<<"s[i]: "<<s[i]<<endl;
            if(s[i] == s[i - 1]){
                sum = sum + 1;
            }else{
                // cout<<"i: "<<i<<"sum = "<<sum<<endl;
                ans = ans + sum/3;
                sum = 1;
            }
        }
        ans = ans + sum/3;
        // cout<<"sum: "<<sum<<endl;
        cout<<ans<<endl;
    }
}