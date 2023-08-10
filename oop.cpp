#include <bits/stdc++.h>
using namespace std;

class parent {
	int a = 0;

   public:
	parent(int t = 0) : a(t) { cout << "parent: " << a << endl; }
	int get() { return a; }
	int set(int x) { return a = x; }
	void print() { cout << "Parent" << endl; }
	virtual int t() {
		cout << "parent: t" << a << endl;
		return 0;
	};
};

class derived : public parent {
   public:
	derived(int t = 0) : parent(t) { cout << "derived: " << t << endl; }
	void print() { cout << "Derived" << endl; }
	int t() {
		cout << "t" << endl;
		return 0;
	}
};

signed main(void) {
	parent z(10);
	z.t();
	return 0;
}