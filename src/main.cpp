#include <iostream>
// #include "func.h"
#include <OnnxMlirRuntime.h>
#include <OnnxMlirCompiler.h>

int main() {

    char *outputFile = nullptr;
    char *errorMessage = nullptr;
    const char *onnxFile = "model.onnx";
    const char *flags = "--EmitMLIR";

    int64_t result = onnx_mlir::omCompileFromFile(onnxFile, flags, &outputFile, &errorMessage);

    if (result == onnx_mlir::CompilerSuccess) {
        std::cout << "Compilation successful! Output: " << outputFile << std::endl;
    } else {
        std::cerr << "Compilation failed: " << errorMessage << std::endl;
    }

    return 0;
}