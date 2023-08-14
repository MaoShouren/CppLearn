#include <memory>
#include "myclass.h"

class Myclass {
 
public:
    Myclass(int val): data(val) {}
    int gedData() const {
        return data; 
    }

private:
    int data;
};
