//============================================================================
// Name        : kmeans.cpp
// Author      : poizen
// Version     :
// Copyright   : opensource for life
// Description : kmeans 
//============================================================================

#include <iostream>
#include<cstdlib>
#include<math.h>
#include<algorithm>
using namespace std;\

class Point{
private:

public:
	float  x,y,clusterid;
	Point(){
	 x=0;
	 y=0;
	 clusterid=0;
}
	Point(float x,float y){
		this->x=x;
		this->y=y;
	}
	void setx(float x){
		this->x=x;
	}
	void sety(float y){
		this->y=y;
	}
	float getx(){
		return x;
	}
	float gety(){
		return y;
	}
	void setclusterid(float id){
		this->clusterid=id;
	}
	float getclusterid(){
		return clusterid;
	}
};
float distance(float x1,float y1,float x2, float y2){

	float x1x2=x1-x2,y1y2=y1-y2;
	float dist=sqrt(powf(x1x2,2)+powf(y1y2,2));

	return dist;
}

int main() {
	bool nochange[2]={false,false};
	float dist1=0,dist2=0;
	Point data[10], centroid[2], oldcentroid[2];
//initializing dataset to random points
	for(int i=0;i<10;i++){
		float xx=rand()%10;
		float yy=rand()%10;
		data[i].setx(xx);
		data[i].sety(yy);
	}

	cout<<"the dataset are at positions: "<<endl;
	for(int i=0;i<10;i++){

		cout<<"for dataset "<<i<<" X: "<<data[i].getx()<<" Y: "<<data[i].gety()<<" cluster id :"<<data[i].getclusterid()<<endl;
	}
//init centr
	for(int i=0;i<2;i++){
				float xx=rand()%10;
				float yy=rand()%10;
				centroid[i].setx(xx);
				centroid[i].sety(yy);
	}
//where are they?
	for(int i=0;i<2;i++){
			cout<<endl;
			cout<<"for CENTROID "<<i<<" X: "<<centroid[i].getx()<<" Y: "<<centroid[i].gety()<<endl;
		}
	cout<<endl;
//calculate distance of each point towards the centroid and assign which dataset belongs to which cluster
	for(int i=0;i<10;i++){

		 dist1=distance(data[i].x,data[i].y,centroid[0].x,centroid[0].y);
		 dist2=distance(data[i].x,data[i].y,centroid[1].x,centroid[1].y);

		if(dist1>=dist2){

			data[i].setclusterid(1);
		}
		else{
			data[i].setclusterid(0);
		}
	}
	for(int i=0;i<10;i++){

			cout<<"for dataset "<<i<<" X: "<<data[i].getx()<<" Y: "<<data[i].gety()<<" cluster id :"<<data[i].getclusterid()<<endl;
		}
			float x=0,y=0,x2=0,y2=0;
			float c1=0,c2=0;

//calculating new position for the centroids
		while(nochange[1]==false or nochange[0]==false){

					//cpying old centroid positions

					for(int i=0;i<2;i++){
					oldcentroid[i].setx(centroid[i].getx());
					oldcentroid[i].sety(centroid[i].gety());
					}
	for(int i=0;i<10;i++){
		float closex[2],closey[2];
		int min[2]={999,999};
		if(data[i].getclusterid()==0){
			x=x+data[i].getx();
			c1++;
			y=y+data[i].gety();
			dist1=distance(data[i].x,data[i].y,centroid[0].x,centroid[0].y);
			/*if(dist1<min1){
				min1=dist1;
				closex[0]=data[i].getx();
				closey[0]=data[i].gety();
			}*/
		}
		else{
			x2=x2+data[i].getx();
			c2++;
			y2=y2+data[i].gety();
			/*dist1=distance(data[i].x,data[i].y,centroid[0].x,centroid[0].y);*/

		}
		//i declared new variables rather than the ones mentioned already because it gave me some error, and im too lazy to correct that :)
		float x3=x/c1,y3=y/c1,y4=y2/c2,x4=x2/c2;

		centroid[0].setx(x3);
		centroid[0].sety(y3);
		centroid[1].setx(x4);
		centroid[1].sety(y4);
//what you do hereafter is check which of the objects is having closest distance to the centroid, and you make that object
		//the new centroil :)
		for(int i=0;i<10;i++){

			if(data[i].clusterid==0){
				 dist1=distance(data[i].x,data[i].y,centroid[0].x,centroid[0].y);
				 if(dist1<min[0]){
				 				min[0]=dist1;
				 				closex[0]=data[i].getx();
				 				closey[0]=data[i].gety();

				 			}

			}
			else{
				 dist2=distance(data[i].x,data[i].y,centroid[1].x,centroid[1].y);
				 if(dist2<min[1]){
				 				 				min[1]=dist2;
				 				 				closex[1]=data[i].getx();
				 				 				closey[1]=data[i].gety();

				 				 			}
			}



			}
		// cout<<"data object closest to the centroid 1 is made the new centroid"<<closex[0]<<" " <<closey[0];
		 //cout<<"data object closest to the centroid 2 is made the new centroid"<<closex[1]<<" " <<closey[1];
		 	 	centroid[0].setx(closex[0]);
		 		centroid[0].sety(closey[0]);
		 		centroid[1].setx(closex[1]);
		 		centroid[1].sety(closey[1]);




	}
	for(int i=0;i<2;i++){

		if(oldcentroid[i].getx()==centroid[i].getx()&&oldcentroid[i].gety()==centroid[i].gety()){
			nochange[i]=true; //if the value of centroid's previous x and y are same as current. ie. it is in right position
			}

				cout<<endl;
				//cout<<"for CENTROID "<<i<<" X: "<<centroid[i].getx()<<" Y: "<<centroid[i].gety()<<endl;
			}
			}

	cout<<"the final positions of centroid 1 are ("<<centroid[0].getx()<<","<<centroid[0].gety()<<")"<<endl;
	cout<<"the final positions of centroid 2 are ("<<centroid[1].getx()<<","<<centroid[1].gety()<<")"<<endl;

	return 0;
}



















