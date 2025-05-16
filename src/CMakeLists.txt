set (libmcpc_SOURCES)

# add_compile_options(-std=c23)
# add_compile_options(-Dis_unix)

add_compile_options (/Dis_win)
add_compile_options (/Dis_wincl)
add_compile_options (/nologo)
add_compile_options (/std:c17)
add_compile_options (/DMCPC_PTCH_C23KW1)
add_compile_options (/DMCPC_PTCH_C23CKD1)
add_compile_options (/DMCPC_PTCH_C23UCHAR1)


list (APPEND libmcpc_SOURCES alloc.c)
list (APPEND libmcpc_SOURCES log.c)
list (APPEND libmcpc_SOURCES errcode.c)
list (APPEND libmcpc_SOURCES tool.c)
list (APPEND libmcpc_SOURCES rsc.c)
list (APPEND libmcpc_SOURCES server.c)
list (APPEND libmcpc_SOURCES retbuf.c)
list (APPEND libmcpc_SOURCES ucbr.c)
list (APPEND libmcpc_SOURCES serlz.c)
list (APPEND libmcpc_SOURCES mjson.c)

add_library (mcpc STATIC ${libmcpc_SOURCES})

target_include_directories (
  mcpc
  PRIVATE ${PROJECT_SOURCE_DIR}
)
target_link_libraries (mcpc ws2_32)
