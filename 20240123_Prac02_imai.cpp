/*
BankAccount�N���X�ɂ́A�����̏��L�҂̖��O�ƌ����c�����i�[���邽�߂̃v���C�x�[�g�����o�ϐ�������܂��B
�N���X�ɂ́A�ȉ��̋@�\��񋟂���p�u���b�N���\�b�h���K�v�ł��B
�R���X�g���N�^: �����̏��L�҂̖��O���󂯎��A�����c�����[���ɏ��������܂��B
getOwnerName���\�b�h: �����̏��L�҂̖��O��Ԃ��܂��B
getBalance���\�b�h: �����c����Ԃ��܂��B
deposit���\�b�h: �w�肳�ꂽ���z�������ɓ������܂��B
withdraw���\�b�h: �w�肳�ꂽ���z��������������o���܂��B�������A�����o�����z�������c���𒴂��Ă���ꍇ�͈����o�����s��Ȃ��ł��������B
*/
#include<iostream>
#include<string.h>


//BankAccount�N���X
class BankAccout
{
private:
    //�v���C�x�[�g�����o�[�ϐ�
    std::string name;
    double balance;
public:
    //�R���X�g���N�^
    BankAccout(const std::string& owner) : name(owner), balance(0.0) {}
    //�f�X�g���N�^
    ~BankAccout() {}
    //�����̏��L�҂̖��O��Ԃ����\�b�h
    std::string getOwnerName();
    //�����c����Ԃ����\�b�h
    double getBalance();
    //�������郁�\�b�h
    void deposit(double amount);
    //���o�������郁�\�b�h
    void withdraw(double amout);
};

    /// <summary>
    /// �����̏��L�҂̖��O��Ԃ�
    /// </summary>
    /// <returns></returns>
    std::string BankAccout::getOwnerName() {
        return name;
    }
    /// <summary>
    /// �����c����Ԃ�
    /// </summary>
    /// <returns></returns>
    double BankAccout::getBalance() {
        return balance;
    }
    /// <summary>
    /// �������\�b�h
    /// </summary>
    /// <param name="amount"></param>
    void BankAccout::deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            std::cout << amount << "�~�������܂����B\n";
        }
        else
        {
            std::cout << "�����ɕs��������܂��B\n";
        }
    }
    /// <summary>
    /// ���o���\�b�h
    /// </summary>
    /// <param name="amout"></param>
    void BankAccout::withdraw(double amout) {
        if (amout > 0 && amout <= balance)
        {
            balance -= amout;
            std::cout << amout << "�~�o�����܂����B\n";
        }
        else
        {
            std::cout << "�o���ɕs��������܂��B\n";
        }
    }
int main(void)
{
    //�ϐ��錾
    std::string Name;
    double Money;
    int choice = 0;
    std::cout << "�����̏��L�Җ�����͂��Ă��������B\n";
    std::cin >> Name;

    //�o���N�A�J�E���g�N���X�C���X�^���X��
    BankAccout banlaccout(Name);

    //�����̏��L�Җ��\��
    std::cout << banlaccout.getOwnerName() << "\n";

    while (true)
    {
        std::cout << "�����I��ł��������B\n";
        std::cout << "0:�c���ؖ�\n1:����\n2:�o��\n3:�I��\n";
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            std::cout << "�c���́A" << banlaccout.getBalance() << "�~�ł�\n";
            break;
        case 1:
            std::cout << "����������z����͂��Ă��������B\n";
            std::cin >> Money;
            banlaccout.deposit(Money);
            std::cout << "�c��" << banlaccout.getBalance() << "�~�ł�\n";
            break;
        case 2:
            std::cout << "�o��������z����͂��Ă��������B\n";
            std::cin >> Money;
            banlaccout.withdraw(Money);
            std::cout << "�c��" << banlaccout.getBalance() << "�~�ł�\n";
            break;
        case 3:
            std::cout << "�I�����܂��B\n";
            break;

        default:
            std::cout << "���͂Ɍ�肪����܂��B�ēx���͂��Ă��������B\n";
            break;
        }

        if (choice == 3)
        {
            break;
        }

    }


    return 0;
}