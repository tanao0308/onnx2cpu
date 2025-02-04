include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(demo main.cpp func.cpp)

find_package(utf8_range REQUIRED)
find_package(absl REQUIRED)
find_package(LLVM REQUIRED)
find_package(MLIR REQUIRED)
find_package(ONNX REQUIRED)
if(TARGET ONNX::onnx)
    message(STATUS "Exist target ONNX::onnx!")
endif()
if(TARGET ONNX::onnx_proto)
    message(STATUS "Exist target ONNX::onnx_proto!")
endif()
message(STATUS "ONNX include directories: ${ONNX_INCLUDE_DIRS}")
message(STATUS ">>> ${ONNX_LIBS} || ${ONNX_VERSION} || ${ONNX_DIR} || ${ONNX}")
# include_directories(${LLVM_INCLUDE_DIRS})
# target_link_libraries(demo ${LLVM_LIBRARIES})

target_include_directories(demo PRIVATE ${ONNX_INCLUDE_DIRS})
target_link_libraries(demo PRIVATE ONNX::onnx ONNX::onnx_proto)

################################################################

add_library(OnnxMlirCompiler STATIC IMPORTED)
set_target_properties(OnnxMlirCompiler PROPERTIES
    IMPORTED_LOCATION "/usr/local/lib/libOMCompiler.a"  # .a 文件的路径
)
# target_link_libraries(libOMCompiler PRIVATE LLVM)
target_link_libraries(demo PRIVATE OnnxMlirCompiler)

get_target_property(ONNX_LINK_LIBRARIES ONNX::onnx INTERFACE_LINK_LIBRARIES)
message(STATUS "${ONNX_LINK_LIBRARIES} || ${INTERFACE_LINK_LIBRARIES}")