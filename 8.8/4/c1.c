#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

// 方法1：memcpy拷贝 memcpy(void *destin, const void *source, size_t n);
void store_floats_method1(float a, float b, char* buffer) {
    memcpy(buffer, &a, sizeof(float));
    memcpy(buffer + sizeof(float), &b, sizeof(float));
}

void extract_floats_method1(const char* buffer, float* a, float* b) {
    memcpy(a, buffer, sizeof(float));
    memcpy(b, buffer + sizeof(float), sizeof(float));
}

// 方法2：union
union FloatBytes {
    float f;
    char bytes[sizeof(float)];
};

void store_floats_method2(float a, float b, char* buffer) {
    union FloatBytes u1, u2;
    u1.f = a;
    u2.f = b;
    for (int i = 0; i < sizeof(float); i++) {
        buffer[i] = u1.bytes[i];
        buffer[i + sizeof(float)] = u2.bytes[i];
    }
}

void extract_floats_method2(const char* buffer, float* a, float* b) {
    union FloatBytes u1, u2;
    for (int i = 0; i < sizeof(float); i++) {
        u1.bytes[i] = buffer[i];
        u2.bytes[i] = buffer[i + sizeof(float)];
    }
    *a = u1.f;
    *b = u2.f;
}

// 方法3：指针强制转换
void store_floats_method3(float a, float b, char* buffer) {
    *((float*)buffer) = a;
    *((float*)(buffer + sizeof(float))) = b;
}

void extract_floats_method3(const char* buffer, float* a, float* b) {
    *a = *((float*)buffer);
    *b = *((float*)(buffer + sizeof(float)));
}

// 比较浮点数是否近似相等（处理浮点误差）
int float_equals(float a, float b) {
    return fabs(a - b) < 1e-6; // 允许微小误差
}

int main() 
{
    float original_a = 3.1415926f;
    float original_b = 2.7182818f;
    char buffer[8];

    // 测试方法1
    store_floats_method1(original_a, original_b, buffer);
    float a1, b1;
    extract_floats_method1(buffer, &a1, &b1);
    printf("Method1: a=%.7f (diff=%e), b=%.7f (diff=%e)\n",
           a1, a1 - original_a, b1, b1 - original_b);

    // 测试方法2
    store_floats_method2(original_a, original_b, buffer);
    float a2, b2;
    extract_floats_method2(buffer, &a2, &b2);
    printf("Method2: a=%.7f (diff=%e), b=%.7f (diff=%e)\n",
           a2, a2 - original_a, b2, b2 - original_b);

    // 测试方法3
    store_floats_method3(original_a, original_b, buffer);
    float a3, b3;
    extract_floats_method3(buffer, &a3, &b3);
    printf("Method3: a=%.7f (diff=%e), b=%.7f (diff=%e)\n",
           a3, a3 - original_a, b3, b3 - original_b);

    // 验证是否完全一致
    if (float_equals(a1, original_a)) printf("Method1: a matches!\n");
    if (float_equals(b1, original_b)) printf("Method1: b matches!\n");
    if (float_equals(a2, original_a)) printf("Method2: a matches!\n");
    if (float_equals(b2, original_b)) printf("Method2: b matches!\n");
    if (float_equals(a3, original_a)) printf("Method3: a matches!\n");
    if (float_equals(b3, original_b)) printf("Method3: b matches!\n");

    return 0;
}