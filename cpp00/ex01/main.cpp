#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string cmd;

    while(1){
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin,cmd);
        if(cmd == "ADD"){
            phonebook.addContact();
        }else if(cmd == "SEARCH"){
            phonebook.searchContacts();
        }else if(cmd == "EXIT"){
            break;
        } else{
            std::cout << "Invalid command!" << std::endl;
        }
    }
    return (0);
}