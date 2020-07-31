#ifndef PART2H_HPP
#define PART2H_HPP
#include <iostream>

namespace QueueSiavash
{
  struct QueueNode
    {
        long data;
        QueueNode *link;
    };
    typedef QueueNode* QueueNodePtr;
    
    class Queue
    {   
    public:
        Queue();
		~Queue();
		bool empty();
        void add(long &item);
        long remove(long &seconds);
        long updateWaitTime(long &newTime);
		long wait[3] = {0, 0, 0};

    private:
        QueueNodePtr front;
        QueueNodePtr back;
    };
}

#endif