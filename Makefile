# flags info https://codeforces.com/blog/entry/15547
CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -pedantic -std=c++17 -Wshadow -Wformat=2 -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wnull-dereference -Wdouble-promotion -Wno-unused-result 
CXXDEBUGFLAGS = -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover

# usage: `make a` produces `a` from `a.cpp` 
# if one directory deep, use `make -f ../Makefile a`
% : %.cpp
	$(CXX) $(CXXFLAGS) $(CXXDEBUGFLAGS) -o $@ $< 
