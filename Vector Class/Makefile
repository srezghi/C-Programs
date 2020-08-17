# See example: https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# the build target executable:
TARGET1 = Test
TARGET2 = Exp

all: $(TARGET1) $(TARGET2)

$(TARGET1): $(TARGET1).cpp
	$(CC) $(CFLAGS) -o $(TARGET1) $(TARGET1).cpp

$(TARGET2): $(TARGET2).cpp
	$(CC) $(CFLAGS) -o $(TARGET2) $(TARGET2).cpp

clean:
	$(RM) $(TARGET1) $(TARGET2)
 
