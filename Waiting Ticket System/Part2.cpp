//**
//* @brief The implementation of the Queue class will be found in this file. 
//*		   This file also includes the header function (Part2h.h). 
//*		   This code will be employed in the test drive (Part2-main.cpp).
//*
//**
#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <ctime>
#include "Part2h.h"
using namespace std;
using namespace QueueSiavash;

Queue::Queue()
{
    front = nullptr;
    back = nullptr;
}

Queue::~Queue()
{
    while (empty() == false)
    {
        QueueNodePtr discard;
        discard = front;
        front = front->link;
        if(front == nullptr)
        {
            back = nullptr;
        }
        delete discard;
    }
}

bool Queue::empty()
{
    return (front == nullptr);
}

void Queue::add(long &seconds)
{
    if(empty())
    {
        front = new QueueNode;
        front->data = seconds;
        front->link = nullptr;
        back = front;
    }
    else
    {
        QueueNodePtr temp_ptr;
        temp_ptr = new QueueNode;
        temp_ptr->data = seconds;
        temp_ptr->link = nullptr;
        back->link = temp_ptr;
        back = temp_ptr;
    }
}

long Queue::remove(long &seconds)
{
    long waitTime;
    if (empty())
    {
        cout << "The line is empty" << endl;
        exit(1);
    }
    else
    {
        waitTime = (seconds - front->data);
        QueueNodePtr discard;
        discard = front;
        front = front->link;
        if(front == nullptr)
        {
            back = nullptr;
        }
        delete discard;
        return waitTime;
    }
}

long Queue::updateWaitTime(long &newTime)
{
    long averageWaitTime;
	long wait[3] = { 0, 0, 0 };
    int temp1 = 0;
    for(int i(2); i > 0; i--)
    {
        wait[i] = wait[i - 1];
    }
    wait[0] = newTime;
    for(int j(1); j < 3; j++)
    {
        if(wait[j] == 0)
        {
            temp1++;
        }
    }
    averageWaitTime = ((wait[0] + wait[1] + wait[2]) / (3 - temp1));
    return averageWaitTime;
}