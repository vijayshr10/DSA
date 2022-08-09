#include <iostream>
using namespace std;



void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition(int input[], int l, int r)
{
    int pivot = input[r];
    int i=l-1;
    
    for(int j=l; j<r; j++)
    {
        if(input[j]<pivot)
        {
            i++;
            swap(&input[i], &input[j]);
        }
    }
    swap(&input[i+1], &input[r]);
    return i+1;
}

	
	void quickSort(int input[], int l, int r)
	{
        if(l<r)
        {
            int pi = partition(input, l,r);
            quickSort(input, l, pi-1);
            quickSort(input, pi+1, r);
        }
	}
	void quickSort(int input[], int size)
	{
    		quickSort(input, 0, size - 1);
	}
		

int main(){
   int n;
   cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}




