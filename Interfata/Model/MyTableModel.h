#pragma once

#include <Qt>
#include <QAbstractTableModel>
#include <QItemSelectionModel>
#include <QBrush>
#include <vector>
#include <QFont>

#include "../../Domain/Movie.h"

using std::vector;


class MyTableModel :public QAbstractTableModel {

private:
    vector<Movie> movies;

public:
    MyTableModel() {
        vector<Movie> mov;
        movies = mov;
    }

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return movies.size();
    }
    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 4;
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if (role == Qt::ForegroundRole) {
            auto mov = this->movies[index.row()];
            if (mov.getAnAparitie() %2 == 1) {
                return QBrush(Qt::darkBlue);
            }
        }

        if (role == Qt::FontRole) {
            QFont f;
            f.setBold(index.row() % 4 == 0);
            std::cout << index.row();
            return f;
        }

        if (role == Qt::DisplayRole) {
            auto mov = movies[index.row()];
            if (index.column() == 0) {
                return QString::fromStdString(mov.getTitlu());
            }
            else if (index.column() == 1) {
                return QString::fromStdString(mov.getGen());
            }
            else if (index.column() == 2) {
                return QString::number(mov.getAnAparitie());
            }
            else if (index.column() == 3) {
                return QString::fromStdString(mov.getActorPrincipal());
            }
        }

        return QVariant{};
    }

    void setMovies(const vector<Movie> movies) {
        this->movies = movies;
        auto topLeft = createIndex(0, 0);
        auto bottomR = createIndex(rowCount(), columnCount());
        emit dataChanged(topLeft, bottomR);
    }

    Qt::ItemFlags flags(const QModelIndex& /*index*/) const {
        return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
    }

    }

    QVariant headerData(int section, Qt::Orientation orientation, int role) const
    {
        if (role == Qt::DisplayRole)
        {
            if (orientation == Qt::Horizontal) {
                switch (section)
                {
                    case 0:
                        return tr("Title");
                    case 1:
                        return tr("Genre");
                    case 2:
                        return tr("Year");
                    case 3:
                        return tr("Main Actor");
                    default:
                        return QString("");
                }
            }
        }
        return QVariant();
    }

    QList<Movie> selectedItems() const {
        QList<Movie> selectedMoviesList;
        for (int row = 0; row < rowCount(); ++row) {
            QModelIndex index = this->index(row, 0);
            if (index.isValid() && index.data(Qt::CheckStateRole) == Qt::Checked) {
                Movie movie = movies.at(row);
                selectedMoviesList.push_back(movie);
            }
        }
    }
};
