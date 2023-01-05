#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Initialize set
    set<int> s;

    s.insert(1);
    s.insert(4);
    s.insert(2);
    s.insert(5);
    s.insert(3);

    // finding position of 6
    auto pos = s.find(0);

    // print element if it is present in set
    if(pos != s.end())
        cout << "Element found at position : "<< *pos;
    else
        cout << "Element not present in set";

    return 0;
}
