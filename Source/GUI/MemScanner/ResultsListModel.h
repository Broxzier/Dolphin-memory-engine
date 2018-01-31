#pragma once

#include <QtCore/QAbstractTableModel>

#include "../../MemoryScanner/MemoryScanner.h"

class ResultsListModel : public QAbstractTableModel
{
  Q_OBJECT

public:
  enum
  {
    RESULT_COL_ADDRESS = 0,
    RESULT_COL_SCANNED,
    RESULT_COL_CURRENT,
    RESULT_COL_NUM
  };

  ResultsListModel(QObject* parent, MemScanner* scanner);
  ~ResultsListModel();

  int columnCount(const QModelIndex& parent = QModelIndex()) const override;
  int rowCount(const QModelIndex& parent = QModelIndex()) const override;
  QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
  QVariant headerData(int section, Qt::Orientation orientation,
                      int role = Qt::DisplayRole) const override;

  u32 getResultAddress(const int row) const;
  Common::MemOperationReturnCode updateScannerCurrentCache();
  void updateAfterScannerReset();

private:
  MemScanner* m_scanner;
};
