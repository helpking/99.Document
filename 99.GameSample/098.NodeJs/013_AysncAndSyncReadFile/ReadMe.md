方法
Sr. No.	方法	描述
1	fs.rename(oldPath, newPath, callback)	        rename()异步，不带参数可能是个例外，提供完成回调
2	fs.ftruncate(fd, len, callback)	                ftruncate()异步，不带参数可能是个例外，提供完成回调
3	fs.ftruncateSync(fd, len)	                ftruncate() 同步
4	fs.truncate(path, len, callback)	        truncate()异步. 没有参数时它可能是例外，提供给完成回调。
5	fs.truncateSync(path, len)	                truncate()同步
6	fs.chown(path, uid, gid, callback)	        chown()异步. 没有参数时它可能是例外，提供给完成回调。
7	fs.chownSync(path, uid, gid)	                chown() 同步
8	fs.fchown(fd, uid, gid, callback)	        fchown()异步. 没有参数时它可能是例外，提供给完成回调。
9	fs.fchownSync(fd, uid, gid)	                fchown()异步
10	fs.lchown(path, uid, gid, callback)	        lchown()异步. 没有参数时它可能是例外，提供给完成回调。
11	fs.lchownSync(path, uid, gid)	                lchown()同步
12	fs.chmod(path, mode, callback)	                chmod()异步. 没有参数时它可能产生例外，提供给完成回调。
13	fs.chmodSync(path, mode)	                chmod() 同步
14	fs.fchmod(fd, mode, callback)	                fchmod() 异步. 没有参数时它可能产生例外，提供给完成回调。
15	fs.fchmodSync(fd, mode)	                        fchmod() 同步
16	fs.lchmod(path, mode, callback)	                lchmod() 异步， 没有参数时它可能产生例外，提供给完成回调。仅可在Mac OS X 上使用
17	fs.lchmodSync(path, mode)	                lchmod() 同步
18	fs.stat(path, callback)	                        stat() 同步，回调函数得到两个参数(err, stats) ，其中stats是一个fs.Stats对象
19	fs.lstat(path, callback)	                lstat()异步，回调函数得到两个参数(err, stats)，其中stats是一个fs.Stats对象。lstat()等同于stat()，不同之处在于，如果路径path是一个符号链接，那么链接本身是stat-ed，而不是指文件。
20	fs.fstat(fd, callback)	                        fstat() 异步. 回调函数得到两个参数 (err, stats) ，其中统计数据是一个fs.Stats对象。fstat()等同于stat()，除了该文件是stat-ed 由文件描述符fd指定。
21	fs.statSync(path)	                        stat()同步，返回fs.Stats的一个实例。
22	fs.lstatSync(path)	                        lstat()同步，返回fs.Stats的一个实例。
23	fs.fstatSync(fd)	                        fstat() 同步，返回fs.Stats的一个实例。
24	fs.link(srcpath, dstpath, callback)	        link() 异步.  没有参数时它可能产生例外，提供给完成回调。
25	fs.linkSync(srcpath, dstpath)	                link() 同步
26	fs.symlink(srcpath, dstpath[, type], callback)	symlink()异步，没有参数时它可能是例外，提供给完成回调。该类型参数可以设置为 'dir', 'file', 或 'junction' (默认为'file') ，只适用于Windows(忽略其他平台)。请注意，Windows结点需要目标路径是绝对的。当使用'junction'，目标参数将自动归绝对路径。
27	fs.symlinkSync(srcpath, dstpath[, type])	symlink()同步
28	fs.readlink(path, callback)	                readlink()同步，回调函数得到两个参数(err, linkString)。
29	fs.realpath(path[, cache], callback)	        realpath() 异步. 回调函数得到两个参数(err, resolvedPath)。可以使用process.cwd解决相对路径。缓存cache是一个对象字面量，可以用来强制一个特定路径解析或避免额外的fs.stat调用真正的路径映射路径。
30	fs.realpathSync(path[, cache])	                realpath()同步，返回解决路径。
31	fs.unlink(path, callback)	                unlink()异步，没有参数时它可能产生例外，提供给完成回调。
32	fs.unlinkSync(path)	                        unlink()同步
33	fs.rmdir(path, callback)	                rmdir()异步，没有参数时它可能产生例外，提供给完成回调。
34	fs.rmdirSync(path)	                        rmdir()同步
35	fs.mkdir(path[, mode], callback)	        mkdir(2)异步，模式默认为0777。
36	fs.mkdirSync(path[, mode])	                mkdir()同步
37	fs.readdir(path, callback)	                readdir(3) 同步，读取目录中的内容。回调函数得到两个参数 (err, files) ，其中文件是文件的数组名称在目录中，不包括 '.' 和 '..'.
38	fs.readdirSync(path)	                        readdir()同步，返回文件名数组不含 '.' 和 '..'.
39	fs.close(fd, callback)	                        close() 同步，没有参数时它可能产生例外，提供给完成回调。
40	fs.closeSync(fd)	                        close() 同步
41	fs.open(path, flags[, mode], callback)	        异步文件打开
42	fs.openSync(path, flags[, mode])	        fs.open()同步
43	fs.utimes(path, atime, mtime, callback)	
 
