#include <cstdio>
#include "Register.h"

class File{
    public:
        // Public Methods
        bool write(Register & reg_write) const;
        Register read(int index);
        int getAmountOfRegisters();
};