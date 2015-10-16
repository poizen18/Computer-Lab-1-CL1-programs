//============================================================================
// Name        : knapclass.cpp
// Author      : poizen
// Version     :
// Copyright   : Your copyright notice
// Description : ._. 
//============================================================================

#include <iostream>
using namespace std;
class knap{
	int weight[20],profit[20],k=-1,totalweight=0,totalprofit=0,vector[20],n,mw;
public:
	void getdata(){
		cout<<"enter the number of items: and MAXIMUM weight";
		cin>>n>>mw;

		for(int i=0;i<n;i++){
		cout<<"enter the profit and weight";
		cin>>profit[i]>>weight[i];
		}
	}
	void display(){		cout<<"\n the solution vector is: ";
		for(int i=0;i<n;i++){
			cout<<" "<<vector[i];
		}
	}
	int upperbound(){
		for(int i=k+1;i<n;i++){

			if(totalweight+weight[i]<=mw){
				totalprofit=totalprofit+profit[i];
				totalweight=totalweight+weight[i];
			}

		}
		return totalprofit;
	}
	int leastcost(){

		for(int i=k+1;i<n;i++){

					totalweight=totalweight+weight[i];
					if(totalweight<=mw){
						totalprofit=totalprofit+profit[i];
					}
					else{
						totalweight=mw-(totalweight-weight[i]);
						totalprofit=totalprofit+((weight[i]/profit[i])*totalweight);
						}
				}
				return totalprofit;
	}
	void knapsack(){
		int w=0,l=0,p=0,ub1,ub2,c;
		while(l<n){
			w=totalweight;
			p=totalprofit;
			ub1=upperbound();
			totalprofit=p;
			totalweight=w;

			c=leastcost();
			k=l;

			ub2=upperbound();
			totalprofit=p;
			totalweight=w;
			if(ub1>=ub2){
				vector[l]=1;
				totalprofit=totalprofit+profit[l];
				totalweight=totalweight+weight[l];
				cout<<"the least cost::  "<<c;

			}
			else{
				vector[l]=0;
			}
			l++;
			ub1=ub2=c=0;
		}
		display();
	}
};

int main() {
knap p;
p.getdata();
p.knapsack();
return 0;
}
