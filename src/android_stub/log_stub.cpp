#include <android/log.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
extern "C" {

int __android_log_write(int prio, const char* tag, const char* text)
{
  int fdKmsg = -1;
  fdKmsg = open("/dev/kmsg", O_WRONLY);
  if (fdKmsg != -1)
  {
    //dprintf(fdKmsg, "-- Hello World --\n");
    write(fdKmsg, text, strlen(text) + 1);
    close(fdKmsg);
  }
  else
  {
    printf("Unable to get file descriptor\n");
  }

  return 0;
}

int __android_log_print(int prio, const char* tag, const char* fmt, ...)
{
   // For simplicity, forwarding the arguments to printf
   va_list args;
   va_start(args, fmt);
   vprintf(fmt, args);
   va_end(args);

   return 0; // Assuming success
}

int __android_log_vprint(int prio, const char* tag, const char* fmt, va_list ap)
{
   // For simplicity, forwarding the arguments to vprintf
   vprintf(fmt, ap);

   return 0; // Assuming success
}

}

