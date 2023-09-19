#include<cstring>
using namespace std;
#include <string>

class Transaction{
    public:
        //CONSTRUCTOR
        Transaction();
        Transaction(double debit, double credit);
        //SETTERS Y GETTERS
        void setDebit(double _debit);
        void setCredit(double _credit);
        double getDebit();
        double getCredit();
        void cinTransaction();
        void coutTransaction();
    private:
        double debit;
        double credit;
};