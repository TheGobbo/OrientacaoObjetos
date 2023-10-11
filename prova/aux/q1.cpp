#include <iostream>

class A {
  public: 
    A() : dado{56} {};
    virtual ~A() = default;

    int get() const {return 1;};

    const int* fn(int* const par) const {
        *par = *par + 10;
        return new int{dado + *par};
    }

  private:
    int dado;
};

class B : public A {
  public:
  int get() const { return 2;}
};

class C : public B {
  public:
    int get() const { return 3;}
};

int main() {
    // A ca;
    // int * par{new int{40}};
    // const int* ret{ca.fn(par)};

    // std::cout << "ret" << *ret << "\npar" << *par << '\n';
    // delete ret;
    // delete par;

    A* ptr{new C{}};

    std::cout << ptr->get() << '\n';

    return 0;
}