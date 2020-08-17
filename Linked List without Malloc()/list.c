#include "list.h"
#include <stdio.h>
#include <stdbool.h>

// These are the ints and arrays that I use to keep track
// of the removed nodes and head pointers. I have defined 
// an index for both nodes and heads. By using it, the code
// keeps track of them by storing their indexes in the seperate
// arrays for nodes and heads.
static int nodesCounter = 0;
static int headCounter = 0;
static int trackingNodeIndex = 0;
static int trackingNodeArray[100];
static int trackingHeadIndex = 0;
static int trackingHeadArray[10];
static Node nodeArray[LIST_MAX_NUM_NODES];
static List* headArray[LIST_MAX_NUM_HEADS];


List* List_create()
{
    headCounter += 1;
    //If there are available head pointers throu head array
    if(headCounter <= 10) 
    {
        List* temp = &headArray[headCounter - 1];
        temp->start = temp->currentItem = temp->end = NULL;
        temp->size = 0;
        temp->headIndex = headCounter - 1;
        return temp;        
    }
    
    //If there are available head pointers throu list of removed heads
    else if (headCounter > 10)
    {
        if(trackingHeadIndex == 0 || trackingHeadIndex > 10)
        {
            printf("\nNo head pointer is available\n");
            return NULL;
        }
        else if (trackingHeadIndex > 0 && trackingHeadIndex <= 10)
        {
            List* temp = &headArray[trackingHeadArray[trackingHeadIndex - 1]];
            temp->start = temp->currentItem = temp->end = NULL;
            temp->size = 0;
            temp->headIndex = trackingHeadArray[trackingHeadIndex - 1];
            trackingHeadIndex -= 1;
            return temp;
        }
    }
}


int List_count(List* pList)
{
    return pList->size;
}


void* List_first(List* pList)
{
    int listSize = List_count(pList);
    if (listSize == 0)
    {
        pList->currentItem = NULL;
        pList->withinList = false;
        return NULL;
    }

    //Checks if the list is not empty
    else
    {
        pList->currentItem = pList->start; 
        pList->withinList = true;
        return pList->currentItem->data;
    }
}


void* List_last(List* pList)
{
    int listSize = List_count(pList);
    if (listSize == 0)
    {
        pList->currentItem = NULL;
        pList->withinList = false;
        return NULL;
    }

    //Checks if the list is not empty
    else
    {
        pList->currentItem = pList->end;
        pList->withinList = true; 
        return pList->end->data; 
    }
        
}


void* List_next(List* pList)
{
    if(pList->size == 0)
    {
        return NULL;
    }

    //Checks if the current item is within the list
    else if (pList->withinList)
    {
        if(pList->currentItem == pList->end)
        {
            pList->withinList = false;
            pList->beyondEnd = true;
            pList->currentItem = NULL;
            return NULL;
        }

        else 
        { 
            pList->currentItem = pList->currentItem->next;
            return pList->currentItem->data;
        }
    }

    //Checks if the current item is beyond the start
    else if(pList->beyondStart)
    {
        pList->currentItem = pList->start;
        pList->beyondStart = false;
        pList->withinList = true;
        return pList->currentItem->data;
    }

    //Checks if the current item is beyond the end
    else if(pList->beyondEnd)
    {
        return NULL;
    }
}


void* List_prev(List* pList)
{
    //Checks if the list is empty
    if(pList->size == 0)
    {
        return NULL;
    }

    //Checks if the current item is within the list
    else if (pList->withinList)
    {
        if(pList->currentItem == pList->start)
        {
            pList->withinList = false;
            pList->beyondStart = true;
            pList->currentItem = NULL; 
            return NULL;
        }
        else
        { 
            pList->currentItem = pList->currentItem->prev;
            return pList->currentItem->data;  
        }
    }

    //Checks if the current item is beyond the end
    else if(pList->beyondEnd)
    {
        pList->currentItem = pList->end;
        pList->beyondEnd = false;
        pList->withinList = true;
        return pList->currentItem->data;
    }

    //Checks if the current item is beyond the start
    else if(pList->beyondStart)
    {
        return NULL;
    }
}


void* List_curr(List* pList)
{
    if (pList->size == 0)
    {
        printf("List is empty, no current item");
        return NULL;
    }
    else
    {
        //printf("\nexit curr");
        return pList->currentItem->data;
    }
}


