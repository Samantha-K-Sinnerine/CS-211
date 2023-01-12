//Samantha Sinnerine CSCI 211 - 8 Numbers in a Cross 

#include <iostream>
#include <cmath>
using namespace std;

bool Ok(int q[], int c){
    
    //Adjacency helper array for each square
	int a[8][5] ={  {-1},               // 0  
                    {0, -1},            // 1
                    {0, -1},            // 2  The cross with configuration:
                    {0, 1, 2, -1},      // 3              0 1
                    {0, 1, 3, -1},      // 4            2 3 4 5
                    {1, 4, -1},         // 5              6 7
                    {2, 3, 4, -1},      // 6
                    {3, 4, 5, 6, -1} }; // 7
    
    //Row test            
    for (int i=0; i<c; i++){ 
        if (q[i]==q[c]) return false; // if the number in square c has already been used, return false.
    }
    
    //Adjacent and consecutive test
    for (int i=0; a[c][i] != -1; i++){
        if (abs(q[c] - q[a[c][i]]) == 1) return false; // if the number in square c and it's adjacent squares differ by 1, return false.
    }
    
    return true; //number in square c is valid
}

void print(int q[], int count){
    
    cout<<"Solution #" <<count<<":"<<endl;
	
	//displays solution in cross format
	cout<<" "<<q[0]<<q[1]<<endl;
	cout<<q[2]<<q[3]<<q[4]<<q[5]<<endl;
	cout<<" "<<q[6]<<q[7]<<endl;
	
	cout<<endl;
}


int main( ) {
	
	int q[8]={0}, count=1, c=0;
	
	while (c != -1){
	    
	    q[c]=0;
	    
	    if(c == 8){             //off cross 
	        print(q , count++); //print solution
	        c--;                //backtrack
	    }
	    
	    while(q[c] < 9){
	        
	        q[c]++;             //increment number
	        
	        if (q[c]==9){       //off cross
	            c--;            //backtrack
	        } 
	        else if (Ok(q,c)){ //if number in square c is valid, exit inner while loop
	            break;
	        }
	    }
	    
	    c++;  //increment square #
	    
	}
	
	return 0;
	
}