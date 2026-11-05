#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

Matrix *matrix_create(size_t rows, size_t cols)
{
    if (rows == 0 || cols == 0) {
        return NULL;
    }
    Matrix *m = malloc(sizeof(*m));
    if (m == NULL) {
        return NULL;
    }
    m->data = calloc(rows * cols, sizeof(double));
    if (m->data == NULL) {
        free(m);
        return NULL;
    }
    m->rows = rows;
    m->cols = cols;
    return m;
}

void matrix_free(Matrix *m)
{
    if (m == NULL) {
        return;
    }
    free(m->data);
    free(m);
}

double matrix_get(const Matrix *m, size_t i, size_t j)
{
    if (m == NULL || i >= m->rows || j >= m->cols) {
        return 0.0;
    }
    return m->data[i * m->cols + j];
}

void matrix_set(Matrix *m, size_t i, size_t j, double v)
{
    if (m == NULL || i >= m->rows || j >= m->cols) {
        return;
    }
    m->data[i * m->cols + j] = v;
}

void matrix_print(const Matrix *m)
{
    if (m == NULL) {
        printf("(null matrix)\n");
        return;
    }
    for (size_t i = 0; i < m->rows; ++i) {
        for (size_t j = 0; j < m->cols; ++j) {
            printf("%8.2f ", matrix_get(m, i, j));
        }
        printf("\n");
    }
}

/* ---------------------------------------------------------------------- */
/* TODO: implement the three functions below.                             */
/* Read the comments in include/matrix.h for the exact contract.          */
/* ---------------------------------------------------------------------- */

int matrix_add(const Matrix *a, const Matrix *b, Matrix *out)
{
    (void)a;
    (void)b;
    (void)out;
    return -1; /* TODO */
}

int matrix_mul(const Matrix *a, const Matrix *b, Matrix *out)
{
    (void)a;
    (void)b;
    (void)out;
    return -1; /* TODO */
}

int matrix_transpose(const Matrix *a, Matrix *out)
{
    (void)a;
    (void)out;
    return -1; /* TODO */
}
