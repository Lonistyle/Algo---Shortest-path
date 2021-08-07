#pragma once
#include "AdjList.h"

/*
* Vertex object --> the vertices of graph.
*/

class Vertex
{
private:
	int m_VertexDegree;
	AdjList* m_AdjacentList;

public:
	/* C'tor + D'tor */
	Vertex();
	~Vertex();

	/* Getters + Setters */
	AdjList* GetHead() { return m_AdjacentList; }
	bool setVertexDegree(int i_VertexDegree);
	AdjList* getVertexAdjList();

	/* Check if delete AND find the desired adjacent for vertex. */
	bool IsDeleted();
	void DeleteVertex() { m_AdjacentList = nullptr; }
	AdjList::Node* findPrevAdjacent(int i_VertexNamber);
};

