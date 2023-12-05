# Shanghai-Qianrui-Private-Equity-Fund-Written-Examination


#上海骞瑞私募基金 笔试


#建议不要去，还没面试先是基本笔试，然后项目笔试，而且hr特别高冷，发了回答之后不理人的

#我问笔试怎么样，微信和邮箱都不回我

#最抽象的是，我第一次做完1,2轮笔试，过了半个月，另一个猎头找我去面这家，我做完第1轮，那个猎头告诉我你基本笔试不通过，我啊？？？

#第一次笔试给我30题，从linux到c++到八股文到python，第二次才给我几题八股文和python，我随便就做完了，说我不通过，太抽象了


# 编程练习

## test-1 : tickdata的存储

### 背景

alpha基金公司使用csv格式存储tickdata(参见csv/example.csv)，他们发现这种存储格式至少有两个问题：

- 占用磁盘空间较大
- 无法快速提取某段时间数据
  
因此他们想请你帮忙设计一种二进制文件格式，即td文件，来解决上面两个问题。由于将所有数据以二进制格式(int, double等）而不是文本格式(string)存储已经可以减少磁盘空间占用，你主要关心的应该是如何从td文件中**快速**提取某段时间的数据

### 要求

- 请编写一个c++程序，可以
	- 将csv文件转换成td文件
		-  e.g. ```./tdb -c -o db/example.db csv/example.csv```
	- 将td文件转换成csv文件
		- e.g. ```./tdb -d -o csv/example.csv db/example.db```
	- **快速**从td文件里取出某一段时间的tickdata数据
		- e.g. ```./tdb -s -f "2022-06-01 09:45:32" -t "2022-06-01 10:05:21" db/example.db```
  
- 需要提交的内容应包括
	- 源代码
	- Makefile/CMakeLists.txt等工程文件
  
- 程序应可编译可运行，并且注意在工程中各类文件的组织方式

## test-2 : 数据库操作界面

### 背景

delta基金公司后台员工发现，在数据库中添加合约时，需要改动不止一张表。同时他们非常粗心，经常忘记修改其中的某一张表。因此他们想请你设计一个基于qt的应用程序，在每次添加合约时同时修改所有相关的表

### 要求

- 编写的一个基于PyQt的带有图形界面的Python程序
	- 可以在界面上输入待添加的合约信息
	- 点击某个按钮，即可将信息更新到Instrument表和Fee表
  
- Instrument表的列
	- InstrumentId(Char(16))
	- Exchange(Char(8))
	- PointValue(double)
	- Currency(Char(8))
  
- Fee表的列
	- InstrumentID(Char(16))
	- FeeBps(double)
	- FeeQty(double)
  
- 需要提交的内容包括
	- python代码
	- 生成Instrument表和Fee表的sql文件

- 程序应该可运行，数据库为mysql/mariadb，注意主键和约束的建立
  
