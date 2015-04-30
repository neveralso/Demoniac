//
// Created by Neveralso on 15/3/19.
//

#ifndef _DEMONIAC_TCPSERVER_H_
#define _DEMONIAC_TCPSERVER_H_

#include <functional>
#include <map>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "Demoniac/util/Noncopyable.h"
#include "Demoniac/util/EventHandler.h"
#include "Demoniac/util/Error.h"
#include "Demoniac/Log.h"

namespace dc {

class IOLoop;

class TCPConnection;

class TCPHandler;

class TCPServer : Noncopyable, public EventHandler {
private:

    const int MAX_PENDING_CONNECTIONS_NUM = 200;

    std::map<int, std::function<void *()>> route_map_;

    std::map<int, TCPConnection *> connection_poll_;
public:
    TCPServer();

    template<typename T>
    void AddHandler(const sockaddr &sock_addr) {

        if (!std::is_base_of<TCPHandler, T>::value) {
            LOG_ERROR << "Wrong handler type" << typeid(T).name();
            throw HandlerTypeError(typeid(T).name());
        }

        auto f = [=]() {
            return (void *) (new T);
        };

        _AddHandler(sock_addr, f);
    }

    virtual void _WriteCallback(int fd, int data);

    virtual void _CloseCallback(int fd, int data);

    void _AddHandler(const sockaddr &sock_addr, std::function<void *()>);

    void _ReadCallback(int fd, int data);

    void CreateConnection(int fd, int data);

    void RemoveConnection(int fd);

};

}

#endif //_DEMONIAC_TCPSERVER_H_