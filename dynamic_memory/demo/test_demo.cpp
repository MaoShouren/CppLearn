#include <iostream>

class MyClass {
public:
	MyClass(int value)  {
		this->value = value;
		someOtherFunction(this);
	}
	void someOtherFunction(MyClass* obj) {
		int value = obj->value;
		std::cout  <<  "Value: " <<  value << std::endl;
	}
int value;	

};

int main(int argc, char** argv) {
	MyClass* objPtr = new MyClass(42);
	int val = objPtr->value;
	std::cout << "Value is : " << val << std::endl;

	delete objPtr;

	return 0;
}
