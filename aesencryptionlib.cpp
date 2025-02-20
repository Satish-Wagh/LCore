#include "aesencryptionlib.h"
#include<openssl/aes.h>
#include<openssl/rsa.h>
#include<openssl/pem.h>
#include<openssl/err.h>
#include<QDebug>


AESEncryptionLib::AESEncryptionLib()
{
}


bool AESEncryptionLib::is_base64(AESEncryptionLib::byte c)
{
    return (isalnum(c) || (c == '+') || (c == '/'));
}

void AESEncryptionLib::gen_Key(AESEncryptionLib::byte key[])
{     
    int nCheckCount = 0;

RANDLable:
    memset(key, 0, sizeof(key));

    if(nCheckCount <= 50)
    {
        AES_KEY aes_key;
        if (AES_set_encrypt_key(key, strlen(reinterpret_cast<const char*>(key)) * 8, &aes_key) < 0)
        {
            nCheckCount++;
            goto RANDLable;
        }

    }

//    if (rc != 1)
//    {
//        // cout << "RAND_bytes key failed";
//    }

}

void AESEncryptionLib::get_IV(AESEncryptionLib::byte iv[])
{
    int  rc = RAND_bytes(iv, BLOCKSIZE);
    if (rc != 1)
    {
        cout << "RAND_bytes for iv failed";
    }
}

string AESEncryptionLib::aes_256_cbc_encode(const string& password, const string& data)
{
    //here iv default character set to all 0
    unsigned char iv[AES_BLOCK_SIZE] = { '0','0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };

    AES_KEY aes_key;
    if (AES_set_encrypt_key(reinterpret_cast<const unsigned char*>(password.c_str()), password.length() * 8, &aes_key) < 0)
    {
        return "Key Not Set";
    }

    string strRet;
    string data_bak = data;
    unsigned int data_length = data_bak.length();

    int padding = 0;
    if (data_bak.length() % (AES_BLOCK_SIZE) > 0)
    {
        padding = AES_BLOCK_SIZE - data_bak.length() % (AES_BLOCK_SIZE);
    }
    else
    {
        padding = AES_BLOCK_SIZE;
    }

    data_length += padding;

    while (padding > 0)
    {
        data_bak += '\0';
        padding--;
    }

    for (unsigned int i = 0; i < data_length / (AES_BLOCK_SIZE); i++)
    {
        string str16 = data_bak.substr(i*AES_BLOCK_SIZE, AES_BLOCK_SIZE);
        unsigned char out[AES_BLOCK_SIZE];
        ::memset(out, 0, AES_BLOCK_SIZE);
        AES_cbc_encrypt(reinterpret_cast<const unsigned char*>(str16.c_str()), out, AES_BLOCK_SIZE, &aes_key, iv, AES_ENCRYPT);
        strRet += string(reinterpret_cast<const char*>(out), AES_BLOCK_SIZE);
    }
    return strRet;
}
string AESEncryptionLib::aes_256_cbc_decode(const string &password, const string &strData)
{
    //here iv default character set to all 0
    unsigned char iv[AES_BLOCK_SIZE] = { '0','0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };

    AES_KEY aes_key;
    if (AES_set_decrypt_key(reinterpret_cast<const unsigned char*>(password.c_str()), password.length() * 8, &aes_key) < 0)
    {
        return "Decrypt Failed";
    }

    string strRet;
    for (unsigned int i = 0; i < strData.length() / AES_BLOCK_SIZE; i++)
    {
        string str16 = strData.substr(i*AES_BLOCK_SIZE, AES_BLOCK_SIZE);
        unsigned char out[AES_BLOCK_SIZE];
        ::memset(out, 0, AES_BLOCK_SIZE);
        AES_cbc_encrypt(reinterpret_cast<const unsigned char*>(str16.c_str()), out, AES_BLOCK_SIZE, &aes_key, iv, AES_DECRYPT);
        strRet += string(reinterpret_cast<const char*>(out), AES_BLOCK_SIZE);
    }
    return strRet;
}

string AESEncryptionLib::base64_encode(const char *bytes_to_encode, int in_len)
{
    string ret;
    int i = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];

    while (in_len--) {
        char_array_3[i++] = *(bytes_to_encode++);
        if (i == 3) {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            for (i = 0; (i < 4); i++)
                ret += base64_chars[char_array_4[i]];
            i = 0;
        }
    }

    if (i)
    {
        int j;
        for (j = i; j < 3; j++)
            char_array_3[j] = '\0';

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        char_array_4[3] = char_array_3[2] & 0x3f;

        for (j = 0; (j < i + 1); j++)
            ret += base64_chars[char_array_4[j]];

        while ((i++ < 3))
            ret += '=';

    }
    return ret;

}

string AESEncryptionLib::base64_decode(const string &encoded_string)
{
    int in_len = encoded_string.size();
    int i = 0;
    int in_ = 0;
    unsigned char char_array_4[4], char_array_3[3];
    string ret;

    while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
        char_array_4[i++] = encoded_string[in_]; in_++;
        if (i == 4) {
            for (i = 0; i < 4; i++)
                char_array_4[i] = base64_chars.find(char_array_4[i]);

            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

            for (i = 0; (i < 3); i++)
                ret += char_array_3[i];
            i = 0;
        }
    }

    if (i) {
        int j;
        for (j = i; j < 4; j++)
            char_array_4[j] = 0;

        for (j = 0; j < 4; j++)
            char_array_4[j] = base64_chars.find(char_array_4[j]);

        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

        for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
    }

    return ret;
}

