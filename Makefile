LLVM_BUILD_DIR = ~/llvm-project/build_debug

.PHONY: default clean test

default:
	cmake -G Ninja -B build/ . \
		-DLLVM_DIR=$(LLVM_BUILD_DIR)/lib/cmake/llvm \
		-DMLIR_DIR=$(LLVM_BUILD_DIR)/lib/cmake/mlir \
		-DPolly_DIR=$(LLVM_BUILD_DIR)/tools/polly/lib/cmake/polly \
		-DCMAKE_C_COMPILER=clang \
		-DCMAKE_CXX_COMPILER=clang++ \
        -DCMAKE_LINKER_TYPE=LLD
	cmake --build build/

clean:
	-rm -rf build/

test:
	build/tools/kiss-opt/kiss-opt -foo test/in.mlir 2>log
