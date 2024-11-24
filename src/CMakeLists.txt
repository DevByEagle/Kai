project(lily VERSION 1.0.0 LANGUAGES C)

set(lily_headers
    lily.h
    )

file(GLOB SOURCES "*.c")

add_library(${PROJECT_NAME} ${SOURCES} ${lily_headers})

if (NOT BUILD_SHARED_LIBS)
    MESSAGE(STATUS "Building ${PROJECT_NAME} static library")
    add_library(${PROJECT_NAME}_static ALIAS ${PROJECT_NAME})
else()
    MESSAGE(STATUS "Building ${PROJECT_NAME} shared library")
    target_compile_definitions(${PROJECT_NAME}
                               PRIVATE $<BUILD_INTERFACE:BUILD_LIBTYPE_SHARED>
                               INTERFACE $<INSTALL_INTERFACE:USE_LIBTYPE_SHARED>
    )
    set_target_properties(${PROJECT_NAME} PROPERTIES
        PREFIX ""
    )
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
                      PUBLIC_HEADER "${lily_headers}"
                      VERSION ${PROJECT_VERSION}
                      )

# Registering include directories
target_include_directories(${PROJECT_NAME}
                           PUBLIC
                           $<INSTALL_INTERFACE:include>
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                           PRIVATE
                           ${CMAKE_CURRENT_SOURCE_DIR}
                           )

target_link_libraries(${PROJECT_NAME} PRIVATE opengl32 glu32 gdi32)
# Copy the header files to the build directory for convenience
file(COPY ${lily_headers} DESTINATION "include")

# Includes information on how the library will be installed on the system
# when cmake --install is run
#include(InstallConfigurations)

# Options if you want to create an installer using CPack
include(PackConfigurations)

enable_testing()