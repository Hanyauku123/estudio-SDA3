#include <iostream>
#include <stdlib.h>
#include <time.h>

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
void printNewTree(node*);
void insertData(int, node**);
void printKInterval(node*, int, int);

int main(void){
    srand(time(NULL));

    node* tree = NULL;

    
    for(int i = 0; i < 10; i++ )
        insertData(rand() % 50, &tree);
    
    cout << "******************** PreOrder traversal ********************" << endl;
    preOrder(tree);

    cout << "******************** Print K interval from random numbers********************" << endl;
    printKInterval(tree, 1, 20);
    

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

void preOrder(node* tree) {
    if(tree) {
        cout << tree->data << endl;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void printKInterval(node* compare, int k1, int k2){
    if(compare){
        printKInterval(compare->left, k1, k2);
        if(compare->data <= k2 &&  compare->data >= k1)
            cout<< compare->data << " "<<endl;
    printKInterval(compare->right, k1, k2);
    }
}