string AESEncryptionLib::GenerateKeyUsingRAND_bytes()
{
    bool bStatus = false;
    string strSecretKEY;

    QString fileENC = "/sda1/data/.sysinfo";

    QFile mfile(fileENC);

    if(mfile.open(QIODevice::ReadOnly | QIODevice::Text ))
    {
        QTextStream in(&mfile);
        QString strLine;
        while(!in.atEnd())
            strLine = in.readAll();
        if(!strLine.trimmed().isEmpty())
            bStatus = true;
    }
    mfile.close();

    QString strKey, strSubKey;


    if(bStatus)
    {
        QFile mfilen(fileENC);
        if(mfilen.open(QIODevice::ReadOnly | QIODevice::Text ))
        {
            QTextStream in(&mfilen);

            QString strLine;
            while(!in.atEnd())
            {
                strLine = in.readLine();
                strKey = strLine;
                strLine = in.readLine();
                strSubKey = strLine;
            }
        }
        mfilen.close();

        if(strKey.isEmpty() == false)
        {
            string strKey1 = strKey.toStdString();
            string strDecodeSubKey1 = strSubKey.toStdString();

            string strDecodeKey = base64_decode(strKey1);
            string strDecodeSubKey = base64_decode(strDecodeSubKey1);

            string strMainKey = aes_256_cbc_decode(strDecodeSubKey, strDecodeKey);
            strMainKey.erase(find(strMainKey.begin(), strMainKey.end(), '\0'), strMainKey.end());  //to remove \0 characters

            strSecretKEY = strMainKey;
        }
    }
    else
    {

        byte key1[33], Secrete_key[33];

        ::memset(key1, 0, sizeof(key1));
        ::memset(Secrete_key, 0, sizeof(Secrete_key));

        //generate main key
        gen_Key(key1);

        string sKey(reinterpret_cast<char*>(key1));

        //generate sub key
        gen_Key(Secrete_key);

        string strMainKey(reinterpret_cast<char*>(Secrete_key));

        // here we encode maincode using sub key
        string str_encode = aes_256_cbc_encode(strMainKey, sKey);

        string str_encode_MainKey = base64_encode(str_encode.c_str(), str_encode.length());

        string str_encode_SubKey = base64_encode(strMainKey.c_str(), strMainKey.length());

        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(SYSCONF_DB);
        if(!db.open())
        {
            db.isOpen();
        }

        sync();
        LCore liblcore;
        QString ColumnType = "Property VARCHAR(50) PRIMARY KEY, Value VARCHAR(75)";
        liblcore.writeTable("SysConf", ColumnType, "'MKInfo', '"+QString::fromStdString(str_encode_MainKey)+"'", "AppendNew");
        liblcore.writeTable("SysConf", ColumnType, "'SKInfo', '"+QString::fromStdString(str_encode_SubKey)+"'", "AppendNew");

        int status = access(FIRSTPARTITIONMOUNTPOINT, W_OK);

        if(status != 0)
            mount(FIRSTPARTITIONMOUNTPOINT, FIRSTPARTITIONMOUNTPOINT, "ext3", MS_REMOUNT | MS_NODEV, "");

        QFile fileEncryption(fileENC);
        if (fileEncryption.open(QIODevice::WriteOnly | QIODevice::Text ))
        {
            QTextStream out(&fileEncryption);
            out <<  QString::fromStdString(str_encode_MainKey)<< "\n";
            out <<  QString::fromStdString(str_encode_SubKey) << "\n";
            fileEncryption.close();
            fileEncryption.setPermissions(QFile::ReadOwner | QFile::WriteOwner | QFile::ExeOwner | QFile::ReadUser | QFile::WriteUser | QFile::ExeUser | QFile::ReadGroup | QFile::WriteGroup | QFile::ExeGroup | QFile::ReadOther | QFile::WriteOther | QFile::ExeOther);
        }

        if(status != 0)
            mount(FIRSTPARTITIONMOUNTPOINT, FIRSTPARTITIONMOUNTPOINT, "ext3", MS_REMOUNT | MS_RDONLY | MS_NODEV, "");

        strSecretKEY = sKey;
    }

    return strSecretKEY;
}

