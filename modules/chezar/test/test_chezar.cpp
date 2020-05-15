// Copyright 2017 Korniakov Kirill

#include <gtest/gtest.h>

#include <string>

#include "include/chezar.h"


TEST_F(ChezarTest, Encrypt_Simple) {
    // Arrange
    string a = "abcd";

    // Act
    string b = Encrypt(a, 1);

    // Assert
    EXPECT_EQ(b, "bcde");
}

TEST_F(ChezarTest, Decrypt_Simple) {
    // Arrange
    string a = "bcde";

    // Act
    string b = Decrypt(a, 1);

    // Assert
    EXPECT_EQ(b, "abcd");
}
