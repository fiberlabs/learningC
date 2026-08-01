#include <stdio.h>

struct Request {
    int id;
    int is_valid;
};

void log_request(struct Request *idPara) {
    printf("Logging Request ID: %d\n", idPara->id);
}

void auth_request(struct Request *idPara) {
    if (idPara->id <= 0) {
        idPara->is_valid = 0;
    }
}

void exec_request(struct Request *idPara) {
    if (idPara->is_valid == 1) {
        printf("Executing Request: %d\n", idPara->id);
    } else {
        printf("Request Invalid- Execution Skipped\n");
    }
}

int main() {
    void (*pipeline[])(struct Request *) = {
        log_request,
        auth_request,
        exec_request,
        NULL
    };

    struct Request req1;
    req1.id = 10;
    req1.is_valid = 1; //assume its valid

    for (int i = 0; pipeline[i] != NULL; i++) {
        pipeline[i](&req1);
    }

    return 0;
}

