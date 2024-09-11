/*
Name: Ross Ziegler
ID Number: 2414809
Email: rziegler@chapman.edu
Section: CPSC 350 -04
Assignment: P5 Lazy BST
*/

/*
Overview:
This file creates a Faculty which hold a id number, name, level, department, and list of advisees
*/
#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <string>

class Faculty{
    public:
    // Constructor of the faculty class
        Faculty();
    // Constructor of the faculty class
        Faculty(int idNumber, std::string name, std::string level, std::string department);
    // destructor of the faculty class
        virtual ~Faculty();
    // overides the less than operator for Faculty
    bool operator < (const Faculty& other)const;
    // overides the greater than operator for Faculty
    bool operator > (const Faculty& other)const;
    // overides the equals operator for Faculty
    bool operator == (const Faculty& other)const;
    // overides the != operator for Faculty
    bool operator != (const Faculty& other)const;
    // overides the <= operator for Faculty
    bool operator <= (const Faculty& other)const;
    // overides the >= operator for Faculty
    bool operator >= (const Faculty& other)const;
    // get the Faculty Id
        int getID();
    // get the 
        void setID(int newID);
        std::string getName();
        void setName(std::string newName);
        std::string getLevel();
        void setLevel(std::string newLevel);
        std::string getDepartment();
        void setDepartment(std::string newDepartment);
        void addToList(int idNumber);
        void removeFromList(int idNumber);
        int removeFromFront();
        bool listIsEmpty();
        int getMaxAdvisees();
        std::string displayList();
    private:
        int m_IDNumber;
        std::string m_Name;
        std::string m_Level;
        std::string m_Department;
        int* m_AdviseeIDs;
        int m_NumAdvisees;
        int m_maxAdvisees;
};

#endif