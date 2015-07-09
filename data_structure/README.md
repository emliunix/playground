# OUTLINE

学习基本数据结构的所有笔记，代码，及其他工作成果。

### Notes：

* 索引以0开始
* 数据元素为简单起见，全部使用整型（char型和int型没什么冲突）
* 使用GNU Make作为自动构建工具
* 编写环境以Linux环境为主，所以可能无法在Windows上编译通过，或是需要特殊的环境（MinGW，Cygwin），代码可以查看,后期可能会有在windows上编译的二进制文件打包
* 欢迎提交pull requests，一起完善

## 线性表

在`sequence`目录下。

按照我的总结，线性表包括如下内容：

* 基本的线性表
* 顺序表
* 串
* 栈，队列

基本的线性表就是那种每一个元素都有另一个元素作为直接前驱或直接后继的数据结构

这种数据结构的抽象模型应该只关注这种关系，也就是说不应该考虑元素具体是什么类型，
元素与元素之间是否可以比较大小，元素的个数是否有限（无限元素个数的线性表可以参见
**lazy sequence**的概念）

线性表的存储结构主要有顺序存储（就是用一个数组，也就是一块连续的存储空间来存储）和
链式存储（通过一个具有引用作用的字段来保存节点与节点的关系，C/C++里面的指针，
Java里面的对象引用）

顺序表在基本线性表上添加一层限制：

* 首先元素之间可以比较大小，
* 其次表中的每一个元素与其直接前驱或后继要符合统一的大小关系，
就是一个比一个小或一个比一个大的意思。

串在线性表上添加的限制：

* 串中的每一个元素可以与另一个元素进行等价的比较。
如果说顺序表中的元素之间需要存在`>`或`<`的比较能力，那么在串中，
元素之间需要能够进行`==`比较。

栈和队列：

* 栈即是LIFO（Last In First Out, 后进先出或者说是先进后出）
* 队列即是FIFO（First  In First Out,先进先出）

### Notes：

为了简单，这里的顺序存储就不像java里面的ArrayList一样实现动态扩容了。

## 递归

## 矩阵与广义表