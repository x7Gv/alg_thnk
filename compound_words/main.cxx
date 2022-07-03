#include <bits/stdc++.h>
// #include <dbg.h>

using namespace std;

unordered_set<string> dict;
set<string> compounds;

template <typename T>
pair<T, bool> nth_elem(unordered_set<T>& searchSet,
                            int index)
{
    pair<T, bool> result;

    if (searchSet.size() > index) {
        result.first
            = *(std::next(
                searchSet.begin(),
                index));
        result.second = true;
    }

    else
        result.second = false;

    return result;
}

void solve() {
    int i = 1;
    for (string element : dict) {
        for (int i = 1; i < element.length(); i++) {
            string a = element.substr(0, i);
            string b = element.substr(i, element.length());

            if (dict.count(a) && dict.count(b)) {
                compounds.insert(a + b);
                break;
            }
        }
    }
}

int main() {

    int i, n = 0;
    string word;

    while (cin >> word) {
        dict.insert(word);
    }

    solve();

    for (string compound : compounds) {
        printf("%s\n", compound.c_str());
    }

    return 0;
}
