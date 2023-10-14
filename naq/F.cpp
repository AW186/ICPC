#include <cstdint>
#include <set>
#include <algorithm>
#include <map>
#include <deque>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    size_t s = str.size();
#define A 1
#define E ((uint32_t)1 << ('e' - 'a'))
#define I ((uint32_t)1 << ('i' - 'a'))
#define O ((uint32_t)1 << ('o' - 'a'))
#define U ((uint32_t)1 << ('u' - 'a'))
    uint32_t mask = A | E | I | O | U;
    int vowel = 0;
    int y = 0;
    for (int i = 0; i < s; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            vowel++;
        } else if (str[i] == 'y') y++;
    }
    cout << vowel << " " << (vowel + y) << endl;
    return 0;
        //Code here
}
