#include <iostream>  
#include <cstdlib>  
#include <ctime>  
using namespace std;  
int main() {  
	srand(time(0)); //To initialize the random number generator with the current time as the seed
  	cout<< "Random number between 1 and 10 is: "<<endl;  
	for(int i=0;i<10;i++)  
        cout << (rand() % 10) + 1<<" "; //rand() generate a random integer between 0 and RAND_MAX.   	
    return 0;  
}