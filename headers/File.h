#include <cstdio>
#include "Register.h"

class File {
    public:
        File();
        File(std::string path);
        void setPath(std::string path);
        std::string getPath();
        bool write(Register & reg_write);
        bool write(Register & reg_write, int index);
        Register read(int index);
        int getIndex(int id);
        int getAmountOfRegisters();
    
    private:
        // Attributes
        std::string _path;
};