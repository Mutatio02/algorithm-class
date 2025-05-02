#include <bits/stdc++.h>
using namespace std;
// 25.05.02 N으로 만들기 - 백트래킹
string N;
map<set<string>,int> mp;

void solve(int left,int right, string cur, set<string>stmp) {
    if(cur==N) { // N과 같은 숫자가 만들어진 경우 
        mp[stmp] = 1; // 해당 경우의 수 추가
        return;
    }

    if(left>0) {
        string nxt = N[left-1]+cur; // 숫자 왼쪽에 추가해보기
        stmp.insert(nxt);
        solve(left-1,right,nxt,stmp);
        stmp.erase(nxt); // 백트래킹
    }

    if(right+1<N.length()) {
        string nxt = cur+N[right+1]; // 숫자 오른쪽에 추가해보기
        stmp.insert(nxt);
        solve(left,right+1,nxt,stmp);
        stmp.erase(nxt); // 백트래킹
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N.length(); i++) {
        string tmp = N.substr(i,1); // 1개씩 자르기
        set<string> st = {tmp}; // 중복을 확인하기 위해 set을 이용해 저장
        solve(i,i,tmp,st); // left right를 이용해 idx를 조절하기
    }
    
    cout << mp.size();
    return 0;
}
