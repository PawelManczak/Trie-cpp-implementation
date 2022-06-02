#include <iostream>
#include <string>

#define MAX_CHARS 26
#define NOT_INITIALIZED "-"

using namespace std;

class Trie {
public:
    Trie* children[MAX_CHARS] = {}; 
    bool endOfWord = false;

    Trie() {
        for (int i = 0; i < MAX_CHARS; i++)
            children[i] == nullptr;
    }

    void insert(string);
    bool search(string);
};

void Trie::insert(string s) {
    Trie* curr = this;

    for (int i = 0; i < s.size(); i++)
    {
        if (curr->children[s[i] - 'a'] == nullptr) {
            curr->children[s[i] - 'a'] = new Trie();
        }

        curr = curr->children[s[i] - 'a'];
    }

    curr->endOfWord = true;
}

bool Trie::search(string s) {
    Trie* curr = this;

    for (int i = 0; i < s.size(); i++) {
        if (curr->children[s[i] - 'a'] != nullptr)
            curr = curr->children[s[i] - 'a'];
        else
            return false;
    }

    return curr->endOfWord;
}
int main()
{
    Trie* trie = new Trie();

    trie->insert("word");
    cout << trie->search("word");
}

