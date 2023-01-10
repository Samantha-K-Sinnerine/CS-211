//Samantha Sinnerine CS211 - N-Queens Solution using 1D array data structure and goto statements

#include <iostream>
#include <cmath>
using namespace std;

int main( ) {
	
	//initialize variables
	int q[8], c = -1, counter=1;
	
	Nc: c++;
		if (c == 8)	goto print;
	
	q[c] = -1;
		
	Nr: q[c]++;
	    if (q[c] == 8)	goto backtrack;

	//row + diagonal test:
	
	for (int i = 0; i < c; i++)
	{
		if (q[i]==q[c] || (c-i) == abs(q[c]-q[i])) goto Nr;
	}
	
	goto Nc;

backtrack:
	
		c--;
		
		if (c == -1) return 0;
		
		goto Nr;


print : 

	cout<<"Solution #" <<counter<<":"<<endl;
	
	for (int i=0; i<8; i++){
	    for (int r=0; r<q[i]; r++) cout<<0<<" ";
	    cout<<1<<" ";
	    for (int c=q[i]+1; c<8; c++) cout<<0<<" ";
	    cout<<endl;
	}
	
	cout<<endl;
	counter++;
	
	
	goto backtrack;
      
    
}
