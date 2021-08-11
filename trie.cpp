#include <bits/stdc++.h>
using namespace std;
class TrieNode {
public:
  bool isWord;
  vector<TrieNode*> children;
  
  TrieNode() {
    isWord = false;
    children = vector<TrieNode*>(26, NULL);
  }
};

class Trie {
private:
  TrieNode *root;
  
public:
  TrieNode *getRoot() {
    return root;
  }
  
  Trie(vector<string>& words) {
    root = new TrieNode();
    for(int i=0; i<words.size(); ++i)
      addWord(words[i]);
  }
  
  void addWord(const string& word) {
    TrieNode *cur = root;
    for (int i = 0; i < word.size(); ++i) {
      int index = word[i] - 'a';
      if (!cur->children[index])
        cur->children[index] = new TrieNode();
      cur = cur->children[index];
    }
    cur->isWord = true;
  }
};
