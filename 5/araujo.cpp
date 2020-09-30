#include <iostream>
#include <stdlib.h>
typedef struct Nodo{
    int dato;
    struct Nodo* izq, *der;
} Nodo;

using namespace std;

Nodo* BST;

void inicializarArbol(){
    BST = NULL;
}

Nodo* crearNodo(){
    Nodo* n = (Nodo*) malloc(sizeof(Nodo));
    if(n == NULL){
        cout << "fuck off";
        exit(0);
    }
    return n;
}

Nodo* inicializarNodo(int dato){
    Nodo* temp = crearNodo();
    temp->dato = dato;
    temp->izq = temp->der = NULL;
    return temp;
}

void quemarArbol(){
    Nodo* n1 = inicializarNodo(51);
    Nodo* n2 = inicializarNodo(37);
    Nodo* n3 = inicializarNodo(82);
    Nodo* n4 = inicializarNodo(25);
    Nodo* n5 = inicializarNodo(51);
    Nodo* n6 = inicializarNodo(61);
    Nodo* n7 = inicializarNodo(51);
    Nodo* n8 = inicializarNodo(73);
    BST = n1; n1->izq = n2; n1->der = n3;
    n2->izq = n4; n2->der = n5; n3->izq = n6;
    n5->izq = n7; n6->der = n8;
}

void mostrarArbolPreOrder(Nodo* T){
    if(T == NULL) return;
    cout << T->dato << " - ";
    mostrarArbolPreOrder(T->izq);
    mostrarArbolPreOrder(T->der);
}

bool seEncuentra(int n,Nodo* T){
    if(T == NULL) return false;
    if(T->dato == n) return true;
    if(n < T->dato) return seEncuentra(n, T->izq);
    else return seEncuentra(n, T->der);
}

int enQueNivelSeEncuentra(int n,Nodo* T){
    if(T->dato == n) return 1;
    if(n < T->dato) return 1 + seEncuentra(n, T->izq);
    else return 1 + seEncuentra(n, T->der);
}

int contarOcurrencias(int n,Nodo* T){
    if(T == NULL) return 0;
    int cont = 0;
    if(T->dato == n) cont++;
    if(n <= T->dato) cont += contarOcurrencias(n, T->izq);
    else cont += contarOcurrencias(n, T->der);
    return cont;
}

int contarOcurrenciasv2(int n,Nodo* T){ //Version resumida
    if(T == NULL) return 0;
    int cont = T->dato == n;
    return cont + (n <= T->dato) ? contarOcurrenciasv2(n, T->izq) : contarOcurrenciasv2(n, T->der);
}

int main()
{
    quemarArbol();
    mostrarArbolPreOrder(BST);
    
    if(seEncuentra(82,BST)) cout << "El 82 esta\n";
    else cout << "El 82 no esta\n";
    
    if(seEncuentra(115,BST)) cout << "El 115 esta\n";
    else cout << "El 115 no esta\n";
    
    int dato = 25;
    if(seEncuentra(dato,BST)) cout << "El dato " << dato << " esta en el nivel " << enQueNivelSeEncuentra(dato,BST);
    
    cout << "\nEl 51 se encuentra " << contarOcurrencias(51,BST) << " veces";
    //cout << "\nEl 51 se encuentra " << contarOcurrenciasv2(51,BST) << " veces";

    return 0;
}