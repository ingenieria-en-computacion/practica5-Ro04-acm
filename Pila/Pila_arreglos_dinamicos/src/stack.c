#include "stack.h"

/**
 * Crea una nueva pila vacía y la devuelve.
 * 
 * @param len valor que indica cuantos elementos se pueden guardar en la pila
 * @return Una nueva pila vacía. Si la creación falla, el estado de la cola es inválido.
 * @details Esta función inicializa una pila vacía. 
 *          Asigna memoria dinámica a data mediante malloc con un número de elementos igual a len
 */
Stack stack_create(int len){
    Stack s;
    s.len=len;
    s.data=(Data*)malloc(sizeof(Data)*s.len);
    s.top=-1;
    return s;
}

/**
 * Inserta un elemento en la parte superior de la pila.
 * 
 * @param s Referencia a la pila donde se insertará el elemento.
 * @param d Dato que se insertará en la pila.
 * @details Esta función añade el dato `d` en la parte superior de la pila. Si la pila está llena, 
 *          la función no realiza ninguna operación.
 */
void stack_push(Stack* s, Data d){
    if (s->top<s->len-1)
    {
        s->top++;
        s->data(s->top)=d;
        return;
    }
    printf("La pila esta llena\n");
    
}

/**
 * Elimina y devuelve el elemento en la parte superior de la pila.
 * 
 * @param s Referencia a la pila de la cual se eliminará el elemento.
 * @return El dato que estaba en la parte superior de la pila. Si la pila está vacía 
 *         devuelve un valor que indica error (por ejemplo, -1 o un valor predeterminado).
 * @details Esta función elimina el elemento en la parte superior de la pila y lo devuelve.
 *          Si la pila está vacía, no se realiza ninguna operación y se devuelve un valor de error.
 */
Data stack_pop(Stack* s){
    if (s->top >= 0) {  // Comprobamos si la pila no está vacía
        Data top = s->data[s->top];  // Guardamos el valor que se va a eliminar
        s->top--;  // Decrementamos top para "eliminar" el elemento
        return top;  // Retornamos el dato eliminado
    } else {
        printf("La pila esta vacia\n");
        return -1;  // Indicamos que no se pudo hacer pop, ya que la pila está vacía
    }
}

/**
 * Verifica si la pila está vacía.
 * 
 * @param s Referencia a la pila que se desea verificar.
 * @return 1 si la pila está vacía, 0 si no lo está. Si el puntero `s` es NULL, devuelve -1.
 * @details Esta función comprueba si la pila no contiene elementos. Es útil para evitar operaciones
 *          como `stack_pop` en una pila vacía.
 */
int stack_is_empty(Stack* s){
    return s.top==-1;
}

/**
 * Vacía la pila, eliminando todos sus elementos.
 * 
 * @param s Referencia a la pila que se desea vaciar.
 * @details Esta función hace que top sea igual a -1
 */
void stack_empty(Stack* s){
  
    s->top = -1;
}

/**
 * Elimina data y libera la memoria asociada.
 * 
 * @param s Referencia a la pila que se desea liberar la memoria de data
 * @details Esta función libera la memoria asignada dinámicamente para data dentro de la pila
 */
void stack_delete(Stack *s){
    free(s->data);  // Liberamos la memoria asignada para los elementos de la pila
    s->data = NULL;
}

/**
 * Imprime los elementos de la pila.
 * 
 * @param s Referencia a la pila que se desea imprimir.
 * @details Esta función imprime los elementos de la pila en orden, desde la parte superior
 *          hasta la base. Si la pila está vacía la función imprime
 *          un mensaje indicando que la pila está vacía o es inválida. La salida se dirige a
 *          la salida estándar (stdout).
 */
void stack_print(Stack *s){
    if (stack_is_empty(s)) {  // Verificamos si la pila esta vacia
        printf("[]\n");  //
        return;
    }
    printf("[");
    for (int i = s->top; i >= 0; i--) {  // Recorremos la pila desde el top hacia abajo
        printf("%d", s->data[i]);  // Imprimimos cada elemento
        if (i > 0) {
            printf(", ");  // Añadimos una coma si no es el último elemento
        }
    }
    printf("]\n");  
}