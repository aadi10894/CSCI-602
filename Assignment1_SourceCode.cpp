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
int insertionSort( int arr[], int n)  //Function to sort using Insertion Sort
{
    int counter=0;					// Just an addition to the program to calculate the number of comparisons it to took to sort the array elements
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
            counter++;			// Just an addition to the program to calculate the number of comparisons it to took to sort the array elements
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


int selectionSort(int arr[], int n)  //Function to sort using Selection Sort
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
  if (G=='I')   //If the sorting method is selected as Insertion
  {
      //t=clock(); 		//For traditional method of calculating time.
      c=insertionSort(arr, Num);
      //t=clock()-t; 	//For traditional method of calculating time.
  }
  if (G=='S')	// //If the sorting method is selected as Insertion
  {
      //t=clock(); 		//For traditional method of calculating time.
      c=selectionSort(arr, Num);
      //t=clock()-t;	//For traditional method of calculating time.
  }
  //double time_taken=((double) t)/CLOCKS_PER_SEC; 		//For traditional method of calculating time.
  
  printArray(arr, Num);
    cout<<"Number of comparisons="<<c<<endl;					// Just an additional command to calculate the number of comparisons it to took to sort the array elements
    //cout<<"Time Taken="<<time_taken<<endl;					//For traditional method of calculating time.
}


