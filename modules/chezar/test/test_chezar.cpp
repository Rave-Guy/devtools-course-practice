// Copyright 2020 Suchkov Makar

#include <gtest/gtest.h>

#include <string>

#include "include/chezar.h"


TEST(Suchkov_Makar_ChezarTest, Encrypt_Simple) {
    // Arrange
    char a[] = "abcd";

    // Act
    char *b = Encrypt(a, 1);

    // Assert
    ASSERT_STRCASENE(Encrypt(a, 1), "bcde");
}

TEST(Suchkov_Makar_ChezarTest, Decrypt_Simple) {
    // Arrange
    char a[] = "bcde";

    // Act
    

    // Assert
    ASSERT_STRCASENE(Decrypt(a, 1), "abcd");
}


TEST(Suchkov_Makar_ChezarTest, Decrypt_Encrypt_Simple) {
    // Arrange
    char a[] = "abcdefghijklmnopqrstuvwxyz";

    // Act
    
    // Assert
    ASSERT_STRCASENE(Encrypt(a, 5),  Decrypt(a, 5));
}