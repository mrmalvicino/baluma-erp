#include "../headers/EmployeesManager.h"

EmployeesManager::EmployeesManager()
{
    _employees_backup.setPath("registers/employees.bkp");
}

void EmployeesManager::displayMenu()
{
    int selection = 1;

    do{
        _terminal.clear();
        _terminal.displayMenuHeader("RECURSOS HUMANOS");
        std::cout << "(1) INCORPORAR EMPLEADO\n";
        std::cout << "(2) EDITAR EMPLEADO\n";
        std::cout << "(3) BUSCAR EMPLEADO\n";
        std::cout << "(4) VER LISTADO\n";
        _terminal.printLine();
        std::cout << "(6) EXPORTAR BACKUP\n";
        std::cout << "(7) IMPORTAR BACKUP\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 6);

        switch (selection)
        {
        case 1:
            addEmployee();
            break;
        case 2:
            editEmployee();
            break;
        case 3:
            searchEmployee();
            break;
        case 4:
            listEmployeesMenu();
            break;
        case 5:
            exportEmployeeBackup();
            break;
        case 6:
            importEmployeeBackup();
            break;
        }

    }while(selection != 0);
}

bool EmployeesManager::addEmployee()
{
    bool successful_write;
    bool user_wants_to_save;

    _terminal.clear();
    _terminal.displayMenuHeader("DAR DE ALTA EMPLEADO");

    _employee.setId(generateEmployeeId());

    cinEmployeeName(_employee);
    cinEmployeeLegalId(_employee);
    cinEmployeeAdress(_employee);
    cinEmployeePhone(_employee);
    cinEmployeeEmail(_employee);
    cinEmployeeTitle(_employee, false);
    cinEmployeeAdmission(_employee);

    std::cout << "¿Desea guardar un nuevo registro con los datos ingresados? [S/N]\n";
    user_wants_to_save = _terminal.validateBool();

    if(user_wants_to_save == true)
    {
        successful_write = _employees_archive.write(_employee);
        if(successful_write == true)
        {
            std::cout << "Registro guardado correctamente.\n";
        } else {
            std::cout << "Error de escritura.\n";
        }
    } else {
            successful_write = false;
            std::cout << "Registro descartado por el usuario.\n";
    }

    _terminal.pause();
    _terminal.clear();

    return successful_write;
}

void EmployeesManager::loadEmployee(int index)
{
    _employee = _employees_archive.read(index);
}

bool EmployeesManager::editEmployee()
{
    _terminal.clear();

    int search_rtn = searchEmployee();

    if(search_rtn == -1)
    {
        return false;
    }

    int selection = 1;

    do{
        _terminal.clear();
        _terminal.displayMenuHeader("EDITAR EMPLEADO");
        _terminal.centerAndPrint(_employee.getDescription());
        std::cout << "\n";
        std::cout << "(1) EDITAR NOMBRE\n";
        std::cout << "(2) EDITAR DNI\n";
        std::cout << "(3) EDITAR DOMICILIO\n";
        std::cout << "(4) EDITAR TELÉFONO\n";
        std::cout << "(5) EDITAR E-MAIL\n";
        std::cout << "(6) EDITAR PUESTO DE TRABAJO\n";
        std::cout << "(7) EDITAR FECHA DE ALTA\n";
        std::cout << "(8) DAR DE BAJA / REINCORPORAR\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0,8);

        switch (selection)
        {
        case 1:
            cinEmployeeName(_employee);
            break;
        
        case 2:
            cinEmployeeLegalId(_employee);
            break;

        case 3:
            cinEmployeeAdress(_employee);
            break;

        case 4:
            cinEmployeePhone(_employee);
            break;

        case 5:
            cinEmployeeEmail(_employee);
            break;

        case 6:
            cinEmployeeTitle(_employee, true);
            break;

        case 7:
            cinEmployeeAdmission(_employee);
            break;

        case 8:
            cinEmployeeIsActive(_employee);
            break;
        }

    }while(selection != 0);

    int index = _employees_archive.getIndex(_employee.getId());
    bool succesful_write = _employees_archive.overWrite(_employee, index);

    return succesful_write;
}

int EmployeesManager::searchEmployee()
{
    _terminal.clear();

    int search_rtn = 0;
    int selection = 1;

    _terminal.displayMenuHeader("BUSCAR EMPLEADO");
    std::cout << "(1) BUSCAR POR ID\n";
    std::cout << "(2) BUSCAR POR NOMBRE\n";
    std::cout << "(3) BUSCAR POR DNI\n";

    selection = _terminal.validateInt(0,3);

    switch (selection)
    {
    case 0:
        search_rtn = -1;
        _terminal.clear();
        break;
    case 1:
        search_rtn = searchEmployeeById();
        break;
    
    case 2:
        search_rtn = searchEmployeeByName();
        break;
    
    case 3:
        search_rtn = searchEmployeeByDNI();
    }

    return search_rtn;
}

