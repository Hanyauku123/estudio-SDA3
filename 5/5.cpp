#include <iostream>
using namespace std;

struct node {
    int data;
    node* left, *right;

    node(){
        left = right = NULL;
    }
    
    node (int _data) : data(_data){
        left = right = NULL;
    }
};

void preOrder(node*);
void showNodes(node*);
int levelOfTree(node*);
void insertData(int, node**);


int main(void){
    node* tree = nullptr;

    insertData(30, &tree);
    insertData(10, &tree);
    insertData(12, &tree);
    insertData(28, &tree);
    insertData(9, &tree);
    insertData(11, &tree);
    insertData(7, &tree);
    insertData(15, &tree);
    insertData(65, &tree);
    insertData(100, &tree);

     cout << "******************** PreOrder traversal 1 ********************" << endl;
    preOrder(tree);

    cout << "******************** Cantidad de niveles ********************" << endl;
    levelOfTree(tree);

    return 0;
}

void preOrder(node* tree) {
    if(tree) {
        cout << tree->data << endl;
        preOrder(tree->left);
        preOrder(tree->right);
    }
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

int levelOfTree(node* level){
    if(!level){
        return 0;
    }else if(level->left!= NULL){
            return 1 + levelOfTree(level->left);
    }else{
        return 1 + levelOfTree(level->right);
    }
    return 0;
}