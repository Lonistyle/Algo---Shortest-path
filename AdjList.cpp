#include "AdjList.h"

AdjList::AdjList() :m_Head(nullptr), m_Tail(nullptr)
{
}

AdjList::Node::Node(int i_NumberOfVertex, int i_Weight)
{
	m_VertexNumber = i_NumberOfVertex;
	m_WeightEdge = i_Weight;
	m_NextAdjacent = nullptr;
}

AdjList::~AdjList()
{
	Node* currentNode = m_Head;
	if (currentNode != nullptr)
	{
		while (currentNode->m_NextAdjacent != nullptr)
		{
			Node* nextNode = currentNode->m_NextAdjacent;
			delete currentNode;
			currentNode = nextNode;
		}
	}
}

AdjList::Node* AdjList::findPrevVertexAdjacent(int i_AdjacentVertex)
{
	AdjList::Node* currentNode = m_Head;

	while (currentNode->m_NextAdjacent != nullptr)
	{
		if (currentNode->m_NextAdjacent->m_VertexNumber == i_AdjacentVertex)
		{
			return currentNode;
		}

		currentNode = currentNode->m_NextAdjacent;
	}

	return nullptr;
}

void AdjList::RemoveSpecificNode(int i_AdjacentVertex)
{
	AdjList::Node* removeNode;

	if (m_Head->m_VertexNumber == i_AdjacentVertex)
	{
		removeNode = m_Head;
		m_Head = m_Head->m_NextAdjacent;
		
		if (AdjListIsEmpty() == true)
		{
			MakeEmptyList();
		}
	}
	else 
	{
		Node* prevNode = findPrevVertexAdjacent(i_AdjacentVertex);
		removeNode = prevNode->m_NextAdjacent;

		prevNode->m_NextAdjacent = prevNode->m_NextAdjacent->m_NextAdjacent;
	}
}

bool AdjList::AdjListIsEmpty()
{
	bool isEmpty = false;

	if (m_Head == nullptr)
	{
		isEmpty = true;
	}

	return isEmpty;
}

void AdjList::MakeEmptyList()
{
	m_Head = m_Tail = nullptr;
}

int AdjList::RemoveFromTail()
{
	Node* curr = m_Head;
	while (curr->m_NextAdjacent != nullptr)
		curr = curr->m_NextAdjacent;

	return curr->m_VertexNumber;
}

bool AdjList::AddNodeToEndOfList(int i_NumberOfVertex, int i_WeightEdge)
{
	bool isAddedSuccssefully = true;
	Node* newNode = new Node(i_NumberOfVertex, i_WeightEdge);

	if (newNode == nullptr)
	{
		isAddedSuccssefully = false;
	}
	else
	{
		if (AdjListIsEmpty() == true)
		{
			m_Tail = m_Head = newNode;
		}
		else
		{
			m_Tail->m_NextAdjacent = newNode;
			m_Tail = newNode;
		}
	}

	return isAddedSuccssefully;
}

int AdjList::RemoveNodeFromTheStartOfTheList()
{

	Node* temp = m_Head;
	m_Head=m_Head->m_NextAdjacent;
	int ToReturn = temp->m_VertexNumber;
	delete temp;
	return ToReturn;
}
