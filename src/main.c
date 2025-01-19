#include "AppState.h"
#include "defs.h"

int main(int argc, char **argv)
{
    AppState *app_state = AppState_new();
    if (app_state) {
        AppState_run(app_state);
        AppState_free(app_state);
    }
    return 0;
} /* main */
