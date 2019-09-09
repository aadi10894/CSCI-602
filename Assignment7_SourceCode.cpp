#include <iostream>
#include <string.h>
#include <sstream> 
#include <time.h>
using namespace std;


void printArray(int arr[], int n)
{
    int i;
    for (i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

int insertionSort( int arr[], int n)
{
    int counter=0;		// Just an addition to the program to calculate the number of comparisons it to took to sort the array elements
    cout<<"Insertion Sort"<<endl;
    int i, key, j;
    for (i=1; i<n; i++)
    {
        key=arr[i];
        j=i-1;
        
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
            counter++;		// Just an addition to the program to calculate the number of comparisons it to took to sort the array elements
        }
        arr[j+1]=key;
        
    }
    return counter;
}

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}


int selectionSort(int arr[], int n)
{
    double counter=0;
    cout<<"Selection Sort"<<endl;
    int i, j, min_idx;
    for (i=0;i<n-1;i++)
    {
        min_idx=i;
        for (j=i+1;j<n;j++)
        {
            counter++;
            if(arr[j]<arr[min_idx])
                min_idx=j;
        }
        swap(&arr[min_idx], &arr[i]);
    }
    return counter;
}

void heapify(int arr[], int n, int i, int& count)
{
	int max = i; // this is now the root of the tree and we need to swap it with some 
	int left, right;
	left = 2 * i + 1; // left child is at 2*i+1 (you can apply it on any node)
	right = 2 * i + 2; // right chil is at 2*i+2
	
	// in case the left child is larger 
	if (left < n && arr[left] > arr[max]) 
	{
		count++;
		max = left;
	}

	// If right child is larger than largest so far 
	if (right < n && arr[right] > arr[max])
	{
		count++;
		max = right;
	}

	// in case we have changed the max number to left or right
	if (max != i)
	{
		//move the max to top and let's heapify the rest of the tree 
		swap(&arr[i],&arr[max]);
		count++;
		// if say the new max was left or right, we move the root to its place and do the same to the tree with the root
		heapify(arr, n, max, count);
	}
}

int heapSort(int arr[], int n)
{
	int count = 0;
	cout << "heapSort" << endl;
	//first thing, we will need to rearrange the given array(tree)it is enough to say n/2 since we will compare to the last row which is 		//left and right of the row before
	for (int i = n / 2 - 1; i >= 0; i--)
	heapify(arr, n, i, count);
	// by this way, we make sure that each element is at its correct sorted position since we will each element into top and heapify will 		//send it to the correct position
	for (int i = n - 1; i >= 0; i--)
	{
		
		swap(&arr[0], &arr[i]);

		// with each part of the tree, take the size i and start with root at top and then go down to make sure all is sorted now
	heapify(arr, i, 0, count);
	}	
	return count;
}

int maxElement(int arr[], int n)
{
	
}

void counter(int arr[], int n, int exp)
{
	int newarr[n]; // output array 
	int i, count[10] = { 0 }; //we do 10 containers for each digit

	// Store count of occurrences in count[] 
	for (i = 0; i < n; i++)
	{
		int pos = (arr[i] / exp) % 10; //to get the digit at current exp
		count[pos]++; //increase its position in the count array
	}
	for (i = 1; i < 10; i++)
	count[i] += count[i - 1];

	//now we make the new array
	for (i = n - 1; i >= 0; i--)
	{
		int num = count[(arr[i] / exp) % 10] - 1; //number of needed positions in the new array
		newarr[num] = arr[i];
		//then we update the needed number of positions 
		count[(arr[i] / exp) % 10]--;
	}

	//overwrite the old array with the new array 
	for (i = 0; i < n; i++)
	arr[i] = newarr[i];
}

void radixsort(int arr[], int n)
{
	// to know the number of containers we need
	int max = arr[0];
	for (int i = 0; i < n; i++)
	if (arr[i] > max)
	max = arr[i]; //update max if a larger number found
	//note that exp here is 10^i , so for each ith digit, we do sort the numbers
	for (int exp = 1; max >= exp ; exp *= 10) //each time we change the sorting digit by multiplying exp by 10
	counter(arr, n, exp);
}


int main(int argc, char** argv)
{
        cout<<"Number of arguments"<<argc<<"\n";
        int Num=1000;
        char S='R';
        char G;
        string temp;
        for (int i=0; i<argc; ++i){
                if(argv[i][0]=='N')
                {
                        temp=argv[i];
                        string N=temp.substr(2);
							//To convert this string to integer
                        stringstream temp1(N);
                        temp1>>Num;
                }
                if (argv[i][0]=='S')
                {
                        S=argv[i][2];
                }
                if (argv[i][0]=='G')
                {
                        G=argv[i][2];
                }
        }
	//Initialize and populate our array
  int arr[Num]={};
  if(S=='A')		//for ascending order
  {
     for (int i=0; i<Num; i++)
     {
         arr[i]=i;
     }
  }
  if (S=='D')		//for descendinging order
  {
      int j=Num-1;
      for (int i=0; i<Num; i++)
      {
          arr[i]=j; j--;
      }
  }
  if (S=='R')		//for random numbers
  {
      for(int i=0; i<Num; i++)
      {
          arr[i]=rand()%100000000001; 
      }
  }
  printArray(arr, Num);
  //Sorting
  int c=0;
  //clock_t t;  		//For traditional method of calculating time.
  if (G=='I')
  {
      //t=clock(); 		//For traditional method of calculating time.
      c=insertionSort(arr, Num);
      //t=clock()-t; 	//For traditional method of calculating time.
  }
  if (G=='S')	// for selection sort
  {
      //t=clock(); 		//For traditional method of calculating time.
      c=selectionSort(arr, Num);
      //t=clock()-t;	//For traditional method of calculating time.
  }
  //double time_taken=((double) t)/CLOCKS_PER_SEC; 		//For traditional method of calculating time.
  
  printArray(arr, Num);
    //cout<<"Number of comparisons="<<c<<endl;					// Just an additional command to calculate the number of comparisons it to took to sort the array elements
    //cout<<"Time Taken="<<time_taken<<endl;					//For traditional method of calculating time.
}



