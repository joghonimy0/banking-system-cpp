#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount
{
    protected :
    static vector<string> accounts;
    static vector<float> balance;
    static vector<int> accnum;
    static string check;
    static int accs;


    public :
    BankAccount(){}
    
     virtual void newAccount(string owner)=0;
     virtual void deposit(float Amount, int accnumber)=0;
     virtual void withdraw(float Amount, int accnumber)=0;
     void AccDetails(int AccountNumber)
    {
        if(AccountNumber>=accs+1001){cout << "\nThere are no accounts with this number\n";} /////////
        else if(AccountNumber<1001){cout << "\nInvalid account number";}////////////////// validation
        else if(accs>0)
        {
            cout << "Account number : " << to_string(accnum[AccountNumber-1001]) << "\nName : " << accounts[AccountNumber-1001] <<"\nBalance : " << fixed << setprecision(2) <<balance[AccountNumber-1001];

            if(checkType(AccountNumber) == 1)
            {cout << "\nAccount Type : Savings Account\nInterest rate : 5%" << endl;}

            else if(checkType(AccountNumber) == 0)
            {cout << "\nAccount Type : Currents Account\nOverdraft Limit : 200$"<< endl;}
    
        }

        else{cout << "No accounts created";}   
    }
     void AllAcounts()
     {

        cout << "=======ALL BANK ACCOUNTS=======" << endl;
        cout << "===============================" << endl;
        cout << "Total Accounts : "<< accs << endl;
        if(accs<1){cout << "No accounts created"; return;}
        cout << "===============================" << endl;
        for(int c = 0; c < accs; c++)
        {
            cout << "Account number : " << to_string(accnum[c]) << "\nName : " << accounts[c] <<"\nBalance : " << fixed << setprecision(2) << balance[c];

            if(checkType(1001+c) == 1)
            {cout << "\nAccount Type : Savings Account\nInterest rate : 5%" << endl;}

            else if(checkType(1001+c) == 0)
            {cout << "\nAccount Type : Currents Account\nOverdraft Limit : 200$" << endl;}
        }
     }

     int checkType(int accnumber)
     {
        if(accs==0||!(accnumber>1000&&accnumber<accs+1001)){return 2;} // validation
        return check[accnumber-1001]=='s'; 
     }
};
///////////////////////////////////////
    class savings : public BankAccount
    {
        public : 
        savings():BankAccount(){}

    void newAccount(string owner)
    {
        balance.push_back(0);
        accnum.push_back(1001+accs);
        accounts.push_back //inserting account details
        (owner);
        check.push_back('s'); // determining account type

        cout << "Account Created Successfully." << endl << "Your account number is " << accnum[accs] <<  ", deposit money to activate it." << endl <<"===============================" << endl;
        accs++; // account counting
    }

    void deposit(float Amount, int accnumber)
    {
        balance[accnumber-1001]+=(Amount*1.05); 
        cout << "\nTransaction succeed\n";
    }

    void withdraw(float Amount, int accnumber)
    {
        if(balance[accnumber-1001]-Amount<0){cout << "===============================" << "\nYour account balance is insufficient\n===============================\n"; return;}
        balance[accnumber-1001]-=Amount;
        cout << "\nTransaction succeed\n";
    }

    };

////////////////////////////////////////

    class currents : public BankAccount
    {
        public :
        currents():BankAccount(){}

        void newAccount(string owner)
        {
        balance.push_back(0);
        accnum.push_back(1001+accs);
        accounts.push_back //inserting account details
        (owner);
        check.push_back('c'); //determining acc type 
        cout << "\n===============================\nAccount Created Successfully." << endl << "Your account number is " << accnum[accs] <<  ", deposit money to activate it." << endl <<"===============================" << endl;
        accs++;
        }
        void deposit(float Amount, int accnumber)
    {
        balance[accnumber-1001]+=Amount;
        cout << "\nTransaction succeed\n";
    }
    void withdraw(float Amount, int accnumber)
    {
        if(balance[accnumber-1001]-Amount<-200){cout << "===============================" << "\nThis transaction exceeds the overdraft limit\n"; return;}
        balance[accnumber-1001]-=Amount;
        cout << "\nTransaction succeed\n";

    }
    };
     

void Interface()
{
    cout << "\n===============================\n";
    cout << "Welcome to Egypt Bank!\n===============================\n";
    cout << "Choose the number of service :";
    cout << "\n1. Create new account";
    cout << "\n2. Deposit";
    cout << "\n3. Withdraw";
    cout << "\n4. View account details";
    cout << "\n5. View all accounts";
    cout << "\n6. Exit" << endl;
}
// static variables
int BankAccount::accs = 0;
vector<string>BankAccount::accounts;
vector<float>BankAccount::balance;
vector<int>BankAccount::accnum;
string BankAccount::check = "";


