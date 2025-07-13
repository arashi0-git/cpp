# cpp07で学んだこと
## template <class T>
型を引数として受け取れるテンプレート関数
## template <class T, class F>
```
void iter(T *address, size_t length, F func) {
    for (size_t i = 0; i < length; i++) {
        func(address[i]);
    }
}
```
```T```では```int```や```string```などの型を柔軟に扱う
```F```では```const```や```non-const```などの関数の引数としてあたえる型を柔軟にきめる
複数のtemplateを使用可能

```
template <class T>
T &operator[](unsigned int index);

template <class T>
const T &operator[](unsigned int index) const;
```
の違い
## non-constの場合
```
Array<int> arr(5);
arr[0] = 30;
```
```Array<T>```オブジェクトから書き換え可能要素の取得が可能

## constの場合
```
const Array<int> arr(5);
std::cout << arr[0]; // OK!
arr[0] = 42; //コンパイルエラー
```
constとnon-constを２つ用意することで変更、出力両方可能
