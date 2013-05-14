#Makefile

OBJS = Robot.o RGB.o main.o
LDLIBS = 
EXEC = robot
CFLAGS = -ggdb -Wall
HEADERS = 

robot: $(OBJS)
	g++ -std=c++11 -o $(EXEC) $(OBJS) $(HEADERS) $(LDLIBS)

#foo.o: bar.o baz.o

%.o: %.cpp
	g++ -std=c++11 -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
