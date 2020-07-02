INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_METEOR meteor)

FIND_PATH(
    METEOR_INCLUDE_DIRS
    NAMES meteor/api.h
    HINTS $ENV{METEOR_DIR}/include
        ${PC_METEOR_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    METEOR_LIBRARIES
    NAMES gnuradio-meteor
    HINTS $ENV{METEOR_DIR}/lib
        ${PC_METEOR_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(METEOR DEFAULT_MSG METEOR_LIBRARIES METEOR_INCLUDE_DIRS)
MARK_AS_ADVANCED(METEOR_LIBRARIES METEOR_INCLUDE_DIRS)

