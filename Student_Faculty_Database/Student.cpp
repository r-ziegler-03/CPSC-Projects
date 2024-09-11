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
#include "Student.h"
#include <iostream>
#include <sstream>
#include <string>


Student::Student(){
    m_IDNumber = 0;
    m_Name = "unknown";
    m_Level = "unkown";
    m_Major = "unkown";
    m_GPA = 0.0;
    m_AdvisorID = 0.0;
}

Student::Student(int idNumber, std::string name, std::string level, std::string major, double gpa, int advisorID){
    m_IDNumber = idNumber;
    m_Name = name;
    m_Level = level;
    m_Major = major;
    m_GPA = gpa;
    m_AdvisorID = advisorID;
}

Student::~Student(){}


bool Student::operator == (const Student& other) const{
    return m_IDNumber == other.m_IDNumber;
}

bool Student::operator > (const Student& other) const{
    return m_IDNumber > other.m_IDNumber;
}

bool Student::operator < (const Student& other) const{
    return m_IDNumber < other.m_IDNumber;
}

bool Student::operator != (const Student& other) const{
    return m_IDNumber != other.m_IDNumber;
}

bool Student::operator >= (const Student& other) const{
    return m_IDNumber >= other.m_IDNumber;
}

bool Student::operator <= (const Student& other) const{
    return m_IDNumber <= other.m_IDNumber;
}

int Student::getID(){
    return m_IDNumber;
}
void Student::setID(int newID){
    m_IDNumber = newID;
}

std::string Student::getName(){
    return m_Name;
}
void Student::setName(std::string newName){
    m_Name = newName;
}

std::string Student::getLevel(){
    return m_Level;
}
void Student::setLevel(std::string newLevel){
    m_Level = newLevel;
}

std::string Student::getMajor(){
    return m_Major;
}
void Student::setMajor(std::string newMajor){
    m_Major = newMajor;
}

double Student::getGPA(){
    return m_GPA;
}
void Student::setGPA(double newGPA){
    m_GPA = newGPA;
}

int Student::getAdvisorID(){
    return m_AdvisorID;
}
void Student::setAdvisorID(int newAdvisorID){
    m_AdvisorID = newAdvisorID;
}


