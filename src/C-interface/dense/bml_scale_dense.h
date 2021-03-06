#ifndef __BML_SCALE_DENSE_H
#define __BML_SCALE_DENSE_H

#include "bml_types_dense.h"

bml_matrix_dense_t *bml_scale_dense_new(
    const double scale_factor,
    const bml_matrix_dense_t * A);

bml_matrix_dense_t *bml_scale_dense_new_single_real(
    const double scale_factor,
    const bml_matrix_dense_t * A);

bml_matrix_dense_t *bml_scale_dense_new_double_real(
    const double scale_factor,
    const bml_matrix_dense_t * A);

bml_matrix_dense_t *bml_scale_dense_new_single_complex(
    const double scale_factor,
    const bml_matrix_dense_t * A);

bml_matrix_dense_t *bml_scale_dense_new_double_complex(
    const double scale_factor,
    const bml_matrix_dense_t * A);

void bml_scale_dense(
    const double scale_factor,
    const bml_matrix_dense_t * A,
    bml_matrix_dense_t * B);

void bml_scale_dense_single_real(
    const double scale_factor,
    const bml_matrix_dense_t * A,
    bml_matrix_dense_t * B);

void bml_scale_dense_double_real(
    const double scale_factor,
    const bml_matrix_dense_t * A,
    bml_matrix_dense_t * B);

void bml_scale_dense_single_complex(
    const double scale_factor,
    const bml_matrix_dense_t * A,
    bml_matrix_dense_t * B);

void bml_scale_dense_double_complex(
    const double scale_factor,
    const bml_matrix_dense_t * A,
    bml_matrix_dense_t * B);

void bml_scale_inplace_dense(
    const double scale_factor,
    bml_matrix_dense_t * A);

void bml_scale_inplace_dense_single_real(
    const double scale_factor,
    bml_matrix_dense_t * A);

void bml_scale_inplace_dense_double_real(
    const double scale_factor,
    bml_matrix_dense_t * A);

void bml_scale_inplace_dense_single_complex(
    const double scale_factor,
    bml_matrix_dense_t * A);

void bml_scale_inplace_dense_double_complex(
    const double scale_factor,
    bml_matrix_dense_t * A);

#endif
