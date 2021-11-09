# 开发环境

运行环境: windows
开发语言: C++
设备类型: 桌面(windows)
编译器: Microsoft Visual C++ Compiler 14.0(x86)
Qt 版本: Qt 5.9.0 MSVC2015 32bit
IDE版本: QtCreator 4.3.0(community)

***

# 注意事项

* 路径不要有中文和特殊符号

* 添加构建步骤:自定义进程步骤

  ``` makefile
  nmake install
  ```

* 代码中使用了自定义的控件(`MultiWidget`和`Serialcomm`),自定义控件的源码分别在

  `multiwidgetplugin`

  `serialcommplugin`

  里面有mingw和msvc2015文件夹，当使用相应的编译器时会调用这里的\*.dll文件

* 如果想在Defigner里面看到有这两个自定义控件,则需要将里面的`xxxplugin`里面的\*.dll和\*.lib文件复制到QtCreator的安装目录里,详细的操作请先学习如何创建自定义控件.

* 源码兼容msvc和mingw两个编译器,可以任意切换两个编译器进行编译,默认使用msvc2015编译

* 如果切换编译器,要注意将之前的所有编译生成文件删掉再重新编译

  




