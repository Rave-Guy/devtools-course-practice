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

TEST(Suchkov_Makar_ChezarTest, Can_Add_key_Data) {
    // Arrange
    Chezar estr;
    std::string a;
    int key;
    // Act
    key = 1;
    // Assert
    EXPECT_EQ(true, estr.SetKey(key));
}

TEST(Suchkov_Makar_ChezarTest, Can_Add_str_Data) {
    // Arrange
    Chezar estr;
    std::string a;
    int key;
    // Act
    a = "abcd";
    // Assert
    EXPECT_EQ(true, estr.SetStr(a));
}

TEST(Suchkov_Makar_ChezarTest, Can_Get_str_Data) {
    // Arrange
    Chezar estr;
    std::string a;
    int key;
    // Act
    estr.SetStr(a);
    // Assert
    EXPECT_EQ(true, estr.GetStr());
}

TEST(Suchkov_Makar_ChezarTest, Can_Get_key_Data) {
    // Arrange
    Chezar estr;
    std::string a;
    int key = 1488;
    // Act
    estr.SetKey(key);
    // Assert
    EXPECT_EQ(key, estr.GetKey());
}

TEST(Suchkov_Makar_ChezarTest, Can_Encrypt_Data) {
    // Arrange
    Chezar estr("abcdefghijklmnopqrstuvwxyz", 1488);
    // Act
    estr.Encrypt();
    // Assert
    EXPECT_EQ(true, estr.isEncrypt());
}

TEST(Suchkov_Makar_ChezarTest, Can_Decrypt_Data) {
    // Arrange
    Chezar estr("abcdefghijklmnopqrstuvwxyz", 1488);
    // Act
    estr.Decrypt();
    // Assert
    EXPECT_EQ(false, estr.isEncrypt());
}

TEST(Suchkov_Makar_ChezarTest, Can_Crypt_Data) {
    // Arrange
    Chezar estr("abcdefghijklmnopqrstuvwxyz", 1488);
    // Act
    estr.Encrypt();    
    // Assert
    ASSERT_STRCASEEQ("ghijklmnopqrstuvwxyzabcde", estr.GetStr());
}

TEST(Suchkov_Makar_ChezarTest, Can_Crypt_again_Data) {
    // Arrange
    Chezar estr("ghijklmnopqrstuvwxyzabcde", 1488);
    // Act
    estr.Decrypt();    
    // Assert
    ASSERT_STRCASEEQ("abcdefghijklmnopqrstuvwxy", estr.GetStr());
}