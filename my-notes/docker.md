## 学习 docker
### 启动 docker 容器
    docker run -it \
    -v ~/om:/root/om \
    -p 5555:22 \
    2c7dfd53f0c4 \
    bash
### 使用 vscode 连接本机 docker 容器
    本质是要访问容器中的 ssh 服务
    使用命令行启动并进入容器，为容器下载 ssh 服务。
        由于外界默认不能访问容器的端口，在启动容器时需要将内部的 ssh 端口（默认为22）映射到宿主机的某个端口（xx）
        此时宿主机的 xx 端口提供的服务就是容器 22 端口的 ssh 服务
    接下来配置 vscode 的 ssh 连接即可（\.ssh\config）
```
Host onnx-mlir
    HostName localhost
    User root
    Port 2222
```
    容器内还需要配置 /etc/ssh/sshd_config 文件，设置 PermitRootLogin yes, PasswordAuthentication yes

### 使用 vscode 连接 wsl2 中的 docker 容器
    多了一步配置 windows 到 wsl2 的端口映射