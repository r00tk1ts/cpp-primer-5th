#include <iostream>
#include <string>
#include <memory>

struct connection {
    std::string ip;
    int port;
    connection(std::string _ip, int _port) : ip(_ip), port(_port) { }
};

struct destination {
    std::string ip;
    int port;
    destination(std::string _ip, int _port) : ip(_ip), port(_port) { }
};

connection connect(destination* pDest)
{
    std::shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
    std::cout << "creating connection(" << pConn.use_count() << ")" << std::endl;
    return *pConn;
}

void disconnect(connection conn)
{
    std::cout << "connection close(" << conn.ip << ":" << conn.port << ")" << std::endl;
}

void end_connection(connection *pConn)
{
    disconnect(*pConn);
}

void f(destination &d)
{
    connection conn = connect(&d);
    std::shared_ptr<connection> p(&conn, end_connection);
    std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
}

int main()
{
	destination dest("127.0.0.1", 8080);
    f(dest);
	return 0;
}