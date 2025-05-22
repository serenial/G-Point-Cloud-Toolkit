include(${CMAKE_CURRENT_LIST_DIR}/lv_interop/CMakeLists.txt)

target_sources(g_pc_toolkit PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/point_correspondences.cpp
)