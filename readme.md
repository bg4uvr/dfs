
C++ 数独解算（回溯法）

参考网友的代码，进行了一些修改及完善，分别在windows及linux下测试运行正常，解算 号称世界最难的数独：
800000000
003600000
070090200
050007000
000045700
000100300
001000068
008500010
090000400

用时不到1秒。

结果为： 
8 1 2 4 5 3 6 7 9
9 4 3 6 7 2 1 8 5
5 7 6 8 9 1 2 4 3
3 5 4 2 6 7 8 9 1
1 8 9 3 4 5 7 2 6
2 6 7 1 8 9 3 5 4
7 2 1 9 3 4 5 6 8
4 3 8 5 2 6 9 1 7
6 9 5 7 1 8 4 3 2

本题迭代运算总次数: 26782

bg4uvr 2021.2.23

参考文章：
[https://blog.csdn.net/qq_42948504/article/details/82255456](https://blog.csdn.net/qq_42948504/article/details/82255456)

本人修改完善后的代码（适合学习编程的新手阅读）

[https://gitee.com/bg4uvr/dfs](https://gitee.com/bg4uvr/dfs)
[https://github.com/bg4uvr/dfs](https://github.com/bg4uvr/dfs)
