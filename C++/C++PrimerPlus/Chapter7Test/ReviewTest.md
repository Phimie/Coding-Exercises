# 复习题
### 第一题
#### 
```C++
声明,定义,调用
```
### 第二题
```C++
// a. igor()没有参数，且没有返回值
void igor();

// b. tofu()接受一个int参数，并返回一个float
float tofu(int param);

// c. mpg()接受两个double参数，并返回一个double
double mpg(double param1, double param2);

// d. summation()将long数组名和数组长度作为参数，并返回一个long值
long summation(long arr[], int length);

// e. doctor()接受一个字符串参数（不能修改该字符串），并返回一个double值
double doctor(const std::string& str);

// f. ofcourse()将boss结构作为参数，不返回值
void ofcourse(struct boss param);

// g. plot()将map结构的指针作为参数，并返回一个字符串
std::string plot(struct map* ptr);
```

### 第三题
```C++
void setArrayValues(int arr[], int length, int value);
```
### 第四题
```C++
void setArrayValues(int* start, int* end, int value) {
    for (int* ptr = start; ptr != end; ++ptr) {
        *ptr = value;
    }
}
```
### 第五题
```C++
double findMax(const double arr[], int length) {
    if (length <= 0) {
        throw std::invalid_argument("Array length must be positive.");
    }
    double max_value = std::numeric_limits<double>::lowest();
    for (int i = 0; i < length; ++i) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    return max_value;
}

```
### 第六题
```C++
因为基本类型的函数参数本来就不会被函数内部修改,const定义是为了定义一个不会被修改的值
```
### 第七题
```C++
字符数组,字符指针,字符串字面量
```
### 第八题
```C++
int replace(char* str, char c1, char c2) {
    if (!str) { 
        return 0;
    }
    int count = 0; 
    char* ptr = str;

    while (*ptr != '\0') { 
        if (*ptr == c1) { 
            *ptr = c2;
            count++;
        }
        ptr++;
    }
    return count;
}
```
### 第九题
```C++
字符串字面量
```

### 第十题
```C++
地址传递效率高,但是代码复杂性增加,值传递简单直观但是效率较低
```
### 第十一题
```C++
int judge(int (*func)(const char*));
```
### 第十二题
```C++
void displayApplicant(const Applicant& app) {
    std::cout << "Applicant Name: " << app.name << std::endl;
    std::cout << "Credit Ratings:\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "Rating " << (i + 1) << ": " << app.credit_ratings[i] << std::endl;
    }
}

void displayApplicant(const Applicant* app) {
    std::cout << "Applicant Name: " << app->name << std::endl;
    std::cout << "Credit Ratings:\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "Rating " << (i + 1) << ": " << app->credit_ratings[i] << std::endl;
    }
}
```
### 第十三题
```C++
#include <iostream>

struct Applicant {
    char name[30];
    int credit_ratings[3];
};

void f1(Applicant* a);
const char* f2(const Applicant* a1, const Applicant* a2);

typedef void (*F1)(Applicant*);
typedef const char* (*F2)(const Applicant*, const Applicant*);

int main() {
    F1 p1 = f1;
    F2 p2 = f2;

    F1 a[5];
    F2* b = new F2[10];

    for (int i = 0; i < 5; ++i) {
        a[i] = f1;
    }

    for (int i = 0; i < 10; ++i) {
        b[i] = f2;
    }

    delete[] b;

    return 0;
}
```

<br>
<br>
<br>
<br>
<br>

####  2025/2/16