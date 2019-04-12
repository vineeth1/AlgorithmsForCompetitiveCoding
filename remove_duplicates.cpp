#include <bits/stdc++.h>

using namespace std;

void remove_duplicates(vector<int> &v) {
    int n = v.size();
    int current = v[0];
    int distinct = 0;
    for(int i = 1; i < n; i++) {
        if(v[i] != current) {
            distinct++;
            current = v[i];
            v[distinct] = v[i];
        }
    }

    for(int i = 0; i < n - distinct - 1; i++) {
        v.pop_back();
    }

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}