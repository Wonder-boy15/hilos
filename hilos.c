#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Función que ejecutará el hilo secundario
void* contar_descendente(void* arg) {
    for (int i = 10000; i >= 1; i--) {
        printf("[Hilo Secundario] %d\n", i);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t hilo;

    // Crear el hilo secundario que ejecutará contar_descendente
    if (pthread_create(&hilo, NULL, contar_descendente, NULL) != 0) {
        perror("Error al crear el hilo");
        return 1;
    }

    // El hilo principal (proceso) imprime de 1 a 10,000
    for (int i = 1; i <= 10000; i++) {
        printf("[Hilo Principal]  %d\n", i);
    }

    // Esperar a que el hilo secundario termine su ejecución
    pthread_join(hilo, NULL);

    return 0;
}