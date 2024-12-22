#include <iostream>

using namespace std;

class BankAccount 
{
	int accountNumber;
	string accountHolder;
	double balance;
	
public:
	static int totalAccounts;
	
	
	BankAccount()
	{
		accountNumber = 0;
		accountHolder = " ";
		balance = 0.0;
		totalAccounts++;
	}
	
	BankAccount(int accno, string accholder, double initialBal)
	{
		accountNumber = accno;
		accountHolder = accholder;
		balance = initialBal;
		totalAccounts++;

	}
	
	~BankAccount()
	{
		cout<<"Accounts are being destroyed"<<endl;
		while (!totalAccounts)
		{
			totalAccounts--;
		}
		
	}
	
	void print()
	{
		cout<<"Account Number: "<<accountNumber<<endl;
		cout<<"Account Holder: "<<accountHolder<<endl;
		cout<<"Account Balance: "<<balance<<endl;
	//	cout<<"Total Accounts: "<<count()<<endl;
		cout<<endl;
	}
	
	static int count()
	{
		return totalAccounts;
	}
	
	BankAccount operator +(double newBal)
	{
		this->balance = this->balance + newBal;
		return *this;
	}
	
	BankAccount operator -(double newBal)
	{
		this->balance = this->balance - newBal;;
		return *this;
	}
	
	BankAccount operator +=(double amount)
	{
		this->balance += amount;
		return *this;
	}
	
	BankAccount operator -=(double amount)
	{
		this->balance -= amount;
		return* this;
	}
	
	bool operator <(BankAccount& other)
	{
		return (this->balance < other.balance);
	}
	
	bool operator >(BankAccount& other)
	{
		return (this->balance > other.balance);		
	}
	
	bool operator ==(BankAccount& other)
	{
		return (this->accountNumber==other.accountNumber);
	}
	
	

};

int BankAccount::totalAccounts=0;

int main()
{
	BankAccount acc1;
	BankAccount acc2(1, "Ali", 350.0);
	acc1.print();
	acc2.print();
	
	BankAccount acc3(2, "AAA", 100.0);
	cout<<"Inital Values of Account:"<<endl;
	acc3.print();
	cout<<"Balance after adding 200:"<<endl;
	acc3+200.0;
	acc3.print();
	cout<<"Balance after Substracting 50:"<<endl;
	acc3-50;
	acc3.print();
	
	BankAccount acc4(3, "Ahmad", 267.8);
	acc4.print();
	BankAccount acc5(4, "Daud", 250.5);
	acc5.print();
	bool var = acc4<acc5;
	cout<<"Is balance of acc4 < acc5: "<<var<<endl;
	
	bool var2 = acc4>acc5;
	cout<<"Is balance of acc4 > acc5: "<<var2<<endl;
	
	bool var3 = acc4==acc5;
	cout<<"Is Account Number of acc4 == acc5: "<<var3<<endl;
	bool var4 = acc1==acc3;
	cout<<"Is Account Number of acc1 == acc3: "<<var4<<endl;
	
	
	cout<<"Total Accounts: "<<BankAccount::count()<<endl;
//	system("pause");
}
