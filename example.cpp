#include "logo.h"
#include <string>
#include <iterator>
#include <list>
#include <initializer_list>

TO takis WITH b FSTART
; std::cout << "inside of function list is = \n";
SHOW:tlist

SHOW : ARG(NUMBER : 3)


	FEND

START_PROGRAM

FORWARD (NUMBER:5)
LEFT (NUMBER:5)


BACK (NUMBER: 4)

MAKE turtleMoves = LIST[
	ARRAY{ (WORD:"FORWARD"), (NUMBER: 100) },
		ARRAY{ (WORD:"RIGHT"), (NUMBER: 90) },
		ARRAY{ (WORD:"FORWARD"), (NUMBER: 100) },
		ARRAY{ (WORD:"RIGHT"), (NUMBER: 90) },
		ARRAY{ (WORD:"FORWARD"), (NUMBER: 100) },
		ARRAY{ (WORD: "LEFT"), (NUMBER: 90) },
		ARRAY{ (WORD: "FORWARD"), (NUMBER: 100) },
		ARRAY{ (WORD: "LEFT"), (NUMBER: 90) }
]



CENTER
REPEAT (NUMBER:2) TIMES DO
	FOREACH turtleMoves DO
	IF ITEM({ (NUMBER: 1) }, ELEM) == (WORD: "FORWARD") DO
		FORWARD ITEM({ (NUMBER: 2) }, ELEM)
	ELIF ITEM({ (NUMBER: 1) }, ELEM) == (WORD: "BACK") DO
		BACK ITEM({ (NUMBER: 2) }, ELEM)
	ELIF ITEM({ (NUMBER: 1) }, ELEM) == (WORD: "LEFT") DO
		LEFT ITEM({ (NUMBER: 2) }, ELEM)
	ELSE
		RIGHT ITEM({ (NUMBER: 2) }, ELEM)
END
END
END

PENUP
CENTER
RIGHT(NUMBER: 90)
FORWARD(NUMBER: 150)
PENDOWN
REPEAT(NUMBER: 360) TIMES DO
FORWARD(NUMBER: 2)
RIGHT(NUMBER: 1)
END









MAKE exmpl = LIST[NUMBER:4, WORD : "lol", NUMBER : 2, WORD : "ADFASDF", BOOLEAN : TRUE]
; std::cout << "Out of function list is = \n";
SHOW:exmpl
SHOW: tlist
CALL takis(exmpl)
//exmpl = t0[t0=...= 4, t0=...=lol, ...]

MAKE v = NUMBER:6
MAKE u =  NUMBER:-2
MAKE word = WORD : "Takis"
ASSIGN v = PRODUCT(v,u)
MAKE a = SENTENCE((WORD : "Vlakas"), word)

MAKE b = DIFFERENCE(NUMBER:5,NUMBER:2,DIFFERENCE(NUMBER:21,NUMBER:7))
MAKE c = QUOTIENT(NUMBER:20,NUMBER:2,NUMBER:5)


; std::cout << "c = " << c.getnumVal() << std::endl;
//MAKE sub2 = LIST[WORD:"Hey", NUMBER : 10]

 //PRINT(WORD:"EISAI XAZOS")
//SETXY  m,m 
//RIGHT (NUMBER: 45)
//FORWARD(NUMBER:20)

MAKE number = (WORD:"fgljdf")

MAKE arr = ARRAY{ WORD: "test", ARRAY{ NUMBER: 5, WORD : "Yay" },NUMBER : 12.3, number, WORD : "Takis" }
SHOW:arr
MAKE sub = LIST[WORD:"Hey", NUMBER : 10]



MAKE cont = ITEM({ NUMBER: 2, NUMBER : 1 }, arr)

MAKE variable = (WORD:"newval")

SETITEM({ NUMBER: 3 }, arr, variable)

MAKE n1 = NUMBER: 19

MAKE n2 = NUMBER : 2

MAKE n3 = MODULO(n1, (NUMBER: 4))

; std::cout << "Operation result = " << n3.getnumVal() << "\n";

//Loops and repcount testing
REPEAT n1 TIMES DO
std::cout << "Yay iteration.\n";
SHOW:REPCOUNT
REPEAT(NUMBER: 4) TIMES DO
std::cout << "Yay  second iteration.\n";
 SHOW:REPCOUNT
	 END
	 END

	 REPEAT WHILE(n2 < n1) DO
	 SHOW : REPCOUNT
	 ASSIGN n2 = SUM(n2, (NUMBER:1))
	 SHOW : n2
	 REPEAT n1 TIMES DO
	 std::cout <<"Nested ";
  SHOW:REPCOUNT
	  END
	  END
	  //moveXY a = NUMBER : 2, NUMBER : 3
	  
	 // MAKE a = NUMBER : 2, NUMBER : 3
	  //SETXY NUMBER:2,NUMBER3
	  ; std::list<Var> ex;

std::cout << "SHOW LIST:\n";
FOREACH exmpl DO
	
	SHOW:REPCOUNT
END

//std::cout << Filler::getParam(ELMT);
//for(Var a : getValue(ex));

IF AND(n1 == (NUMBER: 1), n2, (BOOLEAN: FALSE), n1) DO std::cout << "This statement is true\n"; ELSE std::cout << "This statement is false\n"; END

/*std::initializer_list<Var>::iterator it;
for (it = arr.begin(); it != arr.end(); ++it) {
if( it->type == 3) std::cout << it->strVal << std::endl;
else std::cout << it->numVal << std::endl;
}*/


if (arr.vec[2].getType() == 3)	std::cout << "Result = " << arr.vec[2].getstrVal() << std::endl;
else std::cout << "Result = " << arr.vec[2].getnumVal() << std::endl;

std::list<Var>::iterator iter;

for (iter = a.ls.begin(); iter != a.ls.end(); ++iter) {
if (iter->getType() == 3) std::cout << iter->getstrVal() << std::endl;
else std::cout << iter->getnumVal() << std::endl;
}

; std::cout << number.getstrVal() << std::endl;
; system("pause");
END_PROGRAM

//;Var number = (t0 = Var(), t0.numVal = 1==0?0:2)