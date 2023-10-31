exe e:
	g++ -c *.cpp -I/usr/local/SFML/include
	g++ *.o -o sfml-app -L/usr/local/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lGL
	rm *.o
asan a:
	g++ -c *.cpp -I/usr/local/SFML/include
	g++ *.o -o sfml-app -g -fsanitize=address -L/usr/local/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lGL
	rm *.o
run r:
	export LD_LIBRARY_PATH=/usr/local/SFML/lib && ./sfml-app

quick q:
	g++ -c *.cpp -I/usr/local/SFML/include
	g++ *.o -o sfml-app -L/usr/local/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lGL
	rm *.o
	export LD_LIBRARY_PATH=/usr/local/SFML/lib && ./sfml-app

clean c:
	rm sfml-app
