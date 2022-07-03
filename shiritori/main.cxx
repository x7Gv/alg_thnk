#include <bits/stdc++.h>
// #include <dbg.h>

#define FAIR_GAME -1
#define PLAYER_1_L 1
#define PLAYER_2_L 2

using namespace std;

unordered_set<string> words;
int n = 0;

int main() {
    scanf("%d", &n);

    int state = FAIR_GAME;

    char last = '\0';
    for (int i = 0; i < n; i++) {

        string word;
        cin >> word;

        if (last == '\0') {
            words.insert(word);
            last = word[word.length() - 1];
        } else {
            if (word[0] == last && (words.count(word) == 0)) {
                words.insert(word);
                last = word[word.length() - 1];
            } else {
                state = (i % 2 == 0) ? PLAYER_1_L : PLAYER_2_L;
                break;
            }
        }
    }

    switch (state) {
        case FAIR_GAME:
            printf("Fair Game\n");
            break;
        case PLAYER_1_L:
            printf("Player 1 lost\n");
            break;
        case PLAYER_2_L:
            printf("Player 2 lost\n");
            break;
    }
}
