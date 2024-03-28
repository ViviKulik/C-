#include "../Domain/Movie.h"
#include "../Repository/AbstractRepository.h"

class UndoAction {
public:
    UndoAction() = default;

    virtual ~UndoAction() = default;

    virtual void doUndo() = 0;
};


class AddUndo : public UndoAction {
private:
    Movie movieAdded;
    AbstractRepository &repo;

public:
    AddUndo(AbstractRepository& repo, const Movie& movAdded) : UndoAction(),
                                                               repo { repo }, movieAdded { movAdded } {}

    ~AddUndo() override =default;

    void doUndo() override;
};


class DeleteUndo : public UndoAction {
private:
    Movie movieDeleted;
    AbstractRepository &repo;

public:
    DeleteUndo(AbstractRepository& repo, const Movie& movDeleted) : UndoAction(),
                                                                    repo { repo }, movieDeleted { movDeleted } {}

    ~DeleteUndo() override =default;

    void doUndo() override;
};

class ModifyUndo : public UndoAction {
private:
    Movie movieToModify;
    AbstractRepository&repo;

public:
    ModifyUndo (AbstractRepository& repo, const Movie& movToModify) : UndoAction(),
                                                                      repo { repo }, movieToModify { movToModify }{}

    ~ ModifyUndo () override =default;

    void doUndo() override;
};
