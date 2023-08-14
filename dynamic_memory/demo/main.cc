#include "myclass.h"
#include <memory>

int main() {

    std::shared_ptr<Myclass> obj1 = std::make_shared<Myclass>(42);
    int val = obj1->gedData();

    return 0;
}