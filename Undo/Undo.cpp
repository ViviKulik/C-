#include "Undo.h"

void AddUndo::doUndo() {
    repo.delete_repo(movieAdded);
}

void DeleteUndo::doUndo() {
    repo.add_repo(movieDeleted);
}

void ModifyUndo::doUndo() {
    repo.modify_repo(movieToModify);
}