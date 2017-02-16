##
## Makefile for  in /home/brout_m/rendu/cpp/cpp_nanotekspice/units
##
## Made by brout_m
## Login   <marc.brout@epitech.eu>
##
## Started on  Wed Feb  8 10:39:36 2017 brout_m
## Last update Wed Feb 15 14:24:59 2017 brout_m
##

TEST4001=	tests-4001
TEST4008=	tests-4008
TEST4011=	tests-4011
TEST4013=	tests-4013
TEST4017=	tests-4017
TEST4030=	tests-4030
TEST4069=	tests-4069
TEST4071=	tests-4071
TEST4081=	tests-4081
TEST4514=	tests-4514
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

TEST4001OBJ=	$(TEST4001SRC:.cpp=.o)
TEST4008OBJ=	$(TEST4008SRC:.cpp=.o)
TEST4011OBJ=	$(TEST4011SRC:.cpp=.o)
TEST4013OBJ=	$(TEST4013SRC:.cpp=.o)
TEST4017OBJ=	$(TEST4017SRC:.cpp=.o)
TEST4030OBJ=	$(TEST4030SRC:.cpp=.o)
TEST4069OBJ=	$(TEST4069SRC:.cpp=.o)
TEST4071OBJ=	$(TEST4071SRC:.cpp=.o)
TEST4081OBJ=	$(TEST4081SRC:.cpp=.o)
TEST4514OBJ=	$(TEST4514SRC:.cpp=.o)
TESTINPUTOBJ=	$(TESTINPUTSRC:.cpp=.o)
TESTOUTPUTOBJ=	$(TESTOUTPUTSRC:.cpp=.o)
TESTCLOCKOBJ=	$(TESTCLOCKSRC:.cpp=.o)

INC=		-I../include

CXX= 		g++ $(INC) -std=c++14

CFLAGS=		$(INC)

all: $(TEST4001) $(TEST4008) $(TEST4011) $(TEST4013) $(TEST4017) $(TEST4030) $(TEST4069) $(TEST4071) $(TEST4081) $(TEST4514) $(TESTINPUT) $(TESTOUTPUT) $(TESTCLOCK)

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

$(TEST4514): $(TEST4514OBJ)
	g++ -o $(TEST4514) $(TEST4514OBJ) $(INC)

$(TESTINPUT): $(TESTINPUTOBJ)
	g++ -o $(TESTINPUT) $(TESTINPUTOBJ) $(INC)

$(TESTOUTPUT): $(TESTOUTPUTOBJ)
	g++ -o $(TESTOUTPUT) $(TESTOUTPUTOBJ) $(INC)

$(TESTCLOCK): $(TESTCLOCKOBJ)
	g++ -o $(TESTCLOCK) $(TESTCLOCKOBJ) $(INC)

clean:
	rm -rf $(TEST4001OBJ)
	rm -rf $(TEST4008OBJ)
	rm -rf $(TEST4011OBJ)
	rm -rf $(TEST4013OBJ)
	rm -rf $(TEST4017OBJ)
	rm -rf $(TEST4030OBJ)
	rm -rf $(TEST4069OBJ)
	rm -rf $(TEST4071OBJ)
	rm -rf $(TEST4081OBJ)
	rm -rf $(TEST4514OBJ)
	rm -rf $(TESTINPUTOBJ)
	rm -rf $(TESTOUTPUTOBJ)
	rm -rf $(TESTCLOCKOBJ)

fclean: clean
	rm -rf $(TEST4001)
	rm -rf $(TEST4008)
	rm -rf $(TEST4011)
	rm -rf $(TEST4013)
	rm -rf $(TEST4017)
	rm -rf $(TEST4030)
	rm -rf $(TEST4069)
	rm -rf $(TEST4071)
	rm -rf $(TEST4081)
	rm -rf $(TEST4514)
	rm -rf $(TESTINPUT)
	rm -rf $(TESTOUTPUT)
	rm -rf $(TESTCLOCK)

re: fclean all

.PHONY: make clean fclean re
