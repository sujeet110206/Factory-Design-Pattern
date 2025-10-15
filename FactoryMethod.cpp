#include<iostream>
using namespace std;

// Product Class and subclasses
class Burger {
public:
    virtual void prepare() = 0; // Pure virtual function
    virtual ~Burger() {}; // Virtual destructor
};

class BasicBurger : public Burger {
public:
    void prepare() override {
        cout << "Prepraing Basic Burger with bun, patty, and ketchup!" << endl;
    }
};

class StandardBurger : public Burger {
public:
    void prepare() override {
        cout << "Prepraing Standard Burger with bun, patty, cheese, and lettuce!" << endl;
    }
};

class PremiumBurger : public Burger {
public:
    void prepare() override {
        cout << "Prepraing Premium Burger with gourmet bun, premium patty, lettuce, and secret sauce!" << endl;
    }
};

class BasicWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Prepraing Basic Wheat Burger with bun, patty, and ketchup!" << endl;
    }
};

class StandardWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Prepraing Standard Wheat Burger with bun, patty, cheese, and lettuce!" << endl;
    }
};

class PremiumWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Prepraing Premium Wheat Burger with gourmet bun, premium patty, lettuce, and secret sauce!" << endl;
    }
};

// Factory and its concrete
class BurgerFactory {
public:
    virtual Burger* createBurger(string& type) = 0;
};

class SinghBurger : public BurgerFactory {
public:
    Burger* createBurger(string& type) override {
        if (type == "basic") {
            return new BasicBurger();
        } else if (type == "standard") {
            return new StandardBurger();
        } else if (type == "premium") {
            return new PremiumBurger();
        } else {
            cout << "Invalid burger type!" << endl;
            return nullptr;
        }
    }
};

class KingBurger : public BurgerFactory {
public:
    Burger* createBurger(string& type) override {
        if (type == "basic") {
            return new BasicWheatBurger();
        } else if (type == "standard") {
            return new StandardWheatBurger();
        } else if (type == "premium") {
            return new PremiumWheatBurger();
        } else {
            cout << "Invalid burger type!" << endl;
            return nullptr;
        }
    }
};

int main() {
    string burgerType = "basic";

    BurgerFactory* myFactory = new SinghBurger();

    Burger* burger = myFactory->createBurger(burgerType);

    burger->prepare();

    return 0;
}