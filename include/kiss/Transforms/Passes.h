#ifndef KISS_TRANSFORMS_PASSES_H
#define KISS_TRANSFORMS_PASSES_H

#include "mlir/Pass/Pass.h"
#include <memory>

namespace kiss {

std::unique_ptr<mlir::Pass> createFooPass();

#define GEN_PASS_REGISTRATION
#include "kiss/Transforms/Passes.h.inc"

inline void registerKissPasses() { registerFooPass(); }

} // namespace kiss
#endif
