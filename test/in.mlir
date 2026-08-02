module {
  func.func @main() {
    %c0 = arith.constant 0 : index
    %c1 = arith.constant 1 : index
    scf.for %i = %c0 to %c1 step %c1 {
      %a = arith.addi %c1, %c1 : index
    }
    return
  }
}
