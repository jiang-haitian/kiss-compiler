add_mlir_library(KissTransforms
  FooPass.cpp

  DEPENDS
  TransformsPassIncGen

  LINK_COMPONENTS
  Core

  LINK_LIBS PUBLIC
  MLIRArithDialect
  MLIRDialectUtils
  MLIRIR
  MLIRMathDialect
  MLIRPass
  MLIRTensorDialect
  MLIRTransforms
  MLIRMathTransforms
  MLIRSupport
)
