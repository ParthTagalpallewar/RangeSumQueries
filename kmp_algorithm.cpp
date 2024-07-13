#include<bits/stdc++.h>
using namespace std;
 
void print(vector<int> &lps){
    for (auto i : lps)
    {
        cout << i << " ";
    }cout << endl;
}
 
void solve(string &s){
    int n = s.size();
    int idx = 1;
    int len = 0;
    vector<int> lps(n);
 
    while(idx < n){
        if(s[idx] == s[len]){
            len++;
            lps[idx] = len;
            idx++;
        }else{
            if(len != 0){
                len = lps[len-1];
            }else{
                lps[idx] = 0;
                idx++;
            }
        }
    }
    vector<int> ans;
    int j = lps[n-1];
    while(j > 0){
        ans.push_back(j);
        j = lps[j-1];
    }
    sort(ans.begin(), ans.end());
 
    print(ans);
}
 
int main(){
    string s; cin >> s;
    solve(s);
}
