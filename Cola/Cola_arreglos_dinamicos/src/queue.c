#include "queue.h"
#include <stdlib.h>

/**
 * Crea una nueva cola vacía y la devuelve.
 * 
 * @param len cantidad de datos que se pueden guardar en el arreglo para la cola
 * @return Una nueva cola vacía. Si la creación falla, el estado de la cola es inválido.
 * @details Esta función inicializa una cola vacía. Asigna memoria dinàmica con malloc al arreglo data usando len
 */
Queue queue_create(int len){
    Queue q;
    q.data = (Data*)malloc(len * sizeof(Data)); // Asignamos la memoria 
    q.head = 0;   // El índice de inicio se pone en 0.
    q.tail = q.head;  // Al no haber datos apuntan a lo mismo
    q.len = len;  // La longitud máxima de la cola.
    return q;     // Devuelve la cola inicializada.
}

/**
 * Inserta un elemento al final de la cola.
 * 
 * @param q Referencia a la cola donde se insertará el elemento.
 * @param d Dato que se insertará en la cola.
 * @details Esta función añade el dato `d` al final de la cola.
 */
void queue_enqueue(Queue* q, Data d){
    if (q->tail < q->len - 1) {  // Verifica que haya espacio en la cola
        q->tail++;               // Incrementa el índice final.
        q->data[q->tail] = d;    // Inserta el dato al final de la cola.
    }
}

/**
 * Elimina y devuelve el elemento al frente de la cola.
 * 
 * @param q Referencia a la cola de la cual se eliminará el elemento.
 * @return El dato que estaba al frente de la cola. Si la cola está vacía o el puntero
 *         `q` es NULL, devuelve un valor que indica error (por ejemplo, un valor predeterminado).
 * @details Esta función elimina el elemento al frente de la cola y lo devuelve.
 *          Si la cola está vacía, no se realiza ninguna operación y se devuelve un valor de error.
 */
Data queue_dequeue(Queue* q){
    if (queue_is_empty(q)) {      // Si la cola esta vacia devuelve un error
        return -1;                
    }
    Data front = q->data[q->head]; // Guarda el elemento al frente.
        q->head++;                     // Mueve hacia enfrente.
        if (q->head > q->tail) {      
        q->head = 0;
        q->tail = -1;
        }
    return front; 
}

/**
 * Verifica si la cola está vacía.
 * 
 * @param q Referencia a la cola que se desea verificar.
 * @return `true` si la cola está vacía, `false` si no lo está. 
 * @details Esta función comprueba si la cola no contiene elementos. Es útil para evitar operaciones
 *          como `queue_dequeue` en una cola vacía.
 */
bool queue_is_empty(Queue* q){
    return q->tail == -1;
}

/**
 * Obtiene el elemento al frente de la cola sin eliminarlo.
 * 
 * @param q Referencia a la cola de la cual se desea obtener el elemento.
 * @return El dato que está al frente de la cola. Si la cola está vacía , devuelve un valor que indica error (por ejemplo, un valor predeterminado).
 * @details Esta función devuelve el elemento al frente de la cola sin modificarla.
 *          Si la cola está vacía, no se realiza ninguna operación y se devuelve un valor de error.
 */
Data queue_front(Queue* q){
    if (queue_is_empty(q)) {
        return -1;  // Valor de error si esta vacia 
    }
    return q->data[q->head];  //lo que usamos al guardar el elemento al frente
}

/**
 * Vacía la cola, eliminando todos sus elementos.
 * 
 * @param q Referemcoa a la cola que se desea vaciar.
 * @details Esta función hace que los índices head y tail tomen el valor de -1
 */
void queue_empty(Queue* q){
    q->head = 0;   // El índice de inicio se pone en 0.
    q->tail = q->head;  // Al no haber datos apuntan a lo mismo
}

/**
 * Elimina la cola y libera la memoria asociada a ella.
 * 
 * @param q Referencia a la cola que se desea eliminar.
 * @details Esta función libera la memoria asignada dinámicamente para datos
 *          utilizando `free`. Es responsabilidad del llamante asegurarse de que la cola ya no se utiliza después
 *          de ser eliminada.
 */
void queue_delete(Queue* q){
    free(q->data);  // Libera la memoria 
    q->data = NULL; // Pone el puntero a NULL para evitar uso accidental.
}