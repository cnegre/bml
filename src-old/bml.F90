!> \mainpage Basic Matrix Library (bml)
!!
!! This library implements a common API for linear algebra and matrix
!! functions. It offers several data structures for matrix storage and
!! algorithms. Currently the following are implemented:
!!   - dense @ref bml_type_m::bml_matrix_dense
!!   - sparse (ELLPACK) @ref bml_type_m::bml_matrix_ellpack
!!
!! The use of this library is pretty straightforward. In the
!! application code, `use` the bml main module,
!!
!! \code{.F90}
!! use bml
!! \endcode
!!
!! A matrix is of type
!!
!! \code{.F90}
!! class(bml_matrix_t), allocatable :: a
!! \endcode
!!
!! There are two important things to note. First, we use a polymorphic
!! type for matrices in order to simplify the bml code, hence the
!! matrix type is specified with the `class` keyword instead of
!! `type`. Second, the matrix needs to be allocatable since it has to
!! be allocated by the library using the desired type,
!! e.g. dense:double. A matrix is allocated through one of the \ref
!! allocate_group "allocation functions". For instance,
!!
!! \code{.F90}
!! call bml_allocate(BML_MATRIX_DENSE, 100, a)
!! \endcode
!!
!! will allocate a dense, double-precision, \f$ 100 \times 100 \f$
!! matrix which is initialized to zero. Additional functions allocate
!! special matrices,
!!   - bml_allocate_m::bml_random_matrix Allocate and initialize a
!!     random matrix.
!!   - bml_allocate_m::bml_identity_matrix Allocate and initialize the
!!     identity matrix.
!!
!! A matrix is deassociated by calling
!!
!! \code{.F90}
!! call bml_deallocate(a)
!! \endcode
!!
!! \author
!! Jamaludin Mohd-Yusof <jamal@lanl.gov>
!! Nicolas Bock <nbock@lanl.gov>
!! Susan M. Mniszewski <smm@lanl.gov>
!!
!! \copyright Los Alamos National Laboratory 2015
!!
!! \todo
!! Add full support for dense matrix type for single precision.
!!
!! \defgroup allocate_group Allocation and Deallocation Functions
!! \defgroup convert_group Converting between Matrix Formats
!! \defgroup add_group Adding Matrices
!! \defgroup multiply_group Multiplying Matrices

!> \copyright Los Alamos National Laboratory 2015

!> Main matrix library module.
module bml

  ! Put this first.
  use bml_type_m

  ! Add all of the other modules.
  use bml_add_m
  use bml_allocate_m
  use bml_convert_m
  use bml_copy_m
  use bml_diagonalize_m
  use bml_error_m
  use bml_get_bandwidth_m
  use bml_get_m
  use bml_multiply_m
  use bml_print_m
  use bml_scale_m
  use bml_trace_m
  use bml_transpose_m
  use bml_utility_m

contains

  !> Get the library version string.
  !!
  !! \return The version string.
  function bml_version()
    character(len=100) :: bml_version
    bml_version = PROJECT_VERSION
  end function bml_version

end module bml
