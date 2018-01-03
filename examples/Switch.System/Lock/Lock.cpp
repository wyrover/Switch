#include <Switch/Switch>

using namespace System;
using namespace System::Threading;

namespace Examples {
  class Account : public object {
  public:
    explicit Account(int initial) : balance(initial) {}

    int Withdraw(int amount) {
      // This condition never is true unless the lock statement is commented out.
      if (this->balance < 0)
        throw Exception("Negative Balance", caller_);

      // Comment out the next line to see the effect of leaving out the lock keyword.
      lock_(this->lock) {
        if (this->balance >= amount) {
          Console::WriteLine("Balance before Withdrawal :  {0}", this->balance);
          Console::WriteLine("Amount to Withdraw        : -{0}", amount);
          this->balance = this->balance - amount;
          Console::WriteLine("Balance after Withdrawal  :  {0}", this->balance);
          return amount;
        }
      }
      return 0;
    }

    void DoTransactions() {
      for (int i = 0; i < 100; i++)
        Withdraw(this->random.Next(1, 100));
    }

  private:
    Object lock;
    int balance;
    Random random;
  };

  class Program {
  public:
    static void Main() {
      Array<Thread> threads(10);
      Account account(1000);
      for (int i = 0; i < 10; i++) {
        threads[i] = Thread(ThreadStart(account, &Account::DoTransactions));
        threads[i].Start();
      }
    }
  };
}

startup_(Examples::Program);
