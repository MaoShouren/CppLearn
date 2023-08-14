#include <iostream>
#include <thread>
#include <memory>


// 线程调用的函数含有参数
// void add(int& a) {
//     while (a<10) std::cout << a++;
// }

// int main() {
//     int a = 0;
// // 此处使用std::ref的原因是由于 add 函数中形参为引用数据类型
//     std::thread t1(add, std::ref(a)); 
//     t1.join();
//     // t1.detach();

//     return 0;
// }

// 线程调用成员函数
// class test {
//     public:
//         void display(int a) {
//             std::cout << a << "\n";
//         }
// };

// int main() {
//     test a;
//     std::thread t2(&test::display, a, 3); //此处第一个参数必须添加&
//     t2.join();
//     return 0;
// }

// 多线程执行含有返回值的函数，获取函数返回值
// int f(int a, int b) {
//     return a+b;
// }

// int main() {
//     int result = 0;
//     std::thread* t;
//     t= new std::thread([&] {result = f(2, 3);});
//     t->join();
//     std::cout << result;

//     return 0;
// }


