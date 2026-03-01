# 2025/4/18
##### 关于冒泡排序
```C++
//冒泡排序优化
bool swapped = false;
    //内循环
if (!swapped) break; //两行代码体现算法及时终止思想
```

##### 关于桶排序
```C++
//桶排序优化
//原代码:
for (int j = 0; j < Bucket[i]; ++j) // 每次循环都要判断j

//优化后:
int count = Bucket[i];
while (count-- > 0) //通过while避免了冗余操作
    {
        std::cout << i << " ";
    }

//原理​​：将for循环改为while递减，减少条件判断次数
```

```C++

```
