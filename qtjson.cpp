#include "qtjson.h"

#include <QDateTime>

namespace QtJson
{
static QString dateFormat, dateTimeFormat;

static QString sanitizeString(QString str);
static QByteArray join(const QList<QByteArray> &list, const QByteArray &sep);
static QVariant parseValue(const QString &json, int &index, bool &success);
static QVariant parseObject(const QString &json, int &index, bool &success);
static QVariant parseArray(const QString &json, int &index, bool &success);
static QVariant parseString(const QString &json, int &index, bool &success);
static QVariant parseNumber(const QString &json, int &index);
static int lastIndexOfNumber(const QString &json, int index);
static void eatWhitespace(const QString &json, int &index);
static int lookAhead(const QString &json, int index);
static int nextToken(const QString &json, int &index);

template<typename T>
QByteArray serializeMap(const T &map, bool &success)
{
    QByteArray str = "{ ";
    QList<QByteArray> pairs;
    for(typename T::const_iterator it = map.begin(), itend = map.end(); it != itend; ++it)
    {
        QByteArray serializedValue = serialize(it.value());
        if(serializedValue.isNull())
        {
            success = false;
            break;
        }
        pairs << sanitizeString(it.key()).toUtf8() + " : " + serializedValue;
    }

    str += join(pairs, ", ");
    str += " }";
    return str;
}

QVariant parse(const QString &json)
{
    bool success = true;
    return parse(json, success);
}

QVariant parse(const QString &json, bool &success)
{
    success = true;

    // Return an empty QVariant if the JSON data is either null or empty
    if(!json.isNull() || !json.isEmpty())
    {
        QString data = json;
        // We'll start from index 0
        int index = 0;

        // Parse the first value
        QVariant value = parseValue(data, index, success);

        // Return the parsed value
        return value;
    }
    else
    {
        // Return the empty QVariant
        return QVariant();
    }
}

QByteArray serialize(const QVariant &data)
{
    bool success = true;
    return serialize(data, success);
}

QByteArray serialize(const QVariant &data, bool &success)
{
    QByteArray str;
    success = true;

    if(!data.isValid()) // invalid or null?
        str = "null";
    else if((data.type() == QVariant::List) || (data.type() == QVariant::StringList)) // variant is a list?
    {
        QList<QByteArray> values;
        const QVariantList list = data.toList();
        Q_FOREACH(const QVariant& v, list)
        {
            QByteArray serializedValue = serialize(v);
            if (serializedValue.isNull())
            {
                success = false;
                break;
            }
            values << serializedValue;
        }

        str = "[ " + join( values, ", " ) + " ]";
    }
    else if (data.type() == QVariant::Hash) // variant is a hash?
        str = serializeMap<>(data.toHash(), success);
    else if (data.type() == QVariant::Map) // variant is a map?
        str = serializeMap<>(data.toMap(), success);
    else if ((data.type() == QVariant::String) || (data.type() == QVariant::ByteArray)) // a string or a byte array?
        str = sanitizeString(data.toString()).toUtf8();
    else if (data.type() == QVariant::Double) // double?
    {
        double value = data.toDouble(&success);
        if(success)
        {
            str = QByteArray::number(value, 'g');
            if(!str.contains(".") && ! str.contains("e"))
                str += ".0";
        }
        else if (data.type() == QVariant::Bool) // boolean value?
            str = data.toBool() ? "true" : "false";
        else if (data.type() == QVariant::ULongLong) // large unsigned number?
            str = QByteArray::number(data.value<qulonglong>());
        else if (data.canConvert<qlonglong>()) // any signed number?
            str = QByteArray::number(data.value<qlonglong>());
        else if (data.canConvert<long>()) //TODO: this code is never executed because all smaller types can be converted to qlonglong
            str = QString::number(data.value<long>()).toUtf8();
        else if (data.type() == QVariant::DateTime) // datetime value?
            str = sanitizeString(dateTimeFormat.isEmpty() ? data.toDateTime().toString() : data.toDateTime().toString(dateTimeFormat)).toUtf8();
        else if (data.type() == QVariant::Date) // date value?
            str = sanitizeString(dateTimeFormat.isEmpty() ? data.toDate().toString() : data.toDate().toString(dateFormat)).toUtf8();
        else if (data.canConvert<QString>()) { // can value be converted to string?
            // this will catch QUrl, ... (all other types which can be converted to string)
            str = sanitizeString(data.toString()).toUtf8();
        } else
            success = false;
    }

    if(success)
        return str;

    return QByteArray();
}

// cppcheck-suppress unusedFunction
QString serializeStr(const QVariant &data)
{
    return QString::fromUtf8(serialize(data));
}

QString serializeStr(const QVariant &data, bool &success)
{
    return QString::fromUtf8(serialize(data, success));
}

enum JsonToken
{
    JsonTokenNone = 0,
    JsonTokenCurlyOpen = 1,
    JsonTokenCurlyClose = 2,
    JsonTokenSquaredOpen = 3,
    JsonTokenSquaredClose = 4,
    JsonTokenColon = 5,
    JsonTokenComma = 6,
    JsonTokenString = 7,
    JsonTokenNumber = 8,
    JsonTokenTrue = 9,
    JsonTokenFalse = 10,
    JsonTokenNull = 11
};

static QString sanitizeString(QString str)
{
    str.replace(QLatin1String("\\"), QLatin1String("\\\\"));
    str.replace(QLatin1String("\""), QLatin1String("\\\""));
    str.replace(QLatin1String("\b"), QLatin1String("\\b"));
    str.replace(QLatin1String("\f"), QLatin1String("\\f"));
    str.replace(QLatin1String("\n"), QLatin1String("\\n"));
    str.replace(QLatin1String("\r"), QLatin1String("\\r"));
    str.replace(QLatin1String("\t"), QLatin1String("\\t"));
    return QString(QLatin1String("\"%1\"")).arg(str);
}

static QByteArray join(const QList<QByteArray> &list, const QByteArray &sep)
{
    QByteArray res;
    Q_FOREACH(const QByteArray &i, list)
    {
        if(!res.isEmpty())
            res += sep;

        res += i;
    }
    return res;
}

static QVariant parseValue(const QString &json, int &index, bool &success)
{
    // Determine what kind of data we should parse by
    // checking out the upcoming token
    switch(lookAhead(json, index))
    {
    case JsonTokenString:
        return parseString(json, index, success);
    case JsonTokenNumber:
        return parseNumber(json, index);
    case JsonTokenCurlyOpen:
        return parseObject(json, index, success);
    case JsonTokenSquaredOpen:
        return parseArray(json, index, success);
    case JsonTokenTrue:
        nextToken(json, index);
        return QVariant(true);
    case JsonTokenFalse:
        nextToken(json, index);
        return QVariant(false);
    case JsonTokenNull:
        nextToken(json, index);
        return QVariant();
    case JsonTokenNone:
        break;
    }

    // If there were no tokens, flag the failure and return an empty QVariant
    success = false;
    return QVariant();
}

static QVariant parseObject(const QString &json, int &index, bool &success)
{
    QVariantMap map;

    // Get rid of the whitespace and increment index
    nextToken(json, index);

    // Loop through all of the key/value pairs of the object
    while(true)
    {
        // Get the upcoming token
        int token = lookAhead(json, index);

        if(token == JsonTokenNone)
        {
            success = false;
            return QVariantMap();
        }
        else if (token == JsonTokenComma)
            nextToken(json, index);
        else if (token == JsonTokenCurlyClose)
        {
            nextToken(json, index);
            return map;
        }
        else
        {
            // Parse the key/value pair's name
            QString name = parseString(json, index, success).toString();

            if(!success)
                return QVariantMap();

            // Get the next token
            token = nextToken(json, index);

            // If the next token is not a colon, flag the failure
            // return an empty QVariant
            if(token != JsonTokenColon)
            {
                success = false;
                return QVariant(QVariantMap());
            }

            // Parse the key/value pair's value
            QVariant value = parseValue(json, index, success);

            if(!success)
                return QVariantMap();

            // Assign the value to the key in the map
            map[name] = value;
        }
    }

    // Return the map successfully
    return QVariant(map);
}

static QVariant parseArray(const QString &json, int &index, bool &success)
{
    QVariantList list;

    nextToken(json, index);

    while(true)
    {
        int token = lookAhead(json, index);

        if(token == JsonTokenNone)
        {
            success = false;
            return QVariantList();
        }
        else if (token == JsonTokenComma)
            nextToken(json, index);
        else if (token == JsonTokenSquaredClose)
        {
            nextToken(json, index);
            break;
        }
        else
        {
            QVariant value = parseValue(json, index, success);
            if(!success)
                return QVariantList();
            list.push_back(value);
        }
    }

    return QVariant(list);
}

static QVariant parseString(const QString &json, int &index, bool &success)
{
    QString s;
    QChar c;

    eatWhitespace(json, index);

    c = json[index++];

    bool complete = false;
    while(!complete)
    {
        if(index == json.size())
            break;

        c = json[index++];

        if(c == '\"')
        {
            complete = true;
            break;
        }
        else if (c == '\\')
        {
            if(index == json.size())
                break;

            c = json[index++];

            if(c == '\"')
                s.append('\"');
            else if (c == '\\')
                s.append('\\');
            else if (c == '/')
                s.append('/');
            else if (c == 'b')
                s.append('\b');
            else if (c == 'f')
                s.append('\f');
            else if (c == 'n')
                s.append('\n');
            else if (c == 'r')
                s.append('\r');
            else if (c == 't')
                s.append('\t');
            else if (c == 'u')
            {
                int remainingLength = json.size() - index;
                if(remainingLength >= 4)
                {
                    QString unicodeStr = json.mid(index, 4);

                    int symbol = unicodeStr.toInt(0, 16);

                    s.append(QChar(symbol));

                    index += 4;
                }
                else
                    break;
            }
        }
        else
            s.append(c);
    }

    if(!complete)
    {
        success = false;
        return QVariant();
    }

    return QVariant(s);
}

static QVariant parseNumber(const QString &json, int &index)
{
    eatWhitespace(json, index);

    int lastIndex = lastIndexOfNumber(json, index);
    int charLength = (lastIndex - index) + 1;
    QString numberStr;

    numberStr = json.mid(index, charLength);

    index = lastIndex + 1;
    bool ok;

    if(numberStr.contains('.'))
        return QVariant(numberStr.toDouble(NULL));
    else if (numberStr.startsWith('-'))
    {
        int i = numberStr.toInt(&ok);
        if(!ok)
        {
            qlonglong ll = numberStr.toLongLong(&ok);
            return ok ? ll : QVariant(numberStr);
        }
        return i;
    }
    else
    {
        uint u = numberStr.toUInt(&ok);
        if(!ok)
        {
            qulonglong ull = numberStr.toULongLong(&ok);
            return ok ? ull : QVariant(numberStr);
        }
        return u;
    }
}

static int lastIndexOfNumber(const QString &json, int index)
{
    int lastIndex;

    for(lastIndex = index; lastIndex < json.size(); lastIndex++)
    {
        if(QString("0123456789+-.eE").indexOf(json[lastIndex]) == -1)
            break;
    }

    return lastIndex -1;
}

static void eatWhitespace(const QString &json, int &index)
{
    for(; index < json.size(); index++)
    {
        if(QString(" \t\n\r").indexOf(json[index]) == -1)
            break;
    }
}

static int lookAhead(const QString &json, int index)
{
    int saveIndex = index;
    return nextToken(json, saveIndex);
}

static int nextToken(const QString &json, int &index)
{
    eatWhitespace(json, index);

    if(index == json.size())
        return JsonTokenNone;

    QChar c = json[index];
    index++;
    switch(c.toLatin1())
    {
    case '{': return JsonTokenCurlyOpen;
    case '}': return JsonTokenCurlyClose;
    case '[': return JsonTokenSquaredOpen;
    case ']': return JsonTokenSquaredClose;
    case ',': return JsonTokenComma;
    case '"': return JsonTokenString;
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    case '-': return JsonTokenNumber;
    case ':': return JsonTokenColon;
    }
    index--; // ^ WTF?

    int remainingLength = json.size() - index;

    // True
    if(remainingLength >= 4)
    {
        if(json[index] == 't' && json[index + 1] == 'r' && json[index + 2] == 'u' && json[index + 3] == 'e')
        {
            index += 4;
            return JsonTokenTrue;
        }
    }

    // False
    if (remainingLength >= 5) {
        if (json[index] == 'f' && json[index + 1] == 'a' &&
                json[index + 2] == 'l' && json[index + 3] == 's' &&
                json[index + 4] == 'e') {
            index += 5;
            return JsonTokenFalse;
        }
    }

    // Null
    if(remainingLength >= 4)
    {
        if(json[index] == 'n' && json[index + 1] == 'u' && json[index + 2] == 'l' && json[index + 3] == 'l')
        {
            index += 4;
            return JsonTokenNull;
        }
    }

    return JsonTokenNone;
}

// cppcheck-suppress unusedFunction
void setDateTimeFormat(const QString &format)
{
    dateTimeFormat = format;
}

// cppcheck-suppress unusedFunction
void setDateFormat(const QString &format)
{
    dateFormat = format;
}

// cppcheck-suppress unusedFunction
QString getDateTimeFormat()
{
    return dateTimeFormat;
}

// cppcheck-suppress unusedFunction
QString getDateFormat()
{
    return dateFormat;
}

} //end namespace
