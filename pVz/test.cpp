#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h> 


int main()
{
	std:: srand(time(0));
	for(int i=0 ; i<100 ; i++)
		std::cout << 0+ (std::rand() % 9)<< std::endl;

	return 0;

}