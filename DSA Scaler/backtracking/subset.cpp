#include <iostream>
#include <string>

using namespace std;

void allSubset(string a, int i, string add, int N)
{
    if (i == N)
    {
        cout << add << endl;
        return;
    }

    // dos

    add = add + (a.at(i));

    // method
    allSubset(a, i + 1, add, N);
    add.pop_back();

    allSubset(a, i + 1, add, N);
}

int main()
{
    string s, add;
    cin >> s;

    allSubset(s, 0, add, s.size());
}