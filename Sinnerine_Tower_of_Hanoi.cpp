//Samantha Sinnerine CS211 - Tower of Hanoi (non-recursive solution)
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> t[3]; //three towers A,B,C represented as an array of 3 vectors
    int n;
    cout << "Please enter the number of rings to move: ";
    cin >> n;
    
    // move counts number of moves made = 2^n - 1
    // candidate is the smallest available ring that has not just been moved.
    int from = 0, to, closest, furthest, candidate = 1, move = 0; 
    
    
    /*if there is an even number of rings, move in a counter-clockwise direction.
    closet tower will be tower 2, furthest will be tower 1 and vice versa for an odd num of rings*/
    if (n%2 == 0){ 
        closest = 2;
        furthest = 1;
    } else{
        closest = 1;
        furthest = 2;
    }
   
    to = closest;
    
    // Initialize the 3 towers
    for(int i = n + 1; i >= 1; --i)
        t[0].push_back(i); 
    t[1].push_back(n+1); 
    t[2].push_back(n+1);
   
    while (t[1].size() < n+1) { // while tower B does not contain all of the rings
        cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << endl;
      
        t[to].push_back(t[from].back()); // push the top from the "from" tower to the "to" tower.
        t[from].pop_back(); // remove the ring from the "from" tower"
      
        // determine the next "from" tower by comparing the rings at the top of the 2 towers after the tower we just moved to. The tower with the smaller ring becomes the new "from" tower
        if (t[(to+1) % 3].back() < t[(to+2) % 3].back()) 
            from = (to+1) % 3;
        else
            from = (to+2) % 3;
         
      // determine the "to" tower (the closest, legal tower on which the candidate can be placed)
      //if candidate is smaller than the ring on the closest tower, then the ring will be placed on closest tower from the "from" tower else it will be placed on the furthest tower
      if (t[from].back() < t[(from+closest) % 3].back()) 
         to = (from+closest) % 3; 
      else
         to = (from+furthest) % 3;
         
         candidate = t[from].back(); // the candidate is the ring on top of the "from" tower.
   }
   
   
   return 0;
}