#include<iostream>

using namespace std;

class Set {

    public:

    int data;
    int rank;
    Set * parent;

    Set (int arg_data, int arg_rank) : data(arg_data), rank(arg_rank), parent(this) {
        cout << "Created set : " << arg_data << " Parent : " << parent->data <<  " Rank : " << arg_rank << endl;
    }
    Set* FindParent (Set& );
    void Merge (Set&, Set&);
};

// FindParent applies path compression to all the nodes in the search path of the parent
// without changing their ranks.
Set* FindParent (Set& s) {
    if ( s.data != s.parent->data ) {
        s.parent = FindParent (*(s.parent));
    }
    return s.parent;
}

// Merge operation makes use of heuristic union-by-rank.
void Merge (Set& a, Set& b) {

    Set* parent_of_a = FindParent(a);
    Set* parent_of_b = FindParent(b);

    if ( parent_of_a->data != parent_of_b->data ) {
        if ( a.rank < b.rank ) {
             a.parent = parent_of_b;
             b.rank += 1;
        } else {
             b.parent = parent_of_a;
             a.rank += 1;
        }
    }

    cout << "\nMerging " << a.data << " & " << b.data << endl;
    cout << "Rank of : " << a.data << " = " << a.rank << endl;
    cout << "Parent of : " << a.data << " = " << a.parent->data << endl;
    cout << "Rank of : " << b.data << " = " << b.rank << endl;
    cout << "Parent of : " << b.data << " = " << b.parent->data << endl;
}

int main() {

    // Initially every node in a set has a rank 0 and is a parent of itself
    Set s1(1, 0); // Data : 1, Rank : 0, Parent : 1
    Set s2(2, 0);
    Set s3(3, 0);
    Set s4(4, 0);
    Set s5(5, 0);
    Set s6(6, 0);
    Set s7(7, 0);
    Set s8(8, 0);
    Set s9(9, 0);
    Set s10(10, 0);

    Merge (s1, s3);
    Merge (s2, s4);
    /* 
       1      2
       ^      ^
       |      |
       3      4
    */

    Merge (s3, s5);
    Merge (s4, s6);

    /*
       1        2
       ^        ^
       | \      | \
       3  5     4  6 
    */

    Merge (s1, s6);

    return 0;
}
