#include <stdio.h>
#include <sys/syslog.h>

#define RESULT_OK 0
// Generic return value for errors in this application
#define RESULT_ERR 1

void usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s writefile writestr\n", prog_name);
}

int main(int argc, char **argv) {
    char *writefile;
    char *writestr;
    FILE *dest;

    openlog("finder-app/writer", LOG_PID, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Wrong number of arguments. Expected 2 received %d", argc - 1);
        usage(argv[0]);
        return RESULT_ERR;
    }

    writefile = argv[1];
    writestr = argv[2];

    dest = fopen(writefile, "w");

    if (dest == NULL) {
        syslog(LOG_ERR, "Unable to open %s for writing", writefile);
        return RESULT_ERR;
    }

    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);
    if (fprintf(dest, "%s", writestr) < 0) {
        syslog(LOG_ERR, "Unable to write to %s", writefile);
        return RESULT_ERR;
    }

    if (fclose(dest) != 0) {
        syslog(LOG_ERR, "Unable to close %s", writefile);
        return RESULT_ERR;
    }

    return RESULT_OK;
}
