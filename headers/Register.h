#include <string>
#include <cstring>

class Register {
    public:
        Register();
        Register(int id, std::string description);
        void setId(int id);
        void setDescription(std::string description);
        int getId();
        std::string getDescription();

    private:
        int _id;
        char _description[30];
};