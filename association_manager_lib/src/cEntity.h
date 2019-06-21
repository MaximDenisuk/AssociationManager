//
// Created by mdenysiuk on 05.04.19.
//

#ifndef ASSOCIATIONMANAGER_CENTITY_H
#define ASSOCIATIONMANAGER_CENTITY_H

#include <string>
#include <vector>

class cEntity {
private:
    std::string shortName_,
                longName_;
    std::vector<std::pair<std::string, std::string> > associationList;

public:
    void setLongName_(const std::string &longName_);
    void setShortName_(const std::string &shortName_);
    const std::vector<std::pair<std::string, std::string> > &getAssociationList() const;
    const std::string &getLongName_() const;
    const std::string &getShortName_() const;
    void addAssociation(const std::string& _associatedWith, const std::string& _associationName);

    cEntity(const std::string &_shortName, const std::string &_longName);
};

inline const std::string &
cEntity::getShortName_() const {
    return shortName_;
}

inline void
cEntity::setShortName_(const std::string &shortName_) {
    cEntity::shortName_ = shortName_;
}

inline const std::string &
cEntity::getLongName_() const {
    return longName_;
}

inline void
cEntity::setLongName_(const std::string &longName_) {
    cEntity::longName_ = longName_;
}

inline const std::vector<std::pair<std::string, std::string> > &
cEntity::getAssociationList() const {
    return associationList;
}

inline void
cEntity::addAssociation(const std::string&  _associationName, const std::string&_associatedWith) {
    if (!_associatedWith.empty() && !_associationName.empty()) {
        associationList.push_back(std::pair<std::string, std::string>( _associationName, _associatedWith));
    }
}

#endif //ASSOCIATIONMANAGER_CENTITY_H
