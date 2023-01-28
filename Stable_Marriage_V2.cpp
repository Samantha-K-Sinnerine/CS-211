//Samantha Sinnerine - CSCI 211- Stable Marriage Problem

#include <iostream>
#include <cmath>

using namespace std;

bool Ok(int q[], int c){
    /* i - current man
    q[i] - current woman
    c - new man
    q[c] - new woman */
    
    //men preferences
    //           w0 w1 w2
    int mp[3][3]={0,2,1, //m0
				  0,2,1, //m1
				  1,2,0};//m2
	
	//women preferences
    //           m0 m1 m2			
	int wp[3][3]={2,1,0, //w0
				  0,1,2, //w1
				  2,0,1};//w2
	
	//if woman is already chosen 	  
    for (int i=0; i<c; i++){
        if (q[i] == q[c]) return false;
    }
    
    //if current woman prefers new man to her partner and new man prefers current woman to his partner		
    for (int i=0; i<c; i++){
        if (wp[q[i]][c] < wp[q[i]][i] && mp[c][q[i]] < mp[c][q[c]]) return false;
    }
    
    //if current man prefers new woman to his partner and new woman prefers current man to her partner
    for (int i=0; i<c; i++){
        if (mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]) return false;
    }
	
	return true;			  
    
}

void print(int q[], int count){ //displays solutions in table format
    
    cout<<"Solution #"<<count<<endl;
    cout<<"Man     Woman"<<endl;
    
    for (int i=0; i<3; i++){
        cout<<i<<"       "<<q[i]<<endl;
    }
    
    cout<<endl;
    
}


int main()
{
    int q[3], c=-1, count=1; 
    
    while (true){
        
        c++;
        
        if (c == 3){ 
            print(q , count++);
            c--;
        } else {
            q[c] = -1;
        }
        
        while (true){
            q[c]++;
            if (q[c] == 3){
                c--;
                if (c == -1) return 0;
            }
            else if(Ok(q, c)){
                break;
            }
        }
    }
}

