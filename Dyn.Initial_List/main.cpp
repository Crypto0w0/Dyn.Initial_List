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
    ostream& operator << (ostream& o, const Point& p){
        o << p.getX() << " " << p.getY();;
        return o;
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
        void Print(){
            for (int i = 0; i < size; i++){
                cout << arr[i] << endl;
            }
        }
};

int main() {
    Point p1;
    Point p2;
    MyClass<Point, 2> cl {p1, p2};
    MyClass<int, 2> cl2 {1, 2};
    cl2.Print();
}
