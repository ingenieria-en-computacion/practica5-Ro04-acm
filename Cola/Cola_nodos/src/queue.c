#include "queue.h"
#include <stdlib.h>

Queue* queue_create(){
    Queue* q = (Queue*)malloc(sizeof(Queue)); //inicializamos la memoria
    if (q != NULL) {
        q->head = NULL; //al apenas crearse apunta a nulo
        q->tail = NULL;
    }
    return q; //retorna lo que recien creamos
}

void queue_enqueue(Queue* q, Data d){
    if (q == NULL) return; //retornamos sin hacer nada
    
    Node* new_node = (Node*)malloc(sizeof(Node)); //creamos un nuevo nodo y usamos next para el ultimo elemento del nodo
    if (new_node == NULL) return;//si no se puede asigmar retornamos el error null

    new_node->data = d; //asignasmos el valor de d
    new_node->next = NULL; //nuevo nodo es el ultimo por ende el sig es nulo

    if (q->tail != NULL) {
        q->tail->next = new_node; //si la cola no esta vacia el nodo actual apunta al nuevo
    }
    q->tail = new_node; //se convierte emn el ultimo nodo

    if (q->head == NULL) {
        q->head = new_node; //si la cola estaba vacia el nuevo se vuelve el primero
    }
}

Data queue_dequeue(Queue* q){
    if (q == NULL || q->head == NULL) { // Si la cola no existe 
        return -1; // Devuelve un valor por defecto.
    }

    Node* temp = q->head; // Almacena un puntero temporal al primer nodo.
    Data value = temp->data; // Guarda el valor del primer nodo.
    q->head = q->head->next; // El segundo nodo se convierte en el primero.

    if (q->head == NULL) { // Si la cola esta vacia
        q->tail = NULL; // También ponemos tail en NULL.
    }

    free(temp); // Libera la memoria del nodo desencolado.
    return value; // Devuelve el valor del nodo eliminado.
}

bool queue_is_empty(Queue* q){
    return (q == NULL || q->head == NULL); // La cola esta vacía si head es NULL o la cola no existe.
}

Data queue_front(Queue* q){
    if (q == NULL || q->head == NULL) { // Si la cola no existe 
        return -1; // Devuelve un valor por defecto.
    }
    return q->head->data; // Devuelve el valor del primer nodo.
}

void queue_empty(Queue* q){
    while (!queue_is_empty(q)) { // Mientras la cola no este vacia
        queue_dequeue(q); // Desencola (elimina) el primer nodo. (lo hicimos arriba)
    }
}

void queue_delete(Queue* q){
    if (q != NULL) { // Si la cola no es NULL
        queue_empty(q); //  elimina todos los nodos.
        free(q); // Libera la memoria de la estructura Queue.
    }
}