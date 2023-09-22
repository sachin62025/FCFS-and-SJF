EXECUTABLE = scheduling
SOURCES = main.c fcfs.c sjf.c
OBJECTS = $(SOURCES:.c=.o)

# Default target
all: $(EXECUTABLE)

# Compile and link
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)
