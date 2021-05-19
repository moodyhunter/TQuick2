/****************************************************************************
**
** Library: TQuick
**
** MIT License
**
** Copyright (c) 2019 toou http://www.toou.net
** Copyright (c) 2020 chengxuewen <1398831004@qq.com>
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
*all
** copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
** SOFTWARE.
**
****************************************************************************/

#ifndef TTOASTITEM_H
#define TTOASTITEM_H

#include <QObject>
#include <QQuickItem>

class TToastItemPrivate;
class TToastItem : public QQuickItem
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(TToastItem)
    Q_DISABLE_COPY(TToastItem)

    Q_PROPERTY(QString message READ getMessage WRITE setMessage NOTIFY messageChanged)
    Q_PROPERTY(int type READ getType WRITE setType NOTIFY typeChanged)

  public:
    enum Type
    {
        Message,
        Error,
        Warning,
        Custom,
    };
    Q_ENUM(Type)

    TToastItem(QQuickItem *parent = nullptr);
    ~TToastItem();

    QString getMessage() const;
    int getType() const;

  signals:
    void messageChanged(QString getMessage);
    void typeChanged(int getType);

  public slots:
    void setMessage(const QString &strMessage);
    void setType(const int &iType);

  private:
    TToastItemPrivate *d_ptr;
};

#endif // TG_TOASTITEM_H
