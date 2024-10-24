struct Node
{
    Node* links[26];
    int endWith=0,pref=0;

    void put(char c,Node* node){
        links[c-'a']=node;
    }

    bool containsKey(char c){
        return links[c-'a']!=NULL;
    }

    Node* get(char c){
        return links[c-'a'];
    }

    void increasePref(){
        pref++;
    }

    void decreasePref(){
        pref--;
    }


    void increaseEndWith(){
        endWith++;
    }

    void decreaseEndWith(){
        endWith--;
    }

    bool isEnd(){
        return endWith;
    }



    
};


class Trie{
private:
    Node* root=NULL;
public:

    Trie(){
        root=new Node();
    }

    void insert(string &word){
        Node* temp=root;

        for(char c:word){
            if(!temp->containsKey(c)){
                temp->put(c,new Node());
            }
            temp=temp->get(c);
            temp->pref+=1;
        }
        temp->endWith+=1;
    }

    int countWordsEqualTo(string &word){
        Node* temp=root;

        for(char c:word){
            if(!temp->containsKey(c)){
                return false;
            }
            temp=temp->get(c);
        }
        return temp->endWith;
    }

    int countWordsStartingWith(string &word){
        Node* temp=root;

        for(char c:word){
            if(!temp->containsKey(c)){
                return false;
            }
            temp=temp->get(c);
        }
        return temp->pref;
    }

    void erase(string &word){
        Node* temp=root;

        for(char c:word){
            if(!temp->containsKey(c)){
                return;
            }
            temp=temp->get(c);
            temp->pref-=1;
        }
        temp->endWith-=1;
    }
};
