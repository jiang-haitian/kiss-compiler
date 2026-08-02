#ifndef KISS_COMPILER_TRANSFORMS_PASSES
#define KISS_COMPILER_TRANSFORMS_PASSES

include "mlir/Pass/PassBase.td"

def FooPass : Pass<"foo", "func::FuncOp"> {
  let summary = "just a test pass";
  let description = [{
  }];
  let constructor =
       "kiss::createFooPass()";
}

#endif
