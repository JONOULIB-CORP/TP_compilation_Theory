#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool matchABCStar(const char* str) {
    enum State { START, ACCEPT } state = START;

    for (const char* p = str; *p != '\0'; ++p) {
        switch (state) {
            case START:
                if (*p == 'a' || *p == 'b' || *p == 'c') state = START;
                else state = ACCEPT;
                break;
            case ACCEPT:
                return false;
        }
    }
    return true;
}

void matchABCStarFromFile(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        if (matchABCStar(line)) {
            printf("Match: %s\n", line);
        } else {
            printf("No match: %s\n", line);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    const char* filename = argv[1];
    matchABCStarFromFile(filename);
    return 0;
}
