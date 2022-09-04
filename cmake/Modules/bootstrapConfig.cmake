INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_BOOTSTRAP bootstrap)

FIND_PATH(
    BOOTSTRAP_INCLUDE_DIRS
    NAMES bootstrap/api.h
    HINTS $ENV{BOOTSTRAP_DIR}/include
        ${PC_BOOTSTRAP_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    BOOTSTRAP_LIBRARIES
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

include("${CMAKE_CURRENT_LIST_DIR}/bootstrapTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(BOOTSTRAP DEFAULT_MSG BOOTSTRAP_LIBRARIES BOOTSTRAP_INCLUDE_DIRS)
MARK_AS_ADVANCED(BOOTSTRAP_LIBRARIES BOOTSTRAP_INCLUDE_DIRS)
