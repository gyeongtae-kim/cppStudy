/*
// Banking System Ver0.2
// author : gtkim
// 내용 :: OOP단계별 프로젝트
//
// git 참고 :http://egloos.zum.com/riniblog/v/1024993
*/
#include <iostream>
#include <cstring>

using namespace std;

class Account
{
private:
	int accID;
	int money;
	char * name;
public:
	Account(int id,int depositMoney) : accID(id), money(depositMoney)
	{

	}

};

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum {MAKE,DEPOSIT,WITHDRAW,SHOW,EXIT};
int state;
int main(void)
{
	while(1){
		ShowMenu();
		cin>>state;
		switch(state)
		{
		case MAKE: MakeAccount();
			break;
		case DEPOSIT:DepositMoney();
			break;
		case WITHDRAW: WithdrawMoney();
			break;
		case SHOW: ShowAllAccInfo();
			break;
		}
		if(state>EXIT) break;
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
	cout<<"[Make Account]"<<endl;
	cout<<"Account ID: ";
	cin>> id;
	//Account->accID= id;
}
void DepositMoney(void)
{

}
void WithdrawMoney(void)
{

}
void ShowAllAccInfo(void)
{

}