# CPP05

thisポインタとは
```
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}
```
thisはメンバ関数内で使える特別なポインタで、その関数を呼び出しているオブジェクト自身のアドレス  
を指している
```
Bureaucrat a("Alice", 10);
Bureaucrat b("Bob", 42);
a = b;
```
この時、``` a.operator=(b)```が呼ばれる
this->aのアドレス
&other->bのアドレス

## ```std::string &Bureaucrat::getName()```の意味
const std::string &とは  
戻り値が参照という意味
std::stringを直接返すのではなく、オブジェクト内部の文字列への参照を返している。
値をコピーしないため、高速(std::stringは重い)

throwとは例外をなげるためのキーワード
throwされた時点で、関数の処理は中断される
例外は```try/catch```ブロックで捕まえる必要がある

whatとは例外に関する説明文を返す関数
```virtual const char *what() const throw(); //これは例外を投げないことを宣言している```

## クラスの中のクラス
nested classと呼ばれる
```
class Outer {
 public:
  class Inner {
   public:
    void sayHello();
  };
};
```
ネストされたクラスは外側のクラスとは独立したスコープを持つ
外側のクラスのprivateなメンバに直接アクセスできない

クラスの中のクラスのpublicはどこからでもアクセスできる

なぜネストクラスにするのか
```
class Bureaucrat {
  class GradeTooHighException : public std::exception { ... };
};
```
という形で、Bureaucratにだけ関係する例外を内部に閉じ込めている