#ifndef AESENCRYPTIONLIB_H
#define AESENCRYPTIONLIB_H
#include <cmath>
#include <iostream>
#include <string>
#include <memory>
#include <limits>
#include <stdexcept>
#include <cstring>
#include<QString>
#include<QFile>
#include<QTextStream>
#include <vector>
#include <string>
#include<fstream>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <unistd.h>
#include <sys/mount.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include<QStringList>
#include<QtSql/QSqlError>
#include "lcore.h"

#define SYSCONF_DB              "/data/sysconf.db"
#define FIRSTPARTITIONMOUNTPOINT "/sda1"
using namespace std;

static const string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static const unsigned int KEY_SIZE = 32;
static const unsigned int BLOCKSIZE = 16;

class AESEncryptionLib
{
    typedef unsigned char byte;
public:
    AESEncryptionLib();
    string EncryptDecryptStringAES(const string& strSourceString, int nType);

private :
    static inline bool is_base64(byte c);

    void gen_Key(byte key[KEY_SIZE]);
    void get_IV(byte iv[BLOCKSIZE]);

    static string aes_256_cbc_encode(const string& password, const string& data);
    static string aes_256_cbc_decode(const string& password, const string& strData);
    static string base64_encode(char const* bytes_to_encode, int in_len);
    static string base64_decode(const string & encoded_string) ;
    string GenerateKeyUsingRAND_bytes();

   // QString writeTable(QString , QString, QString, QString);
};


#endif // AESENCRYPTIONLIB_H

//sudo apt-get install libboost-all-dev
