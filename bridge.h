#ifndef BRIDGE_H
#define BRIDGE_H

#include <QObject>

class Bridge : public QObject
{
    Q_OBJECT

    QStringList object;

public:
    explicit Bridge(QObject *parent = nullptr);

signals:
    void pushedPage();
    void popPage();

public slots:
    Q_INVOKABLE void emitPushedPage() { emit pushedPage(); };
    Q_INVOKABLE void emitPopPage() { emit popPage(); };

    Q_INVOKABLE void setObject(const QStringList &object) { this->object = object; };
    Q_INVOKABLE QStringList getObject() { return object; };
};

#endif // BRIDGE_H
