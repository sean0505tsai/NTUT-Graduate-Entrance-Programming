# 114北科資工所程式設計參考解答

使用 GitHub Copilot 輔助完成解答，並由人工校正。

## 目錄

- [114北科資工所程式設計參考解答](#114北科資工所程式設計參考解答)
  - [目錄](#目錄)
  - [Problem 1](#problem-1)
    - [1-1](#1-1)
    - [1-2](#1-2)
  - [Problem 2](#problem-2)
    - [2-1](#2-1)
    - [2-2](#2-2)
    - [2-3](#2-3)
    - [2-4](#2-4)
    - [2-5](#2-5)
    - [2-6](#2-6)
    - [2-7 \& 2-8](#2-7--2-8)
      - [2-7](#2-7)
      - [2-8](#2-8)
  - [Problem 3](#problem-3)
  - [Problem 4](#problem-4)
  - [Problem 5](#problem-5)

## Problem 1

### 1-1

### 1-2

## Problem 2

- 2-1: `&& buf[i] <= 'Z'`
- 2-2: `'A'`
- 2-3: `total+`
- 2-4: `+i`
- 2-5: `-`
- 2-6: `4`
- 2-7: `-1, 0`
- 2-8: `1, 0`

### 2-1

```c
if('A' <= buf[i] && buf[i] <= 'Z')
                 ^^^^^^^^^^^^^^^^
```

ASCII碼中，'A'是65，'Z'是90，所以如果buf[i]在65到90之間，就表示buf[i]是大寫字母。

### 2-2

```c
buf[i] = 'a' + buf[i] - 'A'
                      ^^^^^^
```

'a'是97，'A'是65，所以buf[i] - 'A'會得到buf[i]在大寫字母中的位置，再加上'a'就會得到對應的小寫字母。

### 2-3

```c
if(data[i] == c) total+=1;
                 ^^^^^^
```

如果data[i]等於c，表示在data陣列中找到了c這個字元，所以total加1。

### 2-4

```c
alpha_table[i] = alpha_count(buf, ('a'+ i));
                                      ^^^
```

`('a' + i)` 會得到對應的小寫字母，例如`i=0`時是`'a'`，`i=1`時是`'b'`，以此類推。`alpha_count`函式會計算`buf`陣列中該字母出現的次數，並將結果存入`alpha_table`陣列中對應的位置。

### 2-5

```c
int index = specific_c - 'a';
                      ^^^
```

`specific_c - 'a'` 會得到 `specific_c`在小寫字母中的位置，例如 `specific_c` 是 `'a'` 時，`index` 會是0；`specific_c` 是 `'b'` 時，`index` 會是1，以此類推。接著再從 `alpha_table` 陣列查詢對應位置(該字母)的值，就可以得到`specific_c` 在 `buf` 陣列中出現的次數。

### 2-6

```c
printf("%d\n", alpha_count("book_is_good", 'o'));
```

- Ans: `4`

`alpha_count("book_is_good", 'o')` 會計算字串 "book_is_good" 中 'o' 出現的次數。字串中 'o' 出現了4次，所以結果是4。

### 2-7 & 2-8

```c
int comp(char* s, char* d){
    if((*s=='\0')&&(*d=='\0')) return 0;      // 兩字元皆為空字元，表示兩字串相等
    else if ((*s=='\0')||(*s<*d)) return -1;  // s < d 或s為空字元
    else if ((*d=='\0')||(*s>*d)) return 1;   // s > d 或d為空字元
    else return comp(s+1,d+1);                // 繼續比較下一個字元
}
```

#### 2-7

```c
printf("%d, %d\n", comp("FO", "FOO"), comp("FO", "FO")); 
```
- Ans: `-1, 0`  

`FO` 與 `FOO` 比較時前兩個字元相同，但比較到第三個字元時，`FO` 已經結束了（空字元），所以 `*s == '\0'` 條件成立，return -1。  

`FO` 與 `FO` 完全相同，所以比較到最後兩個字元都是空字元，return 0。

#### 2-8

```c
printf("%d, %d\n", comp("FOOD", "FOOAD"), comp("", ""));
```

- Ans: `1, 0`

`FOOD` 與 `FOOAD` 前3個字元相同，但比較到第四個字元時，`D` 大於 `A`，所以 `*s > *d` 條件成立，return 1。

## Problem 3

- 3-1: `struct`
- 3-2: 
- 3-3:
- 3-4:
- 3-5:
- 3-6:
- 3-7:
- 3-8:
- 3-9:

## Problem 4

## Problem 5
