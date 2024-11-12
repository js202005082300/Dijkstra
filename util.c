#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void checkAllocation(void* ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Erreur : problème allocation dynamique.\n");
        exit(EXIT_FAILURE); // ou exit(1)
    }
}
