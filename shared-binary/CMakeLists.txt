if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # set to use Multithreaded Static Runtime
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

  # vcpkg has some issues with not loading the static libs
  # so manually fix the MSVC runtime components used
  string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
  string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})
  string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE})
endif()


# Specify Project
project(g_pc_toolkit_shared_binary VERSION 1.0.0 LANGUAGES C CXX)

# include tooling to generate export header
include(GenerateExportHeader)

# export a json file with the compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Find pcl
find_package(PCL 1.15.0 CONFIG REQUIRED COMPONENTS registration)

# specify shared-library target
add_library(g_pc_toolkit SHARED)

# add source
include(${CMAKE_CURRENT_SOURCE_DIR}/src/CMakeLists.txt)

# add compile definitions
target_compile_definitions(g_pc_toolkit PUBLIC g_pc_toolkit_BYTE_PACKING_${CMAKE_SIZEOF_VOID_P})

target_include_directories(g_pc_toolkit
  PUBLIC
  "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/g_pc_toolkit>"
  # add binary directory so auto-generated G_PC_TOOLKIT_EXPORT.h is found
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)

# plaform specific definitions
if(WIN32)
  # windows.h definitions
  target_compile_definitions(g_pc_toolkit PUBLIC WIN32_LEAN_AND_MEAN NOMINMAX /wd4068)
elseif(UNIX)
  # link against static system libs
  target_link_options(g_pc_toolkit PRIVATE
    "-static-libgcc" "-static-libstdc++"
  )

  # try and remove unused code sections
  target_compile_options(g_pc_toolkit PRIVATE
    "-fdata-sections" "-ffunction-sections" "-Wl,--gc-sections"
  )

  # don't use "lib"-prefix on linux
  set_target_properties(g_pc_toolkit PROPERTIES PREFIX "")
endif()

# specify target properties
# winrt only supports C++17 std
set_property(TARGET g_pc_toolkit PROPERTY CXX_STANDARD 17)
set_target_properties(g_pc_toolkit PROPERTIES
  POSITION_INDEPENDENT_CODE ON
  C_VISIBILITY_PRESET hidden
  CXX_VISIBILITY_PRESET hidden
  VISIBILITY_INLINES_HIDDEN ON
  WINDOWS_EXPORT_ALL_SYMBOLS OFF
)

# generate export header
generate_export_header(g_pc_toolkit)

# Set the Library Filename to include the bitness
math(EXPR BITNESS "8*${CMAKE_SIZEOF_VOID_P}")
set_target_properties(g_pc_toolkit PROPERTIES OUTPUT_NAME gpctoolkit_${BITNESS}-${g_pc_toolkit_shared_binary_VERSION_MAJOR})
target_link_libraries(g_pc_toolkit PRIVATE
  ${PCL_LIBRARIES}
)

# Install Shared Library
INSTALL(TARGETS g_pc_toolkit
  RUNTIME DESTINATION g_pc_toolkit/bin
  LIBRARY DESTINATION g_pc_toolkit/bin
)
