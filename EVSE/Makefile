CC = g++
LIBS = $(shell pkg-config opencv4 --libs) -pthread
CFLAGS = -g -Wall -D_REENTRANT $(shell pkg-config opencv4 --cflags)

SRCS = main.cpp ChargingportDetector.cpp ClientSocket.cpp GlobalVariables.cpp
OBJS = $(SRCS:.cpp=.o)
PROG = EVSEApp

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PROG) $(OBJS)

