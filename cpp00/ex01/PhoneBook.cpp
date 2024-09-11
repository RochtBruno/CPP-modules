#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): index(0), count (0) {}
    std::string PhoneBook::formatField(const std::string& field) {
        if (field.length() > 10) {
            return field.substr(0, 9) + ".";
        }
        return std::string(10 -field.length(), ' ') + field;
}

    void PhoneBook::addContact(){
        Contact newContact;
        std::string input;

        std::cout << "Fill with your first name: ";
        std::getline(std::cin, input);
        if(input.empty())
        {
            std::cout << "Empty field!" << std:: endl;
            return ;
        } else {
            newContact.setFirstName(input);
        }

        std::cout << "Fill wih your last name: ";
        std::getline(std::cin, input);
        if(input.empty())
        {
            std::cout << "Empty field!" << std:: endl;
            return ;
        } else {
            newContact.setLastName(input);
        }

        std::cout << "Fill with your nickname: ";
        std::getline(std::cin, input);
        if(input.empty())
        {
            std::cout << "Empty field!" << std:: endl;
            return ;
       } else {
            newContact.setNickname(input);
        }

        std::cout << "fill with your phone nuumber: ";
        std::getline(std::cin,input);
        if(input.empty())
        {
            std::cout << "Empty field!" << std::endl;
            return;
        }else{
            newContact.setPhoneNumber(input);
            }

        std::cout << "Fill with your darkest secret: ";
        std::getline(std::cin,input);
        if(input.empty()){
            std::cout << "Empty field" << std:: endl;
                return;
        }else {
            newContact.setDarkestSecret(input);
        }

        contacts[index] = newContact;
        index = (index + 1) % 8;
        if(count < 8)
            count++;
        }
    void PhoneBook::searchContacts(){
        int index;

        if(count == 0){
            std::cout << "Phonebook is empty" << std::endl;
            return ;
        }
        std::cout << "|-index--|-firstname|-lastname-|-nickname-|" << std::endl;
        for(int i = 0; i < count; i++){
            std::cout << "    " << i << "    " << "|" << formatField(contacts[i].getFirstName()) 
            << "|" << formatField(contacts[i].getLastName()) << "|" 
             << formatField(contacts[i].getNickname()) << "|" 
            << std::endl;
        }
        std::cout << "Enter the index of the contact to view" << std::endl;
        std::cin >> index;
        if(index >= 0 && index < count){
            contacts[index].printContact();
        }else {
            std::cout << "Invalid index" << std::endl;
        }
            std::cin.ignore();
    }
