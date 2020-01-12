#include <bits/stdc++.h>

using namespace std;

int find_set(vector<int> &parent, int i) {
    if (parent[i] != i) {
        parent[i] = find_set(parent, parent[i]);
    } 
    return parent[i];
}

void union_set(vector<int> &parent, vector<int> &rank, int i, int j) {
    int set_i = find_set(parent, i);
    int set_j = find_set(parent, j); 
    if (set_i != set_j) {
        if (rank[set_i] > rank[set_j]) {
            parent[set_j] = set_i;
        } else {
            parent[set_i] = set_j;
        }
        if (rank[set_i] == rank[set_j]) {
            rank[set_j]++;
        }
    }
}

int main(void) {
    int n = 6;
    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }



}
