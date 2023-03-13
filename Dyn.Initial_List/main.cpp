#include <iostream>
using namespace std;

class Point{
    int x;
    int y;
public:
    Point(){
        x = 0;
        y = 0;
    }
    Point& operator=(Point& obj){
        this->x = obj.x;
        this->y = obj.y;
        return *this;
    }
};

template<class T, int size>
class MyClass{
    T* arr = new T[size];
    public:
        MyClass(){
            arr = nullptr;
        }
        ~MyClass(){
            delete[] arr;
        }
        MyClass(initializer_list<T> obj){
            arr = new T[size];
            int count = 0;
            for (auto el : obj){
                arr[count] = el;
                count++;
            }
        }
};

int main() {
    Point p1;
    Point p2;
    MyClass<Point, 2> cl {p1, p2};
}
