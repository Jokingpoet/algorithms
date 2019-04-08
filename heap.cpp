#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

class heap {
private:
	vector<int> h;
	int parent(int c) {
		if (c == 0) {
			return 0;
		}
		else {
			if (c % 2 == 0) {
				return (c - 2) / 2;
			}
			else {
				return (c - 1) / 2;
			}
		}
	}
public:
	void insertion(int n) {
		h.push_back(n);
		if (h.size() == 1) {
			return;
		}
		int i = h.size() - 1;
		while (i != 0 && h[i] < h[parent(i)]) {
			int tmp = h[parent(i)];
			h[parent(i)] = h[i];
			h[i] = tmp;
			i = parent(i);
		}
		return;
	}

	int pop() {
		int res = h[0];
		h[0] = h[h.size() - 1];
		h.pop_back();
		int i = 0;
		while (2 * i + 2 < h.size()) {
			if (h[i] < h[2 * i + 1] && h[i] < h[2 * i + 2]) {
				break;
			}
			else if (h[2 * i + 1] < h[2 * i + 2]) {
				int tmp = h[i];
				h[i] = h[2 * i + 1];
				h[2 * i + 1] = tmp;
				i = 2 * i + 1;
			}
			else {
				int tmp = h[i];
				h[i] = h[2 * i + 2];
				h[2 * i + 2] = tmp;
				i = 2 * i + 2;
			}
		}
		if (2 * i + 1 < h.size() && h[2 * i + 1] < h[i]) {
			int tmp = h[i];
			h[i] = h[2 * i + 1];
			h[2 * i + 1] = tmp;
		}
		return res;
	}
};

int main() {
	heap myheap;
	srand(int(time(0)));
	for (int i = 0; i < 20; i++) {
		myheap.insertion(rand() % 1000);
	}
	for (int i = 0; i < 20; i++) {
		cout << myheap.pop() << endl;
	}
	system("pause");
}