int List_add(List* pList, void* pItem)
{
    nodesCounter += 1;
    //If there are available nodes throu node array
    if (nodesCounter <= 100)
    {
        Node* newNode = &nodeArray[nodesCounter - 1];
        newNode->nodeIndex = nodesCounter - 1;

        //If the list is empty, just add the new node
        if (pList->size == 0)
        {
            pList->size += 1;
            newNode->data = pItem;
            pList->start = newNode;
            pList->currentItem = newNode;
            pList->end = newNode;
            pList->beyondEnd = pList->beyondStart = false; 
            pList->withinList = true;      
            return 0;
        }

        //If the current pointer is within the pList
        else if (pList->withinList)
        {
            pList->size += 1;
            Node* temp = pList->currentItem->next;
            pList->currentItem->next = newNode;
            newNode->prev = pList->currentItem;
            newNode->next = temp;
            if (temp == NULL)
            {
                pList->end = newNode;
            }
            else
            {
                temp->prev = newNode;
            }
            newNode->data = pItem;
            pList->currentItem = newNode; 
            return 0;
        }
   
        //If the current pointer is before the start of the pList
        else if (pList->beyondStart)
        {
            pList->size += 1;
            newNode->prev = NULL;
            newNode->next = pList->start;
            newNode->data = pItem;
            pList->start->prev = newNode;
            pList->start = newNode;
            pList->currentItem = newNode; 
            pList->withinList = true;                 
            pList->beyondStart = pList->beyondEnd = false; 
            return 0;
        }

        //If the current pointer is beyond the end of the pList
        else if (pList->beyondEnd)
        {
            pList->size += 1;
            newNode->prev = pList->end;
            newNode->next = NULL;
            newNode->data = pItem;
            pList->end->next = newNode;
            pList->end = newNode;
            pList->currentItem = newNode; 
            pList->withinList = true;             
            pList->beyondStart = pList->beyondEnd = false;     
            return 0;
        }
    }

    //If there are available nodes throu list of removed nodes
    else if (nodesCounter > 100)
    {
        if (trackingNodeIndex == 0 || trackingNodeIndex > 100)
        {   
            printf("\nNo node is available\n");
            return -1;
        }
        else if (trackingNodeIndex > 0)
        {
            Node* newNode = &nodeArray[trackingNodeArray[trackingNodeIndex - 1]];
            newNode->nodeIndex = trackingNodeArray[trackingNodeIndex - 1];
            trackingNodeIndex -= 1;

            //If the list is empty, just add the new node
            if (pList->size == 0)
            {
                pList->size += 1;
                newNode->data = pItem;
                pList->start = newNode;
                pList->currentItem = newNode;
                pList->end = newNode;
                pList->beyondEnd = pList->beyondStart = false; 
                pList->withinList = true;                     
                return 0;
            }

            //If the current pointer is within the pList
            else if (pList->withinList)
            {
                Node* temp = pList->currentItem->next;
                pList->currentItem->next = newNode;
                pList->size += 1;
                newNode->prev = pList->currentItem;
                newNode->next = temp;
                if (temp == NULL)
                {
                    pList->end = newNode;
                }
                else
                {
                    temp->prev = newNode;
                }
                newNode->data = pItem;
                pList->currentItem = newNode; 
                return 0;
            }
   
            //If the current pointer is before the start of the pList
            else if (pList->beyondStart)
            {
                pList->size += 1;
                newNode->prev = NULL;
                newNode->next = pList->start;
                newNode->data = pItem;
                pList->start->prev = newNode;
                pList->start = newNode;
                pList->currentItem = newNode; 
                pList->withinList = true;                    
                pList->beyondStart = pList->beyondEnd = false; 
                return 0;
        }

            //If the current pointer is beyond the end of the pList
            else if (pList->beyondEnd)
            {
                pList->size += 1;
                newNode->prev = pList->end;
                newNode->next = NULL;
                newNode->data = pItem;
                pList->end->next = newNode;
                pList->end = newNode;
                pList->currentItem = newNode;
                pList->withinList = true;                     
                pList->beyondStart = pList->beyondEnd = false;   
                return 0;
            } 
        }
    }

    //Failure
    else
        return -1;
}