int EmployeesManager::searchEmployeeById()
{
    int search_rtn = 0;
    int index;
    int id;
    int max_id;

    max_id = _employees_archive.getAmountOfRegisters();

    std::cout << "Ingrese ID o 0 para cancelar:\n";
    id = _terminal.validateInt(0,max_id);

    if(0 < id)
    {
        index = _employees_archive.getIndex(id);
        loadEmployee(index);
        printEmployee();
    } else {
        search_rtn = -1;
        std::cout << "Búsqueda abortada por el usuario.\n";
    }

    _terminal.pause();

    return search_rtn;
}

int EmployeesManager::searchEmployeeByName()
{
    int search_rtn = 0;
    int index;
    std::string description;

    std::cout << "Ingresar nombre del empleado completo:\n";
    std::cin.ignore();
    getline(std::cin,description);

    index = _employees_archive.getIndex(description);

    while(index == -1)
    {
        std::cout << "No se encontro el registro " << description << ". Ingrese el nombre nuevamente o ingrese 0 para cancelar.\n";
        getline(std::cin,description);

        if(description == "0")
        {
            index = -2;
        } else {
            index = _employees_archive.getIndex(description);
        }
    }

    if(0 <= index)
    {
        loadEmployee(index);
        printEmployee();
    } else {
        search_rtn = -1;
        std::cout << "Búsqueda abortada por el usuario.\n";
    }

    _terminal.pause();

    return search_rtn;
}

int EmployeesManager::searchEmployeeByDNI()
{
    int search_rtn = 0;
    int index;
    long long int legal_id;

    std::cout << "Ingrese ID o 0 para cancelar:\n";
    std::cin >> legal_id;

    if(0 < legal_id)
    {
        index = _employees_archive.getIndex(legal_id);
        loadEmployee(index);
        printEmployee();
    } else {
        search_rtn = -1;
        std::cout << "Búsqueda abortada por el usuario.\n";
    }

    _terminal.pause();

    return search_rtn;
}

void EmployeesManager::listEmployeesMenu()
{
     _terminal.clear();

    int selection = 1;

    while (selection != 0)
    {
        _terminal.displayMenuHeader("LISTAR EMPLEADOS");
        std::cout << "(1) LISTAR TODOS LOS REGISTROS\n";
        std::cout << "(2) LISTAR SOLO ACTIVOS\n";
        std::cout << "(3) LISTAR SOLO DADOS DE BAJA\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 3);

        switch (selection) {
            case 0:
             _terminal.clear();
             break;
            case 1:
             listEmployees(true, true);
             break;
            case 2:
             listEmployees(true, false);
             break;
            case 3:
             listEmployees(false, true);
             break;
    }
    }
    

}
void EmployeesManager::listEmployees(bool list_actives, bool list_inactives)
{
    _terminal.clear();

    int amount_of_employees = _employees_archive.getAmountOfRegisters();

    for(int i = 0; i < amount_of_employees; i++)
    {
        loadEmployee(i);

        if((_employee.getIsActive() == true && list_actives == true) || (_employee.getIsActive() == false && list_inactives == true) )
        {
            printEmployee();
        }
    }

    _terminal.pause();
    _terminal.clear();
}

void EmployeesManager::printEmployee()
{
    _terminal.displayMenuHeader(_employee.getDescription());
    std::cout << "# ID: " << _employee.getId() << "\n";
    std::cout << "DNI: " << _employee.getLegalId() << "\n";
    std::cout << "País: " << _employee.getAdress().getCountry() << "\n";
    std::cout << "Provincia: " << _employee.getAdress().getState() << "\n";
    std::cout << "Ciudad: " << _employee.getAdress().getCity() << "\n";
    std::cout << "Calle: " << _employee.getAdress().getStreet() << "\n";
    std::cout << "Número: " << _employee.getAdress().getNumber() << "\n";
    std::cout << "Piso: " << _employee.getAdress().getFloor() << " " << _employee.getAdress().getLetter() << "\n";
    std::cout << "Teléfono: " << _employee.getPhone() << "\n";
    std::cout << "E-mail: " << _employee.getEmail() << "\n";
    std::cout << "Puesto: " << _employee.getTitle() << "\n";
    std::cout << "Fecha de alta: " << _employee.getAdmission().toString() << "\n";
    _terminal.printBool(_employee.getIsActive(), "Estado: Activo\n\n", "Estado: Dado de baja\n\n");
}

void EmployeesManager::cinEmployeeName(Employee &employee)
{
    std::string name;

    std::cout << "Ingrese el nombre del empleado:\n";
    std::cin.ignore();
    getline(std::cin, name);

    employee.setDescription(name);
}

