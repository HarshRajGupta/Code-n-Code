#include <iostream>
using namespace std;
int f(int a[], int key) {
	int n = 6;
	int low = 0, high = 5;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[mid] == key)
			return mid;
		else if (a[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}
int main() {
	int a[] = {1, 3, 5, 67, 89, 758};
	cout << f(a, 3) << endl;

	return 0;
}