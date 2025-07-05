# CPP06で学んだこと
## ヘッダーファイルでの```static```とcppファイルでの```static```は違う意味
ヘッダーファイル内
```
class Test {
    public:
        static void test(...);
};
```
ここでの```static```はこの関数をインスタンスを通さずに呼び出せるという意味
```
Test::test(...); // ok
Test c; c.test; // インスタンス作れないため、エラー
```
cppファイル内
```
static void test(...) {}
```
この関数はこの.cppファイル内でしか使えないことを意味する