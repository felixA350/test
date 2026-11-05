#include "matrix.h"

#include <stdio.h>

static Matrix *make(size_t r, size_t c, const double *v)
{
    Matrix *m = matrix_create(r, c);
    if (m == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < r * c; ++i) {
        m->data[i] = v[i];
    }
    return m;
}

int main(void)
{
    const double av[] = {1, 2, 3, 4, 5, 6};
    const double cv[] = {1, 2, 3, 4, 5, 6};

    Matrix *a = make(2, 3, av);
    Matrix *c = make(3, 2, cv);
    Matrix *p = matrix_create(2, 2);

    if (a == NULL || c == NULL || p == NULL) {
        printf("allocation failed\n");
        return 1;
    }

    printf("A =\n");
    matrix_print(a);
    printf("C =\n");
    matrix_print(c);

    if (matrix_mul(a, c, p) == 0) {
        printf("A * C =\n");
        matrix_print(p);
    } else {
        printf("matrix_mul not implemented yet\n");
    }

    matrix_free(a);
    matrix_free(c);
    matrix_free(p);
    return 0;
}
