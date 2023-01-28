//Samantha Sinnerine CSCI 211 - 8 Queens Solution using a 1D array data strucuture without goto statements.

#include <iostream>
#include <cmath>
using namespace std;

bool Ok(int q[], int c){
    
    //row and diagonal test
    for(int i=0; i<c; i++){
        if (q[i] == q[c] || (c-i) == abs(q[c] - q[i])) return false; 
    }   
    
    return true; 
    
	
}

void print(int q[], int count){
    
    cout<<"Solution #" <<count<<":"<<endl;
    
    //1D formatted solution
    for(int i=0; i<8; i++){
        cout<<q[i]<<" ";
    } cout<<endl;
    
    //2D formatted solution
    for (int r=0; r<8; r++){
        for(int c=0; c<8; c++){
            if(r == q[c]) cout<<"X ";
            else cout<<". ";
        }
	    cout<<endl;
	}
	
    cout<<endl;

}


int main( ) {
	
	int q[8], count=1, c=0; 
    
	while(c != -1){ 
	    
	    if(c == 8){            //off board
	        print(q, count++); //print solution
	        c--;               //backtrack to previous column
	    } else {
	        q[c] = -1;         //starts at 1 before the first row
	    }
	    
	    while(q[c] < 8){
	        q[c]++;        //increment row # starting at row 0
	        if(q[c] == 8){ //off board
	            c--;       //backtrack to previous column
	        }
	        else if (Ok(q , c)) break; //exit inner while loop if the position of queen in column c is valid
	    } 
	   
	    c++; //increment column #
	}
	
	return 0;
}	
