#pragma once

/*
* Adjacent List object --> each vertex recived adjacent list like that.
*/

class AdjList
{
public:

	/* Node for the adjacent list*/
	struct Node
	{
		int m_VertexNumber;
		int m_WeightEdge;
		Node* m_NextAdjacent;

		Node(int i_NumberOfVertex = 0, int i_WeightEdge = 0);
		~Node() {}
	};

private:
	Node* m_Head;
	Node* m_Tail;

public:
	/* C'tor + D'tor */
	AdjList();
	~AdjList();

	/* Getter */
	AdjList::Node* getHead() { return m_Head; }

	/* standart neccessary functions for list */
	bool AdjListIsEmpty();
	void MakeEmptyList();
	int RemoveFromTail();
	bool AddNodeToEndOfList(int i_NumberOfVertex, int i_WeightEdge = 0);
	int RemoveNodeFromTheStartOfTheList();
	void RemoveSpecificNode(int i_AdjacentVertex);
	AdjList::Node* findPrevVertexAdjacent(int i_AdjacentVertex);
};

