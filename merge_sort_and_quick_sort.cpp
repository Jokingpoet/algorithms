#include<thread>
#include<iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> Merge(vector<int>& left, vector<int>& right) {
	int r = 0;
	int l = 0;
	vector<int> res;
	while (r < right.size() && l < left.size()) {
		if (left[l] < right[r]) {
			res.push_back(left[l]);
			l += 1;
		}
		else {
			res.push_back(right[r]);
			r += 1;
		}
	}
	if (l != left.size()) {
		while (l < left.size()) {
			res.push_back(left[l]);
			l += 1;
		}
	}
	if (r != right.size()) {
		while (r < right.size()) {
			res.push_back(right[r]);
			r += 1;
		}
	}
	return res;
}

vector<int> MergeSort(vector<int>& v) {
	if (v.size() <= 1) {
		return v;
	}
	int mid = v.size() / 2;
	vector<int> left;
	vector<int> right;
	for (int i = 0; i < mid; i++) {
		left.push_back(v[i]);
	}
	for (int i = mid; i < v.size(); i++) {
		right.push_back(v[i]);
	}
	left = MergeSort(left);
	right = MergeSort(right);
	return(Merge(left, right));
}

vector<int> quick_sort(vector<int>& v) {
	if (v.size() <= 1) {
		return v;
	}
	int mid = v.size() / 2;
	vector<int> left;
	vector<int> right;
	for (int i = 0; i < v.size(); i++) {
		if (i != mid) {
			if (v[i] < v[mid]) {
				left.push_back(v[i]);
			}
			else {
				right.push_back(v[i]);
			}
		}
	}
	left = quick_sort(left);
	left.push_back(v[mid]);
	right = quick_sort(right);
	for (int i = 0; i < right.size(); i++) {
		left.push_back(right[i]);
	}
	return left;
}



int main()
{
	vector<int> tmp;
	srand(int(time(0)));
	for (int i = 0; i < 20; i++) {
		tmp.push_back(rand() % 1000);
	}
	for (int i = 0; i < tmp.size(); i++) {
		cout << tmp[i] << " ";
	}
	cout << endl;
	vector<int> res1 = quick_sort(tmp);
	for (int i = 0; i < res1.size(); i++) {
		cout << res1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < tmp.size(); i++) {
		cout << tmp[i] << " ";
	}
	cout << endl;
	vector<int> res2 = MergeSort(tmp);
	for (int i = 0; i < res2.size(); i++) {
		cout << res2[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}


