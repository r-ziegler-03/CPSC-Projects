/*
Name: Ross Ziegler
ID Number: 2414809
Email: rziegler@chapman.edu
Section: CPSC 350 -04
Assignment: P5 Lazy BST
*/

/*
Overview:
This file creates the DNA sequence which is a doubly linked list of characters
This file contains methods that produce the complement of the list of characters and check to see if the complement is a 
palindrome with the original list
*/
#include "Faculty.h"
Faculty::Faculty(){
    Faculty(0,"unkown","unknown","unknown");
}

Faculty::Faculty(int idNumber, std::string name, std::string level, std::string department){
    m_IDNumber = idNumber;
    m_Name = name;
    m_Level = level;
    m_Department = department;
    m_maxAdvisees = 10;
    m_NumAdvisees = 0;
    m_AdviseeIDs = new int[m_maxAdvisees];
}

Faculty::~Faculty(){

}

bool Faculty::operator == (const Faculty& other) const{
    return m_IDNumber == other.m_IDNumber;
}
bool Faculty::operator > (const Faculty& other) const{
    return m_IDNumber > other.m_IDNumber;
}
bool Faculty::operator < (const Faculty& other) const{
    return m_IDNumber < other.m_IDNumber;
}
bool Faculty::operator <= (const Faculty& other) const{
    return m_IDNumber <= other.m_IDNumber;
}
bool Faculty::operator >= (const Faculty& other) const{
    return m_IDNumber >= other.m_IDNumber;
}
bool Faculty::operator != (const Faculty& other) const{
    return m_IDNumber != other.m_IDNumber;
}

int Faculty::getID(){
    return m_IDNumber;
}
void Faculty::setID(int newID){
    m_IDNumber = newID;
}

std::string Faculty::getName(){
    return m_Name;
}
void Faculty::setName(std::string newName){
    m_Name = newName;
}

std::string Faculty::getLevel(){
    return m_Level;
}
void Faculty::setLevel(std::string newLevel){
    m_Level = newLevel;
}

std::string Faculty::getDepartment(){
    return m_Department;
}
void Faculty::setDepartment(std::string newDepartment){
    m_Department = newDepartment;
}

void Faculty::addToList(int idNumber){
    if (m_NumAdvisees == m_maxAdvisees){
        int* temp = new int[2*m_maxAdvisees];
        for(int i = 0; i < m_maxAdvisees; i++){
            temp[i] = m_AdviseeIDs[i];
        }
        m_maxAdvisees *= 2;
        m_AdviseeIDs = temp;
        delete[] temp;
    }
    for (int i = 0; i < m_maxAdvisees; i++){
        if (m_AdviseeIDs[i] == 0){
            m_AdviseeIDs[i] = idNumber;
            m_NumAdvisees++;
            break;
        }
    }
}

void Faculty::removeFromList(int idNumber){
    for (int i = 0; i < m_maxAdvisees; i++){
        if (m_AdviseeIDs[i] == idNumber){
            m_AdviseeIDs[i] = 0;
            m_NumAdvisees--;
            break;
        }
    }
}

bool Faculty::listIsEmpty(){
    return (m_NumAdvisees == 0);
}

int Faculty::removeFromFront(){
    for (int i = 0; i < m_maxAdvisees; i++){
        if (m_AdviseeIDs[i] != 0){
            int ret = m_AdviseeIDs[i];
            removeFromList(ret);
            return ret;
        }
    }
    return 0;
}

int Faculty::getMaxAdvisees(){
    return m_maxAdvisees;
}

std::string Faculty::displayList(){
    std::string tempList = "";
    for (int i = 0; i < m_maxAdvisees; i++){
        if (m_AdviseeIDs[i] > 0){
            tempList += std::to_string(m_AdviseeIDs[i]);
            tempList += " ";
        }
    }
    return tempList;
}