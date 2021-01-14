#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

void erat(int N){
	int i, k;
	vector <bool> a(N,true);
	k = 2;
	while (k * k <= N) {
		if (a[k]) {
			i = k * k;
			while (i < N) {
				a[i] = false;
				i += k;
			}
		}
		k++;
	}
	/*
	for (i = 2; i < N; i++) {
		if (a[i]) {
			cout << i << " ";
		}
	}
	cout << endl;
	*/
}

bool is_simple(int x) {
	for (int i = 2; i < x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

void simple(int N) {
	for(int i = 0; i < N; i++){
		if (is_simple(i)){
			//cout << i << " ";
		}
	}
	//cout<<endl;
}

int main()
{
	int N = 100000;
	milliseconds ms1 = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	cout << "before:\n "<<ms1.count() << endl;
	erat(N);
	milliseconds ms2 = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	cout << "after erat:\n "<<ms2.count() << endl;
	simple(N);
	milliseconds ms3 = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	cout << "after simple:\n " << ms3.count() << endl;
}