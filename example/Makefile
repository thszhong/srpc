all:
	g++ -c server.cpp -I../src/
	g++ -c client.cpp -I../src/
	g++ -c echo.pb.cc -I../src/ 
	g++ -o server server.o echo.pb.o -lpthread -lprotobuf -lsrpc -lboost_system -L/usr/local/lib/ -L../src/
	g++ -o client client.o echo.pb.o -lpthread -lprotobuf -lsrpc -lboost_system -L/usr/local/lib/ -L../src/
