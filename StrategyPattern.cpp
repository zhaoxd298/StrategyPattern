#include <iostream>

using namespace std;

// 策略模式(StrategyPattern)
// 定义了算法族，分别封装起来，让他们之间可以互相替换
// 次模式让算法的变化独立于使用算法的客户

/*--------------------Fly(算法)-------------------------*/
class FlyBehavior {
public:
	virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior {
	void fly()
	{
		// 实现鸭子飞行
		cout << "FlyWithWings" << endl;
	}
};

class FlyNoWay : public FlyBehavior {
	void fly()
	{
		// 什么都不做，不会飞
		cout << "FlyNoWay" << endl;
	}
};

class FlyRocketPowered : public FlyBehavior {
	void fly()
	{
		// 像火箭一样飞
		cout << "FlyRocketPowered" << endl;
	}
};
/*---------------------------------------------------*/


/*-----------------------Quack(算法)------------------------*/
class QuackBehavior {
public:
	virtual void quack() = 0;	
};

class Quack : public QuackBehavior {
public:
	void quack() 
	{
		// 实现鸭子呱呱叫
		cout << "Quack" << endl;
	}
};

class Squeak : public QuackBehavior {
public:
	void quack() 
	{
		// 橡皮鸭子吱吱叫
		cout << "Squeak" << endl;
	}
};

class MuteQuack : public QuackBehavior {
public:
	void quack() 
	{
		// 什么都不做，不会叫
		cout << "MuteQuack" << endl;
	}
};
/*------------------------------------------------------*/


/*------------------------Duck----------------------------*/
class Duck {
private:
	FlyBehavior* m_flyBehavior;
	QuackBehavior* m_quackBehavior;

public:
	void setFlyBehavior(FlyBehavior* flyBehavior)
	{
		m_flyBehavior = flyBehavior;
	}
	void setQuackBehavior(QuackBehavior* quackBehavior)
	{
		m_quackBehavior = quackBehavior;
	}
	void performFly()
	{
		m_flyBehavior->fly();
	}
	void performQuack()
	{
		m_quackBehavior->quack();
	}

	virtual void swim() {}
	virtual void display() {}
};

// 绿头鸭
class MallardDuck : public Duck {
public:
	MallardDuck()
	{
		this->setQuackBehavior(new Quack());
		this->setFlyBehavior(new FlyWithWings());
	}

	void display()
	{
		cout << "I'm a real Mallard duck!" << endl;
	}
};

// 模型鸭
class ModelDuck : public Duck {
public:
	ModelDuck()
	{
		this->setQuackBehavior(new Quack());
		this->setFlyBehavior(new FlyNoWay());
	}

	void display()
	{
		cout << "I'm a model duck!" << endl;
	}
};

// 橡皮鸭
class RubberDuck : public Duck {
public:
	RubberDuck()
	{
		this->setQuackBehavior(new Squeak());
		this->setFlyBehavior(new FlyNoWay());
	}

	void display()
	{
		cout << "I'm a model duck!" << endl;
	}
};
/*----------------------------------------------------------------*/



int main()
{
	/*Duck* mallard = new MallardDuck();
	mallard->performQuack();
	mallard->performFly();*/

	Duck* rubber = new RubberDuck();
	rubber->performQuack();
	rubber->performFly();
	rubber->setFlyBehavior(new FlyRocketPowered());
	rubber->performFly();
}