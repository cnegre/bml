!> The basic bml types.
module bml_types_m

  use, intrinsic :: iso_C_binding

  !> The bml vector type.
  type :: bml_vector_t
     !> The C pointer to the vector.
     type(C_PTR) :: ptr = C_NULL_PTR
  end type bml_vector_t

  !> The bml matrix type.
  type :: bml_matrix_t
     !> The C pointer to the matrix.
     type(C_PTR) :: ptr = C_NULL_PTR
  end type bml_matrix_t

  !> The bml-dense matrix type identifier.
  character(len=*), parameter :: BML_MATRIX_DENSE = "dense"

  !> The bml-ellpack matrix type identifier.
  character(len=*), parameter :: BML_MATRIX_ELLPACK = "ellpack"

  !> The single precision identifier.
  character(len=*), parameter :: BML_PRECISION_SINGLE_REAL = "single_real"

  !> The double-precision identifier.
  character(len=*), parameter :: BML_PRECISION_DOUBLE_REAL = "double_real"

  !> The single precision identifier.
  character(len=*), parameter :: BML_PRECISION_SINGLE_COMPLEX = "single_complex"

  !> The double-precision identifier.
  character(len=*), parameter :: BML_PRECISION_DOUBLE_COMPLEX = "double_complex"

end module bml_types_m
