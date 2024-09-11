/*
Name: Ross Ziegler
ID Number: 2414809
Email: rziegler@chapman.edu
Section: CPSC 350 -04
Assignment: P5 Lazy BST
*/

/*
Overview:
This file creates a student class which holds an id number, name, level, major, gpa, and advisor id
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student{
    public:
        // Defualt Constructor for the student class
        Student();
        // Constructor for the student class
        Student(int idNumber, std::string name, std::string level, std::string major, double gpa, int advisorID);
        // Destrcutor for the student class
        virtual ~Student();
        // overides the less than operator for students
        bool operator < (const Student& other)const;
        // overides the greater than operator for students
        bool operator > (const Student& other)const;
        // overides the equals operator for students
        bool operator == (const Student& other)const;
        // overides the != operator for students
        bool operator != (const Student& other)const;
        // overides the <= operator for students
        bool operator <= (const Student& other)const;
        // overides the >= operator for students
        bool operator >= (const Student& other)const;
        // return the students id as an int
        int getID();
        // set the students id given an int perameter
        void setID(int newID);
        // return the students name as a string
        std::string getName();
        // set the students name given a string as a perameter
        void setName(std::string newName);
        // return the students level as a string
        std::string getLevel();
        // set the students level given a string 
        void setLevel(std::string newLevel);
        // return the students major as a string
        std::string getMajor();
        // set the students major given a string
        void setMajor(std::string newMajor);
        // return the students gpa as a double
        double getGPA();
        // set the students gpa given a double
        void setGPA(double newGPA);
        // return the students advisor id as an int
        int getAdvisorID();
        // set the students advisor id given an int
        void setAdvisorID(int newAdvisorID);
    private:
        // students id number
        int m_IDNumber;
        // students name
        std::string m_Name;
        // students level
        std::string m_Level;
        // students major
        std::string m_Major;
        // students gpa
        double m_GPA;
        // students advisor
        int m_AdvisorID;
};

#endif