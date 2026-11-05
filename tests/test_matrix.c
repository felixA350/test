/*
 * Minimal test harness: no external dependencies.
 * Build with:  make test
 */
#include "matrix.h"

#include <math.h>
#include <stdio.h>

static int g_checks = 0;
static int g_failed = 0;

static void check(int cond, const char *what)
{
    g_checks++;
    if (!cond) {
        g_failed++;
        printf("  FAIL  %s\n", what);
    }
}

#define CHECK(cond) check((cond), #cond)

int main(void)
{
    printf("running tests\n");

    /* ---- create / get / set ---- */
    Matrix *a = matrix_create(2, 3);
    CHECK(a != NULL);
    if (a == NULL) {
        return 1;
    }
    matrix_set(a, 0, 0, 1.0);
    matrix_set(a, 0, 1, 2.0);
    matrix_set(a, 0, 2, 3.0);
    matrix_set(a, 1, 0, 4.0);
    matrix_set(a, 1, 1, 5.0);
    matrix_set(a, 1, 2, 6.0);
    CHECK(matrix_get(a, 0, 0) == 1.0);
    CHECK(matrix_get(a, 1, 2) == 6.0);
    CHECK(matrix_get(a, 9, 9) == 0.0); /* out of range is safe */

    /* ---- add ---- */
    Matrix *b = matrix_create(2, 3);
    Matrix *s = matrix_create(2, 3);
    matrix_set(b, 0, 0, 10.0);
    matrix_set(b, 1, 2, 20.0);
    CHECK(matrix_add(a, b, s) == 0);
    CHECK(matrix_get(s, 0, 0) == 11.0);
    CHECK(matrix_get(s, 1, 2) == 26.0);
    CHECK(matrix_get(s, 0, 1) == 2.0);

    /* ---- transpose ---- */
    Matrix *t = matrix_create(3, 2);
    CHECK(matrix_transpose(a, t) == 0);
    CHECK(matrix_get(t, 0, 0) == 1.0);
    CHECK(matrix_get(t, 0, 1) == 4.0);
    CHECK(matrix_get(t, 2, 1) == 6.0);

    /* ---- multiply: (2x3) * (3x2) -> (2x2) ---- */
    Matrix *c = matrix_create(3, 2);
    matrix_set(c, 0, 0, 1.0); matrix_set(c, 0, 1, 2.0);
    matrix_set(c, 1, 0, 3.0); matrix_set(c, 1, 1, 4.0);
    matrix_set(c, 2, 0, 5.0); matrix_set(c, 2, 1, 6.0);
    Matrix *p = matrix_create(2, 2);
    CHECK(matrix_mul(a, c, p) == 0);
    /* a = [1 2 3; 4 5 6], c = [1 2; 3 4; 5 6]
       -> [22 28; 49 64] */
    CHECK(matrix_get(p, 0, 0) == 22.0);
    CHECK(matrix_get(p, 0, 1) == 28.0);
    CHECK(matrix_get(p, 1, 0) == 49.0);
    CHECK(matrix_get(p, 1, 1) == 64.0);

    /* ---- shape mismatches must be rejected ---- */
    Matrix *bad = matrix_create(3, 3);
    CHECK(matrix_add(a, a, bad) == -1);      /* out has wrong shape */
    CHECK(matrix_mul(a, a, p) == -1);        /* a.cols != a.rows     */

    matrix_free(a); matrix_free(b); matrix_free(s);
    matrix_free(t); matrix_free(c); matrix_free(p); matrix_free(bad);

    printf("\n%d checks, %d failed\n", g_checks, g_failed);
    return g_failed == 0 ? 0 : 1;
}
