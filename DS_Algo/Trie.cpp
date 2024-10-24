// https://www.youtube.com/watch?v=dBGUmUQhjaM

/*
Time Complexity:
Insertion: O(N) where N is the length of the word being inserted. This is because we have to iterate over each letter of the word to find its corresponding node or create a node accordingly.
Search: O(N) where N is the length of the word being searched for. This is because in Trie search we traverse over each letter for the word from the root, checking if the current node contains a node at the index of the next letter. This process repeats until we reach the end of the word or encounter a node without the next letter.
Prefix Search: O(N) where N is the length of the prefix being searched for. Similar to searching for words, in prefix search we also iterate over each letter of the word to find its corresponding node.

Space Complexity: 
O(N) where N is the total number of characters across all unique words inserted into the Trie. For each character in a word, a new node may need to be created leading to space proportional to the number of characters.
*/

struct Node{
    Node* links[26];
    bool flag=false;

    void put(char c,Node* node){
        links[c-'a']=node;
    }

    Node* get(char c){
        return links[c-'a'];
    }

    bool containsKey(char c){
        return links[c-'a']!=NULL;
    }

    void setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie {

private:
    Node* root=NULL;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* temp=root;
        for(char c:word){
            if(!temp->containsKey(c)){
                temp->put(c,new Node());
            }
            temp=temp->get(c);
        }
        temp->setEnd();
    }
    
    bool search(string word) {
        Node* temp=root;
        for(char c:word){
            if(!temp->containsKey(c)){
                return false;
            }
            temp=temp->get(c);
        }
        return temp->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        for(char c:prefix){
            if(!temp->containsKey(c)){
                return false;
            }
            temp=temp->get(c);
        }
        return true;
    }
};
