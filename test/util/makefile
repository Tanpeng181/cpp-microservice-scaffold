main: main.cc ../../source/util.cc  ../../source/log.cc
	g++ -std=c++17 $^ -o $@ -ljsoncpp -lfmt -lspdlog -lpthread
clean:
	rm -rf main