//QString AESEncryptionLib::writeTable(QString tableName, QString columnType, QString values, QString condition)
//{
//    qDebug() << "LCore:writeTable::3:: Start.";
//    qDebug() << "LCore:writeTable::3:: args : tableName = " << tableName << " cloumnType = " << columnType
//             << " values = " << values << "Condition = " << condition;
//    QSqlQuery query;
//    QString qry = "";

//    qry = "CREATE TABLE IF NOT EXISTS " + tableName + "(" + columnType + ")";
//    qDebug() << "LCore:writeTable::3:: qry = " << qry;
//    if(query.exec(qry))
//        qDebug() << "LCore:writeTable::3:: Table created " + tableName;
//    else
//    {
//        qDebug() << "LCore:writeTable::3:: Table Not created because " << query.lastError();
//        qDebug() << "LCore:writeTable::3:: Table Not created " << tableName;
//        return ("Table Not Created " + tableName);
//    }

//    QStringList columnList = columnType.split(",");
//    QString columns = "";

//    for (int i = 0; i < columnList.size(); ++i)
//    {
//        QString colName = columnList.at(i).trimmed();
//        QString propName = colName.section(" ",0,0);
//        if(propName.contains("PRIMARY"))
//        {
//            columns = columns.left(columns.length()-2);
//            break;
//        }
//        else
//        {
//            columns.append(propName);
//            if(i < columnList.size()-1)
//                columns.append(", ");
//        }
//    }
//    qDebug() << "LCore:writeTable::3::  columns = " << columns;

//    if(condition != "AppendNew")
//    {
//        {
//            qry = "DELETE FROM " + tableName;
//            if(condition.contains("="))
//                qry.append(" WHERE ").append(condition);

//            qDebug() << "LCore:writeTable::3:: qry = " << qry;

//            if(query.exec(qry))
//                qDebug() << "LCore:writeTable::3:: Table dropped = " + tableName;
//            else
//            {
//                qDebug() << "LCore:writeTable::3:: Table Not dropped because" << query.lastError();
//                return ("Table Not dropped " + tableName);
//            }
//        }
//    }

//    qry = "REPLACE into " + tableName + "(" + columns + ") values(" + values + ")";
//    qDebug() << qry;

//    if(query.exec(qry))
//        qDebug() << "LCore:writeTable::3::  Values Inserted " + tableName;
//    else
//    {
//        //  qDebug() << "LCore:writeTable::3:: Values not Inserted because " <<  query.lastError();
//        return ("Data Not Inserted " + tableName);
//    }

//    query.lastError();
//    // qDebug() << "LCore:writeTable::3:: return  Successful.";
//    return "Successfull";
//}

string AESEncryptionLib::EncryptDecryptStringAES(const string& strSourceString, int nType)
{

    string strKey = GenerateKeyUsingRAND_bytes();

    if(nType == 0)
    {
        string str_encode = aes_256_cbc_encode(strKey, strSourceString);

        if(str_encode == "Key Not Set")
        {
            system(QString("echo \"Key Not Set   \"  >> /tmp/.sysinfocheck").toLatin1());
            return "";
        }

        string str_encode_base64 = base64_encode(str_encode.c_str(), str_encode.length());

        return str_encode_base64;
    }
    else
    {
        string str_decode_base64 = base64_decode(strSourceString);

        string str_decode = aes_256_cbc_decode(strKey, str_decode_base64);


        if(str_decode == "Decrypt Failed")
        {
            system(QString("echo \"Key Not Set   \"  >> /tmp/.sysinfocheck").toLatin1());
            return "";
        }

        str_decode.erase(find(str_decode.begin(), str_decode.end(), '\0'), str_decode.end());  //to remove \0 character

        return str_decode;
    }
}

//This function is called from Citrix source code.

extern "C" string callEncryptDecryptStringAES(string strSourceString, int nType)
{
    AESEncryptionLib objAESEncryptionLib;
    string strData =  objAESEncryptionLib.EncryptDecryptStringAES(strSourceString,  nType);
    return strData;
}
