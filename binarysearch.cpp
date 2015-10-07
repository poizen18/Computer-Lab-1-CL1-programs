#include<iostream>
using namespace std;

void bsearch(int arr[],int low, int high, int key, int itr){
	itr=itr+1;
	cout<<"ITERATION NUMBER "<<itr<<" "<<key<<endl;
	if (low>high){
		cout<<"err";
	}
	else{
		int mid=(low+high)/2;
		if(arr[mid]==key) cout<<arr[mid]<<" found at index "<<mid<<endl;
		else if (key<arr[mid])bsearch(arr,low,mid,key,itr);
		else bsearch(arr,mid+1,high,key,itr);

	}
}

int main(){int key;
	while(key!=-1){


	int n,i,j=3,index;
	cout<<"enter the number of elements"<<endl;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++){
		arr[i]=i+j;
		cout<<"the value at index "<<i<<" is "<<arr[i]<<endl;
	}
	cout<<"enter the number you want to search";
	cin>>key;
	int itr=0;
	bsearch(arr,0,n-1,key,itr);
	//cout<<"the number found at index "<<index;
	return 0;
	}
}
