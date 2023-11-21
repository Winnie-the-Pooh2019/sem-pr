#ifndef SEM_PR_FILEREADER_H
#define SEM_PR_FILEREADER_H

#include "string"

class IFileReader {
    virtual std::string readText() = 0;

    virtual char* read() = 0;
};

#endif //SEM_PR_FILEREADER_H
