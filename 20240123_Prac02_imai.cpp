/*
BankAccountクラスには、口座の所有者の名前と口座残高を格納するためのプライベートメンバ変数があります。
クラスには、以下の機能を提供するパブリックメソッドが必要です。
コンストラクタ: 口座の所有者の名前を受け取り、口座残高をゼロに初期化します。
getOwnerNameメソッド: 口座の所有者の名前を返します。
getBalanceメソッド: 口座残高を返します。
depositメソッド: 指定された金額を口座に入金します。
withdrawメソッド: 指定された金額を口座から引き出します。ただし、引き出す金額が口座残高を超えている場合は引き出しを行わないでください。
*/
#include<iostream>
#include<string.h>


//BankAccountクラス
class BankAccout
{
private:
    //プライベートメンバー変数
    std::string name;
    double balance;
public:
    //コンストラクタ
    BankAccout(const std::string& owner) : name(owner), balance(0.0) {}
    //デストラクタ
    ~BankAccout() {}
    //口座の所有者の名前を返すメソッド
    std::string getOwnerName();
    //口座残高を返すメソッド
    double getBalance();
    //入金するメソッド
    void deposit(double amount);
    //引出しをするメソッド
    void withdraw(double amout);
};

    /// <summary>
    /// 口座の所有者の名前を返す
    /// </summary>
    /// <returns></returns>
    std::string BankAccout::getOwnerName() {
        return name;
    }
    /// <summary>
    /// 口座残高を返す
    /// </summary>
    /// <returns></returns>
    double BankAccout::getBalance() {
        return balance;
    }
    /// <summary>
    /// 入金メソッド
    /// </summary>
    /// <param name="amount"></param>
    void BankAccout::deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            std::cout << amount << "円入金しました。\n";
        }
        else
        {
            std::cout << "入金に不正があります。\n";
        }
    }
    /// <summary>
    /// 引出メソッド
    /// </summary>
    /// <param name="amout"></param>
    void BankAccout::withdraw(double amout) {
        if (amout > 0 && amout <= balance)
        {
            balance -= amout;
            std::cout << amout << "円出金しました。\n";
        }
        else
        {
            std::cout << "出金に不正があります。\n";
        }
    }
int main(void)
{
    //変数宣言
    std::string Name;
    double Money;
    int choice = 0;
    std::cout << "口座の所有者名を入力してください。\n";
    std::cin >> Name;

    //バンクアカウントクラスインスタンス化
    BankAccout banlaccout(Name);

    //口座の所有者名表示
    std::cout << banlaccout.getOwnerName() << "\n";

    while (true)
    {
        std::cout << "操作を選んでください。\n";
        std::cout << "0:残高証明\n1:入金\n2:出金\n3:終了\n";
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            std::cout << "残高は、" << banlaccout.getBalance() << "円です\n";
            break;
        case 1:
            std::cout << "入金する金額を入力してください。\n";
            std::cin >> Money;
            banlaccout.deposit(Money);
            std::cout << "残高" << banlaccout.getBalance() << "円です\n";
            break;
        case 2:
            std::cout << "出金する金額を入力してください。\n";
            std::cin >> Money;
            banlaccout.withdraw(Money);
            std::cout << "残高" << banlaccout.getBalance() << "円です\n";
            break;
        case 3:
            std::cout << "終了します。\n";
            break;

        default:
            std::cout << "入力に誤りがあります。再度入力してください。\n";
            break;
        }

        if (choice == 3)
        {
            break;
        }

    }


    return 0;
}