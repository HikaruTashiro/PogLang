# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mimi/Programming/PUC/5_Semestre/Comp/github/PogLang

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mimi/Programming/PUC/5_Semestre/Comp/github/PogLang

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/mimi/Programming/PUC/5_Semestre/Comp/github/PogLang/CMakeFiles /home/mimi/Programming/PUC/5_Semestre/Comp/github/PogLang//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/mimi/Programming/PUC/5_Semestre/Comp/github/PogLang/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named lexer

# Build rule for target.
lexer: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 lexer
.PHONY : lexer

# fast build rule for target.
lexer/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lexer.dir/build.make CMakeFiles/lexer.dir/build
.PHONY : lexer/fast

#=============================================================================
# Target rules for targets named token

# Build rule for target.
token: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 token
.PHONY : token

# fast build rule for target.
token/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/token.dir/build.make CMakeFiles/token.dir/build
.PHONY : token/fast

#=============================================================================
# Target rules for targets named utils

# Build rule for target.
utils: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 utils
.PHONY : utils

# fast build rule for target.
utils/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/utils.dir/build.make CMakeFiles/utils.dir/build
.PHONY : utils/fast

#=============================================================================
# Target rules for targets named parser

# Build rule for target.
parser: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 parser
.PHONY : parser

# fast build rule for target.
parser/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/parser.dir/build.make CMakeFiles/parser.dir/build
.PHONY : parser/fast

#=============================================================================
# Target rules for targets named PogLang

# Build rule for target.
PogLang: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 PogLang
.PHONY : PogLang

# fast build rule for target.
PogLang/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PogLang.dir/build.make CMakeFiles/PogLang.dir/build
.PHONY : PogLang/fast

pog.o: pog.cpp.o
.PHONY : pog.o

# target to build an object file
pog.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PogLang.dir/build.make CMakeFiles/PogLang.dir/pog.cpp.o
.PHONY : pog.cpp.o

pog.i: pog.cpp.i
.PHONY : pog.i

# target to preprocess a source file
pog.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PogLang.dir/build.make CMakeFiles/PogLang.dir/pog.cpp.i
.PHONY : pog.cpp.i

pog.s: pog.cpp.s
.PHONY : pog.s

# target to generate assembly for a file
pog.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PogLang.dir/build.make CMakeFiles/PogLang.dir/pog.cpp.s
.PHONY : pog.cpp.s

src/lexer.o: src/lexer.cpp.o
.PHONY : src/lexer.o

# target to build an object file
src/lexer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lexer.dir/build.make CMakeFiles/lexer.dir/src/lexer.cpp.o
.PHONY : src/lexer.cpp.o

src/lexer.i: src/lexer.cpp.i
.PHONY : src/lexer.i

# target to preprocess a source file
src/lexer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lexer.dir/build.make CMakeFiles/lexer.dir/src/lexer.cpp.i
.PHONY : src/lexer.cpp.i

src/lexer.s: src/lexer.cpp.s
.PHONY : src/lexer.s

# target to generate assembly for a file
src/lexer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lexer.dir/build.make CMakeFiles/lexer.dir/src/lexer.cpp.s
.PHONY : src/lexer.cpp.s

src/parser.o: src/parser.cpp.o
.PHONY : src/parser.o

# target to build an object file
src/parser.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/parser.dir/build.make CMakeFiles/parser.dir/src/parser.cpp.o
.PHONY : src/parser.cpp.o

src/parser.i: src/parser.cpp.i
.PHONY : src/parser.i

# target to preprocess a source file
src/parser.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/parser.dir/build.make CMakeFiles/parser.dir/src/parser.cpp.i
.PHONY : src/parser.cpp.i

src/parser.s: src/parser.cpp.s
.PHONY : src/parser.s

# target to generate assembly for a file
src/parser.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/parser.dir/build.make CMakeFiles/parser.dir/src/parser.cpp.s
.PHONY : src/parser.cpp.s

src/token.o: src/token.cpp.o
.PHONY : src/token.o

# target to build an object file
src/token.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/token.dir/build.make CMakeFiles/token.dir/src/token.cpp.o
.PHONY : src/token.cpp.o

src/token.i: src/token.cpp.i
.PHONY : src/token.i

# target to preprocess a source file
src/token.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/token.dir/build.make CMakeFiles/token.dir/src/token.cpp.i
.PHONY : src/token.cpp.i

src/token.s: src/token.cpp.s
.PHONY : src/token.s

# target to generate assembly for a file
src/token.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/token.dir/build.make CMakeFiles/token.dir/src/token.cpp.s
.PHONY : src/token.cpp.s

src/utils.o: src/utils.cpp.o
.PHONY : src/utils.o

# target to build an object file
src/utils.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/utils.dir/build.make CMakeFiles/utils.dir/src/utils.cpp.o
.PHONY : src/utils.cpp.o

src/utils.i: src/utils.cpp.i
.PHONY : src/utils.i

# target to preprocess a source file
src/utils.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/utils.dir/build.make CMakeFiles/utils.dir/src/utils.cpp.i
.PHONY : src/utils.cpp.i

src/utils.s: src/utils.cpp.s
.PHONY : src/utils.s

# target to generate assembly for a file
src/utils.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/utils.dir/build.make CMakeFiles/utils.dir/src/utils.cpp.s
.PHONY : src/utils.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... PogLang"
	@echo "... lexer"
	@echo "... parser"
	@echo "... token"
	@echo "... utils"
	@echo "... pog.o"
	@echo "... pog.i"
	@echo "... pog.s"
	@echo "... src/lexer.o"
	@echo "... src/lexer.i"
	@echo "... src/lexer.s"
	@echo "... src/parser.o"
	@echo "... src/parser.i"
	@echo "... src/parser.s"
	@echo "... src/token.o"
	@echo "... src/token.i"
	@echo "... src/token.s"
	@echo "... src/utils.o"
	@echo "... src/utils.i"
	@echo "... src/utils.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

