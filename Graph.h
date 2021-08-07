#pragma once
#include <iomanip>
#include <chrono>
#include "Vertex.h"

/*
* Graph object --> The graph and all the methodes at the project.
* There is also a static function to initialize the graph.
*/

/* Array to save the depth for each vertex. */
struct ArrayNode
{
	int Depth;
	bool Visited;
};

class Graph
{
private:
	int m_NumberOfVertices;
	Vertex* m_VerticesArray;
	ArrayNode* m_DepthArray;
	int m_StartVertex;
	int m_EndVertex;

public:
	/* C'tor + D'tor */
	Graph(int i_NumberOfVertices = 0, int i_StartVertex = 0, int i_EndVertex = 0);
	~Graph();

	/* initialize functions */
	ArrayNode* InitVisitArray();
	void InitFileGraph(int i_NumberOfVertices, int i_OriginalVertex, int i_DestinationVertex);
	static Graph* Init();

	/* Getters */
	int GetStartPoint() { return m_StartVertex; }
	int GetEndPoint() { return m_EndVertex; }

	/* functions for the algorithem - BFS + transpose + delete unnecessary edges */
	ArrayNode* BFS(int i_StartingPoint);
	Graph* Transpose();
	void DeleteUnnecessaryEdges();
	void RunTime();
	void ShortestPathsFromASingleSourceToASingleDestination();

	/* print functions */
	void PrintGraph();
	void PrintEdges();
	void PrintVertex(int i_VertexNumber);

	/* standart neccessary functions for the graph */
	AdjList* GetAdjList(int i_VerticeX);
	void RemoveEdge(int i_VerticeX, int i_VerticeY);
	void MakeEmptyGraph(int i_NumberOfVertices);
	void AddEdge(int i_VertexX, int i_VertexY);
	void DeleteUnnecessaryVertices();
	void ReadGraph(char* i_FileName);
	int AddEdge(int i_VerticeX, int i_VerticeY, int i_WeightEdge);
	bool IsAdjacent(int i_VerticeX, int i_VerticeY);
	int isEmpty();
};