int main() 
{
BankAccount* AccS = new savings();
BankAccount* AccC = new currents();
while(true) // a loop for restarting the program if needed
{
string User="";
string AccType="";
string Back = "If you wish to go back write '0' ";
string exit = "Back : '0' | Exit : '8'";
string customerchoice="";


//interface
Interface();
getline(cin, customerchoice);
///////////
bool validation;
validation = 1;
for(auto i : customerchoice)
{
    if(!(i<='6'&&i>='0')){cout << "\nWrong input\n"; validation = 0; break;}
}
if(validation==0){continue;}
if(customerchoice=="6"){cout << "Thanks for choosing Egypt Bank"; return 0;} // exit
////////////////////////////////////////////////////////////////////////////////////

    else if(customerchoice=="1") //////// 1) creating new account 
    {

        bool validator;
            cout << "\nPlease Write your first and last Name"<< endl;// Customer's name
            cout << "\n===============================\n" << Back <<"\n===============================\n-"; 
            
            getline(cin, customerchoice);

            if(customerchoice=="0"){continue;} //user typed 0
            User = customerchoice; //user didn't type 0
            ////////////////////////////////////////////////////////////////////////////////////
            validator=1;
            for(auto i : User){if(!((i<='Z'&&i>='A')||(i<='z'&&i>='a')||i==' ')){validator = 0; break;}} // validation
            if(validator == 0){cout << "\nWrong input\n"; continue;}
            ////////////////////////////////////////////////////////////////////////////////////
            while(validator)
            {
            cout << "Please specify the account type by writing the number. (1-savings/2-currents) : " << endl; //acc type
            getline(cin, customerchoice);
            if(customerchoice=="0"){validator = 0; continue;} //restarting
            AccType = customerchoice; //user didn't
            ///savings account
            if(AccType == "1")
            {
                AccS->newAccount(User);  //saving account created
            }
            else if(AccType == "2")
            {   
                AccC->newAccount(User); //currents account created
            }
            else{continue;}
            break;
            }
            continue;

    }
    ///////////////////////////////////////////////////////////

    else if(customerchoice=="2")/////// 2) Deposit money
    {
          string num;
        cout << "\n===============================\n";
        cout << Back << "\n===============================\nEnter your account number\n" << "-"; // account number input
        getline(cin,num);
        for(auto i : num) // validation
        {
            if(i<'0'||i>'9'){cout << "\nWrong input\n"; num = "0"; break;}
        }
        if(num=="0"){continue;} // restarting
        int number = stoi(num);
        if(AccS->checkType(number)==2){cout << "\n===============================\n" <<"There are no accounts with this number"; continue;}

        cout << "\nEnter the amount : ";
        string num1;
        getline(cin,num1);

        for(auto i : num1)
        {
            if(i<'0'||i>'9'){cout << "\nWrong input\n"; num1 = "0"; break;}
        }
        if(num1=="0"){continue;}

        int number1 = stoi(num1);
        if(AccS->checkType(number)==1){AccS->deposit(number1,number);}
        else if(AccS->checkType(number)==0){AccC->deposit(number1,number);}



    } 
    // ///////////////////////////////////////////////////////////
    else if(customerchoice=="3")/////// 3) Withdraw money
    {
        string num;
        cout << "\n===============================\n";
        cout << Back << "\n===============================\nEnter your account number\n" << "-";
        getline(cin,num);
        for(auto i : num)
        {
            if(i<'0'||i>'9'){cout << "\nWrong input\n"; num = "0"; break;}
        }
        if(num=="0"){continue;}
        int number = stoi(num);
        if(AccS->checkType(number)==2){cout << "\n===============================\n" <<"There are no accounts with this number"; continue;}

        cout << "\nEnter the amount : ";
        string num1;
        getline(cin,num1);

        for(auto i : num1)
        {
            if(i<'0'||i>'9'){cout << "\nWrong input\n"; num1 = "0"; break;}
        }
        if(num1=="0"){continue;}

        int number1 = stoi(num1);
        if(AccS->checkType(number)==1){AccS->withdraw(number1,number);}
        else if(AccS->checkType(number)==0){AccC->withdraw(number1,number);}
    } 
    ///////////////////////////////////////////////////////////
    else if(customerchoice=="4")/////// 4) View Account Details
    {
      cout << "Enter your account number : "<<endl;
      cout << "\n===============================\n" <<Back << "\n===============================\nEnter your account number\n" << "-";
      string ac_num;
      getline(cin,ac_num);
      for(auto i : ac_num)
        {
            if(i<'0'||i>'9'){cout << "\nWrong input\n"; ac_num = "0"; break;}
        }
      if(ac_num=="0"){continue;}
      int acnum = stoi(ac_num);
      AccS->AccDetails(acnum);
      continue;
    }
    ///////////////////////////////////////////////////////////
    else if(customerchoice=="5")/////// 5) View All Accounts Details
    {
      
      AccS->AllAcounts();
      continue;
    }  

}
}