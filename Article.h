//
// Created by mikesolar on 25-6-1.
//

#ifndef ARTICLE_H
#define ARTICLE_H
#include <QString>
#include <QList>
#include <list>


struct Article {
    QString title;
    QString from;
    QString content;
    QList<QString> pictures;
};
struct Page {
    std::list<Article> articles;
    Article head;
    QString date;
    QString editors;
};

extern Page page;


#endif //ARTICLE_H
