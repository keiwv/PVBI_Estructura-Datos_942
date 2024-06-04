#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

// Definición de una estructura para un nodo en la tabla hash
typedef struct Node {
    char key[256];
    char value[256];
    struct Node* next;
} Node;

// Tabla hash
Node* hashTable[TABLE_SIZE];

// Función hash simple
unsigned int hash(const char* key) {
    unsigned int hashValue = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hashValue = hashValue * 37 + key[i];
    }
    return hashValue % TABLE_SIZE;
}

// Insertar un nuevo elemento en la tabla hash
void insert(const char* key, const char* value) {
    unsigned int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Buscar un elemento en la tabla hash
Node* search(const char* key) {
    unsigned int index = hash(key);
    Node* current = hashTable[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Eliminar un elemento de la tabla hash
void delete(const char* key) {
    unsigned int index = hash(key);
    Node* current = hashTable[index];
    Node* previous = NULL;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (previous == NULL) {
                hashTable[index] = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Actualizar un elemento en la tabla hash
void update(const char* key, const char* newValue) {
    Node* node = search(key);
    if (node != NULL) {
        strcpy(node->value, newValue);
    }
}

// Listar todos los elementos de la tabla hash
void list() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            printf("Clave: %s, Valor: %s\n", current->key, current->value);
            current = current->next;
        }
    }
}

// Mostrar el menú
void menu() {
    int choice;
    char key[256];
    char value[256];

    do {
        printf("Menú:\n");
        printf("1. Insertar un nuevo elemento\n");
        printf("2. Buscar un elemento\n");
        printf("3. Eliminar un elemento\n");
        printf("4. Actualizar un elemento\n");
        printf("5. Listado de la tabla Hash\n");
        printf("6. Salir\n");
        printf("Ingrese su elección: ");
        scanf("%d", &choice);
        getchar(); // Limpiar el buffer

        switch (choice) {
            case 1:
                printf("Ingrese la clave: ");
                fgets(key, 256, stdin);
                key[strcspn(key, "\n")] = '\0'; // Eliminar el salto de línea
                printf("Ingrese el valor: ");
                fgets(value, 256, stdin);
                value[strcspn(value, "\n")] = '\0'; // Eliminar el salto de línea
                insert(key, value);
                break;
            case 2:
                printf("Ingrese la clave para buscar: ");
                fgets(key, 256, stdin);
                key[strcspn(key, "\n")] = '\0';
                Node* node = search(key);
                if (node != NULL) {
                    printf("Valor encontrado: %s\n", node->value);
                } else {
                    printf("Elemento no encontrado\n");
                }
                break;
            case 3:
                printf("Ingrese la clave para eliminar: ");
                fgets(key, 256, stdin);
                key[strcspn(key, "\n")] = '\0';
                delete(key);
                break;
            case 4:
                printf("Ingrese la clave para actualizar: ");
                fgets(key, 256, stdin);
                key[strcspn(key, "\n")] = '\0';
                printf("Ingrese el nuevo valor: ");
                fgets(value, 256, stdin);
                value[strcspn(value, "\n")] = '\0';
                update(key, value);
                break;
            case 5:
                list();
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
                break;
        }
    } while (choice != 6);
}

int main() {
    // Inicializar la tabla hash
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Ejecutar el menú
    menu();

    return 0;
}
