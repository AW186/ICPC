#include <set>
#include <algorithm>
#include <unordered_map>
#include <deque>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

struct Val {
    int len;
    int dups;
};
struct Node {
    int start;
    int end;
};

class Trie {
    Trie *root;
    char current;
    vector<Trie *> child;
public:
    bool isWord;
    int wordLen;
    Trie * next(char val) {
        return child[val - 'a'];
    }
    Trie(Trie *root) {
        this->root = root;
        child = vector<Trie *>(26);
    }
    Trie() {
        this->root = this;
        child = vector<Trie *>(26);
    }
    void add(string val, int start) {
        if (start < val.size()) {
            if (!child[val[start] - 'a']) child[val[start] - 'a'] = new Trie();
            child[val[start]]->add(val, start - 1);
        } else {
            this->isWord = true;
            this->wordLen = val.size();
        }
    }
};

Trie *root;
string str;
unordered_map<int, unordered_map<int, Val>> visit;

Val dfs(int start, int end) {
    if (visit[start][end].dups) return visit[start][end];
    deque<Trie *> q;
    int min = end - start;
    int sum = 1;
    for (int i = start; i < end; i++) {
        int size = q.size();
        int c = str[i];
        for (int k = 0; k < size; k++) {
            auto node = q.front();
            node = node->next(c);
            if (node && node->isWord) {
                auto val = dfs(start, i - node->wordLen);
                if (val.len < min) {
                    min = val.len;
                    sum = val.dups;
                } else if (val.len
            }
        }
        if (root->next(str[i])) q.push_back(root->next(str[i]));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //Code here
    cin >> str;
    root = new Trie();
    root->add("one", 0);
    root->add("two", 0);
    root->add("three", 0);
    root->add("four", 0);
    root->add("five", 0);
    root->add("six", 0);
    root->add("seven", 0);
    root->add("eight", 0);
    auto val = dfs(0, str.size());
    cout << val.len << "\n" << val.dups << endl;
}





