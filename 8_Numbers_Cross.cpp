//Samantha Sinnerine CSCI 211 - 8 Numbers in a Cross 

#include <iostream>
#include <cmath>
using namespace std;

bool Ok(int q[], int c){
    
	int a[8][5] ={  {-1},           // 0  Neighbor list for each square
                    {0, -1},            // 1
                    {0, -1},            // 2  The cross with the squares labeled:
                    {0, 1, 2, -1},      // 3                  0 1
                    {0, 1, 3, -1},      // 4                2 3 4 5
                    {1, 4, -1},         // 5                  6 7
                    {2, 3, 4, -1},      // 6
                    {3, 4, 5, 6, -1} }; // 7
    
    //Row test            
    for (int i=0; i<c; i++){ 
        if (q[i]==q[c]) return false; // If the number in square c has already been used, return false.
    }
    
    //Adjacent and consecutive test
    for (int i=0; a[c][i] != -1; i++){
        if (abs(q[c] - q[a[c][i]]) == 1) return false; // if the numbers written in square c and it's adjacent squares differ by 1, return false.
    }
    
    return true; //number in square c is valid
}



int main( ) {
	
	int q[8]={0}, counter=1, c=-1; 
	
	Nc: c++;
	if (c==8) goto print;
	
	q[c]=0;
	Nr: q[c]++;
	if (q[c]==9) goto backtrack;
	
	if (Ok(q,c)) goto Nc;
	else goto Nr;
  
  
backtrack:
	
	c--;
		
	if (c == -1) return 0;
		
	goto Nr;


print: 

	cout<<"Solution #" <<counter++<<":"<<endl;
	
	cout<<" "<<q[0]<<q[1]<<endl;
	cout<<q[2]<<q[3]<<q[4]<<q[5]<<endl;
	cout<<" "<<q[6]<<q[7]<<endl;
	
	cout<<endl;
	
	
	goto backtrack;
    
}
