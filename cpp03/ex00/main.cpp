#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Taro");

    std::cout << "\n--- 攻撃してみる ---" << std::endl;
    a.attack("TargetA");

    std::cout << "\n--- ダメージを受けてみる ---" << std::endl;
    a.takeDamage(4);

    std::cout << "\n--- 回復してみる ---" << std::endl;
    a.beRepaired(3);

    std::cout << "\n--- 多量のダメージを受けてみる（HPが0になる） ---" << std::endl;
    a.takeDamage(15);

    std::cout << "\n--- HPが0の状態で攻撃＆回復してみる ---" << std::endl;
    a.attack("TargetB");
    a.beRepaired(5);

    std::cout << "\n--- エネルギー切れになるまで攻撃してみる ---" << std::endl;
    for (int i = 0; i < 11; ++i) {
        a.attack("Dummy");
    }

    return 0;
}
