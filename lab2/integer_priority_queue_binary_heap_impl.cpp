#include "integer_priority_queue.hpp"
#include "integer_vector.hpp"

#include <cassert>
#include <iostream>


struct IntegerPriorityQueue
{
	IntegerVector m_heapItems;
};


IntegerPriorityQueue * IntegerPriorityQueueCreate ()
{
	IntegerPriorityQueue * pPQ = new IntegerPriorityQueue;
	IntegerVectorInit( pPQ->m_heapItems );
	IntegerVectorPushBack( pPQ->m_heapItems, 0 ); // reserved cell
	return pPQ;
}


void IntegerPriorityQueueDestroy ( IntegerPriorityQueue * _pPQ )
{
	IntegerVectorDestroy( _pPQ->m_heapItems );
	delete _pPQ;
}



void IntegerPriorityQueueClear ( IntegerPriorityQueue & _pq )
{
	_pq.m_heapItems.m_nUsed = 1;
}


bool IntegerPriorityQueueIsEmpty ( const IntegerPriorityQueue & _pq )
{
	return _pq.m_heapItems.m_nUsed == 1;
}


void IntegerPriorityQueueSwim ( IntegerPriorityQueue & _pq, int _pos )
{
	int * pData = _pq.m_heapItems.m_pData;

	while ( _pos > 1 && ( pData[ _pos / 2 ] > pData[ _pos ] ) )
	{
		std::swap( pData[ _pos / 2 ], pData[ _pos ] );
		_pos = _pos / 2;
	}
}


void IntegerPriorityQueueSink ( IntegerPriorityQueue & _pq, int _pos )
{
	int maxPosition = _pq.m_heapItems.m_nUsed - 1;
	while ( 2 * _pos <= maxPosition )
	{
		int childPos = 2 * _pos;
		if ( childPos < maxPosition && _pq.m_heapItems.m_pData[ childPos ] > _pq.m_heapItems.m_pData[ childPos + 1 ] )
			++ childPos;

		if ( _pq.m_heapItems.m_pData[ _pos ] < _pq.m_heapItems.m_pData[ childPos ] )
			break;

		std::swap( _pq.m_heapItems.m_pData[ _pos ], _pq.m_heapItems.m_pData[ childPos ] );
		_pos = childPos;
	}
}


void IntegerPriorityQueueInsert ( IntegerPriorityQueue & _pq, int _key )
{
	IntegerVectorPushBack( _pq.m_heapItems, _key );
	IntegerPriorityQueueSwim( _pq, _pq.m_heapItems.m_nUsed - 1 );
}


int IntegerPriorityQueueMin ( const IntegerPriorityQueue & _pq )
{
	assert( ! IntegerPriorityQueueIsEmpty( _pq ) );
	return _pq.m_heapItems.m_pData[ 1 ];
}


void IntegerPriorityQueueDeleteMin ( IntegerPriorityQueue & _pq )
{
	assert( !IntegerPriorityQueueIsEmpty( _pq ) );
	std::swap( _pq.m_heapItems.m_pData[ 1 ], _pq.m_heapItems.m_pData[ _pq.m_heapItems.m_nUsed - 1 ] );
	IntegerVectorPopBack( _pq.m_heapItems );
	IntegerPriorityQueueSink( _pq, 1 );
}

