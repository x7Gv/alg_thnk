#include <bits/stdc++.h>
// #include <dbg.h>

using namespace std;

int n, m = 0;

unordered_set<int> cds_n;
unordered_set<int> cds_m;

vector<int> solutions;

void solve() {

    int count = 0;
    auto source = (n <= m) ? &cds_n : &cds_m;
    auto comp = (m >= n) ? &cds_m : &cds_n;


    for (int elem : *source) {

        // dbg(elem);

        if (comp->count(elem) == 1) {
            count++;
        }
    }

    solutions.push_back(count);
}

int main() {

    while (1) {
        scanf("%d %d", &n, &m);

        if (n == 0 && m == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            int cd = 0;
            scanf("%d", &cd);
            cds_n.insert(cd);
        }

        for (int i = 0; i < m; i++) {
            int cd = 0;
            scanf("%d", &cd);
            cds_m.insert(cd);
        }

        solve();

        // dbg(cds_n, cds_m);

        cds_n.clear();
        cds_m.clear();
    }

    for (auto elem : solutions) {
        printf("%d\n", elem);
    }
}
