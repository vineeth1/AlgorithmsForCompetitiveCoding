#include <bits/stdc++.h>

using namespace std;

// returns pivot's index after partitioning the vector ar 
// partition is not stable
int partition(vector<int> &ar, int start, int end) {
	srand (time(NULL));
	int n = end - start + 1;
	swap(ar[end], ar[start + rand() % n]);
	int pivot = ar[end];
	int i = start - 1;

	for (int j = start; j <= end - 1; j++) {
		if (ar[j] <= pivot) {
			i++;
			swap(ar[i], ar[j]);
		}
	}
	swap(ar[i + 1], ar[end]);
	return (i + 1);
}

// returns kth smallest element in ar[start...end]
// be careful ar may be permutated while finding the kth smallest element 
int quick_select(vector<int> &ar, int start, int end, int k) {

	int n = end - start + 1;
	if (k < 1 || k > n) {
		cout << "Error in quick_select function, k out of range" << endl;
		return -1;
	}
 
	if (end == start)
		return ar[end];
	
	int i = partition(ar, start, end);

	if (start + k - 1 == i) {
		return ar[i];
	} else if (start + k - 1 > i) {
		return quick_select(ar, i + 1, end, k - i + start - 1);
	} else {
		return quick_select(ar, start, i - 1, k);
	}
}

// similar to above funtion but is safe, in the sense doesn't mess with the input array
int quick_select_safe(vector<int> ar, int start, int end, int k) {
	return quick_select(ar, start, end, k);
} 

int main(void) {
	vector<int> v;
	int n = 15;
	srand (time(NULL));

	for(int i = 0; i < n; i++) {
		v.push_back(rand() % 50);
	}

	for(int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int> s(v);
	sort(s.begin(), s.end());

	int i = 0;
	for(int a : s) {
		if(a == quick_select_safe(v, 0, v.size() - 1, ++i)) {
			cout << "passed" << endl;
		} else {
			cout << "failed" << endl;
		}
	}

	for(int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}
