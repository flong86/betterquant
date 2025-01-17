include(ExternalProject)
include(cmake/config.cmake)

set(READERWRITER_QUEUE_MAJOR_VER 1)
set(READERWRITER_QUEUE_MINOR_VER 0)
set(READERWRITER_QUEUE_PATCH_VER 6)
set(READERWRITER_QUEUE_URL_HASH  SHA256=fc68f55bbd49a8b646462695e1777fb8f2c0b4f342d5e6574135211312ba56c1)

set(READERWRITER_QUEUE_VER     ${READERWRITER_QUEUE_MAJOR_VER}.${READERWRITER_QUEUE_MINOR_VER}.${READERWRITER_QUEUE_PATCH_VER})
set(READERWRITER_QUEUE_ROOT    ${3RDPARTY_PATH}/readerwriterqueue)
set(READERWRITER_QUEUE_INC_DIR ${READERWRITER_QUEUE_ROOT}/src/readerwriterqueue-${READERWRITER_QUEUE_VER}/)

set(READERWRITER_QUEUE_URL https://github.com/cameron314/readerwriterqueue/archive/refs/tags/v${READERWRITER_QUEUE_VER}.tar.gz)

ExternalProject_Add(readerwriterqueue-${READERWRITER_QUEUE_VER}
    URL               ${READERWRITER_QUEUE_URL}
    URL_HASH          ${READERWRITER_QUEUE_URL_HASH} 
    DOWNLOAD_NAME     readerwriterqueue-${READERWRITER_QUEUE_VER}.tar.gz
    PREFIX            ${READERWRITER_QUEUE_ROOT}
    CONFIGURE_COMMAND ""
    BUILD_COMMAND     ""
    INSTALL_COMMAND   ""
    )

set(3RDPARTY_DEPENDENCIES ${3RDPARTY_DEPENDENCIES} readerwriterqueue-${READERWRITER_QUEUE_VER})

if (NOT EXISTS ${READERWRITER_QUEUE_ROOT}/src/readerwriterqueue-${READERWRITER_QUEUE_VER})
    add_custom_target(rescan-readerwriterqueue ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR} DEPENDS readerwriterqueue-${READERWRITER_QUEUE_VER})
else()
    add_custom_target(rescan-readerwriterqueue)
endif()

