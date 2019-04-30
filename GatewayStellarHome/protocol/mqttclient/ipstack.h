/*******************************************************************************
 * Copyright (c) 2014, 2017 IBM Corp.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution.
 *
 * The Eclipse Public License is available at
 *    http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 *    Ian Craggs - initial API and implementation and/or initial documentation
 *    Ian Craggs - ensure read returns if no bytes read
 *******************************************************************************/
#ifndef IPSTACK
#define IPSTACK

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/param.h>
#include <sys/time.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include <stdlib.h>
#include <string.h>
#include <signal.h>

class IPStack
{
private:
    int mysock;

public:
  IPStack();
  int connect(const char* hostname, int port);
  // return -1 on error, or the number of bytes read
  // which could be 0 on a read timeout
  int read(unsigned char* buffer, int len, int timeout_ms);
  int write(unsigned char* buffer, int len, int timeout);
  int is_connected();
  int disconnect();
};


class Countdown
{
private:
    struct timeval end_time;

public:
  Countdown();
  Countdown(int ms);
  bool expired();
  void countdown_ms(int ms);
  void countdown(int seconds);
  int left_ms();
};

#endif // IPSTACK

