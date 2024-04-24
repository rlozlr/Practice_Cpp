﻿/*
구조체에 대한 복습을 겸할 수 있는 문제를 제시하겠다.
2차원 평면상에서의 좌표를 표현할 수 있는 구조체를 다음과 같이 정의하였다.

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

위의 구조체를 기반으로 두 점의 합을 계산하는 함수를 다음의 형태로 정의하고(덧셈결과는 함수의 반환을 통해서 얻게 한다.)
Point& PntAdder(const Point &p1, const Point &p2);

임의의 두 점을 선언하여, 위 함수를 이용한 덧셈연산을 진행하는 main 함수를 정의해보자.
단, 구조에 Point 관련 변수의 선언은 무조건 new 연산자를 이용해서 진행해야 하며, 할당된 메모리 공간의 소멸도 철저해야한다.
참고로 이 문제의 해결을 위해서는 다음 두 질문에 답을 할 수 있어야 한다.
	- 동적할당 한 변수를 함수의 참조형 매개변수의 인자로 어떻게 전달해야 하는가?
	- 함수 내에 선언된 변수를 참조형으로 반환하려면 해당 변수는 어떻게 선언해야 하는가?
*/

#include <iostream>

// java의 vo class 같은 것
typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point& p1, const Point& p2)
{
	// java로 표현하자면 Point pptr = new Point(); 이런 느낌으로 쓴 것
	Point* pptr = new Point;
	// 포인터가 객체에 접근할 때는 '->'로 
	pptr->xpos = p1.xpos + p2.xpos;
	pptr->ypos = p1.ypos + p2.ypos;
	return *pptr;
}

int main()
{
	Point* pptr1 = new Point;
	pptr1->xpos = 1;
	pptr1->ypos = 9;

	Point* pptr2 = new Point;
	pptr2->xpos = 4;
	pptr2->ypos = 8;

	Point& pref = PntAdder(*pptr1, *pptr2);
	std::cout << "[" << pref.xpos << ", " << pref.ypos << "]" << std::endl;

	// java는 JVM에서 GC가 자동으로 메모리 관리를 해줘서 할 필요 없지만 C++은 메모리 관리까지 해주어야 되기 때문
	delete pptr1;
	delete pptr2;
	delete& pref;


	return 0;
}