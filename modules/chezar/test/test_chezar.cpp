// Copyright 2020 Suchkov Makar

#include <gtest/gtest.h>

#include "include/chezar.h"

TEST(Suchkov_Makar_ChezarTest, Encrypt_Simple) {
    char a[] = "abcd";
    ASSERT_STRCASEEQ(Encrypt(a, 1), "bcde");
}

TEST(Suchkov_Makar_ChezarTest, Decrypt_Simple) {
    char a[] = "bcde";
    ASSERT_STRCASEEQ(Decrypt(a, 1), "abcd");
}

TEST(Suchkov_Makar_ChezarTest, Decrypt_Encrypt_Simple) {
    char a[] = "abcdefghijklmnopqrstuvwxyz";
    ASSERT_STRCASEEQ(Encrypt(a, 5),  Decrypt(a, 5));
}
