##
## Makefile for  in /home/brout_m/rendu/cpp/cpp_nanotekspice/units
##
## Made by brout_m
## Login   <marc.brout@epitech.eu>
##
## Started on  Wed Feb  8 10:39:36 2017 brout_m
## Last update Thu Feb 16 16:09:59 2017 brout_m
##

NANOTEKSPICE=	nanotekspice

NANOLIBRARY=	libnanotekspice.a

COMPONENTPATH= 	src/component

EXECUTIONPATH= 	src/execution

PARSERPATH=	src/parser

SRC=		$(COMPONENTPATH)/Component2716.cpp \
		$(COMPONENTPATH)/Component4001.cpp \
		$(COMPONENTPATH)/Component4008.cpp \
		$(COMPONENTPATH)/Component4011.cpp \
		$(COMPONENTPATH)/Component4013.cpp \
		$(COMPONENTPATH)/Component4017.cpp \
		$(COMPONENTPATH)/Component4030.cpp \
		$(COMPONENTPATH)/Component4040.cpp \
		$(COMPONENTPATH)/Component4069.cpp \
		$(COMPONENTPATH)/Component4071.cpp \
		$(COMPONENTPATH)/Component4081.cpp \
		$(COMPONENTPATH)/Component4094.cpp \
		$(COMPONENTPATH)/Component4514.cpp \
		$(COMPONENTPATH)/ComponentFactory.cpp \
		$(COMPONENTPATH)/ComponentClock.cpp \
		$(COMPONENTPATH)/ComponentFalse.cpp \
		$(COMPONENTPATH)/ComponentInput.cpp \
		$(COMPONENTPATH)/ComponentOutput.cpp \
		$(COMPONENTPATH)/ComponentTrue.cpp \
		$(COMPONENTPATH)/Component.cpp \
		$(COMPONENTPATH)/Gates.cpp \
		$(PARSERPATH)/Parser.cpp

SRCMAIN =	$(EXECUTIONPATH)/Loop.cpp \
		$(EXECUTIONPATH)/main.cpp


OBJ=		$(SRC:.cpp=.o)

OBJMAIN=	$(SRCMAIN:.cpp=.o)

INC=		-I./include/

CXX= 		g++

CXXFLAGS=	 -std=c++14 -W -Wall -Wextra -Werror $(INC)

$(NANOTEKSPICE): $(NANOLIBRARY) $(OBJMAIN)
	$(CXX) -o $(NANOTEKSPICE) $(OBJMAIN) $(INC) -L./ -lnanotekspice

$(NANOLIBRARY): $(OBJ)
	ar rc $(NANOLIBRARY) $(OBJ)
	ranlib $(NANOLIBRARY)

all: $(NANOLIBRARY) $(NANOTEKSPICE)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJMAIN)

fclean: clean
	rm -rf $(NANOLIBRARY)
	rm -rf $(NANOTEKSPICE)

re: fclean all

.PHONY: make clean fclean re