44	fs.utimesSync(path, atime, mtime)	        改变所提供的路径引用的文件的文件时间戳。
45	fs.futimes(fd, atime, mtime, callback)	
 
46	fs.futimesSync(fd, atime, mtime)	        改变由提供的文件的描述符所引用的文件的文件时间戳。
47	fs.fsync(fd, callback)	                        fsync(2) 异步，没有参数时它可能产生例外，提供给完成回调。
48	fs.fsyncSync(fd)	                        fsync(2)同步
49	fs.write(fd, buffer, offset, length[, position], callback)	fd指定的文件写缓冲器
50	fs.write(fd, data[, position[, encoding]], callback)	        指定的fd写入文件数据。如果数据不是一个缓冲区实例则该值将被强制转换为字符串。
51	fs.writeSync(fd, buffer, offset, length[, position])	        fs.write()同步。返回写入的字节数。
52	fs.writeSync(fd, data[, position[, encoding]])	                fs.write()同步。返回写入的字节数。
53	fs.read(fd, buffer, offset, length, position, callback)	        从fd指定文件读取数据。
54	fs.readSync(fd, buffer, offset, length, position)	        fs.read同步。返回 bytesRead 读取的数量。
55	fs.readFile(filename[, options], callback)	                异步读取文件的全部内容。
56	fs.readFileSync(filename[, options])	                        fs.readFile同步，返回文件名的内容。
57	fs.writeFile(filename, data[, options], callback)	        异步数据写入到文件，如果它已经存在则替换文件。数据可以是字符串或缓冲。
58	fs.writeFileSync(filename, data[, options])	                fs.writeFile 同步
59	fs.appendFile(filename, data[, options], callback)	        异步数据追加到文件，创建文件如果文件不存在。数据可以是字符串或缓冲。
60	fs.appendFileSync(filename, data[, options])	                fs.appendFile同步
61	fs.watchFile(filename[, options], listener)	                关注有关文件名更改，回调监听器在每个被访问的文件名时。
62	fs.unwatchFile(filename[, listener])	                        停止监视对于文件名的更改。如果指定监听器，只有特定的监听器被删除。否则，所有监听器都会删除，已经有效地停止监听文件名。
63	fs.watch(filename[, options][, listener])	                关注文件名的变化，其中 filename 是一个文件或目录。返回是一个 fs.FSWatcher 的对象。
64	fs.exists(path, callback)	                                测试给定的路径通过使用文件系统检查是否存在。然后调用回调参数为真或假。
65	fs.existsSync(path)	                                        fs.exists同步
66	fs.access(path[, mode], callback)	                        由path指定的文件测试用户的权限。mode是一个可选整数，指定要执行辅助功能的检查。
67	fs.accessSync(path[, mode])	                                fs.access同步。这将引发辅助功能失败，否则什么也不做。
68	fs.createReadStream(path[, options])	                        返回一个新的ReadStream对象
69	fs.createWriteStream(path[, options])	                        返回一个新的WriteStream对象
70	fs.symlink(srcpath, dstpath[, type], callback)	                异步symlink(). 该类型参数可以设置为'dir'，'file'，或'junction'(默认为“文件”)，只适用于Windows(忽略其他平台)。请注意，Windows交界点需要的目标路径是绝对的。当使用'junction'，目标参数将自动标准化为绝对路径。 

标志
标志进行读/写操作是：
r - 打开文件进行读取。如果该文件不存在发生异常。
r+ - 打开文件进行读取和写入。如果该文件不存在发生异常。
rs - 打开文件，用于读取在同步方式。指示操作系统绕过本地文件系统高速缓存。这是对NFS挂载打开文件，因为它可以让你跳过潜在陈旧的本地缓存中很有用。它对I/O性能有非常现实的影响，除非需要它，否则不要使用此标志。注意，这无法打开 fs.open() 到一个同步阻塞调用。如果这不是真想要的，那么应该使用fs.openSync()。
rs+ - 打开文件进行读取和写入，告诉操作系统同步地打开它。 对于'rs'有关异步使用 - 要慎用。
w - 打开文件进行写入。该文件被创建(如果它不存在)或截断清空内容(如果存在)。
wx - 类似“w”，但如果路径存在，则失败。
w+ - 打开文件进行读取和写入。该文件被创建(如果它不存在)或截断清空内容(如果存在)。
wx+ - 类似 “w+”，但如果路径存在，则失败
a - 打开文件进行追加。如果文件不存在，则创建该文件
ax - 类似“a”，但如果路径存在则失败
a+ - 打开文件进行读取和追加内容。如果文件不存在，则创建该文件
ax+' - 类似 'a+'，但如果路径存在则会失败
