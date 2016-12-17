all:
	g++ -arch x86_64 -framework OpenGL -w -I/usr/local/include -L/usr/local/lib -L/usr/local/Cellar -L/opt/local/lib -o tempest *.cxx -lglfw3.3.2 -lGLEW.2.0.0 -lSOIL