int List_insert(List* pList, void* pItem)
{
    nodesCounter += 1;
    //If there are available nodes throu node array
    if (nodesCounter <= 100)
    {
        Node* newNode = &nodeArray[nodesCounter - 1];
        newNode->nodeIndex = nodesCounter - 1;

        //If the list is empty, just add the new node
        if (pList->size == 0)
        {
            pList->size += 1;
            newNode->data = pItem;
            pList->start = pList->currentItem = pList->end = newNode;
            pList->beyondEnd = pList->beyondStart = false;
            pList->withinList = true;
            return 0;
        }
        //If the current pointer is within the pList
        else if (pList->withinList)
        {
            Node* temp = pList->currentItem->prev;
            pList->size += 1;
            pList->currentItem->prev = newNode;
            newNode->next = pList->currentItem;
            newNode->prev = temp;
            if (temp == NULL)
            {
                pList->start = newNode;
            }
            else
            {
                temp->next = newNode;
            }
            newNode->data = pItem;
            pList->currentItem = newNode;
            return 0;
        }
    
        //If the current pointer is before the start of the pList
        else if (pList->beyondStart)
        {
            pList->size += 1;
            newNode->prev = NULL;
            newNode->next = pList->start;
            newNode->data = pItem;
            pList->start->prev = newNode;
            pList->start = newNode;
            pList->currentItem = newNode; 
            pList->withinList = true;     
            pList->beyondStart = pList->beyondEnd = false;
            return 0;
        }
        
        //If the current pointer is beyond the end of the pList
        else if (pList->beyondEnd)
        {
            pList->size += 1;
            newNode->prev = pList->end;
            newNode->next = NULL;
            newNode->data = pItem;
            pList->end->next = newNode;
            pList->end = newNode;
            pList->currentItem = newNode; 
            pList->withinList = true;      
            pList->beyondStart = pList->beyondEnd = false; 
            return 0;
        } 
    }
    
    //If there are available nodes throu list of removed nodes
    else if (nodesCounter > 100)
    {
        if (trackingNodeIndex == 0 || trackingNodeIndex > 100)
        {   
            printf("\nNo node is available\n");
            return -1;
        }
        else if (trackingNodeIndex > 0)
        {
            Node* newNode = &nodeArray[trackingNodeArray[trackingNodeIndex - 1]];
            newNode->nodeIndex = trackingNodeArray[trackingNodeIndex - 1];
            trackingNodeIndex -= 1;

        //If the list is empty, just add the new node
         if (pList->size == 0)
            {
                pList->size += 1;
                newNode->data = pItem;
                pList->start = pList->currentItem = pList->end = newNode;
                pList->beyondEnd = pList->beyondStart = false;
                pList->withinList = true;
                return 0;
            }
            //If the current pointer is within the pList
            else if (pList->withinList)
            {
                Node* temp = pList->currentItem->prev;
                pList->size += 1;
                pList->currentItem->prev = newNode;
                newNode->next = pList->currentItem;
                newNode->prev = temp;
                if (temp == NULL)
                {
                    pList->start = newNode;
                }
                else
                {
                    temp->next = newNode;
                }
                newNode->data = pItem;
                pList->currentItem = newNode;
                return 0;
            }
        
            //If the current pointer is before the start of the pList
            else if (pList->beyondStart)
            {
                pList->size += 1;
                newNode->prev = NULL;
                newNode->next = pList->start;
                newNode->data = pItem;
                pList->start->prev = newNode;
                pList->start = newNode;
                pList->currentItem = newNode;
                pList->withinList = true;  
                pList->beyondStart = pList->beyondEnd = false; 
                return 0;
            }
            

            //If the current pointer is beyond the end of the pList
            else if (pList->beyondEnd)
            {
                pList->size += 1;
                newNode->prev = pList->end;
                newNode->next = NULL;
                newNode->data = pItem;
                pList->end->next = newNode;
                pList->end = newNode;
                pList->currentItem = newNode; 
                pList->withinList = true; 
                pList->beyondStart = pList->beyondEnd = false;    
                return 0;
            } 
        }
    }
 
    //Failure
    else
        return -1;
}


