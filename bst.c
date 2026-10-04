#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int key; struct Node *left, *right; } Node;

Node* newNode(int k){ Node* n = malloc(sizeof(Node)); n->key=k; n->left=n->right=NULL; return n; }

Node* insert(Node* r, int k){
    if(!r) return newNode(k);
    if(k < r->key) r->left = insert(r->left, k);
    else r->right = insert(r->right, k);
    return r;
}
void inorder(Node* r){ if(r){ inorder(r->left); printf("%d ", r->key); inorder(r->right);} }
void preorder(Node* r){ if(r){ printf("%d ", r->key); preorder(r->left); preorder(r->right);} }
void postorder(Node* r){ if(r){ postorder(r->left); postorder(r->right); printf("%d ", r->key);} }
int height(Node* r){ if(!r) return -1; int a=height(r->left), b=height(r->right); return (a>b?a:b)+1; }

int bstSearch(Node* r, int k, int* cmp){
    printf("  Path: ");
    while(r){
        (*cmp)++;
        printf("%d ", r->key);
        if(k == r->key){ printf("-> FOUND\n"); return 1; }
        r = (k < r->key) ? r->left : r->right;
    }
    printf("-> NOT FOUND\n");
    return 0;
}
int linearSearch(int a[], int n, int k, int* cmp){
    for(int i=0;i<n;i++){ (*cmp)++; if(a[i]==k) return i; }
    return -1;
}

int main(void){
    int keys[] = {45,20,60,10,30,50,70,25,55};
    int n = sizeof(keys)/sizeof(keys[0]);
    Node* root = NULL;
    for(int i=0;i<n;i++) root = insert(root, keys[i]);

    printf("Inorder   : "); inorder(root);   printf("\n");
    printf("Preorder  : "); preorder(root);  printf("\n");
    printf("Postorder : "); postorder(root); printf("\n");
    printf("Height of BST (edges) = %d\n\n", height(root));

    int targets[] = {25,55,90};
    int totB=0, totL=0;
    printf("%-8s %-14s %-14s\n","Key","BST cmps","Linear cmps");
    for(int i=0;i<3;i++){
        int cb=0, cl=0;
        printf("Searching %d (BST)\n", targets[i]);
        bstSearch(root, targets[i], &cb);
        linearSearch(keys, n, targets[i], &cl);
        printf("  BST=%d  Linear=%d\n", cb, cl);
        totB+=cb; totL+=cl;
    }
    printf("\nTotal comparisons: BST=%d, Linear=%d\n", totB, totL);
    return 0;
}
