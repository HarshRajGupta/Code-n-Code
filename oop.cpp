#include <bits/stdc++.h>
using namespace std;

class parent {
	int a = 0;

   public:
	int get() { return a; }
	int set(int x) { return a = x; }
	void print() { cout << "Parent" << endl; }
};

class derived : public parent {
	int b = 0;

   public:
	void print() { cout << "Derived" << endl; }
};

signed main(void) {
	derived d;
	d.set(1);
	cout << d.get();
	return 0;
}