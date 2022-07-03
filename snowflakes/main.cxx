#include <bits/stdc++.h>
// #include <dbg.h>

using namespace std;

#define MAX_N 100000

array<array<int, 6>, MAX_N> flakes;

int flake_id_r(int flake1[6], int flake2[6], int start) {
    int i;
    for (i = 0; i < 6; i++) {
        if (flake1[i] != flake2[(start + i) % 6]) {
            return 0;
        }
    }

    return 1;
}

int flake_id_l(int flake1[6], int flake2[6], int start) {
    int i;
    for (i = 0; i < 6; i++) {
        int idx = (start - i < 0) ? (start - i) + 6 : start - i;
        if (flake1[i] != flake2[idx]) {
            return 0;
        }
    }
    return 1;
}

int flake_id(int flake1[6], int flake2[6]) {
    int start;
    for (start = 0; start < 6; start++) {
        if (flake_id_r(flake1, flake2, start)) {
            return 1;
        }
        if (flake_id_l(flake1, flake2, start)) {
            return 1;
        }
    }
    return 0;
}

int hash_code(int snowflake[6]) {
    return (snowflake[0] + snowflake[1] + snowflake[2] + snowflake[3] + snowflake[4] + snowflake[5]) % MAX_N;
}

void solve(int n) {
    unordered_multimap<int, array<int, 6>> umm(MAX_N);

    for (int i = 0; i < n; i++) {

        int flks[6];
        for (int j = 0; j < 6; j++) {
            flks[j] = flakes[i][j];
        }

        unsigned int code = hash_code(flks);

        umm.emplace(code, flakes[i]);
    }

    typedef unordered_multimap<int, array<int, 6>>::iterator UMMIterator;

    // dbg(umm.size());

    for (unordered_multimap<int, array<int, 6>>::iterator it = umm.begin(); it != umm.end();) {
        int key = it->first;

        std::pair<UMMIterator, UMMIterator> values = umm.equal_range(key);

        for (UMMIterator it2 = values.first; it2 != values.second; it2++) {
            for (UMMIterator it3 = values.first; it3 != values.second && it3 != it2; it3++) {
                if (flake_id(it2->second.data(), it3->second.data()) == 1) {
                    printf("Twin snowflakes found.\n");
                    return;
                }
            }
        }

        do {
            ++it;
        } while (it != umm.end() && key == it->first);
    }

    printf("No two snowflakes are alike.\n");
}

int main() {

    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        array<int, 6> flake;
        for (int j = 0; j < 6; j++) {
            int tmp = 0;
            scanf("%d", &tmp);
            flake[j] = tmp;
            // dbg(flake[j]);
        }
        flakes[i] = flake;
        // dbg(flakes[i]);
    }

    solve(n);

    return 0;
}
