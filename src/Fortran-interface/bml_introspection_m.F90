!> Introspection procedures.
module bml_introspection_m

  implicit none

  private

  interface
     !> Return the matrix size.
     function bml_get_N_C(a) result(n) bind(C, name="bml_get_N")
       use, intrinsic :: iso_C_binding
       type(C_PTR), value, intent(in) :: a
       integer(C_INT) :: n
     end function bml_get_N_C
  end interface

  public :: bml_get_N
  public :: bml_get_bandwidth

contains

  !> Return the matrix size.
  !!
  !!\param a The matrix.
  !!\return The matrix size.
  function bml_get_n(a)

    use bml_types_m

    type(bml_matrix_t), intent(in) :: a
    integer :: bml_get_n

    bml_get_n = bml_get_N_C(a%ptr)

  end function bml_get_n

  !> Get the number of non-zero elements in a given row.
  !!
  !! @param a The matrix.
  !! @param i The row.
  !! @returns The number of non-zero elements (bandwidth) on that row.
  function bml_get_bandwidth(a, i) result(m_i)

    use bml_types_m

    type(bml_matrix_t), intent(in) :: a
    integer, intent(in) :: i
    integer :: m_i

  end function bml_get_bandwidth

end module bml_introspection_m