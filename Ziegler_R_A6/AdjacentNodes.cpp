/*
Name: Ross Ziegler
ID Number: 2414809
Email: rziegler@chapman.edu
Section: CPSC 350 -04
Assignment: PA6 Kruskals
*/

/*
Overview:
This file creates an Adjacent Node object
This object has a start node(int), end node(int), annd a weight(double)
When an instance of this object is created, it takes those three variables as a perameter
*/
#include "AdjacentNodes.h"
// Default constructor for the AdjacentNodes class
AdjacentNodes::AdjacentNodes(){
    AdjacentNodes(0,0,0);
}
// Constructor for the AdjacentNodes class, takes startNode and endNode as an int, and weight as a double
AdjacentNodes::AdjacentNodes(int startNode, int endNode, double weight){
    m_startNode = startNode;
    m_endNode = endNode;
    m_weight = weight;
}
// The deconsructor of the AdjacentNodes class
AdjacentNodes::~AdjacentNodes(){
}
// overrides the equals operator when comparing AdjacentNodes objects by their weight
bool AdjacentNodes::operator == (const AdjacentNodes& other) const{
    return m_weight == other.m_weight;
}
// overrides the greater than operator when comparing AdjacentNodes objects by their weight
bool AdjacentNodes::operator > (const AdjacentNodes& other) const{
    return m_weight > other.m_weight;
}
// overrides the less than operator when comparing AdjacentNodes objects by their weight
bool AdjacentNodes::operator < (const AdjacentNodes& other) const{
    return m_weight < other.m_weight;
}