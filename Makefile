# info https://codeforces.com/blog/entry/15547
all :
	g++ -Wall -Wextra -O2 -pedantic -std=c++17 -Wshadow -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -o template template.cpp 
