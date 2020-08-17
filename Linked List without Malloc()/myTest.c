#include "list.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

/*
    - This is the test file for assignment one created by Siavash Rezghighomi.
    - This test files performes and test all the list.h files.
    - Some test cases have been borrowed from the sampleTest from Dr. Brian Fraser.
*/

// Macro for custom testing; does exit(1) on failure.
#define CHECK(condition) do{ \
    if (!(condition)) { \
        printf("ERROR: %s (@%d): failed condition \"%s\"\n", __func__, __LINE__, #condition); \
        exit(1);\
    }\
} while(0)

// For checking the "free" function called
static int complexTestFreeCounter = 0;
static void complexTestFreeFn(void* pItem) 
{
    CHECK(pItem != NULL);
    complexTestFreeCounter++;
}

// For searching
static bool itemEquals(void* pItem, void* pArg) 
{
    return (pItem == pArg);
}

static void testComplex()
{
    // Creats an empty list called pList1, checks its size and head pointer
    List* pList1 = List_create();
    CHECK(pList1 != NULL);
    CHECK(List_count(pList1) == 0);

    // Adds a new node to the created pList1
    // Checks its size, currentItem pointer and number of the nodes in the pList1
    int added = 41;
    CHECK(List_add(pList1, &added) == 0);
    CHECK(List_count(pList1) == 1);
    CHECK(List_curr(pList1) == &added);

    // Inserts a new node to the created pList1
    // Checks its size, currentItem pointer and number of the nodes in the pList1
    int inserted = 42;
    CHECK(List_insert(pList1, &inserted) == 0);
    CHECK(List_count(pList1) == 2);
    CHECK(List_curr(pList1) == &inserted);
    
    // Prepends a new node to the created pList1
    // Checks its size, currentItem pointer and number of the nodes in the pList1
    int prepended = 43;
    CHECK(List_prepend(pList1, &prepended) == 0);
    CHECK(List_count(pList1) == 3);
    CHECK(List_curr(pList1) == &prepended);
    
    // Appends a new node to the created pList1
    // Checks its size, currentItem pointer and number of the nodes in the pList1
    int appended = 44;
    CHECK(List_append(pList1, &appended) == 0);
    CHECK(List_count(pList1) == 4);
    CHECK(List_curr(pList1) == &appended);

    // Testing: Next through it all (from before list)
    CHECK(List_first(pList1) == &prepended);
    CHECK(List_prev(pList1) == NULL);
    CHECK(List_next(pList1) == &prepended);
    CHECK(List_next(pList1) == &inserted);
    CHECK(List_next(pList1) == &added);
    CHECK(List_next(pList1) == &appended);
    CHECK(List_next(pList1) == NULL);
    CHECK(List_next(pList1) == NULL);

    // Testing: Prev through it all
    // Testing: Starting from past end
    CHECK(List_last(pList1) == &appended);
    CHECK(List_next(pList1) == NULL);
    CHECK(List_prev(pList1) == &appended);
    CHECK(List_prev(pList1) == &added);
    CHECK(List_prev(pList1) == &inserted);
    CHECK(List_prev(pList1) == &prepended);
    CHECK(List_prev(pList1) == NULL);
    CHECK(List_prev(pList1) == NULL);

    // Testing: Remove first
    CHECK(List_first(pList1) == &prepended);
    CHECK(List_remove(pList1) == &prepended);
    CHECK(List_curr(pList1) == &inserted);
    
    // Testing: Trim last
    CHECK(List_trim(pList1) == &appended);
    CHECK(List_curr(pList1) == &added);

    // Testing: Free remaining 2 elements
    complexTestFreeCounter = 0;
    List_free(pList1, complexTestFreeFn);
    CHECK(complexTestFreeCounter == 2);


    // Testing: Concat and Search
    int one = 1;
    int two = 2;
    int three = 3;
    int four = 4;

    // Creats a new list called pList2
    // Checks its size, head pointer and number of the nodes in the pList
    List* pList2 = List_create();
    CHECK(pList2 != NULL);
    CHECK(List_count(pList2) == 0);

    // Adds 2 new node to the created pList2
    List_add(pList2, &one);
    List_add(pList2, &two);
    CHECK(List_count(pList2) == 2);

    // Peforming search on pList 2
    CHECK(List_search(pList2, itemEquals, &two) == &two);


    // Creats a new list called pList3
    // Checks its size, head pointer and number of the nodes in the pList
    List* pList3 = List_create();
    CHECK(pList3 != NULL);
    CHECK(List_count(pList3) == 0);

    // Adds 2 new node to the created pList3
    List_add(pList3, &three);
    List_add(pList3, &four);
    CHECK(List_count(pList3) == 2);

    // Peforming search on pList 3
    CHECK(List_search(pList3, itemEquals, &four) == &four);

    // Search
    // At line #120, we are passing an empty list so it should return NULL
    CHECK(List_search(pList1, itemEquals, &one) == NULL);

    
    // Concatenating and checking the new size of pList2
    List_concat(pList2, pList3);
    CHECK(List_count(pList2) == 4);
}

int main(int argCount, char *args[]) 
{
    testComplex();

    // We got here?!? PASSED!
    printf("********************************\n");
    printf("           PASSED\n");
    printf("********************************\n");
    return 0;
}
