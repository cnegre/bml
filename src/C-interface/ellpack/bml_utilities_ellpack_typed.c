#include "../macros.h"
#include "../typed.h"
#include "../bml_types.h"
#include "../bml_logger.h"
#include "../bml_utilities.h"
#include "bml_types_ellpack.h"
#include "bml_utilities_ellpack.h"

#include <complex.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/** Read in a bml matrix from Matrix Market format.
 *
 *  \ingroup utilities_group
 *
 *  \param A The matrix to be read
 *  \param filename The Matrix Market format file
 */
void TYPED_FUNC(
    bml_read_bml_matrix_ellpack) (
    const bml_matrix_ellpack_t * A,
    const char *filename)
{
    FILE *hFile;
    char header1[20], header2[20], header3[20], header4[20], header5[20];
    int hdimx, nnz, irow, icol, ind;
    REAL_T val;

    int N = A->N;
    int M = A->M;
    REAL_T *A_value = (REAL_T *) A->value;
    int *A_index = A->index;
    int *A_nnz = A->nnz;

    hFile = fopen(filename, "r");

    // Read header
    fscanf(hFile, "%s %s %s %s %s", header1, header2, header3, header4,
           header5);

    // Read N, N, # of non-zeroes
    fscanf(hFile, "%d %d %d", &hdimx, &hdimx, &nnz);

    char *FMT;
    switch (A->matrix_precision)
    {
        case single_real:
            FMT = "%d %d %g\n";
            break;
        case double_real:
            FMT = "%d %d %lg\n";
            break;
        case single_complex:
            FMT = "%d %d %g\n";
            break;
        case double_complex:
            FMT = "%d %d %lg\n";
            break;
        default:
            LOG_ERROR("unknown precision\n");
            break;
    }

    // Read in values
    for (int i = 0; i < nnz; i++)
    {
        fscanf(hFile, FMT, &irow, &icol, &val);
        irow--;
        icol--;
        ind = A_nnz[irow];
        A_index[ROWMAJOR(irow, ind, M, N)] = icol;
        A_value[ROWMAJOR(irow, ind, M, N)] = val;
        A_nnz[irow]++;
    }

    fclose(hFile);
}

/** Write a Matrix Market format file from a bml matrix.
 *
 *  \ingroup utilities_group
 *
 *  \param A The matrix to be written
 *  \param filename The Matrix Market format file
 */
void TYPED_FUNC(
    bml_write_bml_matrix_ellpack) (
    const bml_matrix_ellpack_t * A,
    const char *filename)
{
    FILE *mFile;
    int msum;

    int N = A->N;
    int M = A->M;

    REAL_T *A_value = (REAL_T *) A->value;
    int *A_index = A->index;
    int *A_nnz = A->nnz;

    mFile = fopen(filename, "w");

    // Write header
    fprintf(mFile, "%%%%%%MatrixMarket matrix coordinate real general\n");

    // Collect number of non-zero elements
    // Write out matrix size as dense and number of non-zero elements
    msum = 0;
    for (int i = 0; i < N; i++)
    {
        msum += A_nnz[i];
    }
    fprintf(mFile, "%d %d %d\n", N, N, msum);

    // Write out non-zero elements
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < A_nnz[i]; j++)
        {
            fprintf(mFile, "%d %d %20.15e\n", i + 1,
                    A_index[ROWMAJOR(i, j, M, N)] + 1,
                    REAL_PART(A_value[ROWMAJOR(i, j, M, N)]));
        }
    }

    fclose(mFile);
}
