# This file was automatically generated for projects
# without default 'CMakeLists.txt' file.

FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/src/*.*)

# Embed the IOP file using absolute path
idf_component_register(
    SRCS ${app_sources}
    EMBED_FILES ${CMAKE_SOURCE_DIR}/object_pool/ESP_Controler.iop
)
