#include "kiss/Transforms/Passes.h"
#include "mlir/InitAllDialects.h"
#include "mlir/InitAllExtensions.h"
#include "mlir/InitAllPasses.h"
#include "mlir/Tools/mlir-opt/MlirOptMain.h"

int main(int argc, char **argv) {
  mlir::DialectRegistry registry;
  mlir::registerAllDialects(registry);
  mlir::registerAllExtensions(registry);
  mlir::registerAllPasses();

  kiss::registerKissPasses();

  return mlir::asMainReturnCode(
      mlir::MlirOptMain(argc, argv, "kiss-opt\n", registry));
}
