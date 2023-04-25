# im-enable
代码自于`vscodevim`的`im-select`和[这一篇博客](https://blog.csdn.net/jjk26/article/details/127350273)

# 为什么我做这个东西
`im-select`项目使用的是切换不同的键盘布局，从而实现的输入法切换。而这就需要我们添加英语输入法，引入新的输入法切换快捷键，
而且状态栏还会多显示一个键盘状态，不爽，很不爽。所以我寻找使用使能和失能输入法的方式来替代。

# 使用方式
请参考[im-select](https://github.com/daipeihust/im-select)

# 编译
1. 安装VS
2. 打开`x64 Native Tools Command Prompt for VS xxxx`(xxxx为vs版本)，命令行cd到仓库目录，执行`cl.exe im_enable.cpp`

# 已知问题
微软自带输入法可以切换到英文，但是没法切换回中文。因为默认使用`ctrl+space`对应的其实是`输入法/非输入法切换`。
需要我们进入`设置->输入->高级键盘设置->语言栏选项->高级键设置`修改对应项的按键，而且还不能不设置。
