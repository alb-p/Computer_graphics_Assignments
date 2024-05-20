CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXrandr -lXi
A05: A05.cpp
	g++ $(CFLAGS) -o A05 -I headers -I models -I shaders -I textures A05.cpp $(LDFLAGS)

.PHONY: test clean

test: A05
	./A05
clean:
	rm -f A05

