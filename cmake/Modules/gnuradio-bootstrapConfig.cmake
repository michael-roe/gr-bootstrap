find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_BOOTSTRAP gnuradio-bootstrap)

FIND_PATH(
    GR_BOOTSTRAP_INCLUDE_DIRS
    NAMES gnuradio/bootstrap/api.h
    HINTS $ENV{BOOTSTRAP_DIR}/include
        ${PC_BOOTSTRAP_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_BOOTSTRAP_LIBRARIES
    NAMES gnuradio-bootstrap
    HINTS $ENV{BOOTSTRAP_DIR}/lib
        ${PC_BOOTSTRAP_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-bootstrapTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_BOOTSTRAP DEFAULT_MSG GR_BOOTSTRAP_LIBRARIES GR_BOOTSTRAP_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_BOOTSTRAP_LIBRARIES GR_BOOTSTRAP_INCLUDE_DIRS)
