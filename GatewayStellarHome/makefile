TARGET = demo

#CC = g++
CC = arm-linux-gnueabi-g++

INCLUDES = $(shell find ./ -name "*.h")

SRCS = $(shell find ./ -name "*.cpp")

OBJS = $(SRCS:%.cpp=%.o) 

LIBS = -lpthread -lpaho-embed-mqtt3c -L../lib/arm/

CCFLAGS = -g -Wall -O0 -std=c++11

all: $(TARGET)

info:
	echo $(OBJS)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@ $(LIBS) $(CCFLAGS)

%.o: %.cpp $(INCLUDES)
	$(CC) -c $< -o $@ $(CCFLAGS) 

clean:
	rm -rf $(OBJS) $(TARGET)

