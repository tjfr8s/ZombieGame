
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
#LDFLAGS = 

SRCEXT = cpp
INCEXT = hpp

SRCS = $(shell find . -maxdepth 1 -type f -name \*.$(SRCEXT))
OBJS = $(patsubst ./%, ./%, $(SRCS:.$(SRCEXT)=.o))
INCS = $(shell find . -maxdepth 1 -type f -name \*.$(INCEXT))

ZombieGame: $(OBJS)
	$(CXX) $^ -o ZombieGame

ZombieGameTest: $(OBJS) 
	$(CXX) $^ -o ZombieGameTest

./%.o: ./%.$(SRCEXT) ./%.$(INCEXT)                    
	@echo " $(CXX) $(CXXFLAGS) -c -o $@ $<"; $(CXX) $(CXXFLAGS) -c -o $@ $<           

SpaceTest: Space.o General.o Attic.o Player.o ./test/SpaceTest.o Kitchen.o\
	Bedroom.o Menu.o IntegerValidation.o
	$(CXX) $^ -o SpaceTest

./test/SpaceTest.o: ./test/SpaceTest.cpp
	$(CXX) $(CXXFLAGS) -c -o ./test/SpaceTest.o ./test/SpaceTest.cpp

.PHONY: clean
clean:
	rm *.o ZombieGame SpaceTest PlayerTest ZombieGameTest

	

