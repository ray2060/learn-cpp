#include <iostream>

using namespace std;

struct Node {
    int val;
    int lc = 0, rc = 0;
    
    Node() {}
    
    Node(int x) {
        val = x;
    }
};
Node a[100000];
int idx = 1;

struct BSTree {
    int root = 0;
    
    BSTree() {}
    BSTree(int x) {
        a[idx] = Node(x);
        root = idx;
        printf("New tree, root No.%d\n", idx ++ );
        printf("Value: %d\n", x);
    }
    
    void add(int target) {
        if (root == 0) {
            printf("Not a tree.");
            return;
        }
        int now = root;
        while (a[now].lc || a[now].rc) {
            if (a[now].val == target) {
                printf("Cannot add node.\n");
                return;
            }
            if (a[now].val < target) {
                now = a[now].rc;
            } else {
                now = a[now].lc;
            }
        }
        if (a[now].val == target) {
            printf("Cannot add node.\n");
            return;
        }
        int nu = 0;
        if (a[now].val < target) {
            a[idx] = Node(target);
            a[now].rc = idx;
            nu = idx ++ ;
        } else {
            a[idx] = Node(target);
            a[now].lc = idx;
            nu = idx ++ ;
        }
        printf("Added a node, node No.%d\n", nu);
        printf("Value: %d\n", target);
    }
    
    void find(int target) {
        if (root == 0) {
            printf("Not a tree.");
            return;
        }
        int now = root;
        while (now != 0) {
            if (a[now].val == target) {
                printf("Found the node, node No.%d\n", now);
                printf("Value: %d\n", target);
                return;
            }
            if (a[now].val < target) {
                now = a[now].rc;
            } else {
                now = a[now].lc;
            }
        }
        printf("Node not found.\n");
    }
};

BSTree trees[1000];

int main() {
    int x;
    while (cin >> x) {
        if (x == 1) {
            int t, b;
            cin >> t >> b;
            puts("");
            printf("Tree %d\n", t);
            trees[t] = BSTree(b);
        }
        if (x == 2) {
            int t, b;
            cin >> t >> b;
            puts("");
            printf("Tree %d\n", t);
            trees[t].add(b);
        }
        if (x == 3) {
            int t, b;
            cin >> t >> b;
            puts("");
            printf("Tree %d\n", t);
            trees[t].find(b);
        }
    }
    return 0;
}