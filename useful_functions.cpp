#include <iostream>

int gcd(int a,int b){return b?gcd(b,a%b):a;}

void build_segement_tree(vector<int> &a, vector<int> &tree, int start, int end, int node) {
    if (start == end) {
        tree[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        build_segement_tree(a, tree, start, mid, 2 * node + 1);
        build_segement_tree(a, tree, mid + 1, end, 2 * node + 2);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}
