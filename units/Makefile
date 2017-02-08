##
## Makefile for  in /home/brout_m/rendu/cpp/cpp_nanotekspice/units
##
## Made by brout_m
## Login   <marc.brout@epitech.eu>
##
## Started on  Wed Feb  8 10:39:36 2017 brout_m
## Last update Wed Feb  8 11:23:58 2017 brout_m
##

TEST4001=	tests4001
TEST4008=	tests4008
TEST4011=	tests4011
TESTINPUT=	testsInput
TESTOUTPUT=	testsOutput

COMPONENTPATH= ../src/component

TESTSSRC=	$(COMPONENTPATH)/ComponentFactory.cpp \
		$(COMPONENTPATH)/Component.cpp \
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
		$(COMPONENTPATH)/Component4514.cpp \
		$(COMPONENTPATH)/ComponentInput.cpp \
		$(COMPONENTPATH)/ComponentOutput.cpp \
		$(COMPONENTPATH)/ComponentClock.cpp \
		$(COMPONENTPATH)/ComponentTrue.cpp \
		$(COMPONENTPATH)/ComponentFalse.cpp \
		$(COMPONENTPATH)/Gates.cpp

TEST4001SRC=	$(TESTSSRC) \
		./tests-component4001.cpp
TEST4008SRC=	$(TESTSSRC) \
		./tests-component4008.cpp
TEST4011SRC=	$(TESTSSRC) \
		./tests-component4011.cpp
TESTINPUTSRC=	$(TESTSSRC) \
		./tests-componentInput.cpp
TESTOUTPUTSRC=	$(TESTSSRC) \
		./tests-componentOutput.cpp

TEST4001OBJ=	$(TEST4001SRC:.cpp=.o)
TEST4008OBJ=	$(TEST4008SRC:.cpp=.o)
TEST4011OBJ=	$(TEST4011SRC:.cpp=.o)
TESTINPUTOBJ=	$(TESTINPUTSRC:.cpp=.o)
TESTOUTPUTOBJ=	$(TESTOUTPUTSRC:.cpp=.o)

INC=		-I../include

CXX= 		g++ $(INC) -std=c++11

CFLAGS=		-g $(INC)

$(TEST4001): $(TESTOUTPUT) $(TESTINPUT) $(TEST4008) $(TEST4011) $(TEST4001OBJ)
	g++ -o $(TEST4001) $(TEST4001OBJ) $(INC)

$(TEST4008): $(TEST4008OBJ)
	g++ -o $(TEST4008) $(TEST4008OBJ) $(INC)

$(TEST4011): $(TEST4011OBJ)
	g++ -o $(TEST4011) $(TEST4011OBJ) $(INC)

$(TESTINPUT): $(TESTINPUTOBJ)
	g++ -o $(TESTINPUT) $(TESTINPUTOBJ) $(INC)

$(TESTOUTPUT): $(TESTOUTPUTOBJ)
	g++ -o $(TESTOUTPUT) $(TESTOUTPUTOBJ) $(INC)

all: $(TEST4001)

clean:
	rm -rf $(TEST4001OBJ)
	rm -rf $(TEST4008OBJ)
	rm -rf $(TEST4011OBJ)
	rm -rf $(TESTINPUTOBJ)
	rm -rf $(TESTOUTPUTOBJ)

fclean: clean
	rm -rf $(TEST4001)
	rm -rf $(TEST4008)
	rm -rf $(TEST4011)
	rm -rf $(TESTINPUT)
	rm -rf $(TESTOUTPUT)

re: fclean all

.PHONY: make clean fclean re
