#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <functional>
#include <array> 
using namespace std ;
//Part1
double f(int n, int h[], int s[] ){//h[] contains happy values and s[] contains sad values
	vector<int> exp_val, exp_val1, exp_val2, exp_val_new;
	vector<int> exp_freq, exp_freq1, exp_freq2, exp_freq_new;
	int high[n]; // comparing happy and sad values, sorting them into high and low values
	int low[n];
	for(int i=0; i<N;i++){
		if (h[i]>s[i]){high[i]=h[i]; low[i]=s[i];}
		else {high[i]=s[i]; low[i]=h[i];}
	}
	exp_val[0]=high[0] ;//initialise
	exp_val[1]=low[0];
	exp_freq[0]=1;
	exp_freq[1]=1;
	exp_val1 = exp_val2 = exp_val;
	exp_freq1 = exp_freq2 = exp_freq;

		
		exp_val1 = exp_val2 = exp_val;
		exp_freq1 = exp_freq2 = exp_freq;
		for(int j=0; j<exp_val1.size();j++){
			if (high[i]>exp_val[j]){
				exp_val1[j]=high[i];
			}
			else {
				exp_freq1[j]++;
			}
		}
		for(int j=0; j<exp_val2.size();j++){
			if (low[i]>exp_val[j]) {
				exp_val2[j]=low[i];
			}
			else {
				exp_freq2[j]++;
			}
		}
		exp_val1.insert(exp_val1.end(), exp_val2.begin(), exp_val2.end());
		exp_freq1.insert(exp_freq1.end(), exp_freq2.begin(), exp_freq2.end());
		exp_val = exp_val1;
		exp_freq = exp_freq1;

	
	double sum = 0;
	for (int i=0; i < exp_val.size(); i++) {
		sum = sum + exp_val[i] * exp_freq[i];
	}
	double mean = sum / exp_val.size();
	return mean;
} 


//part2
double probability(int n, int h[], int s[]){ 
    

     std::array<int, n>  h ; 
     // sort using a lambda expression 
    std::sort(h.begin(), h.end(), [](int a, int b) {
        return a > b;   
    });
    std::array<int, n>  s; 
    std::sort(s.begin(), s.end(), [](int c, int d) {
        return c > d;   
    });
    int max_h=h[0];
    int max_s=s[0];
    int k=0;
    int m=0;
    int count_h=0;
    int count_s=0;
    while(max_h==h[k]){
        count_h ++;
        k++;
    }
    while(max_s==s[m]){
        count_s ++;
        m++;
    }
    if(max_h>max_s){
    return (1- (1/pow(2,count_h)));} //Assuming that happy and sad value of one person are not same and are not max
    else if (max_s>max_h){
    return (1- (1/pow(2,count_s)));}

}

int main(){
/////
	int N;
	cin>>N;
	int h[N];
	int s[N];
	int sum = 0;
	for(int i=0; i<N;i++){
		cin>>h[i]>>s[i];
	}
	f(N, h[N], s[N]);
	for (int i = 0; i < N; ++i)
	{
		sum = sum + exp_val[i]*exp_freq[i];
	}
	cout<<sum/pow(2,N);
	probability(int N, int h[N], int s[N])
}