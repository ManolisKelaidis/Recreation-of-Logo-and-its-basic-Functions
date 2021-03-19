#include "logo.h"
#define NUM 1
#define BOOL 2
#define STR 3
#define ARR 4

ShowConsole show_console;
PenColor pen;
ScreenColor scr;
Print print;
moveXY xy;
moveCircle circle;
moveBack mback;
moveForward mforward;
moveRight mright; 
moveLeft mleft; 
std::vector<Var> t1;
Var t0; 
Var tlist;
Var tgraphics;
double tmpn;
bool tmpb; 
std::string tmps;

void doNothing() {}
std::vector<int> repcount;
int nested = 0;
std::list<Var> getValue(Var li)
{
	return li.ls;
}

Var::Var()
{

}

Var::Var(double val)
{
	numVal = val;
	type = NUM;
}

Var::Var(bool val)
{
	boolVal = val;
	type = BOOL;
}

Var::Var(std::string val)
{
	strVal = val;
	type = STR;
}



Var::Var(std::vector<Var> val)
{
	vec = val;
	type = ARR;
}

double Var::getnumVal()
{
	return numVal;
}

bool Var::getboolVal()
{
	return boolVal;
}

std::string Var::getstrVal()
{
	return strVal;
}

int Var::getType()
{
	return type;
}



Var getParam(Var param)
{
	return param;
}

Var getItem(std::initializer_list<Var> index, Var src)
{
	std::initializer_list<Var>::iterator it;
	int index_val;
	Var ret = src;
	for (it = index.begin(); it != index.end(); ++it)
	{	
		
		index_val = ((Var *)it)->getnumVal();
		std::cout << "Vec size  =" << ret.vec.size() << "Index val = " << index_val << std::endl;
		ret = Var( ret.vec[index_val - 1]);
		
	}
	return ret;
}



void setItemIterate(std::initializer_list<Var> index, Var& src, Var val, int i)
{
	std::initializer_list<Var>::iterator it;
	int index_val, x;
	it = index.begin();
	for (x = 1; x <= i; x++)	it++;
	index_val = ((Var *)it)->getnumVal();
	if (it != index.end())
	{
		setItemIterate(index, src.vec[index_val - 1], val, i + 1);
		src.vec[index_val - 1] = val;
	}
}

void setItem(std::initializer_list<Var> index, Var& src, Var val)
{
	if (src.getType() != ARR)
	{
		std::cout << "Error in SETITEM function. second argument is not an ARRAY.\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
	setItemIterate(index, src, val, 0);
	
}

Var Var::operator,(Var v)
{
	if (ls.size() == 0)	ls.push_back(*this);
	ls.push_back(v);

	return *this;
}

Var Var::operator[](Var v)
{
	return v;
}

bool operator==(Var v1, Var v2)
{
	if (v1.getType() != v2.getType())	return false;
	if (v1.getType() == NUM && v1.getnumVal() == v2.getnumVal())	return true;
	if (v1.getType() == BOOL && v1.getboolVal() == v2.getboolVal())	return true;
	if (v1.getType() == STR && v1.getstrVal() == v2.getstrVal())	return true;
	if (v1.getType() == ARR && v1.vec == v2.vec)	return true;
	return false;
}

bool operator!=(Var v1, Var v2)
{
	return !(v1 == v2);
}

bool operator>(Var v1, Var v2)
{
	if (v1.getType() != v2.getType())
	{
		std::cout << "Cannot use relational operators for variables of different types.\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
	if (v1.getType() == NUM && v1.getnumVal() > v2.getnumVal())	return true;
	if (v1.getType() == BOOL && v1.getboolVal() > v2.getboolVal())	return true;
	if (v1.getType() == STR && v1.getstrVal() > v2.getstrVal())	return true;
	if (v1.getType() == ARR && v1.vec > v2.vec)	return true;
	return false;
}

bool operator<(Var v1, Var v2)
{
	if (v1.getType() != v2.getType())
	{
		std::cout << "Cannot use relational operators for variables of different types.\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
	if (v1.getType() == NUM && v1.getnumVal() < v2.getnumVal())	return true;
	if (v1.getType() == BOOL && v1.getboolVal() < v2.getboolVal())	return true;
	if (v1.getType() == STR && v1.getstrVal() < v2.getstrVal())	return true;
	if (v1.getType() == ARR && v1.vec < v2.vec)	return true;
	return false;
}

bool operator>=(Var v1, Var v2)
{
	return !(v1 < v2);
}

bool operator<=(Var v1, Var v2)
{
	return !(v1 > v2);
}

bool evaluate(Var v)
{
	if (v.getType() == NUM && v.getnumVal() == 0)	return false;
	if (v.getType() == BOOL)	return v.getboolVal();
	return true;
}

bool evaluate(bool v)
{
	return v;
}

bool eval_not(Var v)
{
	return !evaluate(v);
}

Var get_argument(Var list, Var index)
{	
	std::list<Var>::iterator iter, it;

	if (index.getType() != NUM)
	{
		std::cout << "Error in ARG. Expected a number.\n";
		system("pause");
		exit(EXIT_FAILURE);
	}

	if (list.ls.empty())
	{
		std::cout << "Error in ARG. List is empty.\n";
		system("pause");
		exit(EXIT_FAILURE);
	}

	int i, num_of_iterations = index.getnumVal();
	Var ret;

	for (i = 1, iter = list.ls.begin(), it = iter; i < num_of_iterations;  i++, ++iter, it = iter )
	{
		
		if (iter == list.ls.end())
		{
			std::cout << "Error in ARG. Index is out of bounds.\n";
			system("pause");
			exit(EXIT_FAILURE);
		}
	}
	if (it == list.ls.end())
	{
		std::cout << "Error in ARG. Index is out of bounds.\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
	ret = *it;
	return ret;
}

