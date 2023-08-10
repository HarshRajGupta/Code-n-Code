#include <bits/stdc++.h>
using namespace std;

class parent {
	int a = 0;

   public:
	parent(int t = 0) : a(t) { cout << "parent: " << a << endl; }
	int get() { return a; }
	int set(int x) { return a = x; }
	void print() { cout << "Parent" << endl; }
};

class derived : public parent {
   public:
   	derived(int t = 0) : parent(t) { cout << "derived: " << t << endl; }
	void print() { cout << "Derived" << endl; }
};

signed main(void) {
	derived* d = new derived(5);
	cout << d->get();
	d->set(1);
	cout << d->get();
	return 0;
}