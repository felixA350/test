# Matrix Library (C)

A small dense matrix library written in C, built as my first real project.

The point is not the feature list. The point is to learn, by building it:

- how a 2D matrix is actually stored in memory (row-major, one flat array)
- how to split a small program into multiple files and build it with `make`
- how to write tests that fail first and pass later
- why iteration order matters for cache performance (see the roadmap below)

## Build

```bash
make
```

## Run the tests

```bash
make test
```

## Run the demo

```bash
make run
```

## Project layout

```
include/matrix.h      public API
src/matrix.c          implementation
tests/test_matrix.c   test harness (no dependencies)
examples/demo.c       small demo program
Makefile              build rules
```

## Roadmap

- [x] Project skeleton: header, build, test harness
- [ ] `matrix_add`
- [ ] `matrix_transpose`
- [ ] `matrix_mul` (naive triple loop)
- [ ] `matrix_mul` blocked / transposed variant, and benchmark both

## What I learned

<!-- Fill this in as you go. Recruiters read this section. -->
