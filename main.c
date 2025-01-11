#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

// 函数：从文件中读取 JSON 字符串
char *read_json_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *json_string = malloc(length + 1);
    if (!json_string) {
        perror("Unable to allocate memory");
        fclose(file);
        return NULL;
    }

    fread(json_string, 1, length, file);
    json_string[length] = '\0'; // Null-terminate the string
    fclose(file);
    
    return json_string;
}

int main() {
    const char *filename = "../main.json"; // JSON 文件名
    char *json_string = read_json_from_file(filename);
    
    if (json_string == NULL) {
        return EXIT_FAILURE;
    }

    // 解析 JSON 字符串
    cJSON *json = cJSON_Parse(json_string);
    if (json == NULL) {
        fprintf(stderr, "Error parsing JSON: %s\n", cJSON_GetErrorPtr());
        free(json_string);
        return EXIT_FAILURE;
    }

    // 格式化输出 JSON
    char *formatted_json = cJSON_Print(json);
    if (formatted_json) {
        printf("Formatted JSON:\n%s\n", formatted_json);
        free(formatted_json);
    }

    // 清理
    cJSON_Delete(json);
    free(json_string);
    
    return EXIT_SUCCESS;
}