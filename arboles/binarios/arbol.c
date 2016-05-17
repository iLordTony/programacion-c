/*
    Archivo: arbol.c
    Autor: Carlos Tonatihu Barrera Pérez      Boleta: 2016630023

    Fecha de creación: viernes 07 de mayo de 2016
    Fecha de modificación:

    Descripción:
        Este archivo se encuentra el codigo de las funciones de 'arbol.h'

    Estructuras de Datos - ESCOM-IPN 2016
*/

#include "arbol.h"
/*
si el valor es menor al elemento lo manda a la izq y a la derecha en caso contrario
*/
int insertar(struct Arbol **arbol, int valor) {
    struct Arbol *arbol_nuevo = NULL;

    if (*arbol == NULL) {
        crearArbol(&arbol_nuevo);
        arbol_nuevo->elemento = valor;
        *arbol = arbol_nuevo;
    }

    crearArbol(&arbol_nuevo);
    arbol_nuevo->elemento = valor;

    if (valor < ((*arbol)->elemento)) {
        if((*arbol)->izquierda != NULL) {
            insertar(&((*arbol)->izquierda), valor);
        }
        (*arbol)->izquierda = arbol_nuevo;
    } else {
        if((*arbol)->derecha != NULL) {
            insertar(&((*arbol)->derecha), valor);
        }
        (*arbol)->derecha = arbol_nuevo;
    }
    return 1;
}

int crearArbol(struct Arbol **nuevo) {
    struct Arbol *auxiliar = NULL;
    auxiliar = (struct Arbol*)malloc(sizeof(struct Arbol));

    if (auxiliar == NULL) {
        return -1;
    }

    auxiliar->izquierda = NULL;
    auxiliar->derecha = NULL;
    *nuevo = auxiliar;
    return 1;
}

void mostar(struct Arbol *un_arbol){
    if(un_arbol == NULL) {
    	return;
    }
    printf("%d ", un_arbol->elemento);
    mostar(un_arbol->derecha);
    mostar(un_arbol->izquierda);
	
}
int buscar(struct Arbol *un_arbol, int dato){
    if(un_arbol==NULL){
        return -1;
    }
    if(dato==un_arbol->elemento){
        return 1;
    }
    if(dato > un_arbol->elemento){
	return buscar(un_arbol->derecha, dato);
    } else {
        return buscar(un_arbol->izquierda, dato);
    }
    return 0;
}