int List_append(List* pList, void* pItem)
{
    nodesCounter += 1;
    //If there are available nodes throu node array
    if (nodesCounter <= 100)
    {
        Node* newNode = &nodeArray[nodesCounter - 1];
        newNode->nodeIndex = nodesCounter - 1;

        //If the list is empty, just add the new node
        if (pList->size == 0)
        {
            pList->size += 1;
            newNode->data = pItem;
            pList->start = pList->currentItem = pList->end = newNode;
            pList->beyondEnd = pList->beyondStart = false;
            pList->withinList = true;
            return 0;
        }
        
        //If the list is not empty, look after the ending point
        else
        {
            pList->size += 1;
            newNode->prev = pList->end;
            newNode->next = NULL;
            newNode->data = pItem;
            pList->end->next = newNode;
            pList->end = newNode;
            pList->currentItem = newNode; 
            pList->withinList = true;     
            pList->beyondStart = pList->beyondEnd = false;  
            return 0;
        } 
    }
    
    //If there are available nodes throu list of removed nodes
    else if (nodesCounter > 100)
    {
        if (trackingNodeIndex == 0 || trackingNodeIndex > 100)
        {   
            printf("\nNo node is available\n");
            return -1;
        }
        else if (trackingNodeIndex > 0)
        {
            Node* newNode = &nodeArray[trackingNodeArray[trackingNodeIndex - 1]];
            newNode->nodeIndex = trackingNodeArray[trackingNodeIndex - 1];
            trackingNodeIndex -= 1;

            //If the list is empty, just add the new node
            if (pList->size == 0)
            {
                pList->size += 1;
                newNode->data = pItem;
                pList->start = pList->currentItem = pList->end = newNode;
                pList->beyondEnd = pList->beyondStart = false;
                pList->withinList = true;
                return 0;
            }

            //If the list is not empty, look after the ending point
            else
            {
                pList->size += 1;
                newNode->prev = pList->end;
                newNode->next = NULL;
                newNode->data = pItem;
                pList->end->next = newNode;
                pList->end = newNode;
                pList->currentItem = newNode; 
                pList->withinList = true; 
                pList->beyondStart = pList->beyondEnd = false;      
                return 0;
            } 
        }
    }
}


int List_prepend(List* pList, void* pItem)
{
    nodesCounter += 1;
    //If there are available nodes throu node array
    if (nodesCounter <= 100)
    {
        Node* newNode = &nodeArray[nodesCounter - 1];
        newNode->nodeIndex = nodesCounter - 1;

        //If the list is empty, just add the new node
        if (pList->size == 0)
        {
            pList->size += 1;
            newNode->data = pItem;
            pList->start = pList->currentItem = pList->end = newNode;
            pList->beyondEnd = pList->beyondStart = false;
            pList->withinList = true;
            return 0;
        }

        //If the list is not empty, look after the starting point
        else
        {
            pList->size += 1;
            newNode->prev = NULL;
            newNode->next = pList->start;
            newNode->data = pItem;
            pList->start->prev = newNode;
            pList->start = newNode;
            pList->currentItem = newNode;
            pList->withinList = true;    
            pList->beyondStart = pList->beyondEnd = false;  
            return 0;
        }
    }
    //If there are available nodes throu list of removed nodes
    else if (nodesCounter > 100)
    {
        if (trackingNodeIndex == 0 || trackingNodeIndex > 100)
        {   
            printf("\nNo node is available\n");
            return -1;
        }
        else if (trackingNodeIndex > 0)
        {
            Node* newNode = &nodeArray[trackingNodeArray[trackingNodeIndex - 1]];
            newNode->nodeIndex = trackingNodeArray[trackingNodeIndex - 1];
            trackingNodeIndex -= 1;

            //If the list is empty, just add the new node
            if (pList->size == 0)
            {
                pList->size += 1;
                newNode->data = pItem;
                pList->start = pList->currentItem = pList->end = newNode;
                pList->beyondEnd = pList->beyondStart = false;
                pList->withinList = true;
                return 0;
            }

            //If the list is not empty, look after the starting point
            else
            {
                pList->size += 1;
                newNode->prev = NULL;
                newNode->next = pList->start;
                newNode->data = pItem;
                pList->start->prev = newNode;
                pList->start = newNode;
                pList->currentItem = newNode; 
                pList->withinList = true;    
                pList->beyondStart = pList->beyondEnd = false;  
                return 0;
            } 
        }
    }
}

void* List_remove(List* pList)
{
    if (pList->size == 0 && pList->beyondEnd == true && pList->beyondStart == true)
    {
        printf("\nNo item to get removed, the given list is empty or invalid");
        return NULL;
    }

    //When the current is within the start and end of the list, neither start or end
    else if (pList->withinList && pList->currentItem != pList->end && pList->currentItem != pList->start)
    {
        Node* temp = pList->currentItem;
        pList->currentItem = pList->currentItem->next;
        pList->currentItem->prev = temp->prev;
        temp->prev->next = pList->currentItem;
        trackingNodeArray[trackingNodeIndex] = temp->nodeIndex;     //Looks after the removed node
        trackingNodeIndex += 1;
        pList->size -= 1;
        return temp->data;
    }

    //When the current is pointing to the start item
    else if (pList->withinList && pList->currentItem == pList->start)
    {
        Node* temp = pList->currentItem;
        pList->currentItem = pList->currentItem->next;
        pList->currentItem->prev = NULL;
        pList->start->next = pList->start->prev = NULL;
        trackingNodeArray[trackingNodeIndex] = temp->nodeIndex;     //Looks after the removed node
        trackingNodeIndex += 1;
        pList->size -= 1;
        pList->start = pList->currentItem;
        return temp->data;
    }

    //When the current is pointing to the end item
    else if (pList->withinList && pList->currentItem == pList->end)
    {
        Node* temp = pList->currentItem;
        pList->end->prev = NULL;
        pList->end = pList->currentItem->prev;
        pList->end->next = NULL;
        pList->currentItem = NULL;
        pList->withinList = false;
        pList->beyondEnd = true;
        return temp->data;
    }
}

