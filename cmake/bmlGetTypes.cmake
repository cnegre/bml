set(PRECISION_TYPES
  single_real
  double_real
  single_complex
  double_complex)

set(C_REAL_TYPES
  float
  double
  "float complex"
  "double complex")

set(F_REAL_TYPES
  "real(C_FLOAT)"
  "real(C_DOUBLE)"
  "complex(C_FLOAT_COMPLEX)"
  "complex(C_DOUBLE_COMPLEX)")

set(F_REAL_KINDS
  "C_FLOAT"
  "C_DOUBLE"
  "C_FLOAT_COMPLEX"
  "C_DOUBLE_COMPLEX")

set(F_REAL_ELEMENT_NAMES
  BML_ELEMENT_REAL
  BML_ELEMENT_REAL
  BML_ELEMENT_COMPLEX
  BML_ELEMENT_COMPLEX)

set(F_PRECISION_NAMES
  BML_PRECISION_SINGLE_REAL
  BML_PRECISION_DOUBLE_REAL
  BML_PRECISION_SINGLE_COMPLEX
  BML_PRECISION_DOUBLE_COMPLEX)

list(LENGTH PRECISION_TYPES NUMBER_TYPES)
math(EXPR NUMBER_TYPES_MAX "${NUMBER_TYPES}-1")

macro(get_fortran_types INDEX PRECISION_TYPE PRECISION_NAME REAL_TYPE REAL_KIND ELEMENT_NAME)
  list(GET PRECISION_TYPES ${INDEX} ${PRECISION_TYPE})
  list(GET F_PRECISION_NAMES ${INDEX} ${PRECISION_NAME})
  list(GET F_REAL_TYPES ${INDEX} ${REAL_TYPE})
  list(GET F_REAL_KINDS ${INDEX} ${REAL_KIND})
  list(GET F_REAL_ELEMENT_NAMES ${INDEX} ${ELEMENT_NAME})
endmacro()

macro(get_c_types INDEX PRECISION_TYPE REAL_TYPE)
  list(GET PRECISION_TYPES ${INDEX} ${PRECISION_TYPE})
  list(GET C_REAL_TYPES ${INDEX} ${REAL_TYPE})
endmacro()