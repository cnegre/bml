#include "bml.h"
#include "bml_test.h"

#include <complex.h>
#include <math.h>
#include <stdlib.h>

int
test_function(
    const int N,
    const bml_matrix_type_t matrix_type,
    const bml_matrix_precision_t matrix_precision,
    const int M)
{
    bml_matrix_t *A = NULL;
    bml_matrix_t *B = NULL;
    bml_matrix_t *C = NULL;

    REAL_T *A_dense = NULL;
    REAL_T *B_dense = NULL;
    REAL_T *C_dense = NULL;

    double alpha_factor = 1.0;
    double beta_factor = 1.0;
    double threshold = 0.0;

    A = bml_random_matrix(matrix_type, matrix_precision, N, M);
    C = bml_copy_new(A);
    B = bml_identity_matrix(matrix_type, matrix_precision, N, M);
    bml_add(A, B, alpha_factor, beta_factor, threshold);
    bml_add_identity(C, beta_factor, threshold);

    A_dense = bml_convert_to_dense(A);
    B_dense = bml_convert_to_dense(B);
    C_dense = bml_convert_to_dense(C);
    bml_print_dense_matrix(N, matrix_precision, A_dense, 0, N, 0, N);
    bml_print_dense_matrix(N, matrix_precision, B_dense, 0, N, 0, N);
    bml_print_dense_matrix(N, matrix_precision, C_dense, 0, N, 0, N);
    for (int i = 0; i < N * N; i++)
    {
        if (fabs(A_dense[i] - C_dense[i]) > 1e-12)
        {
            LOG_ERROR
                ("matrices are not identical; A[%d] = %e C[%d] = %e\n",
                 i, A_dense[i], i, C_dense[i]);
            return -1;
        }
    }
    bml_free_memory(A_dense);
    bml_free_memory(B_dense);
    bml_free_memory(C_dense);

    bml_deallocate(&A);
    bml_deallocate(&B);
    bml_deallocate(&C);

    LOG_INFO("add matrix test passed\n");

    return 0;
}
