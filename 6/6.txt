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

void preOrder(node*);
void insertData(int, node**);
bool compareTree(node*, node*);

int main(void){
    
    node* tree1= NULL;
    node* tree2 = NULL;

    //insert on tree 1
    insertData(30, &tree1);
    insertData(10, &tree1);
    insertData(11, &tree1);
    insertData(28, &tree1);
    insertData(9, &tree1);
    insertData(11, &tree1);
    insertData(250, &tree1);

    //insert on tree 2
    insertData(30, &tree2);
    insertData(10, &tree2);
    insertData(11, &tree2);
    insertData(28, &tree2);
    insertData(9, &tree2);
    insertData(11, &tree2);
    insertData(250, &tree2);

    cout << "******************** PreOrder traversal 1 ********************" << endl;
    preOrder(tree1);

    cout << "******************** PreOrder traversal 2 ********************" << endl;
    preOrder(tree2);

    cout << "******************** The Same Tree :O ********************" << endl;
    cout << " Es el mismo: " << (compareTree(tree1, tree2) ? "verdadero" : "falso") << endl;


    return 0;
}

//insert data on tree1 and tree2
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

//showing data in PreOrder
void preOrder(node* tree) {
    if(tree) {
        cout << tree->data << endl;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

//comparing data from tree1 && tree2
bool compareTree(node* t1, node* t2){
    if(!t1 && !t2) return 1;
    else if(t1 && t2)
            if(t1->data == t2->data && compareTree(t1->left, t2->left) && compareTree(t1->right, t2->right)) return 1;
    
    return 0;
}