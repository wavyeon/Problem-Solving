#include <iostream>

using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	int val;
	for(int i = 0; i < n; i++) {
		cin >> val;
		if(val < x) {
			cout << val << " ";
		}
	}
}