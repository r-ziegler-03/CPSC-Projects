/*
Name: Ross Ziegler
ID Number: 2414809
Email: rziegler@chapman.edu
Section: CPSC 350 -04
Assignment: PA6 Kruskals
*/

/*
Overview:
This file creates an Adjacency matrix
The matrix consists of N nodes and edges, each each with an associated weight
The matrix is a 2D Array of doubles
Within the class you can add edges, remove edges, calculate the Minimum Spanning Tree(MST) and display the matrix
*/
#ifndef WGraph_H
#define WGraph_H

#include <set> // used for the set of vetex's
#include <iostream>
#include <limits> // allows us to get min and max
#include <queue> // allows the use of priority queue
#include "AdjacentNodes.h"

//a weighted, undirected WGraph implemented with adjacency matrix
//fixed size
typedef unsigned int VertexID;

class WGraph{
public: 
    // WGraph default constructor
    WGraph();
    // Wgraph Constructor, initializes the 2D array to be of size sz
    WGraph(unsigned int sz);
    // Deconstructs the adjacency matrix and the connectivity matrix
    ~WGraph();
    // Adds an edge to the matrix given VertexID i and j and assigns that edge with weight w as a double
    void addEdge(VertexID i, VertexID j, double w); // now includes a double for the weight of the edge
    // Removes an edge from the matrix given the VertexID i and j
    void removeEdge(VertexID i, VertexID j);
    // Returns a boolean value on whether the VertexID i and j are adjacent to eachother, meaning they share an edge
    bool areAdjacent(VertexID i, VertexID j);
    // will give us the cheapest path between two vertices
    double cheapestCost(VertexID i, VertexID j); 
    // will calculate the Floyd-Warshall algo and create a connectivity matrix that gives us the shortest path from every node to every other node 
    void calcFW(); 
    // Prints the minimum spanning tree to the terminal given the adjacency matrix, prints the cost of the tree as well
    void computeMST();
    // Displays the adjacency matrix to the terminal
    void display();
private:
    double** m_adj; // Adjacency matrix: is there an edge between two vertices and what's the weight of the edge
    double** m_conn; // Connectivity matrix: more general, is there a path between a start and a finish and what's the cost (all parts summed)
    unsigned int m_size; // number of nodes in WGraph (fixed) 
    bool recalcFW;
};

#endif