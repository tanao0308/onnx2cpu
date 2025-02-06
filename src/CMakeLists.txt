include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(demo main.cpp func.cpp)


# 测试添加 ONNX Target 并链接到本项目
find_package(utf8_range REQUIRED CONFIG)
find_package(absl REQUIRED CONFIG)
find_package(LLVM REQUIRED CONFIG)
find_package(MLIR REQUIRED CONFIG)
find_package(ONNX REQUIRED CONFIG)
message("aaaa${CMAKE_MODULE_PATH}")
if(TARGET ONNX::onnx)
    message(STATUS "Exist target ONNX::onnx")
endif()
if(TARGET ONNX::onnx_proto)
    message(STATUS "Exist target ONNX::onnx_proto")
endif()
message(STATUS "ONNX include directories: ${ONNX_INCLUDE_DIRS}")
message(STATUS "ONNX Version: ${ONNX_VERSION}, ONNX Position: ${ONNX_DIR}")

target_include_directories(demo PRIVATE ${ONNX_INCLUDE_DIRS})
target_link_libraries(demo PRIVATE ONNX::onnx ONNX::onnx_proto)


# 添加 onnx-mlir 的 compiler 静态库
add_library(OnnxMlirCompiler STATIC IMPORTED)
set_target_properties(OnnxMlirCompiler PROPERTIES
    IMPORTED_LOCATION "/usr/local/lib/libOMCompiler.a"  # .a 文件的路径
)
# target_link_libraries(libOMCompiler PRIVATE LLVM) # TODO 为静态库配置依赖
target_link_libraries(demo PRIVATE OnnxMlirCompiler)