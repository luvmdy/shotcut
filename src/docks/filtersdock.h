/*
 * Copyright (c) 2013-2014 Meltytech, LLC
 * Author: Dan Dennedy <dan@dennedy.org>
 * Author: Brian Matherly <code@brianmatherly.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FILTERSDOCK_H
#define FILTERSDOCK_H

#include <QDockWidget>
#include <QObject>
#include <QQuickView>

class QmlFilter;
class QmlMetadata;
class MetadataModel;
class AttachedFiltersModel;

class FiltersDock : public QDockWidget
{
    Q_OBJECT
    
public:
    explicit FiltersDock(MetadataModel* metadataModel, AttachedFiltersModel* attachedModel, QWidget *parent = 0);

signals:
    void currentFilterRequested(int attachedIndex);

public slots:
    void clearCurrentFilter();
    void setCurrentFilter(QmlFilter* filter, QmlMetadata* meta, int index);
    void setFadeInDuration(int duration);
    void setFadeOutDuration(int duration);

protected:
    bool event(QEvent *event);

private slots:
    void resetQview();

private:
    QQuickView m_qview;
};

#endif // FILTERSDOCK_H
