#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <sys/utsname.h>

/**
 * Print very simple information about User
 */
void printUser() {
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
}

/**
 * Print technical information about system.
 */
void printSystem() {
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
}

/**
 * Print message for not supported option.
 */
void printUnrecognize() {
  fprintf(stderr, "ERR: nie rozpoznana opcja\n");
}

int main (int argc, char * argv[]) {
  /* availability options */
  char * opts = "su";
  /* processed option */
  int c;
  /* exit application status */
  int status = 0;

  /* check if define more than one option */
  if (argc < 2) {
    printf("ERR: nie podano żadnej opcji\n");
  } else {
    /* iteration by each of option */
    while ((c = getopt(argc, argv, opts)) != -1) {
      switch (c) {
        /* for 's' print information about system */
        case 's': printSystem(); break;
        /* for 'u' print user profile */
        case 'u': printUser(); break;
        /* for unrecognized option */
        case '?':
        default:
          printUnrecognize();
          status = 1;
      }
    }
  }

  return status;
}

