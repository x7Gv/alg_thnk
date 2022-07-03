#include <stdio.h>

#define MAX_ROWS 100

int sl(int m, int n, int *a) {
    int min = a[0];
    int min_idx = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] < min) {

            min = a[i];
            min_idx = i;
        }
    }
    return min_idx;
}

void solve(int m, int n, int *a) {
    for (int i = 0; i < m; i++) {
        int shortest = sl(m, n, a);

        printf("%d\n", a[shortest]);
        a[shortest] += 1;
    }
}

int main() {

    int a[MAX_ROWS];
    int m, n = 0;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    solve(m, n, a);

    return 0;
}
