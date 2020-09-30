#include <iostream>
using namespace std;

struct node {
    int data;
    node* left, *right;

    node(){
        left = right = nullptr;
    }
    
    node (int _data) : data(_data){
        left = right = nullptr;
    }
};

void inOrder(node*);
void preOrder(node*);
int countLeaf(node*);
int countNodes(node*);
void postOrder(node*);
void insertData(int, node**);

int main(void){
    node* tree = nullptr;

    insertData(30, &tree);
    insertData(10, &tree);
    insertData(11, &tree);
    insertData(28, &tree);
    insertData(9, &tree);
    insertData(11, &tree);
    insertData(7, &tree);
    insertData(15, &tree);
    insertData(65, &tree);
    insertData(100, &tree);
    insertData(20, &tree);
    insertData(35, &tree);
    insertData(68, &tree);
    
     cout << "******************** InOrder traversal ********************" << endl;
    inOrder(tree);

    cout << "******************** PreOrder traversal ********************" << endl;
    preOrder(tree);

    cout << "******************** PostOrder traversal ********************" << endl;
    postOrder(tree);

    cout << "Node numbers: " << countNodes(tree) << endl;

    cout<<"Leaf numbers: " << countLeaf(tree) << endl;
    
    return 0;
}

void insertData(int number, node** root){
    if(!*root){
        *root = new node(number);
    }else{
        if(number < (*root)->data){
            insertData(number, &(*root)->left);
        }else{
            insertData(number, &(*root)->right);
        }
    }
}

void inOrder(node* tree) {
    if(tree) {
        inOrder(tree->left);
        cout << tree->data << endl;
        inOrder(tree->right);
    }
}

void postOrder(node* tree) {
    if(tree) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->data << endl;
    }
}

void preOrder(node* tree) {
    if(tree) {
        cout << tree->data << endl;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

int countNodes(node* full){
    if(!full) return 0;

    return 1 + countNodes(full->left) + countNodes(full->right);
}

int countLeaf(node* junior){
    if(!junior) return 0;
    if(junior->left == NULL && junior->right == NULL) return 1;

    return countLeaf(junior->left) + countLeaf(junior->right);
}