#ifndef DIRUTIL_H
#define DIRUTIL_H

#include "qtutils_global.h"
#include <QtCore/QObject>

namespace QtUtils
{
	class QTUTILS_EXPORT DirUtil : public QObject
	{
		Q_OBJECT

	public:
		explicit DirUtil(QObject* parent = nullptr);

		/// @brief 查找文件夹内所有的文件
		/// @param path 要查找的文件夹
		/// @param nameFilters 文件过滤
		/// @return 找到的文件列表
		QStringList findFiles(const QString& path,
							  const QStringList& nameFilters = QStringList());

		/// @brief 复制目录树下所有的文件到新文件夹
		/// @param fromPath 源文件夹
		/// @param toPath 目的文件夹
		/// @param nameFilters 文件过滤
		/// @param overWrite 是否覆盖
		/// @return 复制的文件数量
		int copyDirs(const QString& fromPath, const QString& toPath,
					 const QStringList& nameFilters = QStringList(),
					 bool overWrite = true);

		/// @brief 复制文件列表到新文件夹
		/// @param files 源文件列表
		/// @param toPath 目的文件夹
		/// @param overWrite 是否覆盖
		/// @return 复制的文件数量
		int copyFiles(const QStringList& files, const QString& toPath,
					  bool overWrite = true);

		/// @brief 重置m_copyFileCount为0
		void resetCopyFileCount();
		Q_SIGNALS:
		/// @brief 信号：当前复制的文件的计数和文件名
		/// @param count 第几个文件
		/// @param name 源文件名
		void currentFile(int count, const QString& name);
	private:
		int m_copyFileCount;

		void doDirTree(const QString& fromPath, const QString& toPath,
					   const QStringList& nameFilters, bool overWrite,
					   QStringList& findFiles, bool isFind);
		QString formatPath(const QString& path);
	};
}

#endif // DIRUTIL_H


