# 复习题
### 第一题
#### 
```C++
第一种形式,两个if是独立的,无论第一个if是否执行成功都会再执行第二个if
而第二种形式,只有在第一个if执行失败的时候才会执行后续的else if
```
### 第二题
```C++
会发生错误,因为++ch是自增运算符
而ch+1不会改变ch的值
```

### 第三题
```C++
给的这段代码有点问题?
if的括号里面是=而不是==?
逻辑也有点问题,就算改成==了,结果也很是奇怪

结果:
HHii!!
SSeenndd ct1=4243321,ct2 = 7602052
```
### 第四题
```C++
// a. weight大于或等于115，但小于125
(weight >= 115) && (weight < 125)

// b. ch为q或Q
(ch == 'q') || (ch == 'Q')

// c. x为偶数，但不是26
(x % 2 == 0) && (x != 26)

// d. x为偶数，但不是26的倍数
(x % 2 == 0) && (x % 26 != 0)

// e. donation为1000-2000或guest为1
((donation >= 1000) && (donation <= 2000)) || (guest == 1)

// f. ch是小写字母或大写字母
((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z'))
```
### 第五题
```C++
不一定,因为x可以表示任何类型的变量,而!!x仅为布尔类型的变量
```
### 第六题
```C++
x >= 0 ? x : -x
```
### 第七题
```C++
switch (choice) {
        case 'A':
            a_grade++;
            break;
        case 'B':
            b_grade++;
            break;
        case 'C':
            c_grade++;
            break;
        case 'D':
            d_grade++;
            break;
        default:
            f_grade++;
            break;
    }
```
### 第八题
```C++
灵活,易于维护,便于理解
```
### 第九题
```C++
int line = 0;
char ch;
bool isQuit = false;
while (cin.get(ch) && !isQuit)
{
    if (ch == 'Q')
    {
        isQuit = true;
    }
    else if (ch == '\n')
    {
        line++;
    }
}
```


<br>
<br>
<br>
<br>
<br>

####  2025/1/14