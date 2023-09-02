#include <string>
#include <cstring>

class Register{
    public:
        // Construct
        Register();
        Register(int id, std::string description);

        // Public Methods
        void setId(int id);
        void setDescription(std::string description);
        int getId();
        std::string getDescription();

    private:
        // Attributes
        int _id;
        char _description[30];
};