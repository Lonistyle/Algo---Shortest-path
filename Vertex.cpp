#include "Vertex.h"
#include <cmath>

Vertex::Vertex()
{
	m_VertexDegree = -1;
	m_AdjacentList = new AdjList();
}

Vertex::~Vertex()
{
	delete m_AdjacentList;
}

bool Vertex::IsDeleted()
{
	bool Ret = false;

	if (m_AdjacentList == nullptr)
	{
		Ret = true;
	}

	return Ret;
}

bool Vertex::setVertexDegree(int i_VertexDegree)
{
	bool isSetSuccessfully = false;

	if (i_VertexDegree < m_VertexDegree)
	{
		m_VertexDegree = i_VertexDegree;
		isSetSuccessfully = true;
	}

	return isSetSuccessfully;
}

AdjList::Node* Vertex::findPrevAdjacent(int i_VertexNamber)
{
	return m_AdjacentList->findPrevVertexAdjacent(i_VertexNamber);
}

AdjList* Vertex::getVertexAdjList()
{
	return m_AdjacentList;
}
