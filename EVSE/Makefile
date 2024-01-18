CC = g++
LIBS = $(shell pkg-config opencv4 --libs)
CFLAGS = -g -Wall $(shell pkg-config opencv4 --cflags)

SRCS = main.cpp ChargingportDetector.cpp
OBJS = $(SRCS:.cpp=.o)
PROG = EVSEApp

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PROG) $(OBJS)

