// Rishabh Ramteke
//170070046


#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

//to erase commas :-  s.erase(std::remove(s.begin(), s.end(), ','), s.end());

//function to find intersection of two vectors
std::vector<std::string> intersection(std::vector<std::string> &v1,
                                      std::vector<std::string> &v2){
    std::vector<std::string> v3;

   // std::sort(v1.begin(), v1.end());
    //std::sort(v2.begin(), v2.end());  // we dont need to sort them as they are already sorted

    std::set_intersection(v1.begin(),v1.end(),
                          v2.begin(),v2.end(),
                          back_inserter(v3));
    return v3;
}


int main()
{
map < string, vector<int> > doc;  
string s,p;

vector<string> phrase ;

int i =1;
while(cin>>s)  //taking input of words in document
	{
		transform(s.begin(), s.end(), s.begin(), ::tolower);  //transforming capitals to lower case
		s.erase(std::remove(s.begin(), s.end(), ','), s.end());//removing comma, semicolon and fullstop
		s.erase(std::remove(s.begin(), s.end(), ';'), s.end());
		s.erase(std::remove(s.begin(), s.end(), '.'), s.end());
		if (s == "*") break; // I am going to stop taking input when we type * after the phrase
		doc[s].push_back(i);
		i++;
		
	}
i--;
// cout<<"Ferg;=hhhhhhh ";

while(cin>>p) //taking input of words in phrase
	{
		transform(p.begin(), p.end(), p.begin(), ::tolower); //transforming capitals to lower case
		p.erase(std::remove(p.begin(), p.end(), ','), p.end());//removing comma, semicolon and fullstop
		p.erase(std::remove(p.begin(), p.end(), ';'), p.end());
		p.erase(std::remove(p.begin(), p.end(), '.'), p.end());
		phrase.push_back(p);
		// i++;
		if (p == "*") break; // I am going to stop taking input when we type fullstop after the phrase
	}

//indexing
 for (map<string,vector<int> >::iterator it=doc.begin(); it!=doc.end(); ++it)
 {
    cout << it->first << " => ";
	vector<int> myvector = it->second;
	
	for (vector<int>::iterator it1 = myvector.begin() ; it1 != myvector.end(); ++it1)
    {cout << ' ' << *it1;}

	cout << '\n';
}


vector<int> v_in ;//initializing vector

// vector<int> v_n ;//intersection of vectors

//let N be no. of words in document
// cout <<i<<endl;

int N = doc.size();
for (int j=1; j<=i; j++ ){
	v_in.push_back(j);
}

//let k be no. of words in phrase
int k = phrase.size() - 1;
// cout << k<<endl;
for (int j = 0; j < k; j++)
{
	//how to find index of first word????
	//=p.[i]

	// Iterator used to store the position  
    // of searched element 
    /*std::vector<int>::iterator it2; 
	 // std::find function call 
    it2 = std::find (doc.begin(), doc.end(), phrase[j]); 
    if (it2 != doc.end()) 
    { 
        std::cout << "Element " << phrase[j] <<" found at position : " ; 
        std:: cout << it2 - doc.begin() + 1 << "\n" ; 
    } 
    else
        std::cout << "phrase not found.\n\n"; */


	//let that index be of vector form
	/*vector<int> v_index;
	v_index = doc[phrase[j]];*/

	vector<int> v_n;//intersection of vectors

   // std::sort(v1.begin(), v1.end());
    //std::sort(v2.begin(), v2.end());  // we dont need to sort them as they are already sorted

	// for(int i=0;i<v_in.size();i++){
	// 	cout<<"degb1 "<<v_in[i]<<endl;
	// 	// v_in[i]+=1;
	// }

	// for(int i=0;i<v_n.size();i++){
	// 	cout<<"degb2"<<v_n[i]<<endl;
	// 	v_n[i]+=1;
	// }

vector <int> v_n1 = doc[phrase[j]];
// for(int i=0;i<v_n1.size();i++){
// 		cout<<"degb3 "<<v_n1[i]<<endl;
// 		// v_n1[i]+=1;
// 	}
int j1 = 0;
int i1 = 0;
while(true)
{
	if(i1 == v_in.size()) break;
	if(j1 == v_n1.size()) break;
	
	if(v_in[i1] == v_n1[j1]) 
	{
		v_n.push_back(v_in[i1]);
		j1++;
		i1++;
	}
	else if(v_in[i1] < v_n1[j1])
	{
		i1++;
	}
	else
	{
		j1++;
	}
}

    // std::set_intersection(v_in.begin(),v_in.end(),
    //                       doc[phrase[j]].begin(),doc[phrase[j]].end(),
    //                       back_inserter(v_n));

	//v_n = intersection(v_in , doc.at(phrase[j]));
	//now we need to increment all elements in this intersection vector
	//std::transform(std::begin(v_n),std::end(v_n),std::begin(v_n),[](int x){return x+1;});
	//transform(v_n.begin(), v_n.end(), v_n.begin(),[](int x){return x+1;});
	//now we need to increment all elements in this intersection vector
	for(int i=0;i<v_n.size();i++){
		// cout<<"degb5  "<<v_n[i]<<endl;
		v_n[i]+=1;
	}

	v_in = v_n;
}


for(int i=0;i<v_in.size();i++){
		v_in[i]-=(k);
	}
	
// Print Vector v_in
    std::cout << "index of phrase :"; 
    for (int j=0; j<v_in.size(); j++) 
        std::cout << " " << v_in[j]; 
          
    std::cout << "\n"; 

}