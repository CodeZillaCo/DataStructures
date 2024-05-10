#include <stdio.h>
#include <stdlib.h>
#include <math.h>
class heap 
{
public:
    int *arr, cur, n, *arrs, curs, ns;
    heap() 
    {
        cur = -1;
        n = -1;
        curs = -1;
        ns = -1;
        arr = (int *)malloc(sizeof(int));
        arrs = (int *)malloc(sizeof(int));
    }
    int insert(int);
    void display();
    void insertheap(int);
    int deletion();
    void inserts(int);
    void sort();
    int search(int);
    int searchindex(int);
    int reduceheapify();
    void heapify(int);
};

int main() 
{
    heap t;
    int ch;
    while (1) 
    {
        printf("\n1.Insert\n2.Display\n3.Deletion\n4.Sorting\n5.Search\n6.Reduce an element\n7.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch) 
        {
        case 1: 
        {
            int num;
            printf("\nEnter the number : ");
            scanf("%d", &num);
            if (t.insert(num)) 
            {
                printf("\nInserted Successfully");
            } 
            else 
            {
                printf("\nCannot be inserted");
            }
            break;
        }
        case 2: 
        {
            t.display();
            break;
        }
        case 3: 
        {
            if (t.deletion()) 
            {
                printf("\nDeleted successfully");
            } 
            else 
            {
                printf("\nCannot be deleted");
            }
            break;
        }
        case 4: 
        {
            t.sort();
            break;
        }
        case 5: 
        {
            int num;
            printf("\nEnter the number : ");
            scanf("%d", &num);
            if (t.search(num)) 
            {
                printf("\nData is found");
            } 
            else 
            {
                printf("\nData is not found");
            }
            break;
        }
        case 6: 
        {
            if (t.reduceheapify()) 
            {
                printf("\nReduced the given elements successfully");
            } 
            else 
            {
                printf("\nThe given elements cannot be reduced");
            }
            break;
        }
        case 7: 
        {
            exit(1);
            break;
        }
        }
        getchar();
        getchar();
    }
    return 0;
}

//Method to insert an element in the heap
int heap::insert(int num) 
{
    if (cur == -1) 
    {
        cur = 0;
        n = 0;
        arr = (int *)malloc(sizeof(int) * (pow(2, n + 1)));
        arr[cur] = num;
        return 1;
    } 
    else 
    {
        if (cur == (pow(2, n + 1)) - 2) 
        {
            n++;
            arr = (int *)realloc(arr, sizeof(int) * (pow(2, n) + 1));
            cur++;
            arr[cur] = num;
            insertheap(cur);
            return 1;
        } 
        else 
        {
            cur++;
            arr[cur] = num;
            insertheap(cur);
            return 1;
        }
    }
}
//Method for heapify operation
void heap::insertheap(int cur) 
{
    int parent, temp;
    if (cur % 2 == 0) 
    {
        parent = (cur - 2) / 2;
    } 
    else 
    {
        parent = (cur - 1) / 2;
    }
    if (arr[parent] > arr[cur]) 
    {
        return;
    } 
    else 
    {
        temp = arr[parent];
        arr[parent] = arr[cur];
        arr[cur] = temp;
        insertheap(parent);
    }
}
//Method to display all the elements in the heap
void heap::display() 
{
    int i;
    for (i = 0; i <= cur; i++) 
    {
        printf("%d ", arr[i]);
    }
}
//Method to delete an element in the heap
int heap::deletion()  
{
    if (cur == -1) 
    {
        return 0; // Heap is empty, deletion not possible
    } 
    else 
    {
        int deletedItem = arr[0]; // Store the root element to return later

        arr[0] = arr[cur]; // Replace root with the last element
        cur--;             // Decrease the size of the heap

        // Restore heap property
        heapify(0);
        inserts(deletedItem);
        return 1; // Deletion successful
    }
}
//Method to insert deleted element in the another array
void heap::inserts(int num) 
{
    if (curs == -1) 
    {
        curs = 0;
        ns = 0;
        arrs = (int *)malloc(sizeof(int) * (pow(2, ns + 1)));
        arrs[curs] = num;
    } 
    else 
    {
        if (curs == (pow(2, ns + 1)) - 2) 
        {
            ns++;
            arrs = (int *)realloc(arrs, sizeof(int) * (pow(2, ns) + 1));
            curs++;
            arrs[curs] = num;
        } 
        else 
        {
            curs++;
            arrs[curs] = num;
        }
    }
}
//Method to display the sorted array
void heap::sort() 
{
    int i;
    printf("\nThe sorted array is : ");
    for (i = 0; i <= curs; i++) 
    {
        printf("%d ", arrs[i]);
    }
}
//Method to search an element in the heap
int heap::search(int num) 
{
    int i;
    for (i = 0; i <= cur; i++) 
    {
        if (num == arr[i]) 
        {
            return 1;
        }
    }
    return 0;
}
//Method to search index of an element in the vertices array
int heap::searchindex(int num) 
{
    int i;
    for (i = 0; i <= cur; i++) 
    {
        if (num == arr[i]) 
        {
            return i;
        }
    }
    return 0;
}
//Method to reduce given elements by reducefactor
int heap::reduceheapify() 
{
    char ans = 'y';
    int num, redfactor, cur;
    while (ans == 'y') 
    {
        printf("\nEnter the element to be reduced : ");
        scanf("%d", &num);
        printf("By how much u need to reduce : ");
        scanf("%d", &redfactor);
        cur = searchindex(num);
        if(cur!=0)
        {
            arr[cur] = arr[cur] - redfactor;
            heapify(cur);
        }
        else
        {
            printf("\nThe element is not present");
        }
        printf("\nDo u wish to continue ? (y/n) ");
        getchar();
        scanf("%c", &ans);
    }
    return 1;
}
//Method to re-heapify
void heap::heapify(int current) 
{
    int parent, lchild, rchild, maxindex, temp;
    parent = current;
    while (1) 
    {
        lchild = 2 * parent + 1;
        rchild = 2 * parent + 2;
        maxindex = parent;
        if (lchild <= cur && arr[lchild] > arr[maxindex]) 
        {
            maxindex = lchild;
        }
        if (rchild <= cur && arr[rchild] > arr[maxindex]) 
        {
            maxindex = rchild;
        }
        if (maxindex != parent) 
        {
            temp = arr[parent];
            arr[parent] = arr[maxindex];
            arr[maxindex] = temp;
            parent = maxindex;
        } 
        else 
        {
            break;
        }
    }
}
