# 使用Ubuntu 24.04作为基础镜像
FROM ubuntu:24.04

# 设置非交互模式，避免安装过程中出现交互提示
ENV DEBIAN_FRONTEND=noninteractive

# 更新包列表并安装必要的依赖
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    make \
    libsfml-dev \
    && rm -rf /var/lib/apt/lists/*

# 创建工作目录
WORKDIR /app

# 复制项目文件到容器中
COPY . /app

# 创建构建目录并进行编译
RUN mkdir -p build && cd build \
    && cmake .. \
    && make

# 运行生成的可执行文件
CMD ["./build/maze"]
