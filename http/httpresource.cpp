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

// Own includes
#include "httpresource.h"

// Qt includes
#include <QStringList>

namespace QtWebServer {

namespace Http {

Resource::Resource(QString uniqueIdentifier,
                   QObject *parent) :
    QObject(parent),
    Responder() {
    _uniqueIdentifier = uniqueIdentifier;
}

bool Resource::match(QString uniqueIdentifier) {
    QStringList splittedUri = this->uniqueIdentifier().split("/", QString::SkipEmptyParts);
    QStringList splittedRequestedUri = uniqueIdentifier.split("/", QString::SkipEmptyParts);

    int count = splittedRequestedUri.count();
    if(splittedUri.count() != count) {
        return false;
    }

    for(int depth = 0; depth < count; depth++) {
        if(splittedUri.at(depth).startsWith("{") && splittedUri.at(depth).endsWith("}")) {
            continue;
        }

        if(splittedUri.at(depth) != splittedRequestedUri.at(depth)) {
            return false;
        }
    }

    return true;
}

QString Resource::uniqueIdentifier() {
    return _uniqueIdentifier.r();
}

void Resource::setUniqueIdentifier(QString uniqueIdentifer) {
    _uniqueIdentifier = uniqueIdentifer;
}

} // namespace Http

} // namespace QtWebServer