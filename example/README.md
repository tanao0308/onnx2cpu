## run onnx with C
#### 将模型从 python 转为 .onnx 格式
```shell
$ python add.py
```
#### 将模型从 .onnx 转为 .so 格式
```shell
$ onnx-mlir add.onnx
```
#### 使用 C 调用模型，并进行推理
```shell
gcc main.c add.so -o add
```
#### 运行模型
```shell
$ export LD_LIBRARY_PATH=. && ./add
```