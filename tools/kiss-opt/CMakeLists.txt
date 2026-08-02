
add_llvm_executable(kiss-opt kiss-opt.cpp PARTIAL_SOURCES_INTENDED)
llvm_update_compile_flags(kiss-opt)

get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)
get_property(conversion_libs GLOBAL PROPERTY MLIR_CONVERSION_LIBS)
get_property(extension_libs GLOBAL PROPERTY MLIR_EXTENSION_LIBS)
target_link_libraries(kiss-opt PRIVATE
  ${dialect_libs}
  ${conversion_libs}
  ${extension_libs}

  KissTransforms

  MLIROptLib
  MLIRPass
  MLIRTransforms
  MLIRMlirOptMain
  MLIRParser
  MLIRSupport
  MLIRIR
  )

mlir_check_all_link_libraries(kiss-opt)
