#include <stdio.h>
#include <cJSON.h>
#include "registry.h"
#include "registry/path_process.h"
#include "env.h"

char *register_path = REGISTRY_PATH;

int registry_init()
{
    char * register_path_now = getenv_("REGISTRY_PATH");
    if (register_path_now != NULL)
    {
       register_path = register_path_now;
    }
    else
    {
       printf("[REGISTRY]:REGISTRY_PATH is not set, use default path %s\n", register_path);
       setenv_("REGISTRY_PATH", register_path, 1);
       printf("[REGISTRY]:please set PATH in /etc/profile\n");
    }
    check_path(register_path);
    return 0;
}

char *get_registry_path(void)
{
    return register_path;
}