void EmployeesManager::cinEmployeeLegalId(Employee &employee)
{
    long long int legal_id;

    std::cout << "Ingrese DNI:\n";
    legal_id = _terminal.validateLongInt(1);

    employee.setLegalId(legal_id);
}

void EmployeesManager::cinEmployeeAdress(Employee &employee)
{
    Adress adress;

    std::string country;
    std::string state;
    std::string city;
    std::string street;
    int number;
    int floor;
    char letter;

    std::cout << "Ingresar el país del domicilio:\n";
    std::cin.ignore();
    getline(std::cin, country);

    std::cout << "Ingresar la provincia del domicilio:\n";
    getline(std::cin, state);

    std::cout << "Ingresar la ciudad del domicilio:\n";
    getline(std::cin, city);

    std::cout << "Ingresar la calle del domicilio:\n";
    getline(std::cin, street);

    std::cout << "Ingresar el número de domicilio:\n";
    number = _terminal.validateInt(0);

    std::cout << "Ingresar el piso:\n";
    floor = _terminal.validateInt(0);

    std::cout << "Ingresar el departamento:\n";
    letter = _terminal.validateChar();

    adress.setCountry(country);
    adress.setState(state);
    adress.setCity(city);
    adress.setStreet(street);
    adress.setNumber(number);
    adress.setFloor(floor);
    adress.setLetter(letter);

    employee.setAdress(adress);

}

void EmployeesManager::cinEmployeePhone(Employee &employee)
{
    int phone;

    std::cout << "Ingrese el número de teléfono:\n";
    std::cin >> phone;

    employee.setPhone(phone);
}

void EmployeesManager::cinEmployeeEmail(Employee &employee)
{
    std::string email;

    std::cout << "Ingrese el e-mail:\n";
    std::cin.ignore();
    getline(std::cin, email);

    employee.setEmail(email);
}

void EmployeesManager::cinEmployeeIsActive(Employee &employee)
{
    if (employee.getIsActive()) {
        employee.setIsActive(false);
        std::cout << "El empleado ha sido dado de baja.\n";
        _terminal.pause();
    } else {
        employee.setIsActive(true);
        std::cout << "El empleado ha sido reincorporado.\n";
        _terminal.pause();
    }
}

void EmployeesManager::cinEmployeeTitle(Employee &employee, bool cin_ignore)
{
    std::string title;

    std::cout << "Ingrese el cargo del empleado:\n";
    if(cin_ignore)
    {
        std::cin.ignore();
    }
    getline(std::cin, title);

    employee.setTitle(title);
}

void EmployeesManager::cinEmployeeAdmission(Employee &employee)
{
    int d, m, a;

    std::cout << "Ingrese la fecha de alta.\n";

    std::cout << "Día: ";  std::cin >> d;
    std::cout << "Mes: ";  std::cin >> m;
    std::cout << "Año: "; std::cin >> a;

    Date date(d,m,a);
    employee.setAdmission(date);
}

int EmployeesManager::generateEmployeeId()
{
    int id = 1;

    if(_employees_archive.getAmountOfRegisters() != 0) {
        id = _employees_archive.getAmountOfRegisters() + 1;
    }

    return id;
}

void EmployeesManager::exportEmployeeBackup()
{
   int amount_of_employees = _employees_archive.getAmountOfRegisters();

   Employee * employees_array = new Employee[amount_of_employees];

   if(employees_array == NULL)
   {
    std::cout << "Error de memoria RAM: No se pudo asignar la memoria requerida al exportar backup.";
   } else {
        for(int i = 0; i < amount_of_employees; i++)
        {
            employees_array[i] = _employees_archive.read(i);
        }

        _employees_backup.createEmptyArchive();

        for(int i = 0; i < amount_of_employees; i++)
        {
            _employees_backup.write(employees_array[i]);
        }

        delete [] employees_array;

        std::cout << "Backup exportado correctamente.\n";
        _terminal.pause();
   }
}

void EmployeesManager::importEmployeeBackup()
{
     std::cout << "¿Desea reemplazar los empleados actuales por aquellos que haya en el archivo de respaldo? [S/N]\n";

    if(_terminal.validateBool() == false)
    {
        std::cout << "Importación abortada por el usuario.\n";
    } else {

        int amount_of_employees = _employees_backup.getAmountOfRegisters();

        Employee * employees_array = new Employee[amount_of_employees];

        if(employees_array == NULL)
        {
            std::cout << "Erorr de memoria RAM: No se puedo asignar la memoria requerida al importar backup.";
        } else {

            for(int i = 0; i < amount_of_employees; i++)
            {
                employees_array[i] = _employees_backup.read(i);
            }

            _employees_archive.createEmptyArchive();

            for(int i = 0; i < amount_of_employees; i++)
            {
                _employees_archive.write(employees_array[i]);
            }

            delete [] employees_array;
            std::cout << "Backup importado correctamente.\n";
            _terminal.pause();
        }
    }
}

