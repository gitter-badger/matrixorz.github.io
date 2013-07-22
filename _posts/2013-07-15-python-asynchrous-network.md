---
layout: post
title: "python asynchrous network"
description: ""
category: 
tags: []
---
{% include JB/setup %}
--------------------------------
select,poll,epoll test in python
--------------------------------

***select test*** selecttest.py

    import select
    import socket
    import Queue

    #create a socket
    server=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    server.setblocking(False)
    #set option reused
    server.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)

    server_address=('localhost',10001)
    server.bind(server_address)

    server.listen(10)

    #sockets from which we except to read
    inputs=[server]

    #sockets from which we expect to write
    outputs=[]

    #Outgoing message queues (socket:Queue)
    message_queues={}

    #A optional parameter for select is TIMEOUT
    timeout=20

    while inputs:
        print "waiting for next event"
        #first parameter--read list,second parameter--write list,third parameter--error list
        readable,writable,exceptional=select.select(inputs,outputs,inputs,timeout)

        #when timeout reached,select return three empty list
        if not (readable or writable or exceptional):
            print "Time out!"
            break;
        for s in readable:
            if s is server:
                #A "readable" socket is ready to accept a connection
                connection,client_address=s.accept()
                print "  connection from",client_address
                connection.setblocking(0)
                inputs.append(connection)
                message_queues[connection]=Queue.Queue()
            else:
                data=s.recv(1024)
                if data:
                    print "received ",data, "from ",s.getpeername()
                    message_queues[s].put(data)
                    #Add output  channel for response
                    if s not in outputs:
                        outputs.append(s)
                else:
                    #Interpret empty result as closed connection
                    print " closing", client_address
                    if s in outputs:
                        outputs.remove(s)
                    inputs.remove(s)
                    s.close()
                    #remove message queue
                    del message_queues[s]
        for s in writable:
            try:
                next_msg=message_queues[s].get_nowait()
            except Queue.Empty:
                print " ",s.getpeername," queue empty"
                outputs.remove(s)
            else:
                print "sending ",next_msg," to",s.getpeername()
                s.send(next_msg)
        for s in exceptional:
            print " exception condition on ",s.getpeername()
            #stop listening for input on the connection
            inputs.remove(s)
            if s in outputs:
                outputs.remove(s)
            s.close()
            #Remove message queue


***polltest*** polltest.py
    
    import socket
    import select
    import Queue
    
    server=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    server.setblocking(False)
    server.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
    server_address=("localhost",10001)
    
    print "Starting up on %s port %s" % server_address
    server.bind(server_address)
    server.listen(5)
    message_queues={}
    #The timeout value is represente in milliseconds,instead of seconds
    timeout=100
    #Create a limit for the next
    READ_ONLY=(select.POLLIN | select.POLLPRI | select.POLLHUP | select.POLLERR)
    READ_WRITE=(READ_ONLY|select.POLLOUT)
    
    #set up the poller
    poller=select.poll()
    poller.register(server,READ_ONLY)
    #map file descriptors to socket objects
    fd_to_socket={server.fileno():server,}
    while True:
        print "Waiting for the next event"
        events=poller.poll(timeout)
        print "*"*20
        print len(events)
        print events
        print "*"*20
        for fd,flag in events:
            s=fd_to_socket[fd]
            if flag & (select.POLLIN|select.POLLPRI):
                if s is server:
                    #A readable socket is ready to accept a connection
                    connection,client_address=s.accept()
                    print "Connection ",client_address
                    connection.setblocking(False)
    
                    fd_to_socket[connection.fileno()]=connection
                    poller.register(connection,READ_ONLY)
    
                    #Give the connection a queue to send data
                    message_queues[connection]=Queue.Queue
                else:
                    data=s.recv(1024)
                    if data:
                        # A readable client socket has data
                        print " received %s from %s " % (data,s.getpeername())
                        message_queues[s].put(data)
                        poller.modify(s,READ_WRITE)
                    else:
                        #Close the connection
                        print " closing ",s.getpeername()
                        #Stop listening for input on the connection
                        poller.unregister(s)
                        s.close()
                        del message_queues[s]
            elif flag & select.POLLHUP:
                #A client that "Hang up",to be closed.
                print "closing ",s.getpeername,"(HUP)"
                poller.unregister(s)
                s.close()
            elif flag & select.POLLOUT:
                #SOCKET is ready to send DATA,if there is any to send
                try:
                    next_msg=message_queues[s].get_nowait()
                except Queue.Empty:
                    #No messages waiting so stop checking
                    print s.getpeername," queue empty"
                    poller.modify(s,READ_ONLY)
                else:
                    print " sending %s to %s" %(next_msg,s.getpeername())
                    s.send(next_msg)
            elif flag & select.POLLERR:
                #Any events with POLLER cause the server to close the sockets
                print " exception on",s.getpeername()
                poller.unregister(s)
                s.close()
                del message_queues[s]
                
