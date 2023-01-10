//Samantha Sinnerine CS211 - N-Queens Solution using 2D array data structure and goto statements

#include <iostream>
using namespace std;

int main( ) {
	
	//initialize variables
    int counter = 1;
	int b[8][8] = {0}, r , c = -1;
	
	Nc: c++;
		if (c == 8)
		{
			goto print;
		}
	
	r = -1;
		
	Nr: r++;
	    if (r == 8)
	    {
		goto backtrack;
		}
	
	
	//row test:
	
	for (int i = 0; i < c; i++)
	{
		if (b[r][i] == 1)
		{
			goto Nr;
		}
	}
	
	//up diagonal test:
	
	for (int i = 1; (r-i) >= 0 && (c-i) >= 0; i++)
	{
		if ((b[r-i][c-i]) == 1)
		{
			goto Nr;
		}
	}
	
	//down diagonal test:
	
	for (int i = 1; (r+i) < 8 && (c-i) >= 0; i++)
	{
		if ((b[r+i][c-i]) == 1)
		{
			goto Nr;
		}
	}
		
	//place queen if all 3 tests are passed
	b[r][c] = 1;
			
	goto Nc;
		
		
backtrack:
	
		c--;
		
		if (c == -1)
		{
			return 0;
		}
		
		r = 0;
		
		while (b[r][c]!=1)
		{
			r++;
		}
		
		b[r][c] = 0;
		
		goto Nr;

//print chessboard

print : 

	cout<<"Solution #" <<counter<<":"<<endl;
	
	for (int r = 0; r < 8; r++){
		
		for (int c = 0; c < 8; c++)
		{
			cout<<b[r][c]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl;
	counter++;
	
	
	goto backtrack;
      
    
}
