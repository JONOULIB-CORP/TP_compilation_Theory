#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

void matchIfThenFromFile(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(1);
    }

    regex_t regex;
    int reti;
    char line[256];

    // Compile the regular expression
    reti = regcomp(&regex, "^if.*n$", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        fclose(file);
        exit(1);
    }

    // Iterate through each line in the file
    while (fgets(line, sizeof(line), file)) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Execute the regular expression
        reti = regexec(&regex, line, 0, NULL, 0);
        if (!reti) {
            printf("Match: %s\n", line);
        } else if (reti == REG_NOMATCH) {
            printf("No match: %s\n", line);
        } else {
            char error_message[100];
            regerror(reti, &regex, error_message, sizeof(error_message));
            fprintf(stderr, "Regex match failed: %s\n", error_message);
        }
    }

    // Free compiled regex
    regfree(&regex);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    const char* filename = argv[1];
    matchIfThenFromFile(filename);
    return 0;
}
