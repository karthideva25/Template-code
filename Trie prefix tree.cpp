class Trie{
    struct TrieNode{
        TrieNode* children[26];
        bool isEnd;
        
        TrieNode(){
            isEnd = false;
            for(int i=0;i<26;i++){
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode* node = root;
        for(char ch: word){
            int index = ch - 'a';
            if(node->children[index] == nullptr){
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
    
    bool search(string word){
        TrieNode* node = root;
        for(char ch: word){
            int index = ch - 'a';
            if(node->children[index] == nullptr){
                return false;
            }
            node = node->children[index];
        }
        return node->isEnd;
    }
    
    bool isStartsWith(string word){
        TrieNode* node = root;
        for(char ch: word){
            int index = ch - 'a';
            if(node->children[index] == nullptr){
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
};



class Trie {
    struct TrieNode{
        TrieNode* children[26];
        bool isEnd;
        
        TrieNode(){
            for(int i=0;i<26;i++){
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;
  public:

    Trie() {
        root = new TrieNode();
    }

    void insert(string &word) {
        TrieNode* node = root;
        for(char ch : word){
            int index = ch - 'a';
            if(node->children[index] == nullptr){
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool search(string &word) {
        TrieNode* node = root;
        for(char ch : word){
            int index = ch - 'a';
            if(node->children[index] == nullptr){
                return false;
            }
            node = node->children[index];
        }
        return node->isEnd;
    }

    bool isPrefix(string &word) {
        TrieNode* node = root;
        for(char ch : word){
            int index = ch - 'a';
            if(node->children[index] == nullptr){
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
};
