#include <bits/stdc++.h>

using namespace std;

bool compare(int a, int b) {
    return a < b;
}

void build_heap(vector<int> &v, unordered_map<int, unordered_set<int> > &m) {
    make_heap(v.begin(), v.end(), compare);
    int n = v.size();
    for (int i = 0; i < n; i++) {
        m[v[i]].insert(i);
    }
}

void delete_at_index(vector<int> &v, unordered_map<int, unordered_set<int> > &m, int i) {
    if (i >= v.size()) {
        return;
    }
    m[v[i]].erase(i);
    if (m[v[i]].empty()) {
        m.erase(v[i]);
    }
    m[v.back()].erase(v.size() - 1);
    m[v.back()].insert(i);
    v[i] = v.back();
    v.pop_back();

    int n = v.size();
    while (true) {
        int left_pointer = 2 * i + 1;
        int right_pointer = 2 * i + 2;
        // if i has 2 children
        if (right_pointer < n) {
            if (max(v[left_pointer], v[right_pointer]) <= v[i]) {
                break;
            } else if (v[left_pointer] > v[right_pointer]) {
                m[v[i]].erase(i);
                m[v[i]].insert(left_pointer);
                m[v[left_pointer]].erase(left_pointer);
                m[v[left_pointer]].insert(i);
                iter_swap(v.begin() + i, v.begin() + left_pointer);
                i = left_pointer;
            } else {
                m[v[i]].erase(i);
                m[v[i]].insert(right_pointer);
                m[v[right_pointer]].erase(right_pointer);
                m[v[right_pointer]].insert(i);
                iter_swap(v.begin() + i, v.begin() + right_pointer);
                i = right_pointer;
            }
        }
        // if i has only left child 
        else if (left_pointer < n) {
            if (v[left_pointer] > v[i]) {
                m[v[i]].erase(i);
                m[v[i]].insert(left_pointer);
                m[v[left_pointer]].erase(left_pointer);
                m[v[left_pointer]].insert(i);
                iter_swap(v.begin() + i, v.begin() + left_pointer);
            }
            break;
        }
        // if i is leaf node 
        else {    
            break;
        }
    }
}

void pop_max(vector<int> &v, unordered_map<int, unordered_set<int> > &m) {
    delete_at_index(v, m, 0);
}

void insert(vector<int> &v, unordered_map<int, unordered_set<int> > &m, int val) {
    v.push_back(val);
    m[val].insert(v.size() - 1);
    int i = v.size() - 1;
    int parent = (i - 1) / 2;
    while (i != 0 && v[parent] < v[i]) {
        m[v[i]].erase(i);
        m[v[i]].insert(parent);
        m[v[parent]].erase(parent);
        m[v[parent]].insert(i);
        iter_swap(v.begin() + i, v.begin() + parent);
        i = parent;
        parent = (i - 1) / 2;
    }
}

void delete_any(vector<int> &v, unordered_map<int, unordered_set<int> > &m, int val) {
    if (m.find(val) == m.end()) {
        return;
    }
    auto it = m[val].begin();
    int i = *it;
    delete_at_index(v, m, i);
}

void delete_all(vector<int> &v, unordered_map<int, unordered_set<int> > &m, int val) {
    while (m.find(val) != m.end()) {
        auto it = m[val].begin();
        int i = *it;
        delete_at_index(v, m, i);
    }
}

bool find(vector<int> &v, unordered_map<int, unordered_set<int> > &m, int val) {
    return m.find(val) != m.end();
}

int main(void) {
    int n = 6;
    vector<int> v(n);
    unordered_map<int, unordered_set<int> > m;
    
    for (int i =  0; i < n; i++) {
        v[i] = rand() % 100;
    }

    build_heap(v, m);
    
    while (true) {
        for (auto i : v) {
            cout << i << " "; 
        }
        cout << endl;
        for (auto i : m) {
            cout << i.first << " - ";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;

        int option, temp;
        cin >> option >> temp;
        if (option == 1) {
            insert(v, m, temp);
        } if (option == 2) {
            delete_any(v, m, temp);
        } if (option == 3) {
            delete_all(v, m, temp);
        }
    }
}
