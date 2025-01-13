CXX = g++
CXXFLAGS = -Wall -Wextra -Werror
SRCDIR = .
OBJDIR = obj
INCLUDES = $(shell find $(SRCDIR) -type d)
INCLUDE_FLAGS = $(addprefix -I, $(INCLUDES))
SOURCES = $(shell find $(SRCDIR) -name '*.cpp')
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)
EXEC = jeu

.PHONY: all run clean

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $^ -o $@

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

run: $(EXEC)
	./$(EXEC)

clean:
	rm -rf $(OBJDIR) $(EXEC) *~ *.core
