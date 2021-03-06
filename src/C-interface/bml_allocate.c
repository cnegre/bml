#include "bml_allocate.h"
#include "bml_introspection.h"
#include "bml_logger.h"
#include "dense/bml_allocate_dense.h"
#include "ellpack/bml_allocate_ellpack.h"

#include <stdlib.h>

/** Allocate and zero a chunk of memory.
 *
 * \ingroup allocate_group_C
 *
 * \param size The size of the memory.
 * \return A pointer to the allocated chunk.
 */
void *
bml_allocate_memory(
    const size_t size)
{
    void *ptr = calloc(1, size);
    if (ptr == NULL)
    {
        LOG_ERROR("error allocating memory\n");
    }
    return ptr;
}

/** Deallocate a chunk of memory.
 *
 * \ingroup allocate_group_C
 *
 * \param ptr A pointer to the previously allocated chunk.
 */
void
bml_free_memory(
    void *ptr)
{
    free(ptr);
}

/** Deallocate a matrix.
 *
 * \ingroup allocate_group_C
 *
 * \param A The matrix.
 */
void
bml_deallocate(
    bml_matrix_t ** A)
{
    if (A == NULL)
    {
        LOG_DEBUG("A is NULL\n");
    }
    else if (*A == NULL)
    {
        LOG_DEBUG("*A is NULL\n");
    }
    else
    {
        switch (bml_get_type(*A))
        {
            case dense:
                bml_deallocate_dense(*A);
                break;
            case ellpack:
                bml_deallocate_ellpack(*A);
                break;
            default:
                LOG_ERROR("unknown matrix type (%d)\n", bml_get_type(*A));
                break;
        }
        *A = NULL;
    }
}

/** Allocate the zero matrix.
 *
 *  Note that the matrix \f$ A \f$ will be newly allocated. The
 *  function does not check whether the matrix is already allocated.
 *
 *  \ingroup allocate_group_C
 *
 *  \param matrix_type The matrix type.
 *  \param matrix_precision The precision of the matrix.
 *  \param N The matrix size.
 *  \param M The number of non-zeroes per row.
 *  \return The matrix.
 */
bml_matrix_t *
bml_zero_matrix(
    const bml_matrix_type_t matrix_type,
    const bml_matrix_precision_t matrix_precision,
    const int N,
    const int M)
{
    LOG_DEBUG("zero matrix of size %d\n", N);
    switch (matrix_type)
    {
        case dense:
            return bml_zero_matrix_dense(matrix_precision, N);
            break;
        case ellpack:
            return bml_zero_matrix_ellpack(matrix_precision, N, M);
            break;
        default:
            LOG_ERROR("unknown matrix type\n");
            break;
    }
    return NULL;
}

/** Allocate a random matrix.
 *
 *  Note that the matrix \f$ A \f$ will be newly allocated. The
 *  function does not check whether the matrix is already allocated.
 *
 *  \ingroup allocate_group_C
 *
 *  \param matrix_type The matrix type.
 *  \param matrix_precision The precision of the matrix.
 *  \param N The matrix size.
 *  \param M The number of non-zeroes per row.
 *  \return The matrix.
 */
bml_matrix_t *
bml_random_matrix(
    const bml_matrix_type_t matrix_type,
    const bml_matrix_precision_t matrix_precision,
    const int N,
    const int M)
{
    LOG_DEBUG("random matrix of size %d\n", N);
    switch (matrix_type)
    {
        case dense:
            return bml_random_matrix_dense(matrix_precision, N);
            break;
        case ellpack:
            return bml_random_matrix_ellpack(matrix_precision, N, M);
            break;
        default:
            LOG_ERROR("unknown matrix type (type ID %d)\n", matrix_type);
            break;
    }
    return NULL;
}

/** Allocate a banded matrix.
 *
 *  Note that the matrix \f$ A \f$ will be newly allocated. The
 *  function does not check whether the matrix is already allocated.
 *
 *  \ingroup allocate_group_C
 *
 *  \param matrix_type The matrix type.
 *  \param matrix_precision The precision of the matrix.
 *  \param N The matrix size.
 *  \param M The bandwidth of the matrix.
 *  \return The matrix.
 */
bml_matrix_t *
bml_banded_matrix(
    const bml_matrix_type_t matrix_type,
    const bml_matrix_precision_t matrix_precision,
    const int N,
    const int M)
{
    LOG_DEBUG("banded matrix of size %d\n", N);
    switch (matrix_type)
    {
        case dense:
            return bml_banded_matrix_dense(matrix_precision, N, M);
            break;
        case ellpack:
            return bml_banded_matrix_ellpack(matrix_precision, N, M);
            break;
        default:
            LOG_ERROR("unknown matrix type (type ID %d)\n", matrix_type);
            break;
    }
    return NULL;
}

/** Allocate the identity matrix.
 *
 *  Note that the matrix \f$ A \f$ will be newly allocated. The
 *  function does not check whether the matrix is already allocated.
 *
 *  \ingroup allocate_group_C
 *
 *  \param matrix_type The matrix type.
 *  \param matrix_precision The precision of the matrix.
 *  \param N The matrix size.
 *  \param M The number of non-zeroes per row.
 *  \return The matrix.
 */
bml_matrix_t *
bml_identity_matrix(
    const bml_matrix_type_t matrix_type,
    const bml_matrix_precision_t matrix_precision,
    const int N,
    const int M)
{
    LOG_DEBUG("identity matrix of size %d\n", N);
    switch (matrix_type)
    {
        case dense:
            return bml_identity_matrix_dense(matrix_precision, N);
            break;
        case ellpack:
            return bml_identity_matrix_ellpack(matrix_precision, N, M);
            break;
        default:
            LOG_ERROR("unknown matrix type (type ID %d)\n", matrix_type);
            break;
    }
    return NULL;
}
