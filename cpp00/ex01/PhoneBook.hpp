#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
    
    public:
        Contact();
        void setFirstName(const std::string &fName);
        void setLastName(const std::string &lName);
        void setNickname(const std::string &nick);
        void setPhoneNumber(const std::string &phone);
        void setDarkestSecret(const std::string &secret);
        std::string getFirstName();
        std::string getLastName();
        std::string getNickname();
        std::string getPhoneNumber();
        std::string getDarkestSecret();
        void    printContact();
};

class PhoneBook{
    private:
        Contact contacts[8];
        int index;
        int count;
        std::string formatField(const std::string &field);
    public:
        PhoneBook();
        void addContact();
        void searchContacts();
};

#endif