#ifndef PARKINGLIST_H
#define PARKINGLIST_H

#include <QAbstractListModel>
#include <QStringListModel>
#include <QDebug>

class parkingList : public QStringListModel
{
    Q_OBJECT

public:
    explicit parkingList(QObject *parent = nullptr);

    void setStringList(const QStringList &strings);

    QStringList	stringList() const;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    bool append(QString qsValue);

    bool remove(QString qsValue);

    bool isGoodValue(QString qsValue);


private:    
    QStringList _list;
};

#endif // PARKINGLIST_H
