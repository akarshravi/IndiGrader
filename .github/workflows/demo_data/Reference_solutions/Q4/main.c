#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

Matrix* read_matrix() {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2) return NULL;
    Matrix *m = create_matrix(r, c);
    if (!m) return NULL;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (scanf("%d", &m->data[i][j]) != 1) {
                free_matrix(m);
                return NULL;
            }
        }
    }
    return m;
}

int main() {
    char op[16];
    if (scanf("%15s", op) != 1) {
        printf("ERROR\n");
        return 0;
    }

    Matrix *a = read_matrix();
    Matrix *b = read_matrix();

    if (!a || !b) {
        printf("ERROR\n");
        free_matrix(a);
        free_matrix(b);
        return 0;
    }

    Matrix *res = NULL;
    if (strcmp(op, "ADD") == 0) {
        res = add_matrices(a, b);
    } else if (strcmp(op, "MUL") == 0) {
        res = multiply_matrices(a, b);
    }

    if (res) {
        print_matrix(res);
        free_matrix(res);
    } else {
        printf("ERROR\n");
    }

    free_matrix(a);
    free_matrix(b);
    return 0;
}
