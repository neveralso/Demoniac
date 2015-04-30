//
// Created by Neveralso on 15/3/23.
//

#ifndef _DEMONIAC_EVENTHANDLER_H_
#define _DEMONIAC_EVENTHANDLER_H_

namespace dc{

class EventHandler {
public:
    virtual void _ReadCallback(int fd, int data) = 0;
    virtual void _WriteCallback(int fd, int data) = 0;
    virtual void _CloseCallback(int fd, int data) = 0;
};

}


#endif //_DEMONIAC_EVENTHANDLER_H_