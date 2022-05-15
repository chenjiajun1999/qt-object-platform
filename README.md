Qt Object Platform
==== 
- 基于 Qt 框架的 3D 物体展示平台，结合纯原生的 OpenGL 库实现。
- 支持鼠标交互，基本几何体生成、物体捕捉等功能。
- 设计了具有链表结构的基类，运用 OOP 多态的特性来统一管理对象，未使用 STL 容器库。
## 开发环境
1. 编程语言：C++
2. 编译器：mingw730_32
3. 项目结构：Qt 5.14.2 + OpenGL
4. 编程环境：CLion 2020.3.4
## 项目文件夹
- object  3D 物体实现类
- tool 鼠标工具类
- vessel 数学工具类
- window Qt 的窗口类
## 示例
![image](https://github.com/hachikuji894/resource-repository/blob/main/images/ededbdf487b6f12ef5ce2dbca296201.png)
## 本地运行
- 克隆到本地后用 CLion 打开项目
- 选择 Qt Creator 下的 /Qt/Tools/mingw730_32 作为 CLion 的 MinGW，并到 /bin 目录设置为电脑环境变量
- 下载 freeglut 3.0 复制 /bin、/include、/lib 文件到 /Qt/5.14.2/mingw73_32 
- 修改 CMakeLists 设置合适的路径
~~~
set(CMAKE_PREFIX_PATH "XXXXXX/Qt/5.14.2/mingw73_32/")
link_directories("XXXXXX/Qt/5.14.2/mingw73_32/lib")
~~~
- 编译运行