#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>

using namespace std;

class Minheap
{
    int *harr;
    int capacity;
    int heap_size;
public:
    //constructor
    Minheap(int capacity);
    
    //to heapify 
    void minheapify(int k);//did not understand

    //returns the index of the parent
    int parent(int i){return ((i-1)/2);}

    //returns the index of the left kid
    int left(int i){return (2*i+1);}

    //returns the index of the right kid
    int right(int i){return (2*i+2);}

    //to extract the min element
    int extractmin();

    //decrese the value stored at i to new_val
    void decreasekey(int i,int new_val);

    //gets element from the root
    int getmin(){return harr[0];}

    //deletes key from the stored index i
    void deletekey(int i);

    //inserts new element "val"
    void insert(int val);
};

//constructor: Builds a heap from a given array a[] of give size
Minheap::Minheap(int cap)
{
    capacity=cap;
    heap_size=0;
    harr=new int[cap];   
}

//Inserts  a new key
void Minheap::insert(int val)
{
    if(heap_size==capacity)
    {
        cout<<"overflow :Could not insert a key";
        return;
    }

    //first insert the key at the end
    heap_size++;
    int i=heap_size-1;
    harr[heap_size-1]=val;

    //fix the min heap property
    while((i)&&(harr[parent(i)]>harr[i]))
    {
        swap(harr[parent(i)],harr[i]);
        i=parent(i);
    }
}

//decreases the value at index i to new_val
void Minheap::decreasekey(int i,int new_val)
{
    if((i<0)||(i>=heap_size))
    {
        cout<<"index not in the domain";
        return;
    }

    harr[i]=new_val;
    while((i)&&(harr[parent(i)]>harr[i]))
    {
        swap(harr[parent(i)],harr[i]);
        i=parent(i);
    }       
}

//method to extact min
int Minheap::extractmin()
{
    if(heap_size==0)
    {
        cout<<"error"<<endl;
        return 0;
    }
    if(heap_size==1)
    {
        heap_size--;
        return harr[0];
    }
    //return root and removes it and fixes the min heap
    int root=harr[0];
    harr[0]=harr[heap_size-1];
    heap_size--;
    minheapify(0);
    return root;
}

//very brilliantly uses already built methods like decrease key and extract min te min heap roperty is fixed by extract min
void Minheap::deletekey(int i)
{
    decreasekey(i,INT_MIN);
    extractmin();
}

//recursive method to heapify a subtree recursively with a root at a given index
//This method assumes the array is already heapified 
void Minheap::minheapify(int k)
{

    int l=left(k);
    int r=right(k);
    int small_ind=k;
    if((l<heap_size)&&(harr[l]<harr[k]))
    {
        small_ind=l;
    }

    if((r<heap_size)&&(harr[r]<harr[small_ind]))
    {
        small_ind=r;
    }

    if(small_ind!=k)
    {
        swap(harr[small_ind],harr[k]);
        minheapify(small_ind);
    }
}


int main() 
{ 
    Minheap h(11); 
    h.insert(3); 
    h.insert(2); 
    h.deletekey(1); 
    h.insert(15); 
    h.insert(5); 
    h.insert(4); 
    h.insert(45); 
    cout << h.extractmin() << " "; 
    cout << h.getmin() << " "; 
    h.decreasekey(2, 1); 
    cout << h.getmin(); 
    return 0; 
} 