#include <iostream>

int main(){
	auto sizeOfUnsignedInt = sizeof(unsigned int);
	auto sizeOfSignedInt = sizeof(int);
	auto sizeOfLongInt = sizeof(long);
	std::cout << sizeOfUnsignedInt << "is equal to? " << sizeOfSignedInt << "but still smaller than: " << sizeOfLongInt << std::endl;
	return 0;
}
