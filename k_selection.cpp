#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

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

// returns the kth largest(or smallest) element, default is smallest
int heap_select_safe(vector<int> &ar, int start, int end, int k, bool largest = false) {
	bool smallest = !largest;
	int n = end - start + 1;

	if (k < 1 || k > n) {
		cout << "Error in heap_select function, k out of range" << endl;
		return -1;
	}

	if (end == start)
		return ar[end];

	if (k > n / 2 + 1) {
		return heap_select_safe(ar, start, end, n - k + 1, !largest);
	}

	vector<int> temp(ar.begin() + start, ar.begin() + end + 1);

	if (largest) {
		make_heap(temp.begin(), temp.end());

		for (int i = 0; i < k; i++) {
			pop_heap(temp.begin(), temp.end() - i);
		}

		return *(temp.end() - k);
	} else {
		make_heap(temp.begin(), temp.end(), greater<int>());

		for (int i = 0; i < k; i++) {
			pop_heap(temp.begin(), temp.end() - i, greater<int>());
		}

		return *(temp.end() - k);
	}
}

// returns the kth largest(or smallest) element, default is smallest
int heap_select(vector<int> &ar, int start, int end, int k, bool largest = false) {
	bool smallest = !largest;
	int n = end - start + 1;

	if (k < 1 || k > n) {
		cout << "Error in heap_select function, k out of range" << endl;
		return -1;
	}

	if (end == start)
		return ar[end];

	if (k > n / 2 + 1) {
		return heap_select(ar, start, end, n - k + 1, !largest);
	}

	if (largest) {
		make_heap(ar.begin() + start, ar.begin() + end + 1);

		for (int i = 0; i < k; i++) {
			pop_heap(ar.begin() + start, ar.begin() + end + 1 - i);
		}

		return *(ar.begin() + end + 1 - k);
	} else {
		make_heap(ar.begin() + start, ar.begin() + end + 1, greater<int>());

		for (int i = 0; i < k; i++) {
			pop_heap(ar.begin() + start, ar.begin() + end + 1 - i, greater<int>());
		}

		return *(ar.begin() + end + 1 - k);
	}
}

int main(void) {
	int n = 20;
	vector<int> v(n);

	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		v[i] = rand() % 100;
	}
	
	for (int i = 0; i < n; i++) {
		if(heap_select(v, 0, n - 1, i+1) == quick_select(v, 0, n - 1, i+1)) {
			cout << "correct" << endl;
		} else {
			cout << "wrong" <<endl;
		}
	}
}