void List_concat(List* pList1, List* pList2)
{
    if (pList1->size == 0)
    {
        pList1->size += pList2->size;
        pList1->start = pList2->start;
        pList1->end = pList2->end;
        pList2->currentItem = NULL;
        trackingHeadArray[trackingHeadIndex] = pList2->headIndex;       //Looks after the removed head pointer
        trackingHeadIndex += 1;
    }

    else
    {
        pList1->size += pList2->size;
        pList1->end->next = pList2->start;
        pList2->start->prev = pList1->end;
        pList1->end = pList2->end;
        trackingHeadArray[trackingHeadIndex] = pList2->headIndex;       //Looks after the removed head pointer
        trackingHeadIndex += 1;
        pList2->start = NULL;
        pList2->currentItem = NULL;
        pList2->end = NULL;
    }
}

void List_free(List* pList, FREE_FN pItemFreeFn)
{
    //Looking after the head pointer
    trackingHeadArray[trackingHeadIndex] = pList->headIndex; //check
    trackingHeadIndex += 1;

    //Removing the nodes and make them reusable 
    //It starts deleting from the start of the list and continues
    //till it reaches the end
    while (pList->start != NULL)
    {
        (*pItemFreeFn)(pList->start->data); //freeing the item
        trackingNodeArray[trackingNodeIndex] = pList->start->nodeIndex; //reserving the node
        trackingNodeIndex += 1;
        Node* temp = pList->start->next;        //Advancing to the next node after the start
        pList->start->next = pList->start->prev = NULL;
        pList->start = temp;
    }
    pList->size = 0;        //Since there are no nodes left, the size of the list is zero
}


void* List_trim(List* pList)
{
    //If the list is empty
    if(pList->size == 0)
    {
        printf("\nList is empty, try again with a valid list\n");
        return NULL;
    }

    //If the list is not empty
    else
    {
        Node* temp = pList->end;
        pList->end = temp->prev;
        pList->end->next = NULL;
        pList->currentItem = pList->end;
        trackingNodeArray[trackingNodeIndex] = temp->nodeIndex;     //Looks after the removed node
        trackingNodeIndex += 1;        
        return temp->data;
    }
}


void* List_search(List* pList, COMPARATOR_FN pComparator, void* pComparisonArg)
{
    //If the current item is beyond the end of the list or the list is empty
    if (pList->beyondEnd || pList->size == 0)
    {
        printf("\nThe current item is beyond the end of the list\n");
        return NULL;
    }

    //If the current item is beyond the start of the list
    else if (pList->beyondStart)
    {
        int success = 0;
        pList->currentItem = pList->start;
        while (pList->currentItem != NULL)      // Searching the list for the given item (data)
        {
            if ((*pComparator)(pList->currentItem->data, pComparisonArg) == 1)
            {
                success = 1;        //The match has found
                return pList->currentItem->data;
            }
            pList->currentItem = pList->currentItem->next;
        }

        if (success == 0)       //Means no match has found
        {
            pList->currentItem = NULL;
            pList->withinList = pList->beyondStart = false;
            pList->beyondEnd = true;
            return NULL;
        }
    }

    //If the current item is within the list
    else if (pList->withinList)
    {
        int success = 0;
        while (pList->currentItem != NULL)
        {
            if ((*pComparator)(pList->currentItem->data, pComparisonArg) == 1)
            {
                success = 1;        //The match has found
                return pList->currentItem->data;   
            }
            pList->currentItem = pList->currentItem->next;
        }

        if (success == 0)       //Means no match has found
        {
            pList->currentItem = NULL;
            pList->withinList = pList->beyondStart = false;
            pList->beyondEnd = true;
            return NULL;
        }
    }
}
