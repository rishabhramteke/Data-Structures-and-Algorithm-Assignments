#include<bits/stdc++.h>
using namespace std;
class Circle{
public:
	double x,y,r;
	Circle(double x1,double y1,double r1){
		x=x1;
		y=y1;
		r=r1;
	}
	Circle(){}
	double get_distance(Circle C1){
		return sqrt(pow(x-C1.x,2) + pow(y-C1.y,2));
	}
	double is_intersect(Circle C1){
		return (this->get_distance(C1) <= r+C1.r);
	}
	bool operator == (Circle const & C1){
		return (C1.x == x) && (C1.y==y) && (C1.r==r);
	}
};

bool has_intersections(vector<Circle> A){
	vector<Circle> B;
	B.clear();
	vector<Circle>::iterator init1;
	vector<Circle>::iterator init2;
	for(init1 = A.begin();init1!=A.end();init1++){
		vector<Circle>::iterator iter3 = B.begin();
		int i;
		for(init2 = iter3,i=0;i<B.size();init2++){
			// cout<<B.size()<<"x"<<"\n";
			if(init1->is_intersect(*init2) && !(*init1==*init2)){
				// cout<<(*init1==*init2)<<"\n";
				// cout<<init1->x<<" "<<init1->y<<" "<<init1->r<<"Init1"<<"\n"
				// <<init2->x<<" "<<init2->y<<" "<<init2->r<<"Init2"<<"\n";
				return true;
			}
			if (init2->x + init2->r < init1->x - init1->r){
				B.erase(init2);
			}
		}
		// cout<<init1->x<<" "<<init1->y<<" "<<init1->r<<"Init1"<<"\n";
		Circle c = *init1;
		B.push_back(c);
		// cout<<B.size()<<"a"<<endl;
	}
	return false;
}

bool compare(Circle const & a,Circle const & b){
	return (a.x-a.r) < (b.x - b.r);
}

int main(){
	double x;
	vector<Circle> A;
	while(cin>>x){
		double y,r;
		cin>>y>>r;
		A.push_back(Circle(x,y,r));
	}
	// A.push_back(Circle(8,0,1));
	// A.push_back(Circle(2,4,1));
	// A.push_back(Circle(6,1,1));
	vector<Circle>::iterator init1 = A.begin();
	vector<Circle>::iterator init2 = A.end();
	vector<Circle>::iterator init3;
	sort(init1,init2,compare);
	// for(init3 = A.begin();init3!=A.end();init3++){
	// 	cout<<init3->x<<" "<<init3->y<<" "<<init3->r<<"\n";
	// }
	cout<<has_intersections(A);

}