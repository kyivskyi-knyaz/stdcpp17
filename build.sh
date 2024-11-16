#g++ -O3 -Wall -g -c -std=c++17 -fsanitize=signed-integer-overflow main.cpp -o main.o
#gcc -O3 -Wall -g -c hash.h -o hash.o
gcc -o myprog main.cpp -lstdc++ 

