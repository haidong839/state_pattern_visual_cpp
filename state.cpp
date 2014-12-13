// state.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
using namespace System;

ref class EmotionalState abstract {
public:
	virtual String^ sayHello() = NULL;
	virtual String^ sayGoodbye() = NULL;

};

ref class HappyState : EmotionalState {
public:
	virtual String^ sayGoodbye() override  {
		return "Bye, friend!";
	}
	virtual  String^ sayHello() override {
		return "Hello, friend!";
	}
};

ref class SadState : EmotionalState {
public:
	virtual String^ sayGoodbye() override  {
		return "Bye, sniff!";
	}
	virtual  String^ sayHello() override {
		return "Hello, sniff!";
	}
};

ref class Person : EmotionalState {
public:
	EmotionalState^ emotionalState;

	Person(EmotionalState^ emotionalState) {
		this->emotionalState = emotionalState;
	}
	void setEmotionalState(EmotionalState^ emotionalState) {
		this->emotionalState = emotionalState;
	}

	virtual String^ sayGoodbye() override {
		return emotionalState->sayGoodbye();
	}

	virtual String^ sayHello() override  {
		return emotionalState->sayHello();
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Person^ person = gcnew Person(gcnew HappyState());
	Console::WriteLine("Hello in happy state: " + person->sayHello());
	Console::WriteLine("Goodbye in happy state: " + person->sayGoodbye());

	person->setEmotionalState(gcnew SadState());
	Console::WriteLine("Hello in sad state: " + person->sayHello());
	Console::WriteLine("Goodbye in sad state: " + person->sayGoodbye());
	Console::ReadLine();

	return 0;
}

