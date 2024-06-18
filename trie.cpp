#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

#define ALPHABET_SIZE (26)

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node 
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isWordEnd;
    unordered_map<string, bool> categories; // Category mapping
};

struct TrieNode* getNode() {
    struct TrieNode* pNode = new TrieNode;
    pNode->isWordEnd = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    return pNode;
}

// Returns 0 if current node has a child 
// If all children are NULL, return 1. 
bool isLastNode(struct TrieNode* root) 
{ 
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        if (root->children[i]) 
            return 0; 
    return 1; 
} 


void insert(struct TrieNode* root, const string key, const string category) {
    struct TrieNode* pCrawl = root;
    for (int level = 0; level < key.length(); level++) {
        int index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
        pCrawl->categories[category] = true; // Store category at each node
    }
    pCrawl->isWordEnd = true;
}

void suggestionsRec(struct TrieNode* root, string& currPrefix, const string category) {
    if (root->isWordEnd && root->categories.find(category) != root->categories.end()) {
        cout << currPrefix << endl;
    }

    if (isLastNode(root)) {
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            currPrefix.push_back('a' + i);
            suggestionsRec(root->children[i], currPrefix, category);
            currPrefix.pop_back();
        }
    }
}

int printAutoSuggestions(TrieNode* root, const string query, const string category) {
    struct TrieNode* pCrawl = root;
    for (int level = 0; level < query.length(); level++) {
        int index = CHAR_TO_INDEX(query[level]);
        if (!pCrawl->children[index])
            return 0;
        pCrawl = pCrawl->children[index];
    }

    bool isWord = (pCrawl->isWordEnd == true);
    bool isLast = isLastNode(pCrawl);

    if (isWord && isLast && pCrawl->categories.find(category) != pCrawl->categories.end()) {
        cout << query << endl;
        return -1;
    }

    if (!isLast) {
        string prefix = query;
        suggestionsRec(pCrawl, prefix, category);
        return 1;
    }
    return 0;
}

int main() {
    struct TrieNode* root = getNode();
    insert(root, "hello", "Emotion");
    insert(root, "dog", "Animal");
    insert(root, "hell", "Emotion");
    insert(root, "cat", "Animal");
    insert(root, "a", "Misc");
    insert(root, "hel", "Emotion");
    insert(root, "help", "Action");
    insert(root, "helps", "Action");
    insert(root, "helping", "Action");

    string query = "hel";
    string category = "Emotion";
    int comp = printAutoSuggestions(root, query, category);

    if (comp == -1)
        cout << "No other strings found with this prefix and category\n";
    else if (comp == 0)
        cout << "No string found with this prefix and category\n";

    return 0;
}