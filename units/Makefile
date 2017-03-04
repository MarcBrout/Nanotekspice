##
## Makefile for  in /home/brout_m/rendu/cpp/cpp_nanotekspice/units
##
## Made by brout_m
## Login   <marc.brout@epitech.eu>
##
## Started on  Wed Feb  8 10:39:36 2017 brout_m
## Last update Sat Mar  4 16:29:27 2017 brout_m
##

TEST2716=	tests-2716
TEST4001=	tests-4001
TEST4008=	tests-4008
TEST4011=	tests-4011
TEST4013=	tests-4013
TEST4017=	tests-4017
TEST4030=	tests-4030
TEST4069=	tests-4069
TEST4071=	tests-4071
TEST4081=	tests-4081
TEST4094=	tests-4094
TEST4503=	tests-4503
TEST4512=	tests-4512
TEST4514=	tests-4514
TEST4801=	tests-4801
TESTINPUT=	tests-Input
TESTOUTPUT=	tests-Output
TESTCLOCK=	tests-Clock

COMPONENTPATH= ../src/component

TESTSSRC=		$(COMPONENTPATH)/Component.cpp \
		$(COMPONENTPATH)/Gates.cpp

TEST4001SRC=	$(TESTSSRC) \
		$(COMPONENTPATH)/Component4001.cpp \
		./tests-component4001.cpp

TEST4008SRC=	$(TESTSSRC) \
		$(COMPONENTPATH)/Component4008.cpp \
		./tests-component4008.cpp

TEST4011SRC=	$(TESTSSRC) \
		$(COMPONENTPATH)/Component4011.cpp \
		./tests-component4011.cpp

TEST4013SRC=	$(TESTSSRC) \
		$(COMPONENTPATH)/Component4013.cpp \
		$(COMPONENTPATH)/ComponentClock.cpp \
		./tests-component4013.cpp

TEST4017SRC=	$(TESTSSRC) \
		$(COMPONENTPATH)/Component4017.cpp \
		$(COMPONENTPATH)/ComponentClock.cpp \
		./tests-component4017.cpp

TEST4030SRC=	$(TESTSSRC) \
		$(COMPONENTPATH)/Component4030.cpp \
		./tests-component4030.cpp

TEST4069SRC=	$(TESTSSRC) \
		$(COMPONENTPATH)/Component4069.cpp \
		./tests-component4069.cpp

TEST4071SRC=	$(TESTSSRC) \
        $(COMPONENTPATH)/Component4071.cpp \
        ./tests-component4071.cpp

TEST4081SRC=	$(TESTSSRC) \
        $(COMPONENTPATH)/Component4081.cpp \
        ./tests-component4081.cpp

TEST4094SRC=	$(TESTSSRC) \
        $(COMPONENTPATH)/Component4094.cpp \
		$(COMPONENTPATH)/ComponentClock.cpp \
		$(COMPONENTPATH)/ComponentInput.cpp \
        ./tests-component4094.cpp

TEST4801SRC=	$(TESTSSRC) \
        $(COMPONENTPATH)/Component4801.cpp \
	$(COMPONENTPATH)/ComponentInput.cpp \
        ./tests-component4801.cpp

TEST2716SRC=	$(TESTSSRC) \
        $(COMPONENTPATH)/Component2716.cpp \
		$(COMPONENTPATH)/ComponentInput.cpp \
		$(COMPONENTPATH)/ComponentOutput.cpp \
        ./tests-component2716.cpp

TEST4503SRC=	$(TESTSSRC) \
        $(COMPONENTPATH)/Component4503.cpp \
        ./tests-component4503.cpp

TEST4512SRC=	$(TESTSSRC) \
        $(COMPONENTPATH)/Component4512.cpp \
        ./tests-component4512.cpp

TEST4514SRC=	$(TESTSSRC) \
        $(COMPONENTPATH)/Component4514.cpp \
		$(COMPONENTPATH)/ComponentInput.cpp \
        ./tests-component4514.cpp

TESTINPUTSRC=	$(TESTSSRC) \
		$(COMPONENTPATH)/ComponentInput.cpp \
		./tests-componentInput.cpp

TESTOUTPUTSRC=	$(TESTSSRC) \
		$(COMPONENTPATH)/ComponentOutput.cpp \
		$(COMPONENTPATH)/ComponentInput.cpp \
		./tests-componentOutput.cpp

TESTCLOCKSRC=	$(TESTSSRC) \
		$(COMPONENTPATH)/ComponentClock.cpp \
		./tests-componentClock.cpp

TEST2716OBJ=	$(TEST2716SRC:.cpp=.o)
TEST4001OBJ=	$(TEST4001SRC:.cpp=.o)
TEST4008OBJ=	$(TEST4008SRC:.cpp=.o)
TEST4011OBJ=	$(TEST4011SRC:.cpp=.o)
TEST4013OBJ=	$(TEST4013SRC:.cpp=.o)
TEST4017OBJ=	$(TEST4017SRC:.cpp=.o)
TEST4030OBJ=	$(TEST4030SRC:.cpp=.o)
TEST4069OBJ=	$(TEST4069SRC:.cpp=.o)
TEST4071OBJ=	$(TEST4071SRC:.cpp=.o)
TEST4081OBJ=	$(TEST4081SRC:.cpp=.o)
TEST4094OBJ=	$(TEST4094SRC:.cpp=.o)
TEST4503OBJ=	$(TEST4503SRC:.cpp=.o)
TEST4512OBJ=	$(TEST4512SRC:.cpp=.o)
TEST4514OBJ=	$(TEST4514SRC:.cpp=.o)
TEST4801OBJ=	$(TEST4801SRC:.cpp=.o)
TESTINPUTOBJ=	$(TESTINPUTSRC:.cpp=.o)
TESTOUTPUTOBJ=	$(TESTOUTPUTSRC:.cpp=.o)
TESTCLOCKOBJ=	$(TESTCLOCKSRC:.cpp=.o)

