#include <iostream>
#include <stdexcept>
#include <exception>
using namespace std;


class Exception : public exception {
private:
    const char* message;

public:
    Exception(const char* msg)
        : message(msg)
    {}

    const char* what() const throw()
    {
        return message;
    }
};



class BankAccount
{
	double balance;
	string AccountNumber;
	
	public:
		BankAccount(double balance, string AccountNumber): balance(balance), AccountNumber(AccountNumber) {}
		
		void setBalance(double balance)
		{
			this->balance = balance;
		}
		void setAccountNo(string no)
		{
			AccountNumber = no;
		}
		
		double getBalance()
		{
			return balance;
		}
		string getAccount()
		{
			return AccountNumber;
		}
		
		
		void deposit(double amount)
		{
			try
			{
				if (amount <= 0)
				{
					throw Exception("Invalid Amount is Entered");
				}
			
			balance = balance+amount;
			cout<<"Balance after Deposit: "<<balance<<endl;
		}
//		catch(double x)
//		{
//			cout<<"Invalid Amount"<<endl;
//		}

		catch(Exception& e)
			{
			cout<<e.what()<<endl;
			}
		}
		
		
		void withdraw(double amount)
		{
			try 
			{
				double newBalance = balance - amount;
				if (amount <= 0)
				{
					throw Exception("Invalid Amount is Entered");
				}
				if (newBalance <= 0)
				{
					throw Exception("Insufficient Balance in the Account");
				}
				balance = newBalance;
				cout<<"Balance after Withdrawing: "<<balance<<endl;
			}
		
		

			catch(Exception& e)
			{
			cout<<e.what()<<endl;
			}
		}
		
		
		void transfer(BankAccount& other, double amount)
		{
			try
			{
				if (amount<=0)
				{
					throw Exception("Amount Entered is Invalid");
				}
				double newBalance = balance - amount;
				if (newBalance <=0)
				{
					throw Exception("Insufficient Funds in the Account");
				}
				balance = newBalance;
				other.balance = other.balance + amount;
				cout<<"Amount Successfully Transferred"<<endl;
				cout<<"Transaction Details: "<<endl;
				cout<<"Current Balance: "<<balance<<"\tOther's Account Balance: "<<other.balance<<endl;
			}
			catch(double x)
			{
				cout<<"Transaction Failed: Insufficient Balance or Invalid Amount"<<endl;
			}

			catch(Exception& e)
			{
			cout<<e.what()<<endl;
			
			}
		}
		
		void checkBalance()
		{
			cout<<"Account Number: "<<AccountNumber<<"\tAccount Balance: "<<balance<<endl;
		}
	
};



int main()
{
	BankAccount acc1(5000.0, "101");
	acc1.deposit(500);
	acc1.deposit(-500);
	acc1.withdraw(100);
	acc1.withdraw(10000);
	BankAccount acc2(4500.0, "102");
	acc1.transfer(acc2, 300);
	acc1.transfer(acc2, -10);
	acc1.transfer(acc2, 6000);
	
	
}
