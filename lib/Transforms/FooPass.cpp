#include "kiss/Transforms/Passes.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Support/LLVM.h"

#define DEBUG_TYPE "foo"

using namespace mlir;
using namespace kiss;

namespace {
#define GEN_PASS_DEF_FOOPASS
#include "kiss/Transforms/Passes.h.inc"
} // namespace

namespace {
struct FooPass : public impl::FooPassBase<FooPass> {
  using Base::Base;
  void runOnOperation() override;
};
} // namespace

void FooPass::runOnOperation() {
  func::FuncOp funcOp = getOperation();
  funcOp.dump();
}

std::unique_ptr<Pass> kiss::createFooPass() {
  return std::make_unique<FooPass>();
}
