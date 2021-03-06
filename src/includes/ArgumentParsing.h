#ifndef ARGUMENT_PARSING
#define ARGUMENT_PARSING


#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <argp.h>

#include "slog.h"
#include "customAssert.h"
#include "signature.h"
#include "utils.h"




enum signatureType {
	BINARY, XML
};


enum formatTypes {
	BEAUTIFUL, CSV
};

struct arguments {
    int verbose;
    char *listFile;
    char *sessionFile;
    char *incrementalFile;
    enum lookup_mode mode;
    enum signatureType sigType;
    enum formatTypes outputFormat;
	double thD, thDc, thXh, thDi, thIt, minScore;
    char **filePaths;
    unsigned int numberOfPaths;
    int useOpenMp;
};

// https://stackoverflow.com/questions/6669842/how-to-best-achieve-string-
// to-number-mapping-in-a-c-program
struct entry {
    char *str;
    int n;
};

static struct entry dict[] = {
    {"binary", BINARY},
    {"xml", XML},
    {"fast", MODE_FAST},
    {"full", MODE_FULL},
    {"csv", CSV},
    {"beautiful", BEAUTIFUL},
};


int numberForKey(char *key);

struct arguments parseArguments(int, char**);

#endif
