#include <iostream>
#include <string>

using namespace std;


class Strategy{
public:
    virtual ~Strategy() {

    }
    virtual int result(int num1, int num2) = 0;
};

class ConcreteStrategyAdd: public Strategy{
public:
    int result(int num1, int num2){
        return num1 + num2;
    }
};

class ConcreteStrategySub: public Strategy{
public:
    int result(int num1, int num2){
        return num1 - num2;
    }
};

class ConcreteStrategyMul: public Strategy{
public:
    int result(int num1, int num2){
        return num1 * num2;
    }
};

class ConcreteStrategyDiv: public Strategy
{
public:
    int result(int num1, int num2){
        return num1 / num2;
    }
};


class Context{
private:
    Strategy* strategy;
public:
    Context(Strategy* strategy){
        this->strategy = strategy;
    }
    int ExecuteStrategy(int a, int b){
        return strategy->result(a, b);
    }
    ~Context(){
        delete strategy;
    }
};


int main(){
    cout << "Enter two arguments" << endl;
    int a , b;
    cin >> a >> b;
    Context* cont = new Context(new ConcreteStrategySub);
    int res = cont->ExecuteStrategy(a,b);
    cout << res;
    delete cont;
    return 0;
}



