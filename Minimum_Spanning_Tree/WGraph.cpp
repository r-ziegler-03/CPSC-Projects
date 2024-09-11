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
#include "WGraph.h"
/*
Default Constructor
intializes the size of the matrix to be 0
intializes the adjacency and connectivity matrix to be NULL
*/
WGraph::WGraph(){
  m_size = 0;
  m_adj = NULL;
  m_conn = NULL;
}
/*
Constructor
initializes the size of the matrix to be of size sz
initializes adjacency and connectivity matrix and fills all of the indexes with 0
*/
WGraph::WGraph(unsigned int sz){
  m_size = sz;
  //allocate sz * sz adj matrix
  m_adj = new double*[sz];
  m_conn = new double*[sz];
  for(int i = 0; i < m_size; ++i){
    m_adj[i] = new double[sz];
    m_conn[i] = new double[sz];
  }
  //start with edges
  for(int i = 0; i < m_size; ++i){
    for(int j = 0; j < m_size; ++j){
      m_adj[i][j] = 0;
      m_conn[i][j] = 0;  
    }
  }

  recalcFW = false;
}
/*
Deconstructor
deallocates adjacency and connectivity matrix from memory
*/
WGraph::~WGraph(){
  for (int i = 0; i < m_size; ++ i){
    delete m_adj[i];
    delete m_conn[i];
  }
  delete[] m_adj;
  delete[] m_conn;
}
/*
Adds an edge to adjacency matrix given VertexID i and j and assigns the edge to be of weight w
this edge is inserted into the matrix given this information
*/
void WGraph::addEdge(VertexID i, VertexID j, double w){
  if(i < m_size && j < m_size){
    m_adj[i][j] = w;  
    m_adj[j][i] = w;
  }
  // calcFW(); // not very efficient since we'd have to re-calculate it every time we add or remove an edge
  recalcFW = true;
}
/*
Removes an edge from the matrix given VertexID i and j
this edge is removed from adjacency matrix given this information
*/
void WGraph::removeEdge(VertexID i, VertexID j){
  if(i < m_size && j < m_size){
    m_adj[i][j] = 0;
    m_adj[j][i] = 0;
  }
  // calcFW(); // not very efficient since we'd have to re-calculate it every time we add or remove an edge
  recalcFW = true;
}
/*
returns true if VertexID i and j are connected by an edge
returns false otherwise
*/
bool WGraph::areAdjacent(VertexID i, VertexID j){
  return (m_adj[i][j] != 0);
}

void WGraph::calcFW(){
  // set the conn matrix equal to adj matrix 
  for (int i = 0; i < m_size; ++i){
    for (int j = 0; j < m_size; ++j){
      m_conn[i][j] = m_adj[i][j];
    }
  }

  // start FW
  for (int im = 0; im < m_size; ++im){ // intermediate points 
    for (int source = 0; source < m_size; ++source){ // source -> starting point
      for (int sink = 0; sink < m_size; ++sink){ // sink -> ending point 
        if (source == sink){
          continue;
        } else if ( m_conn[source][im] != 0 &&
                    m_conn[im][sink] != 0 &&
                    m_conn[source][sink] > m_conn[source][im] + m_conn[im][sink]){
                  
                   m_conn[source][sink] = m_conn[source][im] + m_conn[im][sink];

        }
      }
    }
  }
	recalcFW = false;
}
// will give us the cheapest path between two vertices
double WGraph::cheapestCost(VertexID i, VertexID j){
  if (recalcFW){
    calcFW();
  }
  return m_conn[i][j]; 
}
/*
Produces the MST of the adjacency matrix
the total cost of the MST is outputted to the terminal as well
*/
void WGraph::computeMST(){
    int count = 0; // this will track the total cost of the MST
    int nodeSetLength = m_size; // The length of the collection of sets
    AdjacentNodes resultList[m_size]; // The array of AdjacentNodes will hold the resulting nodes to be added to the MST
    int currentAddition = 0; // tracks the index of result list to insert into 
    std::priority_queue<AdjacentNodes> edgeList; // Priority queue that holds AdjacencyNodes sorted least to greatest by weight
    std::set<int>* nodeSets = new std::set<int>[m_size]; // the collection of sets to make sure an edge hasn't been visited
    // Populates the collection of sets
    for (int k = 0; k < m_size; ++k){
        nodeSets[k].insert(k);
    }
   // Populates the edge list queue
    for (int i = 0; i < m_size - 1; ++i){
        for (int j = i+1; j < m_size; ++j){
            //this only iterates through the top portion of the matrix
            if (m_adj[i][j] != 0){ // makes sure the current index isnt a 0, meaning there is no connection
                // creates an Adjacency node with the start index being i, the end index being j, and the weight being the matrix's current index
                AdjacentNodes currNode(i,j,m_adj[i][j]); 
                currNode.m_weight *= -1; // this makes it so the priority queue is sorted least to greatest
                edgeList.push(currNode); // pushes the node into the edgelist set
            }
        }
    }
    // main loop that continues until there are no valid edges to add
    while (nodeSetLength > 1 && edgeList.size() > 0){
        // grabs the node with the cheapest weight
        AdjacentNodes nextNode = edgeList.top(); 
        edgeList.pop(); // removes the edge from the queue
        int start = nextNode.m_startNode; // store the start node
        int end = nextNode.m_endNode; // store the end node
        int startSet = -1; // the index of the set that the start node is in
        int endSet = -1; // the index of the set that the end node is in
        //finds the index of the node the start node is in
        for (int i = 0; i < nodeSetLength; i++){
            if (nodeSets[i].count(start) > 0){
                startSet = i;
                break;
            }
        }
        //finds the index of the node the end node is in
        for (int i = 0; i < nodeSetLength; i++){
            if (nodeSets[i].count(end) > 0){
                endSet = i;
                break;
            }
        }

        // Adds the node to the mst
        if (startSet != endSet){
            nextNode.m_weight *= -1; // changes the nodes weight so it is not a negative value
            resultList[currentAddition++] = nextNode; // adds the node to result list
            count += nextNode.m_weight; // increments the total weight with the nextnodes weight
            nodeSets[startSet].insert(nodeSets[endSet].begin(),nodeSets[endSet].end()); // merges the two sets
            nodeSets[endSet].clear(); // clears the old set to declutter
            // shifts the rest of the indexes to fill the gap from merging
            for (int i = endSet; i < nodeSetLength - 1; i++){
                nodeSets[i] = nodeSets[i + 1];
            }
            --nodeSetLength; // decrements the nodeSetLength by 1
        }
    }
    WGraph makeMST(m_size); // make a new WGraph object initialized to the size of m_size
    // Loop through result list and adding each index to makeMST as a new edge
    for (int i = 0; i < m_size; i++){
        if (resultList[i].m_weight != 0){
            makeMST.addEdge(resultList[i].m_startNode,resultList[i].m_endNode,resultList[i].m_weight);
        }
    }
    makeMST.display(); // display the mst matrix
    std::cout << "MST cost: " << count << std::endl; // display the total cost of the matrix to the terminal
    delete[] nodeSets; // deallocate nodeSets from memory
}

/*
Displays the adjacency matrix to the terminal
*/
void WGraph::display(){
    for (int i = 0; i < m_size; i++){
        for (int j = 0; j < m_size; j++){
            std::cout << m_adj[i][j] << " ";
        }
        std::cout << std::endl;
    }
}