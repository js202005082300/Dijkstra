#include "util.h"

/**
 * Alloue la mémoire pour un type basé sur la variable fournie.
 */
void check_allocation(void* ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Erreur : problème allocation dynamique.\n");
        exit(EXIT_FAILURE); // ou exit(1)
    }
}
