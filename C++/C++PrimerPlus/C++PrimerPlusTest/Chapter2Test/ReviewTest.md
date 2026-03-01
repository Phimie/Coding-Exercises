# 复习题
### 1．C++程序的模块叫什么?
    一组函数

### 2．下面的预处理器编译指令是做什么用的？

![图片](Img/1.png)

    用来包含iostream文件

### 3．下面的语句是做什么用的？

![图片](Img/2.png)

    使用std命名空间
### 4．什么语句可以用来打印短语“Hello，world”，然后开始新的一行？
```C++
std::cout << "Hello,world"<<std::endl;
```
### 5．什么语句可以用来创建名为cheeses的整数变量？
```C++
int cheeses;
```
### 6．什么语句可以用来将值32赋给变量cheeses？
```C++
cheeses = 32
```
### 7．什么语句可以用来将从键盘输入的值读入变量cheeses中？
```C++
std::cin >> cheeses;
```
### 8．什么语句可以用来打印“We have X varieties of cheese,”，其中X为变量cheeses的当前值。
```C++
std::cout << "We have" << cheeses << "varieties of cheese" << std::endl;
```
### 9．下面的函数原型指出了关于函数的哪些信息？

![图片](Img/3.png)
<br>
```C++
第一个:函数的返回为整形,参数的类型为double
第二个:函数的返回值为空,参数的类型是int
第三个:函数的返回为int,参数为空
```
<br>

### 10．定义函数时，在什么情况下不必使用关键字return？
    当函数的类型是void时
### 11．假设您编写的main( )函数包含如下代码：

![图片](Img/4.png)

### 而编译器指出cout是一个未知标识符。导致这种问题的原因很可能是什么？指出3种修复这种问题的方法。

```C++
方法一:使用using std::cout;
方法二:使用using namespace std;
方法三:使用cout时,前面加上std::
```