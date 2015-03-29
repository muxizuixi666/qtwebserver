//
// Copyright 2010-2015 Jacob Dawid <jacob@omg-it.works>
//
// This file is part of QtWebServer.
//
// QtWebServer is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// QtWebServer is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with QtWebServer.  If not, see <http://www.gnu.org/licenses/>.
//

#pragma once

// Qt includes
#include <QDomDocument>
#include <QList>

namespace QtWebServer {

namespace Html {

class Document :
    public QDomDocument {
public:
    Document(QString documentTypeDeclaration = "<!DOCTYPE html>");
    ~Document();

    void setTitle(QString title);
    QString title();

    QDomElement html();
    QDomElement head();
    QDomElement body();

    bool appendPartial(QDomElement domElement, QString resourceName);


    QList<QDomElement> elementsByClass(QString className) const;
    QList<QDomElement> elementsByClass(QDomElement domElement, QString className) const;

    QDomElement elementById(QString idName) const;
    QList<QDomElement> elementsById(QString idName) const;
    QList<QDomElement> elementsById(QDomElement domElement, QString idName) const;

    QList<QDomElement> elementsByAttribute(QString attributeName,
                                           QString attributeValue,
                                           bool allowMultipleValues = true) const;
    QList<QDomElement> elementsByAttribute(QDomElement domElement,
                                           QString attributeName,
                                           QString attributeValue,
                                           bool allowMultipleValues = true) const;

private:
    QDomElement _html, _head, _body;
    QDomText _title;
};

} // namespace Html

} // namespace QtWebServer