
#include "./hy352_gui.h"
#ifdef APPLE
#include <allegro5/allegro.h>
#endif
#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <initializer_list>
#include <cmath>
#include <string>



extern int nested;
extern std::vector<int> repcount;
#define START_PROGRAM int main(int argc, char **argv){init_GUI();
#define END_PROGRAM  ;destroy_GUI();return 0; } 
#define MAKE ;auto


#define NUMBER t0 = Var(tmpn) = tmpn = 1==0?0
#define BOOLEAN  t0 = Var(tmpb) = tmpb = 1==0?0
#define WORD  t0 = Var(tmps) = tmps = 1==0?0
#define ARRAY t0 = Var(t1) = (std::vector<Var>) t1 = 
#define LIST tlist = t0
#define SENTENCE

#define SETITEM ;setItem
#define ITEM getItem

#define AND eval_and
#define OR eval_or
#define NOT eval_not

#define IF ;repcount.push_back(0);nested++;if(evaluate(
#define DO )){repcount[nested - 1]++;
#define END ;}repcount.pop_back();nested--;
#define ELIF ;}else if(evaluate(
#define ELSE ;}else {repcount[nested - 1]++;

#define REPCOUNT Var((double) repcount[nested - 1])
#define REPEAT ;repcount.push_back(0);nested++;for( int i = 0; i < 
#define TIMES .getnumVal(); i++, doNothing(
#define WHILE 0; i++); while(evaluate(
#define FOREACH ;repcount.push_back(0);nested++;for(Var ELMT : getValue(

#define SHOW ;show_console = (1==0)?Var()
#define ELEM getParam(ELMT)

#define ASSIGN ;
#define SUM operation_plus
#define DIFFERENCE OPERATIONMIN
//defines an intermediate macro and then calls the actual function with an extra parameter (a counter)
#define OPERATIONMIN(...) operation_minus(0, __VA_ARGS__)  
#define PRODUCT operation_mul
#define QUOTIENT OPERATIOND
#define OPERATIOND(...) operation_div(0, __VA_ARGS__)    
#define MODULO operation_mod

#define FORWARD ;mforward = tgraphics =
#define RIGHT ;mright =
#define LEFT ;mleft =
#define PENDOWN ;pen_down();
#define PENUP ;pen_up();
#define CENTER ;turtle_go_to_center();
#define BACK ;mback =
#define CIRCLE ;circle = 
#define SETXY ;xy = (moveXY) 
#define PRINT ;print=
#define SETSCREENCOLOR ;scr = 
#define SETPENCOLOR ;pen=

#define TO void
#define WITH (  Var
#define FSTART ) { Var FUNCTION_ARGUMENTS = tlist; 
#define FEND ;}
#define ARG(a) get_argument(FUNCTION_ARGUMENTS, a)
#define RETURN ;return;
#define CALL ;

#define TRUE true
#define FALSE false

void doNothing();

class Var 
{
	std::string strVal;
	double numVal;
	bool boolVal;
	int type;
public:
	std::vector<Var> vec;
	std::list<Var> ls;

	Var();
	Var(double val);
	Var(bool val);
	Var(std::string val);
	Var(std::vector<Var> val);
	
	double getnumVal();
	bool getboolVal();
	std::string getstrVal();
	int getType();

	Var operator,(Var v);
	Var operator[](Var v);
};



class ShowConsole
{
public:
	ShowConsole() {}
	ShowConsole(Var v)
	{	

		show(v);
		
	}
	void show(Var v)
	{
	
		if (!(v.ls.empty()))
		{
			std::list<Var>::iterator it;
			std::cout << "LIST [\n";
			for (it = v.ls.begin(); it != v.ls.end(); ++it) show(*it);
			
			std::cout << "]\n";
		}
		else if (v.getType() == 1)	std::cout << v.getnumVal();
		else if (v.getType() == 2)	std::cout << v.getboolVal();
		else if (v.getType() == 3)	std::cout << v.getstrVal();
		else if (v.getType() == 4)
		{
			std::cout << "ARRAY {\n";
			for (int i = 0; i < v.vec.size(); i++) show(v.vec[i]);
			std::cout << "}\n";
		}

		std::cout << "\n";
	}
};

