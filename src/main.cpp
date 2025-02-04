#include <OnnxMlirCompiler.h>

#include <iostream>

#include "func.h"

int main() {
  // 测试基础 cmake 操作
  std::cout << func() << std::endl;

  // 测试 .onnx 文件到 mlir dialect 的转化
  char *outputFile = nullptr;
  char *errorMessage = nullptr;
  const char *onnxFile = "model.onnx";
  const char *flags = "--EmitMLIR";

  int64_t result =
      onnx_mlir::omCompileFromFile(onnxFile, flags, &outputFile, &errorMessage);

  if (result == onnx_mlir::CompilerSuccess) {
    std::cout << "Compilation successful! Output: " << outputFile << std::endl;
  } else {
    std::cerr << "Compilation failed: " << errorMessage << std::endl;
  }

  return 0;
}