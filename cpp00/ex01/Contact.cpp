#include "PhoneBook.hpp"


Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}
 
    void Contact::setFirstName(const std::string &fName){
        firstName = fName;
    }
    void Contact::setLastName(const std::string &lName){
        lastName = lName;
    }
    void Contact::setNickname(const std::string &nick){
        nickname = nick;
    }
    void Contact::setPhoneNumber(const std::string &phone){
        phoneNumber = phone;
    }
    void Contact::setDarkestSecret(const std::string &secret){
         darkestSecret = secret;
    }
    std::string Contact::getFirstName(){
        return firstName;
    }
    std::string Contact::getLastName(){
        return lastName;
    }
    std::string Contact::getNickname(){
        return nickname;
    }
    std::string Contact::getPhoneNumber(){
        return phoneNumber;
    }
    std::string Contact::getDarkestSecret(){
        return darkestSecret;
    }
    void    Contact::printContact(){
        std::cout << "first name: " << getFirstName() << std::endl;
        std::cout << "last name: " << getLastName() << std::endl;
        std::cout << "nickname: " << getNickname() << std::endl;
        std::cout << "phone number: " << getPhoneNumber() << std::endl;
        std::cout << "darkest secret: " << getDarkestSecret() << std::endl;
    };


