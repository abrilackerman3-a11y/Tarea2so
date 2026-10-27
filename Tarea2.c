#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* tarea_hilo(void* arg) {
    for (int i = 10000; i >= 1; i--) {
        printf("Hilo secundario: %d\n", i);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t hilo_secundario;

    if (pthread_create(&hilo_secundario, NULL, tarea_hilo, NULL) != 0) {
        perror("Error al crear el hilo");
        return 1;
    }

    for (int i = 1; i <= 10000; i++) {
        printf("Proceso principal: %d\n", i);
    }

    pthread_join(hilo_secundario, NULL);

    printf("\n¡Ejecución de hilos finalizada con éxito!\n");
    return 0;
}