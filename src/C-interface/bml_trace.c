#include "bml_trace.h"
#include "bml_introspection.h"
#include "bml_logger.h"
#include "dense/bml_trace_dense.h"
#include "ellpack/bml_trace_ellpack.h"

#include <stdlib.h>

/** Calculate trace of a matrix.
 *
 * \ingroup trace_group_C
 *
 * \param A Matrix tocalculate trace for
 * \return  Trace of A
 */
double
bml_trace(
    const bml_matrix_t * A)
{
    switch (bml_get_type(A))
    {
        case dense:
            return bml_trace_dense(A);
            break;
        case ellpack:
            return bml_trace_ellpack(A);
            break;
        default:
            LOG_ERROR("unknown matrix type\n");
            break;
    }
    return 0;
}
