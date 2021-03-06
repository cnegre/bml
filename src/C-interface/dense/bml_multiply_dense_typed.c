#include "../blas.h"
#include "../bml_logger.h"
#include "../typed.h"
#include "bml_multiply.h"
#include "bml_multiply_dense.h"
#include "bml_types.h"
#include "bml_types_dense.h"

#include <stdlib.h>
#include <string.h>

#define FUNC_STRING_2(a) #a
#define FUNC_STRING(a) FUNC_STRING_2(a)

/** Matrix multiply.
 *
 * \f$ C \leftarrow \alpha \, A \, B + \beta C \f$
 *
 * \ingroup multiply_group
 *
 * \param A Matrix A
 * \param B Matrix B
 * \param C Matrix C
 * \param alpha Scalar factor multiplied by A * B
 * \param beta Scalar factor multiplied by C
 */
void TYPED_FUNC(
    bml_multiply_dense) (
    const bml_matrix_dense_t * A,
    const bml_matrix_dense_t * B,
    bml_matrix_dense_t * C,
    const double alpha,
    const double beta)
{
    REAL_T alpha_ = (REAL_T) alpha;
    REAL_T beta_ = (REAL_T) beta;
    /* LOG_DEBUG("entering " FUNC_STRING(TYPED_FUNC(bml_multiply_dense)) "()\n"); */
    /* bml_print_dense_matrix(A->N, MATRIX_PRECISION, dense_row_major, A->matrix, 0, A->N, 0, A->N); */
    /* bml_print_dense_matrix(B->N, MATRIX_PRECISION, dense_row_major, B->matrix, 0, B->N, 0, B->N); */
    /* bml_print_dense_matrix(C->N, MATRIX_PRECISION, dense_row_major, C->matrix, 0, C->N, 0, C->N); */
    /* LOG_DEBUG("calling " FUNC_STRING(C_BLAS(GEMM)) "()\n"); */
    C_BLAS(GEMM) ("N", "N", &A->N, &A->N, &A->N, &alpha_, B->matrix,
                  &A->N, A->matrix, &A->N, &beta_, C->matrix, &A->N);
    /* bml_print_dense_matrix(C->N, MATRIX_PRECISION, dense_row_major, C->matrix, 0, C->N, 0, C->N); */
}

/** Matrix multiply.
 *
 * X2 = X * X
 *
 *  \ingroup multiply_group
 *
 *  \param X Matrix X
 *  \param X2 MatrixX2
 */
void TYPED_FUNC(
    bml_multiply_x2_dense) (
    const bml_matrix_dense_t * X,
    bml_matrix_dense_t * X2)
{
    TYPED_FUNC(bml_multiply_dense) (X, X, X2, 1.0, 0.0);
}

/** Matrix multiply.
 *
 * \f$ C \leftarrow A \, B \f$
 *
 * \ingroup multiply_group
 *
 * \param A Matrix A
 * \param B Matrix B
 * \param C Matrix C
 */
void TYPED_FUNC(
    bml_multiply_AB_dense) (
    const bml_matrix_dense_t * A,
    const bml_matrix_dense_t * B,
    bml_matrix_dense_t * C)
{
    TYPED_FUNC(bml_multiply_dense) (A, B, C, 1.0, 0.0);
}

/** Matrix multiply.
 *
 * This routine is provided for completeness.
 *
 * C = A * B
 *
 *  \ingroup multiply_group
 *
 *  \param A Matrix A
 *  \param B Matrix B
 *  \param C Matrix C
 */
void TYPED_FUNC(
    bml_multiply_adjust_AB_dense) (
    const bml_matrix_dense_t * A,
    const bml_matrix_dense_t * B,
    bml_matrix_dense_t * C)
{
    REAL_T alpha = (REAL_T) 1.0;
    REAL_T beta = (REAL_T) 0.0;
    C_BLAS(GEMM) ("T", "T", &A->N, &A->N, &A->N, &alpha, A->matrix,
                  &A->N, B->matrix, &A->N, &beta, C->matrix, &A->N);
}
