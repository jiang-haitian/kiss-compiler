#include "kiss/Transforms/Passes.h"
#include "mlir/Analysis/DataFlow/DeadCodeAnalysis.h"
#include "mlir/Analysis/DataFlow/IntegerRangeAnalysis.h"
#include "mlir/Analysis/DataFlow/SparseAnalysis.h"
#include "mlir/Analysis/DataFlowFramework.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/PatternMatch.h"
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
class Worker {
public:
  Worker(func::FuncOp funcOp) : funcOp(funcOp), rewriter(funcOp) {}

  LogicalResult run();

private:
  func::FuncOp funcOp;
  IRRewriter rewriter;
};
} // namespace

LogicalResult Worker::run() {
  DataFlowSolver solver;
  solver.load<dataflow::DeadCodeAnalysis>();
  solver.load<dataflow::IntegerRangeAnalysis>();
  if (failed(solver.initializeAndRun(funcOp)))
    return failure();

  funcOp.walk([&](arith::AddIOp addiOp) {
    addiOp.dump();
    auto *lattice = solver.lookupState<dataflow::IntegerValueRangeLattice>(
        addiOp.getResult());
    if (lattice) {
      auto r = lattice->getValue().getValue();
      llvm::dbgs() << "smax = " << r.smax() << "\n";
    } else {
      llvm::dbgs() << "state not found\n";
    }
  });
  return success();
}

namespace {
struct FooPass : public impl::FooPassBase<FooPass> {
  using Base::Base;
  void runOnOperation() override;
};
} // namespace

void FooPass::runOnOperation() {
  func::FuncOp funcOp = getOperation();

  if (failed(Worker(funcOp).run()))
    return signalPassFailure();
}

std::unique_ptr<Pass> kiss::createFooPass() {
  return std::make_unique<FooPass>();
}
