#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    // Open syslog with LOG_USER facility
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    // Ensure correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Failed: Two arguments required\n");
        syslog(LOG_ERR, "Failed: Two arguments required");
        closelog();
        return 1;
    }

    // Variables for file path and string to write
    const char *writefile = argv[1];
    const char *writestr = argv[2];

    // Open the file for writing (creates if doesn't exist, truncates if exists)
    FILE* file = fopen(writefile, "w");
    //int fd = open(writefile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (file == NULL) {
        syslog(LOG_ERR, "Error: Could not open file '%s' for writing: %s", writefile, strerror(errno));
        closelog();
        return 1;
    }

    fprintf(file, "%s", writestr);
    // Log writing action
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    // Write the string to the file
/*  ssize_t bytes_written = write(fd, writestr, strlen(writestr));
    if (bytes_written == -1) {
        syslog(LOG_ERR, "Error: Could not write to file '%s': %s", writefile, strerror(errno));
        close(fd);
        closelog();
        return 1;
    }*/

    // Close the file and syslog
    fclose(file);
    closelog();
    return 0;
}
