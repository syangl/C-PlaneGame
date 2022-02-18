#ifndef GRADE_H
#define GRADE_H

#include <QWidget>

class Grade : public QWidget
{
    Q_OBJECT
public:
    explicit Grade(QWidget *parent = nullptr);

    int grade = 0;

signals:

};

#endif // GRADE_H
