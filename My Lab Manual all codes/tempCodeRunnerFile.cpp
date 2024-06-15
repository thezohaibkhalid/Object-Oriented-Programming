

class Base {
public:
    virtual void display() {
        cout << "It's of base class display() function" << endl;
    }
};

class Derived : public Base {
public:
    void display() {
        cout << "It's of derived class display() function" << endl;
    }
};
