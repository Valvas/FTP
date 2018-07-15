#include "functions.h"

/****************************************************************************************************/

void server(int port)
{
  int serverRuns = 1;

  int commandSocket = createSocket(port);

  if(commandSocket > -1)
  {
    printf("\nSuccess\n");
    printf("\nPress a key to exit...");

    getchar();
  }
}

/****************************************************************************************************/

int createSocket(int port)
{
  int newSocket;

  struct sockaddr_in serverAddress;

  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  serverAddress.sin_port = htons(port);

  if((newSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
  {
      printf("\nCould not create socket\n");
      printf("\nPress a key to exit...");

      getchar();

      exit(EXIT_FAILURE);
  }

  if(bind(newSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1)
  {
      printf("\nCould not bind socket\n");
      printf("\nPress a key to exit...");

      getchar();

      exit(EXIT_FAILURE);
  }

  if(listen(newSocket, 10) == -1)
  {
      printf("\nCould not set socket to listen\n");
      printf("\nPress a key to exit...");

      getchar();

      exit(EXIT_FAILURE);
  }

  return newSocket;
}

/****************************************************************************************************/