class moveForward
{
public:
	moveForward() {}
	moveForward(Var v) 
	{
		if (v.getType() == 1)
		{
			turtle_mv_forward(v.getnumVal());
		}
		else
		{
			std::cout << "Incompatible argument type in FORWARD" << std::endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
	}
	
};

class ScreenColor
{
public:
	ScreenColor() {}
	ScreenColor(Var v)
	{	
		std::vector<int> vec;
		std::list<Var>::iterator iter;
		for (iter = v.ls.begin(); iter != v.ls.end(); ++iter)
		{
			vec.push_back(iter->getnumVal());
		}
		if(vec.size()==3)
		set_screen_color(vec[0], vec[1], vec[2]);
		
		
	}

};


class PenColor 
{
public:
	PenColor() {}
	PenColor(Var v)
	{
		std::vector<int> vec;
		std::list<Var>::iterator iter;
		for (iter = v.ls.begin(); iter != v.ls.end(); ++iter)
		{
			vec.push_back(iter->getnumVal());
		}
		if (vec.size() == 3)
			set_pen_color(vec[0], vec[1], vec[2]);


	}

};

class moveXY 
{
public:
	moveXY() {}
	moveXY(Var v1,Var v2)
	{
		
		if (v1.getType() == 1 && v2.getType()==1)
		{
			turtle_go_to_position(v1.getnumVal(),v2.getnumVal());
		}
		else
		{
			std::cout << "Incompatible argument type in XY" << std::endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
	}

};

class moveRight
{
public:
	moveRight(){}
	moveRight(Var v)
	{
		if (v.getType() == 1)
		{
			turtle_rotate(v.getnumVal());
		}
		else
		{
			std::cout << "Incompatible argument type in RIGHT" << std::endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
	}

};

class moveCircle
{
public:
	moveCircle() {}
	moveCircle(Var v)
	{
		if (v.getType() == 1)
		{
			turtle_draw_circle(v.getnumVal());
		}
		else
		{
			std::cout << "Incompatible argument type in Circle" << std::endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
	}

};

class moveLeft
{
public:
	moveLeft() {}
	moveLeft(Var v)
	{
		if (v.getType() == 1)
		{
			turtle_rotate(-v.getnumVal());
		}
		else
		{
			std::cout << "Incompatible argument type in LEFT" << std::endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
	}

};

class Print
{
public:
	Print() {}
	Print(Var v)
	{
		if (v.getType() == 3)
		{
			turtle_draw_label((v.getstrVal()).c_str());
		}
		else
		{
			std::cout << "Incompatible argument type in PRINT" << std::endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
	}

};


class moveBack
{
public:
	moveBack() {}
	moveBack(Var v)
	{
		if (v.getType() == 1)
		{
			turtle_mv_backward(v.getnumVal());
		}
		else
		{
			std::cout << "Incompatible argument type in BACK" << std::endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
	}

};


std::list<Var> getValue(Var li);

bool operator==(Var v1, Var v2);
bool operator!=(Var v1, Var v2);
bool operator>(Var v1, Var v2);
bool operator<(Var v1, Var v2);
bool operator>=(Var v1, Var v2);
bool operator<=(Var v1, Var v2);

Var getParam(Var param);


Var getItem(std::initializer_list<Var> index, Var src);

void setItem(std::initializer_list<Var> index, Var& src, Var val);

bool evaluate(Var v);
bool evaluate(bool v);

bool eval_not(Var v);

template<typename Var> Var operation_plus(Var arg)
{
	return arg;
}
template<typename Var, typename... Args> Var operation_plus(Var start, Args ... args)
{
	Var ret = operation_plus(args...);
	if (start.getType() != 1 || ret.getType() != 1) //They must be numbers.
	{
		std::cout << "Error in SUM function. Argument is not a NUMBER.\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
	return Var(start.getnumVal() + ret.getnumVal());
}

template<typename Var> Var operation_minus(int counter, Var arg)
{
	return Var(-arg.getnumVal());
}
template<typename Var, typename... Args> Var operation_minus(int counter, Var start, Args ... args)
{
	Var ret = operation_minus(counter + 1, args...);
	if (start.getType() != 1 || ret.getType() != 1) //They must be numbers.
	{
		std::cout << "Error in DIFFERENCE function. Argument is not a NUMBER.\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
	if (counter == 0)
	{
		return Var(start.getnumVal() + ret.getnumVal());
	}
	return Var(-start.getnumVal() + ret.getnumVal());
}
template<typename Var> Var operation_mul(Var arg)
{
	return arg;
}
template<typename Var, typename... Args> Var operation_mul(Var start, Args ... args)
{
	Var ret = operation_mul(args...);
	if (start.getType() != 1 || ret.getType() != 1) //They must be numbers.
	{
		std::cout << "Error in PRODUCT function. Argument is not a NUMBER.\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
	return Var(start.getnumVal() * ret.getnumVal());
}

template<typename Var> Var operation_div(int counter, Var arg)
{
	return Var(1 / arg.getnumVal());
}
template<typename Var, typename... Args> Var operation_div(int counter, Var start, Args ... args)
{
	Var ret = operation_div(counter + 1, args...);
	if (start.getType() != 1 || ret.getType() != 1) //They must be numbers.
	{
		std::cout << "Error in QUOTIENT function. Argument is not a NUMBER.\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
	if (counter == 0)
	{
		return Var(start.getnumVal() * ret.getnumVal());
	}
	return Var(1 / start.getnumVal() * ret.getnumVal());
}

template<typename Var> Var operation_mod(Var arg)
{
	return Var(arg.getnumVal());
}
template<typename Var, typename... Args> Var operation_mod(Var start, Args ... args)
{
	Var ret = Var(operation_mod(args...));
	if (start.getType() != 1 || ret.getType() != 1) //They must be numbers.
	{
		std::cout << "Error in MODULO function. Argument is not a NUMBER.\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
	return Var(std::fmod(start.getnumVal(), ret.getnumVal()));
}

template<typename Var> bool eval_and(Var arg)
{
	return evaluate(arg);
}
template<typename Var, typename... Args> bool eval_and(Var start, Args ... args)
{
	bool ret = eval_and(args...);
	return evaluate(start) && evaluate(ret);
}

template<typename Var> bool eval_or(Var arg)
{
	return evaluate(arg);
}
template<typename Var, typename... Args> bool eval_or(Var start, Args ... args)
{
	bool ret = eval_or(args...);
	return evaluate(start) || evaluate(ret);
}
Var get_argument(Var list, Var index);

extern ShowConsole show_console;
extern PenColor pen;
extern ScreenColor scr;
extern Print print;
extern moveXY xy;
extern moveCircle circle;
extern moveBack mback;
extern moveForward mforward;
extern moveRight mright;
extern moveLeft mleft;
extern Var t0;
extern Var tgraphics;
extern Var tlist;
extern std::vector<Var> t1;
extern double tmpn;
extern bool tmpb;
extern std::string tmps;