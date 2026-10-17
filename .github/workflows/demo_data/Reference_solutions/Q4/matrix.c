#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix* create_matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) return NULL;
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    if (!m) return NULL;
    m->rows = rows;
    m->cols = cols;
    m->data = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        m->data[i] = (int *)malloc(sizeof(int) * cols);
    }
    return m;
}

void free_matrix(Matrix *m) {
    if (!m) return;
    if (m->data) {
        for (int i = 0; i < m->rows; i++) {
            free(m->data[i]);
        }
        free(m->data);
    }
    free(m);
}

Matrix* add_matrices(const Matrix *a, const Matrix *b) {
    if (!a || !b) return NULL;
    if (a->rows != b->rows || a->cols != b->cols) return NULL;
    Matrix *res = create_matrix(a->rows, a->cols);
    if (!res) return NULL;
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            res->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return res;
}

Matrix* multiply_matrices(const Matrix *a, const Matrix *b) {
    if (!a || !b) return NULL;
    if (a->cols != b->rows) return NULL;
    Matrix *res = create_matrix(a->rows, b->cols);
    if (!res) return NULL;
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            res->data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                res->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return res;
}

void print_matrix(const Matrix *m) {
    if (!m) return;
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d%s", m->data[i][j], (j == m->cols - 1) ? "" : " ");
        }
        printf("\n");
    }
}
