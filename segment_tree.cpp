#include <bits/stdc++.h>

using namespace std;

void build_segment_tree(vector<int> &a, vector<int> &tree, int start, int end, int node) {
    if (start == end) {
        tree[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        build_segment_tree(a, tree, start, mid, 2 * node + 1);
        build_segment_tree(a, tree, mid + 1, end, 2 * node + 2);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}

void segment_tree_update(vector<int> &a, vector<int> &tree, int start, int end, int node, int i, int value) {
    if (start == end) {
        tree[node] = value;
        a[start] = value;
    } else {
        int mid = (start + end) / 2;
        if (i <= mid) {
            segment_tree_update(a, tree, start, mid, 2 * node + 1, i, value);
        } else {
            segment_tree_update(a, tree, mid + 1, end, 2 * node + 2, i, value);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}

int segment_tree_query(vector<int> &tree, int start, int end, int node, int l, int r) {
    if (l > end || r < start) {
        return 0;
    } else if (start >= l && end <= r) {
        return tree[node];
    } else {
        int mid = (start + end) / 2;
        int p1 = segment_tree_query(tree, start, mid, 2 * node + 1, l , r);
        int p2 = segment_tree_query(tree, mid + 1, end, 2 * node + 2, l , r);
        return (p1 + p2);
    }
}


int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> tree(4 * n);
    build_segment_tree(a, tree, 0, n - 1, 0);

    for (int i = 0; i < 4 * n; i++) {
        cout << i << " " << tree[i] << endl;
    }

    segment_tree_update(a, tree, 0, n - 1, 0, n - 1, 10);

    for (int i = 0; i < 4 * n; i++) {
        cout << i << " " << tree[i] << endl;
    }

    cout << segment_tree_query(tree, 0, n - 1, 0, 0, n - 1);

}
