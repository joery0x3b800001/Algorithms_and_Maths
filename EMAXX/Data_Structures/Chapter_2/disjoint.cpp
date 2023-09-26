// Here we implement the Union-Find Data structure which helps in maintaining set and performs three operations.
// 1.Find(n) : returns the set number to which n belongs to and performs path compression
// 2.Union(a,b): joins the set containing a and back
// 3.makeset(size): initializes the array of nodes with given size



#include<bits/stdc++.h>
using namespace std;

class dsu{
    struct node{
        //int rank;
        int parent;
        int data; // optional if want to store any data in each node
        int size; // size of the set it belongs to
    };

    vector<node> store;
    public:
    void makeset(int size){
        store.resize(size+1); // if indexing is from 1
        for(int i = 0; i <= size; i++){
            //store[i].rank = 0;
            store[i].parent = i;
            store[i].size = 1; 
            store[i].data = i;
        }
    }

    int find(int ele){
        stack<int> elements;
        while(store[ele].parent != ele){
            elements.push(ele);
            ele = store[ele].parent;
        }
        while(!elements.empty()){     // applying path compression
            store[elements.top()].parent = ele;
            elements.pop();
        }
        return ele; 
    }

    void unionset(int a, int b){
        int aset = find(a);
        int bset = find(b);

        if(aset==bset) return;
        else{
            int root = (store[aset].size > store[bset].size) ? aset: bset;
            store[aset].parent = store[bset].parent = root;
            int temp = store[aset].size;
            store[aset].size += store[bset].size;
            store[bset].size += temp;
        }
    }
};

int main(){
    dsu arr;
    arr.makeset(10);
    arr.unionset(1,2);
    arr.unionset(3,8);
    arr.unionset(4,7);
    arr.unionset(5,2);
    arr.unionset(3,2);

    for(int i = 1; i <= 10; i++){
        cout<<arr.find(i)<<" ";
    }
    return 0;
}