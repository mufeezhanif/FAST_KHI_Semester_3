#include <iostream>

using namespace std;

class BankAccount
{
    float balance;
public:
    BankAccount()
    {
        cout << balance<<endl;
    }
    BankAccount(float balance)
    {
        this->balance = balance;
        cout << balance <<endl;
    }

    BankAccount(const BankAccount &obj)
    {
        this->balance = obj.balance;
        balance -= 200;
        cout << "Account 3:" << balance <<endl;
        cout << "Account 2:" << obj.balance <<endl;
    }
};
int main()
{
    BankAccount account1;
    BankAccount account2(1000);
    BankAccount account3 = account2;
}