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

struct nodeCola
{
    int nivel;
    int data;
    nodeCola *next;

};

void preOrder(node*);
void insertData(int, node**);
void levelOfTree(node*, int);
//int levelOfTree(node*);
void insertInCola( nodeCola **, int, int);
void printLista(nodeCola*);

nodeCola * listaOrdenada;

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
    levelOfTree(tree, 0);
    //printLista(listaOrdenada);
    
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

/*int levelOfTree(node* level){
    if(!level){
        return 0;
    }else if(level->left!= NULL){
            return 1 + levelOfTree(level->left);
    }else{
        return 1 + levelOfTree(level->right);
    }
    return 0;
}*/

/*void levelOfTree(node *level, int n){
    if(level){
        cout << "nivel: " << n << endl;
        cout << level->data << endl;
        levelOfTree(level->right, ++n);
        levelOfTree(level->left, ++n);
    }
}*/



//funci'on que calcula los niveles y toma los valores de los nodos
void levelOfTree(node *level, int n){
    if (level){
        insertInCola(&listaOrdenada, level->data, n);
        cout << "Nivel: " << n << endl;
        cout << level->data << endl;
        levelOfTree(level->left, ++n);
        levelOfTree(level->right, ++n);
    }
}

void insertInCola( nodeCola ** lista, int valor, int nivel){
    nodeCola * recl = (*lista);
    nodeCola * ant = recl;
    cout << "hola" << endl;
    if(!recl){
        *lista = new nodeCola();
        (*lista)->data = valor;
        (*lista)->nivel = nivel;
        (*lista)->next = NULL;
        cout << (*lista)->nivel << endl;

    }
    //while no ocurre
    while(true){
        if(recl->nivel > nivel || recl == NULL ){
            cout << "hola"<<endl;
            nodeCola * aux = recl;
            nodeCola * nuevo = new nodeCola();
            nuevo->data = valor;
            nuevo->nivel = nivel;
            nuevo->next = aux;
            ant->next = nuevo;
            break;
        }
        ant = recl;
        recl = recl->next;
    }
}

//funcion que imprime la cola con sus niveles
void printLista(nodeCola * lista){
    nodeCola * aux = lista;
    while(aux){
        cout << "Nivel: " << lista->nivel << "Dato:" << lista->data << endl;
        aux = aux->next;
    }
}
