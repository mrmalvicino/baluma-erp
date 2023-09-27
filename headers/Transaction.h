#include<cstring>
using namespace std;
#include <string>

class Transaction{
    public:
        //CONSTRUCTOR
        Transaction();
        Transaction(int accountNumber, int transactionId, double debit, double credit,const std::string & description);
        //SETTERS Y GETTERS
        void setAccountNumber(int _accountNumber);
        void setTransactionId(int _transactionId);
        void setDebit(double _debit);
        void setCredit(double _credit);
        void setDescription(const std::string &_description);
        int getAccountNumber();
        int getTransactionId();
        double getDebit();
        double getCredit();
        std::string getDescription();
        void cinTransaction();
        void coutTransaction();
    private:   
        int accountNumber;
        int transactionId;
        double debit;
        double credit;
        char description [30];
};