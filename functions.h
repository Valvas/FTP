#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef FTP_FUNCTIONS_H
#define FTP_FUNCTIONS_H

void server(int);
int createSocket(int);

#endif
