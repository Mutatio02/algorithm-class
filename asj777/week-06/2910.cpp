#include <bits/stdc++.h>
using namespace std;
// 25.05.02 빈도정렬(복습) - set과 map, 정렬
int N;
long long C;
unordered_map<int,int> mp;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;
    vector<int> v(N+1,0);
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        mp[num]++;
        if(mp[num]==1) v.push_back(num); // 처음 들어온 경우 추가
    }

    stable_sort(v.begin(),v.end(),[](int a,int b) {return mp[a]>mp[b];}); // 빈도순 으로 정렬 순서 유지를 위한 stable_sort

    for(auto n : v) {
        for(int i=0; i<mp[n]; i++)  {
            cout << n << " ";
        }
    }

    return 0;
}
