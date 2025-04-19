# what is c++
## ・my first subject about c++<br>・I'll write down what I couldn't figure out.

## what is vector
### vector is an array of variable size
```
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v;          // int型のvectorを宣言（空）
    v.push_back(10);             // 10を追加
    v.push_back(20);             // 20を追加

    std::cout << "サイズ: " << v.size() << std::endl;     // → 2
    std::cout << "1つ目の要素: " << v[0] << std::endl;    // → 10

    return 0;
}
```

## what is pair
## pair can handle two different type at the same time.
```
std::pair<int, std::string> myPair(42, "hello");
```

```
accounts_t				accounts( amounts, amounts + amounts_size );
```

|式 | 意味|
|----|----|
|amounts | 配列の先頭（&amounts[0]）|
|amounts + amounts_size | 配列の末尾（終端）|
|std::vector<Account>( amounts, amounts + amounts_size ) | Account を amounts[] の値から順に作って vector に入れる|

## <br>
## what is iterator?
## ✅ イテレータ = ポインタに似たもの
### ・iterator は コンテナ（vectorなど）の要素を1つずつたどるための道具
```
for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << std::endl;
}
//*itで要素にアクセス
```

## what is for_each
### Calls the specified functions sequentially for all elements in the range
```
std::for_each(開始イテレータ, 終了イテレータ, 実行する関数);
```