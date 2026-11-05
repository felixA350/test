#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

/*
 * Row-major dense matrix of doubles.
 *
 * data has rows*cols elements, laid out as:
 *   data[i * cols + j]  ->  element at row i, column j
 */
typedef struct {
    size_t  rows;
    size_t  cols;
    double *data;
} Matrix;

/* Lifecycle ------------------------------------------------------------- */

/* Allocate a rows x cols matrix. Returns NULL on failure (bad size or OOM). */
Matrix *matrix_create(size_t rows, size_t cols);

/* Free memory allocated by matrix_create. Safe to call with NULL. */
void matrix_free(Matrix *m);

/* Accessors ------------------------------------------------------------- */

/* Both return 0.0 / do nothing if the index is out of range. */
double matrix_get(const Matrix *m, size_t i, size_t j);
void   matrix_set(Matrix *m, size_t i, size_t j, double v);

/* Print to stdout in a readable form. */
void matrix_print(const Matrix *m);

/* Operations ------------------------------------------------------------ */

/*
 * All operations write into `out`, which must already be allocated
 * with the right shape. They never allocate.
 *
 * Return 0 on success, -1 on error (shape mismatch or NULL argument).
 */

/* out = a + b, requires a and b to have the same shape as out. */
int matrix_add(const Matrix *a, const Matrix *b, Matrix *out);

/* out = a * b, requires out.rows == a.rows and out.cols == b.cols,
 * and a.cols == b.rows. */
int matrix_mul(const Matrix *a, const Matrix *b, Matrix *out);

/* out = a^T, requires out.rows == a.cols and out.cols == a.rows. */
int matrix_transpose(const Matrix *a, Matrix *out);

#endif /* MATRIX_H */
