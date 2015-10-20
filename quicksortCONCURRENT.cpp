#include<iostream>
#include<stdlib.h>
#include<omp.h>
using namespace std;
void PrintArray( int *A, int nElements )
{
    cout << "[ ";

    for( int i = 0 ; i < nElements ; i++ )
    {
        cout << A[i] ;
        if( i < nElements-1 )
           cout << ", ";
    }

    cout << " ] " << endl;
}

class Quicksort{
public:
//void getarr();
void qs(int *array,int l, int h);
int partition(int *array,int l, int h);

/*
void disp(int *arr, int n){

	cout<<"\n THE SORTED ARRAY IS\n";
	for(int i=0;i<n;i++){
	cout<<""<<arr[i]<<"\n";
		}
	}*/
};

void Quicksort::qs(int *array, int l ,int h){
	int div;
	int tid;
	if(l<h){
		div=partition(array,l,h);
#pragma omp parallel sections
		{
#pragma omp section
		
			qs(array,l,div-1);
#pragma omp section
			qs(array,div+1,h);
			
		}
	}
}
int Quicksort::partition(int* a, int l, int h)
{   /*int x=a[h];
    int i=l-1;
   // #pragma omp parallel for
    	for(int j=l;j<=h-1;j++)
    	  {
          if(a[j]<=x){
    		i=i+1;
       	        std::swap(a[i],a[j]);

          }
       }

       std::swap(a[i+1],a[h]);

       return i+1;*/
       int p=l;
       int pivot=a[l];
      // #pragma omp parallel for ordered
       for (int i=l +1; i<=h;i++){
       if(a[i]<=pivot){
       p++;
       std::swap(a[i],a[p]);
       }
       }
       std::swap(a[p],a[l]);
       return p;

}

int main ()
{
cout<<"CONCURRENT QUICKSORT :D \n";

int e,i;
cout<<"enter the number of elements you want in the array : ";
	//cin>>e;
	cout<<"\n";
	e=100000;    //delete the comment if you dont' want to enter the elements
	int arr[e];
	//cout<<"enter the elements";
	#pragma omp parallel
	for(i=0;i<e;i++){
	//cin>>arr[i];
	arr[i]=rand()%e;	//use this fi you want random values to be generated and stored in the array.
	}
	cout<<"the array is";
	PrintArray(arr,e);
cout<<"\n\n\n";
omp_set_num_threads(10);
Quicksort a;
a.qs(arr,0,e-1);
//
PrintArray(arr,e);
return 0;
}
