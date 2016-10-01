#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<windows.h>
void sig_handler(int signo)
{
  if (signo == SIGINT)
    printf("received SIGINT\n");
}

int main(void)
{
  if (signal(SIGINT, sig_handler) == SIG_ERR)
  printf("\ncan't catch SIGINT\n");
  // A long long wait so that we can easily issue a signal to this process
  while(1)
  {
      printf("123\n");
      Sleep(1000);
  }
  return 0;
}

