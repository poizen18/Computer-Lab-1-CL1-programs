//============================================================================
// Name        : 01knap.cpp
// Author      : poizen
// Version     :
// Copyright   : opensource for life
// execute using g++ 01knap.cpp -std=gnu++11
//======================please ignore the comments like the compiler :)=======

#include <iostream>
#include<omp.h>
using namespace std;
const unsigned int maxweight=10;


struct node{
	 unsigned int itemnum,weight=1,taken=0,profit,total,nodeweight;
	int level;
	char name[20];
};
/*
void ratio(node nodes[5]){

		float ratio=nodes->profit/nodes->weight;


}*/
void swappa(node nodes[5]){
	for(int i=0;i<=4;i++){


			{

				for(int y=1; y<4; y++)

				{
					float ratio1=nodes[y].profit/nodes[y].weight;
					float ratio2=nodes[y+1].profit/nodes[y+1].weight;
					if(ratio1<ratio2){

							std::swap(nodes[y],nodes[y+1]);
					}

				}

			}
/*
		if(nodes[i].ratio<nodes[i+1].ratio){

			std::swap(nodes[i],nodes[i+1]);
		}
		*/
	}
}

void calculatebound(node* nodes){
	unsigned int currentweight=0,maxprofit=0;

	for(int i=0;i<5;i++){
	if(currentweight<maxweight){

			currentweight=currentweight+nodes[i].weight;
			//currentweight=currentweight-nodes[i].weight;
		maxprofit=maxprofit+nodes[i].profit;

		if(currentweight>maxweight){
			currentweight=currentweight-nodes[i].weight;
			maxprofit=maxprofit-nodes[i].profit;
		}
	}

	}
	cout<<"MAXIMUM PROFIT CAN BE "<<maxprofit<<" and weight of knapsack is "<<currentweight<<endl;
}
/*
void upperbound(node *no){


}*/
/*
int bound(int cw){
	int p;
	if(cw<=maxweight){

		return p;
	}

}
*/
/*
void branch(node *nodes,int i){
	int lev=0,cp,cw=0;

	if(nodes[i].level==lev){
		//goleft
		cw=nodes[i].nodeweight+nodes[i+1].weight+cw;
		cp=bound(cw);




	}

}

*/
int main() {
	int i;
	node nodes[5];
	//cout << "enter the maximum weight" << endl; // prints ssssss
	//init node 0
	/*nodes[0].level=0;
	nodes[0].profit=0;
	nodes[0].total=0;
	nodes[0].weight=0;
	nodes[0].nodeweight=0;
*/
	cout <<"enter 5 items "<<endl;

	for(i=0;i<=4;i++){
		cout<<"item number "<<i;
		//std::getline (std::cin,nodes[i].name);
		nodes[i].itemnum=i;
		cout<<endl<<"enter the profit and weight ";
		cin>>nodes[i].profit;cout<<endl;
		cin>>nodes[i].weight;cout<<endl;
		}
			//displaying values
			for(i=0;i<=4;i++){
			cout<<"name "<<nodes[i].itemnum;
			cout<<endl<<" profit= "<<nodes[i].profit<<"w= "<<nodes[i].weight;cout<<endl;
			}
			swappa(nodes); //sorting them in descending order of their P/W ratio.
			//hola
			for(i=0;i<=4;i++){
						cout<<"item number "<<nodes[i].itemnum<<endl<<"               profit =  "<<nodes[i].profit<<"   w= "<<nodes[i].weight<<endl;
						}
			calculatebound(nodes);
	return 0;
}
