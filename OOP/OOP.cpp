/*
// Banking System Ver0.2
// author : gtkim
// 내용 :: OOP단계별 프로젝트
*/
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN=20;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum {MAKE=1,DEPOSIT,WITHDRAW,SHOW,EXIT};


class Account
{
private:
	int accID;
	int balance;
	char *cusName;

public:
	Account(int id, int money, char *name)
		:accID(id),balance(money)
	{
		int len = strlen(name)+1;
		cusName = new char[len];
		strcpy(cusName,name);
	}
	int GetAccID()	{return accID;}
	int GetBalance(){return balance;}
	void Deposit(int money)	{balance+=money;}
	void Withdraw(int money)
	{
		if( balance < money)
		{
			cout<<"잔액부족"<<endl;
		}

		balance-=money;
	}
	void ShowInfo()
	{
		cout<<"Account ID: "<<accID<<endl;
		cout<<"Name: "<<cusName<<endl;
		cout<<"Balance: "<<balance<<endl;
	}
	
	~Account()
	{
		delete []cusName;
	}
	
};

Account *accArr[100];
int accNum=0;

int main(void)
{
	int choice;
	while(1)
	{
		ShowMenu();
		cin>>choice;

		switch(choice)
		{
		case MAKE: MakeAccount();
			break;
		case DEPOSIT:DepositMoney();
			break;
		case WITHDRAW: WithdrawMoney();
			break;
		case SHOW: ShowAllAccInfo();
			break;
		case EXIT:

			return 0;
		default:
			cout<<"Illegal selection.."<<endl;
		}
	}
	return 0;
}

void ShowMenu(void)
{
	cout<<"-----Menu-----"<<endl;
	cout<<"1.Make Account"<<endl;
	cout<<"2.Deposit Money"<<endl;
	cout<<"3.Withraw Money"<<endl;
	cout<<"4.Show All Account"<<endl;
	cout<<"5.Exit"<<endl;
	cout<<"Select: ";
}
void MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	cout<<"[Make Account]"<<endl;
	cout<<"Account ID: ";	cin>> id;
	cout<<"Name: "; cin>>name;
	cout<<"Deposit: ";	cin>>balance;

	accArr[accNum++]= new Account(id,balance,name);
}
void DepositMoney(void)
{
	int id;
	int money;
	int num;
	cout<<"Account ID: "; cin>>id;
	for(int i=0;i<accNum;i++)
	{
		if(accArr[i]->GetAccID()==id)
			num=i;
	}
	cout<<"Deposit: ";cin>>money;
	accArr[num]->Deposit(money);
	cout<<"Balanvce: "<<accArr[num]->GetBalance()<<endl;	
}
void WithdrawMoney(void)
{
	int id;
	int money;
	int num;
	cout<<"Account ID: "; cin>>id;
	for(int i=0;i<accNum;i++)
	{
		if(accArr[i]->GetAccID()==id)
			num=i;
	}
	cout<<"Withdraw: ";cin>>money;
	accArr[num]->Withdraw(money);
	cout<<accArr[num]->GetBalance()<<endl;	
	
}
void ShowAllAccInfo(void)
{
	for(int i=0;i<accNum;i++)
	{
		cout<<"-----"<<i+1<<"-----"<<endl;
		accArr[i]->ShowInfo();
		cout<<"-----------"<<endl;
	}
		
}