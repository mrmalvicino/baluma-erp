#include<cstring>
using namespace std;
#include <string>

class Account{
public:
    //CONSTRUCTOR
    Account();
    Account(int accountNumber,std::string denomination,std::string concept, std::string accountName, double balance, double passive, double active):
        accountNumber(accountNumber),denomination(denomination),concept(concept),accountName(accountName), balance(balance), passive(passive), active(active){}
    //GETTERS Y SETTERS
    void setAccountNumber(int _accountNumber);
    void setActive(double _active);
    void setPassive(double _passive);
    void setBalance(double _balance);
    void setAccountName(std::string _accountName);
    void setDenomination(std::string _denomination);
    void setConcept(std::string _concept);
    double getActive();
    double getPassive();
    double getBalance();
    int getAccountNumber();
    std::string getAccountName();
    std::string getDenomination();
    std::string getConcept();
    //METODOS
    void deposit(double amount);
    void remove(double amount);
    void moveAccount();

private:
    int accountNumber;
    double active;
    double passive;
    double balance;
    std::string accountName;
    std::string denomination;
    std::string concept;
};


