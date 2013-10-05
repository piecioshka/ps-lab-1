#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <sys/utsname.h>

int main (int argc, char * argv[]) {
  char * l = getlogin();
  if (l) {
    printf("getlogin: %s\n", l);
  }
  int u = getuid();
  if (u) {
    printf("getuid: %i\n", u);
  }

  struct passwd * p = getpwent();
  if (p) {
    printf("passwd->pw_uid: %i\n", p->pw_uid);
    printf("passwd->pw_gid: %i\n", p->pw_gid);
    printf("passwd->pw_expire: %lu\n", p->pw_expire);
  }

  struct utsname unameData;
  if (uname(&unameData) != -1) {
    printf("uname->sysname: %s\n", unameData.sysname);
    printf("uname->nodename: %s\n", unameData.nodename);
    printf("uname->release: %s\n", unameData.release);
    printf("uname->version: %s\n", unameData.version);
    printf("uname->machine: %s\n", unameData.machine);
  }

  char name[256];
  if (gethostname(name, sizeof name) != -1) {
    printf("gethostname: %s\n", name);
  }
  return 1;
}

