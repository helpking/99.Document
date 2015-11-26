http://www.css88.com/archives/4548

Node.js的process模块

process模块用来与当前进程互动，可以通过全局变量process访问，不必使用require命令加载。它是一个EventEmitter对象的实例。

属性
process对象提供一系列属性，用于返回系统信息。

process.pid：当前进程的进程号。
process.version：Node的版本，比如v0.10.18。
process.platform：当前系统平台，比如Linux。
process.title：默认值为“node”，可以自定义该值。
process.argv：当前进程的命令行参数数组。
process.env：指向当前shell的环境变量，比如process.env.HOME。
process.execPath：运行当前进程的可执行文件的绝对路径。
process.stdout：指向标准输出。
process.stdin：指向标准输入。
process.stderr：指向标准错误。

参考例子：001_ProcessStdOut.js
