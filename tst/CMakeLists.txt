

add_compile_options(/Dis_win)
add_compile_options(/Dis_wincl)
add_compile_options(/nologo)
add_compile_options(/std:c17)
add_compile_options(/DMCPC_C23PTCH_KW1)
add_compile_options(/DMCPC_C23PTCH_CKD1)
add_compile_options(/DMCPC_C23PTCH_UCHAR1)


# --------------------------- Add A Test ---------------------------

set (CurrTestName server1)

add_executable (${CurrTestName} ${CurrTestName}.c commtst.c)

target_include_directories (
  ${CurrTestName}
  PRIVATE ${PROJECT_SOURCE_DIR}
  PRIVATE ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries (${CurrTestName} ws2_32)
target_link_libraries (${CurrTestName} mcpc)

add_test(NAME ${CurrTestName} COMMAND ${CurrTestName})

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/server1-req-initialize-1.json
  ${CMAKE_CURRENT_BINARY_DIR}/server1-req-initialize-1.json
  COPYONLY
)
