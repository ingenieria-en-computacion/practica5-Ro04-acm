#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Crea una nueva pila vacía y la devuelve.
 * 
 * @return Un auntador a la nueva pila creada. Si la creación falla, devuelve NULL.
 * @details Esta función asigna memoria dinámicamente para una nueva pila utilizando `malloc`.
 *          Si la asignación de memoria falla, la función devuelve NULL. La pila creada
 *          está vacía y top apunta a NULL
 */
Stack *stack_create(){
    Stack *s = (Stack*)malloc(sizeof(Stack)); // Asigna memoria para la pila
    s->top = NULL;  // La pila está vacía, por lo tanto, `top` apunta a NULL
    return s;  
}

/**
 * Inserta un elemento en la parte superior de la pila.
 * 
 * @param s Auntador a la pila donde se insertará el elemento.
 * @param d Dato que se insertará en la pila.
 * @details Esta función añade el dato `d` en la parte superior de la pila. Si la pila está llena
 *          o el puntero `s` es NULL, la función no realiza ninguna operación.
 */
void stack_push(Stack* s, Data d){
    if (s == NULL) {  // Verifica que la pila no sea NULL
        printf("Pila no válida.\n");
        return;
    }

    Node *n = new_node(d);  // Crea un nuevo nodo con el dato proporcionado
    if (n == NULL) {  // Verifica si la creación del nodo fue exitosa
        printf("Error al crear el nodo.\n");
        return;
    }

    n->next = s->top;  // El nuevo nodo apunta al nodo que está en la parte superior de la pila
    s->top = n; 
}

/**
 * Elimina y devuelve el elemento en la parte superior de la pila.
 * 
 * @param s Auntador a la pila de la cual se eliminará el elemento.
 * @return El dato que estaba en la parte superior de la pila. Si la pila está vacía o el puntero
 *         `s` es NULL, devuelve un valor que indica error (por ejemplo, -1 o un valor predeterminado).
 * @details Esta función elimina el elemento en la parte superior de la pila y lo devuelve.
 *          Si la pila está vacía, no se realiza ninguna operación y se devuelve un valor de error.
 */
Data stack_pop(Stack* s){

}

/**
 * Verifica si la pila está vacía.
 * 
 * @param s Auntador a la pila que se desea verificar.
 * @return 1 si la pila está vacía, 0 si no lo está. Si el puntero `s` es NULL, devuelve -1.
 * @details Esta función comprueba si la pila no contiene elementos. Es útil para evitar operaciones
 *          como `stack_pop` en una pila vacía.
 */
int stack_is_empty(Stack* s){
    if (s == NULL) {  // Verifica si la pila o la parte superior de la pila es NULL
        printf("Pila vacía o inválida.\n");
        return -1;  // Valor de error 
    }

    Node *top_node = s->top;  // Almacena el nodo superior de la pila
    s->top = s->top->next;     // Actualiza la parte superior de la pila
    Data d = top_node->data;  // Obtiene el dato del nodo que se va a eliminar
    delete_node(top_node);    // Libera la memoria del nodo eliminado
    return d;
}

/**
 * Vacía la pila, eliminando todos sus elementos.
 * 
 * @param s Auntador a la pila que se desea vaciar.
 * @details Esta función elimina todos los elementos de la pila, dejándola vacía.
 *          Si el puntero `s` es NULL, la función no realiza ninguna operación.
 *          La memoria de los elementos eliminados se libera adecuadamente.
 */
void stack_empty(Stack* s){
   
    Node *current = s->top;  // Apunta al primer nodo de la pila
    while (current != NULL) {  // Recorre la pila hasta que no queden elementos
        Node *next = current->next;  // Guarda el siguiente nodo
        delete_node(current);         // Libera la memoria del nodo actual
        current = next;               // Avanza al siguiente nodo
    }
    s->top = NULL;  // Al finalizar, la pila está vacía
}

/**
 * Elimina la pila y libera la memoria asociada a ella.
 * 
 * @param s Auntador a la pila que se desea eliminar.
 * @details Esta función libera la memoria asignada dinámicamente para la pila y todos sus elementos
 *          utilizando `free`. Si el puntero pasado es NULL, la función no realiza ninguna operación.
 *          Es responsabilidad del llamante asegurarse de que la pila ya no se utiliza después
 *          de ser eliminada.
 */
void stack_delete(Stack *s){
    stack_empty(s);  // Elimina todos los elementos de la pila
    free(s);  
}

/**
 * Imprime los elementos de la pila.
 * 
 * @param s Auntador a la pila que se desea imprimir.
 * @details Esta función imprime los elementos de la pila en orden, desde la parte superior
 *          hasta la base. Si la pila está vacía o el puntero `s` es NULL, la función imprime
 *          un mensaje indicando que la pila está vacía o es inválida. La salida se dirige a
 *          la salida estándar (stdout).
 */
void stack_print(Stack *s){
    if (s == NULL) {  // Verifica si la pila es NULL o está vacía
        printf("Pila vacía o inválida.\n");
        return;
    }

    Node *current = s->top;  // Apunta al primer nodo de la pila
    while (current != NULL) {  // Recorre la pila
        printf("%d ", current->data);  // Imprime el dato del nodo actual
        current = current->next;       // Avanza al siguiente nodo
    }
    printf("\n");  // Imprime una nueva línea al final
}