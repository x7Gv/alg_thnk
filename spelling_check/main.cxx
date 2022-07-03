#include <bits/stdc++.h>
// #include <dbg.h>

using namespace std;

string incorrect;
string correct;
int pos = 0;

unordered_set<int> delset;

char correct_i(int i) {
    if (i < 0) {
        return '\0';
    }

    return correct[i];
}

char incorrect_i(int i) {
    if (i < 0) {
        return '\0';
    }

    return incorrect[i];
}

void solve() {

    int dev = 0;
    for (int i = 0; i < incorrect.length(); i++) {
        if (correct_i(i) != incorrect_i(i)) {
            dev = i;
            break;
        }
    }

    int dev_num = 0;
    for (int i = 0; i < incorrect.length(); i++) {
        if (i <= dev) {
            if (correct_i(i) != incorrect_i(i))
                dev_num++;
        } else {
            if (correct_i(i-1) != incorrect_i(i))
                dev_num++;
        }
    }

    if (dev_num > 1) {
        return;
    }

    for (int i = 0; i < incorrect.length(); i++) {
        if (correct_i(i) != incorrect_i(i)) {

            if (correct_i(i) == '\x00') {
                delset.insert(i+1);

                int j = 1;
                while (incorrect_i(i - j) == incorrect_i(i)) {
                    delset.insert((i-j) + 1);
                    j++;
                }

                break;;
            }

            // //dbg(i, correct_i(i));
            pos++;
            delset.insert(i+1);

            int j = 1;
            while (incorrect_i(i - j) == incorrect_i(i)) {
                pos++;
                delset.insert((i-j) + 1);
                j++;
            }

            j = 1;
            while (incorrect_i(i + j) == incorrect_i(i)) {
                pos++;
                delset.insert((i+j) + 1);
                j++;
            }

            break;
        }
    }
}

int main() {

    cin >> incorrect;
    cin >> correct;

    solve();
    // solve();

    //dbg(delset);

    vector<int> deletions(delset.begin(), delset.end());

    sort(deletions.begin(), deletions.end());

    // //dbg(deletions);

    printf("%d\n", (int) deletions.size());
    for (int i = 0; i < deletions.size(); i++) {
        if (i == (deletions.size() - 1)) {
            printf("%d\n", deletions[i]);
            break;
        }
        printf("%d ", deletions[i]);
    }
}
