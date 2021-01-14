#include <iostream>
#include <vector>

using namespace std;

void write6(int x) {
	int M;
	M = 100000;
	while (M > 0) {
		cout << x / M;
		x = x % M;
		M /= 10;
	}
}

int main()
{
	int s, r, k, d;
	int N = 100;
	vector <int> a(N);
	for (int i = 0; i < N; i++) {
		a[i] = 0;
	}
	a[0] = 1;
	d = 1000000;
	for (k = 2; k < N; k++) {
		r = 0;
		for (int i = 0; i < N; i++) {
			s = a[i] * k + r;
			a[i] = s % d;
			r = s / d;
		}
	}
	int i;
	for (i = N - 1; i > 0; i--) {
		if (a[i] != 0) {
			break;
		}
	}
	cout << a[i];
	for (k = i - 1; k > 0; k--) {
		write6(a[k]);
	}
}
