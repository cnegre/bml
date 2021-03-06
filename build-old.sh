#!/bin/sh

TOP_DIR="${PWD}"
BUILD_DIR="${BUILD_DIR:=${TOP_DIR}/build-old}"
INSTALL_DIR="${INSTALL_DIR:=${TOP_DIR}/install-old}"

mkdir -v -p "${BUILD_DIR}" || exit
mkdir -v -p "${INSTALL_DIR}" || exit

cd "${BUILD_DIR}"
cmake .. \
  -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE:=Debug} \
  -DCMAKE_Fortran_COMPILER=${FC:=gfortran} \
  -DCMAKE_INSTALL_PREFIX="${INSTALL_DIR}" \
  -DBML_TESTING=yes \
  -DBML_OLD=yes
cd "${TOP_DIR}"

make -C "${BUILD_DIR}" VERBOSE=0 || exit
make -C "${BUILD_DIR}" docs || exit
cd "${BUILD_DIR}"
ctest --output-on-failure
cd "${TOP_DIR}"
make -C "${BUILD_DIR}" install
