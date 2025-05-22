target_sources(g_pc_toolkit PUBLIC
  FILE_SET HEADERS
  BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
  FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/include/g_pc_toolkit/lv_interop/lv_types.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/g_pc_toolkit/lv_interop/set_packing.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/g_pc_toolkit/lv_interop/lv_vec_types.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/g_pc_toolkit/lv_interop/lv_edvr_managed_object.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/g_pc_toolkit/lv_interop/lv_str.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/g_pc_toolkit/lv_interop/lv_array_1d.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/g_pc_toolkit/lv_interop/lv_functions.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/g_pc_toolkit/lv_interop/lv_array_md.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/g_pc_toolkit/lv_interop/lv_array_2d.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/g_pc_toolkit/lv_interop/lv_error.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/g_pc_toolkit/lv_interop/reset_packing.hpp
)

target_sources(g_pc_toolkit PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/lv_functions.cpp
  ${CMAKE_CURRENT_LIST_DIR}/lv_error.cpp
  ${CMAKE_CURRENT_LIST_DIR}/lv_str.cpp
  ${CMAKE_CURRENT_LIST_DIR}/lv_vec_types.cpp
)