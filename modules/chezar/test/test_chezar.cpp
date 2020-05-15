// Copyright 2020 Suchkov Makar

#include <gtest/gtest.h>

#include <string>

#include "include/chezar.h"


TEST(Suchkov_Makar_ChezarTest, Encrypt_Simple) {
    // Arrange
    string a = "abcd";

    // Act
    string b = Encrypt(a, 1);

    // Assert
    EXPECT_EQ(b, "bcde");
}

TEST((Suchkov_Makar_ChezarTest, Decrypt_Simple) {
    // Arrange
    string a = "bcde";

    // Act
    string b = Decrypt(a, 1);

    // Assert
    EXPECT_EQ(b, "abcd");
}
