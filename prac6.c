/*
Nombre: Brayan López Mercado
Matrícula: 1280838
Fecha De Entrega: 2 De Octubre De 2024
Materia: Algoritmos y Estructura De Datos
Grupo: 552
Practica 6: Operaciones Basicas Con Arboles Binarios
*/
#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int dato;
    struct Nodo* hijoIzq;
    struct Nodo* hijoDer;
};

void imprimirArbol(struct Nodo* raiz, int espacio);
void insertar(struct Nodo* raiz,int dato);
struct Nodo* crearNodo(int dato);
struct Nodo* eliminar(struct Nodo* raiz, int dato);

int main(){
    struct Nodo* raiz=NULL;
    int opt=0;
    int dato;
    do{
        printf("1) Insertar Nodo\n");
        printf("2) Eliminar Nodo\n");
        printf("3) Salir\n");
        printf("Selecciona Una Opcion: ");
        scanf("%d",&opt);
        printf("\n");
        switch(opt){
            case 1:
                printf("Numero a Insertar: ");
                scanf("%d",&dato);
                if(raiz==NULL)
                    raiz=crearNodo(dato);
                else
                    insertar(raiz,dato);
                printf("\n");
                imprimirArbol(raiz,0);
                printf("\n");
                break;
            case 2:
                printf("Numero a Borrar: ");
                scanf("%d",&dato);
                raiz=eliminar(raiz,dato);
                imprimirArbol(raiz,0);
                printf("\n");
                break;
        };
    }while(opt!=3);
    free(raiz);
    return 0;
}


struct Nodo* crearNodo(int dato){
    struct Nodo* nuevoNodo=(struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato=dato;
    nuevoNodo->hijoIzq=NULL;
    nuevoNodo->hijoDer=NULL;
    return nuevoNodo;

}

void insertar(struct Nodo* raiz,int dato){
    struct Nodo* nodoActual=raiz;
    if(dato==nodoActual->dato){
        printf("El Numero Ya Existe Dentro Del Arbol");
        return;
    }
    struct Nodo* nuevoNodo=crearNodo(dato);
    if(nodoActual->hijoIzq==NULL && dato<nodoActual->dato){
        nodoActual->hijoIzq=nuevoNodo;
    }
    else if(nodoActual->hijoDer==NULL && dato>nodoActual->dato){
        nodoActual->hijoDer=nuevoNodo;
    }
    else{
        if (dato<nodoActual->dato)
            insertar(nodoActual->hijoIzq, dato);
        else 
            insertar(nodoActual->hijoDer,dato);
    }
}

struct Nodo* eliminar(struct Nodo* raiz, int dato){
    struct Nodo* nodoActual=raiz;
    if(nodoActual==NULL){
        printf("No Se Encontro El Numero Dentro Del Arbol\n");
        return raiz;
    }
    if(dato<nodoActual->dato)
        nodoActual->hijoIzq=eliminar(nodoActual->hijoIzq,dato);
    else if(dato>raiz->dato)
        nodoActual->hijoDer=eliminar(nodoActual->hijoDer,dato);
    else{
        struct Nodo* auxiliar;
        if(nodoActual->hijoIzq==NULL){
            auxiliar=nodoActual->hijoDer;
            free(nodoActual);
            return auxiliar;
        }
        else if(nodoActual->hijoDer==NULL){
            auxiliar=nodoActual->hijoIzq;
            free(nodoActual);
            return auxiliar;
        }
        else{
            struct Nodo* nodoSucesor=nodoActual->hijoDer;
            while(nodoSucesor!=NULL && nodoSucesor->hijoIzq!=NULL)
                nodoSucesor=nodoSucesor->hijoIzq;
            nodoActual->dato=nodoSucesor->dato;
            nodoActual->hijoDer=eliminar(nodoActual->hijoDer,nodoSucesor->dato);
        }
    }
    return nodoActual;
}

void imprimirArbol(struct Nodo* raiz,int espacio) {
    if (raiz==NULL)
        return;
    espacio+=5;
    imprimirArbol(raiz->hijoDer,espacio);
    printf("\n");
    for (int idx=5;idx<espacio;idx++)
        printf(" ");
    printf("%d\n",raiz->dato);
    imprimirArbol(raiz->hijoIzq,espacio);
}