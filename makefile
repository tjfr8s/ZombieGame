
CXX = g++
CXXFLAGS = -std=c++0x
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

SpaceTest: Space.o Player.o SpaceTest.o General.o Menu.o IntegerValidation.o \
	Kitchen.o Bedroom.o Attic.o
	$(CXX) $^ -o SpaceTest

ZombieGameTest: Space.o Player.o ZombieGameTest.o General.o Menu.o IntegerValidation.o \
	Kitchen.o Bedroom.o Attic.o ZombieGame.o
	$(CXX) $^ -o ZombieGameTest





$(OBJS): $(SRCS) $(INCS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.$(SRCEXT))




.PHONY: clean
clean:
	rm *.o ZombieGame SpaceTest PlayerTest

	

