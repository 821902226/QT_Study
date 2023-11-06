#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

    void classOver();

signals:
    void hungery();
    void hungery(QString food); //信号重载

public slots:
};

#endif // TEACHER_H
