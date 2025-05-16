CPPで学んだこと

?なぜインスタンス化できないようにするの？
✅理由１：意味のない使用を防ぐ
AAnimal a;           // ❌ 「動物だけ」ってなんの動物？意味が曖昧
AAnimal* a = new AAnimal(); // ❌ 何の鳴き声を出すのか分からない

?virtualをつける意味とは？
✅基底クラスでポインタを扱う時に、デストラクタにvirtualがないと、**派生クラスのデストラクタが呼ばれずメモリリークする可能性**があるため

？オーバーライドとは？
・オーバーライドとは、**基底クラスの仮想関数を、派生クラスで独自の動作に置き換えること**

🔧具体例：
class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Animal sound" << std::endl;
    }
};
「どの動物でも鳴き声を出せる」という抽象的な動作。
↓これを継承したクラスでオーバーライド
class Dog : public Animal {
public:
    void makeSound() const { // ← オーバーライド！
        std::cout << "Woof!" << std::endl;
    }
};
