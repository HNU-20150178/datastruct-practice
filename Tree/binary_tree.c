#include <stdio.h>
#include <string.h>
typedef struct node{
    int key;
    struct node *left;
    struct node *right;
}node;
node *head, *tail;

void preorder_traverse(node *n){
    if(n!=tail){
        visit(n);
        preorder_traverse(n->left);
        preorder_traverse(n->right);
    }
}

void inorder_traverse(node *n){
    if(n!=tail){
        inorder_traverse(n->left);
        visit(n);
        inorder_traverse(n->right);
    }
}

void postorder_traverse(node *n){
    if(n!=tail){
        postorder_traverse(n->left);
        postorder_traverse(n->right);
        visit(n);
    }
}

void levelorder_traverse(node *n){
    put(n);
    while(!is_queue_empty()){
        n=get();
        visit(n);
        if(n->left != tail) put(n->left);
        if(n->right != tail) put(n->right);
    }
}



int main(){

}