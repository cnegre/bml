#ifndef __BML_MULTIPLY_DENSE_H
#define __BML_MULTIPLY_DENSE_H

#include "bml_types_dense.h"

// Matrix multiply - C = alpha * A * B + beta * C
void bml_multiply_dense(
    const bml_matrix_dense_t * A,
    const bml_matrix_dense_t * B,
    bml_matrix_dense_t * C,
    const double alpha,
    const double beta);

void bml_multiply_dense_single_real(
    const bml_matrix_dense_t * A,
    const bml_matrix_dense_t * B,
    bml_matrix_dense_t * C,
    const double alpha,
    const double beta);

void bml_multiply_dense_double_real(
    const bml_matrix_dense_t * A,
    const bml_matrix_dense_t * B,
    bml_matrix_dense_t * C,
    const double alpha,
    const double beta);

void bml_multiply_dense_single_complex(
    const bml_matrix_dense_t * A,
    const bml_matrix_dense_t * B,
    bml_matrix_dense_t * C,
    const double alpha,
    const double beta);

void bml_multiply_dense_double_complex(
    const bml_matrix_dense_t * A,
    const bml_matrix_dense_t * B,
    bml_matrix_dense_t * C,
    const double alpha,
    const double beta);

void bml_multiply_x2_dense(
    const bml_matrix_dense_t * X,
    bml_matrix_dense_t * X2);

void bml_multiply_x2_dense_single_real(
    const bml_matrix_dense_t * X,
    bml_matrix_dense_t * X2);

void bml_multiply_x2_dense_double_real(
    const bml_matrix_dense_t * X,
    bml_matrix_dense_t * X2);

void bml_multiply_x2_dense_single_complex(
    const bml_matrix_dense_t * X,
    bml_matrix_dense_t * X2);

void bml_multiply_x2_dense_double_complex(
    const bml_matrix_dense_t * X,
    bml_matrix_dense_t * X2);

void bml_multiply_AB_dense(
    const bml_matrix_dense_t * A,
    const bml_matrix_dense_t * B,
    bml_matrix_dense_t * C);

void bml_multiply_AB_dense_single_real(
    const bml_matrix_dense_t * A,
    const bml_matrix_dense_t * B,
    bml_matrix_dense_t * C);

void bml_multiply_AB_dense_double_real(
    const bml_matrix_dense_t * A,
    const bml_matrix_dense_t * B,
    bml_matrix_dense_t * C);

void bml_multiply_AB_dense_single_complex(
    const bml_matrix_dense_t * A,
    const bml_matrix_dense_t * B,
    bml_matrix_dense_t * C);

void bml_multiply_AB_dense_double_complex(
    const bml_matrix_dense_t * A,
    const bml_matrix_dense_t * B,
    bml_matrix_dense_t * C);

void bml_multiply_adjust_AB_dense(
    const bml_matrix_dense_t * A,
    const bml_matrix_dense_t * B,
    bml_matrix_dense_t * C);

void bml_multiply_adjust_AB_dense_single_real(
    const bml_matrix_dense_t * A,
    const bml_matrix_dense_t * B,
    bml_matrix_dense_t * C);

void bml_multiply_adjust_AB_dense_double_real(
    const bml_matrix_dense_t * A,
    const bml_matrix_dense_t * B,
    bml_matrix_dense_t * C);

void bml_multiply_adjust_AB_dense_single_complex(
    const bml_matrix_dense_t * A,
    const bml_matrix_dense_t * B,
    bml_matrix_dense_t * C);

void bml_multiply_adjust_AB_dense_double_complex(
    const bml_matrix_dense_t * A,
    const bml_matrix_dense_t * B,
    bml_matrix_dense_t * C);

#endif
