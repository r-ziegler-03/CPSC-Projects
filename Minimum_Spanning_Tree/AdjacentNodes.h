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
#ifndef ADJACENT_NODES_H
#define ADJACENT_NODES_H

class AdjacentNodes{
    public:
        // Default constructor for the AdjacentNodes class
        AdjacentNodes();
        // Constructor for the AdjacentNodes class, takes startNode and endNode as an int, and weight as a double
        AdjacentNodes(int startNode, int endNode, double weight);
        // The deconsructor of the AdjacentNodes class
        virtual ~AdjacentNodes();
        // the member variable that holds the start node as an int
        int m_startNode;
        // the member variable that holds the end node as an int
        int m_endNode;
        // the member variable that holds the weight of the edge as a double
        double m_weight;
        // overrides the less than operator when comparing AdjacentNodes objects by their weight
        bool operator < (const AdjacentNodes& other)const;
        // overrides the greater than operator when comparing AdjacentNodes objects by their weight
        bool operator > (const AdjacentNodes& other)const;
        // overrides the equals operator when comparing AdjacentNodes objects by their weight
        bool operator == (const AdjacentNodes& other)const;
        
};

#endif