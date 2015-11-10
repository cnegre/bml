!> Interface module.
module bml_interface_m

  implicit none

  private

  !> The enum values of the C API. Keep this synchronized with the
  !! enum in bml_types.h.
  integer, parameter :: bml_matrix_type_uninitialized_enum_id = 0
  integer, parameter :: bml_matrix_type_dense_enum_id = 1
  integer, parameter :: bml_matrix_type_ellpack_enum_id = 2

  integer, parameter :: bml_matrix_precision_uninitialized_id = 0
  integer, parameter :: bml_matrix_precision_single_real_enum_id = 1
  integer, parameter :: bml_matrix_precision_double_real_enum_id = 2
  integer, parameter :: bml_matrix_precision_single_complex_enum_id = 3
  integer, parameter :: bml_matrix_precision_double_complex_enum_id = 4

  public :: get_enum_id

contains

  !> Convert the matrix type and precisions strings into enum values.
  !!
  !! @param type_string The string used in the Fortran API to identify
  !! the matrix type and precision.
  !! @return The corresponding integer value matching the enum values
  !! in bml_matrix_types_t and bml_matrix_precision_t.
  function get_enum_id(type_string) result(id)

    use bml_types_m

    character(len=*), intent(in) :: type_string
    integer :: id

    select case(type_string)
    case(BML_PRECISION_SINGLE_REAL)
       id = bml_matrix_precision_single_real_enum_id
    case(BML_PRECISION_DOUBLE_REAL)
       id = bml_matrix_precision_double_real_enum_id
    case(BML_PRECISION_SINGLE_COMPLEX)
       id = bml_matrix_precision_single_complex_enum_id
    case(BML_PRECISION_DOUBLE_COMPLEX)
       id = bml_matrix_precision_double_complex_enum_id
    case(BML_MATRIX_DENSE)
       id = bml_matrix_type_dense_enum_id
    case(BML_MATRIX_ELLPACK)
       id = bml_matrix_type_ellpack_enum_id
    case default
       print *, "unknown type string "//trim(type_string)
       error stop
    end select

  end function get_enum_id

end module bml_interface_m