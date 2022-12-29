#include<iostream>
#include<map>

using namespace std;

struct TreeNode{
    char ch;
    int freq;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(char c, int f){
        ch = c;
        freq = f;
        left = NULL;
        right = NULL;
    }

};

map<char, int> generateFrequencyMap(string s){
    map<char, int> m;
    
    for(int i=0; i<s.length(); i++){
        m[s[i]] = 0;
    }

    for(int i=0; i<s.length(); i++){
        m[s[i]]++;
    }

    return m;
}

class MinHeap{
    TreeNode** heap;
    int size = 0;
public:
    MinHeap(){
        heap = new TreeNode*[26];
    } 

    void minHeapify(int index){
        TreeNode* t = heap[index];
        int freq = heap[index]->freq;
        int parentIndex = (index -1) / 2;

        while(freq < heap[parentIndex]->freq && index >= 0){
            heap[index] = heap[parentIndex];
            index = parentIndex;
            parentIndex = (index - 1) / 2;
        }

        heap[index] = t;
    }

    void downHeapify(int index){
        TreeNode* t = heap[index];
        
        int freq = t->freq;
        int childIndex1 = 2*index + 1;
        int childIndex2 = 2*index + 2;

        int minIndex = heap[childIndex1]->freq < heap[childIndex2]->freq ? childIndex1 : childIndex2;
        
        while(heap[childIndex1] && heap[childIndex2] && index < size && freq > heap[index]->freq){
            index = minIndex;
            childIndex1 = 2*index + 1;
            childIndex2 = 2*index + 2;
            minIndex = heap[childIndex1]->freq < heap[childIndex2]->freq ? childIndex1 : childIndex2;
        }


    }

    void Insert(TreeNode* n){
        if(size == 0){
            heap[size] = n;
            size++;
            return;
        }
        
        heap[size] = n;
        minHeapify(size);
        size++;
    }

    TreeNode* Delete(){
        TreeNode* t = heap[0];
        heap[0] = heap[size - 1];
        size--;
        downHeapify(0);

        return t;    
    }

    int getSize(){
        return size;
    }

    void display(){
        for(int i=0; i<size; i++){
            cout<<heap[i]->ch<<" : "<<heap[i]->freq<<endl;
        }
    }
};

TreeNode* giveHuffmanTree(MinHeap &min){
    while(min.getSize() > 1){
        TreeNode* t1 = min.Delete();
        TreeNode* t2 = min.Delete();

        TreeNode* t = new TreeNode(' ', t1->freq + t2->freq);
        t->left = t1;
        t->right = t2;

        min.Insert(t);
    }

    return min.Delete();
}

void getCodedElements(TreeNode* t, string s, map<char, string> &m){
    if(t == NULL){
        return;
    }

    if(t->ch != ' '){
        m[t->ch] = s;
    }

    getCodedElements(t->left, s+'0', m);
    getCodedElements(t->right, s+'1', m);
}

string getCode(map<char, string> m, string s){
    string res = "";
    for(int i=0; i<s.length(); i++){
        res+=m[s[i]];
    }

    return res;
}

string HuffmanEncoder(string s){
    map<char, int> m = generateFrequencyMap(s);
    MinHeap minHeap;

    for(auto it:m){
        TreeNode* t = new TreeNode(it.first, it.second);
        minHeap.Insert(t);
    }
    
    TreeNode* t = giveHuffmanTree(minHeap);
    map<char, string> codedMap;
    getCodedElements(t, "", codedMap);

    return getCode(codedMap, s);
}

int main(){

    cout<<HuffmanEncoder("Hello world");
    return 0;
}