INC=		-I../include

ifeq ($(DEBUG), yes)
CXXFLAGS=	 -std=c++14 -g -W -Wall -Wextra -Werror $(INC)
else
CXXFLAGS=	 -std=c++14 -W -Wall -Wextra -Werror $(INC)
endif

CXX= 		g++

all: $(TEST2716) $(TEST4001) $(TEST4008) $(TEST4011) $(TEST4013) $(TEST4017) $(TEST4030) $(TEST4069) $(TEST4071) $(TEST4081) $(TEST4094) $(TEST4503) $(TEST4512) $(TEST4514) $(TEST4514) $(TEST4801) $(TESTINPUT) $(TESTOUTPUT) $(TESTCLOCK)

$(TEST2716): $(TEST2716OBJ)
	g++ -o $(TEST2716) $(TEST2716OBJ) $(INC)

$(TEST4001): $(TEST4001OBJ)
	g++ -o $(TEST4001) $(TEST4001OBJ) $(INC)

$(TEST4008): $(TEST4008OBJ)
	g++ -o $(TEST4008) $(TEST4008OBJ) $(INC)

$(TEST4011): $(TEST4011OBJ)
	g++ -o $(TEST4011) $(TEST4011OBJ) $(INC)

$(TEST4013): $(TEST4013OBJ)
	g++ -o $(TEST4013) $(TEST4013OBJ) $(INC)

$(TEST4017): $(TEST4017OBJ)
	g++ -o $(TEST4017) $(TEST4017OBJ) $(INC)

$(TEST4030): $(TEST4030OBJ)
	g++ -o $(TEST4030) $(TEST4030OBJ) $(INC)

$(TEST4069): $(TEST4069OBJ)
	g++ -o $(TEST4069) $(TEST4069OBJ) $(INC)

$(TEST4071): $(TEST4071OBJ)
	g++ -o $(TEST4071) $(TEST4071OBJ) $(INC)

$(TEST4081): $(TEST4081OBJ)
	g++ -o $(TEST4081) $(TEST4081OBJ) $(INC)

$(TEST4094): $(TEST4094OBJ)
	g++ -o $(TEST4094) $(TEST4094OBJ) $(INC)

$(TEST4503): $(TEST4503OBJ)
	g++ -o $(TEST4503) $(TEST4503OBJ) $(INC)

$(TEST4512): $(TEST4512OBJ)
	g++ -o $(TEST4512) $(TEST4512OBJ) $(INC)

$(TEST4514): $(TEST4514OBJ)
	g++ -o $(TEST4514) $(TEST4514OBJ) $(INC)

$(TEST4801): $(TEST4801OBJ)
	g++ -o $(TEST4801) $(TEST4801OBJ) $(INC)

$(TESTINPUT): $(TESTINPUTOBJ)
	g++ -o $(TESTINPUT) $(TESTINPUTOBJ) $(INC)

$(TESTOUTPUT): $(TESTOUTPUTOBJ)
	g++ -o $(TESTOUTPUT) $(TESTOUTPUTOBJ) $(INC)

$(TESTCLOCK): $(TESTCLOCKOBJ)
	g++ -o $(TESTCLOCK) $(TESTCLOCKOBJ) $(INC)

clean:
	rm -rf $(TEST2716OBJ)
	rm -rf $(TEST4001OBJ)
	rm -rf $(TEST4008OBJ)
	rm -rf $(TEST4011OBJ)
	rm -rf $(TEST4013OBJ)
	rm -rf $(TEST4017OBJ)
	rm -rf $(TEST4030OBJ)
	rm -rf $(TEST4069OBJ)
	rm -rf $(TEST4071OBJ)
	rm -rf $(TEST4081OBJ)
	rm -rf $(TEST4094OBJ)
	rm -rf $(TEST4503OBJ)
	rm -rf $(TEST4512OBJ)
	rm -rf $(TEST4514OBJ)
	rm -rf $(TEST4801OBJ)
	rm -rf $(TESTINPUTOBJ)
	rm -rf $(TESTOUTPUTOBJ)
	rm -rf $(TESTCLOCKOBJ)

fclean: clean
	rm -rf $(TEST2716)
	rm -rf $(TEST4001)
	rm -rf $(TEST4008)
	rm -rf $(TEST4011)
	rm -rf $(TEST4013)
	rm -rf $(TEST4017)
	rm -rf $(TEST4030)
	rm -rf $(TEST4069)
	rm -rf $(TEST4071)
	rm -rf $(TEST4081)
	rm -rf $(TEST4094)
	rm -rf $(TEST4503)
	rm -rf $(TEST4512)
	rm -rf $(TEST4514)
	rm -rf $(TEST4801)
	rm -rf $(TESTINPUT)
	rm -rf $(TESTOUTPUT)
	rm -rf $(TESTCLOCK)

re: fclean all

.PHONY: make clean fclean re