***epoll test*** epolltest.py

    import socket,logging
    import select,errno
    
    logger=logging.getLogger("network-server")
    
    def InitLog():
        logger.setLevel(logging.DEBUG)
    
        fh=logging.FileHandler("network-server.log")
        fh.setLevel(logging.DEBUG)
        ch=logging.StreamHandler()
        ch.setLevel(logging.DEBUG)
    
        formatter=logging.Formatter("%(asctime)s - %(name)s - %(levelname)s -%(message)s")
        ch.setFormatter(formatter)
        fh.setFormatter(formatter)
    
        logger.addHandler(fh)
        logger.addHandler(ch)
    
    if __name__=="__main__":
        InitLog()
    
        try:
            listen_fd=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        except socket.error,msg:
            logger.error("create a socket failed")
    
        try:
            listen_fd.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
        except socket.error,msg:
            logger.error("setsocketopt error")
    
        try:
            listen_fd.bind(('',10001))
        except socket.error,msg:
            logger.error("listen file id bind ip error")
    
        try:
            listen_fd.listen(10)
        except socket.error,msg:
            logger.error(msg)
        try:
            epoll_fd=select.epoll()
            epoll_fd.register(listen_fd.fileno(),select.EPOLLIN)
        except select.error,msg:
            logger.error(msg)
        
        connections={}
        addresses={}
        datalist={}
        while True:
            epoll_list = epoll_fd.poll()
            for fd,events in epoll_list:
                if fd==listen_fd.fileno():
                    conn,addr=listen_fd.accept()
                    logger.debug("accept connction from  %s,%d,fd = %d" %(addr[0],addr[1],conn.fileno()))
                    conn.setblocking(0)
                    epoll_fd.register(conn.fileno(),select.EPOLLIN|select.EPOLLET)
                    connections[conn.fileno()]=conn 
                    addresses[conn.fileno()]=addr
                elif select.EPOLLIN  & events:
                    datas=''
                    while True:
                        try:
                            data=connections[fd].recv(10)
                            if not data and not datas:
                                epoll_fd.unregister(fd)
                                connections[fd].close()
                                logger.debug("%s,%d closed" % (addresses[fd][0],addresses[fd][1]))
                                
                                break
                            else:
                                datas+=data 
                        except socket.error,msg:
                            if msg.errno==errno.EAGAIN:
                                logger.debug("%s receive %s" % (fd,datas))
                                datalist[fd]=datas
                                epoll_fd.modify(fd,select.EPOLLET|select.EPOLLOUT)
                                break
                            else:
                                epoll_fd.unregister(fd)
                                connections[fd].close()
                                logger.error(msg)
                                break
                elif select.EPOLLHUP & events:
                    epoll_fd.unregister(fd)
                    connections[fd].close()
                    logger.debug("%s ,%d closed" % (addresses[fd][0],addresses[fd][1]))
                elif select.EPOLLOUT & events:
                    sendLen=0
                    while True:
                        sendLen += connections[fd].send(datalist[fd][sendLen:])
                        if sendLen == len(datalist[fd]):
                             break
                    epoll_fd.modify(fd,select.EPOLLIN|select.EPOLLET)
                else:
                    continue
    

***common client***  commontest.py

    import socket
    messages = ["This is the message",
             "It will be send",
             "in parts"]
    
    print "Connect to the server"
    
    server_address=("localhost",10001)
    
    #Create a TCP/IP sock
    socks=[]
    for i in range(10):
         socks.append(socket.socket(socket.AF_INET,socket.SOCK_STREAM))
    
    for s in socks:
        s.connect(server_address)
    
    counter=0
    for message in messages:
        for s in socks:
            counter+=1
            print " %s sending %s "%(s.getpeername(),message+" version "+str(counter))
            s.send(message+" version "+str(counter))
        for s in socks:
            data=s.recv(1024)
            print " %s received %s " % (s.getpeername(),data)
            if not data:
                print "closing socket",s.getpeername()
                s.close()
    
 针对epoll的使用有一篇很好的博客：scotdoyle.com/python-epoll-howto.html
 
 针对asyncore的介绍和使用有很好的一篇博客：blog.csdn.net/livefun/article/details/8721772
    
    
        
     